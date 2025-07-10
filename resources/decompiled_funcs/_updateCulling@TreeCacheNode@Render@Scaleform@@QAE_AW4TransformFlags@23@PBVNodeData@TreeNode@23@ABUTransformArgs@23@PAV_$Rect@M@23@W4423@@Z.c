Scaleform::Render::TransformFlags __thiscall Scaleform::Render::TreeCacheNode::updateCulling(
        Scaleform::Render::TreeCacheNode *this,
        const Scaleform::Render::TreeNode::NodeData *data,
        const Scaleform::Render::TransformArgs *t,
        Scaleform::Render::Rect<float> *cullRect,
        Scaleform::Render::TransformFlags flags)
{
  bool v6; // zf
  double v7; // st7
  const Scaleform::Render::TransformArgs *v8; // edi
  Scaleform::Render::MaskEffect *pEffect; // esi
  const Scaleform::Render::Matrix4x4<float> *v10; // eax
  Scaleform::Render::MaskEffectState v11; // edi
  const Scaleform::Render::Matrix4x4<float> *ViewProj; // eax
  const Scaleform::Render::Matrix4x4<float> *v13; // eax
  Scaleform::Render::FilterEffect *FilterEffect; // esi
  const Scaleform::Render::Matrix4x4<float> *v15; // eax
  int v16; // eax
  bool v17; // al
  unsigned int State; // eax
  const Scaleform::Render::Matrix4x4<float> *v19; // eax
  Scaleform::Render::TreeCacheRoot *pRoot; // edi
  unsigned __int16 v21; // ax
  Scaleform::Render::TreeCacheNode *v22; // eax
  unsigned __int16 v23; // ax
  Scaleform::Render::TreeCacheNode *pParent; // eax
  Scaleform::Render::TransformFlags result; // eax
  const Scaleform::Render::Viewport *p_M34; // [esp+1534h] [ebp-1C0h]
  const Scaleform::Render::Viewport *v27; // [esp+1534h] [ebp-1C0h]
  Scaleform::Render::MaskEffectState MES; // [esp+153Ch] [ebp-1B8h]
  char v29; // [esp+155Ah] [ebp-19Ah]
  _BYTE v30[5]; // [esp+155Bh] [ebp-199h]
  int v31; // [esp+1560h] [ebp-194h]
  float v32; // [esp+1560h] [ebp-194h]
  float v33; // [esp+1560h] [ebp-194h]
  Scaleform::Render::Rect<float> maskBounds; // [esp+1564h] [ebp-190h] BYREF
  Scaleform::Render::FilterEffect *v35; // [esp+1580h] [ebp-174h]
  Scaleform::Render::Matrix2x4<float> boundAreaMatrix; // [esp+1584h] [ebp-170h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+15A4h] [ebp-150h] BYREF
  Scaleform::Render::Matrix3x4<float> viewMatrix; // [esp+15B4h] [ebp-140h] BYREF
  Scaleform::Render::Matrix3x4<float> v39; // [esp+15E4h] [ebp-110h] BYREF
  Scaleform::Render::TransformArgs v40; // [esp+1614h] [ebp-E0h] BYREF

  v30[4] = 0;
  v29 = 0;
  *(_DWORD *)v30 = (flags & 0x80) != 0;
  if ( (flags & 0x10) == 0 )
    goto LABEL_49;
  v6 = this->pMask == 0;
  v7 = 0.0;
  maskBounds.x1 = 0.0;
  maskBounds.y1 = 0.0;
  maskBounds.x2 = 0.0;
  maskBounds.y2 = 0.0;
  if ( v6 && (data->Flags & 0x400) == 0 )
  {
    v8 = t;
  }
  else
  {
    v8 = t;
    Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &viewMatrix);
    v7 = 0.0;
  }
  if ( this->pMask )
  {
    pEffect = (Scaleform::Render::MaskEffect *)this->Effects.pEffect;
    boundAreaMatrix.M[0][0] = 1.0;
    boundAreaMatrix.M[1][1] = 1.0;
    boundAreaMatrix.M[0][1] = v7;
    boundAreaMatrix.M[0][2] = v7;
    boundAreaMatrix.M[0][3] = v7;
    boundAreaMatrix.M[1][0] = v7;
    boundAreaMatrix.M[1][2] = v7;
    boundAreaMatrix.M[1][3] = v7;
    if ( pEffect )
    {
      while ( pEffect->GetType(pEffect) != State_UserEventHandler )
      {
        pEffect = (Scaleform::Render::MaskEffect *)pEffect->pNext;
        if ( !pEffect )
          goto LABEL_10;
      }
      MES = pEffect->MES;
      ViewProj = Scaleform::Render::TransformArgs::GetViewProj(v8);
      v11 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
              this,
              &maskBounds,
              &boundAreaMatrix,
              &viewMatrix,
              ViewProj,
              MES,
              flags);
      if ( Scaleform::Render::MaskEffect::UpdateMatrix(pEffect, v11, &boundAreaMatrix) )
      {
        this->UpdateFlags |= 0x40000u;
        Scaleform::Render::TreeCacheNode::addParentToDepthPatternUpdate(this);
      }
    }
    else
    {
LABEL_10:
      v10 = Scaleform::Render::TransformArgs::GetViewProj(v8);
      v11 = Scaleform::Render::TreeCacheNode::calcMaskBounds(
              this,
              &maskBounds,
              &boundAreaMatrix,
              &viewMatrix,
              v10,
              MES_NoMask,
              flags);
    }
    if ( v11 == MES_NoMask )
      goto LABEL_14;
    if ( v11 == MES_Culled )
    {
      *(_DWORD *)&v30[1] = 1;
      v29 = 1;
LABEL_14:
      v7 = 0.0;
      v8 = t;
      goto LABEL_22;
    }
    if ( (flags & 0x80) != 0 )
    {
      p_M34 = (const Scaleform::Render::Viewport *)&Scaleform::Render::TreeCacheNode::GetNodeData(this->pRoot)[1].M34;
      v13 = Scaleform::Render::TransformArgs::GetViewProj(t);
      Scaleform::Render::TransformBounds3D(&r, v13, p_M34, &viewMatrix, (__m128 *)&maskBounds, 0);
      if ( (LOBYTE(Scaleform::Render::TreeCacheNode::GetNodeData(this->pRoot)[1].M34.M[2][2]) & 0x30) != 0 )
        goto LABEL_14;
    }
    else
    {
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&t->Mat, &maskBounds, (__m128 *)&maskBounds);
    }
    if ( !Scaleform::Render::Rect<float>::IntersectRect(cullRect, cullRect, &maskBounds) )
    {
      v7 = 0.0;
      v8 = t;
      v29 = 1;
      *(_DWORD *)&v30[1] = 1;
      goto LABEL_22;
    }
    goto LABEL_14;
  }
