BOOL __thiscall Scaleform::Render::ComplexMesh::IsEvicted(Scaleform::Render::ComplexMesh *this)
{
  return !this->pCacheMeshItem && !this->StagingBufferSize;
}
