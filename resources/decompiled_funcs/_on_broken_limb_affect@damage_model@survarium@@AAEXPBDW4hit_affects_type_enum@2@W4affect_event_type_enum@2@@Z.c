void __thiscall survarium::damage_model::on_broken_limb_affect(
        survarium::damage_model *this,
        const char *bodypart,
        survarium::hit_affects_type_enum affect,
        survarium::affect_event_type_enum type)
{
  if ( affect == affects_type_leg_damage && vostok::strings::equal("left_leg", bodypart) )
  {
    this->m_broken_legs_count[0] = type == affect_applying;
  }
  else if ( affect == affects_type_leg_damage && vostok::strings::equal(&stru_975580.m_buffer[4], bodypart) )
  {
    this->m_broken_legs_count[1] = type == affect_applying;
  }
  else if ( affect == affects_type_hand_damage && vostok::strings::equal("left_hand", bodypart) )
  {
    this->m_broken_hands_count[0] = type == affect_applying;
  }
  else if ( affect == affects_type_hand_damage && vostok::strings::equal("right_hand", bodypart) )
  {
    this->m_broken_hands_count[1] = type == affect_applying;
  }
}
