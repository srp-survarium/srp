void __thiscall Scaleform::Render::GlyphFitter::LineTo(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16> *p_Vertices; // esi
  Scaleform::Render::GlyphFitter::VertexType *v5; // ebx
  unsigned int v6; // ebx
  Scaleform::Render::GlyphFitter::ContourType *v7; // ecx
  Scaleform::Render::GlyphFitter::VertexType v8; // [esp+0h] [ebp-4h]

  p_Vertices = &this->Vertices;
  v5 = &this->Vertices.Pages[(this->Vertices.Size - 1) >> 4][(this->Vertices.Size - 1) & 0xF];
  v8.x = (int)x;
  if ( v8.x != v5->x || (unsigned __int16)(int)y != v5->y )
  {
    v6 = this->Vertices.Size >> 4;
    if ( v6 >= this->Vertices.NumPages )
      Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
        (Scaleform::Render::ArrayPaged<unsigned int,4,16> *)&this->Vertices,
        this->Vertices.Size >> 4);
    v8.y = (int)y;
    p_Vertices->Pages[v6][p_Vertices->Size++ & 0xF] = v8;
    v7 = this->Contours.Pages[(this->Contours.Size - 1) >> 2];
    ++v7[(this->Contours.Size - 1) & 3].NumVertices;
  }
  this->LastXf = x;
  this->LastYf = y;
}
