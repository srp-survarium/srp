void __usercall vostok::ppmd_compressor::ppmd_compressor(vostok::ppmd_compressor *this@<ecx>, _DWORD *a2@<edi>)
{
  char *v2; // eax
  void *v3; // eax
  ppmd_compressor_impl *v4; // ecx
  ppmd_compressor_impl *v5; // eax

  a2[3] = 0;
  *a2 = &vostok::ppmd_compressor::`vftable';
  a2[1] = &vostok::memory::g_cook_allocator;
  v2 = type_info::raw_name(&ppmd_compressor_impl `RTTI Type Descriptor');
  v3 = vostok::memory::g_cook_allocator.call_malloc(
         &vostok::memory::g_cook_allocator,
         7628,
         v2,
         "vostok::ppmd_compressor::ppmd_compressor",
         ".\\compressor_ppmd.cpp",
         362);
  if ( v3 )
    v5 = ppmd_compressor_impl::ppmd_compressor_impl(v4, (int)v3);
  else
    v5 = 0;
  a2[2] = v5;
}
