void __thiscall vostok::render::stage_postprocess::accumulate_motion_vectors(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *thisa)
{
  const char *m_conflicted_key_name; // eax
  int v3; // ecx
  vostok::render::render_target *m_object; // ecx
  const char *v5; // edx
  vostok::render::resource_manager *m_rt; // ecx
  bool v7; // zf
  int y; // eax
  vostok::render::renderer_context *m_context; // ecx
  vostok::render::render_target *v10; // eax
  vostok::render::resource_manager *v11; // ecx
  vostok::render::render_target *v12; // eax
  vostok::render::resource_manager *v13; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v14; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v15; // ecx
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *v16; // ecx
  vostok::render::render_surface_instance **M_left; // esi
  vostok::render::render_surface_instance **v18; // eax
  void **v19; // eax
  vostok::render::render_surface_instance **v20; // edi
  vostok::render::render_surface_instance **v21; // ebx
  vostok::render::render_surface_instance **v22; // eax
  void **v23; // eax
  vostok::render::render_surface_instance **v24; // eax
  stlp_std::priv::_Rb_tree_node_base *M_right; // ecx
  vostok::render::grass_render_model *v26; // edx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ebx
  signed int v28; // esi
  unsigned int v29; // eax
  vostok::render::render_surface_instance **p_instance; // ecx
  unsigned int v31; // ecx
  _DWORD *v32; // eax
  unsigned int v33; // ecx
  bool v34; // al
  stlp_std::priv::_Rb_tree_node_base *v35; // edi
  int v36; // eax
  _DWORD *p_M_color; // eax
  vostok::render::render_surface_instance **v38; // ebx
  stlp_std::priv::_Rb_tree_node_base *v39; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::render_surface_instance *v41; // ebx
  unsigned int m_render_surface; // ecx
  int v43; // eax
  vostok::render::material_effects *v44; // esi
  vostok::render::res_effect *v45; // ecx
  _DWORD *v46; // eax
  vostok::math::float4x4 *m_transform; // eax
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > > *p_m_prev_matrix_map; // edx
  vostok::math::float4x4 *v49; // esi
  stlp_std::priv::_Rb_tree_node_base *v50; // eax
  vostok::render::map<vostok::render::render_surface_instance *,vostok::math::float4x4,stlp_std::less<vostok::render::render_surface_instance *> > *v51; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > > *v52; // eax
  vostok::math::float4x4 *v53; // esi
  vostok::render::stage_postprocess *v54; // edi
  vostok::math::float4x4 *v55; // eax
  vostok::render::shader_constant_host *m_prev_world_view_matrix_parameter; // edx
  const char *v57; // esi
  int m_buffer_index; // ecx
  int v59; // ebx
  int m_slot_index; // edx
  vostok::math::float4x4 *v61; // edi
  unsigned int v62; // ecx
  unsigned int v63; // eax
  _BYTE *v64; // eax
  char v65; // dl
  char v66; // bl
  vostok::math::float4x4 *v67; // eax
  vostok::render::shader_constant_host *m_inverse_world_matrix_parameter; // edx
  int v69; // ecx
  float v70; // ebx
  int v71; // edx
  vostok::math::float4x4 *v72; // edi
  unsigned int v73; // ecx
  unsigned int v74; // eax
  _BYTE *v75; // eax
  char v76; // dl
  char v77; // bl
  unsigned int M_node_count; // esi
  vostok::render::backend *v79; // ecx
  const char *v80; // edi
  unsigned int v81; // ebx
  bool v82; // al
  const char *v83; // esi
  void *v84; // eax
  void *v85; // esi
  stlp_std::priv::_Rb_tree_node_base *v86; // eax
  void *v87; // esi
  void **v88; // [esp+0h] [ebp-198h]
  void **v89; // [esp+0h] [ebp-198h]
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *p_m_parent; // [esp+14h] [ebp-184h]
  float v91; // [esp+18h] [ebp-180h]
  unsigned int v92; // [esp+18h] [ebp-180h]
  vostok::render::render_surface_instance **it; // [esp+28h] [ebp-170h]
  vostok::render::render_surface_instance **ita; // [esp+28h] [ebp-170h]
  int v95; // [esp+2Ch] [ebp-16Ch] BYREF
  vostok::render::render_surface_instance *instance; // [esp+30h] [ebp-168h] BYREF
  stlp_std::map<vostok::render::render_surface_instance *,vostok::math::float4x4,stlp_std::less<vostok::render::render_surface_instance *>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > v97; // [esp+34h] [ebp-164h] BYREF
  vostok::render::render_surface_instance **__last; // [esp+4Ch] [ebp-14Ch]
  int v99; // [esp+50h] [ebp-148h]
  float v100; // [esp+54h] [ebp-144h]
  D3D11_VIEWPORT tmp_viewport; // [esp+58h] [ebp-140h] BYREF
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > >,bool> result; // [esp+70h] [ebp-128h] BYREF
  D3D11_VIEWPORT orig_viewport; // [esp+78h] [ebp-120h] BYREF
  vostok::math::float4x4 local_to_world; // [esp+90h] [ebp-108h] BYREF
  stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> __val; // [esp+D4h] [ebp-C4h] BYREF
  vostok::math::float4x4 prev_world_matrix; // [esp+118h] [ebp-80h] BYREF
  vostok::math::float4x4 other; // [esp+158h] [ebp-40h] BYREF

  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v3 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 547);
  *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 167) |= *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 539) != v3;
  *((_DWORD *)m_conflicted_key_name + 539) = v3;
  m_object = thisa->m_context->m_targets->m_family[16].target.m_object;
  v5 = 0;
  if ( m_object )
  {
    v5 = (const char *)thisa->m_context->m_targets->m_family[16].target.m_object;
    ++m_object->m_reference_count;
    m_rt = (vostok::render::resource_manager *)m_object->m_rt;
  }
  else
  {
    m_rt = 0;
  }
  if ( *((vostok::render::resource_manager **)m_conflicted_key_name + 535) != m_rt )
  {
    *((_DWORD *)m_conflicted_key_name + 535) = m_rt;
    *((_BYTE *)m_conflicted_key_name + 163) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 536) )
  {
    *((_DWORD *)m_conflicted_key_name + 536) = 0;
    *((_BYTE *)m_conflicted_key_name + 164) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 537) )
  {
    *((_DWORD *)m_conflicted_key_name + 537) = 0;
    *((_BYTE *)m_conflicted_key_name + 165) = 1;
  }
  if ( *((_DWORD *)m_conflicted_key_name + 538) )
  {
    *((_DWORD *)m_conflicted_key_name + 538) = 0;
    *((_BYTE *)m_conflicted_key_name + 166) = 1;
  }
  if ( v5 )
  {
    v7 = (*(_DWORD *)v5)-- == 1;
    if ( v7 )
    {
      vostok::render::resource_manager::release(
        m_rt,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v5);
      m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
    }
  }
  vostok::render::backend::clear_render_targets(
    (vostok::render::backend *)m_rt,
    (int)m_conflicted_key_name,
    0.0,
    0.0,
    0.0,
    0.0,
    v91);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  instance = (vostok::render::render_surface_instance *)1;
  (*(void (__stdcall **)(int, vostok::render::render_surface_instance **, D3D11_VIEWPORT *))(*(_DWORD *)y + 380))(
    y,
    &instance,
    &orig_viewport);
  m_context = thisa->m_context;
  tmp_viewport.TopLeftX = 0.0;
  tmp_viewport.TopLeftY = 0.0;
  v10 = m_context->m_targets->m_family[16].target.m_object;
  v11 = 0;
  if ( v10 )
  {
    v11 = (vostok::render::resource_manager *)v10;
    ++v10->m_reference_count;
  }
  tmp_viewport.Width = (float)(unsigned int)v11->shader_name_to_mask_config.m_object;
  v7 = v11->sh_created-- == 1;
  if ( v7 )
    vostok::render::resource_manager::release(
      v11,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
      (const char *)v11);
  v12 = thisa->m_context->m_targets->m_family[16].target.m_object;
  v13 = 0;
  if ( v12 )
  {
    v13 = (vostok::render::resource_manager *)thisa->m_context->m_targets->m_family[16].target.m_object;
    ++v12->m_reference_count;
  }
  tmp_viewport.Height = (float)LODWORD(v13->m_num_bytes_of_texture_video_memory);
  v7 = v13->sh_created-- == 1;
  if ( v7 )
    vostok::render::resource_manager::release(
      v13,
      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
      (const char *)v13);
  tmp_viewport.MinDepth = 0.0;
  LODWORD(tmp_viewport.MaxDepth) = clear_value;
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &tmp_viewport);
  memset(&v97._M_t._M_header._M_data._M_parent, 0, 12);
  *(_DWORD *)&v97._M_t._M_key_compare.gap0 = 0;
  __last = 0;
  v99 = 0;
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
    v14,
    (int)&v97._M_t._M_header._M_data._M_parent,
    0x400u);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::reserve(
    v15,
    (int)&v97._M_t._M_key_compare,
    0x100u);
  p_m_parent = (stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *> > *)&thisa->m_context->m_scene_view.m_object[4].m_sub_fat.m_parent;
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
    p_m_parent,
    (int)&v97._M_t._M_header._M_data._M_parent,
    (unsigned int)p_m_parent);
  stlp_std::priv::_Impl_vector<void *,vostok::render::std_allocator<void *>>::operator=(
    v16,
    (int)&v97._M_t._M_key_compare,
    (unsigned int)&thisa->m_context->m_scene_view.m_object[4].m_construct_thread_id);
  M_left = (vostok::render::render_surface_instance **)v97._M_t._M_header._M_data._M_left;
  v18 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_skeletal_filter_predicate>(
          (vostok::render::render_surface_instance **)v97._M_t._M_header._M_data._M_parent,
          (vostok::render::render_surface_instance **)v97._M_t._M_header._M_data._M_left,
          (vostok::render::remove_model_skeletal_filter_predicate)1);
  if ( v18 != M_left )
  {
    v19 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_skeletal_filter_predicate>(
                     v18 + 1,
                     v18,
                     M_left,
                     (vostok::render::remove_model_skeletal_filter_predicate)1);
    if ( v19 != (void **)M_left )
    {
      v88 = stlp_std::priv::__copy_ptrs<void * *,void * *>((void **)M_left, (void **)M_left, v19);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      M_left = (vostok::render::render_surface_instance **)v88;
      v97._M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)v88;
    }
  }
  v20 = __last;
  v21 = *(vostok::render::render_surface_instance ***)&v97._M_t._M_key_compare.gap0;
  v22 = stlp_std::priv::__find_if<vostok::render::render_surface_instance * *,vostok::render::remove_model_skeletal_filter_predicate>(
          *(vostok::render::render_surface_instance ***)&v97._M_t._M_key_compare.gap0,
          __last,
          0);
  if ( v22 != v20 )
  {
    v23 = (void **)stlp_std::remove_copy_if<vostok::render::render_surface_instance * *,vostok::render::render_surface_instance * *,vostok::render::remove_model_skeletal_filter_predicate>(
                     v22 + 1,
                     v22,
                     v20,
                     0);
    if ( v23 != (void **)v20 )
    {
      v89 = stlp_std::priv::__copy_ptrs<void * *,void * *>((void **)v20, (void **)v20, v23);
      stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
      v20 = (vostok::render::render_surface_instance **)v89;
      v21 = *(vostok::render::render_surface_instance ***)&v97._M_t._M_key_compare.gap0;
      __last = (vostok::render::render_surface_instance **)v89;
    }
  }
  v24 = v21;
  it = v21;
  if ( v21 != v20 )
  {
    M_right = v97._M_t._M_header._M_data._M_right;
    v26 = vostok::render::g_allocator.m_object;
    do
    {
      if ( M_left == (vostok::render::render_surface_instance **)M_right )
      {
        M_parent = v97._M_t._M_header._M_data._M_parent;
        v28 = (char *)M_left - (char *)v97._M_t._M_header._M_data._M_parent;
        v29 = v28 >> 2;
        v95 = 1;
        instance = (vostok::render::render_surface_instance *)(v28 >> 2);
        if ( v28 >> 2 == 0x3FFFFFFF )
          stlp_std::__stl_throw_length_error("vector");
        p_instance = &instance;
        if ( v29 <= 1 )
          p_instance = (vostok::render::render_surface_instance **)&v95;
        v31 = (unsigned int)*p_instance + v29;
        v95 = v31;
        if ( v31 > 0x3FFFFFFF || v31 < v29 )
        {
          v31 = 0x3FFFFFFF;
          v95 = 0x3FFFFFFF;
        }
        *(_DWORD *)&v97._M_t._M_header._M_data._M_color = v31;
        instance = (vostok::render::render_surface_instance *)1;
        v32 = &instance;
        if ( v31 )
          v32 = &v97;
        v33 = 4 * *v32;
        v34 = BYTE2(v26->m_children_resources.m_lock) && v33;
        BYTE2(v26->m_children_resources.m_lock) = v34;
        if ( v33 )
          v35 = (stlp_std::priv::_Rb_tree_node_base *)vostok_mspace_malloc(
                                                        (void *)HIDWORD(v26->m_reconstruction_info_actuality_tick),
                                                        v33);
        else
          v35 = 0;
        if ( v28 )
        {
          memmove((unsigned __int8 *)v35, (unsigned __int8 *)M_parent, v28);
          p_M_color = (_DWORD *)(v28 + v36);
        }
        else
        {
          p_M_color = &v35->_M_color;
        }
        v7 = v97._M_t._M_header._M_data._M_parent == 0;
        *p_M_color = *it;
        v26 = vostok::render::g_allocator.m_object;
        v38 = (vostok::render::render_surface_instance **)(p_M_color + 1);
        if ( !v7 )
        {
          v39 = v97._M_t._M_header._M_data._M_parent;
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v39);
          v26 = vostok::render::g_allocator.m_object;
        }
        M_right = (stlp_std::priv::_Rb_tree_node_base *)((char *)v35 + 4 * v95);
        v24 = it;
        v97._M_t._M_header._M_data._M_parent = v35;
        v20 = __last;
        M_left = v38;
      }
      else
      {
        *M_left = *v24;
        v26 = vostok::render::g_allocator.m_object;
        ++M_left;
      }
      ++v24;
      v97._M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)M_left;
      it = v24;
    }
    while ( v24 != v20 );
  }
  ita = (vostok::render::render_surface_instance **)v97._M_t._M_header._M_data._M_parent;
  if ( (vostok::render::render_surface_instance **)v97._M_t._M_header._M_data._M_parent != M_left )
  {
    do
    {
      v41 = *ita;
      m_render_surface = (unsigned int)(*ita)->m_render_surface;
      v43 = *(_DWORD *)(m_render_surface + 148);
      instance = *ita;
      v97._M_t._M_node_count = m_render_surface;
      if ( !v43 || s_use_one_material_value )
        v44 = s_nomaterial_material_effects[*(_DWORD *)(m_render_surface + 4)];
      else
        v44 = (vostok::render::material_effects *)(v43 + 264);
      vostok::render::renderer_context::set_w(thisa->m_context, v41->m_transform);
      v46 = &v44->m_effects[0].m_object->__vftable;
      if ( (unsigned int)((v46[71] - v46[70]) >> 2) > 6 )
      {
        v46[69] = 6;
        vostok::render::res_effect::apply_pass(v45, v92);
      }
      m_transform = v41->m_transform;
      qmemcpy((void *)&local_to_world, m_transform, sizeof(local_to_world));
      p_m_prev_matrix_map = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > > *)&thisa->m_prev_matrix_map;
      v49 = m_transform;
      v50 = thisa->m_prev_matrix_map._M_t._M_header._M_data._M_parent;
      qmemcpy((void *)&prev_world_matrix, v49, sizeof(prev_world_matrix));
      v51 = &thisa->m_prev_matrix_map;
      if ( v50 )
      {
        do
        {
          if ( *(_DWORD *)&v50[1]._M_color < (unsigned int)v41 )
          {
            v50 = v50->_M_right;
          }
          else
          {
            v51 = (vostok::render::map<vostok::render::render_surface_instance *,vostok::math::float4x4,stlp_std::less<vostok::render::render_surface_instance *> > *)v50;
            v50 = v50->_M_left;
          }
        }
        while ( v50 );
        p_m_prev_matrix_map = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> > > *)&thisa->m_prev_matrix_map;
        if ( v51 == &thisa->m_prev_matrix_map )
          goto LABEL_73;
        if ( (unsigned int)v41 < v51->_M_t._M_node_count )
          v51 = &thisa->m_prev_matrix_map;
      }
      if ( v51 != (vostok::render::map<vostok::render::render_surface_instance *,vostok::math::float4x4,stlp_std::less<vostok::render::render_surface_instance *> > *)p_m_prev_matrix_map )
      {
        qmemcpy((void *)&prev_world_matrix, &v51->_M_t._M_key_compare, sizeof(prev_world_matrix));
        *(_DWORD *)&v97._M_t._M_header._M_data._M_color = v41;
        v52 = stlp_std::map<vostok::render::render_surface_instance *,vostok::math::float4x4,stlp_std::less<vostok::render::render_surface_instance *>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4>>>::operator[]<vostok::render::render_surface_instance *>(
                &v97,
                p_m_prev_matrix_map);
        qmemcpy(v52, &local_to_world, 0x40u);
        goto LABEL_74;
      }
