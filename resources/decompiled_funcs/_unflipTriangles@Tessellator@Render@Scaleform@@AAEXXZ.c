void __thiscall Scaleform::Render::Tessellator::unflipTriangles(Scaleform::Render::Tessellator *this)
{
  double v1; // st7
  unsigned int v2; // ebp
  Scaleform::Render::Tessellator::TriangleType **Pages; // esi
  Scaleform::Render::TessVertex **v4; // ecx
  Scaleform::Render::Tessellator::TriangleType *v5; // edx
  Scaleform::Render::Tessellator::MonoVertexType *v6; // edi
  Scaleform::Render::Tessellator::TriangleType *v7; // esi
  Scaleform::Render::Tessellator::MonoVertexType *v8; // ebx
  Scaleform::Render::Tessellator::MonoVertexType *v9; // edx
  float *p_x; // edi
  Scaleform::Render::TessVertex *v11; // esi
  double v12; // st6
  float *v13; // esi
  double v14; // st6
  float *v15; // ebx
  double v16; // st5
  double v17; // st4
  double v18; // st3
  int v19; // eax
  int v20; // eax
  int v21; // eax
  float *v22; // edx
  double v23; // st7
  double v24; // st6
  double v25; // st3
  double v26; // st5
  float *v27; // ecx
  double v28; // st7
  double v29; // st6
  double v30; // st3
  double v31; // st5
  double v32; // st7
  double v33; // st6
  double v34; // st3
  double v35; // st5
  double v36; // st7
  bool wasFlipped; // [esp+17h] [ebp-61h]
  const Scaleform::Render::TessVertex *refV2; // [esp+18h] [ebp-60h]
  const Scaleform::Render::TessVertex *refV1; // [esp+1Ch] [ebp-5Ch]
  float xa; // [esp+20h] [ebp-58h]
  float xb; // [esp+20h] [ebp-58h]
  float xc; // [esp+20h] [ebp-58h]
  float x; // [esp+20h] [ebp-58h]
  float xd; // [esp+20h] [ebp-58h]
  float xe; // [esp+20h] [ebp-58h]
  float xf; // [esp+20h] [ebp-58h]
  float ya; // [esp+24h] [ebp-54h]
  float yb; // [esp+24h] [ebp-54h]
  float y; // [esp+24h] [ebp-54h]
  float yc; // [esp+24h] [ebp-54h]
  float yd; // [esp+24h] [ebp-54h]
  float ye; // [esp+24h] [ebp-54h]
  int v53; // [esp+28h] [ebp-50h]
  Scaleform::Render::Tessellator *v54; // [esp+2Ch] [ebp-4Ch]
  unsigned int pass; // [esp+30h] [ebp-48h]
  float d1a; // [esp+34h] [ebp-44h]
  float d1; // [esp+34h] [ebp-44h]
  float d2a; // [esp+38h] [ebp-40h]
  float d2b; // [esp+38h] [ebp-40h]
  float d2c; // [esp+38h] [ebp-40h]
  float d2; // [esp+38h] [ebp-40h]
  float d2d; // [esp+38h] [ebp-40h]
  float d2e; // [esp+38h] [ebp-40h]
  float d2f; // [esp+38h] [ebp-40h]
  float d2g; // [esp+38h] [ebp-40h]
  float d2h; // [esp+38h] [ebp-40h]
  float d2i; // [esp+38h] [ebp-40h]
  float d2j; // [esp+38h] [ebp-40h]
  float d2k; // [esp+38h] [ebp-40h]
  float d2l; // [esp+38h] [ebp-40h]
  float d2m; // [esp+38h] [ebp-40h]
  float d2n; // [esp+38h] [ebp-40h]
  float d2o; // [esp+38h] [ebp-40h]
  float d2p; // [esp+38h] [ebp-40h]
  const Scaleform::Render::TessVertex *refV3; // [esp+3Ch] [ebp-3Ch]
  unsigned int i; // [esp+40h] [ebp-38h]
  unsigned int nt; // [esp+44h] [ebp-34h]
  double v78; // [esp+48h] [ebp-30h]
  double v79; // [esp+50h] [ebp-28h]
  double v80; // [esp+68h] [ebp-10h]
  double v81; // [esp+70h] [ebp-8h]

  v1 = 0.0;
  v54 = this;
  for ( pass = 0; pass < 8; ++pass )
  {
    wasFlipped = 0;
    i = 0;
    if ( this->MeshTriangles.NumArrays )
    {
      v53 = 0;
      while ( 1 )
      {
        v2 = 0;
        nt = this->MeshTriangles.Arrays[v53].Size;
        if ( nt )
          break;
LABEL_37:
        ++v53;
        if ( ++i >= this->MeshTriangles.NumArrays )
          goto LABEL_38;
      }
      while ( 2 )
      {
        Pages = this->MeshTriangles.Arrays[v53].Pages;
        v4 = this->MeshVertices.Pages;
        v5 = Pages[v2 >> 4];
        v6 = v5[v2 & 0xF].d.m.v1;
        v7 = &v5[v2 & 0xF];
        v8 = v7->d.m.v2;
        refV1 = &v4[(v6->srcVer & 0xFFFFFFF) >> 4][v6->srcVer & 0xF];
        v9 = v7->d.m.v3;
        refV2 = &v4[(v8->srcVer & 0xFFFFFFF) >> 4][v8->srcVer & 0xF];
        refV3 = &v4[(v9->srcVer & 0xFFFFFFF) >> 4][v9->srcVer & 0xF];
        p_x = &v4[(v6->aaVer & 0xFFFFFFF) >> 4][v6->aaVer & 0xF].x;
        v11 = v4[(v8->aaVer & 0xFFFFFFF) >> 4];
        v12 = v11[v8->aaVer & 0xF].y;
        v13 = &v11[v8->aaVer & 0xF].x;
        v14 = v12 - p_x[1];
        v80 = v14;
        v15 = &v4[(v9->aaVer & 0xFFFFFFF) >> 4][v9->aaVer & 0xF].x;
        v16 = *v15 - *v13;
        v17 = v15[1] - v13[1];
        v18 = *v13 - *p_x;
        v81 = v18;
        d2a = v16 * v14 - v18 * v17;
        if ( d2a >= v1 )
        {
          d1a = v18;
          d2b = v14;
          d1 = d2b * d2b + d1a * d1a;
          ya = v16;
          d2c = v17;
          d2 = d2c * d2c + ya * ya;
          v79 = *p_x - *v15;
          xa = v79;
          v78 = p_x[1] - v15[1];
          yb = v78;
          y = yb * yb + xa * xa;
          xb = d2 + d1 + y;
          xc = sqrt(xb);
          x = xc * v54->IntersectionEpsilon;
          if ( d2 >= (double)d1 )
          {
            v19 = 2;
            if ( y >= (double)d2 )
              goto LABEL_11;
          }
          else
          {
            if ( y < (double)d1 )
            {
              v19 = 1;
              goto LABEL_12;
            }
LABEL_11:
            v19 = 3;
          }
LABEL_12:
          v20 = v19 - 1;
          if ( v20 )
          {
            v21 = v20 - 1;
            if ( v21 )
            {
              v22 = &refV2->x;
              if ( v21 == 1 )
              {
                v23 = refV2->x - *v13;
                v24 = refV2->y - v13[1];
                d2d = v23 * v78 - v24 * v79;
                v25 = d2d;
                d2e = fabs(d2d);
                if ( x > (double)d2e )
                {
                  *v13 = refV2->x;
                  v13[1] = refV2->y;
                }
                else
                {
                  d2f = v79 * (v13[1] - v15[1]) - v78 * (*v13 - *v15);
                  d2g = d2f / v25;
                  v26 = d2g;
                  if ( d2g <= 0.0 || v26 >= 1.0 )
                  {
                    *v13 = refV2->x;
                    v13[1] = refV2->y;
                  }
                  else
                  {
                    xd = v23 * v26 + *v13;
                    yc = v26 * v24 + v13[1];
                    *v13 = xd + (refV2->x - xd) * 0.125;
                    v13[1] = 0.125 * (refV2->y - yc) + yc;
                  }
                }
              }
              goto LABEL_32;
            }
            v27 = &refV1->x;
            v28 = refV1->x - *p_x;
            v29 = refV1->y - p_x[1];
            d2h = v28 * v17 - v29 * v16;
            v30 = d2h;
            d2i = fabs(d2h);
            if ( x > (double)d2i
              || (d2j = v16 * (p_x[1] - v13[1]) - v17 * (*p_x - *v13), d2k = d2j / v30, v31 = d2k, d2k <= 0.0)
              || v31 >= 1.0 )
            {
              v22 = &refV2->x;
              *p_x = refV1->x;
              p_x[1] = refV1->y;
            }
            else
            {
              v22 = &refV2->x;
              xe = v28 * v31 + *p_x;
              yd = v31 * v29 + p_x[1];
              *p_x = xe + (refV1->x - xe) * 0.125;
              p_x[1] = 0.125 * (refV1->y - yd) + yd;
            }
          }
          else
          {
            v32 = refV3->x - *v15;
            v33 = refV3->y - v15[1];
            d2l = v32 * v80 - v33 * v18;
            v34 = d2l;
            d2m = fabs(d2l);
            if ( x > (double)d2m
              || (d2n = v81 * (v15[1] - p_x[1]) - v80 * (*v15 - *p_x), d2o = d2n / v34, v35 = d2o, d2o <= 0.0)
              || v35 >= 1.0 )
            {
              *v15 = refV3->x;
              v36 = refV3->y;
            }
            else
            {
              xf = v32 * v35 + *v15;
              ye = v35 * v33 + v15[1];
              *v15 = xf + (refV3->x - xf) * 0.125;
              v36 = 0.125 * (refV3->y - ye) + ye;
            }
            v22 = &refV2->x;
            v15[1] = v36;
LABEL_32:
            v27 = &refV1->x;
          }
          d2p = (v13[1] - p_x[1]) * (*v15 - *v13) - (v15[1] - v13[1]) * (*v13 - *p_x);
          v1 = 0.0;
          if ( d2p >= 0.0 )
          {
            *p_x = *v27;
            p_x[1] = v27[1];
            *v13 = *v22;
            v13[1] = v22[1];
            *v15 = refV3->x;
            v15[1] = refV3->y;
          }
          wasFlipped = 1;
        }
        this = v54;
        if ( ++v2 >= nt )
          goto LABEL_37;
        continue;
      }
    }
LABEL_38:
    if ( !wasFlipped )
      return;
  }
}
