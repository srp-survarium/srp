void __thiscall Scaleform::Render::Hairliner::sweepScanbeam(
        Scaleform::Render::Hairliner *this,
        const Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::MonoChainType *,4,8> *aet,
        float yb)
{
  unsigned int i; // ebp
  Scaleform::Render::Hairliner::MonoChainType *v5; // edi
  const Scaleform::Render::Hairliner::SrcVertexType *v6; // eax
  const Scaleform::Render::Hairliner::SrcVertexType *v7; // ebx
  unsigned int prevVertex; // eax
  unsigned int j; // ebx
  Scaleform::Render::Hairliner::HorizontalEdgeType *v10; // edi
  unsigned int v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // [esp+4h] [ebp-34h]
  Scaleform::Render::Hairliner::SrcVertexType v; // [esp+18h] [ebp-20h] BYREF
  Scaleform::Render::Hairliner::SrcVertexType v16; // [esp+20h] [ebp-18h] BYREF
  Scaleform::Render::Hairliner::SrcVertexType v2; // [esp+28h] [ebp-10h] BYREF
  Scaleform::Render::Hairliner::SrcVertexType v1; // [esp+30h] [ebp-8h] BYREF

  for ( i = 0; i < aet->Size; ++i )
  {
    v5 = aet->Pages[i >> 4][i & 0xF];
    v6 = (const Scaleform::Render::Hairliner::SrcVertexType *)Scaleform::Render::Hairliner::addEventVertex(
                                                                this,
                                                                v5,
                                                                yb,
                                                                v5->flags & 1);
    v7 = v6;
    if ( this->NumHorizontals )
      v7 = Scaleform::Render::Hairliner::processHorizontalEdges(this, v5, v6, yb);
    if ( v7 != (const Scaleform::Render::Hairliner::SrcVertexType *)-1 )
    {
      prevVertex = v5->prevVertex;
      if ( prevVertex != -1 && (const Scaleform::Render::Hairliner::SrcVertexType *)prevVertex != v7 )
        Scaleform::Render::Hairliner::emitEdge(this, prevVertex, (unsigned int)v7);
      v5->prevVertex = (unsigned int)v7;
    }
  }
  for ( j = 0; j < this->NumHorizontals; ++j )
  {
    v10 = &this->HorizontalEdges.Pages[(j + this->StartHorizontals) >> 2][(j + this->StartHorizontals) & 3];
    if ( v10->lv != -1 && v10->x1 != this->OutVertices.Pages[v10->lv >> 4][v10->lv & 0xF].x )
    {
      v.x = v10->x1;
      v.y = yb;
      v11 = Scaleform::Render::Hairliner::addEventVertex(this, &v);
      Scaleform::Render::Hairliner::emitEdge(this, v10->lv, v11);
    }
    if ( v10->rv != -1 && v10->x2 != this->OutVertices.Pages[v10->rv >> 4][v10->rv & 0xF].x )
    {
      v16.x = v10->x2;
      v16.y = yb;
      v12 = Scaleform::Render::Hairliner::addEventVertex(this, &v16);
      Scaleform::Render::Hairliner::emitEdge(this, v10->rv, v12);
    }
    if ( v10->lv == -1 && v10->rv == -1 )
    {
      v1.x = v10->x1;
      v1.y = yb;
      v2.x = v10->x2;
      v2.y = yb;
      v14 = Scaleform::Render::Hairliner::addEventVertex(this, &v2);
      v13 = Scaleform::Render::Hairliner::addEventVertex(this, &v1);
      Scaleform::Render::Hairliner::emitEdge(this, v13, v14);
    }
  }
}
