PROGRAM = program

SRC_DIR = src
BUILD_DIR = build

CC = riscv64-elf-gcc
OBJCOPY = riscv64-elf-objcopy
CFLAGS = -march=rv32imac_zicsr -mabi=ilp32
LDFLAGS = -Wl,--gc-sections -Wl,-Map,$(BUILD_DIR)/$(PROGRAM).map \
		  -nostartfiles -nostdlib
OBJCOPYFLAGS = -O ihex

C_SOURCE_FILES = $(wildcard $(SRC_DIR)/*.c)
ASM_SOURCE_FILES = $(wildcard $(SRC_DIR)/*.S)
HEADER_FILES = $(wildcard $(SRC_DIR)/*.h)
OBJECT_FILES = $(C_SOURCE_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o) \
	$(ASM_SOURCE_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%.o)


$(PROGRAM).elf: $(BUILD_DIR) $(BUILD_DIR)/$(PROGRAM).elf $(BUILD_DIR)/$(PROGRAM).hex $(HEADER_FILES)
	cp $(BUILD_DIR)/$(PROGRAM).elf $(PROGRAM).elf

$(BUILD_DIR):
	mkdir build

$(BUILD_DIR)/$(PROGRAM).hex : $(BUILD_DIR) $(BUILD_DIR)/$(PROGRAM).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $(BUILD_DIR)/$(PROGRAM).elf $(BUILD_DIR)/$(PROGRAM).hex

$(BUILD_DIR)/$(PROGRAM).elf: $(BUILD_DIR) $(OBJECT_FILES) $(PROGRAM).ld
	$(CC) $(CFLAGS) $(LDFLAGS) -T $(PROGRAM).ld $(OBJECT_FILES) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.S $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: flash
flash: $(BUILD_DIR)/$(PROGRAM).elf
	echo -e "r\nloadfile $<\nexit" | JLinkExe -device FE310 -if JTAG -speed 4000 -jtagconf -1,-1 \


.PHONY: clean
clean:
	rm -rf $(PROGRAM).elf $(BUILD_DIR)
