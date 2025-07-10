void __thiscall Scaleform::Render::VertexPath::Scale(Scaleform::Render::VertexPath *this, float sx, float sy)
{
  unsigned int i; // esi
  unsigned int v4; // eax
  int v5; // edx

  for ( i = 0; i < this->Vertices.Size; this->Vertices.Pages[v4][v5].y = this->Vertices.Pages[v4][v5].y * sy )
  {
    v4 = i >> 4;
    v5 = i++ & 0xF;
    this->Vertices.Pages[v4][v5].x = this->Vertices.Pages[v4][v5].x * sx;
  }
}
