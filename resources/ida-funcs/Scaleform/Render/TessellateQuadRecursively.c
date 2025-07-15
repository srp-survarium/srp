void __cdecl Scaleform::Render::TessellateQuadRecursively(
        Scaleform::Render::TessBase *con,
        float toleranceSq,
        float x1,
        float y1,
        float x2,
        float y2,
        float x3,
        float y3,
        int level)
{
  double v10; // st4
  double v11; // st2
  double v12; // st1
  double v13; // st4
  double v14; // st5
  float x2a; // [esp+Ch] [ebp-34h]
  float y2a; // [esp+10h] [ebp-30h]
  float v17; // [esp+2Ch] [ebp-14h]
  float v18; // [esp+2Ch] [ebp-14h]
  float v19; // [esp+30h] [ebp-10h]
  float v20; // [esp+34h] [ebp-Ch]
  float v21; // [esp+34h] [ebp-Ch]
  float v22; // [esp+34h] [ebp-Ch]
  float v23; // [esp+38h] [ebp-8h]
  float v24; // [esp+38h] [ebp-8h]
  float v25; // [esp+38h] [ebp-8h]
  float v26; // [esp+38h] [ebp-8h]
  float v27; // [esp+38h] [ebp-8h]

  while ( 1 )
  {
    ++level;
    v10 = y3 - y1;
    v11 = x3 - x1;
    v23 = (x2 - x3) * v10 - (y2 - y3) * v11;
    v12 = v23;
    if ( v23 < 0.0 )
      v12 = -v12;
    v17 = v12;
    if ( v17 == 0.0 )
      break;
    v24 = v11;
    v20 = v10;
    v25 = v24 * v24 + v20 * v20;
    if ( v25 * toleranceSq >= v17 * v17 || level >= 13 )
      break;
    v26 = (x1 + x2) * 0.5;
    v21 = (y1 + y2) * 0.5;
    v19 = (x3 + x2) * 0.5;
    v18 = (y3 + y2) * 0.5;
    v13 = v26;
    v27 = (v19 + v26) * 0.5;
    v14 = v21;
    v22 = 0.5 * (v18 + v21);
    y2a = v14;
    x2a = v13;
    Scaleform::Render::TessellateQuadRecursively(con, toleranceSq, x1, y1, x2a, y2a, v27, v22, level);
    y2 = v18;
    x2 = v19;
    y1 = v22;
    x1 = v27;
  }
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(con, LODWORD(x3), LODWORD(y3));
}
