void __thiscall survarium::game_statistics_handler::on_player_killed(
        survarium::game_statistics_handler *this,
        unsigned int current_time_in_ms,
        unsigned __int8 killer,
        survarium::player_stances_enum killer_stance,
        unsigned __int16 killer_weapon_id,
        const vostok::math::float3 *killer_position,
        bool killer_is_in_anomaly,
        unsigned __int8 victim,
        const vostok::math::float3 *victim_position,
        bool victim_is_in_anomaly,
        survarium::profile_slot_enum weapon_slot,
        bool is_headshot,
        char victim_had_victory_item)
{
  int v14; // eax
  survarium::shared_statistics *v15; // [esp-4h] [ebp-8h]

  v14 = survarium::shared_statistics::kill_event_arg((vostok::resources::resource_ptr<survarium::base_player,vostok::resources::unmanaged_intrusive_base> *)this->m_game_world_core);
  survarium::shared_statistics::on_player_killed(
    v15,
    &this->m_shared_statistics,
    current_time_in_ms,
    killer,
    victim,
    is_headshot,
    victim_had_victory_item,
    v14);
}
