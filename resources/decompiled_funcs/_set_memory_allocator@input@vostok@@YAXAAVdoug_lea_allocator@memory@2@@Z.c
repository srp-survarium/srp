void __usercall vostok::input::set_memory_allocator(vostok::memory::doug_lea_allocator *allocator@<eax>)
{
  vostok::input::g_allocator = allocator;
}
