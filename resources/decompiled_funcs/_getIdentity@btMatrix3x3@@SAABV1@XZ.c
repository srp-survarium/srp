const btMatrix3x3 *__cdecl btMatrix3x3::getIdentity()
{
  if ( (`btMatrix3x3::getIdentity'::`2'::`local static guard' & 1) == 0 )
  {
    `btMatrix3x3::getIdentity'::`2'::`local static guard' |= 1u;
    `btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[0].mVec128.m128_u64[0] = (unsigned int)clear_value;
    `btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[0].mVec128.m128_u64[1] = 0;
    `btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[1].mVec128.m128_i32[0] = 0;
    *(unsigned __int64 *)((char *)`btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[1].mVec128.m128_u64 + 4) = (unsigned int)clear_value;
    `btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[1].mVec128.m128_i32[3] = 0;
    `btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[2].mVec128.m128_u64[0] = 0;
    `btMatrix3x3::getIdentity'::`2'::identityMatrix.m_el[2].mVec128.m128_u64[1] = (unsigned int)clear_value;
  }
  return &`btMatrix3x3::getIdentity'::`2'::identityMatrix;
}
