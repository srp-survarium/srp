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
  float *v10; // edi
  Scaleform::Render::TessVertex *v11; // esi
  double y; // st6
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
  char v37; // [esp+17h] [ebp-61h]
  float *v38; // [esp+18h] [ebp-60h]
  float *p_x; // [esp+1Ch] [ebp-5Ch]
  float v40; // [esp+20h] [ebp-58h]
  float v41; // [esp+20h] [ebp-58h]
  float v42; // [esp+20h] [ebp-58h]
  float v43; // [esp+20h] [ebp-58h]
  float v44; // [esp+20h] [ebp-58h]
  float v45; // [esp+20h] [ebp-58h]
  float v46; // [esp+20h] [ebp-58h]
  float v47; // [esp+24h] [ebp-54h]
  float v48; // [esp+24h] [ebp-54h]
  float v49; // [esp+24h] [ebp-54h]
  float v50; // [esp+24h] [ebp-54h]
  float v51; // [esp+24h] [ebp-54h]
  float v52; // [esp+24h] [ebp-54h]
  int v53; // [esp+28h] [ebp-50h]
  Scaleform::Render::Tessellator *v54; // [esp+2Ch] [ebp-4Ch]
  unsigned int i; // [esp+30h] [ebp-48h]
  float v56; // [esp+34h] [ebp-44h]
  float v57; // [esp+34h] [ebp-44h]
  float v58; // [esp+38h] [ebp-40h]
  float v59; // [esp+38h] [ebp-40h]
  float v60; // [esp+38h] [ebp-40h]
  float v61; // [esp+38h] [ebp-40h]
  float v62; // [esp+38h] [ebp-40h]
  float v63; // [esp+38h] [ebp-40h]
  float v64; // [esp+38h] [ebp-40h]
  float v65; // [esp+38h] [ebp-40h]
  float v66; // [esp+38h] [ebp-40h]
  float v67; // [esp+38h] [ebp-40h]
  float v68; // [esp+38h] [ebp-40h]
  float v69; // [esp+38h] [ebp-40h]
  float v70; // [esp+38h] [ebp-40h]
  float v71; // [esp+38h] [ebp-40h]
  float v72; // [esp+38h] [ebp-40h]
  float v73; // [esp+38h] [ebp-40h]
  float v74; // [esp+38h] [ebp-40h]
  float *v75; // [esp+3Ch] [ebp-3Ch]
  int v76; // [esp+40h] [ebp-38h]
  unsigned int Size; // [esp+44h] [ebp-34h]
  double v78; // [esp+48h] [ebp-30h]
  double v79; // [esp+50h] [ebp-28h]
  double v80; // [esp+68h] [ebp-10h]
  double v81; // [esp+70h] [ebp-8h]

  v1 = 0.0;
  v54 = this;
  for ( i = 0; i < 8; ++i )
  {
    v37 = 0;
    v76 = 0;
    if ( this->MeshTriangles.NumArrays )
    {
      v53 = 0;
      while ( 1 )
      {
        v2 = 0;
        Size = this->MeshTriangles.Arrays[v53].Size;
        if ( Size )
          break;
LABEL_37:
        ++v53;
        if ( ++v76 >= this->MeshTriangles.NumArrays )
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
        p_x = &v4[(v6->srcVer & 0xFFFFFFF) >> 4][v6->srcVer & 0xF].x;
        v9 = v7->d.m.v3;
        v38 = &v4[(v8->srcVer & 0xFFFFFFF) >> 4][v8->srcVer & 0xF].x;
        v75 = &v4[(v9->srcVer & 0xFFFFFFF) >> 4][v9->srcVer & 0xF].x;
        v10 = &v4[(v6->aaVer & 0xFFFFFFF) >> 4][v6->aaVer & 0xF].x;
        v11 = v4[(v8->aaVer & 0xFFFFFFF) >> 4];
        y = v11[v8->aaVer & 0xF].y;
        v13 = &v11[v8->aaVer & 0xF].x;
        v14 = y - v10[1];
        v80 = v14;
        v15 = &v4[(v9->aaVer & 0xFFFFFFF) >> 4][v9->aaVer & 0xF].x;
        v16 = *v15 - *v13;
        v17 = v15[1] - v13[1];
        v18 = *v13 - *v10;
        v81 = v18;
        v58 = v16 * v14 - v18 * v17;
        if ( v58 >= v1 )
        {
          v56 = v18;
          v59 = v14;
          v57 = v59 * v59 + v56 * v56;
          v47 = v16;
          v60 = v17;
          v61 = v60 * v60 + v47 * v47;
          v79 = *v10 - *v15;
          v40 = v79;
          v78 = v10[1] - v15[1];
          v48 = v78;
          v49 = v48 * v48 + v40 * v40;
          v41 = v61 + v57 + v49;
          v42 = sqrt(v41);
          v43 = v42 * v54->IntersectionEpsilon;
          if ( v61 >= (double)v57 )
          {
            v19 = 2;
            if ( v49 >= (double)v61 )
              goto LABEL_11;
          }
          else
          {
            if ( v49 < (double)v57 )
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
              v22 = v38;
              if ( v21 == 1 )
              {
                v23 = *v38 - *v13;
                v24 = v38[1] - v13[1];
                v62 = v23 * v78 - v24 * v79;
                v25 = v62;
                v63 = fabs(v62);
                if ( v43 > (double)v63 )
                {
                  *v13 = *v38;
                  v13[1] = v38[1];
                }
                else
                {
                  v64 = v79 * (v13[1] - v15[1]) - v78 * (*v13 - *v15);
                  v65 = v64 / v25;
                  v26 = v65;
                  if ( v65 <= 0.0 || v26 >= 1.0 )
                  {
                    *v13 = *v38;
                    v13[1] = v38[1];
                  }
                  else
                  {
                    v44 = v23 * v26 + *v13;
                    v50 = v26 * v24 + v13[1];
                    *v13 = v44 + (*v38 - v44) * 0.125;
                    v13[1] = 0.125 * (v38[1] - v50) + v50;
                  }
                }
              }
              goto LABEL_32;
            }
            v27 = p_x;
            v28 = *p_x - *v10;
            v29 = p_x[1] - v10[1];
            v66 = v28 * v17 - v29 * v16;
            v30 = v66;
            v67 = fabs(v66);
            if ( v43 > (double)v67
              || (v68 = v16 * (v10[1] - v13[1]) - v17 * (*v10 - *v13), v69 = v68 / v30, v31 = v69, v69 <= 0.0)
              || v31 >= 1.0 )
            {
              v22 = v38;
              *v10 = *p_x;
              v10[1] = p_x[1];
            }
            else
            {
              v22 = v38;
              v45 = v28 * v31 + *v10;
              v51 = v31 * v29 + v10[1];
              *v10 = v45 + (*p_x - v45) * 0.125;
              v10[1] = 0.125 * (p_x[1] - v51) + v51;
            }
          }
          else
          {
            v32 = *v75 - *v15;
            v33 = v75[1] - v15[1];
            v70 = v32 * v80 - v33 * v18;
            v34 = v70;
            v71 = fabs(v70);
            if ( v43 > (double)v71
              || (v72 = v81 * (v15[1] - v10[1]) - v80 * (*v15 - *v10), v73 = v72 / v34, v35 = v73, v73 <= 0.0)
              || v35 >= 1.0 )
            {
              *v15 = *v75;
              v36 = v75[1];
            }
            else
            {
              v46 = v32 * v35 + *v15;
              v52 = v35 * v33 + v15[1];
              *v15 = v46 + (*v75 - v46) * 0.125;
              v36 = 0.125 * (v75[1] - v52) + v52;
            }
            v22 = v38;
            v15[1] = v36;
LABEL_32:
            v27 = p_x;
          }
          v74 = (v13[1] - v10[1]) * (*v15 - *v13) - (v15[1] - v13[1]) * (*v13 - *v10);
          v1 = 0.0;
          if ( v74 >= 0.0 )
          {
            *v10 = *v27;
            v10[1] = v27[1];
            *v13 = *v22;
            v13[1] = v22[1];
            *v15 = *v75;
            v15[1] = v75[1];
          }
          v37 = 1;
        }
        this = v54;
        if ( ++v2 >= Size )
          goto LABEL_37;
        continue;
      }
    }
LABEL_38:
    if ( !v37 )
      return;
  }
}
