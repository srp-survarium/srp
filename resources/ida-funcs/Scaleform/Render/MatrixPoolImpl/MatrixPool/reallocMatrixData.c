char __thiscall Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
        Scaleform::Render::MatrixPoolImpl::MatrixPool *this,
        Scaleform::Render::MatrixPoolImpl::EntryHandle *handle,
        unsigned __int8 formatBits)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *v3; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v4; // esi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ebx
  unsigned __int8 Format; // dl
  int v8; // eax
  Scaleform::Render::Matrix3x4<float> *v9; // edx
  unsigned __int8 v10; // al
  float *v11; // eax
  float *v12; // ecx
  Scaleform::Render::Cxform *v13; // eax
  float *v14; // ecx
  float *v15; // eax
  float *v16; // ecx
  float *v17; // eax
  unsigned int *v18; // eax
  int DataPageOffset; // edx
  unsigned __int16 v20; // ax
  unsigned __int8 v21; // [esp+17h] [ebp-39h]
  Scaleform::Render::MatrixPoolImpl::DataHeader *v22; // [esp+18h] [ebp-38h]
  Scaleform::Render::Matrix3x4<float> v24; // [esp+20h] [ebp-30h] BYREF

  v3 = Scaleform::Render::MatrixPoolImpl::MatrixPool::allocData(
         this,
         16 * ((unsigned __int8)byte_874214[5 * (formatBits & 0xF)] + ((formatBits & 0x10 | 0x20u) >> 4)),
         handle);
  v4 = v3;
  v22 = v3;
  if ( !v3 )
    return 0;
  pHeader = handle->pHeader;
  v3->Format = formatBits;
  v3->RefCount = pHeader->RefCount;
  Format = pHeader->Format;
  v8 = Format & 0xF;
  v21 = Format;
  if ( (formatBits & 0x10) != 0 )
  {
    if ( (Format & 0x10) != 0 )
    {
      v9 = (Scaleform::Render::Matrix3x4<float> *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_874214[5 * v8]);
      v10 = formatBits;
    }
    else
    {
      Scaleform::Render::Matrix3x4<float>::Matrix3x4<float>(
        &v24,
        (const Scaleform::Render::Matrix2x4<float> *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_874214[5 * v8]));
      v10 = formatBits;
      v9 = &v24;
    }
    memcpy((int)(&v4[1].RefCount + 4 * (unsigned __int8)byte_874214[5 * (v10 & 0xF)]), (const __m128i *)v9, 0x30u);
    Format = v21;
  }
  else
  {
    v11 = (float *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_874214[5 * v8]);
    v12 = (float *)(&v4[1].RefCount + 4 * (unsigned __int8)byte_874214[5 * (formatBits & 0xF)]);
    *v12 = *v11;
    v12[1] = v11[1];
    v12[2] = v11[2];
    v12[3] = v11[3];
    v12[4] = v11[4];
    v12[5] = v11[5];
    v12[6] = v11[6];
    v12[7] = v11[7];
  }
  if ( (formatBits & 1) != 0 )
  {
    if ( (Format & 1) != 0 )
      v13 = (Scaleform::Render::Cxform *)(&pHeader[1].RefCount
                                        + 4
                                        * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[0]);
    else
      v13 = &Scaleform::Render::Cxform::Identity;
    qmemcpy(
      &v4[1].RefCount
    + 4 * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v4->Format & 0xF].Offsets[0],
      v13,
      0x20u);
    v4 = v22;
  }
  if ( (formatBits & 2) != 0 )
  {
    if ( (Format & 2) != 0 )
      v14 = (float *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_874211[5 * (pHeader->Format & 0xF)]);
    else
      v14 = (float *)&Scaleform::Render::Matrix2x4<float>::Identity;
    v15 = (float *)(&v4[1].RefCount + 4 * (unsigned __int8)byte_874211[5 * (v4->Format & 0xF)]);
    *v15 = *v14;
    v15[1] = v14[1];
    v15[2] = v14[2];
    v15[3] = v14[3];
    v15[4] = v14[4];
    v15[5] = v14[5];
    v15[6] = v14[6];
    v15[7] = v14[7];
  }
  if ( (formatBits & 4) != 0 )
  {
    if ( (Format & 4) != 0 )
      v16 = (float *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_874212[5 * (pHeader->Format & 0xF)]);
    else
      v16 = (float *)&Scaleform::Render::Matrix2x4<float>::Identity;
    v17 = (float *)(&v4[1].RefCount + 4 * (unsigned __int8)byte_874212[5 * (v4->Format & 0xF)]);
    *v17 = *v16;
    v17[1] = v16[1];
    v17[2] = v16[2];
    v17[3] = v16[3];
    v17[4] = v16[4];
    v17[5] = v16[5];
    v17[6] = v16[6];
    v17[7] = v16[7];
  }
  if ( (formatBits & 8) != 0 )
  {
    v18 = &v4[1].RefCount + 4 * (unsigned __int8)byte_874213[5 * (v4->Format & 0xF)];
    if ( (Format & 8) != 0 )
    {
      qmemcpy(v18, &pHeader[1].RefCount + 4 * (unsigned __int8)byte_874213[5 * (pHeader->Format & 0xF)], 0x40u);
      v4 = v22;
    }
    else
    {
      memset((int)v18, 0, 64);
    }
  }
  if ( pHeader->pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    DataPageOffset = pHeader->DataPageOffset;
    v20 = 16 * pHeader->UnitSize;
    pHeader->pHandle = 0;
    pHeader->RefCount = 0;
    *(_WORD *)((char *)&pHeader[1].pHandle + DataPageOffset + 2) += v20;
    this->FreedSpace += v20;
  }
  handle->pHeader = v4;
  return 1;
}
