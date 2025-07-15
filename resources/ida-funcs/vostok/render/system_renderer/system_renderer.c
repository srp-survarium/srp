void __thiscall vostok::render::system_renderer::system_renderer(
        vostok::render::system_renderer *this,
        vostok::render::system_renderer *renderer_context)
{
  char v2; // al
  vostok::render::untyped_buffer *m_object; // ecx
  vostok::render::res_geometry *geometry; // eax
  vostok::render::resource_manager *v5; // ecx
  vostok::render::res_geometry *v6; // eax
  float v7; // xmm1_4
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v8; // esi
  vostok::render::effect_manager *v9; // ecx
  vostok::render::effect_manager *v10; // ecx
  vostok::render::effect_manager *v11; // ecx
  vostok::render::effect_manager *v12; // ecx
  vostok::shared_string *v13; // ecx
  vostok::render::backend *v14; // ecx
  vostok::render::res_geometry *v15; // eax
  vostok::render::effect_manager *v16; // ecx
  vostok::shared_string *v17; // ecx
  vostok::render::backend *v18; // ecx
  vostok::shared_string *v19; // ecx
  vostok::render::resource_manager *v20; // esi
  const vostok::render::shader_constant_binding *v21; // eax
  vostok::render::effect_manager *v22; // ecx
  vostok::render::effect_manager *v23; // ecx
  vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *v24; // edi
  bool v25; // zf
  vostok::render::effect_descriptor *new_effect; // eax
  vostok::render::effect_manager *v27; // ecx
  vostok::shared_string *v28; // ecx
  vostok::render::backend *v29; // ecx
  char *v30; // eax
  vostok::memory::pthreads3_allocator *v31; // ecx
  survarium::pure_game_effect_emitter_base *v32; // ecx
  vostok::render::material_effects_instance_cook_data *v33; // eax
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v34; // eax
  vostok::render::resource_manager *v35; // ecx
  vostok::render::res_geometry *v36; // eax
  vostok::render::res_declaration *v37; // [esp-18h] [ebp-A0h]
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v38; // [esp-8h] [ebp-90h] BYREF
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *p_m_sh_vcolor; // [esp-4h] [ebp-8Ch]
  vostok::strings::shared::profile *v40; // [esp+0h] [ebp-88h]
  unsigned int v41; // [esp+4h] [ebp-84h]
  char v42; // [esp+13h] [ebp-75h]
  vostok::shared_string name; // [esp+14h] [ebp-74h] BYREF
  vostok::shared_string v44; // [esp+18h] [ebp-70h] BYREF
  vostok::render::surface_effect_parameters parameters; // [esp+1Ch] [ebp-6Ch] BYREF
  __int16 v46; // [esp+2Ch] [ebp-5Ch]
  __int16 v47; // [esp+2Eh] [ebp-5Ah]
  vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator v48; // [esp+30h] [ebp-58h] BYREF
  vostok::render::shader_constant_binding v49; // [esp+3Ch] [ebp-4Ch] BYREF
  D3D11_INPUT_ELEMENT_DESC decl_size; // [esp+50h] [ebp-38h] BYREF
  const char *v51; // [esp+6Ch] [ebp-1Ch]
  int v52; // [esp+70h] [ebp-18h]
  int v53; // [esp+74h] [ebp-14h]
  int v54; // [esp+78h] [ebp-10h]
  int v55; // [esp+7Ch] [ebp-Ch]
  int v56; // [esp+80h] [ebp-8h]
  int v57; // [esp+84h] [ebp-4h]

  memset(&v49, 0, 12);
  renderer_context->m_screen_vertex_ib.m_object = 0;
  renderer_context->m_screen_vertex_geometry.m_object = 0;
  v49.m_type = rc_float;
  v2 = v42;
  *(_DWORD *)&renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_color = v49.m_source.m_pointer;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_parent = (stlp_std::priv::_Rb_tree_node_base *)v49.m_source.m_size;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)v49.m_name.m_pointer.m_object;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)v49.m_type;
  renderer_context->m_render_model_to_material._M_t._M_key_compare.gap0 = v2;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_color = 0;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_parent = 0;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_left = &renderer_context->m_render_model_to_material._M_t._M_header._M_data;
  renderer_context->m_render_model_to_material._M_t._M_header._M_data._M_right = &renderer_context->m_render_model_to_material._M_t._M_header._M_data;
  renderer_context->m_render_model_to_material._M_t._M_node_count = 0;
  renderer_context->m_renderer_context = (vostok::render::renderer_context *)&s_system_renderer_buffer.m_family[2].name;
  renderer_context->m_sh_sl.m_object = 0;
  renderer_context->m_add_border_padding_effect.m_object = 0;
  renderer_context->m_block_compression_effect.m_object = 0;
  vostok::quasi_singleton<vostok::render::system_renderer>::pinst = renderer_context;
  renderer_context->m_colored_geom_sl.m_object = 0;
  vostok::render::vertex_buffer::vertex_buffer(&renderer_context->m_vertex_stream, (unsigned int)&loc_100000);
  vostok::render::index_buffer::index_buffer(&renderer_context->m_index_stream, (unsigned int)&loc_100000);
  vostok::render::vertex_buffer::vertex_buffer(&renderer_context->m_vertex_stream_quad, (unsigned int)&loc_3FFFF + 1);
  vostok::render::index_buffer::index_buffer(&renderer_context->m_index_stream_quad, (unsigned int)&loc_3FFFF + 1);
  renderer_context->m_sh_particle_selection.m_object = 0;
  renderer_context->m_sh_vcolor.m_object = 0;
  renderer_context->m_sh_grid_25.m_object = 0;
  renderer_context->m_sh_grid_50.m_object = 0;
  renderer_context->m_sh_ui.m_object = 0;
  renderer_context->m_notexture_shader.m_object = 0;
  memset(renderer_context->m_editor_selection_shader, 0, sizeof(renderer_context->m_editor_selection_shader));
  renderer_context->m_editor_model_ghost_shader.m_object = 0;
  renderer_context->m_colored_geom.m_object = 0;
  renderer_context->m_grid_geom.m_object = 0;
  renderer_context->m_ui_geom.m_object = 0;
  renderer_context->m_grid_texture_25.m_object = 0;
  renderer_context->m_grid_texture_50.m_object = 0;
  renderer_context->m_rotation_mode_states[0].m_object = 0;
  renderer_context->m_rotation_mode_states[1].m_object = 0;
  m_object = renderer_context->m_vertex_stream.m_buffer.m_object;
  p_m_sh_vcolor = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)renderer_context->m_index_stream.m_buffer.m_object;
  v38.m_object = (survarium::pure_game_effect_emitter_base *)m_object;
  v37 = (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  renderer_context->m_grid_mode = 0;
  renderer_context->m_color_write = 1;
  geometry = vostok::render::resource_manager::create_geometry(
               (vostok::render::resource_manager *)m_object,
               v37,
               F_L,
               2u,
               (vostok::render::untyped_buffer *)0x10,
               (vostok::render::untyped_buffer *)v38.m_object,
               (int)p_m_sh_vcolor);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &renderer_context->m_colored_geom,
    geometry);
  v6 = vostok::render::resource_manager::create_geometry(
         v5,
         (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
         F_L_sl,
         5u,
         (vostok::render::untyped_buffer *)0x24,
         renderer_context->m_vertex_stream.m_buffer.m_object,
         (int)renderer_context->m_index_stream.m_buffer.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &renderer_context->m_colored_geom_sl,
    v6);
  *(float *)&v49.m_name.m_pointer.m_object = c_anim_center;
  v7 = s_bm_current_air_resistance;
  v49.m_source.m_size = 0;
  *(float *)&v49.m_type = s_bm_current_air_resistance;
  renderer_context->m_selection_color.x = 0.0;
  *(_QWORD *)&renderer_context->m_selection_color.elements[1] = *(_QWORD *)&v49.m_source.m_size;
  LODWORD(renderer_context->m_selection_color.w) = v49.m_type;
  memset((void *)&v49.m_source.m_size, 0, 12);
  renderer_context->m_current_selection_color.x = 0.0;
  *(_QWORD *)&renderer_context->m_current_selection_color.elements[1] = *(_QWORD *)&v49.m_source.m_size;
  LODWORD(renderer_context->m_current_selection_color.w) = v49.m_type;
  *(float *)&v49.m_source.m_pointer = FLOAT_0_2;
  *(float *)&v49.m_source.m_size = FLOAT_0_2;
  *(float *)&v49.m_name.m_pointer.m_object = FLOAT_0_2;
  *(float *)&v49.m_type = FLOAT_0_2;
  renderer_context->m_ghost_model_color.x = FLOAT_0_2;
  *(_QWORD *)&renderer_context->m_ghost_model_color.elements[1] = *(_QWORD *)&v49.m_source.m_size;
  LODWORD(renderer_context->m_ghost_model_color.w) = v49.m_type;
  v8 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
  p_m_sh_vcolor = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_sh_vcolor;
  renderer_context->m_selection_rate = v7;
  renderer_context->m_grid_density = FLOAT_0_1;
  vostok::render::effect_manager::create_effect<vostok::render::effect_system_colored>(v9, v8, p_m_sh_vcolor);
  vostok::render::effect_manager::create_effect<vostok::render::effect_system_line>(
    v10,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_sh_sl);
  vostok::render::effect_manager::create_effect<vostok::render::effect_add_border_padding>(
    v11,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_add_border_padding_effect);
  vostok::render::effect_manager::create_effect<vostok::render::effect_block_compression>(
    v12,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_block_compression_effect);
  vostok::shared_string::shared_string(v13, &name.m_pointer, "grid_density");
  renderer_context->m_grid_density_constant = vostok::render::backend::register_constant_host(
                                                v14,
                                                SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                                &name,
                                                0);
  if ( name.m_pointer.m_object && !_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::strings::shared::detail::intrusive_base::destroy(
      0,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  v15 = vostok::render::resource_manager::create_geometry(
          (vostok::render::resource_manager *)renderer_context->m_vertex_stream.m_buffer.m_object,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          F_TL_0,
          3u,
          (vostok::render::untyped_buffer *)0x1C,
          renderer_context->m_vertex_stream.m_buffer.m_object,
          (int)renderer_context->m_renderer_context->m_quad_ib.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &renderer_context->m_ui_geom,
    v15);
  vostok::render::effect_manager::create_effect<vostok::render::effect_system_ui>(
    v16,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_sh_ui);
  vostok::shared_string::shared_string(v17, &name.m_pointer, "m_WVP_sl");
  renderer_context->m_WVP_sl = vostok::render::backend::register_constant_host(
                                 v18,
                                 SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                 &name,
                                 0);
  if ( name.m_pointer.m_object )
  {
    v19 = (vostok::shared_string *)_InterlockedExchangeAdd(&name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF);
    if ( !v19 )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object);
  }
  v20 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  vostok::render::shader_constant_binding::shader_constant_binding(
    &v49,
    &renderer_context->m_current_selection_color,
    v19,
    "selection_color");
  vostok::render::resource_manager::register_constant_binding(v20, v21);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&v49.m_name.m_pointer);
  vostok::render::effect_manager::create_effect<vostok::render::effect_wireframe_colored>(
    v22,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_notexture_shader);
  name.m_pointer.m_object = 0;
  v44.m_pointer.m_object = (vostok::strings::shared::profile *)renderer_context->m_editor_selection_shader;
  do
  {
    if ( name.m_pointer.m_object != (vostok::strings::shared::profile *)12 )
    {
      memset((void *)&v49.m_source.m_size, 255, 12);
      v24 = (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst;
      v49.m_source.m_pointer = name.m_pointer.m_object;
      if ( (`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>'::`2'::`local static guard'
          & 1) == 0 )
      {
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>'::`2'::`local static guard' |= 1u;
        `vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>'::`2'::descriptor_object.m_object = (vostok::configs::binary_config *)&vostok::render::effect_editor_selection::`vftable';
        atexit((int (__cdecl *)())`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>'::`2'::`dynamic atexit destructor for 'descriptor_object'');
        v23 = (vostok::render::effect_manager *)p_m_sh_vcolor;
      }
      parameters.vertex_input_type = 0;
      v25 = LOBYTE(v24->m_object) == 0;
      p_m_sh_vcolor = (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&v49;
      v38.m_object = (survarium::pure_game_effect_emitter_base *)&parameters;
      if ( v25 )
      {
        vostok::render::effect_manager::create_new_effect(
          v23,
          __SPAIR64__((unsigned int)v44.m_pointer.m_object, (unsigned int)v24),
          (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>'::`2'::descriptor_object,
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v38.m_object,
          (vostok::render::surface_effect_parameters *)p_m_sh_vcolor);
      }
      else
      {
        new_effect = vostok::render::effect_manager::create_new_effect(
                       v23,
                       v24,
                       (vostok::render::effect_descriptor *)&parameters.cull_mode,
                       (vostok::render::effect_descriptor *)&`vostok::render::effect_manager::create_effect<vostok::render::effect_editor_selection>'::`2'::descriptor_object,
                       (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v38.m_object,
                       (vostok::render::surface_effect_parameters *)p_m_sh_vcolor);
        vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
          (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)new_effect,
          (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)v44.m_pointer.m_object);
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&parameters.cull_mode);
      }
      vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&parameters);
    }
    ++name.m_pointer.m_object;
    v44.m_pointer.m_object = (vostok::strings::shared::profile *)((char *)v44.m_pointer.m_object + 4);
  }
  while ( (unsigned int)name.m_pointer.m_object < 0xF );
  vostok::render::effect_manager::create_effect<vostok::render::effect_editor_model_ghost>(
    v23,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_editor_model_ghost_shader);
  vostok::render::effect_manager::create_effect<vostok::render::effect_particle_selection>(
    v27,
    (vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base> *)vostok::quasi_singleton<vostok::render::effect_manager>::pinst,
    (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)&renderer_context->m_sh_particle_selection);
  vostok::shared_string::shared_string(v28, &v44.m_pointer, "start_corner");
  renderer_context->m_c_start_corner = vostok::render::backend::register_constant_host(
                                         v29,
                                         SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
                                         &v44,
                                         0);
  if ( v44.m_pointer.m_object && !_InterlockedExchangeAdd(&v44.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    name.m_pointer.m_object = v44.m_pointer.m_object;
    vostok::threading::mutex::lock(0, &s_manager_buffer);
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::find(
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)name.m_pointer.m_object,
      &v48,
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
      v40);
    while ( v48.m_value && v48.m_value != name.m_pointer.m_object )
      vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator::operator++(
        &v48,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::iterator *)&v49);
    vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy>::erase(
      (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)&result,
      v48.m_index,
      v48.m_value);
    LeaveCriticalSection(&s_manager_buffer);
    vostok::strings::shared::profile::destroy((vostok::threading::mutex *)name.m_pointer.m_object, v40);
  }
  v30 = type_info::raw_name(&vostok::render::material_effects_instance_cook_data `RTTI Type Descriptor');
  parameters.cull_mode = (unsigned int)vostok::memory::pthreads3_allocator::malloc_impl(
                                         v31,
                                         (int)&vostok::memory::g_mt_allocator,
                                         (const char *const)0x10,
                                         v30,
                                         (const char *const)v40,
                                         v41);
  if ( parameters.cull_mode )
  {
    p_m_sh_vcolor = 0;
    v38.m_object = v32;
    vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>(
      &v38,
      0);
    vostok::render::material_effects_instance_cook_data::material_effects_instance_cook_data(
      post_process_vertex_input_type,
      (vostok::render::material_effects_instance_cook_data *)parameters.cull_mode,
      v38,
      (bool)p_m_sh_vcolor,
      (vostok::render::enum_cull_mode)v40);
  }
  else
  {
    v33 = 0;
  }
  renderer_context->m_cook_data_to_delete = v33;
  v53 = 16;
  v55 = 16;
  parameters.draw_to_gbuffer = 0x10000;
  parameters.blend_mode = 196610;
  v46 = 2;
  v47 = 1;
  decl_size.SemanticIndex = 0;
  memset(&decl_size.InputSlot, 0, 16);
  v52 = 0;
  v54 = 0;
  v56 = 0;
  v57 = 0;
  decl_size.SemanticName = "POSITION";
  decl_size.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
  v51 = "TEXCOORD";
  vostok::render::resource_manager::create_buffer(
    0xCu,
    vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
    (void *)2,
    (vostok::render::enum_buffer_type)&parameters.draw_to_gbuffer,
    1,
    0,
    0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v34,
    (const vostok::render::untyped_buffer **)&renderer_context->m_screen_vertex_ib.m_object,
    (vostok::render::hw_buffer_pool *)2);
  v36 = vostok::render::resource_manager::create_geometry(
          v35,
          (vostok::render::res_declaration *)vostok::quasi_singleton<vostok::render::resource_manager>::pinst,
          &decl_size,
          2u,
          (vostok::render::untyped_buffer *)0x18,
          renderer_context->m_vertex_stream_quad.m_buffer.m_object,
          (int)renderer_context->m_screen_vertex_ib.m_object);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    &renderer_context->m_screen_vertex_geometry,
    v36);
}
