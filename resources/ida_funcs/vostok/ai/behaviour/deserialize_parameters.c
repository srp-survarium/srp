void __thiscall vostok::ai::behaviour::deserialize_parameters(
        vostok::ai::behaviour *this,
        vostok::configs::binary_config_value *options)
{
  const vostok::configs::binary_config_value *smell_parameters; // [esp+4h] [ebp-14h]
  const vostok::configs::binary_config_value *hearing_parameters; // [esp+8h] [ebp-10h]
  const vostok::configs::binary_config_value *damage_parameters; // [esp+Ch] [ebp-Ch]
  const vostok::configs::binary_config_value *interaction_parameters; // [esp+10h] [ebp-8h]
  const vostok::configs::binary_config_value *vision_parameters; // [esp+14h] [ebp-4h]

  if ( vostok::configs::binary_config_value::value_exists(options, "vision_sensor_parameters") )
  {
    vision_parameters = vostok::configs::binary_config_value::operator[](options, "vision_sensor_parameters");
    vostok::ai::vision_sensor_parameters::deserialize(&this->m_vision_parameters, vision_parameters);
  }
  if ( vostok::configs::binary_config_value::value_exists(options, "interaction_sensor_parameters") )
  {
    interaction_parameters = vostok::configs::binary_config_value::operator[](options, "interaction_sensor_parameters");
    vostok::ai::interaction_sensor_parameters::deserialize(&this->m_interaction_parameters, interaction_parameters);
  }
  if ( vostok::configs::binary_config_value::value_exists(options, "damage_sensor_parameters") )
  {
    damage_parameters = vostok::configs::binary_config_value::operator[](options, "damage_sensor_parameters");
    vostok::ai::damage_sensor_parameters::deserialize(&this->m_damage_parameters, damage_parameters);
  }
  if ( vostok::configs::binary_config_value::value_exists(options, "hearing_sensor_parameters") )
  {
    hearing_parameters = vostok::configs::binary_config_value::operator[](options, "hearing_sensor_parameters");
    vostok::ai::hearing_sensor_parameters::deserialize(&this->m_hearing_parameters, hearing_parameters);
  }
  if ( vostok::configs::binary_config_value::value_exists(options, "smell_sensor_parameters") )
  {
    smell_parameters = vostok::configs::binary_config_value::operator[](options, "smell_sensor_parameters");
    vostok::ai::smell_sensor_parameters::deserialize(&this->m_smell_parameters, smell_parameters);
  }
}
