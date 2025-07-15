btDbvtNode *__usercall removeleaf@<eax>(btDbvtNode *leaf@<eax>, btDbvt *pdbvt)
{
  btDbvtNode *result; // eax
  btDbvtNode *parent; // esi
  __m128 *p_mVec128; // ebx
  btDbvtNode *v5; // eax
  __m128 *v6; // eax
  __m128 v7; // xmm1
  __m128 v8; // xmm2
  __m128 *v9; // ecx
  __m128 v10; // xmm0
  float v11[8]; // [esp+10h] [ebp-20h] BYREF

  if ( leaf == pdbvt->m_root )
  {
    pdbvt->m_root = 0;
    return 0;
  }
  else
  {
    parent = leaf->parent;
    p_mVec128 = &parent->parent->volume.mi.mVec128;
    v5 = (btDbvtNode *)parent->volume.mi.mVec128.m128_i32[10 - (parent->childs[1] == leaf)];
    if ( p_mVec128 )
    {
      p_mVec128[2].m128_i32[(p_mVec128[2].m128_i32[2] == (_DWORD)parent) + 1] = (int)v5;
      v5->parent = (btDbvtNode *)p_mVec128;
      btAlignedFreeInternal(pdbvt->m_free);
      pdbvt->m_free = parent;
      while ( 1 )
      {
        v6 = (__m128 *)p_mVec128[2].m128_i32[2];
        v7 = v6[1];
        v8 = *v6;
        qmemcpy(v11, p_mVec128, sizeof(v11));
        v9 = (__m128 *)p_mVec128[2].m128_i32[1];
        v10 = _mm_max_ps(v9[1], v7);
        *p_mVec128 = _mm_min_ps(*v9, v8);
        p_mVec128[1] = v10;
        if ( v11[0] == p_mVec128->m128_f32[0]
          && v11[1] == p_mVec128->m128_f32[1]
          && v11[2] == p_mVec128->m128_f32[2]
          && v11[4] == p_mVec128[1].m128_f32[0]
          && v11[5] == p_mVec128[1].m128_f32[1]
          && v11[6] == p_mVec128[1].m128_f32[2] )
        {
          break;
        }
        p_mVec128 = (__m128 *)p_mVec128[2].m128_i32[0];
        if ( !p_mVec128 )
          return pdbvt->m_root;
      }
      return (btDbvtNode *)p_mVec128;
    }
    else
    {
      pdbvt->m_root = v5;
      v5->parent = 0;
      btAlignedFreeInternal(pdbvt->m_free);
      result = pdbvt->m_root;
      pdbvt->m_free = parent;
    }
  }
  return result;
}
