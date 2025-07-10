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
  float r; // [esp+24h] [ebp-2Ch]
  float l; // [esp+28h] [ebp-28h]
  Scaleform::Render::Point3<float> vUpVec; // [esp+2Ch] [ebp-24h] BYREF
  Scaleform::Render::Point3<float> vLookatPt; // [esp+38h] [ebp-18h] BYREF
  Scaleform::Render::Point3<float> vEyePt; // [esp+44h] [ebp-Ch] BYREF
  float matViewa; // [esp+54h] [ebp+4h]
  float matViewb; // [esp+54h] [ebp+4h]
  float matViewc; // [esp+54h] [ebp+4h]
  float t; // [esp+5Ch] [ebp+Ch]
  float b; // [esp+60h] [ebp+10h]
  float eyeZ; // [esp+68h] [ebp+18h]
  float eyeZa; // [esp+68h] [ebp+18h]
  float eyeZb; // [esp+68h] [ebp+18h]

  r = frameRect->x2 - projCenter->x;
  l = -(projCenter->x - frameRect->x1);
  b = -(frameRect->y2 - projCenter->y);
  t = projCenter->y - frameRect->y1;
  vUpVec.x = frameRect->x2 - frameRect->x1;
  vUpVec.x = fabs(vUpVec.x);
  vUpVec.x = vUpVec.x * 0.5;
  v9 = fieldOfView;
  if ( focalLength == 0.0 )
  {
    if ( v9 > 0.0 )
    {
      *(double *)&vUpVec.x = vUpVec.x;
      eyeZ = v9 * 3.141592653589793 / 180.0;
      eyeZa = 0.5 * eyeZ;
      eyeZb = tan(eyeZa);
      x = *(double *)&vUpVec.x / eyeZb;
      v10 = 0.0;
    }
    else
    {
      v10 = 0.0;
      x = vUpVec.x;
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
    matViewa = -focalLength;
    v14 = -100000.0;
    if ( matViewa >= -100000.0 )
      v14 = matViewa;
    matViewb = v14;
    vEyePt.x = projCenter->x;
    vEyePt.y = projCenter->y;
    vEyePt.z = matViewb;
    vLookatPt.x = projCenter->x;
    vLookatPt.y = projCenter->y;
    vLookatPt.z = v10;
    if ( bInvertY )
      v15 = 1.0;
    else
      v15 = -1.0;
    matViewc = v15;
    vUpVec.x = v10;
    vUpVec.y = matViewc;
    vUpVec.z = v10;
    if ( bInvertY )
      Scaleform::Render::Matrix3x4<float>::ViewLH(matView, &vEyePt, &vLookatPt, &vUpVec);
    else
      Scaleform::Render::Matrix3x4<float>::ViewRH(matView, &vEyePt, &vLookatPt, &vUpVec);
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
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterLH(matPersp, focalLength, l, r, b, t, fNearZa, fFarZa);
      else
        Scaleform::Render::Matrix4x4<float>::PerspectiveOffCenterRH(matPersp, focalLength, l, r, b, t, fNearZa, fFarZa);
    }
    else
    {
      fFarZ = 100000.0;
      fNearZ = v18;
      if ( bInvertY )
        Scaleform::Render::Matrix4x4<float>::OrthoOffCenterLH(matPersp, l, r, b, t, fNearZ, fFarZ);
      else
        Scaleform::Render::Matrix4x4<float>::OrthoOffCenterRH(matPersp, l, r, b, t, fNearZ, fFarZ);
    }
  }
}
