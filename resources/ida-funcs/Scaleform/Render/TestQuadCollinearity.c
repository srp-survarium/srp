char __cdecl Scaleform::Render::TestQuadCollinearity(
        Scaleform::Render::TessBase *con,
        const Scaleform::Render::ToleranceParams *param,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3)
{
  double v8; // st5
  double v9; // st6
  double v10; // st3
  double v11; // st7
  double v12; // st2
  double v13; // st4
  double v14; // st5
  double v15; // st7
  float v17; // [esp+4h] [ebp-30h]
  float d1b; // [esp+Ch] [ebp-28h]
  float d1c; // [esp+Ch] [ebp-28h]
  float d1d; // [esp+Ch] [ebp-28h]
  float d1; // [esp+Ch] [ebp-28h]
  float d1a; // [esp+Ch] [ebp-28h]
  float daa; // [esp+10h] [ebp-24h]
  float da; // [esp+10h] [ebp-24h]
  float dab; // [esp+10h] [ebp-24h]
  float dac; // [esp+10h] [ebp-24h]
  double v27; // [esp+14h] [ebp-20h]
  double v28; // [esp+1Ch] [ebp-18h]
  double v29; // [esp+24h] [ebp-10h]
  double v30; // [esp+2Ch] [ebp-8h]
  float x12a; // [esp+3Ch] [ebp+8h]
  float x12b; // [esp+3Ch] [ebp+8h]
  float x12c; // [esp+3Ch] [ebp+8h]
  float x12d; // [esp+3Ch] [ebp+8h]
  float x12e; // [esp+3Ch] [ebp+8h]
  float x12f; // [esp+3Ch] [ebp+8h]
  float x12g; // [esp+3Ch] [ebp+8h]
  float x12; // [esp+3Ch] [ebp+8h]
  float x12h; // [esp+3Ch] [ebp+8h]
  float x12i; // [esp+3Ch] [ebp+8h]
  float y12; // [esp+40h] [ebp+Ch]
  float y2a; // [esp+4Ch] [ebp+18h]
  float y2b; // [esp+4Ch] [ebp+18h]
  float y2c; // [esp+4Ch] [ebp+18h]
  float y2d; // [esp+4Ch] [ebp+18h]

  v8 = x3 - x1;
  v9 = x1;
  d1b = v8;
  v10 = y3 - y1;
  daa = v10;
  da = daa * daa + d1b * d1b;
  v11 = x2;
  d1c = (x2 - x3) * v10 - (y2 - y3) * v8;
  v12 = d1c;
  if ( d1c < 0.0 )
    v12 = -v12;
  d1d = v12;
  x12a = param->CollinearityTolerance * 0.25;
  if ( x12a * x12a * da >= d1d * d1d )
  {
    if ( da == 0.0 )
    {
      v14 = y1;
    }
    else
    {
      v13 = (v8 * (v11 - v9) + v10 * (y2 - y1)) / da;
      v14 = y1;
      d1 = v13;
      if ( d1 >= 0.0 && d1 <= 1.0 )
        goto LABEL_11;
    }
    v27 = v11 - v9;
    dab = v27;
    v28 = y2 - v14;
    x12b = v28;
    x12c = x12b * x12b + dab * dab;
    x12d = sqrt(x12c);
    d1a = x12d;
    v30 = x3 - x2;
    dac = v30;
    v29 = y3 - y2;
    x12e = v29;
    x12f = x12e * x12e + dac * dac;
    x12g = sqrt(x12f);
    x12 = x12g + d1a;
    if ( x12 != 0.0 )
    {
      x12h = d1a / x12;
      v15 = x12h;
      x12i = v27 * x12h + x1;
      y12 = v28 * v15 + y1;
      y2a = v29 * v15 + y2;
      y2b = (y2a - y12) * v15 + y12;
      v17 = y2b;
      y2c = v30 * v15 + x2;
      y2d = v15 * (y2c - x12i) + x12i;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(
        con,
        LODWORD(y2d),
        LODWORD(v17));
    }
LABEL_11:
    ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(con, LODWORD(x3), LODWORD(y3));
    return 1;
  }
  return 0;
}
