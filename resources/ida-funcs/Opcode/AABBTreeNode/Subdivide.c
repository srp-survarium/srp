char __thiscall Opcode::AABBTreeNode::Subdivide(
        Opcode::AABBTreeNode *this,
        Opcode::AABBTreeNode *builder,
        Opcode::AABBTreeBuilder *a4)
{
  Opcode::AABBTreeNode *v6; // esi
  unsigned int *p_mNbPrimitives; // edi
  unsigned int mNbPrimitives; // eax
  unsigned int mRules; // eax
  unsigned int v10; // eax
  Opcode::AABBTreeBuilder *v11; // edi
  int v12; // edi
  void *mNodeBase; // eax
  bool v14; // zf
  Opcode::AABBTreeBuilder_vtbl *v15; // edx
  double v16; // st7
  Opcode::AABBTreeBuilder_vtbl *v17; // eax
  double v18; // st7
  Opcode::AABBTreeBuilder_vtbl *v19; // eax
  double v20; // st7
  double v21; // st7
  Opcode::AABBTreeBuilder_vtbl *v22; // edx
  bool v23; // cc
  int v24; // eax
  float v25; // xmm1_4
  unsigned int i; // edi
  float *v27; // edx
  int *v28; // eax
  int v29; // ecx
  Opcode::AABBTreeNode *v30; // eax
  unsigned int v31; // ecx
  int v32; // eax
  IceMaths::Point mExtents; // [esp+4h] [ebp-28h] BYREF
  IceMaths::Point v34; // [esp+10h] [ebp-1Ch] BYREF
  float v35; // [esp+1Ch] [ebp-10h]
  float v36; // [esp+20h] [ebp-Ch]
  unsigned int v37; // [esp+24h] [ebp-8h]
  unsigned int j; // [esp+28h] [ebp-4h]
  unsigned int *v39; // [esp+38h] [ebp+Ch]

  if ( !a4 )
    return 0;
  v6 = builder;
  p_mNbPrimitives = &builder->mNbPrimitives;
  mNbPrimitives = builder->mNbPrimitives;
  v39 = &builder->mNbPrimitives;
  if ( mNbPrimitives == 1
    || !a4->ValidateSubdivision(a4, builder->mNodePrimitives, mNbPrimitives, (const IceMaths::AABB *)builder) )
  {
    return 1;
  }
  mRules = a4->mSettings.mRules;
  if ( (mRules & 1) != 0 )
  {
    mExtents = builder->mBV.mExtents;
    v10 = mExtents.y > mExtents.x;
    if ( mExtents.z > *(&mExtents.x + v10) )
      v10 = 2;
    v6 = builder;
LABEL_9:
    v11 = a4;
    goto LABEL_10;
  }
  if ( (mRules & 2) != 0 )
  {
    j = 0;
    v14 = *p_mNbPrimitives == 0;
    memset((void *)&v34, 0, sizeof(v34));
    if ( !v14 )
    {
      do
      {
        v15 = a4->__vftable;
        v37 = builder->mNodePrimitives[j];
        v16 = ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, _DWORD))v15->GetSplittingValue)(
                a4,
                v37,
                0);
        v17 = a4->__vftable;
        v34.x = v16 + v34.x;
        v18 = ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, int))v17->GetSplittingValue)(a4, v37, 1);
        v19 = a4->__vftable;
        v34.y = v18 + v34.y;
        v20 = ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, int))v19->GetSplittingValue)(a4, v37, 2);
        ++j;
        v34.z = v20 + v34.z;
      }
      while ( j < *p_mNbPrimitives );
    }
    v35 = *(float *)p_mNbPrimitives;
    j = 0;
    v21 = 1.0 / (double)LODWORD(v35);
    memset((void *)&mExtents, 0, sizeof(mExtents));
    v34.x = v34.x * v21;
    v34.y = v34.y * v21;
    v34.z = v21 * v34.z;
    if ( v35 != 0.0 )
    {
      do
      {
        v22 = a4->__vftable;
        v37 = builder->mNodePrimitives[j];
        v36 = v22->GetSplittingValue(a4, v37, 0);
        v35 = a4->GetSplittingValue(a4, v37, 1u);
        *(float *)&v37 = a4->GetSplittingValue(a4, v37, 2u);
        ++j;
        mExtents.x = (float)((float)(v36 - v34.x) * (float)(v36 - v34.x)) + mExtents.x;
        mExtents.y = (float)((float)(v35 - v34.y) * (float)(v35 - v34.y)) + mExtents.y;
        mExtents.z = (float)((float)(*(float *)&v37 - v34.z) * (float)(*(float *)&v37 - v34.z)) + mExtents.z;
      }
      while ( j < *p_mNbPrimitives );
    }
    LODWORD(v35) = *p_mNbPrimitives - 1;
    *(float *)&v37 = 1.0 / (double)LODWORD(v35);
    v23 = (float)(*(float *)&v37 * mExtents.y) <= (float)(*(float *)&v37 * mExtents.x);
    mExtents.z = *(float *)&v37 * mExtents.z;
    mExtents.x = *(float *)&v37 * mExtents.x;
    mExtents.y = *(float *)&v37 * mExtents.y;
    v10 = !v23;
    if ( mExtents.z > *(&mExtents.x + v10) )
      v10 = 2;
    goto LABEL_9;
  }
  if ( (mRules & 8) != 0 )
  {
    v11 = a4;
    mExtents.x = (double)(unsigned int)Opcode::AABBTreeNode::Split(builder, a4, 0) / (double)*v39;
    mExtents.y = (double)(unsigned int)Opcode::AABBTreeNode::Split(builder, a4, 1u) / (double)*v39;
    v24 = Opcode::AABBTreeNode::Split(builder, a4, 2u);
    v35 = *(float *)&v24;
    v35 = *(float *)v39;
    v25 = mExtents.y - 0.5;
    v23 = (float)((float)(mExtents.x - 0.5) * (float)(mExtents.x - 0.5)) <= (float)(v25 * v25);
    mExtents.x = (float)(mExtents.x - 0.5) * (float)(mExtents.x - 0.5);
    mExtents.y = v25 * v25;
    mExtents.z = (double)(unsigned int)v24 / (double)LODWORD(v35);
    mExtents.z = (float)(mExtents.z - 0.5) * (float)(mExtents.z - 0.5);
    v10 = !v23;
    if ( *(&mExtents.x + v10) > mExtents.z )
      v10 = 2;
LABEL_10:
    v12 = Opcode::AABBTreeNode::Split(v6, v11, v10);
    if ( v12 && v12 != *v39 )
    {
LABEL_14:
      v6 = builder;
      goto LABEL_15;
    }
LABEL_12:
    if ( a4->mSettings.mLimit != 1 )
      return 1;
    ++a4->mNbInvalidSplits;
    v12 = *v39 >> 1;
    goto LABEL_14;
  }
  if ( (mRules & 4) != 0 )
  {
    mExtents.x = 0.0;
    v34 = builder->mBV.mExtents;
    LODWORD(mExtents.y) = 1;
    LODWORD(mExtents.z) = 2;
    v37 = 3;
    do
    {
      for ( i = 0; i < 2; ++i )
      {
        v27 = &mExtents.y + i;
        v28 = (int *)(&mExtents.x + i);
        v29 = *v28;
        if ( *(&v34.x + *(_DWORD *)v27) > *(&v34.x + *v28) )
        {
          *v28 = *(_DWORD *)v27;
          *(_DWORD *)v27 = v29;
        }
      }
      --v37;
    }
    while ( *(float *)&v37 != 0.0 );
    for ( j = 0; j != 3; ++j )
    {
      v12 = Opcode::AABBTreeNode::Split(builder, a4, *((_DWORD *)&mExtents.x + j));
      if ( v12 && v12 != *v39 )
        goto LABEL_14;
    }
    goto LABEL_12;
  }
  if ( (mRules & 0x10) == 0 )
    return 0;
  v12 = *p_mNbPrimitives >> 1;
LABEL_15:
  mNodeBase = a4->mNodeBase;
  if ( mNodeBase )
  {
    v6->mPos = ((unsigned int)mNodeBase + 36 * a4->mCount - 36) | 1;
LABEL_43:
    a4->mCount += 2;
    v31 = v6->mPos & 0xFFFFFFFE;
    v32 = v31 != 0 ? v31 + 36 : 0;
    *(_DWORD *)(v31 + 28) = v6->mNodePrimitives;
    *(_DWORD *)(v31 + 32) = v12;
    *(_DWORD *)(v32 + 28) = &v6->mNodePrimitives[v12];
    *(_DWORD *)(v32 + 32) = *v39 - v12;
    return 1;
  }
  v30 = vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>(
          2u,
          a4->m_allocator,
          "Opcode::AABBTreeNode::Subdivide",
          (const char *const)0x13D);
  if ( v30 )
  {
    v6->mPos = (unsigned int)v30;
    goto LABEL_43;
  }
  return 0;
}
