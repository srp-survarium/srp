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
  float v16; // [esp+0h] [ebp-Ch]
  float v17; // [esp+4h] [ebp-8h]
  float v18; // [esp+8h] [ebp-4h]
  float v19; // [esp+18h] [ebp+Ch]
  float v20; // [esp+18h] [ebp+Ch]
  float v21; // [esp+18h] [ebp+Ch]
  float v22; // [esp+18h] [ebp+Ch]
  float v23; // [esp+18h] [ebp+Ch]

  v6 = viewRect->x2 - viewRect->x1;
  v7 = viewRect->y2 - viewRect->y1;
  v18 = (float)v6;
  v19 = (float)v7;
  v16 = 0.0;
  v17 = 0.0;
  v8 = v18;
  v9 = v19;
  if ( (vpFlags & 0x100) != 0 )
  {
    v10 = 0.0;
    if ( v6 <= 0 )
      v11 = 0.0;
    else
      v11 = 1.0 / v8;
    v16 = v11;
    if ( v7 > 0 )
      v10 = 1.0 / v9;
    v17 = v10;
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
    v12 = v19;
    v20 = 2.0 / v8;
    v13 = v20;
    pmatrix->M[0][0] = v20;
    v21 = 2.0 / v12;
    pmatrix->M[1][1] = v21;
    pmatrix->M[0][3] = -1.0 - v13 * (double)dx - v16;
    v14 = -1.0 - v21 * (double)dy - v17;
  }
  else
  {
    v22 = 2.0 / v8;
    pmatrix->M[0][0] = v22;
    v15 = v22;
    v23 = -2.0 / v9;
    pmatrix->M[1][1] = v23;
    pmatrix->M[0][3] = -1.0 - v15 * (double)dx - v16;
    v14 = 1.0 - v23 * (double)dy + v17;
  }
  pmatrix->M[1][3] = v14;
}
