void __thiscall vostok::physics::bullet_physics_world::tick(
        vostok::physics::bullet_physics_world *this,
        const unsigned int time_delta_in_ms,
        unsigned int current_time_in_ms)
{
  btSoftRigidDynamicsWorld *m_dynamicsWorld; // ecx
  vostok::physics::bullet_physics_world *v5; // ecx
  btSparseSdf<3> *v6; // ecx
  float v7; // [esp+0h] [ebp-10h]

  this->m_dynamicsWorld->current_time_in_ms = current_time_in_ms;
  m_dynamicsWorld = this->m_dynamicsWorld;
  physics_current_time_ms = current_time_in_ms;
  v7 = (double)time_delta_in_ms * 0.001;
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))m_dynamicsWorld->stepSimulation)(LODWORD(v7), 0, 0.016666668);
  vostok::physics::bullet_physics_world::notify_about_contact(v5, (int)this);
  btSparseSdf<3>::GarbageCollect(v6, &this->m_softBodyWorldInfo->m_sparsesdf);
}
