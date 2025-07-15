void __thiscall survarium::player::render_model(
        survarium::player *this,
        const float last_frame_linear_displacement,
        float a3)
{
  bool v3; // zf
  int v4; // edx
  const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v5; // eax
  vostok::render::scene_renderer *v6; // ecx
  vostok::render::scene_renderer *v7; // ecx
  vostok::render::scene_renderer *v8; // ecx
  vostok::render::scene_renderer *v9; // ecx
  vostok::render::scene_renderer *v10; // ecx
  vostok::render::scene_renderer *v11; // ecx
  vostok::render::scene_renderer *v12; // ecx
  vostok::render::scene_renderer *v13; // ecx
  vostok::render::scene_renderer *v14; // ecx
  vostok::render::scene_renderer *v15; // ecx
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v16; // [esp-18h] [ebp-44h]
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v17; // [esp-18h] [ebp-44h]
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v18; // [esp-18h] [ebp-44h]
  const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *v19; // [esp-18h] [ebp-44h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v20; // [esp-14h] [ebp-40h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v21; // [esp-14h] [ebp-40h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v22; // [esp-14h] [ebp-40h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v23; // [esp-14h] [ebp-40h]
  vostok::render::material_parameter_host *v24; // [esp-8h] [ebp-34h]
  vostok::render::material_parameter_host *v25; // [esp-8h] [ebp-34h]
  vostok::render::material_parameter_host *v26; // [esp-8h] [ebp-34h]
  vostok::render::material_parameter_host *v27; // [esp-8h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::render::trample_desc const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > *v28; // [esp-4h] [ebp-30h]
  float v29; // [esp+0h] [ebp-2Ch]
  float v30; // [esp+0h] [ebp-2Ch]
  float v31; // [esp+0h] [ebp-2Ch]
  float v32; // [esp+0h] [ebp-2Ch]
  float v33; // [esp+0h] [ebp-2Ch]
  float v34; // [esp+0h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v35; // [esp+10h] [ebp-1Ch] BYREF
  int v36; // [esp+14h] [ebp-18h]
  vostok::render::trample_desc v37; // [esp+18h] [ebp-14h] BYREF

  vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v35,
    (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 4));
  v3 = *((_BYTE *)&loc_11437 + LODWORD(last_frame_linear_displacement) + 1) == 0;
  v4 = *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172);
  v36 = v4;
  if ( !v3 )
  {
    v5 = (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264);
    if ( BYTE1(v5->m_object->m_lods[0].m_emitter_instance_list.m_size) )
    {
      vostok::render::scene_renderer::update_model(
        v5,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + v4),
        &v35,
        (const vostok::math::float4x4 *)&byte_10E2C[LODWORD(last_frame_linear_displacement)],
        (const vostok::math::float4x4 *)&byte_10E2C[LODWORD(last_frame_linear_displacement)]);
      if ( *(_DWORD *)(LODWORD(last_frame_linear_displacement) + 70052)
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v24 = *(vostok::render::material_parameter_host **)((char *)&dword_11420
                                                          + LODWORD(last_frame_linear_displacement));
        v20 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264);
        v16 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172));
        v37.position.x = 0.0;
        *(_QWORD *)&v37.position.elements[1] = LODWORD(s_bm_current_air_resistance);
        vostok::render::scene_renderer::set_model_material_parameter_impl(
          v6,
          v16,
          v20,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          0,
          v24,
          (unsigned __int8 *)&v37,
          0xCu);
        v29 = 1.0;
        vostok::render::scene_renderer::set_model_material_parameter(
          v7,
          *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264),
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          0,
          *(vostok::render::material_parameter_host **)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
                                                      + LODWORD(last_frame_linear_displacement)),
          LOBYTE(v29));
        v25 = *(vostok::render::material_parameter_host **)((char *)&loc_11427
                                                          + LODWORD(last_frame_linear_displacement)
                                                          + 1);
        v21 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264);
        v17 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172));
        *(_QWORD *)&v37.position.x = LODWORD(s_bm_current_air_resistance);
        v37.position.z = 0.0;
        v37.radius = s_bm_current_air_resistance;
        vostok::render::scene_renderer::set_model_material_parameter_impl(
          v8,
          v17,
          v21,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          0,
          v25,
          (unsigned __int8 *)&v37,
          0x10u);
        v30 = 0.5;
        vostok::render::scene_renderer::set_model_material_parameter(
          v9,
          *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264),
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          0,
          *(vostok::render::material_parameter_host **)((char *)&loc_1142C + LODWORD(last_frame_linear_displacement)),
          LOBYTE(v30));
        v31 = 0.5;
        vostok::render::scene_renderer::set_model_material_parameter(
          v10,
          *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264),
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          0,
          *(vostok::render::material_parameter_host **)((char *)&loc_1142E + LODWORD(last_frame_linear_displacement) + 2),
          LOBYTE(v31));
        v26 = *(vostok::render::material_parameter_host **)((char *)&dword_11420
                                                          + LODWORD(last_frame_linear_displacement));
        v22 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264);
        v18 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172));
        v37.position.x = 0.0;
        *(_QWORD *)&v37.position.elements[1] = LODWORD(c_anim_center);
        vostok::render::scene_renderer::set_model_material_parameter_impl(
          v11,
          v18,
          v22,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          (survarium::pure_game_effect_emitter_base *)1,
          v26,
          (unsigned __int8 *)&v37,
          0xCu);
        v32 = 5.0;
        vostok::render::scene_renderer::set_model_material_parameter(
          v12,
          *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264),
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          (survarium::pure_game_effect_emitter_base *)1,
          *(vostok::render::material_parameter_host **)((char *)vostok::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::vfs::vfs_mount,vostok::vfs::vfs_intrusive_mount_base,vostok::threading::simple_lock>
                                                      + LODWORD(last_frame_linear_displacement)),
          LOBYTE(v32));
        v27 = *(vostok::render::material_parameter_host **)((char *)&loc_11427
                                                          + LODWORD(last_frame_linear_displacement)
                                                          + 1);
        v23 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264);
        v19 = *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172));
        v37.position.x = 0.0;
        *(_QWORD *)&v37.position.elements[1] = LODWORD(s_bm_current_air_resistance);
        v37.radius = s_bm_current_air_resistance;
        vostok::render::scene_renderer::set_model_material_parameter_impl(
          v13,
          v19,
          v23,
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          (survarium::pure_game_effect_emitter_base *)1,
          v27,
          (unsigned __int8 *)&v37,
          0x10u);
        v33 = 0.5;
        vostok::render::scene_renderer::set_model_material_parameter(
          v14,
          *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264),
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          (survarium::pure_game_effect_emitter_base *)1,
          *(vostok::render::material_parameter_host **)((char *)&loc_1142C + LODWORD(last_frame_linear_displacement)),
          LOBYTE(v33));
        v34 = 0.5;
        vostok::render::scene_renderer::set_model_material_parameter(
          v15,
          *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + *(_DWORD *)(*(_DWORD *)(*(int *)((char *)&dword_11410 + LODWORD(last_frame_linear_displacement)) + 160) + 172)),
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(*(_DWORD *)((char *)&loc_1119E + LODWORD(last_frame_linear_displacement) + 2) + 264),
          (vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(last_frame_linear_displacement) + 70052),
          (survarium::pure_game_effect_emitter_base *)1,
          *(vostok::render::material_parameter_host **)((char *)&loc_1142E + LODWORD(last_frame_linear_displacement) + 2),
          LOBYTE(v34));
      }
      if ( a3 > 0.025 )
      {
        *(_QWORD *)&v37.position.x = *(_QWORD *)&byte_10E5C[LODWORD(last_frame_linear_displacement)];
        v28 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::render::engine::world,vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> const &,vostok::render::trample_desc const &>,boost::_bi::list3<boost::_bi::value<vostok::render::engine::world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> >,boost::arg<1> > > **)((char *)&dword_200060 + v36);
        v37.position.z = *(float *)&byte_10E5C[LODWORD(last_frame_linear_displacement) + 8];
        v37.multiplier = s_bm_current_air_resistance;
        v37.radius = c_anim_center;
        vostok::render::scene_renderer::add_vegetation_trample(&v35, v28, &v37);
      }
    }
  }
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v35);
}
