char __thiscall btCollisionDispatcher::needsCollision(
        btCollisionDispatcher *this,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  int m_activationState1; // eax
  char v4; // bl
  int v5; // eax
  char v6; // al

  m_activationState1 = body0->m_activationState1;
  v4 = 1;
  if ( m_activationState1 == 2 || m_activationState1 == 5 )
  {
    v5 = body1->m_activationState1;
    if ( v5 == 2 || v5 == 5 )
      return 0;
  }
  v6 = body0->m_checkCollideWith ? body0->checkCollideWithOverride(body0, body1) : 1;
  if ( !v6 )
    return 0;
  return v4;
}
