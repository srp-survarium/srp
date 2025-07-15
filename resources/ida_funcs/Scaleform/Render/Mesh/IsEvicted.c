BOOL __thiscall Scaleform::Render::Mesh::IsEvicted(Scaleform::Render::Mesh *this)
{
  return !this->CacheItems.Size && !this->StagingBufferSize;
}
