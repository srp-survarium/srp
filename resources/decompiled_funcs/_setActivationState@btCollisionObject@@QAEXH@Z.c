void __thiscall btCollisionObject::setActivationState(btCollisionObject *this, int newState)
{
  int m_activationState1; // eax

  m_activationState1 = this->m_activationState1;
  if ( m_activationState1 != 4 && m_activationState1 != 5 )
    this->m_activationState1 = newState;
}
