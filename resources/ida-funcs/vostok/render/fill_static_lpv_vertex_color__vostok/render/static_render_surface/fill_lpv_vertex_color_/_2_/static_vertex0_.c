void __cdecl vostok::render::fill_static_lpv_vertex_color__vostok::render::static_render_surface::fill_lpv_vertex_color_::_2_::static_vertex0_(
        vostok::render::batched_geometry_interface *in_out_lpv_geometry,
        vostok::render::render_geometry *in_render_geometry,
        const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *in_materail_effects_instance,
        const vostok::math::float4x4 *in_transform)
{
  vostok::render::untyped_buffer *m_object; // eax
  vostok::render::untyped_buffer *v5; // edi
  unsigned int m_size; // ecx
  unsigned int v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  unsigned int v11; // edi
  char *v12; // esi
  vostok::render::resource_manager *v13; // eax
  vostok::render::untyped_buffer *v14; // ecx
  vostok::render::resource_manager *p_available_memory; // ecx
  float *v16; // ebx
  unsigned __int8 *v17; // esi
  double v18; // st7
  vostok::render::untyped_buffer **v19; // eax
  vostok::render::resource_manager *v20; // ecx
  vostok::render::untyped_buffer *v21; // edx
  unsigned int *v22; // eax
  unsigned int v23; // edx
  bool v24; // zf
  unsigned int v25; // edi
  vostok::memory::doug_lea_allocator *v26; // ecx
  vostok::render::resource_manager *v27; // eax
  vostok::render::untyped_buffer *v28; // ecx
  unsigned __int8 *v29; // eax
  vostok::render::untyped_buffer *v30; // ecx
  vostok::render::batched_geometry_interface_vtbl *v31; // eax
  vostok::render::untyped_buffer *v32; // eax
  vostok::render::resource_manager *v33; // ecx
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_m_ib; // eax
  vostok::render::untyped_buffer *v35; // eax
  vostok::render::untyped_buffer *v36; // edi
  vostok::render::res_declaration *v37; // eax
  vostok::render::resource_manager *v38; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::memory::doug_lea_allocator *v40; // ecx
  vostok::render::untyped_buffer *v41; // esi
  vostok::render::resource_manager *v42; // esi
  vostok::render::resource_manager *v43; // esi
  vostok::render::untyped_buffer *v44; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v45; // [esp-8h] [ebp-40A8h] BYREF
  vostok::math::float2 v46; // [esp-4h] [ebp-40A4h]
  const char *v47; // [esp+4h] [ebp-409Ch]
  unsigned int v48; // [esp+8h] [ebp-4098h]
  vostok::math::color results[64][64]; // [esp+10h] [ebp-4090h] BYREF
  unsigned int v50; // [esp+4014h] [ebp-8Ch] BYREF
  D3D11_INPUT_ELEMENT_DESC count; // [esp+4018h] [ebp-88h] BYREF
  const char *v52; // [esp+4034h] [ebp-6Ch]
  int v53; // [esp+4038h] [ebp-68h]
  int v54; // [esp+403Ch] [ebp-64h]
  int v55; // [esp+4040h] [ebp-60h]
  int v56; // [esp+4044h] [ebp-5Ch]
  int v57; // [esp+4048h] [ebp-58h]
  int v58; // [esp+404Ch] [ebp-54h]
  const char *v59; // [esp+4050h] [ebp-50h]
  int v60; // [esp+4054h] [ebp-4Ch]
  int v61; // [esp+4058h] [ebp-48h]
  int v62; // [esp+405Ch] [ebp-44h]
  int v63; // [esp+4060h] [ebp-40h]
  int v64; // [esp+4064h] [ebp-3Ch]
  int v65; // [esp+4068h] [ebp-38h]
  unsigned int size; // [esp+4070h] [ebp-30h]
  char *v67; // [esp+4074h] [ebp-2Ch]
  unsigned int *v68; // [esp+4078h] [ebp-28h]
  void *v69; // [esp+407Ch] [ebp-24h]
  vostok::render::untyped_buffer *source; // [esp+4080h] [ebp-20h]
  void *data; // [esp+4084h] [ebp-1Ch]
  vostok::render::resource_manager *v72; // [esp+4088h] [ebp-18h]
  vostok::render::untyped_buffer *ib; // [esp+408Ch] [ebp-14h]
  unsigned int stride; // [esp+4090h] [ebp-10h] BYREF
  unsigned __int8 *dst; // [esp+4094h] [ebp-Ch]
  vostok::render::resource_manager *v76; // [esp+4098h] [ebp-8h]
  unsigned int vertex_stride; // [esp+409Ch] [ebp-4h] BYREF

  memset(results, 0xFFu, sizeof(results));
  LODWORD(v46.x) = results;
  *(float *)&v45.m_object = 0.0;
  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v45,
    in_materail_effects_instance);
  if ( vostok::render::read_diffuse_colors_64_(v45, (vostok::math::color (*)[64][64])LODWORD(v46.x)) )
  {
    m_object = in_render_geometry->geom.m_object->m_vb.m_object;
    v5 = 0;
    source = 0;
    if ( m_object )
    {
      ++m_object->m_reference_count;
      source = m_object;
      v5 = m_object;
    }
    m_size = v5->m_size;
    v7 = m_size / in_render_geometry->geom.m_object->m_vb_stride;
    stride = in_render_geometry->geom.m_object->m_vb_stride;
    vertex_stride = v7;
    data = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)m_size,
             (int)vostok::render::g_allocator,
             m_size,
             "base_vb",
             (const char *const)LODWORD(v46.y),
             v47,
             v48);
    size = 20 * vertex_stride;
    v69 = vostok::memory::doug_lea_allocator::malloc_impl(
            v8,
            (int)vostok::render::g_allocator,
            20 * vertex_stride,
            "lpv_vb",
            (const char *const)LODWORD(v46.y),
            v47,
            v48);
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            v9,
            (int)vostok::render::g_allocator,
            36 * vertex_stride,
            "static_vb",
            (const char *const)LODWORD(v46.y),
            v47,
            v48);
    v11 = v5->m_size;
    v12 = v10;
    v67 = v10;
    vostok::render::resource_manager::create_buffer(
      v11,
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)stride,
      (vostok::render::enum_buffer_type)data,
      0,
      0,
      1);
    v72 = 0;
    if ( v13 )
    {
      ++v13->sh_created;
      v72 = v13;
    }
    vostok::render::resource_manager::copy(source, v72, (vostok::render::untyped_buffer *)LODWORD(v46.y));
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    dst = (unsigned __int8 *)vostok::render::untyped_buffer::map(v14, (D3D11_MAP)v72, D3D11_MAP_READ);
    if ( vertex_stride )
    {
      v16 = (float *)((char *)data + 12);
      v76 = (vostok::render::resource_manager *)((char *)v69 + 12);
      v68 = (unsigned int *)(v12 + 12);
      stride = vertex_stride;
      do
      {
        v17 = dst;
        qmemcpy(v16 - 3, dst, 0x20u);
        v18 = v16[3];
        v46.x = 0.0;
        *(float *)&v45.m_object = v18;
        v46.x = v16[4];
        v19 = (vostok::render::untyped_buffer **)vostok::render::interpolated_color_64_(
                                                   &v50,
                                                   (int)(v17 + 32),
                                                   results[0],
                                                   (vostok::math::color (*)[64][64])v45.m_object,
                                                   v46);
        v20 = v76;
        ib = *v19;
        HIBYTE(ib) = *((_BYTE *)v16 + 7);
        v21 = ib;
        v76->sh_returned = (unsigned int)ib;
        *(float *)&v20[-1].m_textures_to_reload.m_buffer[31].m_store[272] = *(v16 - 3);
        v20[-1].m_default_texture.m_object = *(vostok::render::res_texture **)(v16 - 2);
        v20[-1].m_watcher_subscribe_id = *(unsigned int *)(v16 - 1);
        v20->sh_created = *(unsigned int *)v16;
        v22 = v68;
        dst += 32;
        v68[3] = (unsigned int)v21;
        *(v22 - 3) = *((_DWORD *)v16 - 3);
        *(v22 - 2) = *((_DWORD *)v16 - 2);
        *(v22 - 1) = *((_DWORD *)v16 - 1);
        v23 = *(_DWORD *)v16;
        v22[1] = 0;
        v22[2] = 0;
        *v22 = v23;
        v22[4] = *((_DWORD *)v16 + 3);
        v22[5] = *((_DWORD *)v16 + 4);
        p_available_memory = (vostok::render::resource_manager *)&v20->available_memory;
        v16 += 8;
        v24 = stride-- == 1;
        v76 = p_available_memory;
        v68 = v22 + 9;
      }
      while ( !v24 );
    }
    vostok::render::untyped_buffer::unmap((vostok::render::untyped_buffer *)p_available_memory, (int)v72);
    v25 = in_render_geometry->geom.m_object->m_ib.m_object->m_size;
    v68 = (unsigned int *)(v25 >> 1);
    dst = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                               v26,
                               (int)vostok::render::g_allocator,
                               v25,
                               "base_ib",
                               (const char *const)LODWORD(v46.y),
                               v47,
                               v48);
    vostok::render::resource_manager::create_buffer(
      v25,
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)2,
      (vostok::render::enum_buffer_type)dst,
      1,
      0,
      1);
    v76 = 0;
    if ( v27 )
    {
      ++v27->sh_created;
      v76 = v27;
    }
    vostok::render::resource_manager::copy(
      in_render_geometry->geom.m_object->m_ib.m_object,
      v76,
      (vostok::render::untyped_buffer *)LODWORD(v46.y));
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    v29 = (unsigned __int8 *)vostok::render::untyped_buffer::map(v28, (D3D11_MAP)v76, D3D11_MAP_READ);
    memcpy(dst, v29, v25);
    vostok::render::untyped_buffer::unmap(v30, (int)v76);
    if ( in_out_lpv_geometry )
    {
      v31 = in_out_lpv_geometry->__vftable;
      stride = 0;
      v31->add_data(
        in_out_lpv_geometry,
        (const vostok::render::batched_vertex_source *)v67,
        vertex_stride,
        (const unsigned __int16 *)dst,
        (const unsigned int)v68,
        in_transform,
        (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)&stride);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&stride);
    }
    vostok::render::resource_manager::create_buffer(
      size,
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)0x14,
      (vostok::render::enum_buffer_type)v69,
      0,
      0,
      0);
    ib = 0;
    if ( v32 )
    {
      ++v32->m_reference_count;
      ib = v32;
    }
    v54 = 28;
    v61 = 28;
    p_m_ib = &in_render_geometry->geom.m_object->m_ib;
    count.SemanticName = "POSITION";
    count.SemanticIndex = 0;
    count.Format = DXGI_FORMAT_R32G32B32_FLOAT;
    memset(&count.InputSlot, 0, 16);
    v52 = "NORMAL";
    v53 = 0;
    v55 = 0;
    v56 = 12;
    v57 = 0;
    v58 = 0;
    v59 = "TEXCOORD";
    v60 = 0;
    v62 = 0;
    v63 = 16;
    v64 = 0;
    v65 = 0;
    v35 = p_m_ib->m_object;
    v36 = 0;
    if ( v35 )
    {
      v36 = v35;
      ++v35->m_reference_count;
    }
    v37 = vostok::render::resource_manager::create_declaration(
            v33,
            (const D3D11_INPUT_ELEMENT_DESC *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
            &count,
            3u);
    vertex_stride = 0;
    if ( v37 )
    {
      ++v37->m_reference_count;
      vertex_stride = (unsigned int)v37;
    }
    geometry = vostok::render::resource_manager::create_geometry(
                 v38,
                 (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
                 (vostok::render::res_declaration *)vertex_stride,
                 (vostok::render::untyped_buffer *)0x14,
                 ib,
                 v36);
    vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
      &in_render_geometry->lpv_pass_geom,
      geometry);
    if ( dst )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        (char *)dst,
        (const char *const)LODWORD(v46.y),
        v47,
        v48);
    if ( data )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        (char *)data,
        (const char *const)LODWORD(v46.y),
        v47,
        v48);
    if ( v69 )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        (char *)v69,
        (const char *const)LODWORD(v46.y),
        v47,
        v48);
    if ( v67 )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        v67,
        (const char *const)LODWORD(v46.y),
        v47,
        v48);
    vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::render::res_declaration,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&vertex_stride);
    if ( v36 )
    {
      v24 = v36->m_reference_count-- == 1;
      if ( v24 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
          v36,
          (vostok::render::hw_buffer_pool *)LODWORD(v46.y));
    }
    v41 = ib;
    if ( ib )
    {
      v24 = ib->m_reference_count-- == 1;
      if ( v24 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
          v41,
          (vostok::render::hw_buffer_pool *)LODWORD(v46.y));
    }
    v42 = v76;
    if ( v76 )
    {
      v24 = v76->sh_created-- == 1;
      if ( v24 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
          (const vostok::render::untyped_buffer *const)v42,
          (vostok::render::hw_buffer_pool *)LODWORD(v46.y));
    }
    v43 = v72;
    if ( v72 )
    {
      v24 = v72->sh_created-- == 1;
      if ( v24 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
          (const vostok::render::untyped_buffer *const)v43,
          (vostok::render::hw_buffer_pool *)LODWORD(v46.y));
    }
    v44 = source;
    v24 = source->m_reference_count-- == 1;
    if ( v24 )
      vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
        v44,
        (vostok::render::hw_buffer_pool *)LODWORD(v46.y));
  }
}
