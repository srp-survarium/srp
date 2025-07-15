void __thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        const Scaleform::Render::Matrix2x4<float> *m,
        unsigned int index)
{
  int v3; // edx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // edi
  int v6; // ebx
  int v7; // [esp+18h] [ebp+8h]

  v3 = index + 1;
  pHandle = this->pHandle;
  v6 = 1 << (index + 1);
  v7 = index + 1;
  if ( ((unsigned __int8)v6 & this->pHandle->pHeader->Format) == 0 )
  {
    if ( Scaleform::Render::operator==(m, &Scaleform::Render::Matrix2x4<float>::Identity) )
      return;
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_DWORD *)(((unsigned int)pHandle & 0xFFFFF800) + 0x10) + 4),
      pHandle,
      v6 | pHandle->pHeader->Format);
    v3 = v7;
  }
  *(Scaleform::Render::Matrix2x4<float> *)(&this->pHandle->pHeader[1].RefCount
                                         + 4
                                         * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[0].Offsets[4 * (this->pHandle->pHeader->Format & 0xF) + (this->pHandle->pHeader->Format & 0xF) + v3]) = *m;
}
