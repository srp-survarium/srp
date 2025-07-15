void __thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // esi
  unsigned __int8 Format; // bl

  pHandle = this->pHandle;
  Format = this->pHandle->pHeader->Format;
  if ( (Format & 0x10) == 0 )
  {
    if ( Scaleform::Render::operator==(m, &Scaleform::Render::Matrix3x4<float>::Identity) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_DWORD *)(((unsigned int)pHandle & 0xFFFFF800) + 0x10) + 4),
      pHandle,
      Format | 0x10);
  }
  memcpy(
    (int)(&this->pHandle->pHeader[1].RefCount
        + 4 * (unsigned __int8)byte_874214[5 * (this->pHandle->pHeader->Format & 0xF)]),
    (const __m128i *)m,
    0x30u);
}
