void __thiscall vostok::render::stage_postprocess::advanced_bloom(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *thisa)
{
  vostok::render::res_texture *m_context; // ecx
  unsigned int v3; // eax
  void (__thiscall *v4)(vostok::render::res_texture *); // eax
  const vostok::render::res_texture *v5; // esi
  vostok::render::res_texture *m_object; // eax
  const vostok::render::res_texture *v7; // esi
  vostok::render::res_texture *Height; // ecx
  vostok::render::res_texture *v9; // eax
  const vostok::render::res_texture *v10; // esi
  double Width; // st7
  bool v12; // zf
  vostok::render::res_texture *v13; // eax
  const vostok::render::res_texture *v14; // esi
  double v15; // st7
  _DWORD *v16; // eax
  unsigned int v17; // ecx
  vostok::render::res_texture *v18; // eax
  vostok::render::res_texture *v19; // esi
  const char *m_conflicted_key_name; // edi
  vostok::render::res_texture *v21; // ecx
  const char *v22; // esi
  vostok::render::shader_constant_host *m_blur_target_size_parameter; // eax
  vostok::render::render_target *m_buffer_index; // ecx
  const vostok::render::renderer_context_targets *m_targets; // eax
  vostok::render::render_target *v26; // eax
  int y; // eax
  _DWORD *v28; // eax
  unsigned int v29; // ecx
  vostok::render::res_texture *v30; // eax
  vostok::render::res_texture *v31; // esi
  const char *v32; // edi
  vostok::render::res_texture *v33; // ecx
  const char *v34; // esi
  vostok::render::shader_constant_host *v35; // eax
  vostok::render::render_target *v36; // ecx
  const vostok::render::renderer_context_targets *v37; // eax
  vostok::render::render_target *v38; // eax
  int v39; // eax
  _DWORD *v40; // eax
  unsigned int v41; // ecx
  vostok::render::res_texture *v42; // eax
  vostok::render::res_texture *v43; // esi
  const char *v44; // edi
  vostok::render::res_texture *v45; // ecx
  const char *v46; // esi
  vostok::render::shader_constant_host *v47; // eax
  vostok::render::render_target *v48; // ecx
  const vostok::render::renderer_context_targets *v49; // eax
  vostok::render::render_target *v50; // eax
  int v51; // eax
  _DWORD *v52; // eax
  unsigned int v53; // ecx
  vostok::render::res_texture *v54; // eax
  vostok::render::res_texture *v55; // esi
  const char *v56; // edi
  vostok::render::res_texture *v57; // ecx
  const char *v58; // esi
  vostok::render::shader_constant_host *v59; // eax
  vostok::render::render_target *v60; // ecx
  const vostok::render::renderer_context_targets *v61; // eax
  vostok::render::render_target *v62; // eax
  int v63; // eax
  vostok::render::res_texture *v64; // eax
  vostok::render::res_texture *v65; // eax
  vostok::render::res_texture *v66; // eax
  vostok::render::res_texture *v67; // edi
  vostok::render::render_target *v68; // eax
  vostok::render::render_target *v69; // esi
  vostok::render::res_texture *v70; // ecx
  const char *v71; // eax
  vostok::render::res_texture *v72; // eax
  vostok::render::res_texture *v73; // eax
  vostok::render::render_target *v74; // esi
  vostok::render::res_texture *v75; // eax
  vostok::render::res_texture *v76; // eax
  vostok::render::res_texture *v77; // edi
  vostok::render::render_target *v78; // eax
  vostok::render::res_texture *v79; // ecx
  const char *v80; // eax
  vostok::render::res_texture *v81; // eax
  vostok::render::render_target *v82; // esi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v83; // ecx
  vostok::render::res_texture *v84; // eax
  vostok::render::render_target *v85; // eax
  vostok::render::render_target *v86; // edi
  vostok::render::resource_manager *v87; // ecx
  vostok::render::res_texture *v88; // eax
  vostok::render::res_texture *v89; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v90; // ecx
  vostok::render::res_texture *v91; // eax
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v92; // edi
  vostok::render::res_texture *v93; // edi
  const char *v94; // esi
  vostok::render::resource_manager *v95; // ecx
  const char *v96; // eax
  vostok::render::res_texture *v97; // eax
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v98; // edi
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v99; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v100; // edi
  vostok::render::res_texture *v101; // edi
  const char *v102; // esi
  vostok::render::res_texture *v103; // ecx
  const char *v104; // eax
  vostok::render::res_texture *v105; // eax
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *p_target; // edi
  vostok::render::stage_postprocess *v107; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v108; // ecx
  vostok::render::res_texture *v109; // esi
  const char *v110; // edi
  vostok::render::textures_handler<0> *v111; // ecx
  vostok::render::res_texture *v112; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v113; // edi
  vostok::render::stage_postprocess *v114; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v115; // ecx
  vostok::render::res_texture *v116; // esi
  const char *v117; // edi
  vostok::render::textures_handler<0> *v118; // ecx
  vostok::render::res_texture *v119; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v120; // edi
  vostok::render::stage_postprocess *v121; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v122; // ecx
  vostok::render::res_texture *v123; // esi
  const char *v124; // edi
  vostok::render::textures_handler<0> *v125; // ecx
  vostok::render::res_texture *v126; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v127; // edi
  vostok::render::stage_postprocess *v128; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v129; // ecx
  vostok::render::res_texture *v130; // esi
  const char *v131; // edi
  vostok::render::textures_handler<0> *v132; // ecx
  vostok::render::res_texture *v133; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v134; // edi
  vostok::render::stage_postprocess *v135; // ecx
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v136; // ecx
  vostok::render::res_texture *v137; // esi
  const char *v138; // edi
  vostok::render::textures_handler<0> *v139; // ecx
  vostok::render::res_texture *v140; // ecx
  const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v141; // edi
  vostok::render::stage_postprocess *v142; // ecx
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v143; // [esp+D4h] [ebp-48h] BYREF
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v144; // [esp+D8h] [ebp-44h] BYREF
  vostok::render::stage_postprocess *v145[4]; // [esp+DCh] [ebp-40h]
  vostok::render::res_texture *t1[4]; // [esp+ECh] [ebp-30h] BYREF
  char src_ptr[16]; // [esp+FCh] [ebp-20h] BYREF
  __int128 v148; // [esp+10Ch] [ebp-10h]

  m_context = (vostok::render::res_texture *)thisa->m_context;
  v3 = *(_DWORD *)(*(_DWORD *)&m_context[27].m_name.m_string.m_buffer[248] + 344);
  if ( v3 )
  {
    v145[3] = *(vostok::render::stage_postprocess **)(*(_DWORD *)&m_context[27].m_name.m_string.m_buffer[248] + 344);
    if ( v3 > 7 )
      v145[3] = (vostok::render::stage_postprocess *)7;
  }
  else
  {
    v145[3] = 0;
  }
  v4 = m_context->__vftable[1239].~vostok::render::res_texture;
  v5 = 0;
  if ( v4 )
  {
    v5 = (const vostok::render::res_texture *)m_context->__vftable[1239].~vostok::render::res_texture;
    ++*((_DWORD *)v4 + 1);
  }
  *(float *)t1 = (float)v5->m_desc.Width;
  if ( !--v5->m_reference_count )
    vostok::render::res_texture::destroy_impl(m_context, v5);
  m_object = thisa->m_context->m_targets->m_family[30].texture.m_object;
  v7 = 0;
  if ( m_object )
  {
    v7 = thisa->m_context->m_targets->m_family[30].texture.m_object;
    ++m_object->m_reference_count;
  }
  Height = (vostok::render::res_texture *)v7->m_desc.Height;
  --v7->m_reference_count;
  *(float *)&t1[1] = (float)(unsigned int)Height;
  if ( !v7->m_reference_count )
    vostok::render::res_texture::destroy_impl(Height, v7);
  v9 = thisa->m_context->m_targets->m_family[30].texture.m_object;
  v10 = 0;
  if ( v9 )
  {
    v10 = thisa->m_context->m_targets->m_family[30].texture.m_object;
    ++v9->m_reference_count;
  }
  Width = (double)v10->m_desc.Width;
  v12 = --v10->m_reference_count == 0;
  *(float *)&t1[2] = 1.0 / Width;
  if ( v12 )
    vostok::render::res_texture::destroy_impl(Height, v10);
  v13 = thisa->m_context->m_targets->m_family[30].texture.m_object;
  v14 = 0;
  if ( v13 )
  {
    v14 = thisa->m_context->m_targets->m_family[30].texture.m_object;
    ++v13->m_reference_count;
  }
  v15 = (double)v14->m_desc.Height;
  v12 = --v14->m_reference_count == 0;
  *(float *)&t1[3] = 1.0 / v15;
  if ( v12 )
    vostok::render::res_texture::destroy_impl(Height, v14);
  v16 = &thisa->m_sh_blur[0].m_object->__vftable;
  v17 = (v16[71] - v16[70]) >> 2;
  if ( v17 > 3 )
  {
    v16[69] = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v17, (unsigned int)v145[0]);
  }
  v18 = thisa->m_context->m_targets->m_family[32].texture.m_object;
  v19 = 0;
  if ( v18 )
  {
    v19 = thisa->m_context->m_targets->m_family[32].texture.m_object;
    ++v18->m_reference_count;
  }
  m_conflicted_key_name = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)m_conflicted_key_name + 159) = vostok::render::textures_handler<0>::set_overwrite(
                                              (vostok::render::textures_handler<0> *)v17,
                                              (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                            + 1488,
                                              (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                                              v19);
  if ( v19 )
  {
    if ( !--v19->m_reference_count )
      vostok::render::res_texture::destroy_impl(v21, v19);
  }
  v22 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  m_blur_target_size_parameter = thisa->m_blur_target_size_parameter;
  m_buffer_index = (vostok::render::render_target *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                    + 573);
  *(vostok::render::res_texture **)src_ptr = t1[0];
  *(vostok::render::res_texture **)&src_ptr[4] = t1[1];
  *(vostok::render::res_texture **)&src_ptr[8] = t1[2];
  *(vostok::render::res_texture **)&src_ptr[12] = t1[3];
  if ( (vostok::render::render_target *)m_blur_target_size_parameter->m_update_markers[1] == m_buffer_index )
  {
    m_buffer_index = (vostok::render::render_target *)m_blur_target_size_parameter->m_shader_slots[1].m_buffer_index;
    if ( (unsigned __int16)m_buffer_index != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        m_blur_target_size_parameter->m_shader_slots[1].m_slot_index,
        (unsigned __int8)m_blur_target_size_parameter->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * (unsigned __int16)m_buffer_index),
        src_ptr);
  }
  v144.m_object = m_buffer_index;
  ++*((_DWORD *)v22 + 23);
  v144.m_object = 0;
  m_targets = thisa->m_context->m_targets;
  v143.m_object = 0;
  v26 = m_targets->m_family[34].target.m_object;
  if ( v26 )
  {
    v143.m_object = v26;
    ++v26->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface((vostok::render::stage_postprocess *)&v143, thisa, v143, v144);
  y = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  *(_OWORD *)src_ptr = 0;
  v148 = 0;
  (*(void (__stdcall **)(int, int, char *, _DWORD))(*(_DWORD *)y + 132))(y, 8, src_ptr, 0);
  v28 = &thisa->m_sh_blur[0].m_object->__vftable;
  v29 = (v28[71] - v28[70]) >> 2;
  if ( v29 > 3 )
  {
    v28[69] = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v29, (unsigned int)v145[0]);
  }
  v30 = thisa->m_context->m_targets->m_family[34].texture.m_object;
  v31 = 0;
  if ( v30 )
  {
    v31 = thisa->m_context->m_targets->m_family[34].texture.m_object;
    ++v30->m_reference_count;
  }
  v32 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v32 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)v29,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                            v31);
  if ( v31 )
  {
    if ( !--v31->m_reference_count )
      vostok::render::res_texture::destroy_impl(v33, v31);
  }
  v34 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v35 = thisa->m_blur_target_size_parameter;
  v36 = (vostok::render::render_target *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                         + 573);
  *(float *)src_ptr = *(float *)t1 * 0.5;
  *(float *)&src_ptr[4] = *(float *)&t1[1] * 0.5;
  *(float *)&src_ptr[8] = *(float *)&t1[2] * 2.0;
  *(float *)&src_ptr[12] = *(float *)&t1[3] * 2.0;
  if ( (vostok::render::render_target *)v35->m_update_markers[1] == v36 )
  {
    v36 = (vostok::render::render_target *)v35->m_shader_slots[1].m_buffer_index;
    if ( (unsigned __int16)v36 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        v35->m_shader_slots[1].m_slot_index,
        (unsigned __int8)v35->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * (unsigned __int16)v36),
        src_ptr);
  }
  v144.m_object = v36;
  ++*((_DWORD *)v34 + 23);
  v144.m_object = 0;
  v37 = thisa->m_context->m_targets;
  v143.m_object = 0;
  v38 = v37->m_family[36].target.m_object;
  if ( v38 )
  {
    v143.m_object = v38;
    ++v38->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface((vostok::render::stage_postprocess *)&v143, thisa, v143, v144);
  v39 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  *(_OWORD *)src_ptr = 0;
  v148 = 0;
  (*(void (__stdcall **)(int, int, char *, _DWORD))(*(_DWORD *)v39 + 132))(v39, 8, src_ptr, 0);
  v40 = &thisa->m_sh_blur[0].m_object->__vftable;
  v41 = (v40[71] - v40[70]) >> 2;
  if ( v41 > 3 )
  {
    v40[69] = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v41, (unsigned int)v145[0]);
  }
  v42 = thisa->m_context->m_targets->m_family[36].texture.m_object;
  v43 = 0;
  if ( v42 )
  {
    v43 = thisa->m_context->m_targets->m_family[36].texture.m_object;
    ++v42->m_reference_count;
  }
  v44 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v44 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)v41,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                            v43);
  if ( v43 )
  {
    if ( !--v43->m_reference_count )
      vostok::render::res_texture::destroy_impl(v45, v43);
  }
  v46 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v47 = thisa->m_blur_target_size_parameter;
  v48 = (vostok::render::render_target *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                         + 573);
  *(float *)src_ptr = *(float *)t1 * 0.25;
  *(float *)&src_ptr[4] = *(float *)&t1[1] * 0.25;
  *(float *)&src_ptr[8] = *(float *)&t1[2] * 4.0;
  *(float *)&src_ptr[12] = *(float *)&t1[3] * 4.0;
  if ( (vostok::render::render_target *)v47->m_update_markers[1] == v48 )
  {
    v48 = (vostok::render::render_target *)v47->m_shader_slots[1].m_buffer_index;
    if ( (unsigned __int16)v48 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        v47->m_shader_slots[1].m_slot_index,
        (unsigned __int8)v47->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * (unsigned __int16)v48),
        src_ptr);
  }
  v144.m_object = v48;
  ++*((_DWORD *)v46 + 23);
  v144.m_object = 0;
  v49 = thisa->m_context->m_targets;
  v143.m_object = 0;
  v50 = v49->m_family[38].target.m_object;
  if ( v50 )
  {
    v143.m_object = v50;
    ++v50->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface((vostok::render::stage_postprocess *)&v143, thisa, v143, v144);
  v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  *(_OWORD *)src_ptr = 0;
  v148 = 0;
  (*(void (__stdcall **)(int, int, char *, _DWORD))(*(_DWORD *)v51 + 132))(v51, 8, src_ptr, 0);
  v52 = &thisa->m_sh_blur[0].m_object->__vftable;
  v53 = (v52[71] - v52[70]) >> 2;
  if ( v53 > 3 )
  {
    v52[69] = 3;
    vostok::render::res_effect::apply_pass((vostok::render::res_effect *)v53, (unsigned int)v145[0]);
  }
  v54 = thisa->m_context->m_targets->m_family[38].texture.m_object;
  v55 = 0;
  if ( v54 )
  {
    v55 = thisa->m_context->m_targets->m_family[38].texture.m_object;
    ++v54->m_reference_count;
  }
  v56 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v56 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                            (vostok::render::textures_handler<0> *)v53,
                            (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                          + 1488,
                            (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                            v55);
  if ( v55 )
  {
    if ( !--v55->m_reference_count )
      vostok::render::res_texture::destroy_impl(v57, v55);
  }
  v58 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  v59 = thisa->m_blur_target_size_parameter;
  v60 = (vostok::render::render_target *)*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                         + 573);
  *(float *)src_ptr = *(float *)t1 * 0.125;
  *(float *)&src_ptr[4] = *(float *)&t1[1] * 0.125;
  *(float *)&src_ptr[8] = *(float *)&t1[2] * 8.0;
  *(float *)&src_ptr[12] = *(float *)&t1[3] * 8.0;
  if ( (vostok::render::render_target *)v59->m_update_markers[1] == v60 )
  {
    v60 = (vostok::render::render_target *)v59->m_shader_slots[1].m_buffer_index;
    if ( (unsigned __int16)v60 != 0xFFFF )
      vostok::render::shader_constant_buffer::set_memory(
        v59->m_shader_slots[1].m_slot_index,
        (unsigned __int8)v59->m_shader_slots[1].m_class_id,
        *(vostok::render::shader_constant_buffer **)(*(_DWORD *)(*((_DWORD *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                                                                 + 371)
                                                               + 16)
                                                   + 4 * (unsigned __int16)v60),
        src_ptr);
  }
  v144.m_object = v60;
  ++*((_DWORD *)v58 + 23);
  v144.m_object = 0;
  v61 = thisa->m_context->m_targets;
  v143.m_object = 0;
  v62 = v61->m_family[40].target.m_object;
  if ( v62 )
  {
    v143.m_object = v62;
    ++v62->m_reference_count;
  }
  vostok::render::stage_postprocess::fill_surface((vostok::render::stage_postprocess *)&v143, thisa, v143, v144);
  v63 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_game->m_game_world.m_mouse_pos.y;
  *(_OWORD *)src_ptr = 0;
  v148 = 0;
  (*(void (__stdcall **)(int, int, char *, _DWORD))(*(_DWORD *)v63 + 132))(v63, 8, src_ptr, 0);
  v64 = thisa->m_context->m_targets->m_family[33].texture.m_object;
  t1[2] = 0;
  if ( v64 )
  {
    ++v64->m_reference_count;
    t1[2] = v64;
  }
  v65 = (vostok::render::res_texture *)thisa->m_context->m_targets->m_family[33].target.m_object;
  t1[3] = 0;
  if ( v65 )
  {
    ++v65->__vftable;
    t1[3] = v65;
  }
  v66 = thisa->m_context->m_targets->m_family[32].texture.m_object;
  v67 = 0;
  if ( v66 )
  {
    v67 = thisa->m_context->m_targets->m_family[32].texture.m_object;
    ++v66->m_reference_count;
  }
  v68 = thisa->m_context->m_targets->m_family[32].target.m_object;
  v69 = 0;
  if ( v68 )
  {
    v69 = thisa->m_context->m_targets->m_family[32].target.m_object;
    ++v68->m_reference_count;
  }
  vostok::render::stage_postprocess::process_blur(
    v145[3],
    thisa,
    v69,
    v67,
    (vostok::render::render_target *)t1[3],
    t1[2],
    (unsigned int)v145[3]);
  if ( v69 )
  {
    if ( !--v69->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v69);
  }
  if ( v67 )
  {
    if ( !--v67->m_reference_count )
      vostok::render::res_texture::destroy_impl(v70, v67);
  }
  v71 = (const char *)t1[3];
  if ( t1[3] )
  {
    --t1[3]->__vftable;
    if ( !*(_DWORD *)v71 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v70,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v71);
  }
  v72 = t1[2];
  if ( t1[2] )
  {
    --t1[2]->m_reference_count;
    if ( !v72->m_reference_count )
      vostok::render::res_texture::destroy_impl(v70, v72);
  }
  v73 = thisa->m_context->m_targets->m_family[35].texture.m_object;
  v74 = 0;
  t1[3] = 0;
  if ( v73 )
  {
    ++v73->m_reference_count;
    t1[3] = v73;
  }
  v75 = (vostok::render::res_texture *)thisa->m_context->m_targets->m_family[35].target.m_object;
  t1[2] = 0;
  if ( v75 )
  {
    ++v75->__vftable;
    t1[2] = v75;
  }
  v76 = thisa->m_context->m_targets->m_family[34].texture.m_object;
  v77 = 0;
  if ( v76 )
  {
    v77 = thisa->m_context->m_targets->m_family[34].texture.m_object;
    ++v76->m_reference_count;
  }
  v78 = thisa->m_context->m_targets->m_family[34].target.m_object;
  if ( v78 )
  {
    v74 = thisa->m_context->m_targets->m_family[34].target.m_object;
    ++v78->m_reference_count;
  }
  vostok::render::stage_postprocess::process_blur(
    v145[3],
    thisa,
    v74,
    v77,
    (vostok::render::render_target *)t1[2],
    t1[3],
    (unsigned int)v145[3]);
  if ( v74 )
  {
    if ( !--v74->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v74);
  }
  if ( v77 )
  {
    if ( !--v77->m_reference_count )
      vostok::render::res_texture::destroy_impl(v79, v77);
  }
  v80 = (const char *)t1[2];
  if ( t1[2] )
  {
    --t1[2]->__vftable;
    if ( !*(_DWORD *)v80 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v79,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v80);
  }
  v81 = t1[3];
  if ( t1[3] )
  {
    --t1[3]->m_reference_count;
    if ( !v81->m_reference_count )
      vostok::render::res_texture::destroy_impl(v79, v81);
  }
  v82 = 0;
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[37].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v79,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v84 = (vostok::render::res_texture *)thisa->m_context->m_targets->m_family[37].target.m_object;
  t1[1] = 0;
  if ( v84 )
  {
    v82 = (vostok::render::render_target *)v84;
    ++v84->__vftable;
    t1[1] = v84;
  }
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[36].texture;
  t1[2] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v83,
    &t1[2],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v85 = thisa->m_context->m_targets->m_family[36].target.m_object;
  v86 = 0;
  if ( v85 )
  {
    v86 = thisa->m_context->m_targets->m_family[36].target.m_object;
    ++v85->m_reference_count;
  }
  vostok::render::stage_postprocess::process_blur(
    (vostok::render::stage_postprocess *)t1[3],
    thisa,
    v86,
    t1[2],
    v82,
    t1[3],
    (unsigned int)v145[3]);
  if ( v86 )
  {
    if ( !--v86->m_reference_count )
      vostok::render::resource_manager::release(
        v87,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v86);
  }
  v88 = t1[2];
  if ( t1[2] )
  {
    --t1[2]->m_reference_count;
    if ( !v88->m_reference_count )
    {
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v87, v88);
      v82 = (vostok::render::render_target *)t1[1];
    }
  }
  v89 = t1[3];
  if ( v82 )
  {
    if ( !--v82->m_reference_count )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (const char *)v82);
  }
  if ( v89 )
  {
    if ( !--v89->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v87, v89);
  }
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[39].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v87,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v91 = (vostok::render::res_texture *)thisa->m_context->m_targets->m_family[39].target.m_object;
  t1[2] = 0;
  if ( v91 )
  {
    ++v91->__vftable;
    t1[2] = v91;
  }
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[38].texture;
  t1[1] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v90,
    &t1[1],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v92 = (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)thisa->m_context->m_targets;
  t1[0] = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)t1,
    v92 + 1558);
  v93 = t1[1];
  v94 = (const char *)t1[0];
  vostok::render::stage_postprocess::process_blur(
    (vostok::render::stage_postprocess *)t1[2],
    thisa,
    (vostok::render::render_target *)t1[0],
    t1[1],
    (vostok::render::render_target *)t1[2],
    t1[3],
    (unsigned int)v145[3]);
  if ( v94 )
  {
    if ( !--*(_DWORD *)v94 )
      vostok::render::resource_manager::release(
        v95,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v94);
  }
  if ( v93 )
  {
    if ( !--v93->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v95, v93);
  }
  v96 = (const char *)t1[2];
  if ( t1[2] )
  {
    --t1[2]->__vftable;
    if ( !*(_DWORD *)v96 )
      vostok::render::resource_manager::release(
        v95,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v96);
  }
  v97 = t1[3];
  if ( t1[3] )
  {
    --t1[3]->m_reference_count;
    if ( !v97->m_reference_count )
      vostok::render::res_texture::destroy_impl((vostok::render::res_texture *)v95, v97);
  }
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[41].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v95,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v98 = (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)thisa->m_context->m_targets;
  t1[2] = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)&t1[2],
    v98 + 1678);
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[40].texture;
  t1[1] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v99,
    &t1[1],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v100 = (const vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)thisa->m_context->m_targets;
  t1[0] = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)t1,
    v100 + 1638);
  v101 = t1[1];
  v102 = (const char *)t1[0];
  vostok::render::stage_postprocess::process_blur(
    v145[3],
    thisa,
    (vostok::render::render_target *)t1[0],
    t1[1],
    (vostok::render::render_target *)t1[2],
    t1[3],
    (unsigned int)v145[3]);
  if ( v102 )
  {
    if ( !--*(_DWORD *)v102 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v102);
  }
  if ( v101 )
  {
    if ( !--v101->m_reference_count )
      vostok::render::res_texture::destroy_impl(v103, v101);
  }
  v104 = (const char *)t1[2];
  if ( t1[2] )
  {
    --t1[2]->__vftable;
    if ( !*(_DWORD *)v104 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)v103,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v104);
  }
  v105 = t1[3];
  if ( t1[3] )
  {
    --t1[3]->m_reference_count;
    if ( !v105->m_reference_count )
      vostok::render::res_texture::destroy_impl(v103, v105);
  }
  p_target = &thisa->m_context->m_targets->m_family[33].target;
  v144.m_object = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    &v144,
    p_target);
  vostok::render::stage_postprocess::clear_surface(v107, v144);
  vostok::render::res_effect::apply((vostok::render::res_effect *)4, &thisa->m_sh_blur[0].m_object->__vftable);
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[32].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v108,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v109 = t1[3];
  v110 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v110 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             v111,
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             t1[3]);
  if ( v109 )
  {
    if ( !--v109->m_reference_count )
      vostok::render::res_texture::destroy_impl(v112, v109);
  }
  v144.m_object = 0;
  v113 = &thisa->m_context->m_targets->m_family[33].target;
  v143.m_object = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    &v143,
    v113);
  vostok::render::stage_postprocess::fill_surface(v114, thisa, v143, v144);
  vostok::render::res_effect::apply((vostok::render::res_effect *)5, &thisa->m_sh_blur[0].m_object->__vftable);
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[34].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v115,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v116 = t1[3];
  v117 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v117 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             v118,
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             t1[3]);
  if ( v116 )
  {
    if ( !--v116->m_reference_count )
      vostok::render::res_texture::destroy_impl(v119, v116);
  }
  v144.m_object = 0;
  v120 = &thisa->m_context->m_targets->m_family[33].target;
  v143.m_object = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    &v143,
    v120);
  vostok::render::stage_postprocess::fill_surface(v121, thisa, v143, v144);
  vostok::render::res_effect::apply((vostok::render::res_effect *)5, &thisa->m_sh_blur[0].m_object->__vftable);
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[36].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v122,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v123 = t1[3];
  v124 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v124 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             v125,
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             t1[3]);
  if ( v123 )
  {
    if ( !--v123->m_reference_count )
      vostok::render::res_texture::destroy_impl(v126, v123);
  }
  v144.m_object = 0;
  v127 = &thisa->m_context->m_targets->m_family[33].target;
  v143.m_object = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    &v143,
    v127);
  vostok::render::stage_postprocess::fill_surface(v128, thisa, v143, v144);
  vostok::render::res_effect::apply((vostok::render::res_effect *)5, &thisa->m_sh_blur[0].m_object->__vftable);
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[38].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v129,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v130 = t1[3];
  v131 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v131 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             v132,
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             t1[3]);
  if ( v130 )
  {
    if ( !--v130->m_reference_count )
      vostok::render::res_texture::destroy_impl(v133, v130);
  }
  v144.m_object = 0;
  v134 = &thisa->m_context->m_targets->m_family[33].target;
  v143.m_object = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    &v143,
    v134);
  vostok::render::stage_postprocess::fill_surface(v135, thisa, v143, v144);
  vostok::render::res_effect::apply((vostok::render::res_effect *)5, &thisa->m_sh_blur[0].m_object->__vftable);
  v144.m_object = (vostok::render::render_target *)&thisa->m_context->m_targets->m_family[40].texture;
  t1[3] = 0;
  vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    v136,
    &t1[3],
    (const vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v144.m_object);
  v137 = t1[3];
  v138 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name;
  *((_BYTE *)v138 + 159) = vostok::render::textures_handler<0>::set_overwrite(
                             v139,
                             (char *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
                           + 1488,
                             (vostok::render::res_texture *)&stru_963F84.m_name.m_string.m_buffer[116],
                             t1[3]);
  if ( v137 )
  {
    if ( !--v137->m_reference_count )
      vostok::render::res_texture::destroy_impl(v140, v137);
  }
  v144.m_object = 0;
  v141 = &thisa->m_context->m_targets->m_family[33].target;
  v143.m_object = 0;
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::set(
    &v143,
    v141);
  vostok::render::stage_postprocess::fill_surface(v142, thisa, v143, v144);
}
