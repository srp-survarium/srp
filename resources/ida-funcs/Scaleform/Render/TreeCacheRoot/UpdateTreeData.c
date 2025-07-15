void __thiscall Scaleform::Render::TreeCacheRoot::UpdateTreeData(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v3; // eax
  Scaleform::Render::TreeCacheNode *v4; // edi
  int v5; // esi
  Scaleform::Render::TreeCacheNode *pParent; // eax
  int v7; // eax
  void (__thiscall *propagate3DFlag)(Scaleform::Render::TreeCacheNode *, unsigned int); // eax
  Scaleform::Render::TreeCacheNode *v9; // ebx
  unsigned int v10; // eax
  unsigned int State; // eax
  Scaleform::Render::FilterSet *v12; // eax
  int v13; // ebx
  const Scaleform::Render::Cxform *v14; // edx
  const __m128i *v15; // ecx
  const Scaleform::Render::Matrix2x4<float> *v16; // eax
  const Scaleform::Render::ViewMatrix3DState *v17; // edi
  const Scaleform::Render::ProjectionMatrix3DState *v18; // eax
  unsigned int v19; // ebx
  float v20; // edi
  double v21; // st7
  unsigned int v22; // esi
  unsigned int v23; // eax
  Scaleform::Render::FilterSet *v24; // eax
  int v25; // eax
  Scaleform::Render::TreeCacheNode *v26; // edi
  int v27; // ecx
  Scaleform::Render::Matrix3x4<float> *Depth; // ecx
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *v29; // eax
  unsigned int v30; // ecx
  unsigned int i; // edi
  Scaleform::Render::TreeCacheNode *j; // esi
  unsigned int k; // eax
  Scaleform::Render::BundleEntry *pFirst; // ecx
  Scaleform::Render::BundleEntry *pLast; // eax
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  char v39; // [esp+16h] [ebp-1BEh]
  bool v40; // [esp+17h] [ebp-1BDh]
  const Scaleform::Render::ProjectionMatrix3DState *v42; // [esp+1Ch] [ebp-1B8h]
  Scaleform::Render::TreeCacheNode *v43; // [esp+20h] [ebp-1B4h]
  Scaleform::Render::Matrix3x4<float> *m1; // [esp+24h] [ebp-1B0h]
  Scaleform::Render::Matrix3x4<float> *m1a; // [esp+24h] [ebp-1B0h]
  unsigned int v46; // [esp+28h] [ebp-1ACh]
  const Scaleform::Render::ViewMatrix3DState *v47; // [esp+2Ch] [ebp-1A8h]
  int v48; // [esp+30h] [ebp-1A4h]
  Scaleform::Render::BundleIterator ibundles; // [esp+34h] [ebp-1A0h] BYREF
  float v50; // [esp+3Ch] [ebp-198h]
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *v51; // [esp+40h] [ebp-194h]
  unsigned __int8 src[60]; // [esp+44h] [ebp-190h] BYREF
  unsigned int DepthUsed; // [esp+80h] [ebp-154h]
  Scaleform::AmpFunctionTimer v54; // [esp+84h] [ebp-150h] BYREF
  Scaleform::Render::TransformArgs v55; // [esp+94h] [ebp-140h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+174h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+1A4h] [ebp-30h] BYREF

  Instance = Scaleform::AmpServer::GetInstance();
  v3 = Instance->GetDisplayStats(Instance);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v54,
    v3,
    "TreeCacheRoot::UpdateTreeData",
    Amp_Profile_Level_Medium,
    Amp_Native_Function_Id_Invalid);
  DepthUsed = this->DepthUpdates.DepthUsed;
  v48 = 0;
  if ( DepthUsed )
  {
    while ( 1 )
    {
      v4 = this->DepthUpdates.pDepth[v48];
      v43 = v4;
      if ( v4 )
        break;
LABEL_88:
      if ( ++v48 >= DepthUsed )
        goto LABEL_89;
    }
    while ( 1 )
    {
      v5 = v4->UpdateFlags & 3;
      if ( ((unsigned int)&_sbh_sizeHeaderList & v4->UpdateFlags) != 0 )
      {
        pParent = v4->pParent;
        if ( pParent )
          v7 = pParent->Flags & 0x80;
        else
          v7 = 0;
        v4->propagateScale9Flag(v4, v7);
        v4->UpdateFlags &= ~0x10000u;
        v5 |= 1u;
      }
      if ( (v4->UpdateFlags & 0x2000) != 0 )
      {
        propagate3DFlag = v4->propagate3DFlag;
        v4->Flags = v4->Flags & 0xFDFF
                  | (((*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v4->pNode & 0xFFFFF000) + 0x14)
                                             + 4 * ((int)((int)&v4->pNode[-1] - ((int)v4->pNode & 0xFFFFF000)) / 28)
                                             + 20)
                                 & 0xFFFFFFFE)
                                + 6)
                     & 0x200) != 0) << 9);
        propagate3DFlag(v4, 0);
        v4->UpdateFlags &= ~0x2000u;
        v5 |= 1u;
      }
      if ( !v5 )
      {
        v9 = v4;
        while ( 1 )
        {
          v10 = *(_DWORD *)(*(_DWORD *)(((int)v9->pNode & 0xFFFFF000) + 0x14)
                          + 4 * ((int)((int)&v9->pNode[-1] - ((int)v9->pNode & 0xFFFFF000)) / 28)
                          + 20)
              & 0xFFFFFFFE;
          if ( (*(_WORD *)(v10 + 6) & 0x400) != 0 )
          {
            State = Scaleform::Render::StateBag::GetState(
                      (Scaleform::Render::StateBag *)(v10 + 64),
                      State_ActionControl);
            if ( State )
            {
              v12 = *(Scaleform::Render::FilterSet **)(State + 4);
              if ( v12 )
              {
                if ( Scaleform::Render::FilterSet::IsContributing(v12) )
                  break;
              }
            }
          }
          v9 = v9->pParent;
          if ( !v9 )
            goto LABEL_87;
        }
        v5 = 2;
      }
      v46 = *(_DWORD *)(*(_DWORD *)(((int)v43->pNode & 0xFFFFF000) + 0x14)
                      + 4 * ((int)((int)&v43->pNode[-1] - ((int)v43->pNode & 0xFFFFF000)) / 28)
                      + 20)
          & 0xFFFFFFFE;
      v13 = v5 | (this->ViewValid ? 0x10 : 0);
      v39 = v5 != 0;
      v40 = (*(_WORD *)(v46 + 6) & 0x200) != 0;
      if ( (*(_WORD *)(v46 + 6) & 0x400) != 0 )
        v14 = &Scaleform::Render::Cxform::Identity;
      else
        v14 = (const Scaleform::Render::Cxform *)(v46 + 80);
      if ( (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v43->pNode & 0xFFFFF000) + 0x14)
                                  + 4 * ((int)((int)&v43->pNode[-1] - ((int)v43->pNode & 0xFFFFF000)) / 28)
                                  + 20)
                      & 0xFFFFFFFE)
                     + 6)
          & 0x200) != 0 )
      {
        v15 = (const __m128i *)(v46 + 16);
        v16 = &Scaleform::Render::Matrix2x4<float>::Identity;
      }
      else
      {
        v15 = (const __m128i *)&Scaleform::Render::Matrix3x4<float>::Identity;
        v16 = (const Scaleform::Render::Matrix2x4<float> *)(v46 + 16);
      }
      Scaleform::Render::TransformArgs::TransformArgs(&v55, &this->ViewCullRect, v16, v15, v14);
      if ( (*(_WORD *)(v46 + 6) & 0x800) != 0 )
        v17 = (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                              (Scaleform::Render::StateBag *)(v46 + 64),
                                                              State_FSCommandHandler);
      else
        v17 = 0;
      if ( (*(_WORD *)(v46 + 6) & 0x1000) != 0 )
        v18 = (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                    (Scaleform::Render::StateBag *)(v46 + 64),
                                                                    State_ExternalInterface);
      else
        v18 = 0;
      if ( v17 )
      {
        v55.viewState = v17;
        v55.bRecomputeViewProj = 1;
      }
      if ( v18 )
      {
        v55.projState = v18;
        v55.bRecomputeViewProj = 1;
      }
      v19 = (v40 ? 128 : 64) | v13;
      v47 = (*(_WORD *)(v46 + 6) & 0x800) != 0
          ? (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                            (Scaleform::Render::StateBag *)(v46 + 64),
                                                            State_FSCommandHandler)
          : 0;
      v42 = (*(_WORD *)(v46 + 6) & 0x1000) != 0
          ? (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                  (Scaleform::Render::StateBag *)(v46 + 64),
                                                                  State_ExternalInterface)
          : 0;
      v20 = *(float *)&v43->pParent;
      v50 = v20;
      if ( v20 != 0.0 )
        break;
