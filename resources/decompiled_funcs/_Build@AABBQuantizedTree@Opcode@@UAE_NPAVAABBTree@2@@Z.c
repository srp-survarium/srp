char __thiscall Opcode::AABBQuantizedTree::Build(Opcode::AABBQuantizedTree *this, Opcode::AABBTree *tree)
{
  unsigned int mTotalNbNodes; // eax
  bool v5; // zf
  Opcode::AABBCollisionNode *v6; // eax
  Opcode::AABBCollisionNode *v7; // ebx
  Opcode::AABBQuantizedNode *v8; // eax
  float v9; // xmm0_4
  unsigned int mNbNodes; // edi
  float v11; // xmm1_4
  float v12; // xmm2_4
  float v13; // xmm3_4
  float v14; // xmm5_4
  float v15; // xmm6_4
  float z; // xmm7_4
  float *p_z; // ecx
  unsigned int v18; // edx
  long double v19; // st7
  long double v20; // st7
  long double v21; // st7
  long double v22; // st7
  long double v23; // st7
  long double v24; // st7
  float v25; // xmm3_4
  float x; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm4_4
  const vostok::math::float4x4 *v29; // xmm2_4
  float v30; // xmm0_4
  float y; // xmm7_4
  float v32; // xmm0_4
  float v33; // xmm0_4
  float v34; // xmm0_4
  float v35; // xmm0_4
  int v36; // ecx
  int v37; // eax
  float *v38; // edi
  float v39; // xmm0_4
  float v40; // xmm3_4
  float v41; // xmm4_4
  float v42; // xmm5_4
  float v43; // xmm1_4
  unsigned int v44; // edx
  float v45; // xmm2_4
  Opcode::AABBQuantizedNode *mNodes; // eax
  float v47; // xmm2_4
  IceMaths::Point *v48; // ebx
  float v49; // xmm1_4
  float v50; // xmm0_4
  unsigned int v51; // ecx
  bool FixMe; // [esp+13h] [ebp-55h]
  unsigned int j; // [esp+14h] [ebp-54h]
  IceMaths::Point *p_mExtentsCoeff; // [esp+18h] [ebp-50h]
  unsigned int i; // [esp+1Ch] [ebp-4Ch]
  Opcode::AABBCollisionNode *Nodes; // [esp+20h] [ebp-48h]
  int v57; // [esp+24h] [ebp-44h]
  float v58; // [esp+28h] [ebp-40h]
  float v59; // [esp+28h] [ebp-40h]
  float v60; // [esp+28h] [ebp-40h]
  float v61; // [esp+28h] [ebp-40h]
  float v62; // [esp+28h] [ebp-40h]
  float v63; // [esp+28h] [ebp-40h]
  int v64; // [esp+28h] [ebp-40h]
  unsigned int CurID; // [esp+2Ch] [ebp-3Ch] BYREF
  int v66; // [esp+30h] [ebp-38h]
  char *v67; // [esp+34h] [ebp-34h]
  IceMaths::Point CMax; // [esp+38h] [ebp-30h]
  IceMaths::Point EMax; // [esp+44h] [ebp-24h]
  IceMaths::Point Max; // [esp+50h] [ebp-18h]
  IceMaths::Point Min; // [esp+5Ch] [ebp-Ch]

  if ( !tree )
    return 0;
  mTotalNbNodes = tree->mTotalNbNodes;
  if ( mTotalNbNodes != 2 * tree->mNbPrimitives - 1 )
    return 0;
  v5 = this->mNodes == 0;
  this->mNbNodes = mTotalNbNodes;
  if ( !v5 )
  {
    this->m_allocator->call_free(this->m_allocator, &this->mNodes[-1].mAABB.mExtents[1]);
    this->mNodes = 0;
  }
  v6 = vostok::memory::new_array_helper<Opcode::AABBCollisionNode>::call<vostok::memory::base_allocator>(
         this->m_allocator,
         this->mNbNodes);
  v7 = v6;
  Nodes = v6;
  if ( !v6 )
    return 0;
  CurID = 1;
  BuildCollisionTree(v6, 0, &CurID, tree);
  v8 = vostok::memory::new_array_helper<Opcode::AABBQuantizedNode>::call<vostok::memory::base_allocator>(
         this->m_allocator,
         this->mNbNodes);
  this->mNodes = v8;
  if ( !v8 )
    return 0;
  v9 = -3.4028235e38;
  mNbNodes = this->mNbNodes;
  v11 = 0.0;
  v12 = -3.4028235e38;
  v13 = -3.4028235e38;
  v14 = -3.4028235e38;
  v15 = -3.4028235e38;
  z = -3.4028235e38;
  CMax.x = -3.4028235e38;
  CMax.y = -3.4028235e38;
  CMax.z = -3.4028235e38;
  EMax.x = -3.4028235e38;
  EMax.y = -3.4028235e38;
  EMax.z = -3.4028235e38;
  if ( !mNbNodes )
    goto LABEL_24;
  p_z = &v7->mAABB.mCenter.z;
  v18 = mNbNodes;
  do
  {
    v19 = fabs(*(p_z - 2));
    if ( v19 > CMax.x )
    {
      v12 = v19;
      v58 = v19;
      CMax.x = v58;
    }
    v20 = fabs(*(p_z - 1));
    if ( v20 > CMax.y )
    {
      v13 = v20;
      v59 = v20;
      CMax.y = v59;
    }
    v21 = fabs(*p_z);
    if ( v21 > CMax.z )
    {
      v14 = v21;
      v60 = v21;
      CMax.z = v60;
    }
    v22 = fabs(p_z[1]);
    if ( v22 > EMax.x )
    {
      v15 = v22;
      v61 = v22;
      EMax.x = v61;
    }
    v23 = fabs(p_z[2]);
    if ( v23 > EMax.y )
    {
      v9 = v23;
      v62 = v23;
      EMax.y = v62;
    }
    v24 = fabs(p_z[3]);
    if ( v24 > EMax.z )
    {
      z = v24;
      v63 = v24;
      EMax.z = v63;
    }
    p_z += 7;
    --v18;
  }
  while ( v18 );
  if ( v12 == 0.0 )
  {
    CMax.x = 0.0;
  }
  else
  {
LABEL_24:
    CMax.x = 32767.0 / v12;
    z = EMax.z;
  }
  if ( v13 == 0.0 )
    CMax.y = 0.0;
  else
    CMax.y = 32767.0 / v13;
  if ( v14 == 0.0 )
  {
    CMax.z = 0.0;
    v25 = 0.0;
  }
  else
  {
    v25 = 32767.0 / v14;
    CMax.z = 32767.0 / v14;
  }
  if ( v15 == 0.0 )
  {
    EMax.x = 0.0;
    x = 0.0;
  }
  else
  {
    x = 32767.0 / v15;
    EMax.x = 32767.0 / v15;
  }
  if ( v9 == 0.0 )
    v27 = 0.0;
  else
    v27 = 32767.0 / v9;
  if ( z == 0.0 )
    v28 = 0.0;
  else
    v28 = 32767.0 / z;
  v29 = clear_value;
  EMax.z = v28;
  if ( CMax.x == 0.0 )
    v30 = 0.0;
  else
    v30 = *(float *)&clear_value / CMax.x;
  y = CMax.y;
  v5 = CMax.y == 0.0;
  this->mCenterCoeff.x = v30;
  if ( v5 )
    v32 = 0.0;
  else
    v32 = *(float *)&v29 / y;
  this->mCenterCoeff.y = v32;
  if ( v25 == 0.0 )
    v33 = 0.0;
  else
    v33 = *(float *)&v29 / v25;
  this->mCenterCoeff.z = v33;
  if ( x == 0.0 )
    v34 = 0.0;
  else
    v34 = *(float *)&v29 / x;
  this->mExtentsCoeff.x = v34;
  if ( v27 == 0.0 )
    v35 = 0.0;
  else
    v35 = *(float *)&v29 / v27;
  this->mExtentsCoeff.y = v35;
  if ( v28 != 0.0 )
    v11 = *(float *)&v29 / v28;
  v36 = 0;
  this->mExtentsCoeff.z = v11;
  i = 0;
  if ( mNbNodes )
  {
    v66 = -28 - (_DWORD)this;
    v37 = 0;
    v64 = 0;
    v57 = 0;
    v38 = &v7->mAABB.mExtents.z;
    while ( 1 )
    {
      *(__int16 *)((char *)this->mNodes->mAABB.mCenter + v37) = (int)(float)(*(v38 - 5) * CMax.x);
      *(__int16 *)((char *)&this->mNodes->mAABB.mCenter[1] + v37) = (int)(float)(y * *(v38 - 4));
      *(__int16 *)((char *)&this->mNodes->mAABB.mCenter[2] + v37) = (int)(float)(*(v38 - 3) * v25);
      *(unsigned __int16 *)((char *)this->mNodes->mAABB.mExtents + v37) = (int)(float)(*(v38 - 2) * x);
      *(unsigned __int16 *)((char *)&this->mNodes->mAABB.mExtents[1] + v37) = (int)(float)(*(v38 - 1) * v27);
      *(unsigned __int16 *)((char *)&this->mNodes->mAABB.mExtents[2] + v37) = (int)(float)(*v38 * v28);
      v39 = *(v38 - 5);
      v40 = *(v38 - 2);
      v41 = *(v38 - 1);
      v42 = *v38;
      Max.x = v39 + v40;
      v43 = *(v38 - 4);
      Max.y = v43 + v41;
      v44 = 0;
      v45 = *(v38 - 3) - v42;
      Max.z = *(v38 - 3) + v42;
      Min.x = v39 - v40;
      Min.y = v43 - v41;
      Min.z = v45;
      j = 0;
      p_mExtentsCoeff = &this->mExtentsCoeff;
      do
      {
        mNodes = this->mNodes;
        v47 = *(&Max.x + v44);
        v48 = p_mExtentsCoeff;
        v49 = (float)*(__int16 *)((char *)mNodes->mAABB.mCenter + v36) * p_mExtentsCoeff[-1].x;
        FixMe = 1;
        v67 = (char *)p_mExtentsCoeff + v66;
        while ( 1 )
        {
          v50 = (float)*(unsigned __int16 *)((char *)mNodes->mAABB.mExtents + v36) * p_mExtentsCoeff->x;
          if ( v47 > (float)(v50 + v49) || (float)(v49 - v50) > *(float *)((char *)&Min.x + (_DWORD)v67) )
            ++*(unsigned __int16 *)((char *)mNodes->mAABB.mExtents + v36);
          else
            FixMe = 0;
          mNodes = this->mNodes;
          if ( !*(unsigned __int16 *)((char *)mNodes->mAABB.mExtents + v36) )
            break;
          if ( !FixMe )
            goto LABEL_71;
        }
        this->mNodes[i].mAABB.mExtents[j] = -1;
        v48 = p_mExtentsCoeff;
LABEL_71:
        v44 = j + 1;
        v36 += 2;
        j = v44;
        p_mExtentsCoeff = (IceMaths::Point *)&v48->y;
      }
      while ( v44 < 3 );
      v51 = *((_DWORD *)v38 + 1);
      v7 = Nodes;
      if ( (v51 & 1) == 0 )
        v51 = (unsigned int)&this->mNodes[(v51 - (unsigned int)Nodes) / 0x1C];
      this->mNodes[v64].mData = v51;
      v36 = v57 + 16;
      v37 = v64 * 16 + 16;
      v38 += 7;
      ++i;
      v57 += 16;
      ++v64;
      if ( i >= this->mNbNodes )
        break;
      x = EMax.x;
      v25 = CMax.z;
      y = CMax.y;
      v28 = EMax.z;
    }
  }
  this->m_allocator->call_free(this->m_allocator, &v7[-1].mAABB.mExtents.z);
  return 1;
}
