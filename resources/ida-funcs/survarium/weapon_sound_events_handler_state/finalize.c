void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v3,
    &this->gap140 + 1);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::pistol_weapon_core_fire_state::finalize((survarium::weapon_core_fire_state *)this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v3,
    &this->gap140 + 1);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::weapon_core_chamber_a_round_state::finalize((survarium::weapon_core_chamber_a_round_state *)this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v3,
    &this->gap140 + 1);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::weapon_core_chamber_a_round_state::finalize(this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v3,
    &this->gap140 + 1);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::pistol_weapon_core_fire_state::finalize(this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_reload_state> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_reload_state> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_fire_state>::subscribe_sound_events_channel(
    v3,
    &this->gap140 + 1);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::weapon_core_chamber_a_round_state::finalize((survarium::weapon_core_chamber_a_round_state *)this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_finish_substate>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate>::subscribe_sound_events_channel(
    v3,
    &this->m_animation_ended);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::weapon_core_shotgun_reload_finish_substate::finalize(this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_one_round_substate> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate>::subscribe_sound_events_channel(
    v3,
    p_m_sound_effect);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::weapon_core_shotgun_reload_finish_substate::finalize((survarium::weapon_core_shotgun_reload_start_substate *)this);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state>::finalize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *this)
{
  survarium::weapon_sound_effect *p_m_sound_effect; // esi
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_show_state> *v3; // ecx
  survarium::weapon_sound_effect *v4; // ecx

  p_m_sound_effect = &this->m_sound_effect;
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    (int)this->m_weapon->m_user,
    "sound_events",
    &this->m_sound_effect);
  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_hide_state>::subscribe_sound_events_channel(
    v3,
    &this->gap138 + 1);
  survarium::weapon_sound_effect::finalize(v4, (int)p_m_sound_effect);
  survarium::weapon_core_hide_state::finalize((survarium::weapon_core_hide_state *)this);
}
