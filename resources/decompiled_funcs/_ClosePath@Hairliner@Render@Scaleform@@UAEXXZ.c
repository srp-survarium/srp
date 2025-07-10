void __thiscall Scaleform::Render::Hairliner::ClosePath(Scaleform::Render::Hairliner *this)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcVertexType,4,16> *p_SrcVertices; // esi
  unsigned int v2; // edi
  Scaleform::Render::Hairliner::SrcVertexType *v3; // ebx
  Scaleform::Render::Hairliner::SrcVertexType *v4; // edi
  int v5; // eax

  p_SrcVertices = &this->SrcVertices;
  v2 = this->SrcVertices.Size >> 4;
  v3 = &this->SrcVertices.Pages[this->LastVertex >> 4][this->LastVertex & 0xF];
  if ( v2 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices,
      this->SrcVertices.Size >> 4);
  v4 = p_SrcVertices->Pages[v2];
  v5 = p_SrcVertices->Size & 0xF;
  v4[v5].x = v3->x;
  v4[v5].y = v3->y;
  ++p_SrcVertices->Size;
}
