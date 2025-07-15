int __thiscall Scaleform::Render::TreeCacheNode::calcFilterBounds(
        Scaleform::Render::TreeCacheNode *this,
        __m128 *filterBounds,
        Scaleform::Render::Matrix2x4<float> *filterAreaMatrix,
        const Scaleform::Render::Matrix3x4<float> *viewMatrix,
        const Scaleform::Render::Matrix4x4<float> *viewProjMatrix,
        Scaleform::Render::Rect<float> *cullRect)
{
  Scaleform::Render::TreeCacheNode *v6; // edi
  Scaleform::Render::TreeNode *pNode; // eax
  unsigned int v8; // ecx
  signed int v9; // esi
  Scaleform::Render::TreeCacheRoot *pRoot; // eax
  unsigned int v11; // ebx
  bool v13; // al
  Scaleform::Render::TreeCacheNode *v14; // esi
  unsigned int v15; // ecx
  int v16; // edi
  int v17; // edx
  Scaleform::Render::TreeCacheRoot *v18; // eax
  Scaleform::Render::TreeNode *v19; // eax
  unsigned int v20; // esi
  Scaleform::Render::Viewport *v21; // esi
  Scaleform::Render::Rect<float> *p_r; // eax
  unsigned int Flags; // esi
  int v24; // esi
  char v25; // bl
  double x1; // st7
  double y1; // st6
  double x2; // st5
  double y2; // st4
  float v30; // [esp+14h] [ebp-94h]
  float v31; // [esp+14h] [ebp-94h]
  float v32; // [esp+14h] [ebp-94h]
  float v33; // [esp+14h] [ebp-94h]
  float v34; // [esp+14h] [ebp-94h]
  Scaleform::Render::Rect<float> bounds; // [esp+18h] [ebp-90h] BYREF
  Scaleform::Render::Rect<float> v36; // [esp+28h] [ebp-80h] BYREF
  Scaleform::Render::Rect<float> r; // [esp+38h] [ebp-70h] BYREF
  float v38; // [esp+50h] [ebp-58h]
  float v39; // [esp+54h] [ebp-54h]
  Scaleform::Render::Rect<float> pdest; // [esp+58h] [ebp-50h] BYREF
  Scaleform::Render::Matrix4x4<float> v41; // [esp+68h] [ebp-40h] BYREF

  v6 = this;
  pNode = this->pNode;
  v8 = (unsigned int)pNode & 0xFFFFF000;
  v9 = (signed int)&pNode[-1] - ((unsigned int)pNode & 0xFFFFF000);
  pRoot = v6->pRoot;
  v11 = *(_DWORD *)(*(_DWORD *)(v8 + 20) + 4 * (v9 / 28) + 20) & 0xFFFFFFFE;
  v38 = *(float *)&v6;
  if ( !pRoot )
    return 0;
  v13 = (*(_WORD *)(v11 + 6) & 0x200) != 0;
  v14 = v6;
  do
  {
    if ( v13 )
      break;
    v15 = (int)v14->pNode & 0xFFFFF000;
    v16 = (int)&v14->pNode[-1] - v15;
    v14 = v14->pParent;
    v17 = (unsigned __int64)(2454267027LL * v16) >> 32;
    v6 = (Scaleform::Render::TreeCacheNode *)LODWORD(v38);
    v13 = (*(_WORD *)((*(_DWORD *)(*(_DWORD *)(v15 + 20) + 4 * ((v17 >> 4) + ((unsigned int)v17 >> 31)) + 20)
                     & 0xFFFFFFFE)
                    + 6)
         & 0x200) != 0;
  }
  while ( v14 );
  r.x1 = 0.0;
  r.y1 = 0.0;
  r.x2 = 0.0;
  r.y2 = 0.0;
  v36.x1 = 0.0;
  v36.y1 = 0.0;
  v36.x2 = 0.0;
  v36.y2 = 0.0;
  if ( v13 )
  {
    v18 = v6->pRoot;
    bounds.x1 = 0.0;
    v19 = v18->pNode;
    bounds.y1 = 0.0;
    bounds.x2 = 0.0;
    bounds.y2 = 0.0;
    v20 = (*(_DWORD *)(*(_DWORD *)(((unsigned int)v19 & 0xFFFFF000) + 0x14)
                     + 4 * ((int)((int)&v19[-1] - ((unsigned int)v19 & 0xFFFFF000)) / 28)
                     + 20)
         & 0xFFFFFFFE)
        + 160;
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v41, viewProjMatrix, viewMatrix);
    Scaleform::Render::Matrix4x4<float>::EncloseTransformHomogeneous(&v41, (__m128 *)&bounds, (__m128 *)(v11 + 112));
    Scaleform::Render::Viewport::ScaleToViewport<int>(
      (Scaleform::Render::Rect<float> *)&v41,
      0,
      0,
      *(_DWORD *)(v20 + 16),
      *(_DWORD *)(v20 + 20),
      &bounds);
    v36.x1 = v41.M[0][0];
    v36.y1 = v41.M[0][1];
    v36.x2 = v41.M[0][2];
    v36.y2 = v41.M[0][3];
  }
  else
  {
    v41.M[0][0] = viewMatrix->M[0][0];
    v41.M[0][1] = viewMatrix->M[0][1];
    v41.M[0][2] = viewMatrix->M[0][2];
    v41.M[0][3] = viewMatrix->M[0][3];
    v41.M[1][0] = viewMatrix->M[1][0];
    v41.M[1][1] = viewMatrix->M[1][1];
    v41.M[1][2] = viewMatrix->M[1][2];
    v41.M[1][3] = viewMatrix->M[1][3];
    v38 = *(float *)(v11 + 116);
    v39 = *(float *)(v11 + 120);
    v30 = *(float *)(v11 + 124);
    filterBounds->m128_f32[0] = *(float *)(v11 + 112);
    filterBounds->m128_f32[1] = v38;
    filterBounds->m128_f32[2] = v39;
    filterBounds->m128_f32[3] = v30;
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(
      (Scaleform::Render::Matrix2x4<float> *)&v41,
      (__m128 *)&v36,
      filterBounds);
  }
  v21 = (Scaleform::Render::Viewport *)((*(_DWORD *)(*(_DWORD *)(((int)v6->pRoot->pNode & 0xFFFFF000) + 0x14)
                                                   + 4
                                                   * ((int)((int)&v6->pRoot->pNode[-1]
                                                          - ((int)v6->pRoot->pNode & 0xFFFFF000))
                                                    / 28)
                                                   + 20)
                                       & 0xFFFFFFFE)
                                      + 160);
  Scaleform::Render::Viewport::GetCullRectF(v21, &r, 1);
  p_r = cullRect;
  if ( !cullRect )
    p_r = &r;
  Flags = v21->Flags;
  bounds.x1 = p_r->x1;
  v24 = Flags & 0x30;
  bounds.y1 = p_r->y1;
  bounds.x2 = p_r->x2;
  bounds.y2 = p_r->y2;
  if ( v24 == 16 || v24 == 48 )
  {
    bounds.x1 = r.y1;
    bounds.y1 = r.x1;
    bounds.x2 = r.y2;
    bounds.y2 = r.x2;
  }
  pdest.x1 = bounds.x1;
  pdest.y1 = bounds.y1;
  pdest.x2 = bounds.x2;
  pdest.y2 = bounds.y2;
  Scaleform::Render::TreeNode::NodeData::expandByFilterBounds((Scaleform::Render::TreeNode::NodeData *)v11, &pdest, 0);
  r.x1 = bounds.x1 - 32.0;
  r.x2 = bounds.x2 + 32.0;
  r.y1 = bounds.y1 - 32.0;
  r.y2 = bounds.y2 + 32.0;
  Scaleform::Render::Rect<float>::IntersectRect(&pdest, &pdest, &r);
  v25 = 1;
  bounds.x1 = v36.x1;
  bounds.y1 = v36.y1;
  bounds.x2 = v36.x2;
  bounds.y2 = v36.y2;
  if ( r.x2 < (double)v36.x2 || r.y2 < (double)v36.y2 || r.x1 > (double)v36.x1 || r.y1 > (double)v36.y1 )
  {
    v25 = 0;
    if ( !Scaleform::Render::Rect<float>::IntersectRect(&r, &bounds, &v36) )
      return 0;
  }
  v31 = floor(bounds.x1);
  v36.x1 = v31;
  v32 = floor(bounds.y1);
  v36.y1 = v32;
  v33 = ceil(bounds.x2);
  v36.x2 = v33;
  v34 = ceil(bounds.y2);
  v36.y2 = v34;
  x1 = v36.x1;
  filterBounds->m128_f32[0] = v36.x1;
  y1 = v36.y1;
  filterBounds->m128_f32[1] = v36.y1;
  x2 = v36.x2;
  filterBounds->m128_f32[2] = v36.x2;
  y2 = v36.y2;
  filterBounds->m128_f32[3] = v36.y2;
  filterAreaMatrix->M[0][0] = x2 - x1;
  filterAreaMatrix->M[0][1] = 0.0;
  filterAreaMatrix->M[0][2] = 0.0;
  filterAreaMatrix->M[1][0] = 0.0;
  filterAreaMatrix->M[0][3] = x1;
  filterAreaMatrix->M[1][1] = y2 - y1;
  filterAreaMatrix->M[1][2] = 0.0;
  filterAreaMatrix->M[1][3] = y1;
  return (v25 != 0) + 1;
}
