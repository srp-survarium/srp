unsigned int __thiscall Scaleform::Render::StrokerAA::addVertex(
        Scaleform::Render::StrokerAA *this,
        float x,
        float y,
        __int16 style,
        __int16 alpha)
{
  unsigned int v6; // edi
  Scaleform::Render::StrokerAA::VertexType *v7; // eax
  int v9; // [esp+8h] [ebp-4h]

  v6 = this->Vertices.Size >> 4;
  LOWORD(v9) = style;
  HIWORD(v9) = alpha;
  if ( v6 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::Hairliner::FanEdgeType,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::Tessellator::MonoVertexType,4,16> *)&this->Vertices,
      v6);
  v7 = &this->Vertices.Pages[v6][this->Vertices.Size & 0xF];
  v7->x = x;
  v7->y = y;
  *(_DWORD *)&v7->style = v9;
  return this->Vertices.Size++;
}
