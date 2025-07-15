void __thiscall Scaleform::Render::Tessellator::SplitMeshes(Scaleform::Render::Tessellator *this)
{
  unsigned int Size; // ebx
  unsigned int v3; // edi
  Scaleform::Render::TessMesh *v4; // eax
  unsigned int VertexCount; // ecx
  Scaleform::Render::TessMesh *v6; // eax
  unsigned int v7; // edx
  unsigned int i; // ecx
  int v9; // ebp
  Scaleform::Render::TessMesh *v10; // eax
  Scaleform::Render::TessVertex *v11; // ecx
  unsigned __int16 Mesh; // ax
  int v13; // ebp
  Scaleform::Render::TessMesh *v14; // eax
  char v15; // [esp+13h] [ebp-1h]

  while ( 1 )
  {
    Size = this->Meshes.Size;
    v3 = 0;
    v15 = 1;
    if ( !Size )
      break;
    do
    {
      v4 = this->Meshes.Pages[v3 >> 4];
      VertexCount = v4[v3 & 0xF].VertexCount;
      v6 = &v4[v3 & 0xF];
      if ( VertexCount > this->VertexLimit )
      {
        Scaleform::Render::Tessellator::splitMesh(this, v6);
        v15 = 0;
      }
      ++v3;
    }
    while ( v3 < Size );
    if ( v15 )
      break;
    v7 = 0;
    for ( i = 0; i < this->Meshes.Size; v10[v9].VertexCount = 0 )
    {
      v9 = i & 0xF;
      v10 = this->Meshes.Pages[i++ >> 4];
    }
    if ( this->MeshVertices.Size )
    {
      do
      {
        v11 = &this->MeshVertices.Pages[v7 >> 4][v7 & 0xF];
        Mesh = v11->Mesh;
        if ( Mesh != 0xFFFF )
        {
          v13 = Mesh & 0xF;
          v14 = this->Meshes.Pages[Mesh >> 4];
          v11->Idx = v14[v13].VertexCount++;
        }
        ++v7;
      }
      while ( v7 < this->MeshVertices.Size );
    }
  }
}
