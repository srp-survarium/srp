int __thiscall Scaleform::Render::TreeCacheNode::calcMaskBounds(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Rect<float> *maskBounds,
        Scaleform::Render::Matrix2x4<float> *boundAreaMatrix,
        Scaleform::Render::Matrix3x4<float> *viewMatrix,
        const Scaleform::Render::Matrix4x4<float> *viewProjMatrix,
        Scaleform::Render::MaskEffectState oldState,
        __int16 flags)
{
  Scaleform::Render::TreeCacheNode *v7; // ebx
  unsigned int v8; // edi
  bool v9; // al
  Scaleform::Render::TreeCacheNode *v10; // esi
  int v11; // ecx
  signed int v12; // ebx
  unsigned int v13; // edx
  double v15; // st5
  double v16; // st3
  double v17; // st5
  double v18; // st3
  double v19; // st2
  const Scaleform::Render::Viewport *p_M34; // esi
  Scaleform::Render::Rect<float> *v21; // eax
  Scaleform::Render::Rect<float> *v22; // eax
  const Scaleform::Render::Rect<float> *v23; // eax
  double x1; // st7
  double y1; // st6
  unsigned int v0_Sx; // [esp+65Ch] [ebp-F8h]
  unsigned int v4_Sy; // [esp+66Ch] [ebp-E8h]
  float v28; // [esp+68Ch] [ebp-C8h]
  float v29; // [esp+68Ch] [ebp-C8h]
  float v30; // [esp+68Ch] [ebp-C8h]
  float v31; // [esp+68Ch] [ebp-C8h]
  float v32; // [esp+68Ch] [ebp-C8h]
  float v33; // [esp+68Ch] [ebp-C8h]
  float v34; // [esp+68Ch] [ebp-C8h]
  unsigned int v35; // [esp+68Ch] [ebp-C8h]
  unsigned int v36; // [esp+68Ch] [ebp-C8h]
  __m128 *v37; // [esp+690h] [ebp-C4h]
  float v38; // [esp+690h] [ebp-C4h]
  float v39; // [esp+690h] [ebp-C4h]
  float v40; // [esp+690h] [ebp-C4h]
  Scaleform::Render::Rect<float> pr; // [esp+694h] [ebp-C0h] BYREF
  unsigned int v42; // [esp+6B0h] [ebp-A4h]
  Scaleform::Render::Rect<float> rect; // [esp+6B4h] [ebp-A0h] BYREF
  Scaleform::Render::Rect<float> pdest; // [esp+6C4h] [ebp-90h] BYREF
  Scaleform::Render::Rect<float> result; // [esp+6D4h] [ebp-80h] BYREF
  Scaleform::Render::Matrix4x4<float> v46; // [esp+6E4h] [ebp-70h] BYREF
  Scaleform::Render::Matrix3x4<float> v47; // [esp+724h] [ebp-30h] BYREF

  v7 = this;
  v42 = (unsigned int)this;
  v37 = (__m128 *)(*(_DWORD *)(*(_DWORD *)(((int)this->pNode & 0xFFFFF000) + 0x14)
                             + 4 * ((int)((int)&this->pNode[-1] - ((int)this->pNode & 0xFFFFF000)) / 28)
                             + 20)
                 & 0xFFFFFFFE);
  v8 = *(_DWORD *)(*(_DWORD *)(((int)this->pMask->pNode & 0xFFFFF000) + 0x14)
                 + 4 * ((int)((int)&this->pMask->pNode[-1] - ((int)this->pMask->pNode & 0xFFFFF000)) / 28)
                 + 20)
     & 0xFFFFFFFE;
  if ( (*(_BYTE *)(v8 + 6) & 1) == 0 || !this->pRoot )
    return 0;
  v9 = (*(_WORD *)(v8 + 6) & 0x200) != 0;
  v10 = this;
  while ( 1 )
  {
    if ( v9 )
      goto LABEL_15;
    v11 = *(_DWORD *)(((int)v10->pNode & 0xFFFFF000) + 0x14);
    v12 = (signed int)&v10->pNode[-1] - ((int)v10->pNode & 0xFFFFF000);
    v10 = v10->pParent;
    v13 = *(_DWORD *)(v11 + 4 * (v12 / 28) + 20) & 0xFFFFFFFE;
    v9 = (*(_WORD *)(v13 + 6) & 0x200) != 0;
    if ( !v10 )
      break;
    v7 = (Scaleform::Render::TreeCacheNode *)v42;
  }
  if ( (*(_WORD *)(v13 + 6) & 0x200) != 0 )
  {
    v7 = (Scaleform::Render::TreeCacheNode *)v42;
LABEL_15:
    pr.x1 = 0.0;
    pr.y1 = 0.0;
    pr.x2 = 0.0;
    pr.y2 = 0.0;
    memset((int)&v46, 0, sizeof(v46));
    v46.M[0][0] = 1.0;
    v46.M[1][1] = 1.0;
    v46.M[2][2] = 1.0;
    v46.M[3][3] = 1.0;
    memset((int)&v47, 0, sizeof(v47));
    v47.M[0][0] = 1.0;
    v47.M[1][1] = 1.0;
    v47.M[2][2] = 1.0;
    Scaleform::Render::TreeCacheNode::CalcViewMatrix(v7->pMask, &v47, &v46);
    p_M34 = (const Scaleform::Render::Viewport *)&Scaleform::Render::TreeCacheNode::GetNodeData(v7->pRoot)[1].M34;
    v21 = Scaleform::Render::TransformBounds3D(&result, &v46, p_M34, &v47, (__m128 *)(v8 + 112), 0);
    Scaleform::Render::Rect<float>::operator=(maskBounds, v21);
    v22 = Scaleform::Render::TransformBounds3D(&result, viewProjMatrix, p_M34, viewMatrix, v37 + 7, 0);
    Scaleform::Render::Rect<float>::operator=(&pr, v22);
    if ( !Scaleform::Render::Rect<float>::IntersectRect(maskBounds, &result, &pr) )
      return 1;
    v23 = Scaleform::Render::Rect<float>::Union(maskBounds, &pr);
    Scaleform::Render::Rect<float>::operator=(maskBounds, v23);
    Scaleform::Render::Rect<float>::Rect<float>(&pr, maskBounds);
    Scaleform::Render::SnapRectToPixels(&pr);
    x1 = pr.x1;
    boundAreaMatrix->M[0][0] = pr.x2 - pr.x1;
    boundAreaMatrix->M[0][1] = 0.0;
    boundAreaMatrix->M[0][2] = 0.0;
    boundAreaMatrix->M[1][0] = 0.0;
    boundAreaMatrix->M[0][3] = x1;
    y1 = pr.y1;
    boundAreaMatrix->M[1][1] = pr.y2 - pr.y1;
    boundAreaMatrix->M[1][2] = 0.0;
    boundAreaMatrix->M[1][3] = y1;
    return 3;
  }
  else
  {
    v46.M[0][0] = viewMatrix->M[0][0];
    v46.M[0][1] = viewMatrix->M[0][1];
    v46.M[0][2] = viewMatrix->M[0][2];
    v46.M[0][3] = viewMatrix->M[0][3];
    v46.M[1][0] = viewMatrix->M[1][0];
    v46.M[1][1] = viewMatrix->M[1][1];
    v46.M[1][2] = viewMatrix->M[1][2];
    v46.M[1][3] = viewMatrix->M[1][3];
    Scaleform::Render::Matrix2x4<float>::operator=(
      (Scaleform::Render::Matrix2x4<float> *)&v47,
      (const Scaleform::Render::Matrix2x4<float> *)(v8 + 16));
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(
      (Scaleform::Render::Matrix2x4<float> *)&v47,
      &pr,
      (__m128 *)(v8 + 112));
    Scaleform::Render::Rect<float>::operator=(maskBounds, &pr);
    pdest.x1 = 0.0;
    pdest.y1 = 0.0;
    pdest.x2 = 0.0;
    pdest.y2 = 0.0;
    rect.x1 = 0.0;
    rect.y1 = 0.0;
    rect.x2 = 0.0;
    rect.y2 = 0.0;
    if ( !Scaleform::Render::Rect<float>::IntersectRect(
            maskBounds,
            &pdest,
            (const Scaleform::Render::Rect<float> *)&v37[7]) )
      return 1;
    Scaleform::Render::Rect<float>::UnionRect(maskBounds, &rect, (const Scaleform::Render::Rect<float> *)&v37[7]);
    Scaleform::Render::SnapRectToPixels(&rect);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(
      (Scaleform::Render::Matrix2x4<float> *)&v46,
      &result,
      (__m128 *)&rect);
    v28 = rect.x2 - rect.x1;
    *(float *)&v42 = rect.y2 - rect.y1;
    v38 = pdest.x2 - pdest.x1;
    v15 = v38;
    v39 = pdest.y2 - pdest.y1;
    v40 = v15 * v39;
    v16 = v28;
    v29 = *(float *)&v42 * v28;
    v17 = v16;
    v30 = v40 / v29;
    v18 = 1.0 - v30;
    v31 = result.x2 - result.x1;
    v19 = v31;
    v32 = result.y2 - result.y1;
    v33 = v19 * v32;
    v34 = v18 * v33;
    if ( MaskClipAreasThresholds[oldState] >= (double)v34 || (flags & 0x100) != 0 )
    {
      *(float *)&v0_Sx = v17;
      Scaleform::Render::Matrix2x4<float>::SetMatrix(
        boundAreaMatrix,
        v0_Sx,
        COERCE_UNSIGNED_INT(0.0),
        rect.x1,
        0.0,
        v42,
        rect.y1);
      Scaleform::Render::Matrix2x4<float>::Append(boundAreaMatrix, (const Scaleform::Render::Matrix2x4<float> *)&v46);
      return 3;
    }
    else
    {
      pr.x1 = 0.0;
      pr.y1 = 0.0;
      pr.x2 = 0.0;
      pr.y2 = 0.0;
      Scaleform::Render::Matrix3x4<float>::EncloseTransform(viewMatrix, &pr, &pdest);
      Scaleform::Render::SnapRectToPixels(&pr);
      *(float *)&v35 = pr.y2 - pr.y1;
      v4_Sy = v35;
      *(float *)&v36 = pr.x2 - pr.x1;
      Scaleform::Render::Matrix2x4<float>::SetMatrix(
        boundAreaMatrix,
        v36,
        COERCE_UNSIGNED_INT(0.0),
        pr.x1,
        0.0,
        v4_Sy,
        pr.y1);
      return 2;
    }
  }
}
