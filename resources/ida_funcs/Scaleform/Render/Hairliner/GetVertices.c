unsigned int __thiscall Scaleform::Render::Hairliner::GetVertices(
        Scaleform::Render::Hairliner *this,
        Scaleform::Render::TessMesh *mesh,
        Scaleform::Render::TessVertex *vertices,
        unsigned int num)
{
  unsigned int result; // eax
  unsigned int StartVertex; // esi
  Scaleform::Render::Hairliner::OutVertexType *v7; // esi
  double y; // st7

  for ( result = 0; result < num; ++vertices )
  {
    StartVertex = mesh->StartVertex;
    if ( StartVertex >= this->OutVertices.Size )
      break;
    v7 = &this->OutVertices.Pages[StartVertex >> 4][mesh->StartVertex & 0xF];
    vertices->x = v7->x;
    y = v7->y;
    vertices->Styles[0] = 1;
    vertices->y = y;
    vertices->Idx = 0;
    vertices->Styles[1] = 0;
    vertices->Flags = v7->alpha != 0 ? 2 : 0;
    ++mesh->StartVertex;
    ++result;
  }
  return result;
}
