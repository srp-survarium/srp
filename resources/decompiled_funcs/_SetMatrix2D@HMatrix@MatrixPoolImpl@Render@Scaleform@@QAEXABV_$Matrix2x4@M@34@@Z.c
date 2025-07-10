void __thiscall Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(
        Scaleform::Render::MatrixPoolImpl::HMatrix *this,
        const Scaleform::Render::Matrix2x4<float> *m)
{
  *(Scaleform::Render::Matrix2x4<float> *)(&this->pHandle->pHeader[1].RefCount
                                         + 4 * (unsigned __int8)byte_9B2B74[5 * (this->pHandle->pHeader->Format & 0xF)]) = *m;
}
