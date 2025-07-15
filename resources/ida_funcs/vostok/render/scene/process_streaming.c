void __thiscall vostok::render::scene::process_streaming(
        vostok::render::scene *this,
        vostok::render::scene *projection_matrix,
        vostok::math::float3 viewer_position,
        const vostok::math::float4x4 *screen_size_x,
        unsigned int screen_size_y)
{
  vostok::render::scene *v5; // ebx
  float v6; // ecx
  float v7; // edi
  vostok::render::streamable_texture_info *if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z; // eax
  vostok::render::streamable_texture_info *v9; // eax
  vostok::render::streamable_texture_info *v10; // esi
  float v11; // esi
  vostok::render::requested_streamable_texture *if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__2__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z; // eax
  vostok::render::requested_streamable_texture *v13; // eax
  vostok::render::requested_streamable_texture *v14; // esi
  float v15; // edi
  float v16; // eax
  int v17; // eax
  const vostok::render::res_texture *v18; // esi
  vostok::render::requested_streamable_texture *M_finish; // edx
  vostok::render::requested_streamable_texture *M_start; // eax
  survarium::options_tab *v21; // ebx
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v22; // eax
  const vostok::math::sphere *v23; // esi
  const vostok::math::sphere *v24; // edi
  unsigned int v25; // ebx
  unsigned int v26; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v27; // ecx
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v28; // eax
  int v29; // ebx
  survarium::options_tab *v30; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v31; // eax
  stlp_std::priv::_Rb_tree_node_base *v32; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_Impl_vector<vostok::render::requested_streamable_texture,vostok::render::std_allocator<vostok::render::requested_streamable_texture> > *v34; // ecx
  float v35; // esi
  char *m_buffer; // eax
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  boost::_bi::value<float> v38; // ecx
  boost::function<void __cdecl(vostok::resources::queries_result &)> *v39; // ecx
  void (__cdecl *v40)(unsigned __int64 *, unsigned __int64 *, int); // eax
  int v41; // eax
  const vostok::render::res_texture *v42; // ebx
  survarium::options_tab *v43; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v44; // eax
  stlp_std::priv::_Rb_tree_node_base *v45; // eax
  void *v46; // esi
  vostok::render::streaming_ready_texture *v47; // edi
  vostok::render::streaming_ready_texture *v48; // eax
  const vostok::render::res_texture *v49; // esi
  unsigned __int64 v50; // rax
  int v51; // ecx
  vostok::render::streaming_ready_texture *v52; // edi
  unsigned __int64 v53; // rax
  vostok::render::resource_manager *p_a3; // ecx
  vostok::resources::managed_resource *m_object; // eax
  double elapsed_sec; // st7
  vostok::render::res_texture *v57; // eax
  vostok::render::requested_streamable_texture *v58; // edx
  vostok::render::requested_streamable_texture *v59; // eax
  vostok::render::streamable_texture_info *requested_texture; // eax
  vostok::render::res_texture *v61; // ecx
  int v63; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v64; // [esp-1Ch] [ebp-3CCh]
  unsigned __int64 v65; // [esp-18h] [ebp-3C8h]
  boost::_bi::bind_t<void,boost::_mfi::mf4<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>,boost::_bi::list5<boost::_bi::value<vostok::render::scene *>,boost::arg<1>,boost::_bi::value<vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> >,boost::_bi::value<unsigned int>,boost::_bi::value<float> > > v66; // [esp-10h] [ebp-3C0h] BYREF
  vostok::render::resource_manager *v67; // [esp+8h] [ebp-3A8h]
  bool v68; // [esp+Ch] [ebp-3A4h]
  float creation_time; // [esp+18h] [ebp-398h]
  unsigned int index; // [esp+1Ch] [ebp-394h]
  vostok::render::streaming_ready_texture *first; // [esp+20h] [ebp-390h] BYREF
  vostok::render::streamable_texture_info *info_end; // [esp+24h] [ebp-38Ch]
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > v73; // [esp+28h] [ebp-388h] BYREF
  vostok::timing::timer creation_timer; // [esp+40h] [ebp-370h] BYREF
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > v75; // [esp+64h] [ebp-34Ch] BYREF
  _DWORD v76[2]; // [esp+178h] [ebp-238h] BYREF
  vostok::fs_new::virtual_path_string path_add; // [esp+180h] [ebp-230h] BYREF
  vostok::fs_new::virtual_path_string path; // [esp+298h] [ebp-118h] BYREF

  v5 = projection_matrix;
  v6 = *(float *)&projection_matrix->streaming_textures._M_impl._M_start;
  v7 = *(float *)&projection_matrix->streaming_textures._M_impl._M_finish;
  LOBYTE(creation_time) = 0;
  v66.l_.a5_.t_ = creation_time;
  if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z((vostok::render::streamable_texture_info *)LODWORD(v6), (vostok::render::streamable_texture_info *)LODWORD(v7));
  if ( if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z != (vostok::render::streamable_texture_info *)LODWORD(v7) )
  {
    v66.l_.a5_.t_ = creation_time;
    v9 = ___remove_copy_if_PAUstreamable_texture_info_render_vostok__PAU123_Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU123_00Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__Z(
           if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z
         + 1,
           &if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z[1].instances._M_impl,
           (vostok::render::streamable_texture_info *)LODWORD(v7),
           if_PAUstreamable_texture_info_render_vostok__Uremove_texture_predicate__1__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUstreamable_texture_info_render_vostok__PAU234_0Uremove_texture_predicate__1__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z);
    if ( v9 != (vostok::render::streamable_texture_info *)LODWORD(v7) )
    {
      v10 = stlp_std::priv::__copy<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info *,int>(
              projection_matrix->streaming_textures._M_impl._M_finish,
              (vostok::render::streamable_texture_info *)LODWORD(v7),
              v9);
      stlp_std::__destroy_range_aux<vostok::render::streamable_texture_info *,vostok::render::streamable_texture_info>(
        v10,
        projection_matrix->streaming_textures._M_impl._M_finish);
      projection_matrix->streaming_textures._M_impl._M_finish = v10;
    }
  }
  v11 = *(float *)&projection_matrix->requested_streamable_textures._M_impl._M_finish;
  LOBYTE(creation_time) = 0;
  v66.l_.a5_.t_ = creation_time;
  if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__2__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z = _____find_if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__2__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z((vostok::render::requested_streamable_texture *)LODWORD(v11));
  if ( if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__2__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z != (vostok::render::requested_streamable_texture *)LODWORD(v11) )
  {
    v66.l_.a5_.t_ = creation_time;
    v13 = ___remove_copy_if_PAUrequested_streamable_texture_render_vostok__PAU123_Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU123_00Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__Z(
            if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__2__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z
          + 1,
            (vostok::render::requested_streamable_texture *)LODWORD(v11),
            if_PAUrequested_streamable_texture_render_vostok__Uremove_requested_texture_predicate__2__process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__priv_stlp_std__YAPAUrequested_streamable_texture_render_vostok__PAU234_0Uremove_requested_texture_predicate__2__process_streaming_scene_34_QAEXABVfloat4x4_math_4_Vfloat3_94_II_Z_ABUrandom_access_iterator_tag_1__Z);
    if ( v13 != (vostok::render::requested_streamable_texture *)LODWORD(v11) )
    {
      v14 = stlp_std::priv::__copy<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture *,int>(
              projection_matrix->requested_streamable_textures._M_impl._M_finish,
              (vostok::render::requested_streamable_texture *)LODWORD(v11),
              v13);
      stlp_std::__destroy_range_aux<vostok::render::requested_streamable_texture *,vostok::render::requested_streamable_texture>(
        v14,
        projection_matrix->requested_streamable_textures._M_impl._M_finish);
      projection_matrix->requested_streamable_textures._M_impl._M_finish = v14;
    }
  }
  v15 = *(float *)&projection_matrix->streaming_textures._M_impl._M_start;
  v16 = *(float *)&projection_matrix->streaming_textures._M_impl._M_finish;
  index = LODWORD(v15);
  info_end = (vostok::render::streamable_texture_info *)LODWORD(v16);
  if ( LODWORD(v15) != LODWORD(v16) )
  {
    while ( 1 )
    {
      v17 = *(_DWORD *)(LODWORD(v15) + 284);
      v18 = 0;
      if ( v17 )
      {
        v18 = *(const vostok::render::res_texture **)(LODWORD(v15) + 284);
        ++*(_DWORD *)(v17 + 4);
      }
      M_finish = v5->requested_streamable_textures._M_impl._M_finish;
      M_start = v5->requested_streamable_textures._M_impl._M_start;
      v66.l_.a5_.t_ = 0.0;
      if ( v18 )
      {
        LODWORD(v66.l_.a5_.t_) = v18;
        ++v18->m_reference_count;
      }
      *(_DWORD *)&v73._M_header._M_data._M_color = stlp_std::priv::__find_if<vostok::render::requested_streamable_texture *,vostok::render::find_requested_texture_predicate>(
                                                     M_start,
                                                     M_finish,
                                                     LODWORD(v66.l_.a5_.t_));
      if ( v18 )
      {
        if ( !--v18->m_reference_count && v18->m_is_registered )
        {
          v21 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          *(_DWORD *)&v75._M_header._M_data._M_color = v18->m_name.m_string.m_begin;
          v22 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                  &v75,
                  (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                  (const char **)&v75);
          if ( v22 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v21 )
          {
            stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
              (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v66.l_.a5_,
              (int)v21,
              (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v22);
            vostok::render::resource_manager::release_impl(v18, v67);
            v15 = *(float *)&index;
          }
        }
      }
      v23 = *(const vostok::math::sphere **)LODWORD(v15);
      v24 = *(const vostok::math::sphere **)(LODWORD(v15) + 4);
      v25 = 0;
      first = *(vostok::render::streaming_ready_texture **)(*(_DWORD *)(index + 284) + 12);
      creation_time = 0.0;
      if ( *(vostok::render::requested_streamable_texture **)&v73._M_header._M_data._M_color == projection_matrix->requested_streamable_textures._M_impl._M_finish )
      {
        for ( *(_DWORD *)&v73._M_key_compare.stlp_std::binary_function<char *,char *,bool> = 0;
              v23 != v24;
              v25 = LODWORD(creation_time) )
        {
          v26 = vostok::render::calculate_needed_texture_mip_levels(
                  screen_size_x,
                  &viewer_position,
                  v23,
                  screen_size_y,
                  COERCE_CONST_UNSIGNED_INT(v23[1].vector.x),
                  COERCE_CONST_FLOAT((stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&v73._M_key_compare),
                  (float *)&v67->sh_created);
          v23 = (const vostok::math::sphere *)((char *)v23 + 24);
          creation_time = COERCE_FLOAT(vostok::math::max(v25, v26));
        }
        if ( (vostok::render::streaming_ready_texture *)v25 != first )
        {
          v75._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)&v75._M_node_count;
          v27 = *(stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > **)(index + 284);
          v75._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)&v75._M_node_count;
          v28 = 0;
          v75._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)v76;
          LOBYTE(v75._M_node_count) = 0;
          v76[0] = 0;
          v76[1] = v25;
          if ( v27 )
          {
            v28 = v27;
            ++v27->_M_header._M_data._M_parent;
          }
          v29 = v76[0];
          v76[0] = v28;
          if ( v29 )
          {
            if ( !--*(_DWORD *)(v29 + 4) )
            {
              if ( *(_BYTE *)(v29 + 439) )
              {
                v30 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
                first = *(vostok::render::streaming_ready_texture **)(v29 + 144);
                v31 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(v27, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&first);
                if ( v31 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v30 )
                {
                  v32 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                          &v31->_M_header._M_data,
                          (stlp_std::priv::_Rb_tree_node_base **)&v30->m_options_count,
                          (stlp_std::priv::_Rb_tree_node_base **)&v30->m_type,
                          (stlp_std::priv::_Rb_tree_node_base **)&v30->m_game);
                  if ( v32 )
                  {
                    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v32);
                  }
                  --v30->m_movie;
                  vostok::render::resource_manager::release_impl((const vostok::render::res_texture *)v29, v67);
                }
              }
            }
          }
          vostok::fixed_string<260>::operator=(
            (vostok::fixed_string<260> *)&v75._M_header._M_data._M_parent,
            (vostok::fixed_string<260> *)(index + 12));
          v35 = *(float *)&projection_matrix->requested_streamable_textures._M_impl._M_finish;
          if ( (vostok::render::requested_streamable_texture *)LODWORD(v35) == projection_matrix->requested_streamable_textures._M_impl._M_end_of_storage._M_data )
          {
            stlp_std::priv::_Impl_vector<vostok::render::requested_streamable_texture,vostok::render::std_allocator<vostok::render::requested_streamable_texture>>::_M_insert_overflow_aux(
              v34,
              (vostok::render::requested_streamable_texture *)&projection_matrix->requested_streamable_textures,
              (vostok::render::requested_streamable_texture *)LODWORD(v35),
              (const vostok::render::requested_streamable_texture *)&v75._M_header._M_data._M_parent,
              (unsigned int)v67,
              v68);
          }
          else
          {
            if ( v35 != 0.0 )
              vostok::render::requested_streamable_texture::requested_streamable_texture(
                (vostok::render::requested_streamable_texture *)LODWORD(v35),
                (const vostok::render::requested_streamable_texture *)&v75._M_header._M_data._M_parent);
            ++projection_matrix->requested_streamable_textures._M_impl._M_finish;
          }
          path.m_string.m_begin = path.m_string.m_buffer;
          path.m_string.m_max_end = &path.m_separator;
          m_buffer = path_add.m_string.m_buffer;
          path_add.m_string.m_begin = path_add.m_string.m_buffer;
          M_parent = v75._M_header._M_data._M_parent;
          path.m_string.m_end = path.m_string.m_buffer;
          path.m_string.m_buffer[0] = 0;
          path.m_separator = 47;
          path_add.m_string.m_end = path_add.m_string.m_buffer;
          path_add.m_string.m_max_end = &path_add.m_separator;
          path_add.m_string.m_buffer[0] = 0;
          if ( v75._M_header._M_data._M_parent )
          {
            if ( v75._M_header._M_data._M_parent->_M_color )
            {
              do
              {
                if ( m_buffer >= path_add.m_string.m_max_end )
                  break;
                *m_buffer = M_parent->_M_color;
                m_buffer = path_add.m_string.m_end + 1;
                M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 1);
                ++path_add.m_string.m_end;
              }
              while ( M_parent->_M_color );
            }
            *m_buffer = 0;
          }
          path_add.m_separator = 47;
          vostok::fs_new::path_string_impl::assignf(&path, "%s/%s.dds", "resources/textures", path_add.m_string.m_begin);
          first = *(vostok::render::streaming_ready_texture **)&v73._M_key_compare.stlp_std::binary_function<char *,char *,bool>;
          v38.t_ = creation_time;
          *(_BYTE *)(v76[0] + 8) = 0;
          *(boost::_bi::value<float> *)(v76[0] + 12) = v38;
          HIDWORD(v65) = 0;
          LODWORD(v65) = vostok::render::scene::on_texture_loaded;
          v64.m_object = 0;
          if ( v76[0] )
          {
            v64.m_object = (vostok::render::res_texture *)v76[0];
            ++*(_DWORD *)(v76[0] + 4);
          }
          boost::bind<void,vostok::render::scene,vostok::resources::queries_result &,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float,vostok::render::scene *,boost::arg<1>,vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,unsigned int,float>(
            v38,
            (boost::_bi::value<float>)first,
            (int)&v66,
            projection_matrix,
            1_69,
            v64,
            (void (__thiscall *__ptr64)(vostok::render::scene *, vostok::resources::queries_result *, vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>, unsigned int, float))v65);
          boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
            v39,
            v66,
            (int)v67);
          v73._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)path.m_string.m_begin;
          v73._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)7;
          *(float *)&first = 0.0;
          vostok::resources::query_resources(
            (const vostok::resources::request *)&v73._M_header._M_data._M_left,
            1u,
            (const boost::function<void __cdecl(vostok::resources::queries_result &)> *)&creation_timer,
            (vostok::memory::base_allocator *)vostok::render::g_allocator.m_object,
            (const vostok::variant<32> **)&first,
            0,
            assert_on_fail_true);
          if ( LODWORD(creation_timer.m_current_time) )
          {
            if ( (creation_timer.m_current_time & 1) == 0 )
            {
              v40 = *(void (__cdecl **)(unsigned __int64 *, unsigned __int64 *, int))(creation_timer.m_current_time
                                                                                    & 0xFFFFFFFE);
              if ( v40 )
                v40(&creation_timer.m_start_time, &creation_timer.m_start_time, 2);
            }
            LODWORD(creation_timer.m_current_time) = 0;
          }
          v41 = v76[0];
          if ( v76[0] )
          {
            --*(_DWORD *)(v76[0] + 4);
            if ( !*(_DWORD *)(v41 + 4) )
            {
              v42 = (const vostok::render::res_texture *)v76[0];
              if ( *(_BYTE *)(v76[0] + 439) )
              {
                v43 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
                *(_DWORD *)&v73._M_header._M_data._M_color = *(_DWORD *)(v76[0] + 144);
                v44 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(&v73, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&v73);
                if ( v44 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v43 )
                {
                  v45 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                          &v44->_M_header._M_data,
                          (stlp_std::priv::_Rb_tree_node_base **)&v43->m_options_count,
                          (stlp_std::priv::_Rb_tree_node_base **)&v43->m_type,
                          (stlp_std::priv::_Rb_tree_node_base **)&v43->m_game);
                  if ( v45 )
                  {
                    v46 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
                    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
                    vostok_mspace_free(v46, v45);
                  }
                  --v43->m_movie;
                  vostok::render::resource_manager::release_impl(v42, v67);
                }
              }
            }
          }
        }
      }
      v5 = projection_matrix;
      index += 288;
      if ( (vostok::render::streamable_texture_info *)index == info_end )
        break;
      v15 = *(float *)&index;
    }
  }
  if ( v5->ready_streaming_textures._M_impl._M_finish - v5->ready_streaming_textures._M_impl._M_start )
  {
    v47 = v5->ready_streaming_textures._M_impl._M_finish;
    v48 = v5->ready_streaming_textures._M_impl._M_start;
    LOBYTE(info_end) = 0;
    ___sort_PAUstreaming_ready_texture_render_vostok__Uready_texture_comparer__BA___process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__stlp_std__YAXPAUstreaming_ready_texture_render_vostok__0Uready_texture_comparer__BA___process_streaming_scene_23_QAEXABVfloat4x4_math_3_Vfloat3_83_II_Z__Z(
      v48,
      v47,
      0);
    v49 = 0;
    index = 0;
    creation_timer.m_current_time = 0;
    if ( vostok::timing::g_cpu_supports_time_stamp )
    {
      v50 = __rdtsc();
    }
    else
    {
      QueryPerformanceCounter((LARGE_INTEGER *)&v73._M_header._M_data._M_left);
      v50 = *(_QWORD *)&v73._M_header._M_data._M_left;
    }
    v51 = (char *)v5->ready_streaming_textures._M_impl._M_finish - (char *)v5->ready_streaming_textures._M_impl._M_start;
    creation_timer.m_start_time = v50;
    LODWORD(creation_timer.m_time_factor) = clear_value;
    LODWORD(creation_timer.m_backup_time_factor) = clear_value;
    creation_time = 0.0;
    if ( v51 / 288 )
    {
      while ( index < 4 && creation_time <= 2.0 )
      {
        v52 = v5->ready_streaming_textures._M_impl._M_start;
        first = v52;
        if ( vostok::timing::g_cpu_supports_time_stamp )
        {
          v53 = __rdtsc();
        }
        else
        {
          QueryPerformanceCounter((LARGE_INTEGER *)&v73);
          v53 = *(_QWORD *)&v73._M_header._M_data._M_color;
        }
        HIDWORD(creation_timer.m_start_time) = HIDWORD(v53);
        HIDWORD(v53) = v52->num_mips;
        LODWORD(creation_timer.m_start_time) = v53;
        LODWORD(v53) = v52->name.m_begin;
        *(_QWORD *)&v66.l_.a4_.t_ = v53;
        p_a3 = (vostok::render::resource_manager *)&v66.l_.a3_;
        v66.l_.a3_.t_.m_object = 0;
        m_object = v52->data.m_object;
        creation_timer.m_current_time = 0;
        if ( m_object )
        {
          v66.l_.a3_.t_.m_object = (vostok::render::res_texture *)m_object;
          p_a3 = (vostok::render::resource_manager *)_InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        vostok::render::resource_manager::on_texture_loaded(
          p_a3,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::resources::managed_resource *)v66.l_.a3_.t_.m_object,
          (const char *)v66.l_.a4_.t_,
          LODWORD(v66.l_.a5_.t_));
        elapsed_sec = vostok::timing::timer::get_elapsed_sec(&creation_timer);
        v57 = v52->texture.m_object;
        creation_time = elapsed_sec * 1000.0 + creation_time;
        if ( v57 )
        {
          v49 = v57;
          ++v57->m_reference_count;
        }
        v58 = v5->requested_streamable_textures._M_impl._M_finish;
        v59 = v5->requested_streamable_textures._M_impl._M_start;
        v66.l_.a5_.t_ = 0.0;
        if ( v49 )
        {
          LODWORD(v66.l_.a5_.t_) = v49;
          ++v49->m_reference_count;
        }
        requested_texture = (vostok::render::streamable_texture_info *)stlp_std::priv::__find_if<vostok::render::requested_streamable_texture *,vostok::render::find_requested_texture_predicate>(
                                                                         v59,
                                                                         v58,
                                                                         LODWORD(v66.l_.a5_.t_));
        info_end = requested_texture;
        if ( v49 )
        {
          if ( v49->m_reference_count-- == 1 )
          {
            vostok::render::res_texture::destroy_impl(v61, v49);
            requested_texture = info_end;
          }
        }
        if ( requested_texture != (vostok::render::streamable_texture_info *)v5->requested_streamable_textures._M_impl._M_finish )
        {
          stlp_std::vector<vostok::render::requested_streamable_texture,vostok::render::std_allocator<vostok::render::requested_streamable_texture>>::erase(
            &v5->requested_streamable_textures,
            (vostok::render::requested_streamable_texture *)requested_texture);
          v52 = first;
        }
        stlp_std::priv::_Impl_vector<vostok::render::streaming_ready_texture,vostok::render::std_allocator<vostok::render::streaming_ready_texture>>::_M_erase(
          &v5->ready_streaming_textures._M_impl,
          v52,
          (const stlp_std::__false_type *)v67);
        v63 = (char *)v5->ready_streaming_textures._M_impl._M_finish
            - (char *)v5->ready_streaming_textures._M_impl._M_start;
        ++index;
        if ( !(v63 / 288) )
          break;
        v49 = 0;
      }
    }
  }
}
