unsigned int __thiscall Scaleform::Render::GradientData::CalcImageSize(Scaleform::Render::GradientData *this)
{
  Scaleform::Render::GradientData *v1; // edx
  unsigned int RecordCount; // ebp
  unsigned int v3; // ecx
  Scaleform::Render::GradientRecord *pRecords; // eax
  unsigned int v5; // ebx
  unsigned __int8 *p_Red; // edi
  unsigned __int8 *p_Green; // esi
  double v8; // st6
  double v9; // st5
  __int64 v10; // rax
  __int64 v11; // rax
  __int64 v12; // rax
  __int64 v13; // rax
  double v14; // st4
  double v15; // st5
  double v16; // st6
  double v17; // st5
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 v21; // rax
  double v22; // st4
  double v23; // st5
  __int64 v24; // rax
  __int64 v25; // rax
  __int64 v26; // rax
  __int64 v27; // rax
  double v28; // st6
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 v31; // rax
  __int64 v32; // rax
  Scaleform::Render::GradientRecord *v33; // edi
  unsigned __int8 *v34; // esi
  unsigned int v35; // ebx
  double v36; // st6
  __int64 v37; // rax
  __int64 v38; // rax
  __int64 v39; // rax
  __int64 v40; // rax
  unsigned int v42; // eax
  float v43; // [esp+4h] [ebp-10h]
  float v44; // [esp+8h] [ebp-Ch]
  float v45; // [esp+8h] [ebp-Ch]
  float v46; // [esp+8h] [ebp-Ch]
  float v47; // [esp+8h] [ebp-Ch]
  float v48; // [esp+8h] [ebp-Ch]
  float v49; // [esp+8h] [ebp-Ch]
  float v50; // [esp+8h] [ebp-Ch]
  float v51; // [esp+8h] [ebp-Ch]
  float v52; // [esp+8h] [ebp-Ch]
  float v53; // [esp+8h] [ebp-Ch]
  float v54; // [esp+8h] [ebp-Ch]
  float v55; // [esp+8h] [ebp-Ch]
  float v56; // [esp+8h] [ebp-Ch]
  float v57; // [esp+8h] [ebp-Ch]
  float v58; // [esp+8h] [ebp-Ch]
  float v59; // [esp+8h] [ebp-Ch]
  float v60; // [esp+8h] [ebp-Ch]
  float v61; // [esp+8h] [ebp-Ch]
  float v62; // [esp+8h] [ebp-Ch]
  float v63; // [esp+8h] [ebp-Ch]
  float v64; // [esp+8h] [ebp-Ch]
  float v65; // [esp+8h] [ebp-Ch]
  float v66; // [esp+8h] [ebp-Ch]
  float v67; // [esp+8h] [ebp-Ch]
  float v68; // [esp+8h] [ebp-Ch]
  Scaleform::Render::GradientData *v69; // [esp+Ch] [ebp-8h]
  float v70; // [esp+Ch] [ebp-8h]
  float v71; // [esp+Ch] [ebp-8h]
  float v72; // [esp+Ch] [ebp-8h]

  v1 = this;
  v43 = 0.0;
  RecordCount = this->RecordCount;
  v3 = 1;
  v69 = v1;
  if ( RecordCount <= 1 )
    return 64;
  if ( (int)(RecordCount - 1) >= 4 )
  {
    pRecords = v1->pRecords;
    v5 = ((RecordCount - 5) >> 2) + 1;
    p_Red = &pRecords[1].ColorV.Channels.Red;
    p_Green = &pRecords->ColorV.Channels.Green;
    v3 = 4 * v5 + 1;
    do
    {
      v8 = (double)*(p_Red - 6);
      v44 = v8 - (double)*(p_Red - 14);
      v9 = v44;
      if ( v44 > 0.0 )
      {
        v10 = p_Green[1] - *p_Red;
        v45 = (double)(int)((HIDWORD(v10) ^ v10) - HIDWORD(v10)) / v9;
        if ( v43 < (double)v45 )
          v43 = (double)(int)((HIDWORD(v10) ^ v10) - HIDWORD(v10)) / v9;
        v11 = *p_Green - *(p_Red - 1);
        v46 = (double)(int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) / v9;
        if ( v43 < (double)v46 )
          v43 = (double)(int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) / v9;
        v12 = *(p_Green - 1) - *(p_Red - 2);
        v47 = (double)(int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) / v9;
        if ( v43 < (double)v47 )
          v43 = (double)(int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) / v9;
        v13 = p_Green[2] - p_Red[1];
        v48 = (double)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13)) / v9;
        if ( v43 < (double)v48 )
          v43 = (double)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13)) / v9;
      }
      v14 = (double)p_Red[2];
      v15 = v14 - v8;
      v16 = v14;
      v49 = v15;
      v17 = v49;
      if ( v49 > 0.0 )
      {
        v18 = *p_Red - p_Green[17];
        v50 = (double)(int)((HIDWORD(v18) ^ v18) - HIDWORD(v18)) / v17;
        if ( v43 < (double)v50 )
          v43 = (double)(int)((HIDWORD(v18) ^ v18) - HIDWORD(v18)) / v17;
        v19 = *(p_Red - 1) - p_Green[16];
        v51 = (double)(int)((HIDWORD(v19) ^ v19) - HIDWORD(v19)) / v17;
        if ( v43 < (double)v51 )
          v43 = (double)(int)((HIDWORD(v19) ^ v19) - HIDWORD(v19)) / v17;
        v20 = *(p_Red - 2) - p_Green[15];
        v52 = (double)(int)((HIDWORD(v20) ^ v20) - HIDWORD(v20)) / v17;
        if ( v43 < (double)v52 )
          v43 = (double)(int)((HIDWORD(v20) ^ v20) - HIDWORD(v20)) / v17;
        v21 = p_Red[1] - p_Green[18];
        v53 = (double)(int)((HIDWORD(v21) ^ v21) - HIDWORD(v21)) / v17;
        if ( v43 < (double)v53 )
          v43 = (double)(int)((HIDWORD(v21) ^ v21) - HIDWORD(v21)) / v17;
      }
      v22 = (double)p_Red[10];
      v54 = v22 - v16;
      v23 = v54;
      if ( v54 > 0.0 )
      {
        v24 = p_Green[17] - p_Green[25];
        v55 = (double)(int)((HIDWORD(v24) ^ v24) - HIDWORD(v24)) / v23;
        if ( v43 < (double)v55 )
          v43 = (double)(int)((HIDWORD(v24) ^ v24) - HIDWORD(v24)) / v23;
        v25 = p_Green[16] - p_Green[24];
        v56 = (double)(int)((HIDWORD(v25) ^ v25) - HIDWORD(v25)) / v23;
        if ( v43 < (double)v56 )
          v43 = (double)(int)((HIDWORD(v25) ^ v25) - HIDWORD(v25)) / v23;
        v26 = p_Green[15] - p_Green[23];
        v57 = (double)(int)((HIDWORD(v26) ^ v26) - HIDWORD(v26)) / v23;
        if ( v43 < (double)v57 )
          v43 = (double)(int)((HIDWORD(v26) ^ v26) - HIDWORD(v26)) / v23;
        v27 = p_Green[18] - p_Green[26];
        v58 = (double)(int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) / v23;
        if ( v43 < (double)v58 )
          v43 = (double)(int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) / v23;
      }
      v59 = (double)p_Red[18] - v22;
      v28 = v59;
      if ( v59 > 0.0 )
      {
        v29 = p_Green[25] - p_Green[33];
        v60 = (double)(int)((HIDWORD(v29) ^ v29) - HIDWORD(v29)) / v28;
        if ( v43 < (double)v60 )
          v43 = (double)(int)((HIDWORD(v29) ^ v29) - HIDWORD(v29)) / v28;
        v30 = p_Green[24] - p_Green[32];
        v61 = (double)(int)((HIDWORD(v30) ^ v30) - HIDWORD(v30)) / v28;
        if ( v43 < (double)v61 )
          v43 = (double)(int)((HIDWORD(v30) ^ v30) - HIDWORD(v30)) / v28;
        v31 = p_Green[23] - p_Green[31];
        v62 = (double)(int)((HIDWORD(v31) ^ v31) - HIDWORD(v31)) / v28;
        if ( v43 < (double)v62 )
          v43 = (double)(int)((HIDWORD(v31) ^ v31) - HIDWORD(v31)) / v28;
        v32 = p_Green[26] - p_Green[34];
        v63 = (double)(int)((HIDWORD(v32) ^ v32) - HIDWORD(v32)) / v28;
        if ( v43 < (double)v63 )
          v43 = (double)(int)((HIDWORD(v32) ^ v32) - HIDWORD(v32)) / v28;
      }
      p_Green += 32;
      p_Red += 32;
      --v5;
    }
    while ( v5 );
    v1 = v69;
  }
  if ( v3 < RecordCount )
  {
    v33 = &v1->pRecords[v3];
    v34 = &v33[-1].ColorV.Channels.Green;
    v35 = RecordCount - v3;
    do
    {
      v64 = (double)v33->Ratio - (double)*(v34 - 5);
      v36 = v64;
      if ( v64 > 0.0 )
      {
        v37 = v34[1] - v34[9];
        v65 = (double)(int)((HIDWORD(v37) ^ v37) - HIDWORD(v37)) / v36;
        if ( v43 < (double)v65 )
          v43 = (double)(int)((HIDWORD(v37) ^ v37) - HIDWORD(v37)) / v36;
        v38 = *v34 - v34[8];
        v66 = (double)(int)((HIDWORD(v38) ^ v38) - HIDWORD(v38)) / v36;
        if ( v43 < (double)v66 )
          v43 = (double)(int)((HIDWORD(v38) ^ v38) - HIDWORD(v38)) / v36;
        v39 = *(v34 - 1) - v34[7];
        v67 = (double)(int)((HIDWORD(v39) ^ v39) - HIDWORD(v39)) / v36;
        if ( v43 < (double)v67 )
          v43 = (double)(int)((HIDWORD(v39) ^ v39) - HIDWORD(v39)) / v36;
        v40 = v34[2] - v34[10];
        v68 = (double)(int)((HIDWORD(v40) ^ v40) - HIDWORD(v40)) / v36;
        if ( v43 < (double)v68 )
          v43 = (double)(int)((HIDWORD(v40) ^ v40) - HIDWORD(v40)) / v36;
      }
      ++v33;
      v34 += 8;
      --v35;
    }
    while ( v35 );
    v1 = v69;
  }
  if ( v43 == 0.0 )
    return 64;
  if ( v1->LinearRGB )
    v43 = v43 * 1.5;
  if ( v1->Type == 2 )
  {
    v70 = fabs(v1->FocalRatio);
    if ( v70 > 0.5 )
      v43 = v43 / (1.009999990463257 - v70);
  }
  if ( v43 < 0.0 )
    v43 = 0.0;
  v71 = (v43 + 0.1800000071525574) * 5.0;
  v72 = sqrt(v71);
  v42 = (__int64)v72;
  if ( v42 >= 0x12 )
    v42 = 17;
  return Scaleform::Render::GradientData::ImageSizeTable[v42];
}
