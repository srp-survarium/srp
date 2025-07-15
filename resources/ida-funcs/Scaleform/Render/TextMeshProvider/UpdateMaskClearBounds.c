Scaleform::Render::MatrixPoolImpl::HMatrix *__thiscall Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
        Scaleform::Render::TextMeshProvider *this,
        Scaleform::Render::MatrixPoolImpl::HMatrix *result,
        Scaleform::Render::MatrixPoolImpl::HMatrix viewMat)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  int v5; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_ClearBounds; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v7; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix v10; // [esp+4h] [ebp-88h] BYREF
  float y1; // [esp+8h] [ebp-84h]
  Scaleform::Render::Matrix2x4<float> m2; // [esp+Ch] [ebp-80h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+2Ch] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+5Ch] [ebp-30h] BYREF

  m2.M[0][0] = 1.0;
  m2.M[0][1] = 0.0;
  m2.M[0][2] = 0.0;
  m2.M[0][3] = 0.0;
  m2.M[1][0] = 0.0;
  m2.M[1][2] = 0.0;
  m2.M[1][3] = 0.0;
  m2.M[1][1] = 1.0;
  y1 = this->ClearBox.y1;
  v10.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)LODWORD(this->ClearBox.x2);
  dst.M[0][0] = 0.0;
  dst.M[0][1] = 0.0;
  dst.M[0][3] = 0.0;
  dst.M[0][2] = 1.0;
  dst.M[1][0] = 1.0;
  dst.M[1][1] = 1.0;
  m1.M[0][0] = this->ClearBox.x1;
  m1.M[0][1] = y1;
  m1.M[0][2] = *(float *)&v10.pHandle;
  m1.M[1][0] = *(float *)&v10.pHandle;
  m1.M[0][3] = y1;
  m1.M[1][1] = this->ClearBox.y2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&m2, (float *)&dst, (float *)&m1);
  pHeader = viewMat.pHandle->pHeader;
  v5 = viewMat.pHandle->pHeader->Format & 0xF;
  if ( (viewMat.pHandle->pHeader->Format & 0x10) != 0 )
  {
    memcpy((int)&dst, (const __m128i *)&pHeader[1].RefCount + (unsigned __int8)byte_874214[5 * v5], sizeof(dst));
    memcpy((int)&m1, (const __m128i *)&dst, sizeof(m1));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&dst, &m1, &m2);
    p_ClearBounds = &this->ClearBounds;
    if ( this->ClearBounds.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(&this->ClearBounds, &dst);
      goto LABEL_10;
    }
    v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(
           &this->pRenderer->MPool,
           &v10,
           (const __m128i *)&dst,
           0x10u);
  }
  else
  {
    Scaleform::Render::Matrix2x4<float>::Append(
      &m2,
      (const Scaleform::Render::Matrix2x4<float> *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_874214[5 * v5]));
    p_ClearBounds = &this->ClearBounds;
    if ( this->ClearBounds.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->ClearBounds, &m2);
      goto LABEL_10;
    }
    v7 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&this->pRenderer->MPool, &v10, &m2, 0);
  }
  Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_ClearBounds, v7);
  if ( v10.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v10.pHandle->pHeader);
LABEL_10:
  pHandle = p_ClearBounds->pHandle;
  result->pHandle = pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  if ( viewMat.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(viewMat.pHandle->pHeader);
  return result;
}
