void __thiscall survarium::generic_anomaly_core::deactivate(survarium::generic_anomaly_core *this)
{
  survarium::anomaly_state **p_m_current_state; // ebx
  survarium::anomaly_state *m_current_state; // edi
  unsigned int i; // ebx
  survarium::collision_geometry_subscriber *v5; // edi
  survarium::collision_geometry_subscriber v6; // eax

  p_m_current_state = &this->m_current_state;
  m_current_state = this->m_current_state;
  if ( m_current_state )
  {
    survarium::anomaly_state::finalize((survarium::anomaly_state *)this, (int)m_current_state, 0);
    *p_m_current_state = 0;
  }
  if ( this->artefacts_enabled )
  {
    for ( i = 0; i < this->m_artefact_containers._M_impl._M_finish - this->m_artefact_containers._M_impl._M_start; ++i )
    {
      v5 = (survarium::collision_geometry_subscriber *)this->m_artefact_containers._M_impl._M_start[i];
      survarium::usable_object::remove((survarium::usable_object *)this, v5);
      v6.__vftable = v5->__vftable;
      BYTE1(v5[24].__vftable) = 0;
      v6.__vftable[3].~survarium::collision_geometry_subscriber(v5);
    }
  }
  this->on_deactivation(this);
}
