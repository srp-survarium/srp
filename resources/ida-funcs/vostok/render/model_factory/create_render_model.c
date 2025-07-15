void __usercall vostok::render::model_factory::create_render_model(unsigned __int16 type@<ax>)
{
  int v1; // eax
  vostok::memory::doug_lea_allocator *v2; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  vostok::render::render_model *v5; // ecx
  char *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  char *v9; // eax
  vostok::render::skeleton_render_model *v10; // ecx
  char *v11; // eax
  vostok::memory::doug_lea_allocator *v12; // ecx
  vostok::render::render_model *v13; // ecx
  char *v14; // esi
  const char *v15; // [esp+0h] [ebp-Ch]
  const char *v16; // [esp+4h] [ebp-8h]
  unsigned int v17; // [esp+8h] [ebp-4h]

  v1 = type - 1;
  v2 = vostok::render::g_allocator;
  if ( v1 )
  {
    if ( v1 == 39 )
    {
      v7 = type_info::raw_name(&vostok::render::skeleton_render_model `RTTI Type Descriptor');
      v9 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v2, 0x2150u, v7, v15, v16, v17);
      if ( v9 )
        vostok::render::skeleton_render_model::skeleton_render_model(v10, (vostok::shared_string *)v9);
    }
    else
    {
      v3 = type_info::raw_name(&vostok::render::grass_render_model `RTTI Type Descriptor');
      v6 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v2, 0x148u, v3, v15, v16, v17);
      if ( v6 )
      {
        vostok::render::render_model::render_model(v5, (int)v6);
        *((_DWORD *)v6 + 78) = 0;
        *((_DWORD *)v6 + 79) = 0;
        *((_DWORD *)v6 + 80) = 0;
        *(_DWORD *)v6 = &vostok::render::grass_render_model::`vftable';
      }
    }
  }
  else
  {
    v11 = type_info::raw_name(&vostok::render::static_render_model `RTTI Type Descriptor');
    v14 = vostok::memory::doug_lea_allocator::malloc_impl(v12, (int)v2, 0x138u, v11, v15, v16, v17);
    if ( v14 )
    {
      vostok::render::render_model::render_model(v13, (int)v14);
      *(_DWORD *)v14 = &vostok::render::static_render_model::`vftable';
    }
  }
}
