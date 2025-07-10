unsigned int __thiscall Scaleform::Render::Hairliner::addEventVertex(
        Scaleform::Render::Hairliner *this,
        const Scaleform::Render::Hairliner::SrcVertexType *v1)
{
  unsigned int v3; // edi
  Scaleform::Render::Hairliner::OutVertexType *v4; // eax
  float v2; // [esp+4h] [ebp-Ch]
  float v2_4; // [esp+8h] [ebp-8h]

  if ( this->LastY != v1->y || this->LastX != v1->x )
  {
    *(Scaleform::Render::Hairliner::SrcVertexType *)&this->LastX = *v1;
    v2 = v1->x;
    v3 = this->OutVertices.Size >> 4;
    v2_4 = v1->y;
    if ( v3 >= this->OutVertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->OutVertices,
        v3);
    v4 = &this->OutVertices.Pages[v3][this->OutVertices.Size & 0xF];
    v4->x = v2;
    v4->y = v2_4;
    v4->alpha = 1;
    ++this->OutVertices.Size;
  }
  return this->OutVertices.Size - 1;
}
