void __thiscall Scaleform::Render::StrokerAA::addTriangle(
        Scaleform::Render::StrokerAA *this,
        unsigned int v1,
        unsigned int v2,
        unsigned int v3)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::StrokerAA::TriangleType,4,16> *p_Triangles; // esi
  unsigned int v5; // edi
  Scaleform::Render::StrokerAA::TriangleType *v6; // eax

  p_Triangles = &this->Triangles;
  v5 = this->Triangles.Size >> 4;
  if ( v5 >= this->Triangles.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Triangles,
      this->Triangles.Size >> 4);
  v6 = &p_Triangles->Pages[v5][p_Triangles->Size & 0xF];
  v6->v1 = v1;
  v6->v2 = v2;
  v6->v3 = v3;
  ++p_Triangles->Size;
}
