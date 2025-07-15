void __usercall vostok::command_line::set_finger_print(const char *finger_print@<eax>)
{
  strcpy_s((char *)&vostok::memory::g_crt_allocator.m_arena_start, 0x200u, finger_print);
}