LABEL_22:
  if ( (data->Flags & 0x400) != 0 && (flags & 3) != 0 )
  {
    boundAreaMatrix.M[0][0] = 1.0;
    boundAreaMatrix.M[1][1] = 1.0;
    boundAreaMatrix.M[0][1] = v7;
    boundAreaMatrix.M[0][2] = v7;
    boundAreaMatrix.M[0][3] = v7;
    boundAreaMatrix.M[1][0] = v7;
    boundAreaMatrix.M[1][2] = v7;
    boundAreaMatrix.M[1][3] = v7;
    r.x1 = v7;
    r.y1 = v7;
    r.x2 = v7;
    r.y2 = v7;
    FilterEffect = Scaleform::Render::CacheEffectChain::GetFilterEffect(&this->Effects);
    v35 = FilterEffect;
    if ( FilterEffect )
    {
      v15 = Scaleform::Render::TransformArgs::GetViewProj(v8);
      v16 = Scaleform::Render::TreeCacheNode::calcFilterBounds(
              this,
              (__m128 *)&r,
              &boundAreaMatrix,
              &viewMatrix,
              v15,
              cullRect);
      v31 = v16;
      if ( v16 )
      {
        if ( (flags & 2) != 0 )
        {
          qmemcpy(&v39, &v8->Cx, 0x20u);
          Scaleform::Render::Cxform::Append((Scaleform::Render::Cxform *)&v39, &data->Cx);
          Scaleform::Render::FilterEffect::UpdateCxform(v35, (const Scaleform::Render::Cxform *)&v39);
          FilterEffect = v35;
          v16 = v31;
          v8 = t;
        }
        if ( (flags & 1) != 0 )
        {
          v17 = (flags & 0x80) != 0 || v16 == 1;
          if ( Scaleform::Render::FilterEffect::UpdateMatrix(FilterEffect, &boundAreaMatrix, &v8->Mat, v17) )
          {
            State = Scaleform::Render::StateBag::GetState(&data->States, State_ActionControl);
            FilterEffect->Update(FilterEffect, (const Scaleform::Render::State *)State);
          }
        }
      }
    }
  }
  if ( (flags & 0x20) != 0 )
  {
    if ( v29 )
      goto LABEL_49;
    v32 = fabs(v8->Cx.M[0][3]);
    if ( v32 < 0.001 )
    {
      v33 = fabs(v8->Cx.M[1][3]);
      if ( v33 < 0.0039215689 && (this->Flags & 0x40) == 0 )
      {
        *(_DWORD *)&v30[1] = 2;
        goto LABEL_48;
      }
    }
  }
  else if ( v29 )
  {
    goto LABEL_49;
  }
  if ( !this->pRoot )
    goto LABEL_49;
  if ( (flags & 0x80) != 0 )
  {
    Scaleform::Render::TransformArgs::GetMatrix3D(v8, flags, &v39);
    v27 = (const Scaleform::Render::Viewport *)&Scaleform::Render::TreeCacheNode::GetNodeData(this->pRoot)[1].M34;
    v19 = Scaleform::Render::TransformArgs::GetViewProj(v8);
    Scaleform::Render::TransformBounds3D(&r, v19, v27, &v39, (__m128 *)&data->AproxLocalBounds, 1);
    if ( Scaleform::Render::Rect<float>::Intersects(cullRect, &r) )
      goto LABEL_49;
    *(_DWORD *)&v30[1] = 5;
  }
  else
  {
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v8->Mat, &maskBounds, (__m128 *)&data->AproxLocalBounds);
    if ( Scaleform::Render::Rect<float>::Intersects(cullRect, &maskBounds) )
      goto LABEL_49;
    *(_DWORD *)&v30[1] = 3;
  }
