void __thiscall Scaleform::Render::Hairliner::Tessellate(Scaleform::Render::Hairliner *this)
{
  unsigned int v2; // ecx
  unsigned int i; // ebx
  Scaleform::Render::Hairliner::FanEdgeType **Pages; // edi
  Scaleform::Render::Hairliner::FanEdgeType *v5; // edx
  Scaleform::Render::Hairliner::FanEdgeType *v6; // eax
  Scaleform::Render::Hairliner::FanEdgeType *v7; // edx
  unsigned int j; // edi
  float width; // [esp+0h] [ebp-10h]

  this->MinX = 1.0e30;
  this->Triangles.Size = 0;
  this->MinY = 1.0e30;
  this->MaxX = -1.0e30;
  this->MaxY = -1.0e30;
  Scaleform::Render::Hairliner::buildGraph(this);
  if ( this->FanEdges.Size >= 2 )
  {
    Scaleform::Alg::QuickSortSliced<Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>,bool (__cdecl *)(Scaleform::Render::Hairliner::FanEdgeType const &,Scaleform::Render::Hairliner::FanEdgeType const &)>(
      &this->FanEdges,
      0,
      this->FanEdges.Size,
      (bool (__cdecl *)(const Scaleform::Render::Hairliner::FanEdgeType *, const Scaleform::Render::Hairliner::FanEdgeType *))Scaleform::Render::Hairliner::cmpEdges);
    v2 = 1;
    for ( i = 1; v2 < this->FanEdges.Size; ++v2 )
    {
      Pages = this->FanEdges.Pages;
      v5 = &Pages[(v2 - 1) >> 4][((_BYTE)v2 - 1) & 0xF];
      v6 = &Pages[v2 >> 4][v2 & 0xF];
      if ( v5->node1 != v6->node1 || v5->node2 != v6->node2 )
      {
        v7 = &Pages[i >> 4][i & 0xF];
        v7->node1 = v6->node1;
        v7->node2 = v6->node2;
        v7->slope = v6->slope;
        ++i;
      }
    }
    if ( i < this->FanEdges.Size )
      this->FanEdges.Size = i;
    for ( j = 0; j < this->FanEdges.Size; ++j )
    {
      if ( (this->FanEdges.Pages[j >> 4][j & 0xF].node1 & 0x80000000) == 0 )
      {
        Scaleform::Render::Hairliner::generateContourAA(this, j);
        width = -this->Width;
        Scaleform::Render::Hairliner::generateTriangles(this, width);
      }
    }
  }
}
