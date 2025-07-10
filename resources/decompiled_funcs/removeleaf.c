btDbvtNode *__usercall removeleaf@<eax>(btDbvtNode *leaf@<eax>, btDbvt *pdbvt)
{
  btDbvtNode *result; // eax
  btDbvtNode *parent; // edi
  btDbvtNode *v4; // esi
  btDbvtNode *v5; // eax
  btDbvtNode *m_free; // eax
  __m128 *p_mVec128; // eax
  __m128 *v8; // ecx
  __m128 v9; // xmm0
  btDbvtNode *v10; // eax
  unsigned __int64 v11; // [esp+30h] [ebp-20h]
  unsigned __int64 v12; // [esp+38h] [ebp-18h]
  unsigned __int64 v13; // [esp+40h] [ebp-10h]
  unsigned __int64 v14; // [esp+48h] [ebp-8h]

  if ( leaf == pdbvt->m_root )
  {
    pdbvt->m_root = 0;
    return 0;
  }
  else
  {
    parent = leaf->parent;
    v4 = parent->parent;
    v5 = (btDbvtNode *)parent->volume.mi.mVec128.m128_i32[10 - (parent->childs[1] == leaf)];
    if ( v4 )
    {
      *(&v4->dataAsInt + (v4->childs[1] == parent)) = (int)v5;
      v5->parent = v4;
      m_free = pdbvt->m_free;
      if ( m_free )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(m_free);
      }
      pdbvt->m_free = parent;
      while ( 1 )
      {
        p_mVec128 = &v4->childs[1]->volume.mi.mVec128;
        v8 = &v4->childs[0]->volume.mi.mVec128;
        v11 = v4->volume.mi.mVec128.m128_u64[0];
        v12 = v4->volume.mi.mVec128.m128_u64[1];
        v13 = v4->volume.mx.mVec128.m128_u64[0];
        v14 = v4->volume.mx.mVec128.m128_u64[1];
        v9 = _mm_max_ps(v8[1], p_mVec128[1]);
        v4->volume.mi.mVec128 = _mm_min_ps(*v8, *p_mVec128);
        v4->volume.mx.mVec128 = v9;
        if ( *(float *)&v11 == v4->volume.mi.mVec128.m128_f32[0]
          && *((float *)&v11 + 1) == v4->volume.mi.mVec128.m128_f32[1]
          && *(float *)&v12 == v4->volume.mi.mVec128.m128_f32[2]
          && *(float *)&v13 == v4->volume.mx.mVec128.m128_f32[0]
          && *((float *)&v13 + 1) == v4->volume.mx.mVec128.m128_f32[1]
          && *(float *)&v14 == v4->volume.mx.mVec128.m128_f32[2] )
        {
          break;
        }
        v4 = v4->parent;
        if ( !v4 )
          return pdbvt->m_root;
      }
      return v4;
    }
    else
    {
      pdbvt->m_root = v5;
      v5->parent = 0;
      v10 = pdbvt->m_free;
      if ( v10 )
      {
        ++gNumAlignedFree;
        sAlignedFreeFunc(v10);
      }
      result = pdbvt->m_root;
      pdbvt->m_free = parent;
    }
  }
  return result;
}
