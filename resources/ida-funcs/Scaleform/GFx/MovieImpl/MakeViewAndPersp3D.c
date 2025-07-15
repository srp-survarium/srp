void __cdecl Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(
        Scaleform::Render::Matrix3x4<float> *matView,
        Scaleform::Render::Matrix4x4<float> *matPersp,
        const Scaleform::Render::Rect<float> *frameRect,
        const Scaleform::Render::Point<float> *projCenter,
        float fieldOfView,
        float focalLength,
        bool bInvertY)
{
  double v9; // st4
  double v10; // st7
  double x; // st6
  double v13; // st6
  double v14; // st5
  double v15; // st6
  double v16; // rt1
  double v17; // st6
  double v18; // st7
  float fNearZ; // [esp+14h] [ebp-3Ch]
  float fNearZa; // [esp+14h] [ebp-3Ch]
  float fFarZ; // [esp+18h] [ebp-38h]
  float fFarZa; // [esp+18h] [ebp-38h]
  float viewMaxX; // [esp+24h] [ebp-2Ch]
  float viewMinX; // [esp+28h] [ebp-28h]
  Scaleform::Render::Point3<float> upVec; // [esp+2Ch] [ebp-24h] BYREF
  Scaleform::Render::Point3<float> lookAtPt; // [esp+38h] [ebp-18h] BYREF
  Scaleform::Render::Point3<float> eyePt; // [esp+44h] [ebp-Ch] BYREF
  float v28; // [esp+54h] [ebp+4h]
  float v29; // [esp+54h] [ebp+4h]
  float v30; // [esp+54h] [ebp+4h]
  float viewMaxY; // [esp+5Ch] [ebp+Ch]
  float viewMinY; // [esp+60h] [ebp+10h]
  float v33; // [esp+68h] [ebp+18h]
  float v34; // [esp+68h] [ebp+18h]
  float v35; // [esp+68h] [ebp+18h]

  viewMaxX = frameRect->x2 - projCenter->x;
  viewMinX = -(projCenter->x - frameRect->x1);
  viewMinY = -(frameRect->y2 - projCenter->y);
  viewMaxY = projCenter->y - frameRect->y1;
  upVec.x = frameRect->x2 - frameRect->x1;
  upVec.x = fabs(upVec.x);
  upVec.x = upVec.x * 0.5;
  v9 = fieldOfView;
  if ( focalLength == 0.0 )
  {
    if ( v9 > 0.0 )
    {
      *(double *)&upVec.x = upVec.x;
      v33 = v9 * 3.141592653589793 / 180.0;
      v34 = 0.5 * v33;
      v35 = tan(v34);
      x = *(double *)&upVec.x / v35;
      v10 = 0.0;
    }
    else
    {
      v10 = 0.0;
      x = upVec.x;
    }
    focalLength = x;
  }
  else
  {
    v10 = 0.0;
  }
  v13 = 1.0;
  if ( matView )
  {
    v28 = -focalLength;
    v14 = -100000.0;
    if ( v28 >= -100000.0 )
      v14 = v28;
    v29 = v14;
    eyePt.x = projCenter->x;
    eyePt.y = projCenter->y;
    eyePt.z = v29;
    lookAtPt.x = projCenter->x;
    lookAtPt.y = projCenter->y;
    lookAtPt.z = v10;
    if ( bInvertY )
      v15 = 1.0;
    else
      v15 = -1.0;
    v30 = v15;
    upVec.x = v10;
    upVec.y = v30;
    upVec.z = v10;
    if ( bInvertY )
      Scaleform::Render::Matrix3x4<float>::ViewLH(matView, &eyePt, &lookAtPt, &upVec);
    else
      Scaleform::Render::Matrix3x4<float>::ViewRH(matView, &eyePt, &lookAtPt, &upVec);
    v10 = 0.0;
    v13 = 1.0;
  }
  if ( matPersp )
  {
    v16 = v13;
    v17 = v10;
    v18 = v16;
    if ( v17 < fieldOfView )
    {
      fFarZa = 100000.0;
      fNearZa = v18;
      if ( bInvertY )
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(
          matPersp,
          focalLength,
          viewMinX,
          viewMaxX,
          viewMinY,
          viewMaxY,
          fNearZa,
          fFarZa);
      else
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(
          matPersp,
          focalLength,
          viewMinX,
          viewMaxX,
          viewMinY,
          viewMaxY,
          fNearZa,
          fFarZa);
    }
    else
    {
      fFarZ = 100000.0;
      fNearZ = v18;
      if ( bInvertY )
        Scaleform::Render::Matrix4x4<float>::OrthoOffCenterLH(
          matPersp,
          viewMinX,
          viewMaxX,
          viewMinY,
          viewMaxY,
          fNearZ,
          fFarZ);
      else
        Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(
          matPersp,
          viewMinX,
          viewMaxX,
          viewMinY,
          viewMaxY,
          fNearZ,
          fFarZ);
    }
  }
}
