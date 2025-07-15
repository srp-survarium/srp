void __thiscall Scaleform::Render::StrokerAA::GetMesh(
        Scaleform::Render::StrokerAA *this,
        unsigned int __formal,
        Scaleform::Render::TessMesh *mesh)
{
  mesh->MeshIdx = 0;
  mesh->Style1 = 1;
  mesh->Style2 = 0;
  mesh->Flags1 = 0;
  mesh->Flags2 = 0;
  mesh->StartVertex = 0;
  mesh->VertexCount = this->Vertices.Size;
}
