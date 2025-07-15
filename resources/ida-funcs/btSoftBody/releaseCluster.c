void __thiscall btSoftBody::releaseCluster(btSoftBody *this, btSoftBody::Cluster *index)
{
  int v2; // ebp
  btSoftBody::Cluster **v3; // eax
  btSoftBody::Cluster *v4; // esi
  bool v5; // zf
  btDbvtNode *m_leaf; // ebx
  void *v7; // eax

  v2 = (int)index;
  v3 = (btSoftBody::Cluster **)index[2].m_com.mVec128.m128_i32[2];
  v4 = *v3;
  v5 = (*v3)->m_leaf == 0;
  index = *v3;
  if ( !v5 )
  {
    m_leaf = v4->m_leaf;
    removeleaf((btDbvt *)(v2 + 1028), m_leaf);
    v7 = *(void **)(v2 + 1032);
    if ( v7 )
    {
      ++gNumAlignedFree;
      sAlignedFreeFunc(v7);
    }
    --*(_DWORD *)(v2 + 1040);
    *(_DWORD *)(v2 + 1032) = m_leaf;
  }
  btConvexHullComputer::~btConvexHullComputer((btSoftBody::Cluster *)this, (int)v4);
  ++gNumAlignedFree;
  sAlignedFreeFunc(v4);
  btAlignedObjectArray<btSoftBody::Joint *>::remove(
    (btAlignedObjectArray<btSoftBody *> *)&index,
    v2 + 1068,
    (btSoftBody *const *)&index);
}
