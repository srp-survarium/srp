__m128 *__thiscall Scaleform::GFx::AS3::AvmBitmap::GetBounds(
        Scaleform::GFx::AS3::AvmBitmap *this,
        __m128 *result,
        Scaleform::Render::Matrix2x4<float> *transform)
{
  double v3; // st7
  Scaleform::GFx::ImageResource *pObject; // eax
  double v6; // st6
  Scaleform::GFx::ImageResource *v7; // ecx
  int v8; // eax
  float v10; // [esp+B8h] [ebp-58h]
  float v11; // [esp+B8h] [ebp-58h]
  float v12; // [esp+BCh] [ebp-54h]
  __m128 v13; // [esp+C0h] [ebp-50h] BYREF
  int v14; // [esp+D0h] [ebp-40h] BYREF
  int v15; // [esp+D4h] [ebp-3Ch]
  float v16; // [esp+D8h] [ebp-38h]
  float v17; // [esp+DCh] [ebp-34h]
  __m128 v18; // [esp+E0h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v19; // [esp+F0h] [ebp-20h] BYREF

  v3 = 0.0;
  v13.m128_f32[0] = 0.0;
  pObject = this->pImage.pObject;
  v13.m128_f32[1] = 0.0;
  v6 = 0.0;
  v10 = 0.0 + 0.0;
  v13.m128_f32[2] = v10;
  v13.m128_f32[3] = v10;
  if ( pObject )
  {
    pObject->pImage->GetRect(pObject->pImage, (Scaleform::Render::Rect<unsigned long> *)&v14);
    v7 = this->pImage.pObject;
    v19.M[0][0] = 1.0;
    v19.M[0][1] = 0.0;
    v19.M[0][2] = 0.0;
    v19.M[0][3] = 0.0;
    v19.M[1][0] = 0.0;
    v19.M[1][2] = 0.0;
    v19.M[1][3] = 0.0;
    v19.M[1][1] = 1.0;
    v8 = (int)v7->pImage->GetAsImage(v7->pImage);
    if ( v8 )
    {
      (*(void (__thiscall **)(int, Scaleform::Render::Matrix2x4<float> *))(*(_DWORD *)v8 + 68))(v8, &v19);
      v18.m128_f32[0] = (float)(unsigned int)(20 * v14);
      v18.m128_f32[1] = (float)(unsigned int)(20 * v15);
      v18.m128_f32[2] = (float)(unsigned int)(20 * LODWORD(v16));
      v18.m128_f32[3] = (float)(unsigned int)(20 * LODWORD(v17));
      Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v19, &v13, &v18);
    }
    else
    {
      v18.m128_f32[0] = (float)(unsigned int)(20 * v14);
      v18.m128_f32[1] = (float)(unsigned int)(20 * v15);
      v18.m128_f32[2] = (float)(unsigned int)(20 * LODWORD(v16));
      v18.m128_f32[3] = (float)(unsigned int)(20 * LODWORD(v17));
      v13.m128_f32[0] = v18.m128_f32[0];
      v13.m128_f32[1] = v18.m128_f32[1];
      v13.m128_f32[2] = v18.m128_f32[2];
      v13.m128_f32[3] = v18.m128_f32[3];
    }
    v3 = 0.0;
    v6 = 0.0;
  }
  v11 = v13.m128_f32[2] - v13.m128_f32[0];
  v12 = v13.m128_f32[3] - v13.m128_f32[1];
  v18.m128_f32[0] = v3;
  v18.m128_f32[1] = v18.m128_f32[0];
  v18.m128_f32[2] = v11 + v6;
  v18.m128_f32[3] = v6 + v12;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(transform, result, &v18);
  return result;
}
