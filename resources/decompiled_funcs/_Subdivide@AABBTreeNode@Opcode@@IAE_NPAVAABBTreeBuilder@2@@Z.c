bool __usercall Opcode::AABBTreeNode::Subdivide@<al>(
        Opcode::AABBTreeNode *this@<eax>,
        Opcode::AABBTreeBuilder *builder@<edi>)
{
  bool result; // al
  unsigned int mNbPrimitives; // eax
  unsigned int *p_mNbPrimitives; // ebp
  unsigned int *v6; // ecx
  unsigned int mRules; // eax
  float v8; // ecx
  float v9; // edx
  unsigned int v10; // eax
  int v11; // ebp
  bool v12; // zf
  unsigned int v13; // ebp
  void *mNodeBase; // ecx
  float v15; // xmm1_4
  unsigned int v16; // ebx
  unsigned int v17; // ebp
  double v18; // st7
  float (__thiscall *GetSplittingValue)(Opcode::AABBTreeBuilder *, unsigned int, unsigned int); // eax
  double v20; // st7
  float (__thiscall *v21)(Opcode::AABBTreeBuilder *, unsigned int, unsigned int); // eax
  double v22; // st7
  unsigned int v23; // ebx
  double v24; // st7
  float v25; // xmm2_4
  unsigned int v26; // ebp
  double v27; // st7
  unsigned int v28; // eax
  int v29; // eax
  Opcode::AABBTreeNode *v30; // ecx
  Opcode::AABBTreeNode *v31; // ecx
  Opcode::AABBTreeNode *v32; // ecx
  double v33; // st6
  unsigned int v34; // eax
  int v35; // eax
  float z; // edx
  float y; // ecx
  unsigned int v38; // ebx
  unsigned int v39; // eax
  unsigned int v40; // edx
  int v41; // ecx
  int v42; // ebp
  unsigned int v43; // ecx
  int v44; // ebp
  int i; // ebx
  int v46; // eax
  Opcode::AABBTreeNode *v47; // eax
  unsigned int v48; // eax
  unsigned int v49; // ecx
  unsigned int *v50; // [esp+3Ch] [ebp-28h]
  float v51; // [esp+40h] [ebp-24h]
  int v52; // [esp+40h] [ebp-24h]
  float Cy; // [esp+44h] [ebp-20h]
  unsigned int Tmp; // [esp+48h] [ebp-1Ch]
  float Tmpa; // [esp+48h] [ebp-1Ch]
  float Tmpb; // [esp+48h] [ebp-1Ch]
  unsigned int Tmpc; // [esp+48h] [ebp-1Ch]
  unsigned int Tmpd; // [esp+48h] [ebp-1Ch]
  unsigned int SortedAxis[3]; // [esp+4Ch] [ebp-18h] BYREF
  IceMaths::Point Extents; // [esp+58h] [ebp-Ch] BYREF

  if ( !builder )
    return 0;
  mNbPrimitives = this->mNbPrimitives;
  p_mNbPrimitives = &this->mNbPrimitives;
  v50 = &this->mNbPrimitives;
  if ( mNbPrimitives == 1
    || !builder->ValidateSubdivision(builder, this->mNodePrimitives, mNbPrimitives, (const IceMaths::AABB *)this) )
  {
    return 1;
  }
  mRules = builder->mSettings.mRules;
  if ( (mRules & 1) == 0 )
  {
    if ( (mRules & 2) != 0 )
    {
      v15 = 0.0;
      v16 = 0;
      memset(SortedAxis, 0, sizeof(SortedAxis));
      if ( *p_mNbPrimitives )
      {
        do
        {
          v17 = this->mNodePrimitives[v16];
          v18 = ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, _DWORD))builder->GetSplittingValue)(
                  builder,
                  v17,
                  0);
          GetSplittingValue = builder->GetSplittingValue;
          *(float *)SortedAxis = v18 + *(float *)SortedAxis;
          v20 = ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, int))GetSplittingValue)(
                  builder,
                  v17,
                  1);
          v21 = builder->GetSplittingValue;
          *(float *)&SortedAxis[1] = v20 + *(float *)&SortedAxis[1];
          v22 = ((double (__thiscall *)(Opcode::AABBTreeBuilder *, unsigned int, int))v21)(builder, v17, 2);
          v6 = &this->mNbPrimitives;
          ++v16;
          *(float *)&SortedAxis[2] = v22 + *(float *)&SortedAxis[2];
        }
        while ( v16 < *v50 );
        v15 = 0.0;
        p_mNbPrimitives = &this->mNbPrimitives;
      }
      Tmp = *p_mNbPrimitives;
      v23 = 0;
      v24 = 1.0 / (double)*p_mNbPrimitives;
      v25 = 0.0;
      memset((void *)&Extents, 0, sizeof(Extents));
      *(float *)SortedAxis = *(float *)SortedAxis * v24;
      *(float *)&SortedAxis[1] = *(float *)&SortedAxis[1] * v24;
      *(float *)&SortedAxis[2] = v24 * *(float *)&SortedAxis[2];
      if ( Tmp )
      {
        do
        {
          v26 = this->mNodePrimitives[v23];
          v51 = builder->GetSplittingValue(builder, v26, 0);
          Cy = builder->GetSplittingValue(builder, v26, 1u);
          Tmpa = builder->GetSplittingValue(builder, v26, 2u);
          v6 = &this->mNbPrimitives;
          v15 = (float)((float)(v51 - *(float *)SortedAxis) * (float)(v51 - *(float *)SortedAxis)) + Extents.x;
          v25 = (float)((float)(Cy - *(float *)&SortedAxis[1]) * (float)(Cy - *(float *)&SortedAxis[1])) + Extents.y;
          ++v23;
          Extents.x = v15;
          Extents.y = v25;
          Extents.z = (float)((float)(Tmpa - *(float *)&SortedAxis[2]) * (float)(Tmpa - *(float *)&SortedAxis[2]))
                    + Extents.z;
        }
        while ( v23 < *v50 );
      }
      v27 = 1.0 / (double)(*v50 - 1);
      Tmpb = v27;
      Extents.z = v27 * Extents.z;
      Extents.x = Tmpb * v15;
      Extents.y = Tmpb * v25;
      v28 = (float)(Tmpb * v25) > (float)(Tmpb * v15);
      if ( Extents.z > *(&Extents.x + v28) )
        v28 = 2;
      v29 = Opcode::AABBTreeNode::Split((Opcode::AABBTreeNode *)v6, (int)this, v28, builder);
      v11 = v29;
      if ( !v29 )
        goto LABEL_12;
      v12 = v29 == *v50;
    }
    else
    {
      if ( (mRules & 8) == 0 )
      {
        if ( (mRules & 4) == 0 )
        {
          if ( (mRules & 0x10) == 0 )
            return 0;
          v13 = *p_mNbPrimitives;
          goto LABEL_14;
        }
        z = this->mBV.mExtents.z;
        y = this->mBV.mExtents.y;
        Extents.x = this->mBV.mExtents.x;
        Extents.z = z;
        v38 = 0;
        v39 = 1;
        v40 = 2;
        Extents.y = y;
        SortedAxis[0] = 0;
        SortedAxis[1] = 1;
        SortedAxis[2] = 2;
        v41 = 4;
        v52 = 3;
        do
        {
          v42 = 4 * v38;
          if ( *(float *)((char *)&Extents.x + v41) > *(&Extents.x + v38) )
          {
            v43 = v38;
            v38 = v39;
            v39 = v43;
            v41 = v42;
          }
          v44 = 4 * v40;
          if ( *(&Extents.x + v40) > *(float *)((char *)&Extents.x + v41) )
          {
            Tmpd = v39;
            v39 = v40;
            v40 = Tmpd;
            v41 = v44;
          }
          --v52;
        }
        while ( v52 );
        SortedAxis[0] = v38;
        SortedAxis[2] = v40;
        SortedAxis[1] = v39;
        for ( i = 0; i != 3; ++i )
        {
          v46 = Opcode::AABBTreeNode::Split((Opcode::AABBTreeNode *)v41, (int)this, SortedAxis[i], builder);
          v11 = v46;
          if ( v46 )
          {
            v41 = (int)&this->mNbPrimitives;
            if ( v46 != *v50 )
              goto LABEL_15;
          }
        }
        goto LABEL_12;
      }
      Extents.x = (double)(unsigned int)Opcode::AABBTreeNode::Split((Opcode::AABBTreeNode *)v6, (int)this, 0, builder)
                / (double)*p_mNbPrimitives;
      Extents.y = (double)(unsigned int)Opcode::AABBTreeNode::Split(v30, (int)this, 1u, builder)
                / (double)*p_mNbPrimitives;
      Tmpc = Opcode::AABBTreeNode::Split(v31, (int)this, 2u, builder);
      v32 = (Opcode::AABBTreeNode *)*p_mNbPrimitives;
      v33 = (double)*p_mNbPrimitives;
      Extents.x = (float)(Extents.x - 0.5) * (float)(Extents.x - 0.5);
      Extents.y = (float)(Extents.y - 0.5) * (float)(Extents.y - 0.5);
      Extents.z = (double)Tmpc / v33;
      Extents.z = (float)(Extents.z - 0.5) * (float)(Extents.z - 0.5);
      v34 = Extents.x > Extents.y;
      if ( *(&Extents.x + v34) > Extents.z )
        v34 = 2;
      v35 = Opcode::AABBTreeNode::Split(v32, (int)this, v34, builder);
      v11 = v35;
      if ( !v35 )
        goto LABEL_12;
      v12 = v35 == *v50;
    }
