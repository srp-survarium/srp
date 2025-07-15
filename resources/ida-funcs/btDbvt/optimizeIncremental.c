void __thiscall btDbvt::optimizeIncremental(btDbvt *this, btDbvt *passes, int m_leaves)
{
  btDbvt *v3; // esi
  btDbvtNode *m_root; // ebx
  btDbvtNode *parent; // eax
  btDbvtNode *v6; // esi
  int v7; // edi
  int v8; // ecx
  btDbvtNode *v9; // edx
  btDbvtNode *v10; // eax
  BOOL v11; // [esp+18h] [ebp-28h]
  char v12; // [esp+1Ch] [ebp-24h]
  _BYTE v13[32]; // [esp+20h] [ebp-20h] BYREF

  v3 = passes;
  if ( m_leaves < 0 )
    m_leaves = passes->m_leaves;
  if ( passes->m_root && m_leaves > 0 )
  {
    do
    {
      m_root = v3->m_root;
      v12 = 0;
      while ( m_root->childs[1] )
      {
        parent = m_root->parent;
        if ( parent > m_root )
        {
          v6 = parent->parent;
          v11 = parent->childs[1] == m_root;
          v7 = 4 * (parent->childs[1] != m_root) + 36;
          v8 = *(int *)((char *)parent->volume.mi.mVec128.m128_i32 + v7);
          if ( v6 )
            *(&v6->dataAsInt + (v6->childs[1] == parent)) = (int)m_root;
          else
            passes->m_root = m_root;
          *(_DWORD *)(v8 + 32) = m_root;
          parent->parent = m_root;
          v9 = m_root->childs[0];
          m_root->parent = v6;
          parent->dataAsInt = (int)v9;
          parent->childs[1] = m_root->childs[1];
          *(_DWORD *)(m_root->dataAsInt + 32) = parent;
          m_root->childs[1]->parent = parent;
          *(&m_root->dataAsInt + v11) = (int)parent;
          *(int *)((char *)m_root->volume.mi.mVec128.m128_i32 + v7) = v8;
          qmemcpy(v13, parent, sizeof(v13));
          qmemcpy(parent, m_root, 0x20u);
          qmemcpy(m_root, v13, 0x20u);
          v3 = passes;
          m_root = parent;
        }
        m_root = m_root->childs[(v3->m_opath >> v12) & 1];
        v12 = (v12 + 1) & 0x1F;
      }
      v10 = removeleaf(m_root, v3);
      if ( v10 )
        v10 = v3->m_root;
      insertleaf(v10, v3, m_root);
      ++v3->m_opath;
      --m_leaves;
    }
    while ( m_leaves );
  }
}
