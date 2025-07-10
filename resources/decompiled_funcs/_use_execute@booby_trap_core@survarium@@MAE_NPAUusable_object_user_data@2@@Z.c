char __thiscall survarium::booby_trap_core::use_execute(
        survarium::booby_trap_core *this,
        survarium::usable_object_user_data *user)
{
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  float value; // [esp+0h] [ebp-3Ch]
  unsigned int v7; // [esp+4h] [ebp-38h]
  unsigned int defuse_time_ms; // [esp+2Ch] [ebp-10h]
  float engineer_factor; // [esp+30h] [ebp-Ch]
  unsigned int passed_ms; // [esp+38h] [ebp-4h]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v2);
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  passed_ms = user->current_time_ms - user->start_using_time_ms;
  engineer_factor = user->owner->m_usable_object_user_data.booster_engineer_use_time_factor;
  value = (double)survarium::booby_trap_set_core::config(
                    (survarium::booby_trap_set_core *)user,
                    this->m_children_resources.m_size)->defuse_time
        * engineer_factor;
  defuse_time_ms = vostok::math::floor(value);
  if ( defuse_time_ms )
    v7 = vostok::math::min(100 * passed_ms / defuse_time_ms, 0x64u);
  else
    v7 = 100;
  user->current_progress = v7;
  if ( defuse_time_ms && passed_ms < defuse_time_ms )
    return 1;
  (*(void (__thiscall **)(float *))(LODWORD(this[-1].m_current_satisfaction) + 56))(&this[-1].m_current_satisfaction);
  return 0;
}
