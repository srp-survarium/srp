void __thiscall vostok::ai::behaviour::behaviour(
        vostok::ai::behaviour *this,
        const vostok::configs::binary_config_value *general_options,
        vostok::configs::binary_config_value *behaviour_options,
        vostok::ai::ai_world *world,
        unsigned int animations_count,
        unsigned int sounds_count,
        unsigned int movement_targets_count)
{
  survarium::game_camera *v7; // ecx
  const vostok::configs::binary_config_value *v8; // eax

  vostok::resources::unmanaged_resource::unmanaged_resource(&this->vostok::resources::unmanaged_resource, 1u);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_vision_parameters);
  this->__vftable = (vostok::ai::behaviour_vtbl *)&vostok::ai::behaviour::`vftable';
  vostok::ai::vision_sensor_parameters::vision_sensor_parameters(&this->m_vision_parameters);
  vostok::ai::interaction_sensor_parameters::interaction_sensor_parameters(&this->m_interaction_parameters);
  vostok::ai::damage_sensor_parameters::damage_sensor_parameters(&this->m_damage_parameters);
  vostok::ai::hearing_sensor_parameters::hearing_sensor_parameters(&this->m_hearing_parameters);
  vostok::ai::smell_sensor_parameters::smell_sensor_parameters(&this->m_smell_parameters);
  vostok::ai::pre_perceptors_filter::pre_perceptors_filter(&this->m_ignorance_filter);
  this->m_domain = 0;
  this->m_problem = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->m_goals.m_size);
  survarium::weapon_user_dead_state::finalize(v7);
  this->m_goals.m_first = 0;
  this->m_goals.m_last = 0;
  this->m_animations_count = animations_count;
  this->m_sounds_count = sounds_count;
  this->m_movement_targets_count = movement_targets_count;
  vostok::ai::behaviour::deserialize_parameters(this, behaviour_options);
  vostok::ai::behaviour::create_domain(this, general_options, world);
  vostok::ai::behaviour::create_problem(this, behaviour_options, world);
  vostok::ai::behaviour::create_goals(this, behaviour_options, world);
  if ( vostok::configs::binary_config_value::value_exists(behaviour_options, "pre_perceptors_filter") )
  {
    v8 = vostok::configs::binary_config_value::operator[](behaviour_options, "pre_perceptors_filter");
    vostok::ai::behaviour::fill_ignorance_filter(this, v8, world);
  }
}
