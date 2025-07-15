void __thiscall Scaleform::Render::Hairliner::generateContourAA(
        Scaleform::Render::Hairliner *this,
        unsigned int startEdgeIdx)
{
  Scaleform::Render::Hairliner *v2; // ebx
  Scaleform::Render::Hairliner::FanEdgeType *v3; // edi
  float *p_x; // ebp
  unsigned int v5; // eax
  unsigned int v6; // eax
  Scaleform::Render::Hairliner::FanEdgeType **Pages; // esi
  unsigned int v8; // edx
  int *v9; // ecx
  int v10; // eax
  unsigned int v11; // edx
  unsigned int v12; // ecx
  int v13; // ebp
  Scaleform::Render::Hairliner::OutVertexType **v14; // ecx
  Scaleform::Render::Hairliner::OutVertexType *v15; // edx
  double x; // st7
  Scaleform::Render::Hairliner::OutVertexType *v17; // edx
  Scaleform::Render::Hairliner::OutVertexType *v18; // ecx
  double v19; // st6
  Scaleform::Render::Hairliner::OutVertexType *v20; // ecx
  unsigned int Size; // eax
  unsigned int v22; // [esp+4h] [ebp-18h]
  float v24; // [esp+Ch] [ebp-10h]
  float v25; // [esp+10h] [ebp-Ch]
  unsigned int v26; // [esp+14h] [ebp-8h]
  Scaleform::Render::Hairliner::FanEdgeType *v27; // [esp+18h] [ebp-4h]
  unsigned int v28; // [esp+20h] [ebp+4h]
  unsigned int v29; // [esp+20h] [ebp+4h]

  v24 = -1.0e30;
  v2 = this;
  v25 = -1.0e30;
  v3 = &this->FanEdges.Pages[startEdgeIdx >> 4][startEdgeIdx & 0xF];
  v27 = v3;
  this->ContourNodes.Size = 0;
  do
  {
    if ( (v3->node1 & 0x80000000) != 0 )
      break;
    v22 = v3->node1 & 0x7FFFFFFF;
    p_x = &v2->OutVertices.Pages[v22 >> 4][v3->node1 & 0xF].x;
    if ( v24 != *p_x || v25 != p_x[1] )
    {
      v5 = v2->ContourNodes.Size >> 4;
      v28 = v5;
      if ( v5 >= v2->ContourNodes.NumPages )
      {
        Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(&v2->ContourNodes, v5);
        v5 = v28;
      }
      v2->ContourNodes.Pages[v5][v2->ContourNodes.Size++ & 0xF] = v22;
      v24 = *p_x;
      v25 = p_x[1];
    }
    v3->node1 |= 0x80000000;
    v6 = Scaleform::Alg::LowerBoundSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>,unsigned int,bool (__cdecl *)(Scaleform::Render::Hairliner::FanEdgeType const &,unsigned int)>(
           &v2->FanEdges,
           0,
           v2->FanEdges.Size,
           &v3->node2,
           (bool (__cdecl *)(const Scaleform::Render::Hairliner::FanEdgeType *, unsigned int))Scaleform::Render::Hairliner::cmpNode1);
    if ( v6 >= v2->FanEdges.Size )
      break;
    Pages = v2->FanEdges.Pages;
    v29 = 0;
    v8 = v6;
    do
    {
      if ( (Pages[v8 >> 4][v8 & 0xF].node1 & 0x7FFFFFFF) != v3->node2 )
        break;
      ++v29;
      ++v8;
    }
    while ( v8 < v2->FanEdges.Size );
    if ( v29 == 1 )
    {
      v3 = &Pages[v6 >> 4][v6 & 0xF];
    }
    else if ( v29 == 2 )
    {
      v9 = (int *)&Pages[v6 >> 4][v6 & 0xF];
      v3 = &Pages[(v6 + 1) >> 4][(v6 + 1) & 0xF];
      v10 = v9[1];
      if ( v10 == v3->node2 )
      {
        if ( *v9 >= 0 )
          v3 = (Scaleform::Render::Hairliner::FanEdgeType *)v9;
      }
      else if ( v10 != v22 )
      {
        v3 = (Scaleform::Render::Hairliner::FanEdgeType *)v9;
      }
    }
    else
    {
      v11 = 0;
      if ( v29 )
      {
        v12 = v6;
        v26 = v6;
        while ( Pages[v12 >> 4][v12 & 0xF].node2 != v22 )
        {
          ++v11;
          v12 = ++v26;
          if ( v11 >= v29 )
          {
LABEL_31:
            v2 = this;
            goto LABEL_32;
          }
        }
        v13 = 0;
        while ( 1 )
        {
          if ( ++v11 >= v29 )
            v11 = 0;
          v3 = &Pages[(v11 + v6) >> 4][(v11 + v6) & 0xF];
          if ( v3 == v27 )
            break;
          if ( (v3->node1 & 0x80000000) != 0 && ++v13 < v29 )
            continue;
          goto LABEL_31;
        }
        v2 = this;
        break;
      }
    }
LABEL_32:
    ;
  }
  while ( v3 != v27 );
  if ( v2->ContourNodes.Size )
  {
    v14 = v2->OutVertices.Pages;
    v15 = v14[**v2->ContourNodes.Pages >> 4];
    x = v15[**v2->ContourNodes.Pages & 0xF].x;
    v17 = &v15[**v2->ContourNodes.Pages & 0xF];
    v18 = v14[v2->ContourNodes.Pages[(v2->ContourNodes.Size - 1) >> 4][(v2->ContourNodes.Size - 1) & 0xF] >> 4];
    v19 = v18[v2->ContourNodes.Pages[(v2->ContourNodes.Size - 1) >> 4][(v2->ContourNodes.Size - 1) & 0xF] & 0xF].x;
    v20 = &v18[v2->ContourNodes.Pages[(v2->ContourNodes.Size - 1) >> 4][(v2->ContourNodes.Size - 1) & 0xF] & 0xF];
    if ( v19 == x && v20->y == v17->y )
    {
      Size = v2->ContourNodes.Size;
      if ( Size )
        v2->ContourNodes.Size = Size - 1;
    }
  }
}
