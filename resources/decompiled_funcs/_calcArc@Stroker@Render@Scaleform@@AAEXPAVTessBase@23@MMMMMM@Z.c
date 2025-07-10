void __userpurge Scaleform::Render::Stroker::calcArc(
        Scaleform::Render::Stroker *this@<ecx>,
        int edi0@<edi>,
        int a3@<esi>,
        Scaleform::Render::TessBase *tess,
        float x,
        float y,
        float dx1,
        float dy1,
        float dx2,
        float dy2,
        float a11,
        float a12)
{
  double v14; // st7
  double v15; // st6
  double v16; // st6
  double v17; // st5
  int v18; // ebx
  float v19; // [esp+14h] [ebp-18h]
  float v20; // [esp+14h] [ebp-18h]
  float v23; // [esp+1Ch] [ebp-10h]
  float a2a; // [esp+28h] [ebp-4h]
  float a2; // [esp+28h] [ebp-4h]
  float retaddr; // [esp+2Ch] [ebp+0h]
  float tessa; // [esp+30h] [ebp+4h]
  float dy1b; // [esp+40h] [ebp+14h]
  float dy1a; // [esp+40h] [ebp+14h]
  float dy1c; // [esp+40h] [ebp+14h]
  float dy1d; // [esp+40h] [ebp+14h]
  float dy2a; // [esp+48h] [ebp+1Ch]
  float dy2b; // [esp+48h] [ebp+1Ch]
  float dy2c; // [esp+48h] [ebp+1Ch]
  float dy2d; // [esp+48h] [ebp+1Ch]

  a2a = atan2(dy2, dx2);
  dy1b = y + dy1;
  v19 = dy1b;
  dy1a = x + dx1;
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD, int, int))tess->AddVertex)(
    tess,
    LODWORD(dy1a),
    LODWORD(v19),
    edi0,
    a3);
  v14 = a2a;
  v15 = *(float *)&tess;
  if ( *(float *)&tess < (double)a2a )
  {
    tessa = v15 + 6.283185482025146;
    v15 = tessa;
  }
  v16 = v15 - v14;
  v17 = v16 / retaddr;
  retaddr = v16 / (double)((int)v17 + 1);
  a2 = v14 + retaddr;
  if ( (int)v17 > 0 )
  {
    v18 = (int)v17;
    do
    {
      dy2a = sin(a2);
      dy2b = dy2a * this->Width + dy1a;
      v20 = dy2b;
      dy2c = cos(a2);
      dy2d = dy2c * this->Width + dx1;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(dy2d),
        LODWORD(v20));
      --v18;
      a2 = retaddr + a2;
    }
    while ( v18 );
  }
  dy1c = dy1a + a12;
  v23 = dy1c;
  dy1d = dx1 + a11;
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
    tess,
    LODWORD(dy1d),
    LODWORD(v23));
}
