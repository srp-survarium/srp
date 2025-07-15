unsigned __int64 __userpurge vostok::render::resource_manager::allocate_texture_pools@<edx:eax>(
        vostok::render::resource_manager *this@<ecx>,
        unsigned int calculate_memory,
        float __formal,
        float a4)
{
  unsigned int v4; // edi
  char *v5; // ebx
  vostok::memory::doug_lea_allocator *v6; // esi
  vostok::memory::doug_lea_allocator *v7; // ecx
  vostok::memory::doug_lea_allocator *v8; // esi
  char *v9; // eax
  vostok::memory::doug_lea_allocator *v10; // ecx
  char *v11; // edx
  char *v12; // eax
  unsigned int v13; // ecx
  vostok::render::resource_manager *v14; // ecx
  vostok::render::resource_manager *v15; // ecx
  vostok::render::resource_manager *v16; // ecx
  vostok::render::resource_manager *v17; // ecx
  const char *v19; // [esp+0h] [ebp-3Ch]
  const char *v20; // [esp+4h] [ebp-38h]
  unsigned int v21; // [esp+8h] [ebp-34h]
  int v22; // [esp+Ch] [ebp-30h] BYREF
  int v23; // [esp+10h] [ebp-2Ch] BYREF
  int v24; // [esp+14h] [ebp-28h]
  int v25; // [esp+18h] [ebp-24h] BYREF
  int v26; // [esp+1Ch] [ebp-20h]
  int v27; // [esp+20h] [ebp-1Ch]
  int v28; // [esp+24h] [ebp-18h]
  DXGI_FORMAT v29; // [esp+28h] [ebp-14h]
  DXGI_FORMAT v30; // [esp+2Ch] [ebp-10h]
  DXGI_FORMAT v31; // [esp+30h] [ebp-Ch]
  vostok::render::resource_manager *v32; // [esp+34h] [ebp-8h]

  v4 = calculate_memory;
  if ( *(_DWORD *)((char *)&loc_948DA + calculate_memory + 2) )
  {
    v5 = *(char **)((char *)&loc_948DA + calculate_memory + 2);
    v6 = vostok::render::g_allocator;
    if ( v5 )
    {
      vostok::render::texture_storage::~texture_storage(
        (vostok::render::texture_storage *)this,
        *(_DWORD *)((char *)&loc_948DA + calculate_memory + 2));
      vostok::memory::doug_lea_allocator::free_impl(v7, (int)v6, v5, v19, v20, v21);
      *(_DWORD *)((char *)&loc_948DA + calculate_memory + 2) = 0;
    }
  }
  v8 = vostok::render::g_allocator;
  v9 = type_info::raw_name(&vostok::render::texture_storage `RTTI Type Descriptor');
  v11 = vostok::memory::doug_lea_allocator::malloc_impl(v10, (int)v8, 0x20u, v9, v19, v20, v21);
  v12 = 0;
  if ( v11 )
  {
    *(_DWORD *)v11 = 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    *((_DWORD *)v11 + 1) = 0;
    *((_DWORD *)v11 + 2) = v26;
    *((_DWORD *)v11 + 3) = v27;
    *((_DWORD *)v11 + 4) = v28;
    *((_DWORD *)v11 + 2) = 0;
    *((_DWORD *)v11 + 5) = 0;
    v4 = calculate_memory;
    v11[24] = HIBYTE(calculate_memory);
    v11[4] = 0;
    *((_DWORD *)v11 + 3) = v11 + 4;
    *((_DWORD *)v11 + 4) = v11 + 4;
    v11[28] = 0;
    v12 = v11;
  }
  v13 = *(_DWORD *)((char *)&loc_88198 + v4);
  *(_DWORD *)((char *)&loc_948DA + v4 + 2) = v12;
  v27 = 1024;
  v28 = 1024;
  v32 = (vostok::render::resource_manager *)v13;
  v22 = 1;
  v23 = 32;
  v24 = 128;
  v25 = 256;
  v26 = 512;
  v29 = 4096 >> v13;
  vostok::render::resource_manager::add_pool_textures(
    (vostok::render::resource_manager *)v13,
    calculate_memory,
    v13,
    4096 >> v13,
    (DXGI_FORMAT)(4096 >> v13),
    (unsigned int *)0x46,
    (unsigned int)&v22,
    7u,
    1u);
  v27 = 1024;
  v28 = 1024;
  v22 = 1;
  v23 = 32;
  v24 = 128;
  v25 = 256;
  v26 = 512;
  vostok::render::resource_manager::add_pool_textures(
    v14,
    calculate_memory,
    (unsigned int)v32,
    v29,
    v29,
    (unsigned int *)0x4C,
    (unsigned int)&v22,
    7u,
    1u);
  v31 = 2048 >> (char)v32;
  v23 = 1;
  v24 = 8;
  v25 = 16;
  v26 = 32;
  v27 = 64;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    v32,
    calculate_memory,
    (unsigned int)v32,
    v29,
    (DXGI_FORMAT)(2048 >> (char)v32),
    (unsigned int *)0x46,
    (unsigned int)&v23,
    6u,
    1u);
  v23 = 1;
  v24 = 8;
  v25 = 16;
  v26 = 32;
  v27 = 64;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    v15,
    calculate_memory,
    (unsigned int)v32,
    v29,
    v31,
    (unsigned int *)0x4C,
    (unsigned int)&v23,
    6u,
    1u);
  v23 = 1;
  v30 = 1024 >> (char)v32;
  v24 = 8;
  v25 = 16;
  v26 = 32;
  v27 = 64;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    v32,
    calculate_memory,
    (unsigned int)v32,
    1024 >> (char)v32,
    v31,
    (unsigned int *)0x46,
    (unsigned int)&v23,
    6u,
    1u);
  v23 = 1;
  v24 = 8;
  v25 = 16;
  v26 = 32;
  v27 = 64;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    v16,
    calculate_memory,
    (unsigned int)v32,
    v30,
    v31,
    (unsigned int *)0x4C,
    (unsigned int)&v23,
    6u,
    1u);
  v26 = 4;
  v25 = 1;
  v27 = 128;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    v32,
    calculate_memory,
    (unsigned int)v32,
    v30,
    (DXGI_FORMAT)(256 >> (char)v32),
    (unsigned int *)0x46,
    (unsigned int)&v25,
    4u,
    1u);
  v22 = 1;
  v23 = 4;
  v24 = 16;
  v25 = 32;
  v26 = 128;
  v27 = 128;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    v17,
    calculate_memory,
    (unsigned int)v32,
    v29,
    v30,
    (unsigned int *)0x4C,
    (unsigned int)&v22,
    7u,
    1u);
  v25 = 4;
  v26 = 16;
  v27 = 64;
  v28 = 128;
  vostok::render::resource_manager::add_pool_textures(
    (vostok::render::resource_manager *)&v25,
    calculate_memory,
    (unsigned int)v32,
    512 >> (char)v32,
    (DXGI_FORMAT)(512 >> (char)v32),
    (unsigned int *)0x4C,
    (unsigned int)&v25,
    4u,
    6u);
  return (unsigned int)vostok::render::texture_storage::total_allocated_memory(*(vostok::render::texture_storage **)((char *)&loc_948DA + calculate_memory + 2));
}
