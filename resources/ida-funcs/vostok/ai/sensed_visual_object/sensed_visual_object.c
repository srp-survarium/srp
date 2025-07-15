void __usercall vostok::ai::sensed_visual_object::sensed_visual_object(
        vostok::ai::sensed_visual_object *this@<ecx>,
        float other_x@<xmm0>)
{
  btNullPairCache *v3; // [esp+24h] [ebp-64h]

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::math::float3::float3(&this->own_position, LODWORD(other_x), LODWORD(other_x), other_x);
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::memory::uninitialized_value<float>();
  vostok::math::float3::float3(&this->local_point, LODWORD(other_x), LODWORD(other_x), other_x);
  this->object = 0;
  this->next = 0;
  vostok::memory::uninitialized_value<float>();
  this->distance = other_x;
  this->visibility_value = *(float *)&FLOAT_0_0;
  this->was_visible_last_time = 0;
  this->is_in_frustum = survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0
                      ? -51
                      : -3;
  v3 = (btNullPairCache *)(survarium::player_logic_base_state::is_ready_for_transition((btNullPairCache *)this) != 0
                         ? -33698355
                         : -842138115);
  this->newly_added_to_frustum = (char)v3;
  this->was_updated = survarium::player_logic_base_state::is_ready_for_transition(v3) != 0 ? -51 : -3;
}
