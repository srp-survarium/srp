const Scaleform::Render::Matrix2x4<float> *__thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::GetTextureMatrix(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        unsigned int index)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // eax

  pHeader = this->pHandle->pHeader;
  if ( ((unsigned __int8)(1 << (index + 1)) & pHeader->Format) != 0 )
    return (const Scaleform::Render::Matrix2x4<float> *)Scaleform::Render::MatrixPoolImpl::DataHeader::GetData(
                                                          pHeader,
                                                          (Scaleform::Render::MatrixPoolImpl::HMatrixConstants::ElementIndex)(index + 1));
  else
    return &Scaleform::Render::Matrix2x4<float>::Identity;
}
