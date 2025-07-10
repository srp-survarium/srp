void __thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::Cxform *m)
{
  if ( (this->pHandle->pHeader->Format & 1) == 0 )
  {
    if ( Scaleform::Render::Cxform::operator==(m, &Scaleform::Render::Cxform::Identity) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_DWORD *)(((int)this->pHandle & 0xFFFFF800) + 0x10) + 4),
      this->pHandle,
      this->pHandle->pHeader->Format | 1);
  }
  qmemcpy(
    &this->pHandle->pHeader[1].RefCount
  + 4
  * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[this->pHandle->pHeader->Format & 0xF].Offsets[0],
    m,
    0x20u);
}
