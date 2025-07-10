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
  float maxSlope; // [esp+4h] [ebp-10h]
  float slope; // [esp+8h] [ebp-Ch]
  float slopea; // [esp+8h] [ebp-Ch]
  float slopeb; // [esp+8h] [ebp-Ch]
  float slopec; // [esp+8h] [ebp-Ch]
  float sloped; // [esp+8h] [ebp-Ch]
  float slopee; // [esp+8h] [ebp-Ch]
  float slopef; // [esp+8h] [ebp-Ch]
  float slopeg; // [esp+8h] [ebp-Ch]
  float slopeh; // [esp+8h] [ebp-Ch]
  float slopei; // [esp+8h] [ebp-Ch]
  float slopej; // [esp+8h] [ebp-Ch]
  float slopek; // [esp+8h] [ebp-Ch]
  float slopel; // [esp+8h] [ebp-Ch]
  float slopem; // [esp+8h] [ebp-Ch]
  float slopen; // [esp+8h] [ebp-Ch]
  float slopeo; // [esp+8h] [ebp-Ch]
  float slopep; // [esp+8h] [ebp-Ch]
  float slopeq; // [esp+8h] [ebp-Ch]
  float sloper; // [esp+8h] [ebp-Ch]
  float slopes; // [esp+8h] [ebp-Ch]
  float slopet; // [esp+8h] [ebp-Ch]
  float slopeu; // [esp+8h] [ebp-Ch]
  float slopev; // [esp+8h] [ebp-Ch]
  float slopew; // [esp+8h] [ebp-Ch]
  float slopex; // [esp+8h] [ebp-Ch]
  Scaleform::Render::GradientData *r; // [esp+Ch] [ebp-8h]
  float ra; // [esp+Ch] [ebp-8h]
  float rb; // [esp+Ch] [ebp-8h]
  float rc; // [esp+Ch] [ebp-8h]

  v1 = this;
  maxSlope = 0.0;
  RecordCount = this->RecordCount;
  v3 = 1;
  r = v1;
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
      slope = v8 - (double)*(p_Red - 14);
      v9 = slope;
      if ( slope > 0.0 )
      {
        v10 = p_Green[1] - *p_Red;
        slopea = (double)(int)((HIDWORD(v10) ^ v10) - HIDWORD(v10)) / v9;
        if ( maxSlope < (double)slopea )
          maxSlope = (double)(int)((HIDWORD(v10) ^ v10) - HIDWORD(v10)) / v9;
        v11 = *p_Green - *(p_Red - 1);
        slopeb = (double)(int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) / v9;
        if ( maxSlope < (double)slopeb )
          maxSlope = (double)(int)((HIDWORD(v11) ^ v11) - HIDWORD(v11)) / v9;
        v12 = *(p_Green - 1) - *(p_Red - 2);
        slopec = (double)(int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) / v9;
        if ( maxSlope < (double)slopec )
          maxSlope = (double)(int)((HIDWORD(v12) ^ v12) - HIDWORD(v12)) / v9;
        v13 = p_Green[2] - p_Red[1];
        sloped = (double)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13)) / v9;
        if ( maxSlope < (double)sloped )
          maxSlope = (double)(int)((HIDWORD(v13) ^ v13) - HIDWORD(v13)) / v9;
      }
      v14 = (double)p_Red[2];
      v15 = v14 - v8;
      v16 = v14;
      slopee = v15;
      v17 = slopee;
      if ( slopee > 0.0 )
      {
        v18 = *p_Red - p_Green[17];
        slopef = (double)(int)((HIDWORD(v18) ^ v18) - HIDWORD(v18)) / v17;
        if ( maxSlope < (double)slopef )
          maxSlope = (double)(int)((HIDWORD(v18) ^ v18) - HIDWORD(v18)) / v17;
        v19 = *(p_Red - 1) - p_Green[16];
        slopeg = (double)(int)((HIDWORD(v19) ^ v19) - HIDWORD(v19)) / v17;
        if ( maxSlope < (double)slopeg )
          maxSlope = (double)(int)((HIDWORD(v19) ^ v19) - HIDWORD(v19)) / v17;
        v20 = *(p_Red - 2) - p_Green[15];
        slopeh = (double)(int)((HIDWORD(v20) ^ v20) - HIDWORD(v20)) / v17;
        if ( maxSlope < (double)slopeh )
          maxSlope = (double)(int)((HIDWORD(v20) ^ v20) - HIDWORD(v20)) / v17;
        v21 = p_Red[1] - p_Green[18];
        slopei = (double)(int)((HIDWORD(v21) ^ v21) - HIDWORD(v21)) / v17;
        if ( maxSlope < (double)slopei )
          maxSlope = (double)(int)((HIDWORD(v21) ^ v21) - HIDWORD(v21)) / v17;
      }
      v22 = (double)p_Red[10];
      slopej = v22 - v16;
      v23 = slopej;
      if ( slopej > 0.0 )
      {
        v24 = p_Green[17] - p_Green[25];
        slopek = (double)(int)((HIDWORD(v24) ^ v24) - HIDWORD(v24)) / v23;
        if ( maxSlope < (double)slopek )
          maxSlope = (double)(int)((HIDWORD(v24) ^ v24) - HIDWORD(v24)) / v23;
        v25 = p_Green[16] - p_Green[24];
        slopel = (double)(int)((HIDWORD(v25) ^ v25) - HIDWORD(v25)) / v23;
        if ( maxSlope < (double)slopel )
          maxSlope = (double)(int)((HIDWORD(v25) ^ v25) - HIDWORD(v25)) / v23;
        v26 = p_Green[15] - p_Green[23];
        slopem = (double)(int)((HIDWORD(v26) ^ v26) - HIDWORD(v26)) / v23;
        if ( maxSlope < (double)slopem )
          maxSlope = (double)(int)((HIDWORD(v26) ^ v26) - HIDWORD(v26)) / v23;
        v27 = p_Green[18] - p_Green[26];
        slopen = (double)(int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) / v23;
        if ( maxSlope < (double)slopen )
          maxSlope = (double)(int)((HIDWORD(v27) ^ v27) - HIDWORD(v27)) / v23;
      }
      slopeo = (double)p_Red[18] - v22;
      v28 = slopeo;
      if ( slopeo > 0.0 )
      {
        v29 = p_Green[25] - p_Green[33];
        slopep = (double)(int)((HIDWORD(v29) ^ v29) - HIDWORD(v29)) / v28;
        if ( maxSlope < (double)slopep )
          maxSlope = (double)(int)((HIDWORD(v29) ^ v29) - HIDWORD(v29)) / v28;
        v30 = p_Green[24] - p_Green[32];
        slopeq = (double)(int)((HIDWORD(v30) ^ v30) - HIDWORD(v30)) / v28;
        if ( maxSlope < (double)slopeq )
          maxSlope = (double)(int)((HIDWORD(v30) ^ v30) - HIDWORD(v30)) / v28;
        v31 = p_Green[23] - p_Green[31];
        sloper = (double)(int)((HIDWORD(v31) ^ v31) - HIDWORD(v31)) / v28;
        if ( maxSlope < (double)sloper )
          maxSlope = (double)(int)((HIDWORD(v31) ^ v31) - HIDWORD(v31)) / v28;
        v32 = p_Green[26] - p_Green[34];
        slopes = (double)(int)((HIDWORD(v32) ^ v32) - HIDWORD(v32)) / v28;
        if ( maxSlope < (double)slopes )
          maxSlope = (double)(int)((HIDWORD(v32) ^ v32) - HIDWORD(v32)) / v28;
      }
      p_Green += 32;
      p_Red += 32;
      --v5;
    }
    while ( v5 );
    v1 = r;
  }
  if ( v3 < RecordCount )
  {
    v33 = &v1->pRecords[v3];
    v34 = &v33[-1].ColorV.Channels.Green;
    v35 = RecordCount - v3;
    do
    {
      slopet = (double)v33->Ratio - (double)*(v34 - 5);
      v36 = slopet;
      if ( slopet > 0.0 )
      {
        v37 = v34[1] - v34[9];
        slopeu = (double)(int)((HIDWORD(v37) ^ v37) - HIDWORD(v37)) / v36;
        if ( maxSlope < (double)slopeu )
          maxSlope = (double)(int)((HIDWORD(v37) ^ v37) - HIDWORD(v37)) / v36;
        v38 = *v34 - v34[8];
        slopev = (double)(int)((HIDWORD(v38) ^ v38) - HIDWORD(v38)) / v36;
        if ( maxSlope < (double)slopev )
          maxSlope = (double)(int)((HIDWORD(v38) ^ v38) - HIDWORD(v38)) / v36;
        v39 = *(v34 - 1) - v34[7];
        slopew = (double)(int)((HIDWORD(v39) ^ v39) - HIDWORD(v39)) / v36;
        if ( maxSlope < (double)slopew )
          maxSlope = (double)(int)((HIDWORD(v39) ^ v39) - HIDWORD(v39)) / v36;
        v40 = v34[2] - v34[10];
        slopex = (double)(int)((HIDWORD(v40) ^ v40) - HIDWORD(v40)) / v36;
        if ( maxSlope < (double)slopex )
          maxSlope = (double)(int)((HIDWORD(v40) ^ v40) - HIDWORD(v40)) / v36;
      }
      ++v33;
      v34 += 8;
      --v35;
    }
    while ( v35 );
    v1 = r;
  }
  if ( maxSlope == 0.0 )
    return 64;
  if ( v1->LinearRGB )
    maxSlope = maxSlope * 1.5;
  if ( v1->Type == 2 )
  {
    ra = fabs(v1->FocalRatio);
    if ( ra > 0.5 )
      maxSlope = maxSlope / (1.009999990463257 - ra);
  }
  if ( maxSlope < 0.0 )
    maxSlope = 0.0;
  rb = (maxSlope + 0.1800000071525574) * 5.0;
  rc = sqrt(rb);
  v42 = (__int64)rc;
  if ( v42 >= 0x12 )
    v42 = 17;
  return Scaleform::Render::GradientData::ImageSizeTable[v42];
}
