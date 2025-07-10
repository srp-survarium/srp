btDbvtAabbMm *__usercall VolumeOf@<eax>(const btSoftBody::Face *f@<eax>, btDbvtAabbMm *a2@<edi>, float margin)
{
  btVector3 *p_m_x; // ecx
  btVector3 *v4; // edx
  btVector3 *ppts[3]; // [esp+10h] [ebp-Ch] BYREF

  p_m_x = &f->m_n[0]->m_x;
  v4 = &f->m_n[1]->m_x;
  ppts[2] = &f->m_n[2]->m_x;
  ppts[0] = p_m_x;
  ppts[1] = v4;
  btDbvtAabbMm::FromPoints((const btVector3 **)ppts, a2);
  a2->mi.mVec128.m128_f32[0] = a2->mi.mVec128.m128_f32[0] - margin;
  a2->mi.mVec128.m128_f32[1] = a2->mi.mVec128.m128_f32[1] - margin;
  a2->mi.mVec128.m128_f32[2] = a2->mi.mVec128.m128_f32[2] - margin;
  a2->mx.mVec128.m128_f32[0] = a2->mx.mVec128.m128_f32[0] + margin;
  a2->mx.mVec128.m128_f32[1] = a2->mx.mVec128.m128_f32[1] + margin;
  a2->mx.mVec128.m128_f32[2] = a2->mx.mVec128.m128_f32[2] + margin;
  return a2;
}
