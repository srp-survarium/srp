void __thiscall Scaleform::Render::Tessellator::GetMesh(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx,
        Scaleform::Render::TessMesh *mesh)
{
  qmemcpy(mesh, &this->Meshes.Pages[meshIdx >> 4][meshIdx & 0xF], sizeof(Scaleform::Render::TessMesh));
  mesh->StartVertex = 0;
}
