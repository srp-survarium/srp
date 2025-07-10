void __thiscall Scaleform::Render::TreeCacheRoot::UpdateTreeData(Scaleform::Render::TreeCacheRoot *this)
{
  Scaleform::Render::TreeCacheNode *v1; // edi
  int v2; // esi
  Scaleform::Render::TreeCacheNode *pParent; // eax
  int v4; // eax
  void (__thiscall *propagate3DFlag)(Scaleform::Render::TreeCacheNode *, unsigned int); // eax
  Scaleform::Render::TreeCacheNode *v6; // ebx
  unsigned int v7; // eax
  unsigned int State; // eax
  Scaleform::Render::FilterSet *v9; // eax
  int v10; // ebx
  const Scaleform::Render::Cxform *v11; // edx
  Scaleform::Render::Matrix3x4<float> *v12; // ecx
  const Scaleform::Render::Matrix2x4<float> *v13; // eax
  const Scaleform::Render::ViewMatrix3DState *v14; // edi
  const Scaleform::Render::ProjectionMatrix3DState *v15; // eax
  unsigned int v16; // ebx
  Scaleform::Render::TreeCacheNode *v17; // edi
  double v18; // st7
  unsigned int v19; // esi
  unsigned int v20; // eax
  Scaleform::Render::FilterSet *v21; // eax
  Scaleform::Render::TreeCacheRoot *pRoot; // eax
  Scaleform::Render::TreeCacheNode *v23; // edi
  int v24; // ecx
  Scaleform::Render::Matrix3x4<float> *Depth; // ecx
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *p_DepthUpdates; // eax
  unsigned int v27; // ecx
  unsigned int i; // edi
  Scaleform::Render::TreeCacheNode *j; // esi
  unsigned int k; // eax
  Scaleform::Render::BundleEntry *pFirst; // ecx
  Scaleform::Render::BundleEntry *pLast; // eax
  char v33; // [esp+1122h] [ebp-1AEh]
  bool v34; // [esp+1123h] [ebp-1ADh]
  const Scaleform::Render::ProjectionMatrix3DState *v36; // [esp+1128h] [ebp-1A8h]
  Scaleform::Render::TreeCacheNode *v37; // [esp+112Ch] [ebp-1A4h]
  Scaleform::Render::Matrix3x4<float> *m1; // [esp+1130h] [ebp-1A0h]
  Scaleform::Render::Matrix3x4<float> *m1a; // [esp+1130h] [ebp-1A0h]
  unsigned int v40; // [esp+1134h] [ebp-19Ch]
  const Scaleform::Render::ViewMatrix3DState *v41; // [esp+1138h] [ebp-198h]
  int v42; // [esp+113Ch] [ebp-194h]
  Scaleform::Render::TreeCacheNode *v43; // [esp+1140h] [ebp-190h]
  Scaleform::Render::BundleIterator v44; // [esp+1144h] [ebp-18Ch] BYREF
  Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *> *v45; // [esp+114Ch] [ebp-184h]
  unsigned __int8 src[60]; // [esp+1150h] [ebp-180h] BYREF
  unsigned int DepthUsed; // [esp+118Ch] [ebp-144h]
  Scaleform::Render::TransformArgs v48; // [esp+1190h] [ebp-140h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+1270h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [esp+12A0h] [ebp-30h] BYREF

  DepthUsed = this->DepthUpdates.DepthUsed;
  v42 = 0;
  if ( DepthUsed )
  {
    while ( 1 )
    {
      v1 = this->DepthUpdates.pDepth[v42];
      v37 = v1;
      if ( v1 )
        break;
LABEL_88:
      if ( ++v42 >= DepthUsed )
        goto LABEL_89;
    }
    while ( 1 )
    {
      v2 = v1->UpdateFlags & 3;
      if ( ((unsigned int)&_sbh_sizeHeaderList & v1->UpdateFlags) != 0 )
      {
        pParent = v1->pParent;
        if ( pParent )
          v4 = pParent->Flags & 0x80;
        else
          v4 = 0;
        v1->propagateScale9Flag(v1, v4);
        v1->UpdateFlags &= ~0x10000u;
        v2 |= 1u;
      }
      if ( (v1->UpdateFlags & 0x2000) != 0 )
      {
        propagate3DFlag = v1->propagate3DFlag;
        v1->Flags = v1->Flags & 0xFDFF
                  | (((*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v1->pNode & 0xFFFFF000) + 0x14)
                                             + 4 * ((int)((int)&v1->pNode[-1] - ((int)v1->pNode & 0xFFFFF000)) / 28)
                                             + 20)
                                 & 0xFFFFFFFE)
                                + 6)
                     & 0x200) != 0) << 9);
        propagate3DFlag(v1, 0);
        v1->UpdateFlags &= ~0x2000u;
        v2 |= 1u;
      }
      if ( !v2 )
      {
        v6 = v1;
        while ( 1 )
        {
          v7 = *(_DWORD *)(*(_DWORD *)(((int)v6->pNode & 0xFFFFF000) + 0x14)
                         + 4 * ((int)((int)&v6->pNode[-1] - ((int)v6->pNode & 0xFFFFF000)) / 28)
                         + 20)
             & 0xFFFFFFFE;
          if ( (*(_WORD *)(v7 + 6) & 0x400) != 0 )
          {
            State = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v7 + 64), State_ActionControl);
            if ( State )
            {
              v9 = *(Scaleform::Render::FilterSet **)(State + 4);
              if ( v9 )
              {
                if ( Scaleform::Render::FilterSet::IsContributing(v9) )
                  break;
              }
            }
          }
          v6 = v6->pParent;
          if ( !v6 )
            goto LABEL_87;
        }
        v2 = 2;
      }
      v40 = *(_DWORD *)(*(_DWORD *)(((int)v37->pNode & 0xFFFFF000) + 0x14)
                      + 4 * ((int)((int)&v37->pNode[-1] - ((int)v37->pNode & 0xFFFFF000)) / 28)
                      + 20)
          & 0xFFFFFFFE;
      v10 = v2 | (this->ViewValid ? 0x10 : 0);
      v33 = v2 != 0;
      v34 = (*(_WORD *)(v40 + 6) & 0x200) != 0;
      if ( (*(_WORD *)(v40 + 6) & 0x400) != 0 )
        v11 = &Scaleform::Render::Cxform::Identity;
      else
        v11 = (const Scaleform::Render::Cxform *)(v40 + 80);
      if ( (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(((int)v37->pNode & 0xFFFFF000) + 0x14)
                                  + 4 * ((int)((int)&v37->pNode[-1] - ((int)v37->pNode & 0xFFFFF000)) / 28)
                                  + 20)
                      & 0xFFFFFFFE)
                     + 6)
          & 0x200) != 0 )
      {
        v12 = (Scaleform::Render::Matrix3x4<float> *)(v40 + 16);
        v13 = &Scaleform::Render::Matrix2x4<float>::Identity;
      }
      else
      {
        v12 = &Scaleform::Render::Matrix3x4<float>::Identity;
        v13 = (const Scaleform::Render::Matrix2x4<float> *)(v40 + 16);
      }
      Scaleform::Render::TransformArgs::TransformArgs(&v48, &this->ViewCullRect, v13, v12, v11);
      if ( (*(_WORD *)(v40 + 6) & 0x800) != 0 )
        v14 = (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                              (Scaleform::Render::StateBag *)(v40 + 64),
                                                              State_FSCommandHandler);
      else
        v14 = 0;
      if ( (*(_WORD *)(v40 + 6) & 0x1000) != 0 )
        v15 = (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                    (Scaleform::Render::StateBag *)(v40 + 64),
                                                                    State_ExternalInterface);
      else
        v15 = 0;
      if ( v14 )
      {
        v48.viewState = v14;
        v48.bRecomputeViewProj = 1;
      }
      if ( v15 )
      {
        v48.projState = v15;
        v48.bRecomputeViewProj = 1;
      }
      v16 = (v34 ? 128 : 64) | v10;
      v41 = (*(_WORD *)(v40 + 6) & 0x800) != 0
          ? (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                            (Scaleform::Render::StateBag *)(v40 + 64),
                                                            State_FSCommandHandler)
          : 0;
      v36 = (*(_WORD *)(v40 + 6) & 0x1000) != 0
          ? (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                  (Scaleform::Render::StateBag *)(v40 + 64),
                                                                  State_ExternalInterface)
          : 0;
      v17 = v37->pParent;
      v43 = v17;
      if ( v17 )
        break;
