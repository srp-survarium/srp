void __thiscall Scaleform::Render::Hairliner::AddVertex(Scaleform::Render::Hairliner *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::SrcVertexType,4,16> *p_SrcVertices; // esi
  unsigned int v4; // edi
  Scaleform::Render::Hairliner::SrcVertexType *v5; // edi
  int v6; // eax

  p_SrcVertices = &this->SrcVertices;
  v4 = this->SrcVertices.Size >> 4;
  if ( v4 >= this->SrcVertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *)&this->SrcVertices,
      v4);
  v5 = p_SrcVertices->Pages[v4];
  v6 = p_SrcVertices->Size & 0xF;
  v5[v6].x = x;
  v5[v6].y = y;
  ++p_SrcVertices->Size;
}
