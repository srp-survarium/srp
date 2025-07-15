void __thiscall vostok::render::static_render_model_instance::get_surfaces(
        vostok::render::static_render_model_instance *this,
        const vostok::math::float3 *mat_vp,
        const vostok::math::float3 *view_pos,
        vostok::buffer_vector<vostok::render::render_surface_instance *> *list,
        bool visible_only,
        vostok::render::render_surface_instance *lod_id,
        vostok::render::static_render_model_instance *surface_flags)
{
  unsigned __int8 v7; // al
  vostok::render::static_render_model_instance *v8; // edi
  unsigned __int8 v9; // bl
  vostok::render::render_surface_instance *v10; // eax
  vostok::render::model_lods_descriptor *m_lods_descriptor; // ecx
  unsigned __int8 v12; // dl
  unsigned __int8 *v13; // esi
  vostok::buffer_vector<vostok::render::render_surface_instance *> *p_m_current_lod_index; // ecx
  unsigned __int8 *v15; // ebx
  int v16; // eax

  v7 = (unsigned __int8)lod_id;
  v8 = this;
  if ( (_BYTE)lod_id == 0xFF )
  {
    v7 = vostok::render::static_render_model_instance::select_lod(
           this,
           (const vostok::math::float4x4 *)this,
           mat_vp,
           &view_pos->x);
    if ( s_shadow_last_lod && ((unsigned __int8)surface_flags & 2) != 0 )
    {
      if ( v7 < 2u )
        ++v7;
      if ( !v7 )
        v7 = 1;
    }
    if ( v7 == 0xAA )
      goto LABEL_14;
    this = (vostok::render::static_render_model_instance *)v8->m_original.m_object->m_lods_descriptor;
    while ( !*((_BYTE *)&this->__vftable + v7) && v7 )
      --v7;
  }
  if ( v7 == 0xAA )
  {
LABEL_14:
    v9 = 0;
    for ( v8->m_current_lod_index = 0; v9 < v8->m_instances_count; ++v9 )
    {
      v10 = &v8->m_surface_instances[v9];
      lod_id = v10;
      if ( visible_only )
      {
        this = surface_flags;
        if ( ((unsigned int)surface_flags & v10->m_flags) == 0 )
          continue;
      }
      vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(
        (vostok::buffer_vector<vostok::render::render_surface_instance *> *)this,
        (int)list,
        &lod_id);
    }
    return;
  }
  if ( v7 != 3 )
  {
    m_lods_descriptor = v8->m_original.m_object->m_lods_descriptor;
    v12 = m_lods_descriptor->m_lod_surfaces_count[v7];
    if ( v12 )
    {
      v13 = m_lods_descriptor->m_lod_surfaces[v7];
      p_m_current_lod_index = (vostok::buffer_vector<vostok::render::render_surface_instance *> *)&v8->m_current_lod_index;
      HIBYTE(lod_id) = 0;
      if ( v8->m_current_lod_index != v7 )
      {
        HIBYTE(lod_id) = 1;
        LOBYTE(p_m_current_lod_index->m_begin) = v7;
      }
      v15 = v13;
      surface_flags = (vostok::render::static_render_model_instance *)v12;
      do
      {
        v16 = (int)&v8->m_surface_instances[*v15];
        view_pos = (const vostok::math::float3 *)v16;
        if ( !visible_only || (*(_BYTE *)(v16 + 28) & 1) != 0 )
        {
          if ( HIBYTE(lod_id) )
          {
            *(_DWORD *)(v16 + 24) = -1;
            *(_BYTE *)(v16 + 53) = 0;
          }
          vostok::buffer_vector<vostok::render::render_surface_instance *>::push_back(
            p_m_current_lod_index,
            (int)list,
            (vostok::render::render_surface_instance **)&view_pos);
        }
        ++v15;
        surface_flags = (vostok::render::static_render_model_instance *)((char *)surface_flags - 1);
      }
      while ( surface_flags );
    }
  }
}
