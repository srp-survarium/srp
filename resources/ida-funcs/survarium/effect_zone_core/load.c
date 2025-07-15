void __thiscall survarium::effect_zone_core::load(
        survarium::effect_zone_core *this,
        const vostok::configs::binary_config_value *t)
{
  survarium::collision_sensor::load(this, t);
  this->m_invulnerability_duration = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                     t,
                                                     "invulnerability_duration")->data.pointer;
  this->m_invulnerability_attenuation = (unsigned int)vostok::configs::binary_config_value::operator[](
                                                        t,
                                                        "invulnerability_attenuation")->data.pointer;
  this->m_team_owner = (survarium::game_team_id)vostok::configs::binary_config_value::operator[](t, "team")->data.pointer;
}
