unsigned int __thiscall Scaleform::Render::StrokerAA::GetVertices(
        Scaleform::Render::StrokerAA *this,
        Scaleform::Render::TessMesh *mesh,
        Scaleform::Render::TessVertex *vertices,
        unsigned int num)
{
  unsigned int result; // eax
  unsigned int StartVertex; // esi
  Scaleform::Render::StrokerAA::VertexType *v7; // esi
  double y; // st7

  for ( result = 0; result < num; ++vertices )
  {
    StartVertex = mesh->StartVertex;
    if ( StartVertex >= this->Vertices.Size )
      break;
    v7 = &this->Vertices.Pages[StartVertex >> 4][mesh->StartVertex & 0xF];
    vertices->x = v7->x;
    y = v7->y;
    vertices->Idx = 0;
    vertices->y = y;
    vertices->Styles[0] = v7->style;
    vertices->Styles[1] = 0;
    vertices->Flags = v7->alpha != 0 ? 2 : 0;
    ++mesh->StartVertex;
    ++result;
  }
  return result;
}
