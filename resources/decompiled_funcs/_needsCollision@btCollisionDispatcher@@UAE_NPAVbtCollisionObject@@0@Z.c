bool __thiscall btCollisionDispatcher::needsCollision(
        btCollisionDispatcher *this,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  int m_activationState1; // eax
  int v4; // eax
  bool result; // al

  m_activationState1 = body0->m_activationState1;
  result = (m_activationState1 != 2 && m_activationState1 != 5 || (v4 = body1->m_activationState1, v4 != 2) && v4 != 5)
        && (!body0->m_checkCollideWith || body0->checkCollideWithOverride(body0, body1));
  return result;
}
