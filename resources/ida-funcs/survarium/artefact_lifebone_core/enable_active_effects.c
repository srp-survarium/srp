void __thiscall survarium::artefact_lifebone_core::enable_active_effects(
        survarium::artefact_lifebone_core *this,
        unsigned int current_time_in_ms)
{
  survarium::damage_model *v3; // ecx
  survarium::damage_model *m_object; // ebp
  survarium::artefact_lifebone_core::removed_affect *m_begin; // edi
  survarium::artefact_lifebone_core::removed_affect *m_end; // ebx

  m_object = this->m_inventory->m_holder->damage_model(this->m_inventory->m_holder)->m_object;
  m_begin = this->m_config.active.removed_affects.m_begin;
  m_end = this->m_config.active.removed_affects.m_end;
  while ( m_begin != m_end )
  {
    survarium::damage_model::cancel_affect(
      v3,
      (int)m_object,
      current_time_in_ms,
      m_begin->body_part.m_begin,
      (const survarium::hit_affects_type_enum)m_begin->affect);
    ++m_begin;
  }
  this->m_time_left_to_deactivate = this->m_config.active.duration_ms;
}
