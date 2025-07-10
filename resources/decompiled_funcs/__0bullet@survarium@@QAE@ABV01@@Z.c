void __thiscall survarium::bullet::bullet(survarium::bullet *this, survarium::game_camera *other)
{
  survarium::game_camera *x_low; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_velocity);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_start_position);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_start_velocity);
  *(_QWORD *)&this->m_position.x = *(_QWORD *)&other->__vftable;
  this->m_position.z = other->m_inverted_view_matrix.i.y;
  this->m_velocity = *(vostok::math::float3 *)&other->m_inverted_view_matrix.lines[0].elements[2];
  this->m_start_position = *(vostok::math::float3 *)&other->__vftable;
  this->m_start_velocity = *(vostok::math::float3 *)&other->m_inverted_view_matrix.lines[0].elements[2];
  this->m_bullet_manager = (survarium::bullet_manager *)LODWORD(other->m_inverted_view_matrix.k.w);
  this->m_born_time_in_ms = LODWORD(other->m_near_plane);
  this->m_life_time = other->m_fov_factor;
  this->m_air_resistance = *(float *)&other[1].__vftable;
  this->m_current_resistance = other[1].m_inverted_view_matrix.i.x;
  this->m_max_distance = other[1].m_inverted_view_matrix.i.y;
  this->m_flown_distance = other[1].m_inverted_view_matrix.i.z;
  x_low = (survarium::game_camera *)LODWORD(other[1].m_inverted_view_matrix.k.x);
  this->m_change_trajectory_count = (unsigned int)x_low;
  survarium::weapon_user_dead_state::finalize(x_low);
  this->m_bullet_material = (const survarium::game_material *)LODWORD(other->m_inverted_view_matrix.c.x);
  this->m_collided_material = (const survarium::game_material *)LODWORD(other->m_inverted_view_matrix.c.y);
  this->m_initiator = (const survarium::hit_initiator *)LODWORD(other->m_inverted_view_matrix.c.z);
  this->m_ignorable_object = (const survarium::hit_receiver *)LODWORD(other->m_inverted_view_matrix.c.w);
  this->m_last_hitted_body_part = (survarium::body_part_parameters *)other->m_game_scene;
  this->m_tracer_idx = HIWORD(other[1].m_inverted_view_matrix.lines[2].elements[1]);
  survarium::weapon_user_dead_state::finalize(other);
}
