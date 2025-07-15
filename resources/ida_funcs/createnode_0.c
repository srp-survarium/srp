btDbvtNode *__usercall createnode_0@<eax>(
        btDbvt *pdbvt@<ecx>,
        const btDbvtAabbMm *volume0@<edi>,
        const btDbvtAabbMm *volume1@<esi>,
        btDbvtNode *parent)
{
  btDbvtNode *result; // eax
  btVector3 v5; // xmm0

  result = pdbvt->m_free;
  if ( result )
  {
    pdbvt->m_free = 0;
  }
  else
  {
    ++gNumAlignedAllocs;
    result = (btDbvtNode *)sAlignedAllocFunc(0x30u, 16);
  }
  result->parent = parent;
  result->dataAsInt = 0;
  result->childs[1] = 0;
  v5.mVec128 = _mm_max_ps(volume0->mx.mVec128, volume1->mx.mVec128);
  result->volume.mi.mVec128 = _mm_min_ps(volume0->mi.mVec128, volume1->mi.mVec128);
  result->volume.mx = (btVector3)v5.mVec128;
  return result;
}
