void Halt(){
    __asm__ volatile("hlt");
}

void ClearIO(){
    __asm__ volatile ("cli");
}

void SetIO(){
    __asm__ volatile ("sti");
}