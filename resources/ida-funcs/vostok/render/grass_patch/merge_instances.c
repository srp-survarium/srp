void __thiscall vostok::render::grass_patch::merge_instances(
        vostok::render::grass_patch *this,
        vostok::render::grass_patch *thisa)
{
  vostok::render::grass_patch *v2; // edi
  void **m_sort_info; // ebx
  void *v4; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model ****M_start; // esi
  vostok::render::grass_render_model *v7; // eax
  vostok::render::grass_render_model ****j; // esi
  vostok::render::grass_render_model *v9; // eax
  vostok::render::grass_render_surface *v10; // eax
  char *v11; // eax
  vostok::render::stream_1_type *v12; // edi
  vostok::render::grass_source_vertex *v13; // ebp
  unsigned __int8 *v14; // eax
  vostok::memory::doug_lea_allocator *m_object; // ecx
  void *v16; // eax
  void *v17; // esi
  vostok::render::grass_patch::sort_info *v18; // eax
  vostok::render::grass_instance *const *v19; // eax
  vostok::render::grass_instance *v20; // esi
  vostok::render::grass_render_model *v21; // eax
  vostok::render::grass_render_surface *v22; // eax
  vostok::render::grass_render_surface *v23; // ebx
  float *v24; // eax
  float x; // xmm4_4
  float v26; // xmm1_4
  float v27; // xmm0_4
  float v28; // xmm2_4
  float v29; // xmm3_4
  const vostok::math::float4x4 *p_m_transform; // esi
  float v31; // xmm3_4
  float y; // xmm4_4
  float v33; // xmm3_4
  float v34; // xmm0_4
  const vostok::math::float4x4 *v35; // xmm1_4
  unsigned int v36; // eax
  float z; // xmm0_4
  float v38; // xmm1_4
  float v39; // xmm2_4
  float v40; // xmm4_4
  float v41; // xmm3_4
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v43; // ecx
  survarium::game_vtbl *v44; // esi
  bool v45; // zf
  vostok::render::resource_manager *v46; // eax
  survarium::game *m_game; // ecx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *m_movie; // edx
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> **p_m_movie; // edi
  survarium::options_tab *v50; // ebp
  void (__thiscall *tick)(struct survarium::game *, unsigned int); // eax
  vostok::render::grass_render_model *v52; // edi
  survarium::game_vtbl *v53; // eax
  void *v54; // esi
  vostok::render::resource_manager *v55; // esi
  vostok::render::resource_manager *v56; // edi
  vostok::render::res_declaration *declaration; // ebp
  vostok::render::untyped_buffer *v58; // eax
  vostok::render::grass_source_vertex *v59; // esi
  vostok::render::untyped_buffer *v60; // eax
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry *v62; // ecx
  vostok::render::res_geometry *v63; // eax
  vostok::render::grass_render_model *v64; // ecx
  void *v65; // esi
  vostok::render::grass_source_vertex *v66; // eax
  void *v67; // esi
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> v68; // [esp-4h] [ebp-74h]
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> v69; // [esp-4h] [ebp-74h]
  vostok::resources::resource_ptr<vostok::render::grass_render_model,vostok::resources::unmanaged_intrusive_base> v70; // [esp-4h] [ebp-74h]
  vostok::render::untyped_buffer *v71; // [esp-4h] [ebp-74h]
  vostok::render::grass_instance *const *end; // [esp+18h] [ebp-58h]
  unsigned int lod_index; // [esp+1Ch] [ebp-54h]
  vostok::render::stream_1_type *stream_1_data_it; // [esp+20h] [ebp-50h]
  unsigned int current_num_vertices; // [esp+24h] [ebp-4Ch]
  unsigned __int8 *merged_indices_it; // [esp+28h] [ebp-48h]
  unsigned int current_num_indices; // [esp+2Ch] [ebp-44h]
  vostok::render::grass_instance *const *it; // [esp+30h] [ebp-40h]
  vostok::render::grass_patch::sort_info *sort_info_it; // [esp+34h] [ebp-3Ch]
  vostok::math::color color_and_wind; // [esp+38h] [ebp-38h]
  vostok::math::color color_and_winda; // [esp+38h] [ebp-38h]
  int ia; // [esp+3Ch] [ebp-34h]
  unsigned int i; // [esp+3Ch] [ebp-34h]
  vostok::render::stream_1_type *stream_1_data; // [esp+40h] [ebp-30h]
  vostok::render::grass_source_vertex *merged_vertices; // [esp+44h] [ebp-2Ch]
  void **__first; // [esp+48h] [ebp-28h]
  survarium::options_tab *__firsta; // [esp+48h] [ebp-28h]
  int v88; // [esp+4Ch] [ebp-24h] BYREF
  int v89; // [esp+50h] [ebp-20h] BYREF
  int v90; // [esp+54h] [ebp-1Ch] BYREF
  __int64 v91; // [esp+58h] [ebp-18h]
  float v92; // [esp+60h] [ebp-10h]
  __int64 v93; // [esp+64h] [ebp-Ch]
  float v94; // [esp+6Ch] [ebp-4h]

  v2 = thisa;
  if ( thisa->m_instances._M_impl._M_finish - thisa->m_instances._M_impl._M_start )
  {
    m_sort_info = (void **)thisa->m_sort_info;
    thisa->m_num_avaliable_lods = 0;
    lod_index = 0;
    __first = (void **)thisa->m_sort_info;
    while ( 1 )
    {
      end = (vostok::render::grass_instance *const *)v2->m_instances._M_impl._M_finish;
      v4 = *(m_sort_info - 3);
      if ( v4 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v4);
        *(m_sort_info - 3) = 0;
      }
      m_sort_info[3] = 0;
      m_sort_info[6] = 0;
      M_start = (vostok::render::grass_render_model ****)v2->m_instances._M_impl._M_start;
      if ( M_start == (vostok::render::grass_render_model ****)end )
        goto LABEL_60;
      while ( 1 )
      {
        v68.m_object = 0;
        v7 = ***M_start;
        if ( v7 )
        {
          v68.m_object = ***M_start;
          _InterlockedExchangeAdd(&v7->m_reference_count, 1u);
        }
        if ( vostok::render::has_surface_by_lod(lod_index, v68) )
          break;
        if ( ++M_start == (vostok::render::grass_render_model ****)end )
          goto LABEL_60;
      }
      for ( j = (vostok::render::grass_render_model ****)v2->m_instances._M_impl._M_start;
            j != (vostok::render::grass_render_model ****)end;
            ++j )
      {
        v69.m_object = 0;
        v9 = ***j;
        if ( v9 )
        {
          v69.m_object = ***j;
          _InterlockedExchangeAdd(&v9->m_reference_count, 1u);
        }
        v10 = vostok::render::surface_by_lod(lod_index, v69);
        if ( v10 )
        {
          m_sort_info[3] = (char *)m_sort_info[3] + v10->m_num_vertices;
          m_sort_info[6] = (char *)m_sort_info[6] + v10->m_num_indices;
        }
      }
      v11 = (char *)&_sbh_sizeHeaderList
          + (unsigned int)(m_sort_info[3] < &_sbh_sizeHeaderList ? (char *)m_sort_info[3] - 0x10000 : 0);
      m_sort_info[3] = v11;
      v12 = (vostok::render::stream_1_type *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               16 * (_DWORD)v11);
      stream_1_data = v12;
      stream_1_data_it = v12;
      merged_vertices = (vostok::render::grass_source_vertex *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                                 32 * (_DWORD)m_sort_info[3]);
      v13 = merged_vertices;
      v14 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(
                                 (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                 2 * (_DWORD)m_sort_info[6]);
      *(m_sort_info - 3) = v14;
      m_object = (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object;
      merged_indices_it = v14;
      v16 = *m_sort_info;
      current_num_vertices = 0;
      current_num_indices = 0;
      if ( *m_sort_info )
      {
        v17 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(v17, v16);
        *m_sort_info = 0;
        m_object = (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object;
      }
      v18 = (vostok::render::grass_patch::sort_info *)vostok::memory::doug_lea_allocator::malloc_impl(
                                                        m_object,
                                                        20
                                                      * (thisa->m_instances._M_impl._M_finish
                                                       - thisa->m_instances._M_impl._M_start));
      *m_sort_info = v18;
      sort_info_it = v18;
      v19 = (vostok::render::grass_instance *const *)thisa->m_instances._M_impl._M_start;
      it = v19;
      if ( v19 != end )
      {
        while ( 1 )
        {
          v20 = *v19;
          v70.m_object = 0;
          v21 = ***(vostok::render::grass_render_model ****)v19;
          color_and_wind = (vostok::math::color)v20;
          if ( v21 )
          {
            v70.m_object = v21;
            _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
          }
          v22 = vostok::render::surface_by_lod(lod_index, v70);
          v23 = v22;
          if ( v22 && current_num_vertices + v22->m_num_vertices < (unsigned int)&_sbh_sizeHeaderList )
          {
            v24 = (float *)v20->m_template->m_render_model.m_object;
            x = v20->m_transform.j.x;
            v26 = (float)(v24[70] + v24[67]) * 0.5;
            v27 = (float)(v24[66] + v24[69]) * 0.5;
            v28 = (float)(v24[71] + v24[68]) * 0.5;
            v29 = v20->m_transform.k.x * v28;
            p_m_transform = &v20->m_transform;
            v31 = (float)((float)(v29 + (float)(x * v26)) + (float)(p_m_transform->i.x * v27)) + p_m_transform->c.x;
            y = p_m_transform->j.y;
            *(float *)&v91 = v31;
            *((float *)&v91 + 1) = (float)((float)((float)(p_m_transform->k.y * v28) + (float)(y * v26))
                                         + (float)(p_m_transform->i.y * v27))
                                 + p_m_transform->c.y;
            v33 = (float)((float)((float)(p_m_transform->k.z * v28) + (float)(p_m_transform->j.z * v26))
                        + (float)(p_m_transform->i.z * v27))
                + p_m_transform->c.z;
            *(_QWORD *)&sort_info_it->position.x = v91;
            sort_info_it->index_offset = current_num_indices;
            v92 = v33;
            sort_info_it->position.z = v33;
            sort_info_it->num_indices = v23->m_num_indices;
            ++sort_info_it;
            ia = 2 * v23->m_num_indices;
            memcpy((unsigned __int8 *)v13, (unsigned __int8 *)v23->m_vertices, 32 * v23->m_num_vertices);
            memcpy(merged_indices_it, (unsigned __int8 *)v23->m_indices, ia);
            v34 = *(float *)(*(_DWORD *)&color_and_wind + 72);
            *(float *)&v35 = 0.0;
            color_and_winda = *(vostok::math::color *)(*(_DWORD *)&color_and_wind + 4);
            if ( v34 <= 0.0 || (v35 = clear_value, *(float *)&clear_value < v34) )
              v34 = *(float *)&v35;
            v36 = 0;
            for ( color_and_winda.a = (int)(float)(v34 * 255.0); v36 < v23->m_num_indices; merged_indices_it += 2 )
            {
              *(_WORD *)merged_indices_it += current_num_vertices;
              ++v36;
            }
            for ( i = 0; i < v23->m_num_vertices; ++i )
            {
              v12->color_and_wind = color_and_winda.m_value;
              *(_QWORD *)&v12->object_position.x = *(_QWORD *)&v13->position.x;
              v12->object_position.z = v13->position.z;
              z = v13->position.z;
              v38 = v13->position.y;
              v39 = v13->position.x;
              v40 = p_m_transform->j.y;
              *(float *)&v93 = (float)((float)((float)(p_m_transform->j.x * v38) + (float)(p_m_transform->k.x * z))
                                     + (float)(v13->position.x * p_m_transform->i.x))
                             + p_m_transform->c.x;
              *((float *)&v93 + 1) = (float)((float)((float)(p_m_transform->i.y * v39) + (float)(v40 * v38))
                                           + (float)(p_m_transform->k.y * z))
                                   + p_m_transform->c.y;
              v94 = (float)((float)((float)(p_m_transform->i.z * v39) + (float)(p_m_transform->j.z * v38))
                          + (float)(p_m_transform->k.z * z))
                  + p_m_transform->c.z;
              v41 = v94;
              *(_QWORD *)&v13->position.x = v93;
              v13->position.z = v41;
              v13->normal = *vostok::render::transform_packed_normal(p_m_transform, &v13->normal, &v88);
              v13->binormal = *vostok::render::transform_packed_normal(p_m_transform, &v13->binormal, &v89);
              v12 = ++stream_1_data_it;
              v13->tangent = *vostok::render::transform_packed_normal(p_m_transform, &v13->tangent, &v90);
              ++v13;
            }
            current_num_vertices += v23->m_num_vertices;
            current_num_indices += v23->m_num_indices;
          }
          if ( ++it == end )
            break;
          v19 = it;
        }
        m_sort_info = __first;
      }
      buffer = vostok::render::resource_manager::create_buffer(
                 16 * (_DWORD)m_sort_info[3],
                 (bool)v12,
                 (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                 stream_1_data,
                 enum_buffer_type_vertex,
                 0,
                 0);
      v43 = 0;
      if ( buffer )
      {
        ++buffer->m_reference_count;
        v43 = buffer;
      }
      v44 = (survarium::game_vtbl *)*(m_sort_info - 6);
      *(m_sort_info - 6) = v43;
      if ( !v44 )
        goto LABEL_49;
      v45 = v44->enable-- == (void (__thiscall *)(struct survarium::game *, bool))1;
      if ( !v45 )
        goto LABEL_49;
      v46 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game;
      m_movie = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      p_m_movie = &`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_movie;
      v50 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( m_game != (survarium::game *)m_movie )
        break;
LABEL_50:
      v55 = v46;
      v56 = v46;
      declaration = vostok::render::resource_manager::create_declaration(
                      7u,
                      v46,
                      (stlp_std::forward_iterator_tag *)layout);
      __firsta = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      v58 = vostok::render::resource_manager::create_buffer(
              2 * (_DWORD)m_sort_info[6],
              (bool)v56,
              v55,
              *(m_sort_info - 3),
              enum_buffer_type_index,
              0,
              0);
      v59 = merged_vertices;
      v71 = v58;
      v60 = vostok::render::resource_manager::create_buffer(
              32 * (_DWORD)m_sort_info[3],
              (bool)v56,
              v56,
              merged_vertices,
              enum_buffer_type_vertex,
              0,
              0);
      geometry = vostok::render::resource_manager::create_geometry(
                   declaration,
                   v60,
                   (vostok::render::resource_manager *)__firsta,
                   0x20u,
                   v71);
      v62 = 0;
      if ( geometry )
      {
        ++geometry->m_reference_count;
        v62 = geometry;
      }
      v63 = (vostok::render::res_geometry *)*(m_sort_info - 9);
      *(m_sort_info - 9) = v62;
      if ( v63 )
      {
        v45 = v63->m_reference_count-- == 1;
        if ( v45 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v63);
      }
      v64 = vostok::render::g_allocator.m_object;
      if ( stream_1_data )
      {
        v65 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(v65, stream_1_data);
        v64 = vostok::render::g_allocator.m_object;
        v59 = merged_vertices;
      }
      if ( v59 )
      {
        v66 = v59;
        v67 = (void *)HIDWORD(v64->m_reconstruction_info_actuality_tick);
        BYTE2(v64->m_children_resources.m_lock) = 0;
        vostok_mspace_free(v67, v66);
      }
      ++thisa->m_num_avaliable_lods;
      v2 = thisa;
LABEL_60:
      ++m_sort_info;
      ++lod_index;
      __first = m_sort_info;
      if ( lod_index >= 3 )
        return;
    }
    while ( m_game->vostok::engine_user::world::__vftable != v44 )
    {
      m_game = (survarium::game *)((char *)m_game + 4);
      if ( m_game == (survarium::game *)m_movie )
        goto LABEL_50;
    }
    if ( &m_game->survarium::scaleform_game_engine != (survarium::scaleform_game_engine *)m_movie )
      stlp_std::priv::__copy_ptrs<void * *,void * *>(
        (void **)&m_game->survarium::scaleform_game_engine::__vftable,
        (void **)&m_movie->m_object,
        (void **)&m_game->vostok::engine_user::world::__vftable);
    --*p_m_movie;
    v50[2].m_options = (survarium::options_item_base **)((char *)v50[2].m_options - (unsigned int)v44->clear_resources);
    tick = v44->tick;
    v52 = vostok::render::g_allocator.m_object;
    if ( tick )
    {
      (*(void (__stdcall **)(void (__thiscall *)(struct survarium::game *, unsigned int)))(*(_DWORD *)tick + 8))(v44->tick);
      v44->tick = 0;
    }
    v53 = v44;
    v54 = (void *)HIDWORD(v52->m_reconstruction_info_actuality_tick);
    BYTE2(v52->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v54, v53);
LABEL_49:
    v46 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
    goto LABEL_50;
  }
}
