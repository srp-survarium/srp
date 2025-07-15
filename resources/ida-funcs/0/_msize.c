unsigned int __cdecl _msize(_DWORD *pblock)
{
  if ( vostok::memory::g_crt_allocator->m_use_guards )
    return vostok::memory::g_crt_allocator->usable_size_impl(vostok::memory::g_crt_allocator, pblock);
  else
    return vostok_mspace_usable_size(pblock);
}
