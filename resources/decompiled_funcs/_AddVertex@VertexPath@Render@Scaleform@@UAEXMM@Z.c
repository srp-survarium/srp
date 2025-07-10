void __thiscall Scaleform::Render::VertexPath::AddVertex(Scaleform::Render::VertexPath *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16> *p_Vertices; // esi
  unsigned int v4; // edi
  Scaleform::Render::VertexBasic *v5; // edi
  int v6; // eax

  p_Vertices = &this->Vertices;
  v4 = this->Vertices.Size >> 4;
  if ( v4 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::VertexBasic,4,16>::allocPage(&this->Vertices, v4);
  v5 = p_Vertices->Pages[v4];
  v6 = p_Vertices->Size & 0xF;
  v5[v6].x = x;
  v5[v6].y = y;
  ++p_Vertices->Size;
}
