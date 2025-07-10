// local variable allocation has failed, the output may be wrong!
void __userpurge vostok::render::scene::gather_streamable_textures(
        vostok::render::scene *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::render::scene *model,
        vostok::resources::unmanaged_resource *update_only,
        bool update_onlya)
{
  void *v7; // eax
  vostok::render::res_texture *texture; // esi
  vostok::render::res_texture_vtbl *v9; // eax
  vostok::math::aabb *m_reference_count; // ecx
  void (__thiscall *v11)(vostok::render::res_texture *); // ecx
  vostok::render::material_effects *v12; // eax
  void **M_start; // edi
  vostok::render::res_texture_vtbl *v14; // eax
  vostok::render::res_texture *v15; // esi
  float v16; // edi
  vostok::render::streamable_texture_info *if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z; // eax
  stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *v18; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *p_M_impl; // ebx
  float v20; // eax
  float z; // ebx
  bool v22; // zf
  survarium::options_tab *v23; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v24; // eax
  stlp_std::priv::_Rb_tree_node_base *v25; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::grass_render_model *m_object; // edi
  _BYTE *v28; // esi
  void *v29; // eax
  void *v30; // esi
  stlp_std::priv::_Impl_vector<survarium::relocate_item_descr,survarium::std_allocator<survarium::relocate_item_descr> > *v31; // ecx
  float v32; // ecx
  float v33; // ebx
  survarium::options_tab *v34; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v35; // eax
  stlp_std::priv::_Rb_tree_node_base *v36; // eax
  void *v37; // esi
  vostok::render::grass_render_model *v38; // edi
  _BYTE *v39; // esi
  void *v40; // eax
  void *v41; // esi
  char *m_begin; // eax
  void *v43; // esi
  vostok::render::streaming_texture_instance *M_finish; // edi
  vostok::render::streaming_texture_instance *v45; // eax
  void *v46; // esi
  void *v47; // esi
  const vostok::math::float4x4 *v48; // [esp+28h] [ebp-224h]
  vostok::render::texture_named_instance *tex_it; // [esp+2Ch] [ebp-220h]
  bool v50; // [esp+30h] [ebp-21Ch]
  vostok::render::vector<vostok::render::texture_named_instance> effect_used_textures; // [esp+38h] [ebp-214h] BYREF
  vostok::render::vector<vostok::render::render_surface_instance *> surfaces; // [esp+44h] [ebp-208h] BYREF
  _BYTE texture_instance[28]; // [esp+50h] [ebp-1FCh] OVERLAPPED BYREF
  __int64 v54; // [esp+6Ch] [ebp-1E0h]
  vostok::render::texture_named_instance *v55; // [esp+74h] [ebp-1D8h]
  __int64 v56; // [esp+78h] [ebp-1D4h]
  __int64 v57; // [esp+80h] [ebp-1CCh]
  _BYTE bbox[36]; // [esp+88h] [ebp-1C4h] OVERLAPPED BYREF
  vostok::render::streamable_texture_info info; // [esp+ACh] [ebp-1A0h] BYREF
  vostok::math::float4x4 temp_vp_matrix; // [esp+1CCh] [ebp-80h] BYREF
  vostok::math::float4x4 v61; // [esp+20Ch] [ebp-40h] BYREF

  memset(&surfaces, 0, sizeof(surfaces));
  memset(&bbox[24], 0, 12);
  qmemcpy((void *)&temp_vp_matrix, vostok::math::float4x4::identity(&v61), sizeof(temp_vp_matrix));
  ((void (__thiscall *)(vostok::resources::unmanaged_resource *, vostok::math::float4x4 *, _BYTE *, vostok::render::vector<vostok::render::render_surface_instance *> *, _DWORD, int, int, int, int, int))update_only->__vftable[2].link_child_resource)(
    update_only,
    &temp_vp_matrix,
    &bbox[24],
    &surfaces,
    0,
    170,
    3,
    a3,
    a4,
    a2);
  __SET_PAIR__((unsigned int)v55, (unsigned int)v7, *(_QWORD *)texture_instance);
  effect_used_textures._M_impl._M_end_of_storage._M_data = *(vostok::render::texture_named_instance **)texture_instance;
  if ( *(_DWORD *)texture_instance != *(_DWORD *)&texture_instance[4] )
  {
    do
    {
      texture = effect_used_textures._M_impl._M_end_of_storage._M_data->texture;
      v9 = effect_used_textures._M_impl._M_end_of_storage._M_data->texture->__vftable;
      m_reference_count = (vostok::math::aabb *)effect_used_textures._M_impl._M_end_of_storage._M_data->texture->m_reference_count;
      *(_QWORD *)&bbox[12] = *(_QWORD *)&v9[2].~vostok::render::res_texture;
      *(vostok::math::float4 *)&bbox[20] = *(vostok::math::float4 *)&v9[4].~vostok::render::res_texture;
      vostok::math::aabb::modify(m_reference_count, v48);
      v11 = texture->__vftable[37].~vostok::render::res_texture;
      if ( !v11 || s_use_one_material_value )
        v12 = s_nomaterial_material_effects[(int)texture->__vftable[1].~vostok::render::res_texture];
      else
        v12 = (vostok::render::material_effects *)((char *)v11 + 264);
      memset(&surfaces, 0, sizeof(surfaces));
      vostok::render::material_effects::get_used_textures(
        (vostok::render::material_effects *)&surfaces,
        (int)v12,
        (vostok::render::vector<vostok::render::texture_named_instance> *)&surfaces);
      M_start = surfaces._M_impl._M_start;
      *(float *)&bbox[4] = (float)(*(float *)&bbox[28] + *(float *)&bbox[16]) * 0.5;
      *(float *)&bbox[8] = (float)(*(float *)&bbox[32] + *(float *)&bbox[20]) * 0.5;
      *(float *)bbox = (float)(*(float *)&bbox[24] + *(float *)&bbox[12]) * 0.5;
      v56 = *(_QWORD *)bbox;
      effect_used_textures._M_impl._M_start = (vostok::render::texture_named_instance *)surfaces._M_impl._M_start;
      *(float *)&v57 = *(float *)&bbox[8];
      *((float *)&v57 + 1) = sqrtf(
                               (float)((float)((float)(*(float *)&bbox[8] - *(float *)&bbox[20])
                                             * (float)(*(float *)&bbox[8] - *(float *)&bbox[20]))
                                     + (float)((float)(*(float *)&bbox[4] - *(float *)&bbox[16])
                                             * (float)(*(float *)&bbox[4] - *(float *)&bbox[16])))
                             + (float)((float)(*(float *)bbox - *(float *)&bbox[12])
                                     * (float)(*(float *)bbox - *(float *)&bbox[12])));
      v14 = texture->__vftable;
      *(_QWORD *)&texture_instance[12] = v56;
      *(_QWORD *)&texture_instance[20] = v57;
      LODWORD(v54) = v14[38];
      HIDWORD(v54) = texture;
      if ( M_start != surfaces._M_impl._M_finish )
      {
        do
        {
          v15 = effect_used_textures._M_impl._M_start->texture;
          v16 = *(float *)&model->streaming_textures._M_impl._M_finish;
          if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z(model->streaming_textures._M_impl._M_start, (vostok::render::streamable_texture_info *)LODWORD(v16), (vostok::render::scene::gather_streamable_textures::__l2::find_texture_predicate)effect_used_textures._M_impl._M_start->texture);
          p_M_impl = &if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z->instances._M_impl;
          if ( if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z == (vostok::render::streamable_texture_info *)LODWORD(v16) )
          {
            v20 = 0.0;
            *(_DWORD *)info.path.m_buffer = &info.path.m_buffer[12];
            memset(&info.path, 0, 12);
            *(_DWORD *)&info.path.m_buffer[4] = &info.path.m_buffer[12];
            *(_DWORD *)&info.path.m_buffer[8] = &temp_vp_matrix.i.z;
            info.path.m_buffer[12] = 0;
            temp_vp_matrix.i.z = 0.0;
            if ( v15 )
            {
              ++v15->m_reference_count;
              v20 = *(float *)&v15;
            }
            z = temp_vp_matrix.i.z;
            temp_vp_matrix.i.z = v20;
            if ( z != 0.0 )
            {
              v22 = (*(_DWORD *)(LODWORD(z) + 4))-- == 1;
              if ( v22 )
              {
                if ( *(_BYTE *)(LODWORD(z) + 439) )
                {
                  v23 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
                  effect_used_textures._M_impl._M_finish = *(vostok::render::texture_named_instance **)(LODWORD(z) + 144);
                  v24 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>((stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&effect_used_textures._M_impl._M_finish, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&effect_used_textures._M_impl._M_finish);
                  if ( v24 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v23 )
                  {
                    v25 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                            &v24->_M_header._M_data,
                            (stlp_std::priv::_Rb_tree_node_base **)&v23->m_options_count,
                            (stlp_std::priv::_Rb_tree_node_base **)&v23->m_type,
                            (stlp_std::priv::_Rb_tree_node_base **)&v23->m_game);
                    if ( v25 )
                    {
                      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v25);
                    }
                    --v23->m_movie;
                    m_object = vostok::render::g_allocator.m_object;
                    v28 = __RTCastToVoid((void **)LODWORD(z));
                    (**(void (__thiscall ***)(float, _DWORD))LODWORD(z))(COERCE_FLOAT(LODWORD(z)), 0);
                    if ( v28 )
                    {
                      v29 = v28;
                      v30 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
                      BYTE2(m_object->m_children_resources.m_lock) = 0;
                      vostok_mspace_free(v30, v29);
                    }
                  }
                }
              }
            }
            vostok::fixed_string<260>::operator=(
              (vostok::fixed_string<260> *)info.path.m_buffer,
              &effect_used_textures._M_impl._M_start->path);
            if ( info.path.m_end == info.path.m_max_end )
            {
              stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::_M_insert_overflow(
                (stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance> > *)&info.path,
                (const vostok::render::streaming_texture_instance *)&texture_instance[12],
                v31,
                (vostok::render::streaming_texture_instance *)info.path.m_end,
                (const stlp_std::__true_type *)v48,
                (unsigned int)tex_it,
                v50);
            }
            else
            {
              *(_QWORD *)info.path.m_end = *(_QWORD *)&texture_instance[12];
              *((_QWORD *)info.path.m_end + 1) = *(_QWORD *)&texture_instance[20];
              *((_QWORD *)info.path.m_end + 2) = v54;
              info.path.m_end += 24;
            }
            v32 = *(float *)&model->streaming_textures._M_impl._M_finish;
            if ( (vostok::render::streamable_texture_info *)LODWORD(v32) == model->streaming_textures._M_impl._M_end_of_storage._M_data )
            {
              stlp_std::priv::_Impl_vector<vostok::render::streamable_texture_info,vostok::render::std_allocator<vostok::render::streamable_texture_info>>::_M_insert_overflow_aux(
                (stlp_std::priv::_Impl_vector<vostok::render::streamable_texture_info,vostok::render::std_allocator<vostok::render::streamable_texture_info> > *)LODWORD(v32),
                (stlp_std::reverse_iterator<vostok::render::streamable_texture_info *> *)&model->streaming_textures,
                (vostok::render::streamable_texture_info *)LODWORD(v32),
                (const vostok::render::streamable_texture_info *)&info.path,
                (const stlp_std::__false_type *)v48,
                (unsigned int)tex_it,
                v50);
            }
            else
            {
              if ( v32 != 0.0 )
                vostok::render::streamable_texture_info::streamable_texture_info(
                  (vostok::render::streamable_texture_info *)LODWORD(v32),
                  (const vostok::render::streamable_texture_info *)&info.path);
              ++model->streaming_textures._M_impl._M_finish;
            }
            if ( LODWORD(temp_vp_matrix.i.z) )
            {
              v22 = (*(_DWORD *)(LODWORD(temp_vp_matrix.i.z) + 4))-- == 1;
              if ( v22 )
              {
                v33 = temp_vp_matrix.i.z;
                if ( *(_BYTE *)(LODWORD(temp_vp_matrix.i.z) + 439) )
                {
                  v34 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
                  effect_used_textures._M_impl._M_finish = *(vostok::render::texture_named_instance **)(LODWORD(temp_vp_matrix.i.z) + 144);
                  v35 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>((stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)effect_used_textures._M_impl._M_finish, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&effect_used_textures._M_impl._M_finish);
                  if ( v35 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v34 )
                  {
                    v36 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                            &v35->_M_header._M_data,
                            (stlp_std::priv::_Rb_tree_node_base **)&v34->m_options_count,
                            (stlp_std::priv::_Rb_tree_node_base **)&v34->m_type,
                            (stlp_std::priv::_Rb_tree_node_base **)&v34->m_game);
                    if ( v36 )
                    {
                      v37 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                      vostok_mspace_free(v37, v36);
                    }
                    --v34->m_movie;
                    v38 = vostok::render::g_allocator.m_object;
                    v39 = __RTCastToVoid((void **)LODWORD(v33));
                    (**(void (__thiscall ***)(float, _DWORD))LODWORD(v33))(COERCE_FLOAT(LODWORD(v33)), 0);
                    if ( v39 )
                    {
                      v40 = v39;
                      v41 = (void *)HIDWORD(v38->m_reconstruction_info_actuality_tick);
                      BYTE2(v38->m_children_resources.m_lock) = 0;
                      vostok_mspace_free(v41, v40);
                    }
                  }
                }
              }
            }
            m_begin = info.path.m_begin;
            if ( info.path.m_begin )
            {
              v43 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v43, m_begin);
            }
          }
          else
          {
            M_finish = if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z->instances._M_impl._M_finish;
            if ( update_onlya )
              v45 = stlp_std::priv::__find<vostok::render::streaming_texture_instance *,vostok::render::streaming_texture_instance>(
                      if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z->instances._M_impl._M_start,
                      M_finish,
                      (const vostok::render::streaming_texture_instance *)&texture_instance[12]);
            else
              v45 = if_PAUstreamable_texture_info_render_vostok__Ufind_texture_predicate__1__gather_streamable_textures_scene_23_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_3__N_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Ufind_texture_predicate__1__gather_streamable_textures_scene_34_QAEXV__resource_ptr_Vrender_model_instance_impl_render_vostok__Vunmanaged_intrusive_base_resources_3__resources_4__N_Z_ABUrandom_access_iterator_tag_1__Z->instances._M_impl._M_finish;
            if ( v45 == M_finish )
            {
              if ( M_finish == p_M_impl->_M_end_of_storage._M_data )
              {
                stlp_std::priv::_Impl_vector<vostok::render::streaming_texture_instance,vostok::render::std_allocator<vostok::render::streaming_texture_instance>>::_M_insert_overflow(
                  p_M_impl,
                  (const vostok::render::streaming_texture_instance *)&texture_instance[12],
                  v18,
                  M_finish,
                  (const stlp_std::__true_type *)v48,
                  (unsigned int)tex_it,
                  v50);
              }
              else
              {
                *(_QWORD *)&M_finish->object_sphere.vector.x = *(_QWORD *)&texture_instance[12];
                *(_QWORD *)&M_finish->object_sphere.center.elements[2] = *(_QWORD *)&texture_instance[20];
                *(_QWORD *)&M_finish->texel_factor = v54;
                ++p_M_impl->_M_finish;
              }
            }
            else
            {
              *(_QWORD *)&v45->object_sphere.vector.x = v56;
              *(_QWORD *)&v45->object_sphere.center.elements[2] = v57;
            }
          }
          ++effect_used_textures._M_impl._M_start;
        }
        while ( effect_used_textures._M_impl._M_start != (vostok::render::texture_named_instance *)surfaces._M_impl._M_finish );
        M_start = surfaces._M_impl._M_start;
      }
      if ( M_start )
      {
        v46 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(v46, M_start);
      }
      effect_used_textures._M_impl._M_end_of_storage._M_data = (vostok::render::texture_named_instance *)((char *)effect_used_textures._M_impl._M_end_of_storage._M_data + 4);
    }
    while ( effect_used_textures._M_impl._M_end_of_storage._M_data != v55 );
    v7 = *(void **)texture_instance;
  }
  if ( v7 )
  {
    v47 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v47, v7);
  }
  if ( update_only )
  {
    if ( !_InterlockedExchangeAdd(&update_only->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &update_only->vostok::resources::unmanaged_intrusive_base,
        update_only);
  }
}
