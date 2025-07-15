const btTransform *__cdecl btTransform::getIdentity()
{
  if ( (`btTransform::getIdentity'::`2'::`local static guard' & 1) == 0 )
  {
    `btTransform::getIdentity'::`2'::`local static guard' |= 1u;
    `btTransform::getIdentity'::`2'::identityTransform.m_basis = *btMatrix3x3::getIdentity();
    `btTransform::getIdentity'::`2'::identityTransform.m_origin.mVec128.m128_i32[0] = 0;
    `btTransform::getIdentity'::`2'::identityTransform.m_origin.mVec128.m128_i32[1] = 0;
    `btTransform::getIdentity'::`2'::identityTransform.m_origin.mVec128.m128_i32[2] = 0;
    `btTransform::getIdentity'::`2'::identityTransform.m_origin.mVec128.m128_i32[3] = 0;
  }
  return &`btTransform::getIdentity'::`2'::identityTransform;
}
