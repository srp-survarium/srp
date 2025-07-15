void __userpurge vostok::render::culling::possible_sectors_holder::possible_sectors_holder(
        vostok::render::culling::possible_sectors_holder *this@<ecx>,
        _DWORD *a2@<esi>,
        vostok::configs::binary_config_value cfg)
{
  char *v3; // eax
  char *v4; // edi
  char *pointer; // eax
  char *v6; // ecx
  int v7; // edx

  *a2 = 0;
  a2[1] = 0;
  v3 = (char *)vostok::memory::doug_lea_allocator::malloc_impl(
                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                 2 * (24 * HIWORD(*(_DWORD *)&cfg.type) / 24));
  v4 = &v3[2 * (24 * HIWORD(*(_DWORD *)&cfg.type) / 24)];
  *a2 = v3;
  pointer = (char *)cfg.data.pointer;
  v6 = (char *)cfg.data.pointer + 24 * cfg.count;
  a2[1] = v4;
  if ( cfg.data.pointer != v6 )
  {
    v7 = 0;
    do
    {
      *(_WORD *)(v7 + *a2) = *(_WORD *)pointer;
      pointer += 24;
      v7 += 2;
    }
    while ( pointer != v6 );
  }
}
