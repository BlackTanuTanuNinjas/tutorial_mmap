BUILD_DIR := build

build_all:
	@mkdir -p $(BUILD_DIR)
	gcc -Wall -O2 write_char.c    -o $(BUILD_DIR)/write_char
	gcc -Wall -O2 write_string.c  -o $(BUILD_DIR)/write_string

clean:
	rm -rf $(BUILD_DIR)

.PHONY: build_all clean
