Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::Scale9GridInfo::AdjustBounds(
        Scaleform::Render::Scale9GridInfo *this,
        Scaleform::Render::Rect<float> *result,
        float bounds)
{
  float *v3; // eax
  double v5; // st6
  double v6; // st7
  Scaleform::Render::Rect<float> *v7; // eax
  float v8; // [esp+4h] [ebp-24h]
  float v9; // [esp+8h] [ebp-20h]
  float v10; // [esp+Ch] [ebp-1Ch] BYREF
  float v11; // [esp+10h] [ebp-18h] BYREF
  float v12; // [esp+14h] [ebp-14h] BYREF
  float v13; // [esp+18h] [ebp-10h] BYREF
  float v14; // [esp+1Ch] [ebp-Ch] BYREF
  float v15; // [esp+20h] [ebp-8h] BYREF
  float v16; // [esp+24h] [ebp-4h] BYREF

  v3 = (float *)LODWORD(bounds);
  bounds = *(float *)LODWORD(bounds);
  v10 = v3[1];
  v11 = v3[2];
  v12 = v3[1];
  v13 = v3[2];
  v14 = v3[3];
  v15 = *v3;
  v16 = v3[3];
  Scaleform::Render::Scale9GridInfo::Transform(this, &bounds, &v10);
  Scaleform::Render::Scale9GridInfo::Transform(this, &v11, &v12);
  Scaleform::Render::Scale9GridInfo::Transform(this, &v13, &v14);
  Scaleform::Render::Scale9GridInfo::Transform(this, &v15, &v16);
  v8 = v10;
  v5 = bounds;
  v6 = v10;
  v9 = bounds;
  if ( v11 < (double)bounds )
    bounds = v11;
  if ( v12 < v6 )
    v8 = v12;
  if ( v5 < v11 )
    v9 = v11;
  if ( v12 > v6 )
    v10 = v12;
  if ( bounds > (double)v13 )
    bounds = v13;
  if ( v8 > (double)v14 )
    v8 = v14;
  if ( v9 < (double)v13 )
    v9 = v13;
  if ( v10 < (double)v14 )
    v10 = v14;
  if ( bounds > (double)v15 )
    bounds = v15;
  if ( v8 > (double)v16 )
    v8 = v16;
  if ( v9 < (double)v15 )
    v9 = v15;
  if ( v10 < (double)v16 )
    v10 = v16;
  v7 = result;
  result->x1 = bounds;
  result->y1 = v8;
  result->x2 = v9;
  result->y2 = v10;
  return v7;
}