LABEL_82:
      if ( v41 )
      {
        v48.viewState = v41;
        v48.bRecomputeViewProj = 1;
      }
      if ( v36 )
      {
        v48.projState = v36;
        v48.bRecomputeViewProj = 1;
      }
      v37->UpdateTransform(
        v37,
        (const Scaleform::Render::TreeNode::NodeData *)v40,
        &v48,
        (Scaleform::Render::TransformFlags)v16);
      v37->UpdateFlags &= 0xFFFFFFFC;
      v1 = v37;
LABEL_87:
      v1 = v1->pNextUpdate;
      v37 = v1;
      if ( !v1 )
        goto LABEL_88;
    }
    v18 = 0.0;
    while ( 1 )
    {
      if ( (v17->Flags & 3) != 1 )
        v16 &= ~0x10u;
      v19 = *(_DWORD *)(*(_DWORD *)(((int)v17->pNode & 0xFFFFF000) + 0x14)
                      + 4 * ((int)((int)&v17->pNode[-1] - ((int)v17->pNode & 0xFFFFF000)) / 28)
                      + 20)
          & 0xFFFFFFFE;
      if ( (v16 & 0x80u) == 0 )
      {
        if ( (*(_WORD *)(v19 + 6) & 0x200) != 0 )
        {
          *(float *)src = v48.Mat.M[0][0];
          *(float *)&src[4] = v48.Mat.M[0][1];
          *(float *)&src[8] = v48.Mat.M[0][2];
          *(float *)&src[12] = v48.Mat.M[0][3];
          *(float *)&src[16] = v48.Mat.M[1][0];
          *(float *)&src[20] = v48.Mat.M[1][1];
          *(float *)&src[24] = v48.Mat.M[1][2];
          *(float *)&src[28] = v48.Mat.M[1][3];
          *(float *)&src[32] = v18;
          *(float *)&src[36] = v18;
          *(float *)&src[40] = 1.0;
          *(float *)&src[44] = v18;
          memcpy((unsigned __int8 *)&v48.Mat3D, src, sizeof(v48.Mat3D));
          memcpy((unsigned __int8 *)&m2, (unsigned __int8 *)&v48.Mat3D, sizeof(m2));
          Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(
            &v48.Mat3D,
            (const Scaleform::Render::Matrix3x4<float> *)(v19 + 16),
            &m2);
          v48.Mat.M[0][0] = 1.0;
          v16 = v16 & 0xFFFFFF3F | 0x80;
          v48.Mat.M[0][1] = 0.0;
          v48.Mat.M[0][2] = 0.0;
          v48.Mat.M[0][3] = 0.0;
          v48.Mat.M[1][0] = 0.0;
          v48.Mat.M[1][2] = 0.0;
          v48.Mat.M[1][3] = 0.0;
          v18 = 0.0;
          v48.Mat.M[1][1] = 1.0;
          goto LABEL_54;
        }
        Scaleform::Render::Matrix2x4<float>::Append(&v48.Mat, (const Scaleform::Render::Matrix2x4<float> *)(v19 + 16));
      }
      else
      {
        if ( (*(_WORD *)(v19 + 6) & 0x200) != 0 )
        {
          m1 = (Scaleform::Render::Matrix3x4<float> *)(v19 + 16);
        }
        else
        {
          *(float *)src = *(float *)(v19 + 16);
          m1 = (Scaleform::Render::Matrix3x4<float> *)src;
          *(float *)&src[4] = *(float *)(v19 + 20);
          *(float *)&src[8] = *(float *)(v19 + 24);
          *(float *)&src[12] = *(float *)(v19 + 28);
          *(float *)&src[16] = *(float *)(v19 + 32);
          *(float *)&src[20] = *(float *)(v19 + 36);
          *(float *)&src[24] = *(float *)(v19 + 40);
          *(float *)&src[28] = *(float *)(v19 + 44);
          *(float *)&src[32] = v18;
          *(float *)&src[36] = v18;
          *(float *)&src[40] = 1.0;
          *(float *)&src[44] = v18;
        }
        memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)&v48.Mat3D, sizeof(dst));
        Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v48.Mat3D, m1, &dst);
      }
      v18 = 0.0;
