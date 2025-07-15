void __thiscall Scaleform::Render::Scale9GridInfo::Compute(Scaleform::Render::Scale9GridInfo *this)
{
  double v2; // st7
  double v3; // st6
  double v4; // st4
  double v5; // st3
  double v6; // st6
  double v7; // st6
  double v8; // st7
  double v9; // st5
  double v10; // st6
  double v11; // st6
  double v12; // st4
  double v13; // st3
  double v14; // st6
  double v15; // st4
  double v16; // st5
  double v17; // st3
  float v18; // [esp+8h] [ebp-108h]
  float v19; // [esp+8h] [ebp-108h]
  float v20; // [esp+Ch] [ebp-104h]
  float v21; // [esp+Ch] [ebp-104h]
  float v22; // [esp+Ch] [ebp-104h]
  float v23; // [esp+10h] [ebp-100h]
  float v24; // [esp+10h] [ebp-100h]
  float v25; // [esp+10h] [ebp-100h]
  float v26; // [esp+10h] [ebp-100h]
  float v27; // [esp+10h] [ebp-100h]
  float v28; // [esp+10h] [ebp-100h]
  double v29; // [esp+10h] [ebp-100h]
  double v30; // [esp+10h] [ebp-100h]
  float v31; // [esp+1Ch] [ebp-F4h]
  float v32; // [esp+1Ch] [ebp-F4h]
  float v33; // [esp+20h] [ebp-F0h]
  float v34; // [esp+20h] [ebp-F0h]
  float v35; // [esp+24h] [ebp-ECh] BYREF
  float v36; // [esp+28h] [ebp-E8h]
  float v37; // [esp+2Ch] [ebp-E4h]
  float v38; // [esp+30h] [ebp-E0h]
  float v39; // [esp+34h] [ebp-DCh]
  float v40; // [esp+38h] [ebp-D8h]
  float v41; // [esp+3Ch] [ebp-D4h] BYREF
  float v42; // [esp+40h] [ebp-D0h]
  float v43; // [esp+44h] [ebp-CCh]
  float v44; // [esp+48h] [ebp-C8h]
  float v45; // [esp+4Ch] [ebp-C4h]
  float v46; // [esp+50h] [ebp-C0h]
  float y1; // [esp+54h] [ebp-BCh]
  float y2; // [esp+58h] [ebp-B8h]
  float x1; // [esp+5Ch] [ebp-B4h]
  float x2; // [esp+60h] [ebp-B0h]
  float v51; // [esp+64h] [ebp-ACh]
  float v52; // [esp+68h] [ebp-A8h]
  float v53; // [esp+6Ch] [ebp-A4h]
  double v54; // [esp+70h] [ebp-A0h]
  float v55; // [esp+7Ch] [ebp-94h]
  float v56; // [esp+80h] [ebp-90h]
  float v57; // [esp+84h] [ebp-8Ch]
  float v58; // [esp+88h] [ebp-88h]
  float v59; // [esp+8Ch] [ebp-84h]
  float v60; // [esp+90h] [ebp-80h]
  float v61; // [esp+94h] [ebp-7Ch]
  double v62; // [esp+98h] [ebp-78h]
  float v63; // [esp+A4h] [ebp-6Ch]
  float v64; // [esp+A8h] [ebp-68h]
  float v65; // [esp+ACh] [ebp-64h]
  double v66; // [esp+B0h] [ebp-60h]
  float v67; // [esp+BCh] [ebp-54h]
  float v68; // [esp+C0h] [ebp-50h]
  float v69; // [esp+C4h] [ebp-4Ch]
  float v70; // [esp+C8h] [ebp-48h]
  float v71; // [esp+CCh] [ebp-44h]
  double v72; // [esp+D0h] [ebp-40h]
  float v73; // [esp+DCh] [ebp-34h]
  double v74; // [esp+E0h] [ebp-30h]
  double v75; // [esp+E8h] [ebp-28h]
  double v76; // [esp+F0h] [ebp-20h]
  double v77; // [esp+F8h] [ebp-18h]
  double v78; // [esp+100h] [ebp-10h]
  double v79; // [esp+108h] [ebp-8h]

  x1 = this->Scale9.x1;
  y1 = this->Scale9.y1;
  x2 = this->Scale9.x2;
  y2 = this->Scale9.y2;
  v53 = this->Bounds.x1;
  v57 = this->Bounds.y1;
  v52 = this->Bounds.x2;
  v51 = this->Bounds.y2;
  v2 = v53;
  v3 = x1;
  if ( x1 <= (double)v53 )
  {
    v53 = v3 - 0.8999999761581421;
    v2 = v53;
  }
  v4 = v57;
  v5 = y1;
  if ( y1 <= (double)v57 )
  {
    v57 = v5 - 0.8999999761581421;
    v4 = v57;
  }
  if ( x2 >= (double)v52 )
    v52 = v3 + 0.8999999761581421;
  v6 = v52;
  if ( y2 >= (double)v51 )
    v51 = v5 + 0.8999999761581421;
  v55 = this->S9gMatrix.M[0][1] * v4 + v2 * this->S9gMatrix.M[0][0] + this->S9gMatrix.M[0][3];
  v56 = this->S9gMatrix.M[1][1] * v4 + this->S9gMatrix.M[1][0] * v2 + this->S9gMatrix.M[1][3];
  v61 = this->S9gMatrix.M[0][1] * v4 + this->S9gMatrix.M[0][0] * v6 + this->S9gMatrix.M[0][3];
  v58 = v4 * this->S9gMatrix.M[1][1] + this->S9gMatrix.M[1][0] * v6 + this->S9gMatrix.M[1][3];
  v60 = this->S9gMatrix.M[0][1] * v51 + this->S9gMatrix.M[0][0] * v6 + this->S9gMatrix.M[0][3];
  v59 = v6 * this->S9gMatrix.M[1][0] + this->S9gMatrix.M[1][1] * v51 + this->S9gMatrix.M[1][3];
  v67 = this->S9gMatrix.M[0][1] * v51 + this->S9gMatrix.M[0][0] * v2 + this->S9gMatrix.M[0][3];
  v64 = v2 * this->S9gMatrix.M[1][0] + v51 * this->S9gMatrix.M[1][1] + this->S9gMatrix.M[1][3];
  *(float *)&v62 = v61 - v55;
  v23 = v58 - v56;
  v24 = v23 * v23 + *(float *)&v62 * *(float *)&v62;
  v25 = sqrt(v24);
  v20 = v25;
  *(float *)&v62 = v60 - v61;
  v26 = v59 - v58;
  v27 = v26 * v26 + *(float *)&v62 * *(float *)&v62;
  v28 = sqrt(v27);
  v7 = v20;
  if ( v20 == 0.0 )
    v7 = (float)0.001;
  v8 = v28;
  if ( v28 == 0.0 )
    v8 = (float)0.001;
  v18 = (x1 - v53) / v7;
  v33 = (y1 - v57) / v8;
  v21 = (v52 - x2) / v7;
  v31 = (v51 - y2) / v8;
  v9 = v18;
  *(float *)&v54 = v21 + v18;
  if ( *(float *)&v54 <= 1.0 )
  {
    v10 = 0.05000000074505806;
  }
  else
  {
    *(float *)&v54 = *(float *)&v54 + 0.05000000074505806;
    v18 = v9 / *(float *)&v54;
    v10 = 0.05000000074505806;
    v21 = v21 / *(float *)&v54;
    v9 = v18;
  }
  *(float *)&v54 = v31 + v33;
  if ( *(float *)&v54 <= 1.0 )
  {
    v11 = v9;
  }
  else
  {
    *(float *)&v54 = v10 + *(float *)&v54;
    v33 = v33 / *(float *)&v54;
    v11 = v9;
    v31 = v31 / *(float *)&v54;
  }
  v12 = v61 - v55;
  v13 = v11;
  v14 = v55;
  v66 = v13 * v12;
  v69 = v66 + v55;
  v29 = v58 - v56;
  v72 = v29 * v18;
  v70 = v72 + v56;
  v54 = v12 * v21;
  v68 = v61 - v54;
  v15 = v56;
  v76 = v21 * v29;
  v71 = v58 - v76;
  v30 = v60 - v61;
  v65 = v61 + v30 * v33;
  v62 = v59 - v58;
  v63 = v58 + v62 * v33;
  v56 = v60 - v31 * v30;
  v55 = v59 - v31 * v62;
  v75 = v67 - v14;
  *(float *)&v62 = v67 - v75 * v31;
  v74 = v64 - v15;
  *(float *)&v30 = v64 - v74 * v31;
  v73 = v33 * v75 + v14;
  *(float *)&v75 = v33 * v74 + v15;
  v34 = v73 + v66;
  v32 = *(float *)&v75 + v72;
  *(float *)&v54 = v65 - v54;
  *(float *)&v72 = v63 - v76;
  v16 = v60 - v67;
  v79 = v21 * v16;
  *(float *)&v66 = v56 - v79;
  v17 = v59 - v64;
  v78 = v21 * v17;
  *(float *)&v74 = v55 - v78;
  v76 = v16 * v18;
  v22 = v76 + *(float *)&v62;
  v77 = v18 * v17;
  v19 = v77 + *(float *)&v30;
  v41 = v14;
  v42 = v15;
  v43 = v69;
  v44 = v70;
  v45 = v34;
  v46 = v32;
  v35 = v53;
  v36 = v57;
  v37 = x1;
  v39 = x1;
  v38 = v57;
  v40 = y1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(this->ResultingMatrices, &v35, &v41);
  v41 = v69;
  v42 = v70;
  v43 = v68;
  v44 = v71;
  v45 = *(float *)&v54;
  v46 = *(float *)&v72;
  v35 = x1;
  v36 = v57;
  v37 = x2;
  v39 = x2;
  v38 = v57;
  v40 = y1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[1], &v35, &v41);
  v41 = v68;
  v42 = v71;
  v43 = v61;
  v44 = v58;
  v45 = v65;
  v46 = v63;
  v35 = x2;
  v36 = v57;
  v37 = v52;
  v39 = v52;
  v38 = v57;
  v40 = y1;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[2], &v35, &v41);
  v41 = v73;
  v42 = *(float *)&v75;
  v43 = v34;
  v44 = v32;
  v45 = v22;
  v46 = v19;
  v35 = v53;
  v36 = y1;
  v37 = x1;
  v39 = x1;
  v38 = y1;
  v40 = y2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[3], &v35, &v41);
  v41 = v34;
  v42 = v32;
  v43 = *(float *)&v54;
  v44 = *(float *)&v72;
  v45 = *(float *)&v66;
  v46 = *(float *)&v74;
  v35 = x1;
  v36 = y1;
  v37 = x2;
  v39 = x2;
  v38 = y1;
  v40 = y2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[4], &v35, &v41);
  v41 = *(float *)&v54;
  v42 = *(float *)&v72;
  v43 = v65;
  v44 = v63;
  v45 = v56;
  v46 = v55;
  v35 = x2;
  v36 = y1;
  v37 = v52;
  v39 = v52;
  v38 = y1;
  v40 = y2;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[5], &v35, &v41);
  v41 = *(float *)&v62;
  v42 = *(float *)&v30;
  v43 = v22;
  v44 = v19;
  v45 = v67 + v76;
  v46 = v64 + v77;
  v35 = v53;
  v36 = y2;
  v37 = x1;
  v39 = x1;
  v38 = y2;
  v40 = v51;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[6], &v35, &v41);
  v41 = v22;
  v42 = v19;
  v43 = *(float *)&v66;
  v44 = *(float *)&v74;
  v45 = v60 - v79;
  v46 = v59 - v78;
  v35 = x1;
  v36 = y2;
  v37 = x2;
  v39 = x2;
  v38 = y2;
  v40 = v51;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[7], &v35, &v41);
  v41 = *(float *)&v66;
  v42 = *(float *)&v74;
  v43 = v56;
  v44 = v55;
  v45 = v60;
  v46 = v59;
  v35 = x2;
  v36 = y2;
  v37 = v52;
  v39 = v52;
  v38 = y2;
  v40 = v51;
  Scaleform::Render::Matrix2x4<float>::SetParlToParl(&this->ResultingMatrices[8], &v35, &v41);
  this->ResultingGrid.x1 = x1;
  this->ResultingGrid.y1 = y1;
  this->ResultingGrid.x2 = x2;
  this->ResultingGrid.y2 = y2;
}
