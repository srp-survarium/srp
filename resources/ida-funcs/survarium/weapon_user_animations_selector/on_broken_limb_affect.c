void __thiscall survarium::weapon_user_animations_selector::on_broken_limb_affect(
        survarium::weapon_user_animations_selector *this,
        const char *bodypart,
        survarium::game_camera *affect,
        survarium::game_camera *type)
{
  survarium::game_camera *v4; // ecx
  _BYTE *v5; // eax
  survarium::base_player *v6; // ecx
  _BYTE *v7; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v5 )
    survarium::weapon_user_dead_state::finalize(type);
  survarium::weapon_user_dead_state::finalize(v4);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(affect);
  survarium::base_player::force_animation_selection(v6, (int)this->m_user);
}
