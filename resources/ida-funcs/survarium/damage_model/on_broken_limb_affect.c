void __thiscall survarium::damage_model::on_broken_limb_affect(
        survarium::damage_model *this,
        const char *bodypart,
        const survarium::hit_affects_type_enum affect,
        const survarium::affect_event_type_enum type)
{
  if ( affect == affects_type_leg_damage )
  {
    if ( type )
      --this->m_broken_legs_count;
    else
      ++this->m_broken_legs_count;
  }
  else if ( type )
  {
    --this->m_broken_hands_count;
  }
  else
  {
    ++this->m_broken_hands_count;
  }
}
