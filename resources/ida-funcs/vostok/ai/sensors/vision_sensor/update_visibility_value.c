void __thiscall vostok::ai::sensors::vision_sensor::update_visibility_value(vostok::ai::sensors::vision_sensor *this)
{
  vostok::math::float3 *v1; // eax
  survarium::game_camera v3; // [esp+10h] [ebp-54h] BYREF

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v3.m_inverted_view_matrix.lines[1].elements[1]);
  LODWORD(v3.m_inverted_view_matrix.j.x) = this->m_npc;
  v1 = this->m_npc->get_eyes_position(this->m_npc, &v3.m_inverted_view_matrix.lines[0].elements[1]);
  *(_QWORD *)&v3.m_inverted_view_matrix.lines[1].elements[1] = *(_QWORD *)&v1->x;
  v3.m_inverted_view_matrix.j.w = v1->z;
  LODWORD(v3.m_near_plane) = this->m_last_tick;
  v3.m_inverted_view_matrix.k.x = this->m_parameters.time_quant;
  v3.m_inverted_view_matrix.k.y = this->m_parameters.velocity_factor;
  v3.m_inverted_view_matrix.k.z = this->m_parameters.luminosity_factor;
  v3.m_inverted_view_matrix.k.w = this->m_parameters.decrease_factor;
  *(_QWORD *)&v3.m_inverted_view_matrix.lines[3].x = *(_QWORD *)&this->m_parameters.far_plane_distance;
  *(_QWORD *)&v3.m_inverted_view_matrix.lines[3].elements[2] = *(_QWORD *)&this->m_parameters.max_visibility;
  v3.m_game_scene = (survarium::base_game_scene *)LODWORD(this->m_parameters.transparency_threshold);
  LODWORD(v3.m_inverted_view_matrix.i.x) = this->m_world;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v3.m_far_plane);
  v3.m_far_plane = v3.m_inverted_view_matrix.i.x;
  LODWORD(v3.m_fov_factor) = &v3.m_inverted_view_matrix.j.0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v3);
  v3.__vftable = (survarium::game_camera_vtbl *)&v3.m_far_plane;
  vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::sensors::update_visibility_predicate>>(
    &this->m_visible_objects,
    (const vostok::intrusive_list<vostok::ai::sensed_visual_object,vostok::ai::sensed_visual_object *,28,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::void_predicate_ref<vostok::ai::sensors::update_visibility_predicate> *)&v3);
  survarium::weapon_user_dead_state::finalize(&v3);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&v3.m_far_plane);
}
