void __thiscall survarium::damage_model::reset(survarium::damage_model *this)
{
  survarium::reset_predicate pred; // [esp+Fh] [ebp-1h] BYREF

  this->m_last_hit_initiator = -1;
  this->m_broken_legs_count[0] = 0;
  this->m_broken_legs_count[1] = 0;
  this->m_broken_hands_count[0] = 0;
  this->m_broken_hands_count[1] = 0;
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&pred);
  vostok::intrusive_list<survarium::body_part_parameters,survarium::body_part_parameters *,0,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::for_each<survarium::reset_predicate>(
    &this->m_body_parts,
    &pred);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&pred);
}
