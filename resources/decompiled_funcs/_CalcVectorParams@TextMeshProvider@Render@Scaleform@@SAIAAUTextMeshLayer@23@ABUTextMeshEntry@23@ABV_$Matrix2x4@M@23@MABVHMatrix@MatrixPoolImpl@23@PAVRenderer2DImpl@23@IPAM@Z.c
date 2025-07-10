int __cdecl Scaleform::Render::TextMeshProvider::CalcVectorParams(
        Scaleform::Render::TextMeshLayer *layer,
        const Scaleform::Render::TextMeshEntry *ent,
        const Scaleform::Render::Matrix2x4<float> *scalingMtx,
        float sizeScale,
        const Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::Renderer2DImpl *ren,
        char meshGenFlags,
        float *keyData)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // ecx
  unsigned __int8 *v9; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_M; // esi
  Scaleform::Render::MatrixPoolImpl::HMatrix *v11; // eax
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  float *v13; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix *v14; // eax
  Scaleform::Render::MatrixPoolImpl::DataHeader *v15; // ecx
  const Scaleform::Render::Cxform *v16; // eax
  int v17; // esi
  char v18; // bl
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [esp+238h] [ebp-A8h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix v21; // [esp+23Ch] [ebp-A4h] BYREF
  Scaleform::Render::Matrix2x4<float> m2; // [esp+240h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix2x4<float> v23; // [esp+260h] [ebp-80h] BYREF
  Scaleform::Render::Matrix3x4<float> dst; // [esp+280h] [ebp-60h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [esp+2B0h] [ebp-30h] BYREF

  pHeader = m->pHandle->pHeader;
  if ( (pHeader->Format & 0x10) != 0 )
  {
    m2.M[0][0] = sizeScale;
    m2.M[0][1] = 0.0;
    m2.M[0][2] = 0.0;
    m2.M[1][0] = 0.0;
    m2.M[1][2] = 0.0;
    m2.M[1][1] = sizeScale;
    m2.M[0][3] = ent->EntryData.RasterData.Coord[3] + 0.0;
    m2.M[1][3] = ent->EntryData.VectorData.y + 0.0;
    if ( (pHeader->Format & 0x10) != 0 )
      v9 = (unsigned __int8 *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B74[5 * (pHeader->Format & 0xF)]);
    else
      v9 = (unsigned __int8 *)&Scaleform::Render::Matrix3x4<float>::Identity;
    memcpy((unsigned __int8 *)&dst, v9, sizeof(dst));
    memcpy((unsigned __int8 *)&m1, (unsigned __int8 *)&dst, sizeof(m1));
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&dst, &m1, &m2);
    p_M = &layer->M;
    if ( layer->M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix3D(&layer->M, &dst);
      goto LABEL_13;
    }
    v11 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&ren->MPool, &result, &dst, 0x10u);
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v11);
    pHandle = result.pHandle;
  }
  else
  {
    v13 = (float *)(&pHeader[1].RefCount + 4 * (unsigned __int8)byte_9B2B74[5 * (pHeader->Format & 0xF)]);
    m2.M[0][0] = *v13;
    m2.M[0][1] = v13[1];
    m2.M[0][2] = v13[2];
    m2.M[0][3] = v13[3];
    m2.M[1][0] = v13[4];
    m2.M[1][1] = v13[5];
    m2.M[1][2] = v13[6];
    m2.M[1][3] = v13[7];
    v21.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)LODWORD(ent->EntryData.MaskData.Coord[3]);
    result.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)ent->EntryData.RasterData.pGlyph;
    m2.M[0][3] = m2.M[0][1] * *(float *)&result.pHandle + *(float *)&v21.pHandle * m2.M[0][0] + m2.M[0][3];
    m2.M[1][3] = *(float *)&v21.pHandle * m2.M[1][0] + *(float *)&result.pHandle * m2.M[1][1] + m2.M[1][3];
    v23.M[0][0] = sizeScale;
    v23.M[0][1] = 0.0;
    v23.M[0][2] = 0.0;
    v23.M[0][3] = 0.0;
    v23.M[1][0] = 0.0;
    v23.M[1][2] = 0.0;
    v23.M[1][3] = 0.0;
    v23.M[1][1] = sizeScale;
    Scaleform::Render::Matrix2x4<float>::Prepend(&m2, &v23);
    p_M = &layer->M;
    if ( layer->M.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    {
      Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&layer->M, &m2);
      goto LABEL_13;
    }
    v14 = Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&ren->MPool, &v21, &m2, 0);
    Scaleform::Render::MatrixPoolImpl::HMatrix::operator=(p_M, v14);
    pHandle = v21.pHandle;
  }
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(pHandle->pHeader);
LABEL_13:
  Scaleform::Render::Cxform::Cxform((Scaleform::Render::Cxform *)&v23, (Scaleform::Render::Color)ent->mColor);
  v15 = m->pHandle->pHeader;
  if ( (v15->Format & 1) != 0 )
    v16 = (const Scaleform::Render::Cxform *)(&v15[1].RefCount
                                            + 4
                                            * Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v15->Format & 0xF].Offsets[0]);
  else
    v16 = &Scaleform::Render::Cxform::Identity;
  Scaleform::Render::Cxform::Append((Scaleform::Render::Cxform *)&v23, v16);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(p_M, (Scaleform::Render::Cxform *)&v23);
  v17 = 1;
  if ( (meshGenFlags & 1) != 0 )
    v17 = 65;
  if ( (meshGenFlags & 2) != 0 )
    v17 |= 0x80u;
  v18 = Scaleform::Render::MeshKey::CalcMatrixKey(scalingMtx, keyData, 0);
  keyData[Scaleform::Render::MeshKey::GetKeySize(v17) - 1] = 0.0;
  if ( !v18 )
    return v17 | 0x8000;
  return v17;
}
