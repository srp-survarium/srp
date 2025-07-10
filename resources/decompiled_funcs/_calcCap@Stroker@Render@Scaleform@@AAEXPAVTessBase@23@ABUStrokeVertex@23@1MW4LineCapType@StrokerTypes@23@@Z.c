void __userpurge Scaleform::Render::Stroker::calcCap(
        Scaleform::Render::Stroker *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        Scaleform::Render::TessBase *tess,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        Scaleform::Render::StrokerTypes::LineCapType cap,
        float a9,
        float a10)
{
  double v12; // st7
  void (__thiscall *v14)(Scaleform::Render::TessBase *, float, float); // eax
  int v16; // ebp
  void (__thiscall *AddVertex)(Scaleform::Render::TessBase *, float, float); // eax
  bool v20; // zf
  float v21; // [esp+14h] [ebp-20h]
  float v23; // [esp+1Ch] [ebp-18h]
  float v24; // [esp+1Ch] [ebp-18h]
  float v26; // [esp+1Ch] [ebp-18h]
  float v27; // [esp+1Ch] [ebp-18h]
  float dy2; // [esp+28h] [ebp-Ch]
  float dx2; // [esp+2Ch] [ebp-8h]
  double dx2a; // [esp+2Ch] [ebp-8h]
  float retaddr; // [esp+34h] [ebp+0h]
  float tessa; // [esp+38h] [ebp+4h]
  float tessb; // [esp+38h] [ebp+4h]
  float tessc; // [esp+38h] [ebp+4h]
  float tessd; // [esp+38h] [ebp+4h]
  float tesse; // [esp+38h] [ebp+4h]
  float tessf; // [esp+38h] [ebp+4h]
  float a1a; // [esp+3Ch] [ebp+8h]
  float a1; // [esp+3Ch] [ebp+8h]
  float a1b; // [esp+3Ch] [ebp+8h]
  float dy1; // [esp+40h] [ebp+Ch]
  int dy1a; // [esp+40h] [ebp+Ch]
  float dy1b; // [esp+40h] [ebp+Ch]
  float dy1c; // [esp+40h] [ebp+Ch]
  float dx1; // [esp+44h] [ebp+10h]
  float daa; // [esp+48h] [ebp+14h]
  float dab; // [esp+48h] [ebp+14h]
  float dac; // [esp+48h] [ebp+14h]
  float da; // [esp+48h] [ebp+14h]
  float dad; // [esp+48h] [ebp+14h]

  if ( 0.0 == this->Width )
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))tess->AddVertex)(tess, v0->x, v0->y);
  }
  else
  {
    dx2 = 0.0;
    dy2 = 0.0;
    v12 = len;
    a1a = (v1->y - v0->y) / len;
    dx1 = a1a * this->Width;
    a1 = (v0->x - v1->x) / v12;
    dy1 = a1 * this->Width;
    if ( cap == RoundCap )
    {
      a1b = atan2(-dy1, -dx1);
      daa = a1b + 3.141592741012573;
      dx2a = daa - a1b;
      dab = this->Width / (this->CurveTolerance * 0.25 + this->Width);
      dac = acos(dab);
      da = dac + dac;
      v16 = (int)(dx2a / da);
      AddVertex = tess->AddVertex;
      tesse = v0->y - dy1;
      v21 = tesse;
      tessf = v0->x - dx1;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD, int, int))AddVertex)(
        tess,
        LODWORD(tessf),
        LODWORD(v21),
        a3,
        a2);
      if ( v16 > 0 )
      {
        dy1a = (int)(dx2a / da);
        do
        {
          retaddr = sin(dx1);
          retaddr = retaddr * this->Width + v0->y;
          v26 = retaddr;
          retaddr = cos(dx1);
          retaddr = retaddr * this->Width + v0->x;
          ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
            tess,
            LODWORD(retaddr),
            LODWORD(v26));
          v20 = dy1a-- == 1;
          dx1 = a10 + dx1;
        }
        while ( !v20 );
      }
      dad = dx2a / (double)(v16 + 1);
      dy1b = v0->y + dad;
      v27 = dy1b;
      dy1c = v0->x + a9;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(dy1c),
        LODWORD(v27));
    }
    else
    {
      if ( cap == SquareCap )
      {
        dx2 = a1 * this->Width;
        dy2 = dx1;
      }
      v14 = tess->AddVertex;
      tessa = v0->y - dy1 - dy2;
      v23 = tessa;
      tessb = v0->x - dx1 + dx2;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v14)(tess, LODWORD(tessb), LODWORD(v23));
      tessc = v0->y + dy1 - dy2;
      v24 = tessc;
      tessd = v0->x + dx1 + dx2;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(tessd),
        LODWORD(v24));
    }
  }
}
