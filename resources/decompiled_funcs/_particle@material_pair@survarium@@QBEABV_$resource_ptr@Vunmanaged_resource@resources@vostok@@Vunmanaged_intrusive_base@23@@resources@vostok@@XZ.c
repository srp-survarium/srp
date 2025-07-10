void __thiscall survarium::material_pair::particle(survarium::material_pair *this)
{
  survarium::game_camera *m_current_particle_idx; // [esp+4h] [ebp-Ch]

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( this->m_current_particle_idx == this->m_particles._M_impl._M_finish - this->m_particles._M_impl._M_start )
    this->m_current_particle_idx = 0;
  m_current_particle_idx = (survarium::game_camera *)this->m_current_particle_idx;
  this->m_current_particle_idx = (unsigned int)&m_current_particle_idx->__vftable + 1;
  survarium::weapon_user_dead_state::finalize(m_current_particle_idx);
}
