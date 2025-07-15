Scaleform::Render::Cxform *__thiscall Scaleform::Render::ProfileViews::GetCxform(
        Scaleform::Render::ProfileViews *this,
        Scaleform::Render::Cxform *result,
        Scaleform::Render::Cxform *cx,
        float *a4)
{
  float *v4; // esi
  bool v5; // zf
  Scaleform::Render::Cxform *v6; // eax
  float v7; // ebx
  int v9; // [esp+Ch] [ebp-24h]
  Scaleform::Render::Cxform v10; // [esp+10h] [ebp-20h] BYREF

  if ( BYTE1(result->M[0][1]) )
    v4 = result[LODWORD(result[4].M[1][0])].M[1];
  else
    v4 = a4;
  v5 = LODWORD(result->M[0][2]) == 0;
  qmemcpy(cx, v4, sizeof(Scaleform::Render::Cxform));
  if ( !v5 )
  {
    Scaleform::Render::Cxform::Cxform(&v10, LODWORD(result[4].M[1][1]));
    v6 = cx;
    v9 = 0;
    v7 = result->M[0][2];
    do
    {
      if ( ((1 << v9) & LODWORD(v7)) != 0 )
      {
        v6->M[0][0] = *(float *)((char *)v6->M[0] + (char *)&v10 - (char *)cx);
        v6->M[1][0] = *(float *)((char *)v6->M[0] + (char *)v10.M[1] - (char *)cx);
      }
      ++v9;
      v6 = (Scaleform::Render::Cxform *)((char *)v6 + 4);
    }
    while ( v9 < 4 );
  }
  return cx;
}
