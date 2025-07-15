void __thiscall survarium::weapon_core_shotgun_reload_finish_substate::finalize(
        survarium::weapon_core_shotgun_reload_start_substate *this)
{
  survarium::base_player *v2; // ecx

  survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_one_round_substate>::unsubscribe_sound_events_channel((survarium::weapon_sound_events_channel_subscriber<survarium::weapon_core_shotgun_reload_start_substate> *)&this->m_animation_ended);
  survarium::base_player::unsubscribe_animation_player(
    v2,
    (vostok::animation::reserved_channel_ids_enum)this->m_weapon->m_user,
    (const void *)1,
    (int)this);
}
