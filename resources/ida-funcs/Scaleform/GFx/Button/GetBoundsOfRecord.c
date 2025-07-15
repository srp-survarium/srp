Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::Button::GetBoundsOfRecord(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Matrix2x4<float> *transform,
        Scaleform::GFx::DisplayObjectBase *pch)
{
  const Scaleform::Render::Matrix2x4<float> *(__thiscall *GetMatrix)(Scaleform::GFx::DisplayObjectBase *); // edx
  const Scaleform::Render::Matrix2x4<float> *m; // eax
  _BYTE v7[16]; // [esp+30h] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> v8; // [esp+40h] [ebp-20h] BYREF

  result->x1 = 0.0;
  result->y1 = 0.0;
  result->x2 = 0.0;
  result->y2 = 0.0;
  v8.M[0][0] = 1.0;
  v8.M[1][1] = 1.0;
  v8.M[0][1] = 0.0;
  v8.M[0][2] = 0.0;
  v8.M[0][3] = 0.0;
  v8.M[1][0] = 0.0;
  v8.M[1][2] = 0.0;
  v8.M[1][3] = 0.0;
  if ( pch )
  {
    v8.M[0][0] = transform->M[0][0];
    v8.M[0][1] = transform->M[0][1];
    v8.M[0][2] = transform->M[0][2];
    v8.M[0][3] = transform->M[0][3];
    v8.M[1][0] = transform->M[1][0];
    v8.M[1][1] = transform->M[1][1];
    v8.M[1][2] = transform->M[1][2];
    GetMatrix = pch->GetMatrix;
    v8.M[1][3] = transform->M[1][3];
    m = GetMatrix(pch);
    Scaleform::Render::Matrix2x4<float>::Prepend(&v8, m);
    *result = *pch->GetBounds(pch, v7, &v8);
  }
  return result;
}
