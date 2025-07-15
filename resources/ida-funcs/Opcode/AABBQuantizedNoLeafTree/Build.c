char __thiscall Opcode::AABBQuantizedNoLeafTree::Build(Opcode::AABBQuantizedNoLeafTree *this, Opcode::AABBTree *tree)
{
  unsigned int mNbPrimitives; // eax
  bool v5; // zf
  Opcode::AABBQuantizedNoLeafNode *mNodes; // eax
  Opcode::AABBNoLeafNode *v7; // edi
  Opcode::AABBQuantizedNoLeafNode *v8; // eax
  float v9; // xmm0_4
  float v10; // xmm3_4
  float v11; // xmm4_4
  float v12; // xmm5_4
  float v13; // xmm6_4
  unsigned int mNbNodes; // edx
  float *p_z; // ecx
  float v16; // xmm7_4
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm6_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float v22; // xmm2_4
  float v23; // xmm2_4
  float v24; // xmm2_4
  float v25; // xmm2_4
  float v26; // xmm0_4
  int v27; // ecx
  float *v28; // eax
  float v29; // xmm0_4
  float v30; // xmm3_4
  float v31; // xmm4_4
  float v32; // xmm5_4
  float v33; // xmm1_4
  int v34; // edx
  float v35; // xmm2_4
  IceMaths::Point *p_mExtentsCoeff; // edi
  float v37; // xmm1_4
  float v38; // xmm2_4
  float v39; // xmm0_4
  _WORD *v40; // ebx
  unsigned int v41; // edx
  unsigned int v42; // edx
  char v43; // [esp+13h] [ebp-4Dh]
  unsigned int v44; // [esp+14h] [ebp-4Ch]
  float v45; // [esp+1Ch] [ebp-44h]
  float v46; // [esp+1Ch] [ebp-44h]
  float v47; // [esp+1Ch] [ebp-44h]
  float v48; // [esp+1Ch] [ebp-44h]
  float v49; // [esp+1Ch] [ebp-44h]
  float v50; // [esp+1Ch] [ebp-44h]
  unsigned int v51; // [esp+1Ch] [ebp-44h]
  int v52; // [esp+20h] [ebp-40h]
  Opcode::AABBNoLeafNode *v53; // [esp+24h] [ebp-3Ch]
  unsigned int line; // [esp+28h] [ebp-38h] BYREF
  _WORD *v55; // [esp+2Ch] [ebp-34h]
  float v56; // [esp+30h] [ebp-30h]
  float v57; // [esp+34h] [ebp-2Ch]
  float v58; // [esp+38h] [ebp-28h]
  float v59; // [esp+3Ch] [ebp-24h]
  float v60; // [esp+40h] [ebp-20h]
  float v61; // [esp+44h] [ebp-1Ch]
  float v62; // [esp+48h] [ebp-18h]
  float v63; // [esp+50h] [ebp-10h]
  float v64[3]; // [esp+54h] [ebp-Ch]

  if ( !tree )
    return 0;
  mNbPrimitives = tree->mNbPrimitives;
  if ( tree->mTotalNbNodes != 2 * mNbPrimitives - 1 )
    return 0;
  v5 = this->mNodes == 0;
  this->mNbNodes = mNbPrimitives - 1;
  if ( !v5 )
  {
    mNodes = this->mNodes;
    if ( mNodes )
      this->m_allocator->call_free(
        this->m_allocator,
        &mNodes[-1].mPosData,
        "Opcode::AABBQuantizedNoLeafTree::Build",
        ".\\OPC_OptimizedTree.cpp",
        710u);
    this->mNodes = 0;
  }
  v7 = vostok::memory::new_array_helper<Opcode::AABBNoLeafNode>::call<vostok::memory::base_allocator>(
         this->mNbNodes,
         this->m_allocator,
         "Opcode::AABBQuantizedNoLeafTree::Build",
         (const char *const)0x2C7);
  v53 = v7;
  if ( !v7 )
    return 0;
  line = 1;
  BuildNoLeafTree(v7, 0, &line, tree);
  v8 = vostok::memory::new_array_helper<Opcode::AABBQuantizedNoLeafNode>::call<vostok::memory::base_allocator>(
         this->mNbNodes,
         this->m_allocator);
  this->mNodes = v8;
  if ( !v8 )
    return 0;
  v5 = this->mNbNodes == 0;
  v9 = FLOAT_N3_4028235e38;
  v10 = FLOAT_N3_4028235e38;
  v11 = FLOAT_N3_4028235e38;
  v12 = FLOAT_N3_4028235e38;
  v13 = FLOAT_N3_4028235e38;
  v59 = FLOAT_N3_4028235e38;
  v60 = FLOAT_N3_4028235e38;
  v61 = FLOAT_N3_4028235e38;
  v56 = FLOAT_N3_4028235e38;
  v57 = FLOAT_N3_4028235e38;
  v58 = FLOAT_N3_4028235e38;
  if ( v5 )
    goto LABEL_26;
  mNbNodes = this->mNbNodes;
  p_z = &v7->mAABB.mCenter.z;
  do
  {
    v45 = fabs(*(p_z - 2));
    if ( v45 > (double)v59 )
    {
      v10 = v45;
      v59 = v45;
    }
    v46 = fabs(*(p_z - 1));
    if ( v46 > (double)v60 )
    {
      v11 = v46;
      v60 = v46;
    }
    v47 = fabs(*p_z);
    if ( v47 > (double)v61 )
    {
      v12 = v47;
      v61 = v47;
    }
    v48 = fabs(p_z[1]);
    if ( v48 > (double)v56 )
    {
      v13 = v48;
      v56 = v48;
    }
    v49 = fabs(p_z[2]);
    if ( v49 > (double)v57 )
    {
      v9 = v49;
      v57 = v49;
    }
    v50 = fabs(p_z[3]);
    if ( v50 > (double)v58 )
      v58 = v50;
    p_z += 8;
    --mNbNodes;
  }
  while ( mNbNodes );
  if ( v10 == 0.0 )
    v59 = 0.0;
  else
LABEL_26:
    v59 = 32767.0 / v10;
  if ( v11 == 0.0 )
    v16 = 0.0;
  else
    v16 = 32767.0 / v11;
  v60 = v16;
  if ( v12 == 0.0 )
    v17 = 0.0;
  else
    v17 = 32767.0 / v12;
  v61 = v17;
  if ( v13 == 0.0 )
    v18 = 0.0;
  else
    v18 = 32767.0 / v13;
  v62 = v18;
  if ( v9 == 0.0 )
    v19 = 0.0;
  else
    v19 = 32767.0 / v9;
  if ( v58 == 0.0 )
    v63 = 0.0;
  else
    v63 = 32767.0 / v58;
  v20 = s_bm_current_air_resistance;
  if ( v59 == 0.0 )
    v21 = 0.0;
  else
    v21 = s_bm_current_air_resistance / v59;
  this->mCenterCoeff.x = v21;
  if ( v16 == 0.0 )
    v22 = 0.0;
  else
    v22 = v20 / v16;
  this->mCenterCoeff.y = v22;
  if ( v17 == 0.0 )
    v23 = 0.0;
  else
    v23 = v20 / v17;
  this->mCenterCoeff.z = v23;
  if ( v18 == 0.0 )
    v24 = 0.0;
  else
    v24 = v20 / v18;
  this->mExtentsCoeff.x = v24;
  if ( v19 == 0.0 )
    v25 = 0.0;
  else
    v25 = v20 / v19;
  this->mExtentsCoeff.y = v25;
  if ( v63 == 0.0 )
    v26 = 0.0;
  else
    v26 = v20 / v63;
  v27 = 0;
  this->mExtentsCoeff.z = v26;
  v51 = 0;
  if ( this->mNbNodes )
  {
    v28 = &v7->mAABB.mExtents.z;
    while ( 1 )
    {
      this->mNodes[v27].mAABB.mCenter[0] = (int)(float)(*(v28 - 5) * v59);
      this->mNodes[v27].mAABB.mCenter[1] = (int)(float)(*(v28 - 4) * v16);
      v44 = 0;
      this->mNodes[v27].mAABB.mCenter[2] = (int)(float)(v17 * *(v28 - 3));
      this->mNodes[v27].mAABB.mExtents[0] = (int)(float)(*(v28 - 2) * v18);
      this->mNodes[v27].mAABB.mExtents[1] = (int)(float)(v19 * *(v28 - 1));
      this->mNodes[v27].mAABB.mExtents[2] = (int)(float)(*v28 * v63);
      v29 = *(v28 - 5);
      v30 = *(v28 - 2);
      v31 = *(v28 - 1);
      v32 = *v28;
      v56 = v29 + v30;
      v33 = *(v28 - 4);
      v57 = v33 + v31;
      v34 = v27 * 20;
      v35 = *(v28 - 3) - v32;
      v58 = *(v28 - 3) + v32;
      v64[0] = v29 - v30;
      v64[1] = v33 - v31;
      v64[2] = v35;
      v52 = v27 * 20;
      p_mExtentsCoeff = &this->mExtentsCoeff;
      do
      {
        v37 = (float)*(__int16 *)((char *)this->mNodes->mAABB.mCenter + v34) * p_mExtentsCoeff[-1].x;
        v38 = *(&v56 + v44);
        v43 = 1;
        do
        {
          v55 = (unsigned __int16 *)((char *)this->mNodes->mAABB.mExtents + v34);
          v39 = (float)(unsigned __int16)*v55 * p_mExtentsCoeff->x;
          if ( v38 > (float)(v39 + v37)
            || (float)(v37 - v39) > *(float *)((char *)v64 + (_DWORD)((char *)p_mExtentsCoeff - 28 - (_DWORD)this)) )
          {
            ++*v55;
          }
          else
          {
            v43 = 0;
          }
          v40 = (unsigned __int16 *)((char *)this->mNodes->mAABB.mExtents + v34);
          if ( !*v40 )
          {
            *v40 = -1;
            v34 = v52;
            v43 = 0;
          }
        }
        while ( v43 );
        ++v44;
        v34 += 2;
        p_mExtentsCoeff = (IceMaths::Point *)((char *)p_mExtentsCoeff + 4);
        v52 = v34;
      }
      while ( v44 < 3 );
      v41 = *((_DWORD *)v28 + 1);
      v7 = v53;
      if ( (v41 & 1) == 0 )
        v41 = (unsigned int)&this->mNodes[(v41 - (unsigned int)v53) >> 5];
      this->mNodes[v27].mPosData = v41;
      v42 = *((_DWORD *)v28 + 2);
      if ( (v42 & 1) == 0 )
        v42 = (unsigned int)&this->mNodes[(v42 - (unsigned int)v53) >> 5];
      ++v51;
      this->mNodes[v27].mNegData = v42;
      v28 += 8;
      ++v27;
      if ( v51 >= this->mNbNodes )
        break;
      v17 = v61;
      v18 = v62;
      v16 = v60;
    }
  }
  this->m_allocator->call_free(
    this->m_allocator,
    &v7[-1].mPosData,
    "Opcode::AABBQuantizedNoLeafTree::Build",
    ".\\OPC_OptimizedTree.cpp",
    739u);
  return 1;
}