LABEL_82:
      if ( v47 )
      {
        v55.viewState = v47;
        v55.bRecomputeViewProj = 1;
      }
      if ( v42 )
      {
        v55.projState = v42;
        v55.bRecomputeViewProj = 1;
      }
      v43->UpdateTransform(
        v43,
        (const Scaleform::Render::TreeNode::NodeData *)v46,
        &v55,
        (Scaleform::Render::TransformFlags)v19);
      v43->UpdateFlags &= 0xFFFFFFFC;
      v4 = v43;
LABEL_87:
      v4 = v4->pNextUpdate;
      v43 = v4;
      if ( !v4 )
        goto LABEL_88;
    }
    v21 = 0.0;
    while ( 1 )
    {
      if ( (*(_BYTE *)(LODWORD(v20) + 50) & 3) != 1 )
        v19 &= ~0x10u;
      v22 = *(_DWORD *)(*(_DWORD *)((*(_DWORD *)(LODWORD(v20) + 28) & 0xFFFFF000) + 0x14)
                      + 4
                      * ((int)(*(_DWORD *)(LODWORD(v20) + 28) - (*(_DWORD *)(LODWORD(v20) + 28) & 0xFFFFF000) - 28)
                       / 28)
                      + 20)
          & 0xFFFFFFFE;
      if ( (v19 & 0x80u) == 0 )
      {
        if ( (*(_WORD *)(v22 + 6) & 0x200) != 0 )
        {
          *(float *)src = v55.Mat.M[0][0];
          *(float *)&src[4] = v55.Mat.M[0][1];
          *(float *)&src[8] = v55.Mat.M[0][2];
          *(float *)&src[12] = v55.Mat.M[0][3];
          *(float *)&src[16] = v55.Mat.M[1][0];
          *(float *)&src[20] = v55.Mat.M[1][1];
          *(float *)&src[24] = v55.Mat.M[1][2];
          *(float *)&src[28] = v55.Mat.M[1][3];
          *(float *)&src[32] = v21;
          *(float *)&src[36] = v21;
          *(float *)&src[40] = 1.0;
          *(float *)&src[44] = v21;
          memcpy((int)&v55.Mat3D, (const __m128i *)src, sizeof(v55.Mat3D));
          memcpy((int)&m2, (const __m128i *)&v55.Mat3D, sizeof(m2));
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            &v55.Mat3D,
            (const Scaleform::Render::Matrix3x4<float> *)(v22 + 16),
            &m2);
          v55.Mat.M[0][0] = 1.0;
          v19 = v19 & 0xFFFFFF3F | 0x80;
          v55.Mat.M[0][1] = 0.0;
          v55.Mat.M[0][2] = 0.0;
          v55.Mat.M[0][3] = 0.0;
          v55.Mat.M[1][0] = 0.0;
          v55.Mat.M[1][2] = 0.0;
          v55.Mat.M[1][3] = 0.0;
          v21 = 0.0;
          v55.Mat.M[1][1] = 1.0;
          goto LABEL_54;
        }
        Scaleform::Render::Matrix2x4<float>::Append(&v55.Mat, (const Scaleform::Render::Matrix2x4<float> *)(v22 + 16));
      }
      else
      {
        if ( (*(_WORD *)(v22 + 6) & 0x200) != 0 )
        {
          m1 = (Scaleform::Render::Matrix3x4<float> *)(v22 + 16);
        }
        else
        {
          *(float *)src = *(float *)(v22 + 16);
          m1 = (Scaleform::Render::Matrix3x4<float> *)src;
          *(float *)&src[4] = *(float *)(v22 + 20);
          *(float *)&src[8] = *(float *)(v22 + 24);
          *(float *)&src[12] = *(float *)(v22 + 28);
          *(float *)&src[16] = *(float *)(v22 + 32);
          *(float *)&src[20] = *(float *)(v22 + 36);
          *(float *)&src[24] = *(float *)(v22 + 40);
          *(float *)&src[28] = *(float *)(v22 + 44);
          *(float *)&src[32] = v21;
          *(float *)&src[36] = v21;
          *(float *)&src[40] = 1.0;
          *(float *)&src[44] = v21;
        }
        memcpy((int)&dst, (const __m128i *)&v55.Mat3D, sizeof(dst));
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v55.Mat3D, m1, &dst);
      }
      v21 = 0.0;
