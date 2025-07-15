Scaleform::Render::MatrixPoolImpl::HMatrix *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        const Scaleform::Render::Matrix2x4<float> *m,
        const Scaleform::Render::Cxform *cx,
        unsigned __int8 formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(this, m, cx, formatBits);
  return result;
}


Scaleform::Render::MatrixPoolImpl::HMatrix *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        const Scaleform::Render::Matrix2x4<float> *m,
        unsigned __int8 formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
                      this,
                      m,
                      &Scaleform::Render::Cxform::Identity,
                      formatBits);
  return result;
}


Scaleform::Render::MatrixPoolImpl::HMatrix *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::Matrix3x4<float> *m,
        const Scaleform::Render::Cxform *cx,
        unsigned __int8 formatBits)
{
  result->pHandle = Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(this, m, cx, formatBits);
  return result;
}


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
