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
  float v15; // [esp+Ch] [ebp-34h]
  float v16; // [esp+10h] [ebp-30h]
  float y23; // [esp+2Ch] [ebp-14h]
  float y23a; // [esp+2Ch] [ebp-14h]
  float x23; // [esp+30h] [ebp-10h]
  float y123; // [esp+34h] [ebp-Ch]
  float y123a; // [esp+34h] [ebp-Ch]
  float y123b; // [esp+34h] [ebp-Ch]
  float x12; // [esp+38h] [ebp-8h]
  float x12a; // [esp+38h] [ebp-8h]
  float x12b; // [esp+38h] [ebp-8h]
  float x12c; // [esp+38h] [ebp-8h]
  float x12d; // [esp+38h] [ebp-8h]

  while ( 1 )
  {
    ++level;
    v10 = y3 - y1;
    v11 = x3 - x1;
    x12 = (x2 - x3) * v10 - (y2 - y3) * v11;
    v12 = x12;
    if ( x12 < 0.0 )
      v12 = -v12;
    y23 = v12;
    if ( y23 == 0.0 )
      break;
    x12a = v11;
    y123 = v10;
    x12b = x12a * x12a + y123 * y123;
    if ( x12b * toleranceSq >= y23 * y23 || level >= 13 )
      break;
    x12c = (x1 + x2) * 0.5;
    y123a = (y1 + y2) * 0.5;
    x23 = (x3 + x2) * 0.5;
    y23a = (y3 + y2) * 0.5;
    v13 = x12c;
    x12d = (x23 + x12c) * 0.5;
    v14 = y123a;
    y123b = 0.5 * (y23a + y123a);
    v16 = v14;
    v15 = v13;
    Scaleform::Render::TessellateQuadRecursively(con, toleranceSq, x1, y1, v15, v16, x12d, y123b, level);
    y2 = y23a;
    x2 = x23;
    y1 = y123b;
    x1 = x12d;
  }
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))con->AddVertex)(con, LODWORD(x3), LODWORD(y3));
}
