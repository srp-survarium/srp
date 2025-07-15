void __thiscall Scaleform::Render::DICommand_ApplyFilter::ExecuteHWCopyAction(
        Scaleform::Render::DICommand_ApplyFilter *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::Texture **tex,
        const Scaleform::Render::Matrix2x4<float> *texgen)
{
  Scaleform::Render::HAL *pHAL; // ecx
  Scaleform::Render::HAL_vtbl *v7; // eax
  float (__thiscall *GetViewportScaling)(Scaleform::Render::HAL *); // edx
  double v9; // st7
  float *v10; // eax
  Scaleform::Render::HAL *v11; // ecx
  Scaleform::Render::Texture *v12; // [esp-Ch] [ebp-12Ch]
  Scaleform::Render::Filter *pObject; // [esp-4h] [ebp-124h]
  Scaleform::Render::Rect<float> result; // [esp+10h] [ebp-110h] BYREF
  float v15; // [esp+20h] [ebp-100h] BYREF
  float v16; // [esp+24h] [ebp-FCh]
  float v17; // [esp+28h] [ebp-F8h]
  float v18; // [esp+2Ch] [ebp-F4h]
  float v19; // [esp+30h] [ebp-F0h]
  float v20; // [esp+34h] [ebp-ECh]
  float v21; // [esp+38h] [ebp-E8h]
  float v22; // [esp+3Ch] [ebp-E4h]
  float x1; // [esp+40h] [ebp-E0h]
  float y1; // [esp+44h] [ebp-DCh]
  float x2; // [esp+48h] [ebp-D8h]
  float y2; // [esp+4Ch] [ebp-D4h]
  Scaleform::Render::MatrixPoolImpl::HMatrix v27; // [esp+5Ch] [ebp-C4h] BYREF
  Scaleform::Render::Matrix2x4<float> m; // [esp+60h] [ebp-C0h] BYREF
  Scaleform::Render::Matrix2x4<float> m2; // [esp+80h] [ebp-A0h] BYREF
  Scaleform::Render::Matrix2x4<float> sourceRect; // [esp+A0h] [ebp-80h] BYREF
  Scaleform::Render::FilterSet v31; // [esp+C0h] [ebp-60h] BYREF
  Scaleform::Render::FilterPrimitive v32; // [esp+D8h] [ebp-48h] BYREF
  Scaleform::Render::Matrix2x4<float> v33; // [esp+100h] [ebp-20h] BYREF

  m.M[0][0] = 1.0;
  m.M[0][1] = 0.0;
  m.M[0][2] = 0.0;
  m.M[0][3] = 0.0;
  m.M[1][0] = 0.0;
  m.M[1][2] = 0.0;
  m.M[1][3] = 0.0;
  v16 = 0.0;
  v17 = 0.0;
  v18 = 0.0;
  v19 = 0.0;
  v21 = 0.0;
  v22 = 0.0;
  result.x1 = 0.0;
  result.y1 = 0.0;
  result.x2 = 0.0;
  result.y2 = 0.0;
  m.M[1][1] = 1.0;
  v15 = 1.0;
  v20 = 1.0;
  x1 = (float)this->SourceRect.x1;
  y1 = (float)this->SourceRect.y1;
  x2 = (float)this->SourceRect.x2;
  y2 = (float)this->SourceRect.y2;
  m2.M[0][0] = x1 * 20.0;
  m2.M[0][1] = y1 * 20.0;
  m2.M[0][2] = x2 * 20.0;
  m2.M[0][3] = 20.0 * y2;
  LODWORD(sourceRect.M[0][0]) = (int)m2.M[0][0];
  LODWORD(sourceRect.M[0][1]) = (int)m2.M[0][1];
  LODWORD(sourceRect.M[0][2]) = (int)m2.M[0][2];
  LODWORD(sourceRect.M[0][3]) = (int)m2.M[0][3];
  Scaleform::Render::DrawableImage::CalcFilterRect(
    &result,
    (const Scaleform::Render::Rect<long> *)&sourceRect,
    this->pFilter.pObject);
  m2.M[0][0] = result.x1 * 0.05000000074505806;
  m2.M[0][1] = result.y1 * 0.05000000074505806;
  m2.M[0][2] = result.x2 * 0.05000000074505806;
  m2.M[0][3] = 0.05000000074505806 * result.y2;
  result.x1 = m2.M[0][0];
  result.y1 = m2.M[0][1];
  pObject = this->pFilter.pObject;
  result.x2 = m2.M[0][2];
  result.y2 = m2.M[0][3];
  sourceRect.M[0][0] = m2.M[0][2] - m2.M[0][0];
  sourceRect.M[0][1] = m2.M[0][3] - m2.M[0][1];
  m.M[0][0] = sourceRect.M[0][0] * m.M[0][0];
  m.M[0][1] = m.M[0][1] * sourceRect.M[0][0];
  m.M[0][2] = m.M[0][2] * sourceRect.M[0][0];
  m.M[0][3] = sourceRect.M[0][0] * m.M[0][3];
  m.M[1][0] = m.M[1][0] * sourceRect.M[0][1];
  m.M[1][1] = m.M[1][1] * sourceRect.M[0][1];
  m.M[1][2] = m.M[1][2] * sourceRect.M[0][1];
  m.M[1][3] = sourceRect.M[0][1] * m.M[1][3];
  m.M[0][3] = m2.M[0][0] + m.M[0][3];
  m.M[1][3] = m2.M[0][1] + m.M[1][3];
  Scaleform::Render::FilterSet::FilterSet(&v31, (Scaleform::GFx::Resource *)pObject);
  Scaleform::Render::FilterPrimitive::FilterPrimitive(&v32, context->pHAL, (Scaleform::GFx::Resource *)&v31, 0);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&context->pR2D->pImpl->MPool, &v27, &m, 0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&v27, &m);
  Scaleform::Render::FilterPrimitive::Insert(&v32, 0, &v27);
  context->pHAL->PushFilters(context->pHAL, &v32);
  m2.M[0][0] = 1.0;
  pHAL = context->pHAL;
  v7 = pHAL->__vftable;
  m2.M[0][1] = 0.0;
  GetViewportScaling = v7->GetViewportScaling;
  m2.M[0][2] = 0.0;
  m2.M[0][3] = -0.5;
  m2.M[1][3] = -0.5;
  m2.M[1][0] = 0.0;
  m2.M[1][2] = 0.0;
  m2.M[1][1] = 1.0;
  sourceRect.M[0][0] = 2.0;
  sourceRect.M[0][1] = 0.0;
  sourceRect.M[0][2] = 0.0;
  sourceRect.M[0][3] = 0.0;
  sourceRect.M[1][0] = 0.0;
  v9 = ((double (__thiscall *)(Scaleform::Render::HAL *))GetViewportScaling)(pHAL);
  sourceRect.M[1][1] = v9 + v9;
  sourceRect.M[1][2] = 0.0;
  sourceRect.M[1][3] = 0.0;
  v10 = (float *)Scaleform::Render::operator*(&v33, &sourceRect, &m2);
  v15 = *v10;
  v16 = v10[1];
  v17 = v10[2];
  v18 = v10[3];
  v19 = v10[4];
  v20 = v10[5];
  v21 = v10[6];
  v22 = v10[7];
  m2.M[0][0] = result.x2 - result.x1;
  m2.M[0][1] = result.y2 - result.y1;
  sourceRect.M[0][0] = x2 - x1;
  sourceRect.M[0][1] = y2 - y1;
  x1 = sourceRect.M[0][0] / m2.M[0][0];
  y1 = sourceRect.M[0][1] / m2.M[0][1];
  v15 = x1 * v15;
  v16 = v16 * x1;
  v17 = v17 * x1;
  v18 = x1 * v18;
  v11 = context->pHAL;
  v19 = v19 * y1;
  v12 = tex[1];
  v20 = v20 * y1;
  v21 = v21 * y1;
  v22 = y1 * v22;
  v11->DrawableCopyback(v11, v12, (const Scaleform::Render::Matrix2x4<float> *)&v15, texgen + 1);
  context->pHAL->PopFilters(context->pHAL);
  if ( v27.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    Scaleform::Render::MatrixPoolImpl::DataHeader::Release(v27.pHandle->pHeader);
  Scaleform::Render::FilterPrimitive::~FilterPrimitive(&v32);
  Scaleform::Render::FilterSet::~FilterSet(&v31);
}
