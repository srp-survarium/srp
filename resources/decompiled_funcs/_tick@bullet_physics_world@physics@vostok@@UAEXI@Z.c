void __thiscall vostok::physics::bullet_physics_world::tick(
        vostok::physics::bullet_physics_world *this,
        unsigned int current_time_in_ms)
{
  double v3; // st7
  unsigned int v4; // eax
  vostok::physics::bullet_physics_world *v5; // ecx
  float current_time_in_msa; // [esp+14h] [ebp+4h]

  v3 = (double)current_time_in_ms * 0.001;
  this->m_last_frame_delta = (v3 - this->m_last_frame_time) * 0.1 + this->m_last_frame_delta * 0.89999998;
  current_time_in_msa = this->m_last_frame_delta;
  this->m_last_frame_time = v3;
  v4 = vostok::math::floor((float)(current_time_in_msa * 60.0) + 0.5);
  if ( v4 > s_physics_max_substeps_value )
    v4 = 1;
  ((void (__stdcall *)(_DWORD, unsigned int, _DWORD))this->m_dynamicsWorld->stepSimulation)(
    LODWORD(current_time_in_msa),
    v4,
    0.016666668);
  vostok::physics::bullet_physics_world::notify_about_contact(v5, this);
  btSparseSdf<3>::GarbageCollect(&this->m_softBodyWorldInfo->m_sparsesdf, &this->m_softBodyWorldInfo->m_sparsesdf);
}