LABEL_48:
  v29 = 1;
LABEL_49:
  pRoot = this->pRoot;
  if ( pRoot
    && (*(_BYTE *)((*(_DWORD *)(*(_DWORD *)(((int)pRoot->pNode & 0xFFFFF000) + 0x14)
                              + 4 * ((int)((int)&pRoot->pNode[-1] - ((int)pRoot->pNode & 0xFFFFF000)) / 28)
                              + 20)
                  & 0xFFFFFFFE)
                 + 200)
      & 0x30) != 0
    || !v29
    || *(_DWORD *)&v30[1] == 5
    || this == pRoot )
  {
    v23 = this->Flags;
    if ( (v23 & 2) != 0 )
    {
      this->Flags = v23 & 0xFFFD;
      if ( pRoot )
      {
        pParent = this->pParent;
        if ( pParent )
          Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
            pRoot,
            pParent,
            (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
      }
    }
  }
  else
  {
    v21 = this->Flags;
    if ( (v21 & 2) == 0 )
    {
      this->Flags = v21 | 2;
      if ( pRoot )
      {
        v22 = this->pParent;
        if ( v22 )
          Scaleform::Render::TreeCacheRoot::AddToDepthUpdate(
            pRoot,
            v22,
            (unsigned int)&vostok::memory::s_CRT_arena[5574200]);
      }
    }
    flags &= ~0x10u;
  }
  result = flags;
  if ( this->pMask )
  {
    if ( (flags & 0x80u) != 0 )
    {
      Scaleform::Render::TransformArgs::GetMatrix3D(t, flags, &viewMatrix);
      Scaleform::Render::TransformArgs::TransformArgs(&v40, t, &viewMatrix);
      v40.Mat.M[0][0] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][0];
      v40.Mat.M[0][1] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][1];
      v40.Mat.M[0][2] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][2];
      v40.Mat.M[0][3] = Scaleform::Render::Matrix2x4<float>::Identity.M[0][3];
      v40.Mat.M[1][0] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][0];
      v40.Mat.M[1][1] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][1];
      v40.Mat.M[1][2] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][2];
      v40.Mat.M[1][3] = Scaleform::Render::Matrix2x4<float>::Identity.M[1][3];
    }
    else
    {
      Scaleform::Render::TransformArgs::TransformArgs(&v40, t, &t->Mat);
    }
    Scaleform::Render::TreeCacheNode::updateMaskTransform(this, &v40, flags);
    return flags;
  }
  return result;
}
