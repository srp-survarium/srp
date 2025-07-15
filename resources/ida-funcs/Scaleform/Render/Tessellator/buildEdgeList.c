void __thiscall Scaleform::Render::Tessellator::buildEdgeList(
        Scaleform::Render::Tessellator *this,
        unsigned int start,
        unsigned int numEdges,
        int step,
        __int16 leftStyle,
        __int16 rightStyle)
{
  unsigned int Size; // edx
  Scaleform::Render::Tessellator::SrcVertexType **Pages; // ecx
  unsigned int v9; // ebx
  float *p_x; // edx
  Scaleform::Render::Tessellator::SrcVertexType *v11; // ecx
  unsigned int v12; // edi
  Scaleform::Render::Tessellator::EdgeType *v13; // edi
  unsigned int v14; // eax
  Scaleform::Render::Tessellator::EdgeType *v15; // ecx
  Scaleform::Render::Tessellator::SrcVertexType *v16; // esi
  int v17; // eax
  double y; // st7
  float *v19; // eax
  unsigned int v20; // esi
  double v21; // st7
  unsigned int v22; // edx
  Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16> *p_MonoChains; // ebp
  unsigned int v24; // esi
  unsigned int v25; // [esp+Ch] [ebp-38h]
  float v26; // [esp+14h] [ebp-30h]
  _DWORD v27[11]; // [esp+18h] [ebp-2Ch] BYREF

  Size = this->Edges.Size;
  v25 = Size;
  if ( numEdges )
  {
    do
    {
      Pages = this->SrcVertices.Pages;
      v9 = start;
      p_x = &Pages[start >> 4][start & 0xF].x;
      v11 = Pages[(step + start) >> 4];
      start += step;
      v12 = this->Edges.Size >> 4;
      v26 = (v11[start & 0xF].x - *p_x) / (v11[start & 0xF].y - p_x[1]);
      if ( v12 >= this->Edges.NumPages )
        Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
          (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->Edges,
          v12);
      v13 = this->Edges.Pages[v12];
      v14 = this->Edges.Size & 0xF;
      v13[v14].lower = v9;
      v13[v14].slope = v26;
      ++this->Edges.Size;
      --numEdges;
    }
    while ( numEdges );
    Size = v25;
  }
  v15 = &this->Edges.Pages[Size >> 4][Size & 0xF];
  v16 = this->SrcVertices.Pages[v15->lower >> 4];
  v17 = v15->lower & 0xF;
  y = v16[v17].y;
  v19 = &v16[v17].x;
  v20 = this->MonoChains.Size;
  *(float *)&v27[2] = y;
  v21 = *v19;
  v27[0] = Size;
  *(float *)&v27[3] = v21;
  v22 = this->Edges.Size;
  *(float *)&v27[4] = v15->slope;
  p_MonoChains = &this->MonoChains;
  v27[1] = v22 - 1;
  v27[5] = (unsigned __int16)step;
  LOWORD(v27[6]) = leftStyle;
  HIWORD(v27[6]) = rightStyle;
  v24 = v20 >> 4;
  v27[7] = 0;
  v27[8] = 0;
  v27[10] = 0;
  v27[9] = -1;
  if ( v24 >= p_MonoChains->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoChainType,4,16>::allocPage(p_MonoChains, v24);
  qmemcpy(
    &p_MonoChains->Pages[v24][p_MonoChains->Size++ & 0xF],
    v27,
    sizeof(p_MonoChains->Pages[v24][p_MonoChains->Size++ & 0xF]));
}
