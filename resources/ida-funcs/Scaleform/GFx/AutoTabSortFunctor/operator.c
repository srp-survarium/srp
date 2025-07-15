int __thiscall Scaleform::GFx::AutoTabSortFunctor::operator()(
        Scaleform::GFx::AutoTabSortFunctor *this,
        const Scaleform::GFx::InteractiveObject *a,
        const Scaleform::GFx::InteractiveObject *b)
{
  __m128 *v3; // eax
  __m128 *v4; // eax
  double y1; // st5
  double v6; // st4
  double v7; // st5
  double v8; // st4
  float v10; // [esp+8h] [ebp-74h]
  float v11; // [esp+8h] [ebp-74h]
  float v12; // [esp+8h] [ebp-74h]
  float v13; // [esp+8h] [ebp-74h]
  float v14; // [esp+8h] [ebp-74h]
  float v15; // [esp+8h] [ebp-74h]
  float v16; // [esp+Ch] [ebp-70h] BYREF
  float v17; // [esp+10h] [ebp-6Ch]
  Scaleform::Render::Rect<float> pr; // [esp+1Ch] [ebp-60h] BYREF
  Scaleform::Render::Rect<float> v19; // [esp+2Ch] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+3Ch] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> v21; // [esp+5Ch] [ebp-20h] BYREF

  pmat.M[0][0] = 1.0;
  pmat.M[0][1] = 0.0;
  pmat.M[0][2] = 0.0;
  pmat.M[0][3] = 0.0;
  pmat.M[1][0] = 0.0;
  pmat.M[1][2] = 0.0;
  pmat.M[1][3] = 0.0;
  pmat.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(&a->Scaleform::GFx::DisplayObject, &pmat);
  v21.M[0][0] = 1.0;
  v21.M[0][1] = 0.0;
  v21.M[0][2] = 0.0;
  v21.M[0][3] = 0.0;
  v21.M[1][0] = 0.0;
  v21.M[1][2] = 0.0;
  v21.M[1][3] = 0.0;
  v21.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(&b->Scaleform::GFx::DisplayObject, &v21);
  v3 = (__m128 *)a->GetFocusRect(a, &v16);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&pmat, (__m128 *)&pr, v3);
  v4 = (__m128 *)b->GetFocusRect(b, &v16);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v21, (__m128 *)&v19, v4);
  v16 = (pr.x2 + pr.x1) * 0.5;
  y1 = pr.y1;
  v17 = (pr.y2 + pr.y1) * 0.5;
  pr.x1 = (v19.x2 + v19.x1) * 0.5;
  pr.y1 = 0.5 * (v19.y2 + v19.y1);
  v10 = y1 - v19.y1;
  v6 = v10;
  if ( v10 < 0.0 )
    v6 = -v6;
  v11 = v6;
  if ( v11 <= 20.0 )
    goto LABEL_12;
  v12 = pr.y2 - v19.y2;
  v7 = v12;
  if ( v12 < 0.0 )
    v7 = -v7;
  v13 = v7;
  if ( v13 <= 20.0 )
    goto LABEL_12;
  v14 = v17 - pr.y1;
  v8 = v14;
  if ( v14 < 0.0 )
    v8 = -v8;
  v15 = v8;
  if ( v15 <= 20.0 )
  {
LABEL_12:
    if ( pr.x1 <= (double)v16 )
      return 0;
  }
  else if ( v17 >= (double)pr.y1 )
  {
    return 0;
  }
  return 1;
}
