Scaleform::Render::MatrixPoolImpl::HMatrix *__thiscall Scaleform::Render::TextMeshProvider::GetMaskClearBounds(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // ecx
  Scaleform::Render::MatrixPoolImpl::HMatrix *v3; // eax

  pHandle = this->ClearBounds.pHandle;
  v3 = result;
  result->pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  return v3;
}
