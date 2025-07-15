void __thiscall survarium::portable_interactive_object_core::deactivate(
        survarium::portable_interactive_object_core *this,
        const bool real_remove)
{
  survarium::base_player *v3; // ecx
  survarium::base_player *v4; // ecx
  survarium::base_player *v5; // ecx
  survarium::base_player *v6; // ecx
  survarium::base_player *v7; // ecx
  survarium::base_player *v8; // ecx
  survarium::base_player *v9; // ecx
  survarium::base_player *v10; // ecx
  survarium::base_player *v11; // ecx
  vostok::ai::fsm_state *m_current_state; // ecx
  _RTL_CRITICAL_SECTION **v13; // eax
  survarium::damage_subscriber *v14; // [esp+0h] [ebp-8h]

  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_user,
    "Left toe",
    (int)this);
  survarium::base_player::unsubscribe_animation_player(v3, (int)this->m_user, "Left heel", (int)this);
  survarium::base_player::unsubscribe_animation_player(v4, (int)this->m_user, "Right toe", (int)this);
  survarium::base_player::unsubscribe_animation_player(v5, (int)this->m_user, "Right heel", (int)this);
  survarium::base_player::unsubscribe_animation_player(v6, (int)this->m_user, "left_hand_ik", (int)this);
  survarium::base_player::unsubscribe_animation_player(v7, (int)this->m_user, "right_hand_ik", (int)this);
  survarium::base_player::unsubscribe_animation_player(v8, (int)this->m_user, "left_hand_corrector", (int)this);
  survarium::base_player::unsubscribe_animation_player(v9, (int)this->m_user, "right_hand_corrector", (int)this);
  survarium::base_player::unsubscribe_animation_player(v10, (int)this->m_user, "player_sound_events", (int)this);
  survarium::base_player::unsubscribe_animation_player(
    v11,
    (vostok::animation::reserved_channel_ids_enum)this->m_user_animations_selector.m_user,
    (const void *)2,
    (int)&this->m_user_animations_selector);
  m_current_state = this->m_user_animations_selector.m_logic.m_current_state;
  if ( m_current_state )
  {
    m_current_state->finalize(m_current_state);
    this->m_user_animations_selector.m_logic.m_current_state = 0;
  }
  v13 = (_RTL_CRITICAL_SECTION **)this->m_user->damage_model(&this->m_user->survarium::inventory_holder);
  survarium::damage_model::unsubscribe_from_damage(
    (survarium::damage_model *)&this->m_user_hit_animations_selector.m_damage_subscriber,
    *v13,
    (survarium::hit_type_enum)&this->m_user_hit_animations_selector.m_damage_subscriber,
    v14);
  if ( real_remove )
    this->m_user = 0;
}
