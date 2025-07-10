void __thiscall Scaleform::Render::Matrix3x4<float>::GetEulerAngles(
        Scaleform::Render::Matrix3x4<float> *this,
        float *eX,
        float *eY,
        float *eZ)
{
  float *v4; // eax
  double v5; // st7
  float v6; // [esp+3Ch] [ebp-34h]
  float v7; // [esp+3Ch] [ebp-34h]
  float v8; // [esp+3Ch] [ebp-34h]
  float v9; // [esp+3Ch] [ebp-34h]
  float v10; // [esp+3Ch] [ebp-34h]
  Scaleform::Render::Matrix3x4<float> dst; // [esp+40h] [ebp-30h] BYREF

  memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)this, sizeof(dst));
  Scaleform::Render::Matrix3x4<float>::SetXScale(&dst, 1.0);
  Scaleform::Render::Matrix3x4<float>::SetYScale(&dst, 1.0);
  Scaleform::Render::Matrix3x4<float>::SetZScale(&dst, 1.0);
  if ( dst.M[1][0] > 0.9980000257492065 )
  {
    if ( eY )
    {
      v6 = atan2(dst.M[0][2], dst.M[2][2]);
      *eY = v6;
    }
    v4 = eZ;
    if ( !eZ )
      goto LABEL_7;
    v5 = 1.5707964;
LABEL_6:
    *v4 = v5;
LABEL_7:
    if ( eX )
      *eX = 0.0;
    return;
  }
  if ( dst.M[1][0] < -0.9980000257492065 )
  {
    if ( eY )
    {
      v7 = atan2(dst.M[0][2], dst.M[2][2]);
      *eY = v7;
    }
    v4 = eZ;
    if ( !eZ )
      goto LABEL_7;
    v5 = -1.5707964;
    goto LABEL_6;
  }
  if ( eY )
  {
    v8 = atan2(-dst.M[2][0], dst.M[0][0]);
    *eY = v8;
  }
  if ( eX )
  {
    v9 = atan2(-dst.M[1][2], dst.M[1][1]);
    *eX = v9;
  }
  if ( eZ )
  {
    v10 = asin(dst.M[1][0]);
    *eZ = v10;
  }
}
