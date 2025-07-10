void __fastcall vostok::render::system_renderer::system_renderer(
        int a1,
        vostok::render::renderer_context *renderer_context,
        vostok::render::system_renderer *this)
{
  char v3; // cl
  vostok::render::system_renderer *v4; // ebx
  vostok::render::map<vostok::render::render_model_instance *,vostok::render::material_effects,stlp_std::less<vostok::render::render_model_instance *> > *p_m_render_model_to_material; // eax
  vostok::render::system_renderer *v6; // ecx
  vostok::render::untyped_buffer *quad_ib; // eax
  vostok::render::res_state **p_m_quad_ib; // ecx
  vostok::render::untyped_buffer *v9; // edx
  vostok::render::res_state *v10; // eax
  bool v11; // zf
  vostok::render::res_geometry *geometry; // eax
  vostok::render::res_geometry **p_m_object; // ecx
  vostok::render::res_geometry *v14; // edx
  vostok::render::res_geometry *v15; // eax
  vostok::render::res_geometry *v16; // eax
  vostok::render::res_geometry **v17; // ecx
  vostok::render::res_geometry *v18; // edx
  vostok::render::res_geometry *v19; // eax
  vostok::render::res_geometry *v20; // eax
  vostok::render::res_geometry **v21; // ecx
  vostok::render::res_geometry *v22; // edx
  vostok::render::res_geometry *v23; // eax
  vostok::render::res_geometry *v24; // eax
  vostok::render::res_geometry *v25; // ecx
  vostok::render::res_geometry *m_object; // eax
  vostok::render::res_geometry *v27; // eax
  vostok::render::res_geometry *v28; // ecx
  vostok::render::res_geometry *v29; // eax
  vostok::render::effect_manager *m_conflicted_action_to_bind; // ecx
  const vostok::math::float4x4 *v31; // xmm1_4
  __int64 v32; // xmm2_8
  __int64 v33; // xmm0_8
  vostok::strings::shared::manager *v34; // ecx
  vostok::render::system_renderer *v35; // eax
  vostok::render::backend *v36; // ecx
  void *(__thiscall *v37)(void *); // esi
  vostok::render::res_geometry *v38; // eax
  vostok::render::res_geometry *v39; // ecx
  vostok::render::res_geometry *v40; // eax
  void *v41; // esp
  vostok::render::effect_options_descriptor *v42; // eax
  vostok::render::effect_options_descriptor *v43; // ecx
  vostok::render::effect_options_descriptor *v44; // eax
  vostok::strings::shared::manager *v45; // ecx
  vostok::render::system_renderer *v46; // eax
  vostok::render::backend *v47; // ecx
  volatile signed __int32 *v48; // esi
  vostok::strings::shared::manager *v49; // ecx
  vostok::strings::shared::profile *v50; // eax
  volatile signed __int32 *p_m_reference_count; // esi
  vostok::strings::shared::manager *bytes; // ecx
  vostok::render::effect_options_descriptor *v53; // esi
  vostok::render::effect_options_descriptor *v54; // eax
  vostok::strings::shared::manager *v55; // ecx
  vostok::render::system_renderer *v56; // eax
  vostok::render::backend *v57; // ecx
  volatile signed __int32 *v58; // esi
  _DWORD *v59; // eax
  vostok::render::untyped_buffer *buffer; // eax
  vostok::render::untyped_buffer *v61; // ecx
  const vostok::render::res_state *v62; // edx
  survarium::options_tab *v63; // edi
  vostok::render::system_renderer *v64; // esi
  vostok::render::untyped_buffer *v65; // eax
  vostok::render::grass_render_model *v66; // edi
  vostok::render::system_renderer *v67; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::res_geometry *v69; // eax
  vostok::render::res_geometry *v70; // ecx
  vostok::render::res_geometry *v71; // eax
  int v72; // [esp-3E8h] [ebp-85Ch] BYREF
  char *m_editor_selection_shader; // [esp-10h] [ebp-484h]
  unsigned int v74; // [esp-Ch] [ebp-480h]
  int v75; // [esp-8h] [ebp-47Ch]
  void *(__thiscall *v76)(void *); // [esp-4h] [ebp-478h]
  unsigned __int8 data[1024]; // [esp+10h] [ebp-464h] BYREF
  D3D11_INPUT_ELEMENT_DESC screen_vertex_layout[2]; // [esp+414h] [ebp-60h] BYREF
  unsigned __int16 indices[6]; // [esp+44Ch] [ebp-28h] BYREF
  vostok::render::effect_options_descriptor desc; // [esp+458h] [ebp-1Ch] BYREF

  v3 = HIBYTE(this);
  v4 = this;
  p_m_render_model_to_material = &this->m_render_model_to_material;
  this->m_screen_vertex_ib.m_object = 0;
  v4->m_screen_vertex_geometry.m_object = 0;
  *(_QWORD *)&p_m_render_model_to_material->_M_t._M_header._M_data._M_color = 0;
  *(_QWORD *)&p_m_render_model_to_material->_M_t._M_header._M_data._M_left = 0;
  p_m_render_model_to_material->_M_t._M_header._M_data._M_color = 0;
  p_m_render_model_to_material->_M_t._M_header._M_data._M_parent = 0;
  p_m_render_model_to_material->_M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)p_m_render_model_to_material;
  p_m_render_model_to_material->_M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)p_m_render_model_to_material;
  p_m_render_model_to_material->_M_t._M_node_count = 0;
  p_m_render_model_to_material->_M_t._M_key_compare.gap0 = v3;
  v4->m_renderer_context = renderer_context;
  v4->m_sh_sl.m_object = 0;
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_mouse_pos.x = (int)v4;
  v4->m_colored_geom_sl.m_object = 0;
  vostok::render::vertex_buffer::vertex_buffer(&v4->m_vertex_stream, 0x100000u);
  vostok::render::index_buffer::index_buffer(&v4->m_index_stream, 0x100000u);
  vostok::render::vertex_buffer::vertex_buffer(&v4->m_vertex_stream_quad, 0x400u);
  vostok::render::index_buffer::index_buffer(&v4->m_index_stream_quad, 0x400u);
  v4->m_sh_particle_selection.m_object = 0;
  v76 = (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>;
  v4->m_sh_vcolor.m_object = 0;
  v75 = 15;
  v4->m_sh_grid_25.m_object = 0;
  v4->m_sh_grid_50.m_object = 0;
  v74 = 4;
  v4->m_sh_ui.m_object = 0;
  m_editor_selection_shader = (char *)v4->m_editor_selection_shader;
  v4->m_notexture_shader.m_object = 0;
  `vector constructor iterator'(m_editor_selection_shader, v74, v75, v76);
  v4->m_speedtree_selection_shader.m_object = 0;
  v4->m_editor_model_ghost_shader.m_object = 0;
  v76 = (void *(__thiscall *)(void *))vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>;
  v4->m_colored_geom.m_object = 0;
  v75 = 2;
  v4->m_grid_geom.m_object = 0;
  v4->m_ui_geom.m_object = 0;
  v74 = 4;
  v4->m_grid_texture_25.m_object = 0;
  m_editor_selection_shader = (char *)v4->m_rotation_mode_states;
  v4->m_grid_texture_50.m_object = 0;
  `vector constructor iterator'(m_editor_selection_shader, v74, v75, v76);
  v4->m_grid_mode = 0;
  v4->m_color_write = 1;
  quad_ib = vostok::render::system_renderer::create_quad_ib(v6);
  p_m_quad_ib = (vostok::render::res_state **)&v4->m_renderer_context->m_quad_ib;
  v9 = 0;
  if ( quad_ib )
  {
    ++quad_ib->m_reference_count;
    v9 = quad_ib;
  }
  v10 = *p_m_quad_ib;
  *p_m_quad_ib = (vostok::render::res_state *)v9;
  if ( v10 )
  {
    v11 = v10->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        v10,
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  }
  geometry = vostok::render::resource_manager::create_geometry(
               (stlp_std::forward_iterator_tag *)F_TL,
               (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
               3u,
               0x1Cu,
               *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
               + 10),
               v4->m_renderer_context->m_quad_ib.m_object);
  p_m_object = &v4->m_renderer_context->m_g_quad_uv.m_object;
  v14 = 0;
  if ( geometry )
  {
    ++geometry->m_reference_count;
    v14 = geometry;
  }
  v15 = *p_m_object;
  *p_m_object = v14;
  if ( v15 )
  {
    v11 = v15->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v15);
  }
  v16 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)F_TL2uv,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          4u,
          0x24u,
          *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
          + 10),
          v4->m_renderer_context->m_quad_ib.m_object);
  v17 = &v4->m_renderer_context->m_g_quad_2uv.m_object;
  v18 = 0;
  if ( v16 )
  {
    ++v16->m_reference_count;
    v18 = v16;
  }
  v19 = *v17;
  *v17 = v18;
  if ( v19 )
  {
    v11 = v19->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v19);
  }
  v20 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)F_Tquad,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          3u,
          0x24u,
          *((vostok::render::untyped_buffer **)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name
          + 10),
          v4->m_renderer_context->m_quad_ib.m_object);
  v21 = &v4->m_renderer_context->m_g_quad_eye_ray.m_object;
  v22 = 0;
  if ( v20 )
  {
    ++v20->m_reference_count;
    v22 = v20;
  }
  v23 = *v21;
  *v21 = v22;
  if ( v23 )
  {
    v11 = v23->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v23);
  }
  v24 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)F_L,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          2u,
          0x10u,
          v4->m_vertex_stream.m_buffer.m_object,
          v4->m_index_stream.m_buffer.m_object);
  v25 = 0;
  if ( v24 )
  {
    ++v24->m_reference_count;
    v25 = v24;
  }
  m_object = v4->m_colored_geom.m_object;
  v4->m_colored_geom.m_object = v25;
  if ( m_object )
  {
    v11 = m_object->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        m_object);
  }
  v27 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)F_L_sl,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          5u,
          0x24u,
          v4->m_vertex_stream.m_buffer.m_object,
          v4->m_index_stream.m_buffer.m_object);
  v28 = 0;
  if ( v27 )
  {
    ++v27->m_reference_count;
    v28 = v27;
  }
  v29 = v4->m_colored_geom_sl.m_object;
  v4->m_colored_geom_sl.m_object = v28;
  if ( v29 )
  {
    v11 = v29->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v29);
  }
  m_conflicted_action_to_bind = (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind;
  *(_QWORD *)&desc.data = 0;
  *(_QWORD *)&desc.type = __PAIR64__((unsigned int)clear_value, LODWORD(FLOAT_0_5));
  v31 = clear_value;
  *(_QWORD *)&v4->m_selection_color.x = 0;
  v32 = *(_QWORD *)&desc.type;
  *(_QWORD *)&desc.type = 0;
  *(_QWORD *)&v4->m_current_selection_color.x = *(_QWORD *)&desc.data;
  *(_QWORD *)&v4->m_current_selection_color.elements[2] = *(_QWORD *)&desc.type;
  *(_QWORD *)&desc.data = 0x3E4CCCCD3E4CCCCDLL;
  *(_QWORD *)&desc.type = 0x3E4CCCCD3E4CCCCDLL;
  *(_QWORD *)&v4->m_ghost_model_color.x = 0x3E4CCCCD3E4CCCCDLL;
  v33 = *(_QWORD *)&desc.type;
  *(_QWORD *)&v4->m_selection_color.elements[2] = v32;
  LODWORD(v4->m_selection_rate) = v31;
  *(_QWORD *)&v4->m_ghost_model_color.elements[2] = v33;
  vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>(
    m_conflicted_action_to_bind,
    &v4->m_sh_vcolor);
  vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v4->m_sh_sl);
  v76 = (void *(__thiscall *)(void *))"grid_density";
  v35 = (vostok::render::system_renderer *)vostok::strings::shared::manager::string(
                                             v34,
                                             (const char *)s_manager.m_variable);
  v37 = 0;
  this = 0;
  if ( v35 )
  {
    v37 = (void *(__thiscall *)(void *))v35;
    this = v35;
    v36 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v35, 1u);
  }
  v4->m_grid_density_constant = vostok::render::backend::register_constant_host(
                                  v36,
                                  (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                                  (const vostok::shared_string *)&this,
                                  rc_float);
  if ( v37 && !_InterlockedExchangeAdd((volatile signed __int32 *)v37, 0xFFFFFFFF) )
  {
    v76 = v37;
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v38 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)F_TL,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          3u,
          0x1Cu,
          v4->m_vertex_stream.m_buffer.m_object,
          v4->m_renderer_context->m_quad_ib.m_object);
  v39 = 0;
  if ( v38 )
  {
    ++v38->m_reference_count;
    v39 = v38;
  }
  v40 = v4->m_ui_geom.m_object;
  v4->m_ui_geom.m_object = v39;
  if ( v40 )
  {
    v11 = v40->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v40);
  }
  v41 = alloca(1024);
  desc.data = (unsigned __int8 *)&v72;
  desc.bytes = 0;
  desc.id = 0;
  desc.destroyer = 0;
  desc.type = 3;
  desc.count = 0;
  desc.memory_size = 1024;
  v42 = vostok::render::effect_options_descriptor::operator[](
          (vostok::render::effect_options_descriptor *)0x400,
          (int)&desc,
          "ui_texture0");
  vostok::render::effect_options_descriptor::operator=<char const *>(v42, "ui/ui_font_arial_21_1024");
  v44 = vostok::render::effect_options_descriptor::operator[](v43, (int)&desc, "ui_texture1");
  vostok::render::effect_options_descriptor::operator=<char const *>(v44, "ui/ui_skull");
  vostok::render::effect_manager::create_effect<vostok::render::effect_system_ui>(
    (vostok::render::effect_options_descriptor *)&v4->m_sh_ui,
    &desc,
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
  v46 = (vostok::render::system_renderer *)vostok::strings::shared::manager::string(
                                             v45,
                                             (const char *)s_manager.m_variable);
  v48 = 0;
  this = 0;
  if ( v46 )
  {
    v48 = (volatile signed __int32 *)v46;
    this = v46;
    v47 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v46, 1u);
  }
  v4->m_WVP_sl = vostok::render::backend::register_constant_host(
                   v47,
                   (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                   (const vostok::shared_string *)&this,
                   rc_float);
  if ( v48 )
  {
    v49 = (vostok::strings::shared::manager *)_InterlockedExchangeAdd(v48, 0xFFFFFFFF);
    if ( !v49 )
      vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  v50 = vostok::strings::shared::manager::string(v49, (const char *)s_manager.m_variable);
  p_m_reference_count = 0;
  if ( v50 )
  {
    p_m_reference_count = &v50->m_reference_count;
    _InterlockedExchangeAdd(&v50->m_reference_count, 1u);
  }
  desc.destroyer = &v4->m_current_selection_color;
  desc.data = (unsigned __int8 *)16;
  desc.bytes = 0;
  if ( p_m_reference_count )
  {
    desc.bytes = (unsigned int)p_m_reference_count;
    _InterlockedExchangeAdd(p_m_reference_count, 1u);
  }
  *(_DWORD *)&desc.memory_size = 16;
  *(_DWORD *)&desc.type = 0;
  vostok::render::resource_manager::register_constant_binding(
    (const vostok::render::shader_constant_binding *)&desc.destroyer,
    (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
  if ( desc.bytes )
  {
    bytes = (vostok::strings::shared::manager *)desc.bytes;
    if ( !_InterlockedExchangeAdd((volatile signed __int32 *)desc.bytes, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(bytes, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  if ( p_m_reference_count && !_InterlockedExchangeAdd(p_m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(
      (vostok::strings::shared::manager *)p_m_reference_count,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v4->m_notexture_shader);
  vostok::render::effect_manager::create_effect<vostok::render::effect_speedtree_selection>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v4->m_speedtree_selection_shader);
  v53 = 0;
  this = (vostok::render::system_renderer *)v4->m_editor_selection_shader;
  do
  {
    if ( v53 != (vostok::render::effect_options_descriptor *)12 )
    {
      desc.data = &data[24];
      desc.bytes = 0;
      desc.id = 0;
      desc.destroyer = 0;
      desc.type = 3;
      desc.count = 0;
      desc.memory_size = 1024;
      v54 = vostok::render::effect_options_descriptor::operator[](
              (vostok::render::effect_options_descriptor *)0x400,
              (int)&desc,
              (const char *)&key);
      vostok::render::effect_options_descriptor::operator=<enum vostok::render::enum_vertex_input_type>(v53, v54);
      vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>(
        (vostok::render::effect_options_descriptor *)this,
        &desc,
        (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
    }
    this = (vostok::render::system_renderer *)((char *)this + 4);
    v53 = (vostok::render::effect_options_descriptor *)((char *)v53 + 1);
  }
  while ( (unsigned int)v53 < 0xF );
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_model_ghost>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v4->m_editor_model_ghost_shader);
  vostok::render::effect_manager::create_effect<vostok::render::effect_particle_selection>(
    (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
    &v4->m_sh_particle_selection);
  v56 = (vostok::render::system_renderer *)vostok::strings::shared::manager::string(
                                             v55,
                                             (const char *)s_manager.m_variable);
  v58 = 0;
  this = 0;
  if ( v56 )
  {
    v58 = (volatile signed __int32 *)v56;
    this = v56;
    v57 = (vostok::render::backend *)_InterlockedExchangeAdd((volatile signed __int32 *)v56, 1u);
  }
  v4->m_c_start_corner = vostok::render::backend::register_constant_host(
                           v57,
                           (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_key_name,
                           (const vostok::shared_string *)&this,
                           rc_float);
  if ( v58 && !_InterlockedExchangeAdd(v58, 0xFFFFFFFF) )
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  v59 = pt3malloc(0x10u);
  if ( v59 )
  {
    *v59 = 12;
    v59[1] = 0;
    v59[2] = 2;
    *((_BYTE *)v59 + 12) = 0;
  }
  else
  {
    v59 = 0;
  }
  v4->m_cook_data_to_delete = (vostok::render::material_effects_instance_cook_data *)v59;
  indices[0] = 0;
  indices[1] = 1;
  indices[2] = 2;
  indices[3] = 3;
  indices[4] = 2;
  screen_vertex_layout[0].SemanticName = "POSITION";
  screen_vertex_layout[0].SemanticIndex = 0;
  screen_vertex_layout[0].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  screen_vertex_layout[0].InputSlot = 0;
  screen_vertex_layout[0].AlignedByteOffset = 0;
  screen_vertex_layout[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[0].InstanceDataStepRate = 0;
  screen_vertex_layout[1].SemanticName = "TEXCOORD";
  screen_vertex_layout[1].SemanticIndex = 0;
  screen_vertex_layout[1].Format = DXGI_FORMAT_R32G32_FLOAT;
  screen_vertex_layout[1].InputSlot = 0;
  screen_vertex_layout[1].AlignedByteOffset = 16;
  screen_vertex_layout[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
  screen_vertex_layout[1].InstanceDataStepRate = 0;
  indices[5] = 1;
  buffer = vostok::render::resource_manager::create_buffer(
             0xCu,
             0,
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             indices,
             enum_buffer_type_index,
             0,
             0);
  v61 = 0;
  if ( buffer )
  {
    ++buffer->m_reference_count;
    v61 = buffer;
  }
  this = (vostok::render::system_renderer *)v4->m_screen_vertex_ib.m_object;
  v62 = (const vostok::render::res_state *)this;
  v4->m_screen_vertex_ib.m_object = v61;
  if ( v62 )
  {
    v11 = v62->m_reference_count-- == 1;
    if ( v11 )
    {
      v63 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3];
      if ( vostok::render::reclaim<vostok::render::untyped_buffer>(
             (vostok::render::vector<vostok::render::res_state *> *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][10].m_game,
             v62) )
      {
        v64 = this;
        v63[2].m_options = (survarium::options_item_base **)((char *)v63[2].m_options
                                                           - (unsigned int)this->m_screen_vertex_geometry.m_object);
        v65 = v64->m_screen_vertex_ib.m_object;
        v66 = vostok::render::g_allocator.m_object;
        if ( v65 )
        {
          (*(void (__stdcall **)(vostok::render::untyped_buffer *))(v65->m_reference_count + 8))(v64->m_screen_vertex_ib.m_object);
          v64->m_screen_vertex_ib.m_object = 0;
        }
        v67 = v64;
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(v66->m_reconstruction_info_actuality_tick);
        BYTE2(v66->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v67);
      }
    }
  }
  v69 = vostok::render::resource_manager::create_geometry(
          (stlp_std::forward_iterator_tag *)screen_vertex_layout,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          2u,
          0x18u,
          v4->m_vertex_stream_quad.m_buffer.m_object,
          v4->m_screen_vertex_ib.m_object);
  v70 = 0;
  if ( v69 )
  {
    ++v69->m_reference_count;
    v70 = v69;
  }
  v71 = v4->m_screen_vertex_geometry.m_object;
  v4->m_screen_vertex_geometry.m_object = v70;
  if ( v71 )
  {
    v11 = v71->m_reference_count-- == 1;
    if ( v11 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v71);
  }
}
