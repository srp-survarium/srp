char __thiscall Scaleform::Render::TreeCacheNode::calcChildMaskBounds(
        Scaleform::Render::TreeCacheNode *this,
        Scaleform::Render::Rect<float> *bounds,
        Scaleform::Render::TreeCacheNode *child)
{
  Scaleform::Render::TreeCacheNode *v3; // edi
  unsigned int v4; // ebx
  bool v5; // al
  Scaleform::Render::TreeCacheNode *v6; // esi
  unsigned int v7; // ecx
  int v8; // edi
  int v9; // edx
  const Scaleform::Render::TreeNode::NodeData *NodeData; // eax
  float v11; // ecx
  int *p_M34; // eax
  int v13; // ecx
  const Scaleform::Render::Rect<float> *v14; // eax
  Scaleform::Render::TreeCacheNode *pMask; // ecx
  Scaleform::Render::TreeCacheNode *pParent; // eax
  const Scaleform::Render::Matrix2x4<float> *p_result; // edx
  const Scaleform::Render::TreeNode::NodeData *v20; // [esp+Ch] [ebp-64h]
  Scaleform::Render::Rect<float> boundsa; // [esp+10h] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> v22; // [esp+20h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> result; // [esp+30h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> pviewMatrix; // [esp+50h] [ebp-20h] BYREF

  v3 = this;
  v4 = *(_DWORD *)(*(_DWORD *)(((int)child->pMask->pNode & 0xFFFFF000) + 0x14)
                 + 4 * ((int)((int)&child->pMask->pNode[-1] - ((int)child->pMask->pNode & 0xFFFFF000)) / 28)
                 + 20)
     & 0xFFFFFFFE;
  if ( (*(_BYTE *)(v4 + 6) & 1) == 0
    || *(float *)(v4 + 136) <= (double)*(float *)(v4 + 128)
    || *(float *)(v4 + 140) <= (double)*(float *)(v4 + 132) )
  {
    return 0;
  }
  v5 = (*(_WORD *)(v4 + 6) & 0x200) != 0;
  v6 = this;
  if ( this )
  {
    while ( !v5 )
    {
      v7 = (int)v6->pNode & 0xFFFFF000;
      v8 = (int)&v6->pNode[-1] - v7;
      v6 = v6->pParent;
      v9 = (unsigned __int64)(2454267027LL * v8) >> 32;
      v3 = this;
      v5 = (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(v7 + 20) + 4 * ((v9 >> 4) + ((unsigned int)v9 >> 31)) + 20) & 0xFFFFFFFE)
                     + 6)
          & 0x200) != 0;
      if ( !v6 )
        goto LABEL_7;
    }
    goto LABEL_8;
  }
LABEL_7:
  if ( v5 )
  {
LABEL_8:
    NodeData = Scaleform::Render::TreeCacheNode::GetNodeData(v3->pRoot);
    v11 = NodeData[1].M34.M[2][2];
    boundsa.x1 = -1.0;
    p_M34 = (int *)&NodeData[1].M34;
    boundsa.y1 = -1.0;
    v13 = LOBYTE(v11) & 0x30;
    boundsa.x2 = 1.0;
    boundsa.y2 = 1.0;
    if ( v13 == 16 || v13 == 48 )
      v14 = Scaleform::Render::Viewport::ScaleToViewport<int>(
              (Scaleform::Render::Rect<float> *)&result,
              p_M34[2],
              p_M34[3],
              p_M34[5],
              p_M34[4],
              &boundsa);
    else
      v14 = Scaleform::Render::Viewport::ScaleToViewport<int>(&v22, p_M34[2], p_M34[3], p_M34[4], p_M34[5], &boundsa);
    Scaleform::Render::Rect<float>::operator=(bounds, v14);
    return 1;
  }
  v20 = Scaleform::Render::TreeCacheNode::GetNodeData(child);
  Scaleform::Render::Matrix2x4<float>::operator=(&pviewMatrix, (const Scaleform::Render::Matrix2x4<float> *)(v4 + 16));
  pMask = child->pMask;
  pParent = pMask->pParent;
  if ( pParent != v3 )
  {
    if ( pParent == child )
    {
      p_result = (const Scaleform::Render::Matrix2x4<float> *)&v20->M34;
    }
    else
    {
      Scaleform::Render::TreeCacheNode::CalcViewMatrix(pMask, &pviewMatrix);
      Scaleform::Render::Matrix2x4<float>::Matrix2x4<float>(&result);
      Scaleform::Render::TreeCacheNode::CalcViewMatrix(v3, &result);
      p_result = &result;
    }
    Scaleform::Render::Matrix2x4<float>::Append(&pviewMatrix, p_result);
  }
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pviewMatrix, (__m128 *)&boundsa, (__m128 *)(v4 + 112));
  Scaleform::Render::Rect<float>::operator=(bounds, &boundsa);
  return 1;
}
