Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::Button::GetFocusRect(
        Scaleform::GFx::Button *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *BoundsOfState; // eax
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double x1; // st4
  Scaleform::Render::Rect<float> *v8; // eax
  Scaleform::Render::Rect<float> *v9; // eax
  Scaleform::Render::Rect<float> *v10; // eax
  const Scaleform::Render::Rect<float> *v11; // eax
  const Scaleform::Render::Rect<float> *v12; // ecx
  float y1; // [esp+70h] [ebp-4Ch]
  float v14; // [esp+70h] [ebp-4Ch]
  float v15; // [esp+70h] [ebp-4Ch]
  float x2; // [esp+74h] [ebp-48h]
  float v17; // [esp+74h] [ebp-48h]
  float v18; // [esp+74h] [ebp-48h]
  float y2; // [esp+78h] [ebp-44h]
  float v20; // [esp+78h] [ebp-44h]
  float v21; // [esp+78h] [ebp-44h]
  Scaleform::Render::Rect<float> rc; // [esp+7Ch] [ebp-40h] BYREF
  Scaleform::Render::Rect<float> v23; // [esp+8Ch] [ebp-30h] BYREF
  Scaleform::Render::Matrix2x4<float> transform; // [esp+9Ch] [ebp-20h] BYREF

  transform.M[0][0] = 1.0;
  transform.M[0][1] = 0.0;
  transform.M[0][2] = 0.0;
  transform.M[0][3] = 0.0;
  transform.M[1][0] = 0.0;
  transform.M[1][2] = 0.0;
  transform.M[1][3] = 0.0;
  rc.x1 = 0.0;
  rc.y1 = 0.0;
  rc.x2 = 0.0;
  rc.y2 = 0.0;
  transform.M[1][1] = 1.0;
  BoundsOfState = Scaleform::GFx::Button::GetBoundsOfState(
                    this,
                    &v23,
                    &transform,
                    (Scaleform::GFx::Button::ButtonState)3);
  y1 = BoundsOfState->y1;
  x2 = BoundsOfState->x2;
  y2 = BoundsOfState->y2;
  rc.x1 = BoundsOfState->x1;
  v4 = y1;
  rc.y1 = y1;
  v5 = x2;
  rc.x2 = x2;
  v6 = y2;
  rc.y2 = y2;
  x1 = rc.x1;
  if ( rc.x1 != x2 )
    goto LABEL_3;
  if ( v4 != v6 )
    goto LABEL_3;
  v9 = Scaleform::GFx::Button::GetBoundsOfState(this, &v23, &transform, (Scaleform::GFx::Button::ButtonState)2);
  v20 = v9->y1;
  v17 = v9->x2;
  v14 = v9->y2;
  rc.x1 = v9->x1;
  v4 = v20;
  rc.y1 = v20;
  v5 = v17;
  rc.x2 = v17;
  v6 = v14;
  rc.y2 = v14;
  x1 = rc.x1;
  if ( rc.x1 != v17 )
    goto LABEL_3;
  if ( v4 == v6 )
  {
    v10 = Scaleform::GFx::Button::GetBoundsOfState(this, &v23, &transform, (Scaleform::GFx::Button::ButtonState)1);
    v21 = v10->y1;
    v18 = v10->x2;
    v15 = v10->y2;
    rc.x1 = v10->x1;
    rc.y1 = v21;
    rc.x2 = v18;
    rc.y2 = v15;
    if ( rc.x1 == v18
      && v15 == v21
      && (v11 = Scaleform::GFx::Button::GetBoundsOfState(this, &v23, &transform, None),
          v12 = Scaleform::Render::Rect<float>::operator=(&rc, v11),
          v12->x1 == v12->x2)
      && v12->y1 == v12->y2 )
    {
      this->GetBounds(this, result, &transform);
      return result;
    }
    else
    {
      Scaleform::Render::Rect<float>::Rect<float>(result, &rc);
      return result;
    }
  }
  else
  {
LABEL_3:
    v8 = result;
    result->x1 = x1;
    result->y1 = v4;
    result->x2 = v5;
    result->y2 = v6;
  }
  return v8;
}
