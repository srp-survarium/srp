btDbvtNode *__usercall sort@<eax>(btDbvtNode *n@<eax>, btDbvtNode **r)
{
  btDbvtNode *parent; // ecx
  BOOL v3; // edx
  BOOL v4; // esi
  btDbvtNode *v5; // edi
  unsigned __int64 v6; // xmm0_8
  unsigned __int64 v7; // xmm1_8
  unsigned __int64 v8; // xmm2_8
  unsigned __int64 v9; // xmm3_8
  int v10; // [esp+10h] [ebp-4h]

  parent = n->parent;
  if ( parent > n )
  {
    v3 = parent->childs[1] == n;
    v4 = parent->childs[1] != n;
    v10 = *(&parent->dataAsInt + v4);
    v5 = parent->parent;
    if ( v5 )
      *(&v5->dataAsInt + (v5->childs[1] == parent)) = (int)n;
    else
      *r = n;
    *(_DWORD *)(v10 + 32) = n;
    parent->parent = n;
    n->parent = v5;
    parent->36 = n->36;
    *(_DWORD *)(n->dataAsInt + 32) = parent;
    n->childs[1]->parent = parent;
    *(&n->dataAsInt + v3) = (int)parent;
    *(&n->dataAsInt + v4) = v10;
    v6 = parent->volume.mi.mVec128.m128_u64[0];
    v7 = parent->volume.mi.mVec128.m128_u64[1];
    v8 = parent->volume.mx.mVec128.m128_u64[0];
    v9 = parent->volume.mx.mVec128.m128_u64[1];
    parent->volume.mi.mVec128.m128_u64[0] = n->volume.mi.mVec128.m128_u64[0];
    parent->volume.mi.mVec128.m128_u64[1] = n->volume.mi.mVec128.m128_u64[1];
    parent->volume.mx = n->volume.mx;
    n->volume.mi.mVec128.m128_u64[0] = v6;
    n->volume.mi.mVec128.m128_u64[1] = v7;
    n->volume.mx.mVec128.m128_u64[0] = v8;
    n->volume.mx.mVec128.m128_u64[1] = v9;
    return parent;
  }
  return n;
}
