Scaleform::Render::MatrixPoolImpl::HMatrix *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::Matrix3x4<float> *m,
        unsigned __int8 formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
                      this,
                      m,
                      &Scaleform::Render::Cxform::Identity,
                      formatBits);
  return result;
}
