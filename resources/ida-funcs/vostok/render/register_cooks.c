void __cdecl vostok::render::register_cooks(bool is_editor)
{
  vostok::render::texture_gpu_converter_cook *v1; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v2; // ecx
  vostok::render::bake_decal_cook *v3; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v4; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v5; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v6; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v7; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v8; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v9; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v10; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v11; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v12; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v13; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v14; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v15; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v16; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v17; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v18; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v19; // ecx
  vostok::buffer_vector<vostok::resources::cook_base *> *v20; // ecx
  vostok::render::texture_gpu_converter_cook *v21; // [esp-4h] [ebp-14h]
  vostok::render::texture_gpu_converter_cook *v22; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v23; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v24; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v25; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v26; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v27; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v28; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v29; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v30; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v31; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v32; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v33; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v34; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v35; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v36; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v37; // [esp-4h] [ebp-14h]
  vostok::render::bake_decal_cook *v38; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v39; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v40; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v41; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v42; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v43; // [esp-4h] [ebp-14h]
  vostok::buffer_vector<vostok::resources::cook_base *> *v44; // [esp-4h] [ebp-14h]
  vostok::particle *v45; // [esp+0h] [ebp-10h]

  if ( (_S6_6 & 1) == 0 )
  {
    _S6_6 |= 1u;
    vostok::resources::cook_base::cook_base(&renderer_cooker, renderer_class, 0xFFFFFFFD, reuse_false, 0, 0xFFFFFFFD);
    renderer_cooker.__vftable = (vostok::render::renderer_cook_vtbl *)&vostok::render::renderer_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&renderer_cooker, v2);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__renderer_cooker__);
    v1 = v21;
  }
  if ( (_S6_6 & 2) == 0 )
  {
    _S6_6 |= 2u;
    vostok::render::texture_gpu_converter_cook::texture_gpu_converter_cook(v1);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__texture_gpu_converter_cooker__);
    v1 = v22;
  }
  vostok::resources::resources_manager::register_cook(
    &texture_gpu_converter_cooker,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)v1);
  if ( (_S6_6 & 4) == 0 )
  {
    _S6_6 |= 4u;
    vostok::resources::cook_base::cook_base(
      &user_mesh_cooker,
      user_mesh_class,
      0xFFFFFFFD,
      reuse_true,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)2,
      0);
    user_mesh_cooker.__vftable = (vostok::render::user_mesh_cook_vtbl *)&vostok::render::user_mesh_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&user_mesh_cooker, v4);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__user_mesh_cooker__);
    v3 = v23;
  }
  if ( (_S6_6 & 8) == 0 )
  {
    _S6_6 |= 8u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x10,
      &static_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    static_model_instance_cooker.__vftable = (vostok::render::static_model_instance_cook_vtbl *)&vostok::render::static_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&static_model_instance_cooker, v5);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__static_model_instance_cooker__);
    v3 = v24;
  }
  if ( (_S6_6 & 0x10) == 0 )
  {
    _S6_6 |= 0x10u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x11,
      &skeleton_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    skeleton_model_instance_cooker.__vftable = (vostok::render::skeleton_model_instance_cook_vtbl *)&vostok::render::skeleton_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&skeleton_model_instance_cooker, v6);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__skeleton_model_instance_cooker__);
    v3 = v25;
  }
  if ( (_S6_6 & 0x20) == 0 )
  {
    _S6_6 |= 0x20u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0xE,
      &tracer_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    tracer_model_instance_cooker.__vftable = (vostok::render::tracer_model_instance_cook_vtbl *)&vostok::render::tracer_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&tracer_model_instance_cooker, v7);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__tracer_model_instance_cooker__);
    v3 = v26;
  }
  if ( (_S6_6 & 0x40) == 0 )
  {
    _S6_6 |= 0x40u;
    vostok::render::render_model_cook::render_model_cook(
      (vostok::render::render_model_cook *)0x14,
      &skeleton_mesh_instance_cooker);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__skeleton_mesh_instance_cooker__);
    v3 = v27;
  }
  if ( (_S6_6 & 0x80u) == 0 )
  {
    _S6_6 |= 0x80u;
    vostok::render::render_model_cook::render_model_cook(
      (vostok::render::render_model_cook *)0x13,
      &render_model_class_cooker);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__render_model_class_cooker__);
    v3 = v28;
  }
  if ( (_S6_6 & 0x100) == 0 )
  {
    _S6_6 |= 0x100u;
    vostok::render::render_model_cook::render_model_cook(
      (vostok::render::render_model_cook *)0x1A,
      &grass_render_model_class_cooker);
    grass_render_model_class_cooker.__vftable = (vostok::render::grass_render_model_cook_vtbl *)&vostok::render::grass_render_model_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__grass_render_model_class_cooker__);
    v3 = v29;
  }
  if ( (_S6_6 & 0x200) == 0 )
  {
    _S6_6 |= 0x200u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x15,
      &static_render_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    static_render_model_instance_cooker.__vftable = (vostok::render::static_render_model_instance_cook_vtbl *)&vostok::render::static_render_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&static_render_model_instance_cooker, v8);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__static_render_model_instance_cooker__);
    v3 = v30;
  }
  if ( (_S6_6 & 0x400) == 0 )
  {
    _S6_6 |= 0x400u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x16,
      &skeleton_render_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    skeleton_render_model_instance_cooker.__vftable = (vostok::render::skeleton_render_model_instance_cook_vtbl *)&vostok::render::skeleton_render_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&skeleton_render_model_instance_cooker, v9);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__skeleton_render_model_instance_cooker__);
    v3 = v31;
  }
  if ( (_S6_6 & 0x800) == 0 )
  {
    _S6_6 |= 0x800u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x18,
      &skeleton_combined_model_cooker,
      reuse_true,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    skeleton_combined_model_cooker.__vftable = (vostok::render::skeleton_combined_model_cook_vtbl *)&vostok::render::skeleton_combined_model_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&skeleton_combined_model_cooker, v10);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__skeleton_combined_model_cooker__);
    v3 = v32;
  }
  if ( (_S6_6 & 0x1000) == 0 )
  {
    _S6_6 |= 0x1000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x17,
      &skeleton_combined_render_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    skeleton_combined_render_model_instance_cooker.__vftable = (vostok::render::skeleton_combined_render_model_instance_cook_vtbl *)&vostok::render::skeleton_combined_render_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&skeleton_combined_render_model_instance_cooker, v11);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__skeleton_combined_render_model_instance_cooker__);
    v3 = v33;
  }
  if ( (_S6_6 & 0x2000) == 0 )
  {
    _S6_6 |= 0x2000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x12,
      &skeleton_combined_model_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    skeleton_combined_model_instance_cooker.__vftable = (vostok::render::skeleton_combined_model_instance_cook_vtbl *)&vostok::render::skeleton_combined_model_instance_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&skeleton_combined_model_instance_cooker, v12);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__skeleton_combined_model_instance_cooker__);
    v3 = v34;
  }
  if ( (_S6_6 & 0x4000) == 0 )
  {
    _S6_6 |= 0x4000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x68,
      &grass_cooker,
      reuse_false,
      0xFFFFFFFC,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    grass_cooker.__vftable = (vostok::render::grass_cook_vtbl *)&vostok::render::grass_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&grass_cooker, v13);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__grass_cooker__);
    v3 = v35;
  }
  if ( (_S6_6 & 0x8000) == 0 )
  {
    _S6_6 |= 0x8000u;
    vostok::render::bake_decal_cook::bake_decal_cook(v3);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__bake_decal_cooker__);
    v3 = v36;
  }
  if ( ((unsigned int)&_sbh_sizeHeaderList & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)&_sbh_sizeHeaderList;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x65,
      &render_texture_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    render_texture_cooker.__vftable = (vostok::render::render_texture_cook_vtbl *)&vostok::render::render_texture_cook::`vftable';
    vostok::resources::resources_manager::register_cook(&render_texture_cooker, v14);
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__render_texture_cooker__);
    v3 = v37;
  }
  if ( ((unsigned int)&loc_20000 & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)&loc_20000;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x1F,
      &material_cook,
      reuse_true,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    material_cook.__vftable = (vostok::render::material_cook_vtbl *)&vostok::render::material_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__material_cook__);
    v3 = v38;
  }
  vostok::resources::resources_manager::register_cook(
    &material_cook,
    (vostok::buffer_vector<vostok::resources::cook_base *> *)v3);
  if ( (((unsigned int)&loc_3FFFF + 1) & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)&loc_3FFFF + 1;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0xF,
      &material_effects_instance_cooker,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    material_effects_instance_cooker.__vftable = (vostok::render::material_effects_instance_cook_vtbl *)&vostok::render::material_effects_instance_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__material_effects_instance_cooker__);
    v15 = v39;
  }
  vostok::resources::resources_manager::register_cook(&material_effects_instance_cooker, v15);
  vostok::render::register_texture_cook();
  if ( !byte_47E9DA0 )
  {
    vostok::particle::register_particles_cooker(
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)&material_effects_instance_cooker,
      vostok::render::g_allocator);
    vostok::particle::register_particles_system_cooks(v45);
    vostok::resources::unmanaged_cook::unmanaged_cook(
      particle_world_class,
      0xFFFFFFFC,
      (vostok::resources::unmanaged_cook *)&vostok::particle::s_particle_world_cooker_object,
      reuse_false,
      0xFFFFFFFC,
      0);
    *(_DWORD *)vostok::particle::s_particle_world_cooker_object.m_static_memory = &vostok::particle::particle_world_cooker::`vftable';
    _InterlockedExchange(&vostok::particle::s_particle_world_cooker_object.m_initialized, 1);
    vostok::resources::resources_manager::register_cook(
      vostok::particle::s_particle_world_cooker_object.m_variable,
      (vostok::buffer_vector<vostok::resources::cook_base *> *)&vostok::particle::s_particle_world_cooker_object.m_initialized);
    byte_47E9DA0 = 1;
  }
  if ( (_S6_6 & 0x80000) == 0 )
  {
    _S6_6 |= 0x80000u;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x62,
      &scene_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    scene_cook.__vftable = (vostok::render::scene_cook_vtbl *)&vostok::render::scene_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__scene_cook__);
    v16 = v40;
  }
  vostok::resources::resources_manager::register_cook(&scene_cook, v16);
  if ( ((unsigned int)&loc_100000 & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)&loc_100000;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x63,
      &scene_view_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    scene_view_cook.__vftable = (vostok::render::scene_view_cook_vtbl *)&vostok::render::scene_view_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__scene_view_cook__);
    v17 = v41;
  }
  vostok::resources::resources_manager::register_cook(&scene_view_cook, v17);
  if ( ((unsigned int)&loc_200000 & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)&loc_200000;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x64,
      &render_output_window_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    render_output_window_cook.__vftable = (vostok::render::render_output_window_cook_vtbl *)&vostok::render::render_output_window_cook::`vftable';
    render_output_window_cook.m_is_editor = is_editor;
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__render_output_window_cook__);
    v18 = v42;
  }
  vostok::resources::resources_manager::register_cook(&render_output_window_cook, v18);
  if ( ((unsigned int)&loc_400000 & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)&loc_400000;
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x5E,
      &animated_model_cook,
      reuse_false,
      0xFFFFFFFC,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    animated_model_cook.__vftable = (vostok::render::animated_model_instance_cook_vtbl *)&vostok::render::animated_model_instance_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__animated_model_cook__);
    v19 = v43;
  }
  vostok::resources::resources_manager::register_cook(&animated_model_cook, v19);
  if ( ((unsigned int)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)"
      & _S6_6) == 0 )
  {
    _S6_6 |= (unsigned int)"esource_ptr<class vostok::sound::sound_emitter,class vostok::resources::unmanaged_intrusive_base>,const class vostok::sound::sound_propagator_emitter &,class vostok::sound::world_user &)";
    vostok::resources::translate_query_cook::translate_query_cook(
      (vostok::resources::translate_query_cook *)0x71,
      &s_portal_system_cook,
      reuse_false,
      0xFFFFFFFD,
      0,
      (vostok::enum_flags<enum vostok::resources::cook_base::flags_enum>)v45);
    s_portal_system_cook.__vftable = (vostok::render::culling::portal_sector_structure_cook_vtbl *)&vostok::render::culling::portal_sector_structure_cook::`vftable';
    atexit((int (__cdecl *)())vostok::render::register_cooks_::_2_::_dynamic_atexit_destructor_for__s_portal_system_cook__);
    v20 = v44;
  }
  vostok::resources::resources_manager::register_cook(&s_portal_system_cook, v20);
}
