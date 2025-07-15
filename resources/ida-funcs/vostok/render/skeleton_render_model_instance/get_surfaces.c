void __thiscall vostok::render::skeleton_render_model_instance::get_surfaces(
        vostok::render::skeleton_render_model_instance *this,
        const vostok::math::float4x4 *__formal,
        const vostok::math::float3 *a3,
        int list,
        bool visible_only,
        unsigned __int8 a6,
        unsigned int surface_flags)
{
  vostok::render::vector<vostok::render::render_surface_instance *> *v7; // edi
  vostok::render::skeleton_render_model_instance *v8; // ebp
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *m_instances_count; // ecx
  vostok::render::render_surface_instance *v10; // ebx
  char *M_finish; // esi
  unsigned int v12; // eax
  char v13; // dl
  int *p_list; // ecx
  unsigned int v15; // ecx
  int *v16; // eax
  int v17; // ecx
  vostok::render::grass_render_model *m_object; // eax
  unsigned int v19; // ecx
  unsigned __int8 *v20; // ebp
  unsigned int v21; // esi
  int v22; // eax
  unsigned __int8 *v23; // eax
  void **v24; // ebx
  unsigned __int8 *M_start; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v27; // ecx
  unsigned int v28; // [esp-4h] [ebp-28h]
  int v29; // [esp+10h] [ebp-14h]
  unsigned int i; // [esp+14h] [ebp-10h]
  int v31; // [esp+18h] [ebp-Ch] BYREF
  unsigned int v32; // [esp+1Ch] [ebp-8h] BYREF
  vostok::render::skeleton_render_model_instance *v33; // [esp+20h] [ebp-4h]

  v7 = (vostok::render::vector<vostok::render::render_surface_instance *> *)list;
  v8 = this;
  m_instances_count = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)this->m_instances_count;
  v28 = (unsigned int)m_instances_count + ((*(_DWORD *)(list + 4) - *(_DWORD *)list) >> 2);
  v33 = v8;
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(m_instances_count, list, v28);
  i = 0;
  if ( v8->m_instances_count )
  {
    v29 = 0;
    do
    {
      v10 = &v8->m_surface_instances[v29];
      if ( !visible_only || (surface_flags & v10->m_flags) != 0 )
      {
        M_finish = (char *)v7->_M_impl._M_finish;
        if ( M_finish == (char *)v7->_M_impl._M_end_of_storage._M_data )
        {
          v12 = (M_finish - (char *)v7->_M_impl._M_start) >> 2;
          v13 = 1;
          v31 = 1;
          list = v12;
          if ( v12 == 0x3FFFFFFF )
            stlp_std::__stl_throw_length_error("vector");
          p_list = &list;
          if ( v12 <= 1 )
            p_list = &v31;
          v15 = v12 + *p_list;
          list = v15;
          if ( v15 > 0x3FFFFFFF || v15 < v12 )
          {
            list = 0x3FFFFFFF;
            v15 = 0x3FFFFFFF;
          }
          v32 = v15;
          v31 = 1;
          v16 = &v31;
          if ( v15 )
            v16 = (int *)&v32;
          v17 = *v16;
          m_object = vostok::render::g_allocator.m_object;
          v19 = 4 * v17;
          if ( !BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) || !v19 )
            v13 = 0;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = v13;
          if ( v19 )
            v20 = (unsigned __int8 *)vostok_mspace_malloc(
                                       (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick),
                                       v19);
          else
            v20 = 0;
          v21 = M_finish - (char *)v7->_M_impl._M_start;
          if ( v21 )
          {
            memmove(v20, (unsigned __int8 *)v7->_M_impl._M_start, v21);
            v23 = (unsigned __int8 *)(v21 + v22);
          }
          else
          {
            v23 = v20;
          }
          *(_DWORD *)v23 = v10;
          v24 = (void **)(v23 + 4);
          M_start = (unsigned __int8 *)v7->_M_impl._M_start;
          if ( v7->_M_impl._M_start )
          {
            m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free(m_reconstruction_info_actuality_tick_high, M_start);
          }
          v27 = (void **)&v20[4 * list];
          v7->_M_impl._M_start = (void **)v20;
          v8 = v33;
          v7->_M_impl._M_finish = v24;
          v7->_M_impl._M_end_of_storage._M_data = v27;
        }
        else
        {
          *(_DWORD *)M_finish = v10;
          ++v7->_M_impl._M_finish;
        }
      }
      ++v29;
      ++i;
    }
    while ( i < v8->m_instances_count );
  }
}
