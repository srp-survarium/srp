void __thiscall Scaleform::Render::Hairliner::processInterior(Scaleform::Render::Hairliner *this, float yb)
{
  unsigned int v3; // ecx
  Scaleform::Render::Hairliner::IntersectionType *v4; // esi
  unsigned int v5; // eax
  const Scaleform::Render::Hairliner::MonoChainType *mc1; // ebp
  unsigned int v7; // ebx
  unsigned int prevVertex; // eax
  unsigned int v9; // eax
  Scaleform::Render::Hairliner::MonoChainType *mc2; // esi
  unsigned int v11; // ebx
  unsigned int v12; // eax
  unsigned int i; // [esp+18h] [ebp-4h]

  Scaleform::Render::Hairliner::sweepScanbeam(this, &this->ChainsAtBottom, yb);
  v3 = 0;
  for ( i = 0; v3 < this->Intersections.Size; i = v3 )
  {
    v4 = &this->Intersections.Pages[v3 >> 4][v3 & 0xF];
    if ( yb < (double)v4->y )
    {
      v5 = Scaleform::Render::Hairliner::addEventVertex(this, v4->mc1, v4->y, 1);
      mc1 = v4->mc1;
      v7 = v5;
      prevVertex = v4->mc1->prevVertex;
      if ( prevVertex != -1 && prevVertex != v7 )
        Scaleform::Render::Hairliner::emitEdge(this, prevVertex, v7);
      mc1->prevVertex = v7;
      v9 = Scaleform::Render::Hairliner::addEventVertex(this, v4->mc2, v4->y, 1);
      mc2 = v4->mc2;
      v11 = v9;
      v12 = mc2->prevVertex;
      if ( v12 != -1 && v12 != v11 )
        Scaleform::Render::Hairliner::emitEdge(this, v12, v11);
      v3 = i;
      mc2->prevVertex = v11;
    }
    ++v3;
  }
}
