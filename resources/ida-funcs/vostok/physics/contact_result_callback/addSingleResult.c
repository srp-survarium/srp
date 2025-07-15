double __thiscall vostok::physics::contact_result_callback::addSingleResult(
        vostok::physics::contact_result_callback *this,
        btManifoldPoint *cp,
        const btCollisionObject *__formal,
        int a4,
        int a5,
        const btCollisionObject *a6,
        int a7,
        int a8)
{
  if ( cp->m_distance1 < 0.0 )
    this->has_contact = 1;
  return 1.0;
}
