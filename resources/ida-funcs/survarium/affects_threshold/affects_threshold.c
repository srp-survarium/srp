void __thiscall survarium::affects_threshold::affects_threshold(
        survarium::affects_threshold *this,
        float value,
        unsigned int affects_count,
        survarium::body_part_parameters *const bodypart)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->next = 0;
  this->m_value = value;
  this->m_affects_count = affects_count;
  this->m_bodypart = bodypart;
}