LABEL_54:
      v33 |= (v17->UpdateFlags & 3) != 0;
      if ( (*(_WORD *)(v19 + 6) & 0x400) != 0 )
      {
        v20 = Scaleform::Render::StateBag::GetState((Scaleform::Render::StateBag *)(v19 + 64), State_ActionControl);
        if ( v20 )
        {
          v21 = *(Scaleform::Render::FilterSet **)(v20 + 4);
          if ( v21 )
          {
            if ( Scaleform::Render::FilterSet::IsContributing(v21) )
            {
              if ( v33 )
              {
                pRoot = v17->pRoot;
                v17->UpdateFlags |= (unsigned int)&vostok::memory::s_CRT_arena[7671352];
                if ( pRoot )
                {
                  v23 = v43->pParent;
                  if ( v23 )
                  {
                    v24 = (int)&vostok::memory::s_CRT_arena[5574200];
                    if ( (v23->UpdateFlags & 0x80000000) == 0 )
                    {
                      if ( pRoot->DepthUpdatesChained )
                      {
                        Depth = (Scaleform::Render::Matrix3x4<float> *)v23->Depth;
                        p_DepthUpdates = &pRoot->DepthUpdates;
                        m1a = Depth;
                        v45 = p_DepthUpdates;
                        if ( (unsigned int)Depth < p_DepthUpdates->DepthAvailable )
                        {
LABEL_66:
                          v23->pNextUpdate = p_DepthUpdates->pDepth[(_DWORD)Depth];
                          p_DepthUpdates->pDepth[(_DWORD)Depth] = v23;
                          v27 = (unsigned int)&Depth->M[0][0] + 1;
                          if ( p_DepthUpdates->DepthUsed < v27 )
                            p_DepthUpdates->DepthUsed = v27;
                        }
                        else if ( Scaleform::Render::DepthUpdateArrayPOD<Scaleform::Render::TreeCacheNode *>::grow(
                                    p_DepthUpdates,
                                    (unsigned int)&Depth->M[0][0] + 1) )
                        {
                          Depth = m1a;
                          p_DepthUpdates = v45;
                          goto LABEL_66;
                        }
                      }
                      else
                      {
                        v23->pNextUpdate = pRoot->pUpdateList;
                        pRoot->pUpdateList = v23;
                      }
                      v24 = -2130706432;
                    }
                    v23->UpdateFlags |= v24;
                  }
                }
              }
              v17 = v43;
              v16 |= 0x100u;
            }
          }
        }
        v18 = 0.0;
      }
      if ( (v16 & 0x100) == 0 )
      {
        Scaleform::Render::Cxform::Prepend(&v48.Cx, (const Scaleform::Render::Cxform *)(v19 + 80));
        v18 = 0.0;
      }
      if ( !v41 && (*(_WORD *)(v19 + 6) & 0x800) != 0 )
      {
        v18 = 0.0;
        v41 = (const Scaleform::Render::ViewMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                              (Scaleform::Render::StateBag *)(v19 + 64),
                                                              State_FSCommandHandler);
      }
      if ( !v36 && (*(_WORD *)(v19 + 6) & 0x1000) != 0 )
      {
        v18 = 0.0;
        v36 = (const Scaleform::Render::ProjectionMatrix3DState *)Scaleform::Render::StateBag::GetState(
                                                                    (Scaleform::Render::StateBag *)(v19 + 64),
                                                                    State_ExternalInterface);
      }
      v17 = v17->pParent;
      v43 = v17;
      if ( !v17 )
        goto LABEL_82;
    }
  }
LABEL_89:
  for ( i = this->DepthUpdates.DepthUsed; i; --i )
  {
    for ( j = this->DepthUpdates.pDepth[i - 1]; j; j = j->pNextUpdate )
    {
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[39128632] & j->UpdateFlags) != 0 )
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
  v44.pFirst = pFirst;
  for ( v44.pLast = pLast; pFirst; v44.pFirst = pFirst )
  {
    Scaleform::Render::BundleEntry::UpdateBundleEntry(pFirst, this, this->pRenderer2D, &v44);
    if ( v44.pFirst == v44.pLast )
      break;
    pFirst = v44.pFirst->pNextPattern;
  }
  ++BundlePatternFrameId;
}
