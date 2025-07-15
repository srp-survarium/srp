btVector3 *__thiscall btDiscreteDynamicsWorld::getGravity(btDiscreteDynamicsWorld *this, btVector3 *result)
{
  btVector3 *v2; // eax

  v2 = result;
  *result = this->m_gravity;
  return v2;
}
