void __thiscall vostok::render::renderer_context::renderer_context(
        vostok::render::renderer_context *this,
        vostok::render::renderer_context *thisa)
{
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v2; // ecx
  const vostok::math::float4x4 *v3; // xmm1_4
  vostok::render::res_texture **p_m_object; // esi
  const char *v5; // eax
  bool v6; // zf
  vostok::render::res_texture *v7; // eax
  survarium::options_tab *v8; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v9; // eax
  vostok::render::res_texture *m_object; // esi
  survarium::options_tab *v11; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v12; // eax
  vostok::fixed_vector<vostok::render::ray,8>::allign_helper *m_buffer; // ecx
  vostok::render::sun_cascade *v14; // esi
  int v15; // edi
  vostok::render::sun_cascade *m_end; // eax
  vostok::render::renderer_context *v17; // ecx
  vostok::strings::shared::manager *v18; // ecx
  vostok::strings::shared::profile *v19; // eax
  vostok::strings::shared::profile *v20; // ecx
  survarium::game *m_game; // esi
  vostok::render::shader_constant_binding *m_type; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *m_pointer; // ecx
  vostok::render::res_texture *v24; // eax
  vostok::strings::shared::profile *v25; // edi
  vostok::render::shader_constant_host *v26; // eax
  unsigned int m_size; // edx
  void *(__thiscall *v28)(void *); // eax
  vostok::strings::shared::manager *v29; // ecx
  vostok::strings::shared::profile *v30; // eax
  vostok::strings::shared::profile *v31; // ecx
  survarium::game *v32; // esi
  vostok::render::shader_constant_binding *v33; // ecx
  stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *v34; // ecx
  vostok::render::res_texture *v35; // eax
  vostok::strings::shared::profile *v36; // edi
  vostok::render::shader_constant_host *v37; // eax
  unsigned int v38; // edx
  void *(__thiscall *v39)(void *); // eax
  vostok::strings::shared::manager *v40; // ecx
  vostok::strings::shared::profile *v41; // eax
  vostok::strings::shared::profile *v42; // esi
  void *(__thiscall *v43)(void *); // eax
  vostok::strings::shared::profile *v44; // ecx
  vostok::strings::shared::profile *v45; // eax
  vostok::strings::shared::profile *v46; // esi
  void *(__thiscall *v47)(void *); // eax
  vostok::strings::shared::profile *v48; // ecx
  vostok::strings::shared::profile *v49; // eax
  vostok::strings::shared::profile *v50; // esi
  void *(__thiscall *v51)(void *); // eax
  vostok::strings::shared::profile *v52; // ecx
  vostok::strings::shared::profile *v53; // eax
  vostok::strings::shared::profile *v54; // esi
  void *(__thiscall *v55)(void *); // eax
  vostok::strings::shared::profile *v56; // ecx
  vostok::strings::shared::profile *v57; // eax
  vostok::strings::shared::profile *v58; // esi
  void *(__thiscall *v59)(void *); // eax
  vostok::strings::shared::profile *v60; // ecx
  vostok::strings::shared::profile *v61; // eax
  vostok::strings::shared::profile *v62; // esi
  void *(__thiscall *v63)(void *); // eax
  vostok::strings::shared::profile *v64; // ecx
  vostok::strings::shared::profile *v65; // eax
  vostok::strings::shared::profile *v66; // esi
  void *(__thiscall *v67)(void *); // eax
  vostok::strings::shared::profile *v68; // ecx
  vostok::strings::shared::profile *v69; // eax
  vostok::strings::shared::profile *v70; // esi
  void *(__thiscall *v71)(void *); // eax
  vostok::strings::shared::profile *v72; // ecx
  vostok::strings::shared::profile *v73; // eax
  void *(__thiscall *v74)(void *); // eax
  vostok::strings::shared::profile *v75; // ecx
  void *(__thiscall *v76)(void *); // eax
  vostok::strings::shared::manager *v77; // ecx
  vostok::strings::shared::profile *v78; // eax
  void *(__thiscall *v79)(void *); // eax
  vostok::strings::shared::profile *v80; // ecx
  void *(__thiscall *v81)(void *); // eax
  vostok::strings::shared::manager *v82; // ecx
  vostok::strings::shared::profile *v83; // eax
  void *(__thiscall *v84)(void *); // eax
  vostok::strings::shared::profile *v85; // ecx
  void *(__thiscall *v86)(void *); // eax
  vostok::strings::shared::manager *v87; // ecx
  vostok::strings::shared::profile *v88; // eax
  void *(__thiscall *v89)(void *); // eax
  vostok::strings::shared::profile *v90; // ecx
  void *(__thiscall *v91)(void *); // eax
  vostok::strings::shared::manager *v92; // ecx
  vostok::strings::shared::profile *v93; // eax
  void *(__thiscall *v94)(void *); // eax
  vostok::strings::shared::profile *v95; // ecx
  void *(__thiscall *v96)(void *); // eax
  vostok::strings::shared::manager *v97; // ecx
  vostok::strings::shared::profile *v98; // eax
  void *(__thiscall *v99)(void *); // eax
  vostok::strings::shared::profile *v100; // ecx
  void *(__thiscall *v101)(void *); // eax
  vostok::strings::shared::manager *v102; // ecx
  vostok::strings::shared::profile *v103; // eax
  vostok::render::resource_manager *v104; // esi
  const vostok::render::shader_constant_binding *v105; // eax
  void *(__thiscall *v106)(void *); // eax
  vostok::strings::shared::manager *v107; // ecx
  vostok::strings::shared::profile *v108; // eax
  vostok::render::resource_manager *v109; // esi
  const vostok::render::shader_constant_binding *v110; // eax
  void *(__thiscall *v111)(void *); // eax
  vostok::strings::shared::manager *v112; // ecx
  vostok::render::enum_render_target_index v113; // eax
  const vostok::render::res_texture **v114; // edi
  char *v115; // eax
  stlp_std::priv::_Rb_tree_node_base *v116; // eax
  vostok::render::res_texture *v117; // ecx
  const vostok::render::res_texture *v118; // esi
  stlp_std::priv::_Rb_tree_node_base *v119; // eax
  vostok::render::res_texture *v120; // ecx
  const vostok::render::res_texture *v121; // esi
  vostok::strings::shared::profile *v122; // [esp-4h] [ebp-4C4h] BYREF
  vostok::render::resource_manager *v123; // [esp+0h] [ebp-4C0h]
  unsigned int v124; // [esp+4h] [ebp-4BCh]
  bool v125; // [esp+8h] [ebp-4B8h]
  unsigned int i; // [esp+10h] [ebp-4B0h] BYREF
  vostok::render::shader_constant_binding __val; // [esp+14h] [ebp-4ACh] BYREF
  vostok::render::res_texture *texture; // [esp+28h] [ebp-498h] BYREF
  char *m_begin; // [esp+2Ch] [ebp-494h] BYREF
  vostok::math::float4x4 v130; // [esp+30h] [ebp-490h] BYREF
  vostok::render::sun_cascade cascades[4]; // [esp+70h] [ebp-450h] BYREF

  v122 = (vostok::strings::shared::profile *)vostok::render::render_target_instance::render_target_instance;
  thisa->m_targets = 0;
  `vector constructor iterator'((char *)thisa->m_family, 0xA0u, 70, (void *(__thiscall *)(void *))v122);
  thisa->m_t_null.m_object = 0;
  thisa->m_g_quad_uv.m_object = 0;
  thisa->m_g_quad_2uv.m_object = 0;
  thisa->m_g_quad_eye_ray.m_object = 0;
  thisa->m_quad_ib.m_object = 0;
  thisa->m_t_shadow_cascade.m_object = 0;
  thisa->m_time_delta = 0.0;
  thisa->m_sun_cascades.m_begin = (vostok::render::sun_cascade *)thisa->m_sun_cascades.m_buffer;
  thisa->m_sun_cascades.m_end = (vostok::render::sun_cascade *)thisa->m_sun_cascades.m_buffer;
  thisa->m_visible_trees._M_impl._M_start = 0;
  thisa->m_visible_trees._M_impl._M_finish = 0;
  thisa->m_visible_trees._M_impl._M_end_of_storage._M_data = 0;
  thisa->m_scene = 0;
  thisa->m_scene_view.m_object = 0;
  thisa->m_w_stack.m_begin = (vostok::math::float4x4 *)thisa->m_w_stack.m_buffer;
  thisa->m_w_stack.m_end = (vostok::math::float4x4 *)thisa->m_w_stack.m_buffer;
  thisa->m_v_stack.m_begin = (vostok::math::float4x4 *)thisa->m_v_stack.m_buffer;
  thisa->m_v_stack.m_end = (vostok::math::float4x4 *)thisa->m_v_stack.m_buffer;
  thisa->m_p_stack.m_begin = (vostok::math::float4x4 *)thisa->m_p_stack.m_buffer;
  thisa->m_p_stack.m_end = (vostok::math::float4x4 *)thisa->m_p_stack.m_buffer;
  qmemcpy((void *)&thisa->m_w, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_w));
  qmemcpy((void *)&thisa->m_w_transposed, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_w_transposed));
  qmemcpy((void *)&thisa->m_v, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v));
  qmemcpy((void *)&thisa->m_v_transposed, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v_transposed));
  qmemcpy((void *)&thisa->m_v_inverted, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v_inverted));
  qmemcpy(
    (void *)&thisa->m_v_inverted_transposed,
    vostok::math::float4x4::identity(&v130),
    sizeof(thisa->m_v_inverted_transposed));
  qmemcpy((void *)&thisa->m_p, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_p));
  qmemcpy((void *)&thisa->m_p_transposed, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_p_transposed));
  qmemcpy((void *)&thisa->m_p_inverted, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_p_inverted));
  qmemcpy((void *)&thisa->m_wv, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_wv));
  qmemcpy((void *)&thisa->m_wv_transposed, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_wv_transposed));
  qmemcpy((void *)&thisa->m_vp, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_vp));
  qmemcpy((void *)&thisa->m_vp_transposed, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_vp_transposed));
  qmemcpy((void *)&thisa->m_wvp, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_wvp));
  qmemcpy((void *)&thisa->m_wvp_transposed, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_wvp_transposed));
  qmemcpy((void *)&thisa->m_v2shadow0, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v2shadow0));
  qmemcpy((void *)&thisa->m_v2shadow1, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v2shadow1));
  qmemcpy((void *)&thisa->m_v2shadow2, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v2shadow2));
  qmemcpy((void *)&thisa->m_v2shadow3, vostok::math::float4x4::identity(&v130), sizeof(thisa->m_v2shadow3));
  v2 = 0;
  thisa->m_solid_color_specular.x = 0.0;
  thisa->m_solid_color_specular.y = 0.0;
  thisa->m_solid_color_specular.z = 0.0;
  thisa->m_solid_color_specular.w = 0.0;
  thisa->m_solid_material_parameters.x = FLOAT_10_0;
  v3 = clear_value;
  LODWORD(thisa->m_solid_material_parameters.y) = clear_value;
  thisa->m_solid_material_parameters.z = 0.0;
  thisa->m_solid_material_parameters.w = 0.0;
  thisa->m_view_pos.x = 0.0;
  thisa->m_view_pos.y = 0.0;
  thisa->m_view_pos.z = 0.0;
  LODWORD(thisa->m_view_pos.w) = v3;
  thisa->m_eye_pos_view_space.x = 0.0;
  thisa->m_eye_pos_view_space.y = 0.0;
  thisa->m_eye_pos_view_space.z = 0.0;
  LODWORD(thisa->m_eye_pos_view_space.w) = v3;
  thisa->m_view_dir.x = 0.0;
  thisa->m_view_dir.y = 0.0;
  LODWORD(thisa->m_view_dir.z) = v3;
  thisa->m_view_dir.w = FLOAT_0_1;
  thisa->m_c_w = 0;
  thisa->m_c_w_inv = 0;
  thisa->m_c_v = 0;
  thisa->m_c_p = 0;
  thisa->m_c_wv = 0;
  thisa->m_c_vp = 0;
  thisa->m_c_wvp = 0;
  thisa->m_c_v2w = 0;
  p_m_object = &thisa->m_family[0].texture.m_object;
  i = 70;
  do
  {
    v5 = (const char *)*(p_m_object - 1);
    *(p_m_object - 1) = 0;
    if ( v5 )
    {
      v6 = (*(_DWORD *)v5)-- == 1;
      if ( v6 )
        vostok::render::resource_manager::release(
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          v5);
    }
    texture = *p_m_object;
    v7 = texture;
    *p_m_object = 0;
    if ( v7 )
    {
      v6 = v7->m_reference_count-- == 1;
      if ( v6 && v7->m_is_registered )
      {
        v8 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
        m_begin = v7->m_name.m_string.m_begin;
        v9 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
               v2,
               (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
               (const char **)&m_begin);
        if ( v9 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v8 )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v122,
            (int)v8,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v9);
          vostok::render::resource_manager::release_impl(texture, v123);
        }
      }
    }
    p_m_object += 40;
    --i;
  }
  while ( i );
  thisa->m_current_size.x = 0;
  thisa->m_current_size.y = 0;
  m_object = thisa->m_t_shadow_cascade.m_object;
  thisa->m_t_shadow_cascade.m_object = 0;
  if ( m_object )
  {
    v6 = m_object->m_reference_count-- == 1;
    if ( v6 && m_object->m_is_registered )
    {
      v11 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
      texture = (vostok::render::res_texture *)m_object->m_name.m_string.m_begin;
      v12 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
              (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)texture,
              (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
              (const char **)&texture);
      if ( v12 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v11 )
      {
        stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
          (stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > *)&v122,
          (int)v11,
          (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v12);
        vostok::render::resource_manager::release_impl(m_object, v123);
      }
    }
  }
  memset((int)thisa->m_eye_rays, 0, sizeof(thisa->m_eye_rays));
  vostok::render::register_effect_descriptors((vostok::render *)v123);
  cascades[0].size = FLOAT_10_0;
  cascades[0].bias = FLOAT_0_000099999997;
  cascades[1].size = default_fps_3;
  cascades[1].bias = 0.00050000002;
  cascades[0].rays.m_begin = (vostok::render::ray *)cascades[0].rays.m_buffer;
  cascades[2].size = 75.0;
  cascades[0].rays.m_end = (vostok::render::ray *)cascades[0].rays.m_buffer;
  cascades[1].rays.m_end = (vostok::render::ray *)cascades[1].rays.m_buffer;
  cascades[2].bias = epsilon_3_11;
  cascades[1].rays.m_begin = (vostok::render::ray *)cascades[1].rays.m_buffer;
  cascades[2].rays.m_begin = (vostok::render::ray *)cascades[2].rays.m_buffer;
  m_buffer = cascades[3].rays.m_buffer;
  cascades[3].size = 240.0;
  cascades[0].reset_chain = 0;
  cascades[1].reset_chain = 0;
  cascades[2].rays.m_end = (vostok::render::ray *)cascades[2].rays.m_buffer;
  cascades[2].reset_chain = 0;
  cascades[3].rays.m_begin = (vostok::render::ray *)cascades[3].rays.m_buffer;
  cascades[3].rays.m_end = (vostok::render::ray *)cascades[3].rays.m_buffer;
  cascades[3].reset_chain = 0;
  cascades[3].bias = 0.003;
  v14 = cascades;
  v15 = 4;
  do
  {
    m_end = thisa->m_sun_cascades.m_end;
    if ( m_end )
      vostok::render::sun_cascade::sun_cascade((vostok::render::sun_cascade *)m_buffer, m_end, v14);
    ++thisa->m_sun_cascades.m_end;
    ++v14;
    --v15;
  }
  while ( v15 );
  memset((int)thisa->m_eye_rays, 0, sizeof(thisa->m_eye_rays));
  thisa->m_fog_params.x = -1.5;
  thisa->m_fog_params.y = 0.00025000001;
  thisa->m_fog_params.z = 0.00025000001;
  thisa->m_fog_params.w = 0.00025000001;
  __val.m_source.m_pointer = (void *const)clear_value;
  __val.m_source.m_size = (const unsigned int)clear_value;
  __val.m_name.m_pointer.m_object = (vostok::strings::shared::profile *)clear_value;
  __val.m_type = (vostok::render::enum_constant_type)clear_value;
  *(vostok::render::shader_constant_source *)&thisa->m_screen_resolution.x = __val.m_source;
  *(_QWORD *)&thisa->m_screen_resolution.elements[2] = *(_QWORD *)&__val.m_name.m_pointer.m_object;
  vostok::render::renderer_context::reset_matrices(v17, (int)thisa);
  v122 = (vostok::strings::shared::profile *)"m_W";
  v19 = vostok::strings::shared::manager::string(v18, (const char *)s_manager.m_variable);
  v20 = 0;
  i = 0;
  if ( v19 )
  {
    v20 = v19;
    i = (unsigned int)v19;
    _InterlockedExchangeAdd(&v19->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_w_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v20 )
  {
    __val.m_name.m_pointer.m_object = v20;
    _InterlockedExchangeAdd(&v20->m_reference_count, 1u);
  }
  m_game = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][33].m_game;
  m_type = (vostok::render::shader_constant_binding *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][33].m_type;
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  texture = (vostok::render::res_texture *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][33].m_type;
  if ( stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
         m_type,
         (vostok::render::shader_constant_binding *)m_game,
         &__val) != (vostok::render::shader_constant_binding *)m_game )
    goto LABEL_32;
  v24 = texture;
  if ( m_game == *(survarium::game **)&texture->m_loaded )
  {
    stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::_M_insert_overflow_aux(
      &__val,
      m_pointer,
      (stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding> > *)texture,
      (vostok::render::shader_constant_binding *)m_game,
      (const stlp_std::__false_type *)v123,
      v124,
      v125);
LABEL_32:
    v25 = __val.m_name.m_pointer.m_object;
    goto LABEL_33;
  }
  v25 = __val.m_name.m_pointer.m_object;
  if ( m_game )
  {
    m_pointer = (stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *)__val.m_source.m_pointer;
    m_game->vostok::engine_user::world::__vftable = (survarium::game_vtbl *)__val.m_source.m_pointer;
    m_game->survarium::scaleform_game_engine::__vftable = (survarium::scaleform_game_engine_vtbl *)64;
    *(_DWORD *)&m_game->gap8 = 0;
    if ( v25 )
    {
      *(_DWORD *)&m_game->gap8 = v25;
      m_pointer = (stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *)_InterlockedExchangeAdd(&v25->m_reference_count, 1u);
    }
    *(_DWORD *)(&m_game->hide_game_stats + 1) = 0;
    LODWORD(m_game->m_timer.m_current_time) = 320;
  }
  v24->m_reference_count += 20;
LABEL_33:
  v26 = vostok::render::backend::register_constant_host(
          (vostok::render::backend *)m_pointer,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          &__val.m_name,
          __val.m_type);
  if ( v26 )
  {
    m_size = __val.m_source.m_size;
    v26->m_source.m_pointer = __val.m_source.m_pointer;
    v26->m_source.m_size = m_size;
  }
  thisa->m_c_w = v26;
  if ( v25 && !_InterlockedExchangeAdd(&v25->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v25;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v28 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v29 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v28;
      vostok::strings::shared::manager::remove(v29, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"m_V";
  v30 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v31 = 0;
  i = 0;
  if ( v30 )
  {
    v31 = v30;
    i = (unsigned int)v30;
    _InterlockedExchangeAdd(&v30->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_v_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v31 )
  {
    __val.m_name.m_pointer.m_object = v31;
    _InterlockedExchangeAdd(&v31->m_reference_count, 1u);
  }
  v32 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][33].m_game;
  v33 = (vostok::render::shader_constant_binding *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][33].m_type;
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  texture = (vostok::render::res_texture *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][33].m_type;
  if ( stlp_std::priv::__find<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
         v33,
         (vostok::render::shader_constant_binding *)v32,
         &__val) != (vostok::render::shader_constant_binding *)v32 )
    goto LABEL_53;
  v35 = texture;
  if ( v32 == *(survarium::game **)&texture->m_loaded )
  {
    stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding>>::_M_insert_overflow_aux(
      &__val,
      v34,
      (stlp_std::priv::_Impl_vector<vostok::render::shader_constant_binding,vostok::render::std_allocator<vostok::render::shader_constant_binding> > *)texture,
      (vostok::render::shader_constant_binding *)v32,
      (const stlp_std::__false_type *)v123,
      v124,
      v125);
LABEL_53:
    v36 = __val.m_name.m_pointer.m_object;
    goto LABEL_54;
  }
  v36 = __val.m_name.m_pointer.m_object;
  if ( v32 )
  {
    v34 = (stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *)__val.m_source.m_pointer;
    v32->vostok::engine_user::world::__vftable = (survarium::game_vtbl *)__val.m_source.m_pointer;
    v32->survarium::scaleform_game_engine::__vftable = (survarium::scaleform_game_engine_vtbl *)64;
    *(_DWORD *)&v32->gap8 = 0;
    if ( v36 )
    {
      *(_DWORD *)&v32->gap8 = v36;
      v34 = (stlp_std::priv::_Impl_vector<vostok::render::trample_desc,vostok::render::std_allocator<vostok::render::trample_desc> > *)_InterlockedExchangeAdd(&v36->m_reference_count, 1u);
    }
    *(_DWORD *)(&v32->hide_game_stats + 1) = 0;
    LODWORD(v32->m_timer.m_current_time) = 320;
  }
  v35->m_reference_count += 20;
LABEL_54:
  v37 = vostok::render::backend::register_constant_host(
          (vostok::render::backend *)v34,
          (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
          &__val.m_name,
          __val.m_type);
  if ( v37 )
  {
    v38 = __val.m_source.m_size;
    v37->m_source.m_pointer = __val.m_source.m_pointer;
    v37->m_source.m_size = v38;
  }
  thisa->m_c_v = v37;
  if ( v36 && !_InterlockedExchangeAdd(&v36->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v36;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v39 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v40 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v39;
      vostok::strings::shared::manager::remove(v40, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"m_P";
  v41 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v42 = 0;
  if ( v41 )
  {
    v42 = v41;
    _InterlockedExchangeAdd(&v41->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_p_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v42 )
  {
    __val.m_name.m_pointer.m_object = v42;
    _InterlockedExchangeAdd(&v42->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  thisa->m_c_p = vostok::render::resource_manager::register_constant_binding(
                   &__val,
                   (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v43 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v44 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v43;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v44,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v42 && !_InterlockedExchangeAdd(&v42->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v42;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v42,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"m_V2W";
  v45 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v46 = 0;
  if ( v45 )
  {
    v46 = v45;
    _InterlockedExchangeAdd(&v45->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_v_inverted_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v46 )
  {
    __val.m_name.m_pointer.m_object = v46;
    _InterlockedExchangeAdd(&v46->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  thisa->m_c_v2w = vostok::render::resource_manager::register_constant_binding(
                     &__val,
                     (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v47 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v48 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v47;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v48,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v46 && !_InterlockedExchangeAdd(&v46->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v46;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v46,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"m_WV_inverted";
  v49 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v50 = 0;
  if ( v49 )
  {
    v50 = v49;
    _InterlockedExchangeAdd(&v49->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_wv_inverted_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v50 )
  {
    __val.m_name.m_pointer.m_object = v50;
    _InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  thisa->m_c_wv_inv = vostok::render::resource_manager::register_constant_binding(
                        &__val,
                        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v51 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v52 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v51;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v52,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v50 && !_InterlockedExchangeAdd(&v50->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v50;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v50,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"m_WV";
  v53 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v54 = 0;
  if ( v53 )
  {
    v54 = v53;
    _InterlockedExchangeAdd(&v53->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_wv_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v54 )
  {
    __val.m_name.m_pointer.m_object = v54;
    _InterlockedExchangeAdd(&v54->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  thisa->m_c_wv = vostok::render::resource_manager::register_constant_binding(
                    &__val,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v55 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v56 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v55;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v56,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v54 && !_InterlockedExchangeAdd(&v54->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v54;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v54,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"m_VP";
  v57 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v58 = 0;
  if ( v57 )
  {
    v58 = v57;
    _InterlockedExchangeAdd(&v57->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_vp_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v58 )
  {
    __val.m_name.m_pointer.m_object = v58;
    _InterlockedExchangeAdd(&v58->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  thisa->m_c_vp = vostok::render::resource_manager::register_constant_binding(
                    &__val,
                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v59 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v60 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v59;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v60,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v58 && !_InterlockedExchangeAdd(&v58->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v58;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v58,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"m_WVP";
  v61 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v62 = 0;
  if ( v61 )
  {
    v62 = v61;
    _InterlockedExchangeAdd(&v61->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = (void *const)&thisa->m_wvp_transposed;
  __val.m_source.m_size = 64;
  __val.m_name.m_pointer.m_object = 0;
  if ( v62 )
  {
    __val.m_name.m_pointer.m_object = v62;
    _InterlockedExchangeAdd(&v62->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_4x4;
  thisa->m_c_wvp = vostok::render::resource_manager::register_constant_binding(
                     &__val,
                     (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v63 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v64 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v63;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v64,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v62 && !_InterlockedExchangeAdd(&v62->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v62;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v62,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"near_far_invn_invf";
  v65 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v66 = 0;
  if ( v65 )
  {
    v66 = v65;
    _InterlockedExchangeAdd(&v65->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = &thisa->m_near_far_invn_invf;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  if ( v66 )
  {
    __val.m_name.m_pointer.m_object = v66;
    _InterlockedExchangeAdd(&v66->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_near_far = vostok::render::resource_manager::register_constant_binding(
                          &__val,
                          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v67 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v68 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v67;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v68,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v66 && !_InterlockedExchangeAdd(&v66->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v66;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v66,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"fog_params";
  v69 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  v70 = 0;
  if ( v69 )
  {
    v70 = v69;
    _InterlockedExchangeAdd(&v69->m_reference_count, 1u);
  }
  __val.m_source.m_pointer = &thisa->m_fog_params;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  if ( v70 )
  {
    __val.m_name.m_pointer.m_object = v70;
    _InterlockedExchangeAdd(&v70->m_reference_count, 1u);
  }
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_fog_params = vostok::render::resource_manager::register_constant_binding(
                            &__val,
                            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v71 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v72 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v71;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v72,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  if ( v70 && !_InterlockedExchangeAdd(&v70->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = v70;
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)v70,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v122 = (vostok::strings::shared::profile *)"screen_res";
  v73 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v73);
  __val.m_source.m_pointer = &thisa->m_screen_resolution;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &__val.m_name.m_pointer,
    (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i);
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_screen_resolution = vostok::render::resource_manager::register_constant_binding(
                                   &__val,
                                   (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v74 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v75 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v74;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v75,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v76 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v77 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v76;
      vostok::strings::shared::manager::remove(v77, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"eye_position";
  v78 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v78);
  __val.m_source.m_pointer = &thisa->m_view_pos;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &__val.m_name.m_pointer,
    (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i);
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_view_pos = vostok::render::resource_manager::register_constant_binding(
                          &__val,
                          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v79 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v80 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v79;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v80,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v81 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v82 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v81;
      vostok::strings::shared::manager::remove(v82, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"eye_position_view_space";
  v83 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v83);
  __val.m_source.m_pointer = &thisa->m_eye_pos_view_space;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &__val.m_name.m_pointer,
    (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i);
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_eye_pos_view_space = vostok::render::resource_manager::register_constant_binding(
                                    &__val,
                                    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v84 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v85 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v84;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v85,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v86 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v87 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v86;
      vostok::strings::shared::manager::remove(v87, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"eye_direction";
  v88 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v88);
  __val.m_source.m_pointer = &thisa->m_view_dir;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &__val.m_name.m_pointer,
    (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i);
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_view_dir = vostok::render::resource_manager::register_constant_binding(
                          &__val,
                          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v89 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v90 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v89;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v90,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v91 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v92 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v91;
      vostok::strings::shared::manager::remove(v92, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)&stru_961604;
  v93 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v93);
  __val.m_source.m_pointer = &thisa->m_solid_color_specular;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &__val.m_name.m_pointer,
    (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i);
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_solid_color_specular = vostok::render::resource_manager::register_constant_binding(
                                      &__val,
                                      (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v94 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v95 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v94;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v95,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v96 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v97 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v96;
      vostok::strings::shared::manager::remove(v97, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"solid_material_params";
  v98 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v98);
  __val.m_source.m_pointer = &thisa->m_solid_material_parameters;
  __val.m_source.m_size = 16;
  __val.m_name.m_pointer.m_object = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    &__val.m_name.m_pointer,
    (const vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i);
  __val.m_type = rc_float;
  __val.m_class_id = rc_1x4;
  thisa->m_c_solid_material_parameters = vostok::render::resource_manager::register_constant_binding(
                                           &__val,
                                           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  v99 = (void *(__thiscall *)(void *))__val.m_name.m_pointer.m_object;
  if ( __val.m_name.m_pointer.m_object )
  {
    v100 = __val.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v99;
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)v100,
        (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v101 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v102 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v101;
      vostok::strings::shared::manager::remove(v102, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"solid_emission_color";
  v103 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v103);
  v104 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  vostok::render::shader_constant_binding::shader_constant_binding(
    &__val,
    &thisa->m_solid_emission_color,
    (const vostok::shared_string *)&i);
  thisa->m_c_solid_emission_color = vostok::render::resource_manager::register_constant_binding(v105, v104);
  if ( __val.m_name.m_pointer.m_object
    && !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = __val.m_name.m_pointer.m_object;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v106 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v107 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v106;
      vostok::strings::shared::manager::remove(v107, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v122 = (vostok::strings::shared::profile *)"scene_time";
  v108 = vostok::strings::shared::manager::string(s_manager.m_variable, (const char *)s_manager.m_variable);
  i = 0;
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock> *)&i,
    v108);
  v109 = (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
  vostok::render::shader_constant_binding::shader_constant_binding(
    &__val,
    &thisa->m_current_time,
    (const vostok::shared_string *)&i);
  thisa->m_c_scene_time = vostok::render::resource_manager::register_constant_binding(v110, v109);
  if ( __val.m_name.m_pointer.m_object
    && !_InterlockedExchangeAdd(&__val.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    v122 = __val.m_name.m_pointer.m_object;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v111 = (void *(__thiscall *)(void *))i;
  if ( i )
  {
    v112 = (vostok::strings::shared::manager *)i;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)i, 0xFFFFFFFF) )
    {
      v122 = (vostok::strings::shared::profile *)v111;
      vostok::strings::shared::manager::remove(v112, (vostok::strings::shared::profile *)s_manager.m_variable);
    }
  }
  v113 = rt_gbuffer_position_downsampled;
  i = 0;
  v114 = (const vostok::render::res_texture **)&thisa->m_family[0].texture.m_object;
  do
  {
    v115 = (char *)vostok::render::rt_index_to_name(v113);
    if ( v115 )
    {
      v116 = vostok::render::resource_manager::create_texture(
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               v115,
               0,
               0,
               0,
               1,
               1,
               0xFFFFFFFF);
      v117 = 0;
      if ( v116 )
      {
        ++v116->_M_parent;
        v117 = (vostok::render::res_texture *)v116;
      }
      v118 = *v114;
      *v114 = v117;
      if ( v118 )
      {
        v6 = v118->m_reference_count-- == 1;
        if ( v6 )
          vostok::render::res_texture::destroy_impl(v117, v118);
      }
    }
    v113 = i + 1;
    v114 += 40;
    i = v113;
  }
  while ( (unsigned int)v113 < rt_num_render_targets );
  v119 = vostok::render::resource_manager::create_texture(
           (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
           "$user$null",
           0,
           0,
           0,
           1,
           1,
           0xFFFFFFFF);
  v120 = 0;
  if ( v119 )
  {
    ++v119->_M_parent;
    v120 = (vostok::render::res_texture *)v119;
  }
  v121 = thisa->m_t_null.m_object;
  thisa->m_t_null.m_object = v120;
  if ( v121 )
  {
    v6 = v121->m_reference_count-- == 1;
    if ( v6 )
      vostok::render::res_texture::destroy_impl(v120, v121);
  }
  `vector destructor iterator'(
    (char *)cascades,
    0x114u,
    4,
    (void (__thiscall *)(void *))vostok::render::sun_cascade::~sun_cascade);
}
