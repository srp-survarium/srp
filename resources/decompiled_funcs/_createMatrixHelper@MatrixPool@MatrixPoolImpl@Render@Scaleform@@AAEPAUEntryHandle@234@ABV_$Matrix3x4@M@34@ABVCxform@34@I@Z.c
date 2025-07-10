Scaleform::Render::MatrixPoolImpl::EntryHandle *__thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::createMatrixHelper(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::Matrix3x4<float> *m,
        const Scaleform::Render::Cxform *cx,
        unsigned __int8 formatBits)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v4; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *v5; // ebp
  float *v6; // eax
  float *v7; // eax

  v4 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocMatrixData(this, formatBits);
  v5 = v4;
  if ( !v4 )
    return &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle;
  memcpy(
    (unsigned __int8 *)&v4->pHeader[1].RefCount + 16 * (unsigned __int8)byte_9B2B74[5 * (v4->pHeader->Format & 0xF)],
    (unsigned __int8 *)m,
    0x30u);
  if ( (formatBits & 1) != 0 )
    qmemcpy(
      &v5->pHeader[1].RefCount
    + 4
    * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v5->pHeader->Format & 0xF].Offsets[0],
      cx,
      0x20u);
  if ( (formatBits & 2) != 0 )
  {
    v6 = (float *)(&v5->pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B71[5 * (v5->pHeader->Format & 0xF)]);
    *v6 = 1.0;
    v6[5] = 1.0;
    v6[1] = 0.0;
    v6[2] = 0.0;
    v6[3] = 0.0;
    v6[4] = 0.0;
    v6[6] = 0.0;
    v6[7] = 0.0;
  }
  if ( (formatBits & 4) != 0 )
  {
    v7 = (float *)(&v5->pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B72[5 * (v5->pHeader->Format & 0xF)]);
    *v7 = 1.0;
    v7[5] = 1.0;
    v7[1] = 0.0;
    v7[2] = 0.0;
    v7[3] = 0.0;
    v7[4] = 0.0;
    v7[6] = 0.0;
    v7[7] = 0.0;
  }
  if ( (formatBits & 8) != 0 )
    memset(
      (int)(&v5->pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B73[5 * (v5->pHeader->Format & 0xF)]),
      0,
      0x40u);
  return v5;
}
