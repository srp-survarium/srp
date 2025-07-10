void __cdecl vostok::memory::delete_helper<vostok::memory::base_allocator,vostok::vectora<unsigned __int64>>(
        vostok::memory::base_allocator *allocator,
        vostok::vectora<unsigned __int64> **pointer)
{
  void *v2; // [esp+5Ch] [ebp-8h]

  if ( *pointer )
  {
    v2 = *pointer;
    stlp_std::priv::_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>::~_Impl_vector<unsigned __int64,vostok::vectora_allocator<unsigned __int64>>(&(*pointer)->_M_impl);
    vostok::memory::base_allocator::free_impl(allocator, v2);
    *pointer = 0;
  }
}
