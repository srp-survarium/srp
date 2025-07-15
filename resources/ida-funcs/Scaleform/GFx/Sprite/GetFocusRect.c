__m128 *__thiscall Scaleform::GFx::Sprite::GetFocusRect(Scaleform::GFx::Sprite *this, __m128 *result)
{
  Scaleform::GFx::Sprite *v3; // eax
  Scaleform::GFx::Sprite *v4; // esi
  float *v5; // eax
  __m128 v7; // [esp+10h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v8; // [esp+20h] [ebp-20h] BYREF

  v3 = this->GetHitArea(this);
  v8.M[0][0] = 1.0;
  v4 = v3;
  v8.M[0][1] = 0.0;
  v8.M[0][2] = 0.0;
  v8.M[0][3] = 0.0;
  v8.M[1][0] = 0.0;
  v8.M[1][2] = 0.0;
  v8.M[1][3] = 0.0;
  v8.M[1][1] = 1.0;
  if ( v3 )
  {
    v5 = (float *)v3->GetMatrix(v3);
    v8.M[0][0] = *v5;
    v8.M[0][1] = v5[1];
    v8.M[0][2] = v5[2];
    v8.M[0][3] = v5[3];
    v8.M[1][0] = v5[4];
    v8.M[1][1] = v5[5];
    v8.M[1][2] = v5[6];
    v8.M[1][3] = v5[7];
    v4->GetFocusRect(v4, (Scaleform::Render::Rect<float> *)&v7);
    Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v8, result, &v7);
  }
  else
  {
    Scaleform::GFx::InteractiveObject::GetFocusRect(this, (Scaleform::Render::Rect<float> *)result);
  }
  return result;
}
