void __thiscall survarium::body_part_parameters::body_part_parameters(
        survarium::body_part_parameters *this,
        const char *name,
        float health,
        float regeneration_speed,
        float regeneration_timeout,
        bool can_be_assigned,
        survarium::damage_model *owner,
        unsigned __int8 damage_group)
{
  survarium::game_camera *v8; // ecx
  survarium::game_camera *v9; // ecx
  survarium::game_camera *v10; // ecx

  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->next = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_hit_types,
    &this->m_hit_types.m_size);
  survarium::weapon_user_dead_state::finalize(v8);
  this->m_hit_types.m_first = 0;
  this->m_hit_types.m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_thresholds,
    &this->m_thresholds.m_size);
  survarium::weapon_user_dead_state::finalize(v9);
  this->m_thresholds.m_first = 0;
  this->m_thresholds.m_last = 0;
  vostok::fixed_vector<vostok::console_commands::command_token,12>::fixed_vector<vostok::console_commands::command_token,12>((vostok::fixed_vector<stlp_std::pair<char *,unsigned int>,32> *)&this->m_affects);
  this->m_damage_model = owner;
  vostok::fixed_string<16>::fixed_string<16>(&this->m_name, name);
  this->m_max_health = health;
  this->m_health = health;
  this->m_regeneration_speed = regeneration_speed;
  this->m_last_hit_time = 0;
  this->m_last_hit_health = health;
  this->m_assignable = can_be_assigned;
  this->m_damage_group = damage_group;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_damage_protectors,
    &this->m_damage_protectors.m_size);
  survarium::weapon_user_dead_state::finalize(v10);
  this->m_damage_protectors.m_first = 0;
  this->m_damage_protectors.m_last = 0;
  this->m_regeneration_timeout = vostok::math::floor(1000.0 * regeneration_timeout);
}
