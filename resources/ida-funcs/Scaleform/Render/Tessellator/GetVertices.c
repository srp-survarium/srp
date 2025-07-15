unsigned int __thiscall Scaleform::Render::Tessellator::GetVertices(
        Scaleform::Render::Tessellator *this,
        Scaleform::Render::TessMesh *mesh,
        Scaleform::Render::TessVertex *vertices,
        unsigned int num)
{
  unsigned int result; // eax
  Scaleform::Render::TessVertex **Pages; // ebx
  unsigned int v7; // edx
  Scaleform::Render::Tessellator *v8; // [esp+0h] [ebp-4h]

  result = 0;
  v8 = this;
  if ( num )
  {
    while ( mesh->StartVertex < this->MeshVertices.Size )
    {
      Pages = this->MeshVertices.Pages;
      if ( Pages[mesh->StartVertex >> 4][mesh->StartVertex & 0xF].Mesh == mesh->MeshIdx )
      {
        v7 = (unsigned int)&Pages[mesh->StartVertex >> 4][mesh->StartVertex & 0xF];
        vertices->x = *(float *)v7;
        vertices->y = *(float *)(v7 + 4);
        vertices->Idx = *(_DWORD *)(v7 + 8);
        *(_DWORD *)vertices->Styles = *(_DWORD *)(v7 + 12);
        *(_DWORD *)&vertices->Flags = *(_DWORD *)(v7 + 16);
        ++result;
        ++vertices;
      }
      ++mesh->StartVertex;
      if ( result >= num )
        break;
      this = v8;
    }
  }
  return result;
}
