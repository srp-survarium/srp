BOOL __thiscall Scaleform::Render::FilterEffect::UpdateMatrix(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::Matrix2x4<float> *boundsMatrix,
        const Scaleform::Render::Matrix2x4<float> *newNodeMatrix,
        bool forceUncache)
{
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_BoundsMatrix; // edi
  Scaleform::Render::Matrix2x4<float> *v7; // esi
  const Scaleform::Render::Matrix2x4<float> *v8; // esi
  bool v9; // al
  Scaleform::Render::MatrixPoolImpl::DataHeader *v10; // ecx
  float *v11; // eax
  Scaleform::Render::MatrixPoolImpl::HMatrix v12; // edx
  float *v13; // eax
  char CanCacheAcrossTransform; // [esp+17Dh] [ebp-51h]
  float v16; // [esp+17Eh] [ebp-50h]
  float v17; // [esp+17Eh] [ebp-50h]
  float v18; // [esp+17Eh] [ebp-50h]
  float v19; // [esp+17Eh] [ebp-50h]
  float v20; // [esp+17Eh] [ebp-50h]
  float v21; // [esp+17Eh] [ebp-50h]
  float v22; // [esp+182h] [ebp-4Ch]
  float v23; // [esp+186h] [ebp-48h]
  float v24; // [esp+186h] [ebp-48h]
  float v25; // [esp+186h] [ebp-48h]
  float v26; // [esp+186h] [ebp-48h]
  float v27; // [esp+186h] [ebp-48h]
  float v28; // [esp+186h] [ebp-48h]
  float v29; // [esp+186h] [ebp-48h]
  float v30; // [esp+18Ah] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> m; // [esp+18Eh] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> m2; // [esp+1AEh] [ebp-20h] BYREF

  pHeader = this->BoundsMatrix.pHandle->pHeader;
  p_BoundsMatrix = &this->BoundsMatrix;
  CanCacheAcrossTransform = 0;
  if ( (pHeader->Format & 4) != 0 )
    v7 = (Scaleform::Render::Matrix2x4<float> *)(&pHeader[1].RefCount
                                               + 4 * (unsigned __int8)byte_9B2B72[5 * (pHeader->Format & 0xF)]);
  else
    v7 = &Scaleform::Render::Matrix2x4<float>::Identity;
  m2.M[0][0] = 0.0;
  m2.M[0][1] = 0.0;
  m2.M[0][2] = 0.0;
  m2.M[0][3] = 0.0;
  m2.M[1][0] = 0.0;
  m2.M[1][1] = 0.0;
  m2.M[1][2] = 0.0;
  m2.M[1][3] = 0.0;
  if ( forceUncache || (p_BoundsMatrix->pHandle->pHeader->Format & 4) == 0 || Scaleform::Render::operator==(v7, &m2) )
  {
    v8 = newNodeMatrix;
LABEL_32:
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(p_BoundsMatrix, v8, Element_T0);
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(p_BoundsMatrix, (unsigned __int8 *)boundsMatrix, 0x20u);
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(p_BoundsMatrix, boundsMatrix);
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(p_BoundsMatrix, boundsMatrix, Element_Cxform);
    return CanCacheAcrossTransform == 0;
  }
  v22 = newNodeMatrix->M[0][3];
  v16 = v7->M[0][3];
  LOBYTE(v22) = v16 > v22 + 0.00009999999747378752
             || v22 - 0.00009999999747378752 > v16
             || (v22 = newNodeMatrix->M[1][3], v17 = v7->M[1][3], v17 > v22 + 0.00009999999747378752)
             || v17 < v22 - 0.00009999999747378752;
  v18 = v7->M[1][0] * v7->M[1][0] + v7->M[0][0] * v7->M[0][0];
  v19 = sqrt(v18);
  v23 = v19;
  v20 = newNodeMatrix->M[1][0] * newNodeMatrix->M[1][0] + newNodeMatrix->M[0][0] * newNodeMatrix->M[0][0];
  v21 = sqrt(v20);
  LOBYTE(v21) = v23 > v21 + 0.00009999999747378752
             || v23 < v21 - 0.00009999999747378752
             || (v24 = v7->M[1][1] * v7->M[1][1] + v7->M[0][1] * v7->M[0][1],
                 v25 = sqrt(v24),
                 v21 = v25,
                 v26 = newNodeMatrix->M[1][1] * newNodeMatrix->M[1][1] + newNodeMatrix->M[0][1] * newNodeMatrix->M[0][1],
                 v27 = sqrt(v26),
                 v21 > v27 + 0.00009999999747378752)
             || v21 < v27 - 0.00009999999747378752;
  v28 = atan2(v7->M[1][0], v7->M[0][0]);
  v8 = newNodeMatrix;
  v30 = v28;
  v29 = atan2(newNodeMatrix->M[1][0], newNodeMatrix->M[0][0]);
  v9 = v30 <= v29 + 0.00009999999747378752 && v30 >= v29 - 0.00009999999747378752;
  CanCacheAcrossTransform = Scaleform::Render::FilterSet::CanCacheAcrossTransform(
                              (Scaleform::Render::FilterSet *)this->StartEntry.Key.Data,
                              SLODWORD(v22),
                              !v9,
                              SLODWORD(v21));
  if ( !CanCacheAcrossTransform )
    goto LABEL_32;
  v10 = p_BoundsMatrix->pHandle->pHeader;
  if ( (v10->Format & 8) != 0 )
    v11 = (float *)(&v10[1].RefCount + 4 * (unsigned __int8)byte_9B2B73[5 * (v10->Format & 0xF)]);
  else
    v11 = 0;
  v12.pHandle = p_BoundsMatrix->pHandle;
  m2.M[0][0] = *v11;
  m2.M[0][1] = v11[1];
  m2.M[0][2] = v11[2];
  m2.M[0][3] = v11[3];
  m2.M[1][0] = v11[4];
  m2.M[1][1] = v11[5];
  m2.M[1][2] = v11[6];
  m2.M[1][3] = v11[7];
  if ( (v12.pHandle->pHeader->Format & 4) != 0 )
    v13 = (float *)(&v12.pHandle->pHeader[1].RefCount
                  + 4 * (unsigned __int8)byte_9B2B72[5 * (v12.pHandle->pHeader->Format & 0xF)]);
  else
    v13 = (float *)&Scaleform::Render::Matrix2x4<float>::Identity;
  m.M[0][0] = *v13;
  m.M[0][1] = v13[1];
  m.M[0][2] = v13[2];
  m.M[0][3] = v13[3];
  m.M[1][0] = v13[4];
  m.M[1][1] = v13[5];
  m.M[1][2] = v13[6];
  m.M[1][3] = v13[7];
  Scaleform::Render::Matrix2x4<float>::Invert(&m);
  Scaleform::Render::Matrix2x4<float>::Append(&m, newNodeMatrix);
  Scaleform::Render::Matrix2x4<float>::Append(&m2, &m);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(p_BoundsMatrix, &m2);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(p_BoundsMatrix, boundsMatrix, Element_Cxform);
  return CanCacheAcrossTransform == 0;
}
