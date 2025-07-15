void __cdecl vostok::render::fill_static_lpv_vertex_color__vostok::render::static_render_surface::fill_lpv_vertex_color_::_2_::colored_static_vertex_(
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
  vostok::render::untyped_buffer *p_m_size; // ecx
  char *v16; // edx
  char *v17; // ebx
  unsigned int v18; // esi
  vostok::render::resource_manager *v19; // eax
  vostok::render::untyped_buffer *v20; // ecx
  char *v21; // edx
  char *v22; // edx
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
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v45; // [esp-8h] [ebp-40B0h] BYREF
  vostok::math::float2 v46; // [esp-4h] [ebp-40ACh]
  const char *v47; // [esp+4h] [ebp-40A4h]
  unsigned int v48; // [esp+8h] [ebp-40A0h]
  vostok::math::color results[64][64]; // [esp+10h] [ebp-4098h] BYREF
  unsigned int v50; // [esp+4014h] [ebp-94h] BYREF
  D3D11_INPUT_ELEMENT_DESC count; // [esp+4018h] [ebp-90h] BYREF
  const char *v52; // [esp+4034h] [ebp-74h]
  int v53; // [esp+4038h] [ebp-70h]
  int v54; // [esp+403Ch] [ebp-6Ch]
  int v55; // [esp+4040h] [ebp-68h]
  int v56; // [esp+4044h] [ebp-64h]
  int v57; // [esp+4048h] [ebp-60h]
  int v58; // [esp+404Ch] [ebp-5Ch]
  const char *v59; // [esp+4050h] [ebp-58h]
  int v60; // [esp+4054h] [ebp-54h]
  int v61; // [esp+4058h] [ebp-50h]
  int v62; // [esp+405Ch] [ebp-4Ch]
  int v63; // [esp+4060h] [ebp-48h]
  int v64; // [esp+4064h] [ebp-44h]
  int v65; // [esp+4068h] [ebp-40h]
  unsigned int size; // [esp+4074h] [ebp-34h]
  char *v67; // [esp+4078h] [ebp-30h]
  char *v68; // [esp+407Ch] [ebp-2Ch]
  void *data; // [esp+4080h] [ebp-28h]
  vostok::render::untyped_buffer *v70; // [esp+4084h] [ebp-24h]
  vostok::render::untyped_buffer *source; // [esp+4088h] [ebp-20h]
  void *v72; // [esp+408Ch] [ebp-1Ch]
  vostok::render::resource_manager *v73; // [esp+4090h] [ebp-18h]
  unsigned int stride; // [esp+4094h] [ebp-14h] BYREF
  unsigned int vertex_stride; // [esp+4098h] [ebp-10h] BYREF
  unsigned __int8 *dst; // [esp+409Ch] [ebp-Ch]
  vostok::render::untyped_buffer *ib; // [esp+40A0h] [ebp-8h]
  vostok::render::resource_manager *p_m_loaded_texture_names; // [esp+40A4h] [ebp-4h]

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
    ib = (vostok::render::untyped_buffer *)v7;
    data = vostok::memory::doug_lea_allocator::malloc_impl(
             (vostok::memory::doug_lea_allocator *)m_size,
             (int)vostok::render::g_allocator,
             m_size,
             "base_vb",
             (const char *const)LODWORD(v46.y),
             v47,
             v48);
    p_m_loaded_texture_names = (vostok::render::resource_manager *)data;
    size = 20 * (_DWORD)ib;
    v72 = vostok::memory::doug_lea_allocator::malloc_impl(
            v8,
            (int)vostok::render::g_allocator,
            20 * (_DWORD)ib,
            "lpv_vb",
            (const char *const)LODWORD(v46.y),
            v47,
            v48);
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            v9,
            (int)vostok::render::g_allocator,
            36 * (_DWORD)ib,
            "static_vb",
            (const char *const)LODWORD(v46.y),
            v47,
            v48);
    v11 = v5->m_size;
    v12 = v10;
    v68 = v10;
    vostok::render::resource_manager::create_buffer(
      v11,
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)stride,
      (vostok::render::enum_buffer_type)data,
      0,
      0,
      1);
    v73 = 0;
    if ( v13 )
    {
      ++v13->sh_created;
      v73 = v13;
    }
    vostok::render::resource_manager::copy(source, v73, (vostok::render::untyped_buffer *)LODWORD(v46.y));
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    vertex_stride = (unsigned int)vostok::render::untyped_buffer::map(v14, (D3D11_MAP)v73, D3D11_MAP_READ);
    if ( ib )
    {
      v70 = (vostok::render::untyped_buffer *)((char *)v72 + 12);
      v16 = (char *)((_BYTE *)data - v12);
      v17 = v12 + 12;
      v67 = (char *)((_BYTE *)data - v12);
      stride = (unsigned int)ib;
      while ( 1 )
      {
        v18 = vertex_stride;
        qmemcpy(p_m_loaded_texture_names, (const void *)vertex_stride, 0x24u);
        v46.x = 0.0;
        *(float *)&v45.m_object = 0.0;
        v45.m_object = (vostok::particle::particle_system_instance_impl *)p_m_loaded_texture_names->m_video_memory_size;
        v46.x = *(float *)&v16[(_DWORD)v17 + 16];
        dst = (unsigned __int8 *)vostok::render::interpolated_color_64_(
                                   &v50,
                                   v18 + 36,
                                   results[0],
                                   (vostok::math::color (*)[64][64])v45.m_object,
                                   v46)->m_value;
        v19 = p_m_loaded_texture_names;
        HIBYTE(dst) = HIBYTE(p_m_loaded_texture_names->sl_created);
        v20 = v70;
        v70->pool_range.owner = (vostok::render::hw_buffer_pool_chunk *)dst;
        v21 = v67;
        v20[-1].m_size = v19->sh_created;
        v20[-1].m_stride = v19->sh_returned;
        v20[-1].m_type = v19->tl_created;
        v22 = &v21[(_DWORD)v17];
        v20->m_reference_count = *(_DWORD *)v22;
        vertex_stride += 36;
        *((_DWORD *)v17 + 3) = dst;
        *((_DWORD *)v17 - 3) = v19->sh_created;
        *((_DWORD *)v17 - 2) = v19->sh_returned;
        *((_DWORD *)v17 - 1) = v19->tl_created;
        v23 = *(_DWORD *)v22;
        *((_DWORD *)v17 + 1) = 0;
        *((_DWORD *)v17 + 2) = 0;
        *(_DWORD *)v17 = v23;
        *((_QWORD *)v17 + 2) = v19->m_video_memory_size;
        p_m_size = (vostok::render::untyped_buffer *)&v20->m_size;
        v17 += 36;
        v24 = stride-- == 1;
        p_m_loaded_texture_names = (vostok::render::resource_manager *)&v19->m_loaded_texture_names;
        v70 = p_m_size;
        if ( v24 )
          break;
        v16 = v67;
      }
    }
    vostok::render::untyped_buffer::unmap(p_m_size, (int)v73);
    v25 = in_render_geometry->geom.m_object->m_ib.m_object->m_size;
    v70 = (vostok::render::untyped_buffer *)(v25 >> 1);
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
    p_m_loaded_texture_names = 0;
    if ( v27 )
    {
      ++v27->sh_created;
      p_m_loaded_texture_names = v27;
    }
    vostok::render::resource_manager::copy(
      in_render_geometry->geom.m_object->m_ib.m_object,
      p_m_loaded_texture_names,
      (vostok::render::untyped_buffer *)LODWORD(v46.y));
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->Flush(vostok::quasi_singleton<vostok::render::device>::pinst->m_context);
    v29 = (unsigned __int8 *)vostok::render::untyped_buffer::map(
                               v28,
                               (D3D11_MAP)p_m_loaded_texture_names,
                               D3D11_MAP_READ);
    memcpy(dst, v29, v25);
    vostok::render::untyped_buffer::unmap(v30, (int)p_m_loaded_texture_names);
    if ( in_out_lpv_geometry )
    {
      v31 = in_out_lpv_geometry->__vftable;
      stride = 0;
      v31->add_data(
        in_out_lpv_geometry,
        (const vostok::render::batched_vertex_source *)v68,
        (const unsigned int)ib,
        (const unsigned __int16 *)dst,
        (const unsigned int)v70,
        in_transform,
        (const vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)&stride);
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&stride);
    }
    vostok::render::resource_manager::create_buffer(
      size,
      vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
      (void *)0x14,
      (vostok::render::enum_buffer_type)v72,
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
    if ( v72 )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        (char *)v72,
        (const char *const)LODWORD(v46.y),
        v47,
        v48);
    if ( v68 )
      vostok::memory::doug_lea_allocator::free_impl(
        v40,
        (int)vostok::render::g_allocator,
        v68,
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
    v42 = p_m_loaded_texture_names;
    if ( p_m_loaded_texture_names )
    {
      v24 = p_m_loaded_texture_names->sh_created-- == 1;
      if ( v24 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::untyped_buffer>(
          (const vostok::render::untyped_buffer *const)v42,
          (vostok::render::hw_buffer_pool *)LODWORD(v46.y));
    }
    v43 = v73;
    if ( v73 )
    {
      v24 = v73->sh_created-- == 1;
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
