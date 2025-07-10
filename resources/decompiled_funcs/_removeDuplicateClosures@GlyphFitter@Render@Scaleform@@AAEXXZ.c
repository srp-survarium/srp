void __thiscall Scaleform::Render::GlyphFitter::removeDuplicateClosures(Scaleform::Render::GlyphFitter *this)
{
  unsigned int v1; // eax
  Scaleform::Render::GlyphFitter::ContourType *v2; // esi
  unsigned int NumVertices; // edi
  Scaleform::Render::GlyphFitter::VertexType **Pages; // edx
  Scaleform::Render::GlyphFitter::VertexType *v5; // ebx
  Scaleform::Render::GlyphFitter::VertexType *v6; // eax
  unsigned int i; // [esp+0h] [ebp-4h]

  v1 = 0;
  for ( i = 0; v1 < this->Contours.Size; i = v1 )
  {
    v2 = &this->Contours.Pages[v1 >> 2][v1 & 3];
    NumVertices = v2->NumVertices;
    if ( NumVertices > 2 )
    {
      Pages = this->Vertices.Pages;
      v5 = &Pages[v2->StartVertex >> 4][v2->StartVertex & 0xF];
      v6 = &Pages[(v2->StartVertex + NumVertices - 1) >> 4][(v2->StartVertex + NumVertices - 1) & 0xF];
      if ( v5->x == v6->x && v5->y == v6->y )
        v2->NumVertices = NumVertices - 1;
      v1 = i;
    }
    ++v1;
  }
}
