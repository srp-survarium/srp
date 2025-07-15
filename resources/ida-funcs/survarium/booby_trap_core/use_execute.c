char __userpurge survarium::booby_trap_core::use_execute@<al>(
        survarium::booby_trap_core *this@<ecx>,
        float a2@<xmm0>,
        survarium::usable_object_user_data *user)
{
  unsigned int v4; // edi
  survarium::base_player *v5; // eax
  float v6; // xmm0_4
  unsigned int v7; // eax
  float v9; // [esp+18h] [ebp+8h]

  v4 = user->current_time_ms - user->start_using_time_ms;
  v9 = (float)*(unsigned int *)(LODWORD(this->m_transform.j.x) + 332);
  v5 = user->owner->cast_to_base_player(user->owner);
  v6 = survarium::player_params_modifiers_container::apply_modifier(
         &v5->m_profile->modifiers,
         engineer_use_time_modifier,
         a2,
         v9,
         1.0);
  v7 = vostok::math::floor(v6);
  if ( v7 && v4 < v7 )
  {
    user->current_progress = 100 * v4 / v7 < 0x64 ? 100 * v4 / v7 - 100 + 100 : 100;
    return 1;
  }
  else
  {
    user->current_progress = -1;
    return 0;
  }
}
