void __thiscall btCollisionObject::activate(btCollisionObject *this)
{
  int m_activationState1; // eax

  if ( (this->m_collisionFlags & 3) == 0 )
  {
    m_activationState1 = this->m_activationState1;
    if ( m_activationState1 != 4 && m_activationState1 != 5 )
      this->m_activationState1 = 1;
    this->m_deactivationTime = 0.0;
  }
}
