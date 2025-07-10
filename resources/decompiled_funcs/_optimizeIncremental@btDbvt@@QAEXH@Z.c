void __thiscall btDbvt::optimizeIncremental(btDbvt *this, btDbvt *passes, int passesa)
{
  int m_leaves; // eax
  btDbvt *v4; // ebx
  btDbvtNode *m_root; // esi
  char v6; // cl
  btDbvtNode *parent; // eax
  BOOL v8; // ecx
  BOOL v9; // edx
  btDbvtNode *v10; // edi
  unsigned __int64 v11; // xmm0_8
  unsigned __int64 v12; // xmm1_8
  unsigned __int64 v13; // xmm2_8
  unsigned __int64 v14; // xmm3_8
  unsigned int v15; // edx
  btDbvtNode *v16; // eax
  char i; // [esp+20h] [ebp-8h]
  int v18; // [esp+24h] [ebp-4h]

  m_leaves = passesa;
  v4 = passes;
  if ( passesa < 0 )
  {
    m_leaves = passes->m_leaves;
    passesa = m_leaves;
  }
  if ( passes->m_root && m_leaves > 0 )
  {
    do
    {
      m_root = v4->m_root;
      v6 = 0;
      for ( i = 0; m_root->childs[1]; m_root = parent->childs[v15 & 1] )
      {
        parent = m_root->parent;
        if ( parent <= m_root )
        {
          parent = m_root;
        }
        else
        {
          v8 = parent->childs[1] == m_root;
          v9 = parent->childs[1] != m_root;
          v18 = *(&parent->dataAsInt + v9);
          v10 = parent->parent;
          if ( v10 )
            *(&v10->dataAsInt + (v10->childs[1] == parent)) = (int)m_root;
          else
            v4->m_root = m_root;
          *(_DWORD *)(v18 + 32) = m_root;
          parent->parent = m_root;
          m_root->parent = v10;
          parent->dataAsInt = m_root->dataAsInt;
          parent->childs[1] = m_root->childs[1];
          *(_DWORD *)(m_root->dataAsInt + 32) = parent;
          m_root->childs[1]->parent = parent;
          *(&m_root->dataAsInt + v8) = (int)parent;
          v6 = i;
          *(&m_root->dataAsInt + v9) = v18;
          v11 = parent->volume.mi.mVec128.m128_u64[0];
          v12 = parent->volume.mi.mVec128.m128_u64[1];
          v13 = parent->volume.mx.mVec128.m128_u64[0];
          v14 = parent->volume.mx.mVec128.m128_u64[1];
          v4 = passes;
          parent->volume.mi.mVec128.m128_u64[0] = m_root->volume.mi.mVec128.m128_u64[0];
          parent->volume.mi.mVec128.m128_u64[1] = m_root->volume.mi.mVec128.m128_u64[1];
          parent->volume.mx.mVec128.m128_u64[0] = m_root->volume.mx.mVec128.m128_u64[0];
          parent->volume.mx.mVec128.m128_u64[1] = m_root->volume.mx.mVec128.m128_u64[1];
          m_root->volume.mi.mVec128.m128_u64[0] = v11;
          m_root->volume.mi.mVec128.m128_u64[1] = v12;
          m_root->volume.mx.mVec128.m128_u64[0] = v13;
          m_root->volume.mx.mVec128.m128_u64[1] = v14;
        }
        v15 = v4->m_opath >> v6;
        v6 = (v6 + 1) & 0x1F;
        i = v6;
      }
      v16 = removeleaf(m_root, v4);
      if ( v16 )
        v16 = v4->m_root;
      insertleaf(v16, v4, m_root);
      ++v4->m_opath;
      --passesa;
    }
    while ( passesa );
  }
}
