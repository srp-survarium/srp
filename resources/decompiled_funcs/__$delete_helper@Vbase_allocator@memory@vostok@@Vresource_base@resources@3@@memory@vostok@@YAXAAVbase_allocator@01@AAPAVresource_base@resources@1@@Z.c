void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::resources::resource_base>(
        vostok::memory::base_allocator *allocator,
        vostok::resources::resource_base **pointer)
{
  void *v2; // [esp+0h] [ebp-8h]

  if ( *pointer )
  {
    v2 = vostok::memory::detail::get_top_pointer<vostok::resources::resource_base>(pointer);
    vostok::memory::detail::call_destructor_predicate::operator()<vostok::resources::resource_base>((vostok::memory::detail::call_destructor_predicate *)*pointer);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
