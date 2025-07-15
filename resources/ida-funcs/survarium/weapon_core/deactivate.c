void __thiscall survarium::weapon_core::deactivate(survarium::weapon_core *this)
{
  survarium::weapon_core *v1; // ecx
  survarium::base_player *v2; // eax
  survarium::weapon_core *v3; // ecx
  survarium::weapon_core *v4; // ecx
  survarium::weapon_core *v5; // ecx
  survarium::weapon_core *v6; // ecx
  survarium::game_camera *v7; // ecx
  int v8; // eax
  survarium::base_player *v9; // [esp+0h] [ebp-20h]
  survarium::base_player *v10; // [esp+4h] [ebp-1Ch]
  survarium::base_player *v11; // [esp+8h] [ebp-18h]
  survarium::base_player *v12; // [esp+Ch] [ebp-14h]
  survarium::base_player *v13; // [esp+10h] [ebp-10h]
  survarium::base_player *user; // [esp+14h] [ebp-Ch]

  if ( g_is_server )
  {
    user = survarium::weapon_core::get_user(this, (int)this);
    v2 = survarium::weapon_core::get_user(v1, (int)this);
    user->unsubscribe_animation_player(user, "sound_events", v2);
    v13 = survarium::weapon_core::get_user(v3, (int)this);
    v13->unsubscribe_animation_player(v13, "shell_extraction", this);
    v12 = survarium::weapon_core::get_user(v4, (int)this);
    v12->unsubscribe_animation_player(v12, "left_hand_corrector", this);
    v11 = survarium::weapon_core::get_user(v5, (int)this);
    v11->unsubscribe_animation_player(v11, "right_hand_corrector", this);
  }
  survarium::character_dispersion_calculator::set_character_dispersion_params(
    &this->m_dispersion_calculator.m_character_calculator,
    0);
  survarium::character_recoil_calculator::set_character_recoil_params(
    &this->m_recoil_calculator.m_character_calculator,
    0);
  this->m_breath_vibration_calculator.m_user = 0;
  survarium::breath_vibration_calculator::set_breath_holding_params(&this->m_breath_vibration_calculator, 0);
  survarium::weapon_core::instant_hide(this);
  this->m_user->unsubscribe_animation_player(this->m_user, "Right heel", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "Right toe", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "Left heel", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "Left toe", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "left_hand_ik", this);
  this->m_user->unsubscribe_animation_player(this->m_user, "right_hand_ik", this);
  if ( this->m_is_in_sprint_transition )
  {
    v10 = survarium::weapon_core::get_user(this, (int)this);
    v10->unsubscribe_animation_player(v10, channel_id_on_animation_lexeme_end, this);
    v9 = survarium::weapon_core::get_user(v6, (int)this);
    survarium::weapon_user_dead_state::finalize(v7);
    v9->unsubscribe_animation_player(v9, channel_id_on_animation_lexeme_end, (const void *)(v8 + 1));
  }
  survarium::weapon_user_animations_selector::deactivate(&this->m_user_animations_selector);
  vostok::ai::fsm::set_initial_state(this->m_logic, 0);
}
