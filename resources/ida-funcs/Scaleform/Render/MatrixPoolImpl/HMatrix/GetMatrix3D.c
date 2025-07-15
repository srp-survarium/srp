const Scaleform::Render::Matrix3x4<float> *__thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::GetMatrix3D(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx

  pHeader = this->pHandle->pHeader;
  if ( (pHeader->Format & 0x10) != 0 )
    return (const Scaleform::Render::Matrix3x4<float> *)(&pHeader[1].RefCount
                                                       + 4 * (unsigned __int8)byte_874214[5 * (pHeader->Format & 0xF)]);
  else
    return &Scaleform::Render::Matrix3x4<float>::Identity;
}
