unsigned int __thiscall Scaleform::Render::Tessellator::GetMeshTriangleCount(
        Scaleform::Render::Tessellator *this,
        unsigned int meshIdx)
{
  return this->MeshTriangles.Arrays[meshIdx].Size;
}