LABEL_73:
      v53 = v41->m_transform;
      __val.first = v41;
      qmemcpy((void *)&__val.second, v53, sizeof(__val.second));
      stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>>,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4>>>::insert_unique(
        (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)&result,
        (stlp_std::priv::_Rb_tree<vostok::render::render_surface_instance *,stlp_std::less<vostok::render::render_surface_instance *>,stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::render::render_surface_instance * const,vostok::math::float4x4> >,vostok::render::std_allocator<stlp_std::pair<vostok::render::render_surface_instance *,vostok::math::float4x4> > > *)p_m_prev_matrix_map,
        &result,
        &__val);
LABEL_74:
      vostok::math::float4x4::try_invert(&local_to_world, &local_to_world);
      v54 = thisa;
      vostok::math::mul4x3(&other, &prev_world_matrix, &thisa->m_prev_view_matrix);
      v55 = vostok::math::transpose((vostok::math::float4x4 *)&__val, &other);
      m_prev_world_view_matrix_parameter = thisa->m_prev_world_view_matrix_parameter;
      v57 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      if ( m_prev_world_view_matrix_parameter->m_update_markers[1] == *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                      + 573) )
      {
        m_buffer_index = m_prev_world_view_matrix_parameter->m_shader_slots[1].m_buffer_index;
        if ( m_buffer_index != 0xFFFF )
        {
          v59 = *(_DWORD *)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                        + 371)
                                      + 16)
                          + 4 * m_buffer_index);
          LOWORD(v62) = m_prev_world_view_matrix_parameter->m_shader_slots[1].m_class_id;
          m_slot_index = m_prev_world_view_matrix_parameter->m_shader_slots[1].m_slot_index;
          v61 = v55;
          v62 = (unsigned __int8)v62;
          v63 = *(_DWORD *)(v59 + 92) - m_slot_index;
          v95 = v59;
          if ( (unsigned __int8)v62 > v63 )
            v62 = v63;
          v64 = (_BYTE *)(m_slot_index + *(_DWORD *)(v59 + 88));
          v65 = 0;
          *(_DWORD *)&v97._M_t._M_header._M_data._M_color = &v64[v62];
          if ( v64 != &v64[v62] )
          {
            do
            {
              v66 = LOBYTE(v61->i.x) ^ *v64;
              *v64++ = LOBYTE(v61->i.x);
              v65 |= v66;
              v61 = (vostok::math::float4x4 *)((char *)v61 + 1);
            }
            while ( v64 != *(_BYTE **)&v97._M_t._M_header._M_data._M_color );
            v59 = v95;
          }
          v54 = thisa;
          *(_BYTE *)(v59 + 100) |= v65 != 0;
          v41 = instance;
        }
      }
      ++*((_DWORD *)v57 + 23);
      v67 = vostok::math::transpose(&other, &local_to_world);
      m_inverse_world_matrix_parameter = v54->m_inverse_world_matrix_parameter;
      if ( m_inverse_world_matrix_parameter->m_update_markers[1] == *((_DWORD *)v57 + 573) )
      {
        v69 = m_inverse_world_matrix_parameter->m_shader_slots[1].m_buffer_index;
        if ( v69 != 0xFFFF )
        {
          v70 = *(float *)(*(_DWORD *)(*((_DWORD *)v57 + 371) + 16) + 4 * v69);
          LOWORD(v73) = m_inverse_world_matrix_parameter->m_shader_slots[1].m_class_id;
          v71 = m_inverse_world_matrix_parameter->m_shader_slots[1].m_slot_index;
          v72 = v67;
          v73 = (unsigned __int8)v73;
          v74 = *(_DWORD *)(LODWORD(v70) + 92) - v71;
          v100 = v70;
          v95 = v71;
          if ( (unsigned __int8)v73 > v74 )
            v73 = v74;
          v75 = (_BYTE *)(v95 + *(_DWORD *)(LODWORD(v70) + 88));
          v76 = 0;
          *(_DWORD *)&v97._M_t._M_header._M_data._M_color = &v75[v73];
          if ( v75 != &v75[v73] )
          {
            do
            {
              v77 = LOBYTE(v72->i.x) ^ *v75;
              *v75++ = LOBYTE(v72->i.x);
              v76 |= v77;
              v72 = (vostok::math::float4x4 *)((char *)v72 + 1);
            }
            while ( v75 != *(_BYTE **)&v97._M_t._M_header._M_data._M_color );
            v70 = v100;
          }
          *(_BYTE *)(LODWORD(v70) + 100) |= v76 != 0;
          v41 = instance;
        }
      }
      ++*((_DWORD *)v57 + 23);
      v41->m_parent->set_constants(v41->m_parent);
      M_node_count = v97._M_t._M_node_count;
      vostok::render::res_geometry::apply(*(vostok::render::res_geometry **)(v97._M_t._M_node_count + 48));
      v80 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      v81 = 3 * *(_DWORD *)(M_node_count + 68);
      v82 = *((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 529) != 4;
      v83 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
      *((_BYTE *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name + 162) = v82;
      if ( v82 )
        *((_DWORD *)v80 + 529) = 4;
      vostok::render::backend::flush(v79, (int)v80);
      if ( v83[104] )
      {
        ++*((_DWORD *)v83 + 25);
        v81 += 3 * s_max_triagles_per_dip_value < v81 ? 3 * s_max_triagles_per_dip_value - v81 : 0;
      }
      if ( !v83[37] )
        (*(void (__stdcall **)(int, unsigned int, _DWORD, _DWORD))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                                 + 48))(
          `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
          v81,
          0,
          0);
      *((_DWORD *)v83 + 21) += v81 / 3;
      ++ita;
    }
    while ( ita != (vostok::render::render_surface_instance **)v97._M_t._M_header._M_data._M_left );
  }
  (*(void (__stdcall **)(int, int, D3D11_VIEWPORT *))(*(_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y
                                                    + 176))(
    `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y,
    1,
    &orig_viewport);
  v84 = *(void **)&v97._M_t._M_key_compare.gap0;
  if ( *(_DWORD *)&v97._M_t._M_key_compare.gap0 )
  {
    v85 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v85, v84);
  }
  v86 = v97._M_t._M_header._M_data._M_parent;
  if ( v97._M_t._M_header._M_data._M_parent )
  {
    v87 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v87, v86);
  }
}
