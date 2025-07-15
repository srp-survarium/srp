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
  float epsilona; // [esp+28h] [ebp-28h]
  float epsilonb; // [esp+28h] [ebp-28h]
  float epsilonc; // [esp+28h] [ebp-28h]
  float v32; // [esp+2Ch] [ebp-24h]
  float v33; // [esp+30h] [ebp-20h]
  float v34; // [esp+40h] [ebp-10h]
  float v35; // [esp+40h] [ebp-10h]
  float y; // [esp+44h] [ebp-Ch] BYREF
  float x; // [esp+48h] [ebp-8h] BYREF
  float v38; // [esp+4Ch] [ebp-4h]
  float retaddr; // [esp+50h] [ebp+0h]
  float v40; // [esp+54h] [ebp+4h]
  float v41; // [esp+54h] [ebp+4h]
  float v42; // [esp+54h] [ebp+4h]
  float v43; // [esp+58h] [ebp+8h]
  float v44; // [esp+58h] [ebp+8h]
  float v45; // [esp+58h] [ebp+8h]
  float v46; // [esp+58h] [ebp+8h]
  float v47; // [esp+58h] [ebp+8h]
  float v48; // [esp+58h] [ebp+8h]
  float v49; // [esp+58h] [ebp+8h]
  float v50; // [esp+60h] [ebp+10h]
  float v51; // [esp+60h] [ebp+10h]
  float v52; // [esp+64h] [ebp+14h]
  float v53; // [esp+64h] [ebp+14h]
  float v54; // [esp+64h] [ebp+14h]
  float v55; // [esp+64h] [ebp+14h]
  float v56; // [esp+64h] [ebp+14h]
  float v57; // [esp+68h] [ebp+18h]
  float v58; // [esp+68h] [ebp+18h]
  float v59; // [esp+70h] [ebp+20h]
  float v60; // [esp+70h] [ebp+20h]
  float v61; // [esp+78h] [ebp+28h]
  float v62; // [esp+78h] [ebp+28h]
  float v63; // [esp+78h] [ebp+28h]
  float v64; // [esp+78h] [ebp+28h]
  float v65; // [esp+78h] [ebp+28h]

  x = v1->x;
  y = v1->y;
  v34 = 1.0;
  v38 = this->Width * miterLimit;
  v50 = v1->x + dx1;
  v43 = dy2 + v2->y;
  dy = v43;
  v44 = v2->x + dx2;
  v27 = v44;
  v45 = dy2 + v1->y;
  cy = v45;
  v46 = dx2 + v1->x;
  v25 = v46;
  v47 = v1->y + dy1;
  by = v47;
  v48 = dy1 + v0->y;
  ay = v48;
  v49 = dx1 + v0->x;
  if ( Scaleform::Render::Math2D::Intersection(v49, ay, v50, by, v25, cy, v27, dy, &x, &y, epsilon) )
  {
    v51 = x - v1->x;
    v40 = y - v1->y;
    v41 = v40 * v40 + v51 * v51;
    v42 = sqrt(v41);
    v34 = v42;
    if ( v38 < (double)v42 )
    {
      v16 = 1;
    }
    else
    {
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(x),
        LODWORD(y));
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
    v57 = v1->y + dy1;
    if ( (v0->x - v50) * v18 - (v0->y - v57) * dx1 < 0.0 != (v2->x - v50) * v18 - (v2->y - v57) * dx1 < 0.0 )
    {
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
        tess,
        LODWORD(v50),
        LODWORD(v57));
      return;
    }
    v17 = 1;
    v19 = dx1;
  }
  v20 = tess->__vftable;
  if ( LODWORD(lineJoin) == 1 )
  {
    v55 = v18 + v1->y;
    epsilonc = v55;
    v56 = v19 + v1->x;
    ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v20->AddVertex)(
      tess,
      LODWORD(v56),
      LODWORD(epsilonc));
    v64 = v1->y + miterLimit;
    v33 = v64;
    v65 = v1->x + COERCE_FLOAT(1);
    v22 = v65;
  }
  else
  {
    if ( v17 )
    {
      v52 = v19 * miterLimit + v1->y + v18;
      epsilona = v52;
      v53 = v19 + v1->x - v18 * miterLimit;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v20->AddVertex)(
        tess,
        LODWORD(v53),
        LODWORD(epsilona));
      v21 = miterLimit;
      v61 = v1->y + miterLimit - lineJoin * dbevel;
      v33 = v61;
      v62 = dbevel * v21 + lineJoin + v1->x;
    }
    else
    {
      v58 = v19 + v1->x;
      v54 = v18 + v1->y;
      v35 = (v38 - dbevel) / (v34 - dbevel);
      v59 = v54 + (y - v54) * v35;
      epsilonb = v59;
      v60 = v35 * (x - v58) + v58;
      ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))v20->AddVertex)(
        tess,
        LODWORD(v60),
        LODWORD(epsilonb));
      v63 = lineJoin + (v38 - lineJoin) * x;
      v33 = v63;
      v62 = x * (retaddr - dbevel) + dbevel;
    }
    v22 = v62;
  }
  v32 = v22;
  ((void (__thiscall *)(Scaleform::Render::TessBase *, _DWORD, _DWORD))tess->AddVertex)(
    tess,
    LODWORD(v32),
    LODWORD(v33));
}
