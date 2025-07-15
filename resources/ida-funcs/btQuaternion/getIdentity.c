const btQuaternion *__cdecl btQuaternion::getIdentity()
{
  if ( (`btQuaternion::getIdentity'::`2'::`local static guard' & 1) == 0 )
  {
    `btQuaternion::getIdentity'::`2'::`local static guard' |= 1u;
    `btQuaternion::getIdentity'::`2'::identityQuat.m_floats[0] = 0.0;
    `btQuaternion::getIdentity'::`2'::identityQuat.m_floats[1] = 0.0;
    `btQuaternion::getIdentity'::`2'::identityQuat.m_floats[2] = 0.0;
    `btQuaternion::getIdentity'::`2'::identityQuat.m_floats[3] = s_bm_current_air_resistance;
  }
  return &`btQuaternion::getIdentity'::`2'::identityQuat;
}
