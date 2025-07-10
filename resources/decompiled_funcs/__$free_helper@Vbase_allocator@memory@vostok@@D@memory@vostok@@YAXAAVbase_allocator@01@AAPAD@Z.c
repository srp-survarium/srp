void __usercall vostok::memory::free_helper<vostok::memory::base_allocator,char>(
        vostok::memory::base_allocator *allocator@<ecx>,
        char **pointer@<esi>)
{
  if ( *pointer )
  {
    allocator->call_free(allocator, *pointer);
    *pointer = 0;
  }
}
