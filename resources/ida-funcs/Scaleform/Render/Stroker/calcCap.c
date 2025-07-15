// local variable allocation has failed, the output may be wrong!
void __userpurge Scaleform::Render::Stroker::calcCap(
        Scaleform::Render::Stroker *this@<ecx>,
        Scaleform::Render::TessBase *tess,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float len,
        Scaleform::Render::StrokerTypes::LineCapType cap,
        float a7)
{
  double v9; // st7
  void (__thiscall *AddVertex)(Scaleform::Render::TessBase *, float, float); // eax
  int v13; // ebp
  float v14; // ebx
  void (__thiscall *v15)(_DWORD, _DWORD, _DWORD); // eax
  bool v16; // zf
  float v17; // [esp+1Ch] [ebp-18h]
  float v18; // [esp+1Ch] [ebp-18h]
  float v19; // [esp+1Ch] [ebp-18h]
  float v20; // [esp+1Ch] [ebp-18h]
  float v21; // [esp+1Ch] [ebp-18h]
  float v22; // [esp+28h] [ebp-Ch]
  float v23; // [esp+2Ch] [ebp-8h]
  float retaddr; // [esp+34h] [ebp+0h] OVERLAPPED
  float v25; // [esp+38h] [ebp+4h]
  float v26; // [esp+38h] [ebp+4h]
  float v27; // [esp+38h] [ebp+4h]
  float v28; // [esp+38h] [ebp+4h]
  float v29; // [esp+3Ch] [ebp+8h]
  float v30; // [esp+3Ch] [ebp+8h]
  float v31; // [esp+40h] [ebp+Ch]
  float v32; // [esp+40h] [ebp+Ch]
  float v33; // [esp+40h] [ebp+Ch]
  int v34; // [esp+40h] [ebp+Ch]
  float v35; // [esp+40h] [ebp+Ch]
  float v36; // [esp+40h] [ebp+Ch]
  float v37; // [esp+44h] [ebp+10h]
  float v38; // [esp+44h] [ebp+10h]
  float v39; // [esp+44h] [ebp+10h]
  float v40; // [esp+50h] [ebp+1Ch]
  float v41; // [esp+50h] [ebp+1Ch]
  float v42; // [esp+50h] [ebp+1Ch]
  float v43; // [esp+50h] [ebp+1Ch]
  float v44; // [esp+50h] [ebp+1Ch]

  if ( 0.0 == this->Width )
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))tess->AddVertex)(tess, v0->x, v0->y);
  }
  else
  {
    v23 = 0.0;
    v22 = 0.0;
    v9 = len;
    v29 = (v1->y - v0->y) / len;
    v37 = v29 * this->Width;
    v30 = (v0->x - v1->x) / v9;
    v31 = v30 * this->Width;
    if ( cap == RoundCap )
    {
      v38 = atan2(-v31, -v37);
      v40 = v38 + 3.141592741012573;
      *(double *)&retaddr = v40 - v38;
      v41 = this->Width / (this->CurveTolerance * 0.25 + this->Width);
      v42 = acos(v41);
      v43 = v42 + v42;
      v13 = (int)(*(double *)&retaddr / v43);
      v14 = v30 * this->Width;
      v15 = *(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v31) + 16);
      v44 = *(double *)&retaddr / (double)(v13 + 1);
      v39 = v44 + v38;
      v32 = v0->y - COERCE_FLOAT(2);
      v19 = v32;
      v33 = v0->x - a7;
      v15(LODWORD(v14), LODWORD(v33), LODWORD(v19));
      if ( v13 > 0 )
      {
        v34 = v13;
        do
        {
          retaddr = sin(v39);
          retaddr = retaddr * this->Width + v0->y;
          v20 = retaddr;
          retaddr = cos(v39);
          retaddr = retaddr * this->Width + v0->x;
          (*(void (__thiscall **)(float, float, _DWORD))(*(_DWORD *)LODWORD(v14) + 16))(
            COERCE_FLOAT(LODWORD(v14)),
            COERCE_FLOAT(LODWORD(retaddr)),
            LODWORD(v20));
          v16 = v34-- == 1;
          v39 = v44 + v39;
        }
        while ( !v16 );
      }
      v35 = v0->y + COERCE_FLOAT(2);
      v21 = v35;
      v36 = v0->x + a7;
      (*(void (__thiscall **)(float, _DWORD, _DWORD))(*(_DWORD *)LODWORD(v14) + 16))(
        COERCE_FLOAT(LODWORD(v14)),
        LODWORD(v36),
        LODWORD(v21));
    }
    else
    {
      if ( cap == SquareCap )
      {
        v23 = v30 * this->Width;
        v22 = v37;
      }
      AddVertex = tess->AddVertex;
      v25 = v0->y - v31 - v22;
      v17 = v25;
      v26 = v0->x - v37 + v23;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))AddVertex)(tess, LODWORD(v26), LODWORD(v17));
      v27 = v0->y + v31 - v22;
      v18 = v27;
      v28 = v0->x + v37 + v23;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(v28),
        LODWORD(v18));
    }
  }
}
