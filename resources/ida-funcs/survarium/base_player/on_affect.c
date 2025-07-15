void __thiscall survarium::base_player::on_affect(
        survarium::base_player *this,
        const survarium::hit_affects_type_enum affect_type,
        const survarium::affect_event_type_enum event_type,
        unsigned int current_time_in_ms)
{
  if ( affect_type == affects_type_death && event_type == affect_applying
    || affect_type == affects_type_critical_poisoning && event_type == affect_recalling )
  {
    this->m_has_to_die = 1;
  }
}
