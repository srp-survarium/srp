void __userpurge vostok::render::culling::possible_sectors_holder::possible_sectors_holder(
        vostok::render::culling::possible_sectors_holder *this@<ecx>,
        char **a2@<edi>,
        vostok::configs::binary_config_value cfg)
{
  vostok::memory::doug_lea_allocator *v3; // esi
  char *v4; // eax
  unsigned int v5; // ebx
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  char *pointer; // ecx
  char *v9; // ebx
  char *v10; // eax
  int v11; // edx
  const char *v12; // [esp+0h] [ebp-Ch]
  const char *v13; // [esp+4h] [ebp-8h]
  unsigned int v14; // [esp+8h] [ebp-4h]

  *a2 = 0;
  a2[1] = 0;
  v3 = vostok::render::g_allocator;
  v4 = type_info::raw_name(&unsigned short `RTTI Type Descriptor');
  v5 = 2 * (24 * HIWORD(*(_DWORD *)&cfg.type) / 24);
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v3, v5, v4, v12, v13, v14);
  pointer = (char *)cfg.data.pointer;
  v9 = &v7[v5];
  *a2 = v7;
  v10 = (char *)cfg.data.pointer + 24 * cfg.count;
  a2[1] = v9;
  if ( cfg.data.pointer != v10 )
  {
    v11 = 0;
    do
    {
      *(_WORD *)&(*a2)[v11] = *(_WORD *)pointer;
      pointer += 24;
      v11 += 2;
    }
    while ( pointer != v10 );
  }
}
