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
  const Scaleform::Render::StrokeVertex *v13; // ebp
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
  float y; // [esp+18h] [ebp-30h]
  float v29; // [esp+1Ch] [ebp-2Ch]
  float v30; // [esp+28h] [ebp-20h]
  float v31; // [esp+28h] [ebp-20h]
  float x; // [esp+3Ch] [ebp-Ch] BYREF
  float epsilon; // [esp+40h] [ebp-8h]
  float dbevel; // [esp+44h] [ebp-4h]
  float tessa; // [esp+4Ch] [ebp+4h]
  float tessb; // [esp+4Ch] [ebp+4h]
  float tessc; // [esp+4Ch] [ebp+4h]
  float tessd; // [esp+4Ch] [ebp+4h]
  float tesse; // [esp+4Ch] [ebp+4h]
  float dx2; // [esp+50h] [ebp+8h]
  float dy1; // [esp+54h] [ebp+Ch]

  if ( 0.0 == this->Width )
  {
    ((void (__thiscall *)(_DWORD, _DWORD, _DWORD))tess->AddVertex)(tess, v1->x, v1->y);
    return;
  }
  v10 = len1;
  v13 = (const Scaleform::Render::StrokeVertex *)LODWORD(v2);
  v14 = len2;
  epsilon = (len1 + len2) * this->IntersectionEpsilon;
  v15 = v1->y - v0->y;
  len1 = this->Width * v15 / len1;
  dy1 = (v0->x - v1->x) * this->Width / v10;
  v16 = *(float *)(LODWORD(v2) + 4) - v1->y;
  dx2 = this->Width * v16 / len2;
  len2 = (v1->x - *(float *)LODWORD(v2)) * this->Width / len2;
  v2 = v15 * (*(float *)LODWORD(v2) - v1->x) - v16 * (v1->x - v0->x);
  if ( v2 <= 0.0 )
  {
    x = (dx2 + len1) * 0.5;
    v2 = 0.5 * (len2 + dy1);
    dbevel = v2 * v2 + x * x;
    dbevel = sqrt(dbevel);
    LineJoin = this->LineJoin;
    if ( (LineJoin == RoundJoin || LineJoin == BevelJoin) && this->CurveTolerance * 0.125 > this->Width - dbevel )
    {
      v18 = len1;
      len1 = v1->x + len1;
      v19 = len2;
      len2 = len2 + v13->y;
      v29 = len2;
      len2 = v13->x + dx2;
      y = len2;
      len2 = v19 + v1->y;
      cy = len2;
      len2 = dx2 + v1->x;
      v26 = len2;
      len2 = v1->y + dy1;
      by = len2;
      len2 = dy1 + v0->y;
      ay = len2;
      len2 = v18 + v0->x;
      v20 = !Scaleform::Render::Math2D::Intersection(len2, ay, len1, by, v26, cy, y, v29, &x, &v2, epsilon);
      AddVertex = tess->AddVertex;
      if ( v20 )
      {
        tessa = v1->y + dy1;
        ((void (__stdcall *)(_DWORD, _DWORD))AddVertex)(LODWORD(len1), LODWORD(tessa));
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
            v13,
            len1,
            dy1,
            dx2,
            len2,
            *(float *)&LineJoin,
            this->MiterLimit,
            epsilon,
            dbevel);
          return;
        }
        if ( LineJoin == RoundJoin )
        {
          Scaleform::Render::Stroker::calcArc(
            this,
            (int)this,
            (int)v1,
            tess,
            v1->x,
            v1->y,
            len1,
            dy1,
            dx2,
            len2,
            a3,
            a2);
          return;
        }
      }
      v23 = tess->AddVertex;
      tessb = v1->y + dy1;
      v30 = tessb;
      tessc = v1->x + len1;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v23)(tess, LODWORD(tessc), LODWORD(v30));
      tessd = v1->y + len2;
      v31 = tessd;
      tesse = v1->x + dx2;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(tesse),
        LODWORD(v31));
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
      v13,
      len1,
      dy1,
      dx2,
      len2,
      COERCE_FLOAT(1),
      v2,
      epsilon,
      0.0);
  }
}
