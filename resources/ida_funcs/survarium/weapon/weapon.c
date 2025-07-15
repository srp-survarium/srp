void __thiscall survarium::weapon::weapon(
        survarium::weapon *this,
        survarium::weapon *first_view_death_animations_count,
        unsigned int third_view_death_animations_count,
        unsigned int preview_animations_count,
        unsigned int preview_animations_counta)
{
  vostok::render::light_props *v5; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v6; // edx
  unsigned int v7; // ecx
  unsigned int v8; // eax
  const vostok::math::float4x4 *v9; // xmm1_4
  vostok::math::float4x4 *v10; // eax
  vostok::math::float4x4 v11; // [esp+14h] [ebp-40h] BYREF

  survarium::weapon_core::weapon_core(first_view_death_animations_count);
  first_view_death_animations_count->__vftable = (survarium::weapon_vtbl *)&survarium::weapon::`vftable';
  `vector constructor iterator'(
    (char *)&first_view_death_animations_count->m_fingers_corrector,
    0x404u,
    2,
    (void *(__thiscall *)(void *))survarium::fingers_to_weapon_corrector::hand::hand);
  first_view_death_animations_count->m_fingers_corrector.m_interpolator.__vftable = (vostok::animation::linear_interpolator_vtbl *)&vostok::animation::linear_interpolator::`vftable';
  first_view_death_animations_count->m_fingers_corrector.m_interpolator.m_total_transition_time = FLOAT_0_1;
  first_view_death_animations_count->m_fingers_corrector.m_weapon_model.m_object = 0;
  first_view_death_animations_count->m_fingers_corrector.m_first_person_view = 0;
  vostok::render::light_props::light_props(v5);
  first_view_death_animations_count->m_fire_pfx_list = v6;
  first_view_death_animations_count->m_shells_pfx_list = v6;
  first_view_death_animations_count->m_fire_pfx_count = (unsigned __int8)v6;
  first_view_death_animations_count->m_shells_pfx_count = (unsigned __int8)v6;
  first_view_death_animations_count->m_current_shell_pfx_id = (unsigned __int8)v6;
  first_view_death_animations_count->m_current_fire_pfx_id = (unsigned __int8)v6;
  first_view_death_animations_count->model.m_object = (vostok::render::skeleton_model_instance *)v6;
  first_view_death_animations_count->m_game_ui = (survarium::game_world_ui *)v6;
  first_view_death_animations_count->m_rifle_scope.m_object = (survarium::rifle_scope *)v6;
  first_view_death_animations_count->m_first_view_death_animations_count = third_view_death_animations_count;
  first_view_death_animations_count->m_third_view_death_animations_count = preview_animations_count;
  v7 = survarium::light_ids;
  first_view_death_animations_count->m_preview_animations_count = preview_animations_counta;
  survarium::light_ids = v7 + 1;
  first_view_death_animations_count->m_weapon_fire_light_id = v7 + 1;
  qmemcpy(
    &first_view_death_animations_count->m_weapon_fire_light_props,
    &first_view_death_animations_count->survarium::weapon_core::m_transform,
    0x40u);
  first_view_death_animations_count->m_weapon_fire_light_props.local_light_z_bias = 0.0;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_transparency = 0.0;
  first_view_death_animations_count->m_game_scene = (survarium::base_game_scene *)v6;
  first_view_death_animations_count->m_fire_light_anim_length = 200;
  first_view_death_animations_count->m_firing_light_added = (char)v6;
  first_view_death_animations_count->m_is_in_scene = (char)v6;
  first_view_death_animations_count->m_is_scope_aimed = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.does_cast_shadows = 1;
  first_view_death_animations_count->m_weapon_fire_light_props.sun_shadow_map_size = 1;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_map_size_index = (unsigned int)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.num_sun_cascades = (unsigned int)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_distribution_sides[0] = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_distribution_sides[1] = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_distribution_sides[2] = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_distribution_sides[3] = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_distribution_sides[4] = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.shadow_distribution_sides[5] = (char)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.lighting_model = (int)v6;
  first_view_death_animations_count->m_weapon_fire_light_props.range = 5.0;
  v8 = vostok::math::floor(255.0);
  first_view_death_animations_count->m_weapon_fire_light_props.color = (unsigned __int8)v8
                                                                     | (((unsigned __int8)v8
                                                                       | (((unsigned __int8)v8 | (v8 << 8)) << 8)) << 8);
  v9 = clear_value;
  first_view_death_animations_count->m_weapon_fire_light_props.attenuation_power = retry_to_increase_quality_period_sec;
  first_view_death_animations_count->m_weapon_fire_light_props.type = light_type_point;
  LODWORD(first_view_death_animations_count->m_weapon_fire_light_props.intensity) = v9;
  first_view_death_animations_count->m_weapon_fire_light_props.spot_umbra_angle = 0.0;
  first_view_death_animations_count->m_weapon_fire_light_props.spot_penumbra_angle = 0.0;
  first_view_death_animations_count->m_weapon_fire_light_props.spot_falloff = 0.0;
  LODWORD(first_view_death_animations_count->m_weapon_fire_light_props.diffuse_influence_factor) = v9;
  LODWORD(first_view_death_animations_count->m_weapon_fire_light_props.specular_influence_factor) = v9;
  first_view_death_animations_count->m_weapon_fire_light_props.shadower = 0;
  first_view_death_animations_count->m_weapon_fire_light_props.use_with_lpv = 0;
  v10 = vostok::math::float4x4::identity(&v11);
  qmemcpy(
    (void *)&first_view_death_animations_count->m_barrel_transform,
    v10,
    sizeof(first_view_death_animations_count->m_barrel_transform));
  qmemcpy(
    (void *)&first_view_death_animations_count->m_scope_transform,
    v10,
    sizeof(first_view_death_animations_count->m_scope_transform));
}
