void __thiscall vostok::particle::particle_emitter::particle_emitter(vostok::particle::particle_emitter *this)
{
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)this);
  this->m_particle_lifetime_curve.m_line.m_upper.points.pointer = 0;
  HIDWORD(this->m_particle_lifetime_curve.m_line.m_upper.points.max_storage) = 0;
  this->m_particle_lifetime_curve.m_line.m_lower.points.pointer = 0;
  HIDWORD(this->m_particle_lifetime_curve.m_line.m_lower.points.max_storage) = 0;
  this->m_particle_lifetime_curve.m_evaluate_type = age_evaluate_type;
  this->m_particle_spawn_rate_curve.m_line.m_upper.points.pointer = 0;
  HIDWORD(this->m_particle_spawn_rate_curve.m_line.m_upper.points.max_storage) = 0;
  this->m_particle_spawn_rate_curve.m_line.m_lower.points.pointer = 0;
  HIDWORD(this->m_particle_spawn_rate_curve.m_line.m_lower.points.max_storage) = 0;
  this->m_particle_spawn_rate_curve.m_evaluate_type = age_evaluate_type;
  this->m_source_action.pointer = 0;
  HIDWORD(this->m_source_action.max_storage) = 0;
  this->m_target_action.pointer = 0;
  HIDWORD(this->m_target_action.max_storage) = 0;
  this->m_data_type_action.pointer = 0;
  HIDWORD(this->m_data_type_action.max_storage) = 0;
  this->m_actions.pointer = 0;
  HIDWORD(this->m_actions.max_storage) = 0;
  this->m_last_action.pointer = 0;
  HIDWORD(this->m_last_action.max_storage) = 0;
  this->m_particle_system.pointer = 0;
  HIDWORD(this->m_particle_system.max_storage) = 0;
  this->m_burst_entries.pointer = 0;
  HIDWORD(this->m_burst_entries.max_storage) = 0;
  this->m_event.pointer = 0;
  HIDWORD(this->m_event.max_storage) = 0;
}
