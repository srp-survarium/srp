void __thiscall vostok::render::static_render_model_instance::get_surfaces(
        vostok::render::static_render_model_instance *this,
        const vostok::math::float4x4 *mat_vp,
        const vostok::math::float3 *view_pos,
        vostok::render::vector<vostok::render::render_surface_instance *> *list,
        bool visible_only,
        vostok::render::render_surface_instance *lod_id,
        unsigned int surface_flags)
{
  unsigned __int8 v7; // bl
  vostok::render::static_render_model_instance *v8; // ebp
  float i; // eax
  vostok::render::vector<vostok::render::render_surface_instance *> *v10; // edi
  int m_instances_count; // eax
  unsigned __int8 v12; // bl
  unsigned int v13; // esi
  vostok::render::render_surface_instance *v14; // ecx
  void **M_finish; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *m_lods_descriptor; // ecx
  unsigned __int8 v17; // al
  vostok::render::vector<vostok::render::render_surface_instance *> *v18; // edi
  int v19; // esi
  unsigned __int8 *v20; // eax
  unsigned __int8 *v21; // ebx
  int v22; // eax
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v23; // ecx
  bool v24; // [esp+0h] [ebp-10h]
  unsigned __int8 lod_surfaces_count; // [esp+18h] [ebp+8h]

  v7 = (unsigned __int8)lod_id;
  v8 = this;
  if ( (_BYTE)lod_id == 0xFF )
  {
    v7 = vostok::render::static_render_model_instance::select_lod(this, mat_vp, view_pos);
    if ( v7 == 0xAA )
      goto LABEL_7;
    this = (vostok::render::static_render_model_instance *)v8->m_original.m_object;
    for ( i = this->m_collision_object.m_aabb.max.z;
          !*(_BYTE *)(v7 + LODWORD(i));
          this = (vostok::render::static_render_model_instance *)--v7 )
    {
      if ( !v7 )
        break;
    }
  }
  if ( v7 == 0xAA )
  {
LABEL_7:
    v10 = list;
    m_instances_count = v8->m_instances_count;
    v8->m_current_lod_index = 0;
    stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
      (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)this,
      (int)v10,
      m_instances_count + v10->_M_impl._M_finish - v10->_M_impl._M_start);
    v12 = 0;
    if ( v8->m_instances_count )
    {
      v13 = surface_flags;
      do
      {
        v14 = &v8->m_surface_instances[v12];
        lod_id = v14;
        if ( !visible_only || (v13 & v14->m_flags) != 0 )
        {
          M_finish = v10->_M_impl._M_finish;
          if ( M_finish == v10->_M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
              (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&lod_id,
              (int)v10,
              M_finish,
              (void *const *)&lod_id,
              (const stlp_std::__true_type *)1,
              1,
              v24);
          }
          else
          {
            *M_finish = v14;
            ++v10->_M_impl._M_finish;
          }
        }
        ++v12;
      }
      while ( v12 < v8->m_instances_count );
    }
    return;
  }
  if ( v7 != 3 )
  {
    m_lods_descriptor = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v8->m_original.m_object->m_lods_descriptor;
    v17 = *((_BYTE *)&m_lods_descriptor->_M_start + v7);
    lod_surfaces_count = v17;
    if ( v17 )
    {
      v18 = list;
      v19 = v17;
      stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
        m_lods_descriptor,
        (int)list,
        v17 + list->_M_impl._M_finish - list->_M_impl._M_start);
      v20 = v8->m_original.m_object->m_lods_descriptor->m_lod_surfaces[v7];
      LOBYTE(lod_id) = 0;
      if ( v8->m_current_lod_index != v7 )
      {
        LOBYTE(lod_id) = 1;
        v8->m_current_lod_index = v7;
      }
      if ( lod_surfaces_count )
      {
        v21 = v20;
        do
        {
          v22 = (int)&v8->m_surface_instances[*v21];
          list = (vostok::render::vector<vostok::render::render_surface_instance *> *)v22;
          if ( !visible_only || (*(_BYTE *)(v22 + 20) & 1) != 0 )
          {
            if ( (_BYTE)lod_id )
            {
              *(_DWORD *)(v22 + 12) = -1;
              *(_BYTE *)(v22 + 25) = 0;
            }
            v23 = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v18->_M_impl._M_finish;
            if ( v23 == (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)v18->_M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::_M_insert_overflow(
                v23,
                (int)v18,
                (void **)&v23->_M_start,
                (void *const *)&list,
                (const stlp_std::__true_type *)1,
                1,
                v24);
            }
            else
            {
              v23->_M_start = (void **)v22;
              ++v18->_M_impl._M_finish;
            }
          }
          ++v21;
          --v19;
        }
        while ( v19 );
      }
    }
  }
}
