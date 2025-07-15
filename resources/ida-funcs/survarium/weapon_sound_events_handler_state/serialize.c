void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_fire_state> *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect *v4; // ecx

  survarium::double_barreled_weapon_core_fire_state::serialize(this, writer, client_writer);
  survarium::weapon_sound_effect::serialize(v4, (int)&this->m_sound_effect, client_writer);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::double_barreled_weapon_core_reload_state> *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect *v4; // ecx

  survarium::weapon_core_animation_end_aware_state::serialize(this, writer, client_writer);
  survarium::weapon_sound_effect::serialize(v4, (int)&this->m_sound_effect, client_writer);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::pistol_weapon_core_fire_state> *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect *v4; // ecx

  survarium::pistol_weapon_core_fire_state::serialize(this, writer, client_writer);
  survarium::weapon_sound_effect::serialize(v4, (int)&this->m_sound_effect, client_writer);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_chamber_a_round_state> *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect *v4; // ecx

  survarium::weapon_core_animation_end_aware_state::serialize(this, writer, client_writer);
  survarium::weapon_sound_effect::serialize(v4, (int)&this->m_sound_effect, client_writer);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_fire_state> *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect *v4; // ecx

  survarium::weapon_core_fire_state_base::serialize(this, writer, client_writer);
  survarium::weapon_sound_effect::serialize(v4, (int)&this->m_sound_effect, client_writer);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_shotgun_reload_start_substate> *this,
        const vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect::serialize(
    (survarium::weapon_sound_effect *)this,
    (int)&this->m_sound_effect,
    client_writer);
}


void __thiscall survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state>::serialize(
        survarium::weapon_sound_events_handler_state<survarium::weapon_core_show_state> *this,
        vostok::network_core::buffer_writer *writer,
        vostok::network_core::buffer_writer *client_writer)
{
  survarium::weapon_sound_effect *v4; // ecx

  survarium::weapon_core_animation_end_aware_state::serialize(this, writer, client_writer);
  survarium::weapon_sound_effect::serialize(v4, (int)&this->m_sound_effect, client_writer);
}
