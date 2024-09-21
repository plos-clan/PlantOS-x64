#include "../bootloader/limine/limine.h"
__attribute__( ( used, section( ".requests" ) ) ) volatile LIMINE_BASE_REVISION( 2 );

__attribute__( ( used, section( ".requests" ) ) ) volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0,
    .response = 0
}; 
void hcf() {
    for (;;) {
#if defined (__x86_64__)
        asm ("hlt");
#elif defined (__aarch64__) || defined (__riscv)
        asm ("wfi");
#elif defined (__loongarch64)
        asm ("idle 0");
#endif
    }
}
void kmain(void)
{
     struct limine_framebuffer *framebuffer = framebuffer_request.response->framebuffers[0];

    // Note: we assume the framebuffer model is RGB with 32-bit pixels.
    for ( long i = 0; i < 100; i++) {
        volatile  uint32_t *fb_ptr = ((uint32_t *)framebuffer->address);
        fb_ptr[i * (framebuffer->pitch / 4) + i] = 0xffffff;
    }

    // We're done, just hang...
    hcf();
}