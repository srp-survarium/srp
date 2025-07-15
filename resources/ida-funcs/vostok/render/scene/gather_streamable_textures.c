void __userpurge vostok::render::scene::gather_streamable_textures(
        vostok::render::scene *this@<ecx>,
        vostok::render::scene *decal,
        bool update_only)
{
  const vostok::render::material_effects *effects; // eax
  vostok::memory::doug_lea_allocator *v5; // esi
  char *v6; // eax
  vostok::memory::doug_lea_allocator *v7; // ecx
  vostok::render::streaming_texture_instance_proxy_base *v8; // eax
  const char *v9; // [esp+0h] [ebp-45018h]
  bool v10; // [esp+0h] [ebp-45018h]
  const char *v11; // [esp+4h] [ebp-45014h]
  vostok::fixed_vector<vostok::render::texture_named_instance,1024> v12; // [esp+8h] [ebp-45010h] BYREF
  char v13; // [esp+45014h] [ebp-4h] BYREF

  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_use_texture_streaming
    && this->m_parent_resources.m_thread_id )
  {
    effects = vostok::render::decal_instance::get_effects((vostok::render::decal_instance *)this, (int)this);
    v12.m_begin = (vostok::render::texture_named_instance *)v12.m_buffer;
    v12.m_end = (vostok::render::texture_named_instance *)v12.m_buffer;
    v12.m_max_end = (vostok::render::texture_named_instance *)&v13;
    vostok::render::material_effects::get_used_textures((vostok::render::material_effects *)&v12, (int)effects, &v12);
    v5 = vostok::render::g_allocator;
    v6 = type_info::raw_name(&vostok::render::decal_texture_instance_proxy `RTTI Type Descriptor');
    v8 = (vostok::render::streaming_texture_instance_proxy_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                    v7,
                                                                    (int)v5,
                                                                    0x10u,
                                                                    v6,
                                                                    v9,
                                                                    v11,
                                                                    (const unsigned int)v12.m_begin);
    if ( v8 )
    {
      v8->m_moved = 1;
      v8->m_parent_ptr = this;
      v8->__vftable = (vostok::render::streaming_texture_instance_proxy_base_vtbl *)&vostok::render::decal_texture_instance_proxy::`vftable';
      v8[1].__vftable = (vostok::render::streaming_texture_instance_proxy_base_vtbl *)this;
    }
    else
    {
      v8 = 0;
    }
    vostok::render::scene::gather_streamable_textures(decal, &v12, v8, v10);
  }
}


void __thiscall vostok::render::scene::gather_streamable_textures(
        vostok::render::scene *this,
        vostok::render::scene *gw)
{
  int v3; // esi
  int v4; // ebx
  _DWORD *v5; // eax
  int v6; // ecx
  int v7; // ecx
  int v8; // eax
  int v9; // eax
  vostok::render::material_effects *material_effects; // eax
  vostok::render::material_effects *v11; // ecx
  vostok::memory::doug_lea_allocator *v12; // esi
  char *v13; // eax
  vostok::memory::doug_lea_allocator *v14; // ecx
  vostok::render::streaming_texture_instance_proxy_base *v15; // eax
  const char *v16; // [esp+0h] [ebp-4502Ch]
  bool v17; // [esp+0h] [ebp-4502Ch]
  const char *v18; // [esp+4h] [ebp-45028h]
  unsigned int v19; // [esp+8h] [ebp-45024h]
  vostok::fixed_vector<vostok::render::texture_named_instance,1024> effect_used_textures; // [esp+Ch] [ebp-45020h] BYREF
  char v21; // [esp+45018h] [ebp-14h] BYREF
  _DWORD v22[3]; // [esp+4501Ch] [ebp-10h]
  unsigned int v23; // [esp+45028h] [ebp-4h]

  v3 = *(_DWORD *)this->m_streaming_texture_instance_allocator.m_buffer;
  v4 = *(_DWORD *)&this->m_streaming_texture_instance_allocator.m_buffer[4];
  effect_used_textures.m_begin = (vostok::render::texture_named_instance *)effect_used_textures.m_buffer;
  effect_used_textures.m_end = (vostok::render::texture_named_instance *)effect_used_textures.m_buffer;
  effect_used_textures.m_max_end = (vostok::render::texture_named_instance *)&v21;
  while ( v3 != v4 )
  {
    v5 = *(_DWORD **)(*(_DWORD *)(v3 + 76) + 16);
    v6 = v5[78];
    v23 = 0;
    v22[0] = v6;
    v7 = v5[79];
    v8 = v5[80];
    v22[1] = v7;
    v22[2] = v8;
    do
    {
      v9 = v22[v23];
      if ( v9 )
      {
        material_effects = vostok::render::render_surface::get_material_effects(
                             (vostok::render::render_surface *)&effect_used_textures,
                             v9);
        vostok::render::material_effects::get_used_textures(v11, (int)material_effects, &effect_used_textures);
      }
      ++v23;
    }
    while ( v23 < 3 );
    v3 += 16568;
  }
  if ( effect_used_textures.m_end - effect_used_textures.m_begin )
  {
    v12 = vostok::render::g_allocator;
    v13 = type_info::raw_name(&vostok::render::grass_patch_texture_instance_proxy `RTTI Type Descriptor');
    v15 = (vostok::render::streaming_texture_instance_proxy_base *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                     v14,
                                                                     (int)v12,
                                                                     0xCu,
                                                                     v13,
                                                                     v16,
                                                                     v18,
                                                                     v19);
    if ( v15 )
    {
      v15->m_moved = 1;
      v15->m_parent_ptr = this;
      v15->__vftable = (vostok::render::streaming_texture_instance_proxy_base_vtbl *)&vostok::render::grass_patch_texture_instance_proxy::`vftable';
    }
    else
    {
      v15 = 0;
    }
    vostok::render::scene::gather_streamable_textures(gw, &effect_used_textures, v15, v17);
  }
}
