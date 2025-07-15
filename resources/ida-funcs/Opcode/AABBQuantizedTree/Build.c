char __thiscall Opcode::AABBQuantizedTree::Build(Opcode::AABBQuantizedTree *this, Opcode::AABBTree *tree)
{
  unsigned int mTotalNbNodes; // eax
  bool v5; // zf
  Opcode::AABBQuantizedNode *mNodes; // eax
  vostok::memory::base_allocator *m_allocator; // ecx
  Opcode::AABBCollisionNode *v8; // ebx
  Opcode::AABBQuantizedNode *v9; // eax
  float v10; // xmm0_4
  unsigned int mNbNodes; // eax
  float v12; // xmm3_4
  float v13; // xmm4_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float *p_z; // ecx
  unsigned int v17; // edi
  float v18; // xmm7_4
  float v19; // xmm4_4
  float v20; // xmm3_4
  float v21; // xmm6_4
  float v22; // xmm0_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm2_4
  float v26; // xmm2_4
  float v27; // xmm2_4
  float v28; // xmm0_4
  int v29; // edi
  float *v30; // ecx
  float v31; // xmm0_4
  float v32; // xmm0_4
  float v33; // xmm3_4
  float v34; // xmm4_4
  float v35; // xmm5_4
  float v36; // xmm1_4
  int v37; // edx
  float v38; // xmm2_4
  IceMaths::Point *p_mExtentsCoeff; // eax
  float v40; // xmm1_4
  float v41; // xmm2_4
  float v42; // xmm0_4
  _WORD *v43; // ebx
  unsigned int v44; // eax
  char v45; // [esp+13h] [ebp-4Dh]
  unsigned int v46; // [esp+14h] [ebp-4Ch]
  Opcode::AABBCollisionNode *v47; // [esp+1Ch] [ebp-44h]
  float v48; // [esp+20h] [ebp-40h]
  float v49; // [esp+20h] [ebp-40h]
  float v50; // [esp+20h] [ebp-40h]
  float v51; // [esp+20h] [ebp-40h]
  float v52; // [esp+20h] [ebp-40h]
  float v53; // [esp+20h] [ebp-40h]
  unsigned int v54; // [esp+20h] [ebp-40h]
  int v55; // [esp+24h] [ebp-3Ch]
  unsigned int line; // [esp+28h] [ebp-38h] BYREF
  _WORD *v57; // [esp+2Ch] [ebp-34h]
  float v58; // [esp+30h] [ebp-30h]
  float v59; // [esp+34h] [ebp-2Ch]
  float v60; // [esp+38h] [ebp-28h]
  float v61; // [esp+3Ch] [ebp-24h]
  float v62; // [esp+40h] [ebp-20h]
  float v63; // [esp+44h] [ebp-1Ch]
  float v64; // [esp+48h] [ebp-18h]
  float v65; // [esp+50h] [ebp-10h]
  float v66[3]; // [esp+54h] [ebp-Ch]

  if ( !tree )
    return 0;
  mTotalNbNodes = tree->mTotalNbNodes;
  if ( mTotalNbNodes != 2 * tree->mNbPrimitives - 1 )
    return 0;
  v5 = this->mNodes == 0;
  this->mNbNodes = mTotalNbNodes;
  if ( !v5 )
  {
    mNodes = this->mNodes;
    m_allocator = this->m_allocator;
    if ( mNodes )
      m_allocator->call_free(
        m_allocator,
        &mNodes[-1].mAABB.mExtents[1],
        "Opcode::AABBQuantizedTree::Build",
        ".\\OPC_OptimizedTree.cpp",
        596u);
    this->mNodes = 0;
  }
  v8 = vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>(
         this->mNbNodes,
         this->m_allocator,
         "Opcode::AABBQuantizedTree::Build",
         (const char *const)0x255);
  v47 = v8;
  if ( !v8 )
    return 0;
  line = 1;
  BuildCollisionTree(v8, 0, &line, tree);
  v9 = vostok::memory::new_array_helper<Opcode::AABBQuantizedNode>::call<vostok::memory::base_allocator>(
         this->mNbNodes,
         this->m_allocator);
  this->mNodes = v9;
  if ( !v9 )
    return 0;
  v10 = FLOAT_N3_4028235e38;
  mNbNodes = this->mNbNodes;
  v12 = FLOAT_N3_4028235e38;
  v13 = FLOAT_N3_4028235e38;
  v14 = FLOAT_N3_4028235e38;
  v15 = FLOAT_N3_4028235e38;
  v61 = FLOAT_N3_4028235e38;
  v62 = FLOAT_N3_4028235e38;
  v63 = FLOAT_N3_4028235e38;
  v58 = FLOAT_N3_4028235e38;
  v59 = FLOAT_N3_4028235e38;
  v60 = FLOAT_N3_4028235e38;
  if ( !mNbNodes )
    goto LABEL_26;
  p_z = &v8->mAABB.mCenter.z;
  v17 = mNbNodes;
  do
  {
    v48 = fabs(*(p_z - 2));
    if ( v48 > (double)v61 )
    {
      v12 = v48;
      v61 = v48;
    }
    v49 = fabs(*(p_z - 1));
    if ( v49 > (double)v62 )
    {
      v13 = v49;
      v62 = v49;
    }
    v50 = fabs(*p_z);
    if ( v50 > (double)v63 )
    {
      v14 = v50;
      v63 = v50;
    }
    v51 = fabs(p_z[1]);
    if ( v51 > (double)v58 )
    {
      v15 = v51;
      v58 = v51;
    }
    v52 = fabs(p_z[2]);
    if ( v52 > (double)v59 )
    {
      v10 = v52;
      v59 = v52;
    }
    v53 = fabs(p_z[3]);
    if ( v53 > (double)v60 )
      v60 = v53;
    p_z += 7;
    --v17;
  }
  while ( v17 );
  if ( v12 == 0.0 )
    v61 = 0.0;
  else
LABEL_26:
    v61 = 32767.0 / v12;
  if ( v13 == 0.0 )
    v18 = 0.0;
  else
    v18 = 32767.0 / v13;
  v62 = v18;
  if ( v14 == 0.0 )
    v19 = 0.0;
  else
    v19 = 32767.0 / v14;
  v63 = v19;
  if ( v15 == 0.0 )
    v20 = 0.0;
  else
    v20 = 32767.0 / v15;
  v64 = v20;
  if ( v10 == 0.0 )
    v21 = 0.0;
  else
    v21 = 32767.0 / v10;
  if ( v60 == 0.0 )
    v65 = 0.0;
  else
    v65 = 32767.0 / v60;
  v22 = s_bm_current_air_resistance;
  if ( v61 == 0.0 )
    v23 = 0.0;
  else
    v23 = s_bm_current_air_resistance / v61;
  this->mCenterCoeff.x = v23;
  if ( v18 == 0.0 )
    v24 = 0.0;
  else
    v24 = v22 / v18;
  this->mCenterCoeff.y = v24;
  if ( v19 == 0.0 )
    v25 = 0.0;
  else
    v25 = v22 / v19;
  this->mCenterCoeff.z = v25;
  if ( v20 == 0.0 )
    v26 = 0.0;
  else
    v26 = v22 / v20;
  this->mExtentsCoeff.x = v26;
  if ( v21 == 0.0 )
    v27 = 0.0;
  else
    v27 = v22 / v21;
  this->mExtentsCoeff.y = v27;
  if ( v65 == 0.0 )
    v28 = 0.0;
  else
    v28 = v22 / v65;
  v29 = 0;
  this->mExtentsCoeff.z = v28;
  v54 = 0;
  if ( this->mNbNodes )
  {
    v30 = &v8->mAABB.mExtents.z;
    while ( 1 )
    {
      this->mNodes[v29].mAABB.mCenter[0] = (int)(float)(*(v30 - 5) * v61);
      this->mNodes[v29].mAABB.mCenter[1] = (int)(float)(*(v30 - 4) * v18);
      v46 = 0;
      this->mNodes[v29].mAABB.mCenter[2] = (int)(float)(*(v30 - 3) * v19);
      this->mNodes[v29].mAABB.mExtents[0] = (int)(float)(v20 * *(v30 - 2));
      v31 = v65;
      this->mNodes[v29].mAABB.mExtents[1] = (int)(float)(*(v30 - 1) * v21);
      this->mNodes[v29].mAABB.mExtents[2] = (int)(float)(v31 * *v30);
      v32 = *(v30 - 5);
      v33 = *(v30 - 2);
      v34 = *(v30 - 1);
      v35 = *v30;
      v58 = v32 + v33;
      v36 = *(v30 - 4);
      v59 = v36 + v34;
      v37 = v29 * 16;
      v38 = *(v30 - 3) - v35;
      v60 = *(v30 - 3) + v35;
      v66[0] = v32 - v33;
      v66[1] = v36 - v34;
      v66[2] = v38;
      v55 = v29 * 16;
      p_mExtentsCoeff = &this->mExtentsCoeff;
      do
      {
        v40 = (float)*(__int16 *)((char *)this->mNodes->mAABB.mCenter + v37) * p_mExtentsCoeff[-1].x;
        v41 = *(&v58 + v46);
        v45 = 1;
        do
        {
          v57 = (unsigned __int16 *)((char *)this->mNodes->mAABB.mExtents + v37);
          v42 = (float)(unsigned __int16)*v57 * p_mExtentsCoeff->x;
          if ( v41 > (float)(v42 + v40)
            || (float)(v40 - v42) > *(float *)((char *)v66 + (_DWORD)((char *)p_mExtentsCoeff - 28 - (_DWORD)this)) )
          {
            ++*v57;
          }
          else
          {
            v45 = 0;
          }
          v43 = (unsigned __int16 *)((char *)this->mNodes->mAABB.mExtents + v37);
          if ( !*v43 )
          {
            *v43 = -1;
            v37 = v55;
            v45 = 0;
          }
        }
        while ( v45 );
        ++v46;
        v37 += 2;
        p_mExtentsCoeff = (IceMaths::Point *)((char *)p_mExtentsCoeff + 4);
        v55 = v37;
      }
      while ( v46 < 3 );
      v44 = *((_DWORD *)v30 + 1);
      if ( (v44 & 1) == 0 )
        v44 = (unsigned int)&this->mNodes[(v44 - (unsigned int)v47) / 0x1C];
      ++v54;
      v8 = v47;
      this->mNodes[v29].mData = v44;
      v30 += 7;
      ++v29;
      if ( v54 >= this->mNbNodes )
        break;
      v19 = v63;
      v20 = v64;
      v18 = v62;
    }
  }
  this->m_allocator->call_free(
    this->m_allocator,
    &v8[-1].mAABB.mExtents.z,
    "Opcode::AABBQuantizedTree::Build",
    ".\\OPC_OptimizedTree.cpp",
    623u);
  return 1;
}
