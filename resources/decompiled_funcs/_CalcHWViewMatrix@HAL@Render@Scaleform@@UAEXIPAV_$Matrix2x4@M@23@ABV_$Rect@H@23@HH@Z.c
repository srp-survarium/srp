void __thiscall Scaleform::Render::HAL::CalcHWViewMatrix(
        Scaleform::Render::HAL *this,
        __int16 vpFlags,
        Scaleform::Render::Matrix2x4<float> *pmatrix,
        const Scaleform::Render::Rect<int> *viewRect,
        int dx,
        int dy)
{
  int v6; // ecx
  int v7; // edx
  double v8; // st6
  double v9; // st5
  double v10; // st3
  double v11; // st2
  double v12; // st7
  double v13; // st5
  double v14; // st7
  double v15; // rt2
  float xhalfPixelAdjust; // [esp+0h] [ebp-Ch]
  float yhalfPixelAdjust; // [esp+4h] [ebp-8h]
  float vpWidth; // [esp+8h] [ebp-4h]
  float vpHeight; // [esp+18h] [ebp+Ch]
  float vpHeighta; // [esp+18h] [ebp+Ch]
  float vpHeightb; // [esp+18h] [ebp+Ch]
  float vpHeightc; // [esp+18h] [ebp+Ch]
  float vpHeightd; // [esp+18h] [ebp+Ch]

  v6 = viewRect->x2 - viewRect->x1;
  v7 = viewRect->y2 - viewRect->y1;
  vpWidth = (float)v6;
  vpHeight = (float)v7;
  xhalfPixelAdjust = 0.0;
  yhalfPixelAdjust = 0.0;
  v8 = vpWidth;
  v9 = vpHeight;
  if ( (vpFlags & 0x100) != 0 )
  {
    v10 = 0.0;
    if ( v6 <= 0 )
      v11 = 0.0;
    else
      v11 = 1.0 / v8;
    xhalfPixelAdjust = v11;
    if ( v7 > 0 )
      v10 = 1.0 / v9;
    yhalfPixelAdjust = v10;
  }
  pmatrix->M[0][0] = 1.0;
  pmatrix->M[1][1] = 1.0;
  pmatrix->M[0][1] = 0.0;
  pmatrix->M[0][2] = 0.0;
  pmatrix->M[0][3] = 0.0;
  pmatrix->M[1][0] = 0.0;
  pmatrix->M[1][2] = 0.0;
  pmatrix->M[1][3] = 0.0;
  if ( (vpFlags & 1) != 0 )
  {
    v12 = vpHeight;
    vpHeighta = 2.0 / v8;
    v13 = vpHeighta;
    pmatrix->M[0][0] = vpHeighta;
    vpHeightb = 2.0 / v12;
    pmatrix->M[1][1] = vpHeightb;
    pmatrix->M[0][3] = -1.0 - v13 * (double)dx - xhalfPixelAdjust;
    v14 = -1.0 - vpHeightb * (double)dy - yhalfPixelAdjust;
  }
  else
  {
    vpHeightc = 2.0 / v8;
    pmatrix->M[0][0] = vpHeightc;
    v15 = vpHeightc;
    vpHeightd = -2.0 / v9;
    pmatrix->M[1][1] = vpHeightd;
    pmatrix->M[0][3] = -1.0 - v15 * (double)dx - xhalfPixelAdjust;
    v14 = 1.0 - vpHeightd * (double)dy + yhalfPixelAdjust;
  }
  pmatrix->M[1][3] = v14;
}
