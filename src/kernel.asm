BITS 32

GLOBAL _start
GLOBAL gdtFlush
EXTERN kmain

MULTIBOOT_PAGE_ALIGN		equ 1
MULTIBOOT_MEMORY_INFO		equ 2
MULTIBOOT_AOUT_KLUDGE		equ 10000h
MULTIBOOT_HEADER_MAGIC		equ 1BADB002h
MULTIBOOT_HEADER_FLAGS		equ MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO
MULTIBOOT_CHECKSUM		equ -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
MULTIBOOT_BOOTLOADER_MAGIC	equ 2BADB002h

KERNEL_STACK_SIZE		equ 8192

SECTION .bss
ALIGN 16
    resb KERNEL_STACK_SIZE
_stack:

SECTION .rodata
szNoMultiboot: db 'N', 4, 'o', 4, ' ', 4, 'M', 4, 'u', 4, 'l', 4, 't', 4, 'i', 4, 'b', 4, 'o', 4, 'o', 4, 't', 4, '!', 4, 0




SECTION .text

_start:
	mov	esp, _stack
	jmp	.entry
	
ALIGN 4
.multiboot_header:
	dd	MULTIBOOT_HEADER_MAGIC
	dd	MULTIBOOT_HEADER_FLAGS
	dd	MULTIBOOT_CHECKSUM

.entry:
	cmp	eax, MULTIBOOT_BOOTLOADER_MAGIC
	je	.multibootOK
	mov	edi, 0B8000h
	mov	esi, szNoMultiboot
	mov	ecx, 13
	rep	movsw
	jmp	.end

.multibootOK:
	call	kmain

.end:
	cli
	hlt
	jmp	$

; cf gdt.h
; void __fastcall gdtFlush(t_gdtdesc *pdesc)
gdtFlush:
    lgdt	[ecx] ; pdesc
    mov		ax, 10h
    mov		ds, ax
    mov		es, ax
    mov		fs, ax
    mov		gs, ax
    mov		ss, ax
    jmp		0x08:.flush
.flush:
    ret
