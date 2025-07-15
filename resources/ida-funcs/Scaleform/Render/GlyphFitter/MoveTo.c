void __thiscall Scaleform::Render::GlyphFitter::MoveTo(Scaleform::Render::GlyphFitter *this, float x, float y)
{
  unsigned int v4; // edi
  Scaleform::Render::GlyphFitter::ContourType *v5; // edi
  unsigned int v6; // eax
  unsigned int v7; // edi
  Scaleform::Render::GlyphFitter::VertexType v8; // [esp+0h] [ebp-Ch]
  unsigned int Size; // [esp+4h] [ebp-8h]

  Size = this->Vertices.Size;
  v4 = this->Contours.Size >> 2;
  if ( v4 >= this->Contours.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4>::allocPage(
      (Scaleform::Render::ArrayPaged<Scaleform::Render::PathBasic,2,4> *)&this->Contours,
      v4);
  v5 = this->Contours.Pages[v4];
  v6 = this->Contours.Size & 3;
  v5[v6].StartVertex = Size;
  v5[v6].NumVertices = 1;
  ++this->Contours.Size;
  v7 = this->Vertices.Size >> 4;
  if ( v7 >= this->Vertices.NumPages )
    Scaleform::Render::ArrayPaged<Scaleform::Render::GlyphFitter::VertexType,4,16>::allocPage(
      (Scaleform::Render::ArrayPaged<unsigned int,4,16> *)&this->Vertices,
      this->Vertices.Size >> 4);
  v8.y = (int)y;
  v8.x = (int)x;
  this->Vertices.Pages[v7][this->Vertices.Size++ & 0xF] = v8;
  this->StartX = x;
  this->StartY = y;
  this->LastYf = y;
  this->LastXf = x;
}
