unsigned int __thiscall Scaleform::Render::Tessellator::GetMeshVertexCount(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx)
{
  return this->Meshes.Pages[meshIdx >> 4][meshIdx & 0xF].VertexCount;
}