LABEL_11:
    if ( !v12 )
      goto LABEL_15;
    goto LABEL_12;
  }
  v8 = this->mBV.mExtents.y;
  v9 = this->mBV.mExtents.z;
  Extents.x = this->mBV.mExtents.x;
  Extents.y = v8;
  Extents.z = v9;
  v10 = v8 > Extents.x;
  if ( v9 > *(&Extents.x + v10) )
    v10 = 2;
  v11 = Opcode::AABBTreeNode::Split((Opcode::AABBTreeNode *)LODWORD(v8), (int)this, v10, builder);
  if ( v11 )
  {
    v12 = v11 == *v50;
    goto LABEL_11;
  }
LABEL_12:
  result = 1;
  if ( builder->mSettings.mLimit != 1 )
    return result;
  ++builder->mNbInvalidSplits;
  v13 = *v50;
LABEL_14:
  v11 = v13 >> 1;
LABEL_15:
  mNodeBase = builder->mNodeBase;
  if ( !mNodeBase )
  {
    v47 = vostok::memory::new_array_helper<Opcode::AABBTreeNode>::call<vostok::memory::base_allocator>(
            builder->m_allocator,
            2u);
    if ( v47 )
    {
      this->mPos = (unsigned int)v47;
      goto LABEL_48;
    }
    return 0;
  }
  this->mPos = ((unsigned int)mNodeBase + 36 * builder->mCount - 36) | 1;
LABEL_48:
  builder->mCount += 2;
  v48 = this->mPos & 0xFFFFFFFE;
  if ( v48 )
    v49 = v48 + 36;
  else
    v49 = 0;
  *(_DWORD *)(v48 + 28) = this->mNodePrimitives;
  *(_DWORD *)(v48 + 32) = v11;
  *(_DWORD *)(v49 + 28) = &this->mNodePrimitives[v11];
  *(_DWORD *)(v49 + 32) = *v50 - v11;
  return 1;
}
