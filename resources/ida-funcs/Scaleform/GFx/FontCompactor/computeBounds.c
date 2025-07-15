void __thiscall Scaleform::GFx::FontCompactor::computeBounds(
        Scaleform::GFx::FontCompactor *this,
        int *x1,
        int *y1,
        int *x2,
        int *y2)
{
  unsigned int v6; // ecx
  double v7; // st7
  Scaleform::GFx::FontCompactor::ContourType *v8; // edi
  int v9; // eax
  bool v10; // cc
  unsigned int v11; // ebx
  unsigned int DataStart; // ecx
  Scaleform::GFx::FontCompactor::VertexType **Pages; // edx
  __int16 *v14; // esi
  unsigned int v15; // ecx
  Scaleform::GFx::FontCompactor::VertexType *v16; // edx
  int v17; // ecx
  int v18; // eax
  double v19; // st5
  double v20; // st4
  __int16 *v21; // edi
  double v22; // st4
  int v23; // eax
  int v24; // ebx
  int v25; // eax
  int v26; // edx
  int v27; // eax
  double v28; // st7
  double v29; // st6
  double v30; // st5
  double v31; // st5
  double v32; // st4
  __int16 v33; // dx
  double v34; // st5
  int v35; // esi
  int v36; // eax
  int v37; // ecx
  int v38; // ecx
  int v39; // eax
  float y1a; // [esp+4h] [ebp-60h]
  float y1b; // [esp+4h] [ebp-60h]
  float x2a; // [esp+8h] [ebp-5Ch]
  float x2b; // [esp+8h] [ebp-5Ch]
  float y2a; // [esp+Ch] [ebp-58h]
  float y2b; // [esp+Ch] [ebp-58h]
  float x3; // [esp+10h] [ebp-54h]
  float x3a; // [esp+10h] [ebp-54h]
  float y3; // [esp+14h] [ebp-50h]
  float y3a; // [esp+14h] [ebp-50h]
  Scaleform::GFx::FontCompactor::VertexType v50; // [esp+38h] [ebp-2Ch]
  float t; // [esp+38h] [ebp-2Ch]
  float v52; // [esp+38h] [ebp-2Ch]
  int v53; // [esp+38h] [ebp-2Ch]
  float y; // [esp+3Ch] [ebp-28h] BYREF
  float x; // [esp+40h] [ebp-24h] BYREF
  int v56; // [esp+44h] [ebp-20h]
  float v57; // [esp+48h] [ebp-1Ch]
  int v58; // [esp+4Ch] [ebp-18h]
  float v59; // [esp+50h] [ebp-14h]
  Scaleform::GFx::FontCompactor *v60; // [esp+54h] [ebp-10h]
  unsigned int v61; // [esp+58h] [ebp-Ch]
  float v62; // [esp+5Ch] [ebp-8h]
  Scaleform::GFx::FontCompactor::ContourType *v63; // [esp+60h] [ebp-4h]

  *x1 = 0x3FFF;
  *y1 = 0x3FFF;
  *x2 = -16383;
  *y2 = -16383;
  v6 = 0;
  v60 = this;
  v61 = 0;
  if ( this->TmpContours.Size )
  {
    v7 = 0.0;
    do
    {
      v8 = &this->TmpContours.Pages[v6 >> 6][v6 & 0x3F];
      v50 = this->TmpVertices.Pages[v8->DataStart >> 6][v8->DataStart & 0x3F];
      v9 = v50.x >> 1;
      v10 = v9 < *x1;
      v63 = v8;
      v56 = v50.y;
      v59 = *(float *)&v9;
      if ( v10 )
        *x1 = v9;
      if ( v50.y < *y1 )
        *y1 = v50.y;
      if ( v9 > *x2 )
        *x2 = v9;
      if ( v50.y > *y2 )
        *y2 = v50.y;
      v11 = 1;
      if ( v8->DataSize > 1 )
      {
        do
        {
          DataStart = v8->DataStart;
          Pages = this->TmpVertices.Pages;
          v14 = (__int16 *)&Pages[(v8->DataStart + v11) >> 6][(v8->DataStart + v11) & 0x3F];
          if ( (*v14 & 1) != 0 )
          {
            LODWORD(v57) = *v14 >> 1;
            v59 = (float)SLODWORD(v59);
            v15 = ++v11 + DataStart;
            v62 = v59;
            v16 = Pages[v15 >> 6];
            v17 = v15 & 0x3F;
            v18 = v16[v17].x;
            v57 = (float)SLODWORD(v57);
            v19 = v57;
            v20 = v57;
            v21 = (__int16 *)&v16[v17];
            LODWORD(v57) = v18 >> 1;
            v58 = v11;
            v62 = v20 + v20 - v59 - (double)(v18 >> 1);
            if ( v62 == v7 )
              v22 = -1.0;
            else
              v22 = (v20 - v59) / v62;
            t = v22;
            if ( t > v7 && t < 1.0 )
            {
              v23 = v21[1];
              LODWORD(v62) = v14[1];
              y3 = (float)v23;
              x3 = (float)SLODWORD(v57);
              y2a = (float)SLODWORD(v62);
              x2a = v19;
              y1a = (float)v56;
              Scaleform::Render::Math2D::PointOnQuadCurve(v59, y1a, x2a, y2a, x3, y3, t, &x, &y);
              v62 = floor(y);
              v24 = (int)(v62 + 0.5);
              v62 = floor(x);
              v25 = (int)(v62 + 0.5);
              if ( v25 < *x1 )
                *x1 = v25;
              if ( v24 < *y1 )
                *y1 = v24;
              if ( v25 > *x2 )
                *x2 = v25;
              if ( v24 > *y2 )
                *y2 = v24;
              v11 = v58;
            }
            v26 = v14[1];
            v27 = v21[1];
            v62 = (float)v56;
            v28 = v62;
            v57 = v62;
            v58 = v27;
            v62 = (float)v26;
            v29 = v62;
            v30 = v62;
            v62 = v30 + v30 - v57 - (double)v27;
            if ( v62 == 0.0 )
            {
              v31 = 0.0;
              v32 = -1.0;
            }
            else
            {
              v32 = (v30 - v57) / v62;
              v31 = 0.0;
            }
            v52 = v32;
            if ( v52 <= v31 || v52 >= 1.0 )
              goto LABEL_40;
            v33 = *v14;
            LODWORD(v62) = *v21 >> 1;
            y3a = (float)v58;
            v34 = (double)SLODWORD(v62);
            LODWORD(v62) = v33 >> 1;
            x3a = v34;
            y2b = v29;
            x2b = (float)SLODWORD(v62);
            y1b = v28;
            Scaleform::Render::Math2D::PointOnQuadCurve(v59, y1b, x2b, y2b, x3a, y3a, v52, &x, &y);
            v62 = floor(y);
            v35 = (int)(v62 + 0.5);
            v62 = floor(x);
            v36 = (int)(v62 + 0.5);
            if ( v36 < *x1 )
              *x1 = v36;
            if ( v35 < *y1 )
              *y1 = v35;
            if ( v36 > *x2 )
              *x2 = v36;
            if ( v35 <= *y2 )
            {
LABEL_40:
              v38 = *(_DWORD *)v21;
              v7 = 0.0;
              v8 = v63;
              v53 = v38;
            }
            else
            {
              v7 = 0.0;
              *y2 = v35;
              v37 = *(_DWORD *)v21;
              v8 = v63;
              v53 = v37;
            }
          }
          else
          {
            v53 = *(_DWORD *)v14;
          }
          v39 = (__int16)v53 >> 1;
          v10 = v39 < *x1;
          v56 = SHIWORD(v53);
          v59 = *(float *)&v39;
          if ( v10 )
            *x1 = v39;
          if ( SHIWORD(v53) < *y1 )
            *y1 = SHIWORD(v53);
          if ( v39 > *x2 )
            *x2 = v39;
          if ( SHIWORD(v53) > *y2 )
            *y2 = SHIWORD(v53);
          this = v60;
          ++v11;
        }
        while ( v11 < v8->DataSize );
        v6 = v61;
      }
      v61 = ++v6;
    }
    while ( v6 < this->TmpContours.Size );
  }
}
