const btTransform *__cdecl btTransform::getIdentity()
{
  __m128i v1; // [esp+0h] [ebp-10h] BYREF

  if ( (`btTransform::getIdentity'::`2'::`local static guard' & 1) == 0 )
  {
    `btTransform::getIdentity'::`2'::`local static guard' |= 1u;
    memset(&v1, 0, sizeof(v1));
    `btTransform::getIdentity'::`2'::identityTransform.m_basis = *btMatrix3x3::getIdentity();
    `btTransform::getIdentity'::`2'::identityTransform.m_origin = (btVector3)_mm_load_si128(&v1);
  }
  return &`btTransform::getIdentity'::`2'::identityTransform;
}
