void __thiscall Scaleform::Render::Stroker::calcMiter(
        Scaleform::Render::Stroker *this,
        Scaleform::Render::TessBase *tess,
        const Scaleform::Render::StrokeVertex *v0,
        const Scaleform::Render::StrokeVertex *v1,
        const Scaleform::Render::StrokeVertex *v2,
        float dx1,
        float dy1,
        float dx2,
        float dy2,
        float lineJoin,
        float miterLimit,
        float epsilon,
        float dbevel)
{
  char v16; // al
  char v17; // cl
  double v18; // st7
  double v19; // st6
  Scaleform::Render::TessBase_vtbl *v20; // edx
  double v21; // st6
  double v22; // st7
  float ay; // [esp+4h] [ebp-4Ch]
  float by; // [esp+Ch] [ebp-44h]
  float v25; // [esp+10h] [ebp-40h]
  float cy; // [esp+14h] [ebp-3Ch]
  float v27; // [esp+18h] [ebp-38h]
  float dy; // [esp+1Ch] [ebp-34h]
  float v29; // [esp+28h] [ebp-28h]
  float v30; // [esp+28h] [ebp-28h]
  float v31; // [esp+28h] [ebp-28h]
  float v32; // [esp+2Ch] [ebp-24h]
  float v33; // [esp+30h] [ebp-20h]
  float v34; // [esp+40h] [ebp-10h]
  float v35; // [esp+40h] [ebp-10h]
  float yi; // [esp+44h] [ebp-Ch] BYREF
  float xi; // [esp+48h] [ebp-8h] BYREF
  float lim; // [esp+4Ch] [ebp-4h]
  float retaddr; // [esp+50h] [ebp+0h]
  float tessa; // [esp+54h] [ebp+4h]
  float tessb; // [esp+54h] [ebp+4h]
  float tessc; // [esp+54h] [ebp+4h]
  float v0a; // [esp+58h] [ebp+8h]
  float v0b; // [esp+58h] [ebp+8h]
  float v0c; // [esp+58h] [ebp+8h]
  float v0d; // [esp+58h] [ebp+8h]
  float v0e; // [esp+58h] [ebp+8h]
  float v0f; // [esp+58h] [ebp+8h]
  float v0g; // [esp+58h] [ebp+8h]
  float v2a; // [esp+60h] [ebp+10h]
  float v2b; // [esp+60h] [ebp+10h]
  float y1; // [esp+64h] [ebp+14h]
  float y1a; // [esp+64h] [ebp+14h]
  float y1b; // [esp+64h] [ebp+14h]
  float y1c; // [esp+64h] [ebp+14h]
  float y1d; // [esp+64h] [ebp+14h]
  float x1; // [esp+68h] [ebp+18h]
  float x1a; // [esp+68h] [ebp+18h]
  float dy2a; // [esp+70h] [ebp+20h]
  float dy2b; // [esp+70h] [ebp+20h]
  float miterLimitb; // [esp+78h] [ebp+28h]
  float miterLimita; // [esp+78h] [ebp+28h]
  float miterLimitc; // [esp+78h] [ebp+28h]
  float miterLimitd; // [esp+78h] [ebp+28h]
  float miterLimite; // [esp+78h] [ebp+28h]

  xi = v1->x;
  yi = v1->y;
  v34 = 1.0;
  lim = this->Width * miterLimit;
  v2a = v1->x + dx1;
  v0a = dy2 + v2->y;
  dy = v0a;
  v0b = v2->x + dx2;
  v27 = v0b;
  v0c = dy2 + v1->y;
  cy = v0c;
  v0d = dx2 + v1->x;
  v25 = v0d;
  v0e = v1->y + dy1;
  by = v0e;
  v0f = dy1 + v0->y;
  ay = v0f;
  v0g = dx1 + v0->x;
  if ( Scaleform::Render::Math2D::Intersection(v0g, ay, v2a, by, v25, cy, v27, dy, &xi, &yi, epsilon) )
  {
    v2b = xi - v1->x;
    tessa = yi - v1->y;
    tessb = tessa * tessa + v2b * v2b;
    tessc = sqrt(tessb);
    v34 = tessc;
    if ( lim < (double)tessc )
    {
      v16 = 1;
    }
    else
    {
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(xi),
        LODWORD(yi));
      v16 = 0;
    }
    v17 = 0;
    if ( !v16 )
      return;
    v18 = dy1;
    v19 = dx1;
  }
  else
  {
    v18 = dy1;
    x1 = v1->y + dy1;
    if ( (v0->x - v2a) * v18 - (v0->y - x1) * dx1 < 0.0 != (v2->x - v2a) * v18 - (v2->y - x1) * dx1 < 0.0 )
    {
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(v2a),
        LODWORD(x1));
      return;
    }
    v17 = 1;
    v19 = dx1;
  }
  v20 = tess->__vftable;
  if ( LODWORD(lineJoin) == 1 )
  {
    y1c = v18 + v1->y;
    v31 = y1c;
    y1d = v19 + v1->x;
    ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v20->AddVertex)(
      tess,
      LODWORD(y1d),
      LODWORD(v31));
    miterLimitd = v1->y + miterLimit;
    v33 = miterLimitd;
    miterLimite = v1->x + COERCE_FLOAT(1);
    v22 = miterLimite;
  }
  else
  {
    if ( v17 )
    {
      y1 = v19 * miterLimit + v1->y + v18;
      v29 = y1;
      y1a = v19 + v1->x - v18 * miterLimit;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v20->AddVertex)(
        tess,
        LODWORD(y1a),
        LODWORD(v29));
      v21 = miterLimit;
      miterLimitb = v1->y + miterLimit - lineJoin * dbevel;
      v33 = miterLimitb;
      miterLimita = dbevel * v21 + lineJoin + v1->x;
    }
    else
    {
      x1a = v19 + v1->x;
      y1b = v18 + v1->y;
      v35 = (lim - dbevel) / (v34 - dbevel);
      dy2a = y1b + (yi - y1b) * v35;
      v30 = dy2a;
      dy2b = v35 * (xi - x1a) + x1a;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v20->AddVertex)(
        tess,
        LODWORD(dy2b),
        LODWORD(v30));
      miterLimitc = lineJoin + (lim - lineJoin) * xi;
      v33 = miterLimitc;
      miterLimita = xi * (retaddr - dbevel) + dbevel;
    }
    v22 = miterLimita;
  }
  v32 = v22;
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
    tess,
    LODWORD(v32),
    LODWORD(v33));
}