LABEL_54:
      v39 |= (*(_BYTE *)(LODWORD(v20) + 52) & 3) != 0;
      if ( (*(_WORD *)(v22 + 6) & 0x400) != 0 )
      {
        v23 = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v22 + 64), State_ActionControl);
        if ( v23 )
        {
          v24 = *(Scaleform::Render::FilterSet **)(v23 + 4);
          if ( v24 )
          {
            if ( Scaleform::Render::FilterSet::IsContributing(v24) )
            {
              if ( v39 )
              {
                v25 = *(_DWORD *)(LODWORD(v20) + 24);
                *(_DWORD *)(LODWORD(v20) + 52) |= 0x1200000u;
                if ( v25 )
                {
                  v26 = *(Scaleform::Render::TreeCacheNode **)(LODWORD(v50) + 36);
                  if ( v26 )
                  {
                    v27 = 0x1000000;
                    if ( (v26->UpdateFlags & 0x80000000) == 0 )
                    {
                      if ( *(_BYTE *)(v25 + 152) )
                      {
                        Depth = (Scaleform::Render::Matrix3x4<float> *)v26->Depth;
                        v29 = (Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *)(v25 + 156);
                        m1a = Depth;
                        v51 = v29;
                        if ( (unsigned int)Depth < v29->DepthAvailable )
                        {
LABEL_66:
                          v26->pNextUpdate = v29->pDepth[(_DWORD)Depth];
                          v29->pDepth[(_DWORD)Depth] = v26;
                          v30 = (unsigned int)&Depth->M[0][0] + 1;
                          if ( v29->DepthUsed < v30 )
                            v29->DepthUsed = v30;
                        }
                        else if ( Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                                    v29,
                                    (unsigned int)&Depth->M[0][0] + 1) )
                        {
                          Depth = m1a;
                          v29 = v51;
                          goto LABEL_66;
                        }
                      }
                      else
                      {
                        v26->pNextUpdate = *(Scaleform::Render::TreeCacheNode **)(v25 + 148);
                        *(_DWORD *)(v25 + 148) = v26;
                      }
                      v27 = -2130706432;
                    }
                    v26->UpdateFlags |= v27;
                  }
                }
              }
              v20 = v50;
              v19 |= 0x100u;
            }
          }
        }
        v21 = 0.0;
      }
      if ( (v19 & 0x100) == 0 )
      {
        Scaleform::Render::Cxform::Prepend(&v55.Cx, (const Scaleform::Render::Cxform *)(v22 + 80));
        v21 = 0.0;
      }
      if ( !v47 && (*(_WORD *)(v22 + 6) & 0x800) != 0 )
      {
        v21 = 0.0;
        v47 = (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                              (Scaleform::Render::StateBag *)(v22 + 64),
                                                              State_FSCommandHandler);
      }
      if ( !v42 && (*(_WORD *)(v22 + 6) & 0x1000) != 0 )
      {
        v21 = 0.0;
        v42 = (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                    (Scaleform::Render::StateBag *)(v22 + 64),
                                                                    State_ExternalInterface);
      }
      v20 = *(float *)(LODWORD(v20) + 36);
      v50 = v20;
      if ( v20 == 0.0 )
        goto LABEL_82;
    }
  }
