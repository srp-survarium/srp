int __thiscall survarium::weapon_core::on_sprint_animation_ended(
        survarium::weapon_core *this,
        vostok::animation::animation_callback_params *params)
{
  survarium::weapon_core *v2; // ecx
  survarium::game_camera *v3; // ecx
  int v4; // eax
  survarium::base_player *v6; // [esp+0h] [ebp-10h]
  survarium::base_player *user; // [esp+4h] [ebp-Ch]

  params->interrupt_animation_player_tick = 1;
  user = survarium::weapon_core::get_user(this, (int)this);
  user->unsubscribe_animation_player(user, channel_id_on_animation_lexeme_end, this);
  v6 = survarium::weapon_core::get_user(v2, (int)this);
  survarium::weapon_user_dead_state::finalize(v3);
  v6->unsubscribe_animation_player(v6, channel_id_on_animation_lexeme_end, (const void *)(v4 + 1));
  this->m_is_in_sprint_transition = 0;
  return 1;
}
