void __thiscall vostok::render::lpv_batched_geometry::build(
        vostok::render::lpv_batched_geometry *this,
        vostok::render::render_surface_instance **model_instances)
{
  vostok::render::batched_geometry<vostok::render::lpv_vertex> *M_finish; // ecx
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *v3; // edi
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  void **v5; // esi
  vostok::math::float4x4 *v6; // ebx
  void **v7; // ebp
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> v8; // ecx
  char *M_start; // eax
  vostok::render::grass_render_model *m_object; // edx
  vostok::render::render_surface_instance **v11; // esi
  vostok::render::render_surface_instance *v12; // eax
  signed int v13; // ebp
  unsigned int v14; // eax
  int *v15; // ecx
  unsigned int v16; // ebx
  int *v17; // eax
  unsigned int v18; // ecx
  bool v19; // al
  int *v20; // edi
  void **v21; // esi
  int v22; // eax
  int *v23; // eax
  char *v24; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  void **v26; // eax
  unsigned int v27; // edi
  unsigned int v28; // eax
  int *v29; // ecx
  unsigned int v30; // ebp
  int *v31; // eax
  unsigned int v32; // ecx
  bool v33; // al
  int *v34; // ebx
  int v35; // eax
  vostok::math::float4x4 *v36; // eax
  vostok::math::float4x4 *v37; // edi
  char *v38; // eax
  malloc_state *v39; // esi
  malloc_state *v40; // esi
  vostok::math::float4x4 *i; // edi
  char *v42; // eax
  malloc_state *v43; // esi
  char *v44; // eax
  malloc_state *v45; // esi
  int v46; // [esp+18h] [ebp-40h] BYREF
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *it; // [esp+1Ch] [ebp-3Ch]
  int v48; // [esp+20h] [ebp-38h] BYREF
  int v49; // [esp+24h] [ebp-34h] BYREF
  vostok::render::render_surface_instance **end_surf; // [esp+28h] [ebp-30h]
  vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *end; // [esp+2Ch] [ebp-2Ch]
  vostok::render::lpv_batched_geometry *v52; // [esp+30h] [ebp-28h]
  vostok::render::vector<vostok::math::float4x4> matrices; // [esp+34h] [ebp-24h] BYREF
  vostok::render::vector<vostok::render::render_surface *> surfaces; // [esp+40h] [ebp-18h]
  vostok::render::vector<vostok::render::render_surface_instance *> model_surfaces; // [esp+4Ch] [ebp-Ch] BYREF
  void **it_surf; // [esp+5Ch] [ebp+4h]

  v52 = this;
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::invalidate(this, this);
  v3 = (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)*model_instances;
  v4 = (vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *)model_instances[1];
  v5 = 0;
  v6 = 0;
  v7 = 0;
  surfaces._M_impl._M_start = 0;
  surfaces._M_impl._M_end_of_storage._M_data = 0;
  memset(&matrices, 0, sizeof(matrices));
  it = v3;
  end = v4;
  if ( v3 != v4 )
  {
    do
    {
      v8.m_object = v3->m_object;
      memset(&model_surfaces, 0, sizeof(model_surfaces));
      ((void (__thiscall *)(vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base>, _DWORD, _DWORD, vostok::render::vector<vostok::render::render_surface_instance *> *, _DWORD, _DWORD, int))v8.m_object->get_surfaces)(
        v8,
        0,
        0,
        &model_surfaces,
        0,
        0,
        3);
      M_start = (char *)model_surfaces._M_impl._M_start;
      M_finish = (vostok::render::batched_geometry<vostok::render::lpv_vertex> *)model_surfaces._M_impl._M_finish;
      m_object = vostok::render::g_allocator.m_object;
      v11 = (vostok::render::render_surface_instance **)model_surfaces._M_impl._M_start;
      it_surf = model_surfaces._M_impl._M_start;
      end_surf = (vostok::render::render_surface_instance **)model_surfaces._M_impl._M_finish;
      if ( model_surfaces._M_impl._M_start != model_surfaces._M_impl._M_finish )
      {
        do
        {
          v12 = *v11;
          v49 = (int)*v11;
          if ( v7 == surfaces._M_impl._M_end_of_storage._M_data )
          {
            v13 = (char *)v7 - (char *)surfaces._M_impl._M_start;
            v14 = v13 >> 2;
            v48 = 1;
            v46 = v13 >> 2;
            if ( v13 >> 2 == 0x3FFFFFFF )
              goto LABEL_59;
            v15 = &v46;
            if ( v14 <= 1 )
              v15 = &v48;
            v16 = v14 + *v15;
            if ( v16 > 0x3FFFFFFF || v16 < v14 )
              v16 = 0x3FFFFFFF;
            v46 = v16;
            v48 = 1;
            v17 = &v48;
            if ( v16 )
              v17 = &v46;
            v18 = 4 * *v17;
            v19 = BYTE2(m_object->m_children_resources.m_lock) && v18;
            BYTE2(m_object->m_children_resources.m_lock) = v19;
            if ( v18 )
              v20 = vostok_mspace_malloc((malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v18);
            else
              v20 = 0;
            v21 = surfaces._M_impl._M_start;
            if ( v13 )
            {
              memmove((unsigned __int8 *)v20, (unsigned __int8 *)surfaces._M_impl._M_start, v13);
              v23 = (int *)(v13 + v22);
            }
            else
            {
              v23 = v20;
            }
            *v23 = *(_DWORD *)v49;
            m_object = vostok::render::g_allocator.m_object;
            v7 = (void **)(v23 + 1);
            if ( v21 )
            {
              v24 = (char *)v21;
              m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v24);
              m_object = vostok::render::g_allocator.m_object;
            }
            v26 = (void **)&v20[v16];
            v6 = matrices._M_impl._M_finish;
            surfaces._M_impl._M_start = (void **)v20;
            surfaces._M_impl._M_finish = v7;
            surfaces._M_impl._M_end_of_storage._M_data = v26;
          }
          else
          {
            *v7 = v12->m_render_surface;
            m_object = vostok::render::g_allocator.m_object;
            surfaces._M_impl._M_finish = ++v7;
          }
          M_finish = (vostok::render::batched_geometry<vostok::render::lpv_vertex> *)*((_DWORD *)*it_surf + 1);
          v46 = (int)M_finish;
          if ( v6 == matrices._M_impl._M_end_of_storage._M_data )
          {
            v27 = (char *)v6 - (char *)matrices._M_impl._M_start;
            v28 = v6 - matrices._M_impl._M_start;
            v48 = 1;
            v49 = v28;
            if ( &vostok::memory::s_CRT_arena[55905847] == (unsigned __int8 *)v28 )
LABEL_59:
              stlp_std::__stl_throw_length_error("vector");
            v29 = &v49;
            if ( v28 <= 1 )
              v29 = &v48;
            v30 = v28 + *v29;
            if ( v30 > (unsigned int)&vostok::memory::s_CRT_arena[55905847] || v30 < v28 )
              v30 = (unsigned int)&vostok::memory::s_CRT_arena[55905847];
            v48 = v30;
            v49 = 1;
            v31 = &v49;
            if ( v30 )
              v31 = &v48;
            v32 = *v31 << 6;
            v33 = BYTE2(m_object->m_children_resources.m_lock) && v32;
            BYTE2(m_object->m_children_resources.m_lock) = v33;
            if ( v32 )
              v34 = vostok_mspace_malloc((malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v32);
            else
              v34 = 0;
            if ( v27 )
            {
              memmove((unsigned __int8 *)v34, (unsigned __int8 *)matrices._M_impl._M_start, v27);
              v36 = (vostok::math::float4x4 *)(v27 + v35);
            }
            else
            {
              v36 = (vostok::math::float4x4 *)v34;
            }
            qmemcpy((void *)v36, (const void *)v46, sizeof(vostok::math::float4x4));
            m_object = vostok::render::g_allocator.m_object;
            v37 = v36 + 1;
            v38 = (char *)matrices._M_impl._M_start;
            M_finish = (vostok::render::batched_geometry<vostok::render::lpv_vertex> *)vostok::render::g_allocator.m_object;
            if ( matrices._M_impl._M_start )
            {
              v39 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v39, v38);
              m_object = vostok::render::g_allocator.m_object;
            }
            matrices._M_impl._M_start = (vostok::math::float4x4 *)v34;
            matrices._M_impl._M_end_of_storage._M_data = (vostok::math::float4x4 *)&v34[16 * v30];
            v7 = surfaces._M_impl._M_finish;
            matrices._M_impl._M_finish = v37;
            v6 = v37;
          }
          else
          {
            if ( v6 )
            {
              qmemcpy((void *)v6, (const void *)v46, sizeof(vostok::math::float4x4));
              M_finish = 0;
              m_object = vostok::render::g_allocator.m_object;
            }
            matrices._M_impl._M_finish = ++v6;
          }
          v11 = (vostok::render::render_surface_instance **)(it_surf + 1);
          it_surf = (void **)v11;
        }
        while ( v11 != end_surf );
        M_start = (char *)model_surfaces._M_impl._M_start;
        v3 = it;
      }
      if ( M_start )
      {
        v40 = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(v40, M_start);
      }
      it = ++v3;
    }
    while ( v3 != end );
    v5 = surfaces._M_impl._M_start;
  }
  for ( i = matrices._M_impl._M_start; v5 != v7; ++i )
  {
    (*(void (__thiscall **)(void *, _DWORD, vostok::math::float4x4 *))(*(_DWORD *)*v5 + 12))(*v5, 0, i);
    ++v5;
  }
  vostok::render::batched_geometry<vostok::render::lpv_vertex>::finalize_batch(M_finish, v52);
  v42 = (char *)matrices._M_impl._M_start;
  if ( matrices._M_impl._M_start )
  {
    v43 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v43, v42);
  }
  v44 = (char *)surfaces._M_impl._M_start;
  if ( surfaces._M_impl._M_start )
  {
    v45 = (malloc_state *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v45, v44);
  }
}
