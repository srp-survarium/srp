void __thiscall Scaleform::Render::Hairliner::buildEdgeList(
        Scaleform::Render::Hairliner *this,
        unsigned int start,
        unsigned int numEdges,
        int step)
{
  unsigned int Size; // eax
  Scaleform::Render::Hairliner::SrcVertexType **Pages; // eax
  unsigned int v8; // ecx
  Scaleform::Render::Hairliner::SrcVertexType *v9; // eax
  unsigned int v10; // edi
  double x; // st7
  Scaleform::Render::Hairliner::SrcVertexType *v12; // eax
  unsigned int v13; // edi
  Scaleform::Render::Hairliner::SrcEdgeType *v14; // eax
  Scaleform::Render::Hairliner::SrcVertexType **v15; // ecx
  Scaleform::Render::Hairliner::SrcEdgeType *v16; // edi
  unsigned int v17; // esi
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType,4,8> *p_MonoChains; // ebp
  unsigned int v19; // esi
  int v20; // eax
  unsigned int i; // [esp+10h] [ebp-20h]
  unsigned int startEdgeIdx; // [esp+14h] [ebp-1Ch]
  unsigned int e; // [esp+18h] [ebp-18h]
  float e_4; // [esp+1Ch] [ebp-14h]
  float e_8; // [esp+20h] [ebp-10h]
  float e_8a; // [esp+20h] [ebp-10h]
  float e_12; // [esp+24h] [ebp-Ch]
  const Scaleform::Render::Hairliner::SrcVertexType *v1; // [esp+34h] [ebp+4h]

  Size = this->SrcEdges.Size;
  startEdgeIdx = Size;
  for ( i = 0; i < numEdges; ++i )
  {
    Pages = this->SrcVertices.Pages;
    v8 = start;
    start += step;
    v1 = &Pages[v8 >> 4][v8 & 0xF];
    v9 = Pages[start >> 4];
    v10 = start & 0xF;
    x = v9[v10].x;
    v12 = &v9[v10];
    v13 = this->SrcEdges.Size >> 4;
    e = v8;
    e_8 = (x - v1->x) / (v12->y - v1->y);
    if ( v13 >= this->SrcEdges.NumPages )
    {
      Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::StrokeSorter::VertexType,4,16> *)&this->SrcEdges,
        v13);
      v8 = e;
    }
    v14 = &this->SrcEdges.Pages[v13][this->SrcEdges.Size & 0xF];
    v14->lower = v8;
    v14->upper = start;
    v14->slope = e_8;
    v14->next = 0;
    ++this->SrcEdges.Size;
    if ( i )
      this->SrcEdges.Pages[(this->SrcEdges.Size - 2) >> 4][(this->SrcEdges.Size - 2) & 0xF].next = &this->SrcEdges.Pages[(this->SrcEdges.Size - 1) >> 4][(this->SrcEdges.Size - 1) & 0xF];
    Size = startEdgeIdx;
  }
  v15 = this->SrcVertices.Pages;
  v16 = &this->SrcEdges.Pages[Size >> 4][Size & 0xF];
  v17 = this->MonoChains.Size;
  e_4 = v15[v16->lower >> 4][v16->lower & 0xF].y;
  p_MonoChains = &this->MonoChains;
  e_8a = v15[v16->lower >> 4][v16->lower & 0xF].x;
  v19 = v17 >> 4;
  e_12 = v16->slope;
  if ( v19 >= p_MonoChains->NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType,4,8>::allocPage(p_MonoChains, v19);
  v20 = (int)&p_MonoChains->Pages[v19][p_MonoChains->Size & 0xF];
  *(_DWORD *)v20 = v16;
  *(float *)(v20 + 4) = e_4;
  *(float *)(v20 + 8) = e_8a;
  *(float *)(v20 + 12) = e_12;
  *(_DWORD *)(v20 + 16) = 0;
  *(_DWORD *)(v20 + 20) = -1;
  ++p_MonoChains->Size;
}
