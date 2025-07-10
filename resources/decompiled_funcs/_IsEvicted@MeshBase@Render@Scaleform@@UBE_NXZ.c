BOOL __thiscall Scaleform::Render::MeshBase::IsEvicted(Scaleform::Render::MeshBase *this)
{
  return this->StagingBufferSize == 0;
}
