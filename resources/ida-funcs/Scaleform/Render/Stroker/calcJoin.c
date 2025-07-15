void __userpurge Scaleform::Render::Stroker::calcJoin(
        Scaleform::Render::Stroker *this@<ecx>,
        float a2@<ebp>,
        float a3@<esi>,
        Scaleform::Render::TessBase *tess,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        float v2,
        float len1,
        float len2)
{
  double v10; // st6
  float v13; // ebp
  double v14; // st5
  double v15; // st4
  double v16; // st3
  Scaleform::Render::StrokerTypes::LineJoinType LineJoin; // ecx
  double v18; // st7
  double v19; // st6
  bool v20; // zf
  void (__thiscall *AddVertex)(Scaleform::Render::TessBase *, float, float); // eax
  void (__thiscall *v23)(Scaleform::Render::TessBase *, float, float); // edx
  float ay; // [esp+4h] [ebp-44h]
  float by; // [esp+Ch] [ebp-3Ch]
  float v26; // [esp+10h] [ebp-38h]
  float cy; // [esp+14h] [ebp-34h]
  float v28; // [esp+18h] [ebp-30h]
  float dy; // [esp+1Ch] [ebp-2Ch]
  float epsilon; // [esp+28h] [ebp-20h]
  float epsilona; // [esp+28h] [ebp-20h]
  float x; // [esp+3Ch] [ebp-Ch] BYREF
  float v35; // [esp+40h] [ebp-8h]
  float v36; // [esp+44h] [ebp-4h]
  float v37; // [esp+4Ch] [ebp+4h]
  float v38; // [esp+4Ch] [ebp+4h]
  float v39; // [esp+4Ch] [ebp+4h]
  float v40; // [esp+4Ch] [ebp+4h]
  float v41; // [esp+4Ch] [ebp+4h]
  float v42; // [esp+50h] [ebp+8h]
  float v43; // [esp+54h] [ebp+Ch]

  if ( 0.0 == this->Width )
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))tess->AddVertex)(tess, v1->x, v1->y);
    return;
  }
  v10 = len1;
  v13 = v2;
  v14 = len2;
  v35 = (len1 + len2) * this->IntersectionEpsilon;
  v15 = v1->y - v0->y;
  len1 = this->Width * v15 / len1;
  v43 = (v0->x - v1->x) * this->Width / v10;
  v16 = *(float *)(LODWORD(v2) + 4) - v1->y;
  v42 = this->Width * v16 / len2;
  len2 = (v1->x - *(float *)LODWORD(v2)) * this->Width / len2;
  v2 = v15 * (*(float *)LODWORD(v2) - v1->x) - v16 * (v1->x - v0->x);
  if ( v2 <= 0.0 )
  {
    x = (v42 + len1) * 0.5;
    v2 = 0.5 * (len2 + v43);
    v36 = v2 * v2 + x * x;
    v36 = sqrt(v36);
    LineJoin = this->LineJoin;
    if ( (LineJoin == RoundJoin || LineJoin == BevelJoin) && this->CurveTolerance * 0.125 > this->Width - v36 )
    {
      v18 = len1;
      len1 = v1->x + len1;
      v19 = len2;
      len2 = len2 + *(float *)(LODWORD(v13) + 4);
      dy = len2;
      len2 = *(float *)LODWORD(v13) + v42;
      v28 = len2;
      len2 = v19 + v1->y;
      cy = len2;
      len2 = v42 + v1->x;
      v26 = len2;
      len2 = v1->y + v43;
      by = len2;
      len2 = v43 + v0->y;
      ay = len2;
      len2 = v18 + v0->x;
      v20 = !Scaleform::Render::Math2D::Intersection(len2, ay, len1, by, v26, cy, v28, dy, &x, &v2, v35);
      AddVertex = tess->AddVertex;
      if ( v20 )
      {
        v37 = v1->y + v43;
        ((void (__stdcall *)(_DWORD, _DWORD))AddVertex)(LODWORD(len1), LODWORD(v37));
      }
      else
      {
        ((void (__stdcall *)(_DWORD, _DWORD))AddVertex)(LODWORD(x), LODWORD(v2));
      }
    }
    else
    {
      if ( LineJoin >= MiterJoin )
      {
        if ( LineJoin <= MiterBevelJoin )
        {
          Scaleform::Render::Stroker::calcMiter(
            this,
            tess,
            v0,
            v1,
            (const Scaleform::Render::StrokeVertex *)LODWORD(v13),
            len1,
            v43,
            v42,
            len2,
            *(float *)&LineJoin,
            this->MiterLimit,
            v35,
            v36);
          return;
        }
        if ( LineJoin == RoundJoin )
        {
          Scaleform::Render::Stroker::calcArc(this, tess, v1->x, COERCE__DWORD_(v1->y), len1, v43, v42, len2, a3, a2);
          return;
        }
      }
      v23 = tess->AddVertex;
      v38 = v1->y + v43;
      epsilon = v38;
      v39 = v1->x + len1;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v23)(tess, LODWORD(v39), LODWORD(epsilon));
      v40 = v1->y + len2;
      epsilona = v40;
      v41 = v1->x + v42;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(v41),
        LODWORD(epsilona));
    }
  }
  else
  {
    if ( v14 <= v10 )
      v10 = v14;
    v2 = v10;
    v2 = v2 / this->Width;
    Scaleform::Render::Stroker::calcMiter(
      this,
      tess,
      v0,
      v1,
      (const Scaleform::Render::StrokeVertex *)LODWORD(v13),
      len1,
      v43,
      v42,
      len2,
      COERCE_FLOAT(1),
      v2,
      v35,
      0.0);
  }
}
