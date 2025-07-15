void __thiscall Scaleform::Render::Hairliner::emitEdge(
        Scaleform::Render::Hairliner *this,
        unsigned int v1,
        unsigned int v2)
{
  Scaleform::Render::Hairliner::OutVertexType **Pages; // ecx
  float *p_x; // eax
  double v6; // st7
  unsigned int Size; // edi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *p_FanEdges; // esi
  unsigned int v9; // edi
  float v10; // edx
  int v11; // eax
  unsigned int v12; // edi
  int v13; // eax
  float v14; // [esp+28h] [ebp-4h]
  float v15; // [esp+28h] [ebp-4h]

  Pages = this->OutVertices.Pages;
  p_x = &Pages[v1 >> 4][v1 & 0xF].x;
  v6 = Scaleform::Render::Math2D::SlopeRatio(*p_x, p_x[1], Pages[v2 >> 4][v2 & 0xF].x, Pages[v2 >> 4][v2 & 0xF].y);
  Size = this->FanEdges.Size;
  p_FanEdges = (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->FanEdges;
  v9 = Size >> 4;
  if ( v9 >= p_FanEdges->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(p_FanEdges, v9);
  v10 = v6;
  v14 = v6;
  v15 = v14 - 1.0;
  v11 = (int)&p_FanEdges->Pages[v9][p_FanEdges->Size & 0xF];
  *(_DWORD *)v11 = v1;
  *(_DWORD *)(v11 + 4) = v2;
  *(float *)(v11 + 8) = v10;
  ++p_FanEdges->Size;
  if ( v15 < -1.0 )
    v15 = v15 + 2.0;
  v12 = p_FanEdges->Size >> 4;
  if ( v12 >= p_FanEdges->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
      p_FanEdges,
      p_FanEdges->Size >> 4);
  v13 = (int)&p_FanEdges->Pages[v12][p_FanEdges->Size & 0xF];
  *(_DWORD *)v13 = v2;
  *(_DWORD *)(v13 + 4) = v1;
  *(float *)(v13 + 8) = v15;
  ++p_FanEdges->Size;
}
