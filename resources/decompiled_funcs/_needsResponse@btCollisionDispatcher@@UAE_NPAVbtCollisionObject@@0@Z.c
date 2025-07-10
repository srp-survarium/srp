bool __thiscall btCollisionDispatcher::needsResponse(
        btCollisionDispatcher *this,
        btCollisionObject *body0,
        btCollisionObject *body1)
{
  int m_collisionFlags; // ecx
  int v4; // eax
  bool result; // al

  m_collisionFlags = body0->m_collisionFlags;
  result = 0;
  if ( (m_collisionFlags & 4) == 0 )
  {
    v4 = body1->m_collisionFlags;
    if ( (v4 & 4) == 0 && ((m_collisionFlags & 3) == 0 || (v4 & 3) == 0) )
      return 1;
  }
  return result;
}
