void __usercall vostok::ppmd_compressor::ppmd_compressor(vostok::ppmd_compressor *this@<ecx>, _DWORD *a2@<edi>)
{
  int v2; // eax
  ppmd_compressor_impl *v3; // ecx

  *a2 = &vostok::ppmd_compressor::`vftable';
  a2[3] = 0;
  a2[1] = &vostok::memory::g_cook_allocator;
  v2 = ((int (__stdcall *)(int))vostok::memory::g_cook_allocator.call_malloc)(7628);
  if ( v2 )
    a2[2] = ppmd_compressor_impl::ppmd_compressor_impl(v3, v2);
  else
    a2[2] = 0;
}