LABEL_89:
  for ( i = this->DepthUpdates.DepthUsed; i; --i )
  {
    for ( j = this->DepthUpdates.pDepth[i - 1]; j; j = j->pNextUpdate )
    {
      if ( (j->UpdateFlags & 0x3000000) != 0 )
      {
        j->UpdateBundlePattern(j, 0);
        j->UpdateFlags &= 0xFCFFFFFF;
      }
      j->UpdateFlags &= ~0x80000000;
    }
  }
  for ( k = 0; k < this->DepthUpdates.DepthUsed; ++k )
    this->DepthUpdates.pDepth[k] = this->DepthUpdates.NullValue;
  this->DepthUpdates.DepthUsed = 0;
  this->DepthUpdatesChained = 0;
  pFirst = this->CachedChildPattern.pFirst;
  pLast = this->CachedChildPattern.pLast;
  ibundles.pFirst = pFirst;
  ibundles.pLast = pLast;
  if ( pFirst )
  {
    while ( 1 )
    {
      Scaleform::Render::BundleEntry::UpdateBundleEntry(pFirst, this, this->pRenderer2D, &ibundles);
      if ( ibundles.pFirst == ibundles.pLast )
        break;
      pFirst = ibundles.pFirst->pNextPattern;
      ibundles.pFirst = pFirst;
      if ( !pFirst )
        goto LABEL_102;
    }
    ibundles.pLast = 0;
    ibundles.pFirst = 0;
  }
LABEL_102:
  Stats = v54.Stats;
  ++BundlePatternFrameId;
  if ( v54.Stats )
  {
    p_NativePopCallstack = &v54.Stats->NativePopCallstack;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
      Stats,
      ProfileTicks - LODWORD(v54.StartTicks),
      (ProfileTicks - v54.StartTicks) >> 32);
  }
}
