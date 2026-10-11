# 用法：
#   make run Q=001       編譯並執行 cpp-basics/001-* 或 questions/001-*
#   make run DIR=<路徑>  直接指定題目資料夾（VS Code task 會用到）
#   make build Q=001     只編譯不執行
#   make redo Q=001      重做：備份目前答案到 tmp/redo/，main.cpp 還原成最初 commit 的 stub
#   make env             顯示編譯器資訊
#   make clean           清除編譯產物（tmp/build）

CXX      := clang++
STD      := c++20
CXXFLAGS := -std=$(STD) -Wall -Wextra -Wpedantic -Wshadow -Wno-unused-parameter \
            -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer -Iinclude
BUILD    := tmp/build

ifdef Q
DIR ?= $(firstword $(wildcard cpp-basics/$(Q)-* questions/$(Q)-*))
endif
BIN := $(BUILD)/$(notdir $(DIR))

.PHONY: run build redo env clean

run: build
	@echo "▶ 執行 $(notdir $(DIR))"
	@$(BIN) || true

build:
	@test -n "$(DIR)" || { echo "找不到題目：請用 make run Q=001 或 make run DIR=<路徑>"; exit 1; }
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) $(DIR)/main.cpp -o $(BIN)

redo:
	@test -n "$(Q)" || { echo "請用 make redo Q=001"; exit 1; }
	@test -n "$(DIR)" || { echo "找不到題目 $(Q)"; exit 1; }
	@first=$$(git log --diff-filter=A --format=%H -- $(DIR)/main.cpp | tail -1); \
	test -n "$$first" || { echo "$(DIR)/main.cpp 還沒有 commit 過，無法還原 stub"; exit 1; }; \
	mkdir -p tmp/redo; \
	backup=tmp/redo/$(notdir $(DIR))-$$(date +%Y%m%d-%H%M%S).cpp; \
	cp $(DIR)/main.cpp $$backup; \
	git show $$first:$(DIR)/main.cpp > $(DIR)/main.cpp; \
	echo "已還原 $(DIR)/main.cpp 為初始 stub，舊答案備份在 $$backup"

env:
	@mkdir -p $(BUILD)
	@$(CXX) --version | head -1
	@printf '#include <iostream>\nint main(){std::cout << "__cplusplus = " << __cplusplus << "\\n";}' \
		| $(CXX) -std=$(STD) -x c++ - -o $(BUILD)/.env-check && $(BUILD)/.env-check

clean:
	rm -rf $(BUILD)
