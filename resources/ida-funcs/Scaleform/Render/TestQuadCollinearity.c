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
  float v18; // [esp+Ch] [ebp-28h]
  float v19; // [esp+Ch] [ebp-28h]
  float v20; // [esp+Ch] [ebp-28h]
  float v21; // [esp+Ch] [ebp-28h]
  float v22; // [esp+Ch] [ebp-28h]
  float v23; // [esp+10h] [ebp-24h]
  float v24; // [esp+10h] [ebp-24h]
  float v25; // [esp+10h] [ebp-24h]
  float v26; // [esp+10h] [ebp-24h]
  double v27; // [esp+14h] [ebp-20h]
  double v28; // [esp+1Ch] [ebp-18h]
  double v29; // [esp+24h] [ebp-10h]
  double v30; // [esp+2Ch] [ebp-8h]
  float v31; // [esp+3Ch] [ebp+8h]
  float v32; // [esp+3Ch] [ebp+8h]
  float v33; // [esp+3Ch] [ebp+8h]
  float v34; // [esp+3Ch] [ebp+8h]
  float v35; // [esp+3Ch] [ebp+8h]
  float v36; // [esp+3Ch] [ebp+8h]
  float v37; // [esp+3Ch] [ebp+8h]
  float v38; // [esp+3Ch] [ebp+8h]
  float v39; // [esp+3Ch] [ebp+8h]
  float v40; // [esp+3Ch] [ebp+8h]
  float v41; // [esp+40h] [ebp+Ch]
  float v42; // [esp+4Ch] [ebp+18h]
  float v43; // [esp+4Ch] [ebp+18h]
  float v44; // [esp+4Ch] [ebp+18h]
  float v45; // [esp+4Ch] [ebp+18h]

  v8 = x3 - x1;
  v9 = x1;
  v18 = v8;
  v10 = y3 - y1;
  v23 = v10;
  v24 = v23 * v23 + v18 * v18;
  v11 = x2;
  v19 = (x2 - x3) * v10 - (y2 - y3) * v8;
  v12 = v19;
  if ( v19 < 0.0 )
    v12 = -v12;
  v20 = v12;
  v31 = param->CollinearityTolerance * 0.25;
  if ( v31 * v31 * v24 >= v20 * v20 )
  {
    if ( v24 == 0.0 )
    {
      v14 = y1;
    }
    else
    {
      v13 = (v8 * (v11 - v9) + v10 * (y2 - y1)) / v24;
      v14 = y1;
      v21 = v13;
      if ( v21 >= 0.0 && v21 <= 1.0 )
        goto LABEL_11;
    }
    v27 = v11 - v9;
    v25 = v27;
    v28 = y2 - v14;
    v32 = v28;
    v33 = v32 * v32 + v25 * v25;
    v34 = sqrt(v33);
    v22 = v34;
    v30 = x3 - x2;
    v26 = v30;
    v29 = y3 - y2;
    v35 = v29;
    v36 = v35 * v35 + v26 * v26;
    v37 = sqrt(v36);
    v38 = v37 + v22;
    if ( v38 != 0.0 )
    {
      v39 = v22 / v38;
      v15 = v39;
      v40 = v27 * v39 + x1;
      v41 = v28 * v15 + y1;
      v42 = v29 * v15 + y2;
      v43 = (v42 - v41) * v15 + v41;
      v17 = v43;
      v44 = v30 * v15 + x2;
      v45 = v15 * (v44 - v40) + v40;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(
        con,
        LODWORD(v45),
        LODWORD(v17));
    }
LABEL_11:
    ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(con, LODWORD(x3), LODWORD(y3));
    return 1;
  }
  return 0;
}
