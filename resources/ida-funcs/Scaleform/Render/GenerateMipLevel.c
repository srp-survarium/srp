void __stdcall Scaleform::Render::GenerateMipLevel(
        Scaleform::Render::ImagePlane *dplane,
        Scaleform::Render::ImagePlane *splane,
        Scaleform::Render::ImageFormat format,
        unsigned int formatPlaneIndex)
{
  Scaleform::Render::ImagePlane *v4; // ebp
  unsigned int Width; // edi
  unsigned int v6; // esi
  unsigned int v7; // ebx
  unsigned int v8; // edx
  unsigned __int8 *v9; // ecx
  unsigned int v10; // eax
  unsigned __int8 *v11; // ecx
  int v12; // edx
  unsigned int v13; // ebp
  int v14; // ebx
  int v15; // eax
  unsigned int v16; // ecx
  unsigned int v17; // edx
  __int16 v18; // di
  unsigned __int8 *v19; // edx
  unsigned __int8 *v20; // edx
  unsigned int v21; // ebx
  unsigned __int8 *v22; // eax
  int v23; // ecx
  unsigned int v24; // edi
  unsigned int v25; // ebx
  unsigned int v26; // eax
  unsigned int v27; // ecx
  unsigned __int8 *pData; // edx
  unsigned int v29; // edx
  unsigned __int8 *v30; // ecx
  int v31; // edx
  unsigned int v32; // eax
  unsigned int v33; // ebx
  unsigned int v34; // edi
  unsigned __int8 *v35; // eax
  __int16 v36; // cx
  unsigned int v37; // [esp+10h] [ebp-38h]
  unsigned int v38; // [esp+10h] [ebp-38h]
  unsigned int v39; // [esp+10h] [ebp-38h]
  int v40; // [esp+14h] [ebp-34h]
  unsigned int v41; // [esp+14h] [ebp-34h]
  unsigned int v42; // [esp+14h] [ebp-34h]
  unsigned int v43; // [esp+18h] [ebp-30h]
  unsigned int v44; // [esp+18h] [ebp-30h]
  unsigned int v45; // [esp+1Ch] [ebp-2Ch]
  int v46; // [esp+20h] [ebp-28h]
  int v47; // [esp+24h] [ebp-24h]
  unsigned __int8 *v48; // [esp+28h] [ebp-20h]
  int v49; // [esp+2Ch] [ebp-1Ch]
  unsigned int v50; // [esp+30h] [ebp-18h]
  unsigned int Pitch; // [esp+34h] [ebp-14h]
  unsigned __int8 *v52; // [esp+38h] [ebp-10h]
  unsigned __int32 v53; // [esp+3Ch] [ebp-Ch]
  unsigned int v54; // [esp+40h] [ebp-8h]
  unsigned int v55; // [esp+44h] [ebp-4h]
  unsigned int v56; // [esp+4Ch] [ebp+4h]
  unsigned __int8 *v57; // [esp+4Ch] [ebp+4h]
  unsigned __int8 *v58; // [esp+50h] [ebp+8h]
  unsigned __int8 *v59; // [esp+50h] [ebp+8h]
  unsigned int v60; // [esp+54h] [ebp+Ch]
  unsigned int v61; // [esp+54h] [ebp+Ch]
  unsigned int v62; // [esp+54h] [ebp+Ch]
  unsigned int v63; // [esp+54h] [ebp+Ch]

  v4 = dplane;
  Pitch = dplane->Pitch;
  Width = dplane->Width;
  v6 = splane->Pitch;
  v7 = (splane->Width << 10) / dplane->Width;
  v50 = v7;
  v45 = (splane->Height << 10) / dplane->Height;
  if ( splane->Width == 1 )
  {
    if ( splane->Height != 1 )
    {
      pData = dplane->pData;
      v57 = splane->pData;
      v59 = pData;
      switch ( format & 0xFFEFFFFF )
      {
        case 1u:
        case 2u:
          v29 = (v45 - 1) >> 2;
          v41 = 0;
          v44 = v29;
          do
          {
            v30 = &v57[v6 * (v29 >> 10)];
            v31 = v29 & 0x3FF;
            v55 = v31 * v30[2] + (1023 - v31) * v30[v6 + 2];
            v32 = v31 * v30[3] + (1023 - v31) * v30[v6 + 3];
            v33 = v31 * *v30 + (1023 - v31) * v30[v6];
            v59[1] = (v31 * v30[1] + (1023 - v31) * (unsigned int)v30[v6 + 1]) >> 10;
            v59[2] = v55 >> 10;
            v29 = v45 + v44;
            v59[3] = v32 >> 10;
            *v59 = v33 >> 10;
            v59 += Pitch;
            ++v41;
            v44 += v45;
          }
          while ( v41 < v4->Height );
          break;
        case 9u:
        case 0xC8u:
        case 0xC9u:
          v34 = (v45 - 1) >> 2;
          v42 = 0;
          do
          {
            v35 = &v57[v6 * (v34 >> 10)];
            v36 = v34;
            v34 += v45;
            *v59 = ((v36 & 0x3FF) * *v35 + (1023 - (v36 & 0x3FF)) * (unsigned int)v35[v6]) >> 10;
            v59 += Pitch;
            ++v42;
          }
          while ( v42 < v4->Height );
          break;
        default:
          return;
      }
    }
  }
  else if ( splane->Height == 1 )
  {
    v20 = dplane->pData;
    v58 = splane->pData;
    switch ( format & 0xFFEFFFFF )
    {
      case 1u:
      case 2u:
        v21 = (v7 - 1) >> 2;
        v62 = 0;
        v39 = v21;
        if ( Width )
        {
          do
          {
            v22 = &v58[4 * (v21 >> 10)];
            v23 = v21 & 0x3FF;
            v56 = v23 * v22[1] + (1023 - v23) * v22[5];
            v24 = v23 * v22[3] + (1023 - v23) * v22[7];
            v25 = v23 * *v22 + (1023 - v23) * v22[4];
            v26 = v23 * v22[2] + (1023 - v23) * v22[6];
            v20[1] = v56 >> 10;
            *v20 = v25 >> 10;
            v21 = v50 + v39;
            v20[2] = v26 >> 10;
            v20[3] = v24 >> 10;
            v20 += 4;
            ++v62;
            v39 += v50;
          }
          while ( v62 < v4->Width );
        }
        break;
      case 9u:
      case 0xC8u:
      case 0xC9u:
        v27 = (v7 - 1) >> 2;
        v63 = 0;
        if ( Width )
        {
          do
          {
            *v20++ = ((v27 & 0x3FF) * v58[v27 >> 10] + (1023 - (v27 & 0x3FF)) * v58[(v27 >> 10) + 1]) >> 10;
            v27 += v7;
            ++v63;
          }
          while ( v63 < dplane->Width );
        }
        break;
      default:
        return;
    }
  }
  else
  {
    v8 = (v45 - 1) >> 2;
    v40 = 0;
    v43 = v8;
    v53 = (format & 0xFFEFFFFF) - 1;
    v49 = 0;
    while ( 1 )
    {
      v48 = &v4->pData[v49];
      v9 = &splane->pData[v6 * (v8 >> 10)];
      v47 = v8 & 0x3FF;
      v52 = v9;
      v46 = 1023 - v47;
      switch ( v53 )
      {
        case 0u:
        case 1u:
          v10 = (v7 - 1) >> 2;
          v60 = 0;
          v37 = v10;
          if ( Width )
          {
            while ( 1 )
            {
              v11 = &v9[4 * (v10 >> 10)];
              v12 = v10 & 0x3FF;
              v13 = v47 * (v12 * v11[1] + (1023 - v12) * v11[5])
                  + v46 * ((1023 - v12) * v11[v6 + 5] + v12 * v11[v6 + 1]);
              v54 = v47 * (v12 * v11[3] + (1023 - v12) * v11[7])
                  + v46 * ((1023 - v12) * v11[v6 + 7] + v12 * v11[v6 + 3]);
              v14 = v12 * v11[v6] + (1023 - v12) * v11[v6 + 4];
              v15 = v47 * (v12 * *v11 + (1023 - v12) * v11[4]);
              v16 = v47 * (v12 * v11[2] + (1023 - v12) * v11[6])
                  + v46 * ((1023 - v12) * v11[v6 + 6] + v12 * v11[v6 + 2]);
              v48[1] = v13 >> 20;
              v48[2] = v16 >> 20;
              *v48 = (unsigned int)(v15 + v46 * v14) >> 20;
              v48[3] = v54 >> 20;
              v48 += 4;
              ++v60;
              v4 = dplane;
              v7 = v50;
              Width = dplane->Width;
              v10 = v50 + v37;
              v37 += v50;
              if ( v60 >= dplane->Width )
                break;
              v9 = v52;
            }
          }
          break;
        case 8u:
        case 0xC7u:
        case 0xC8u:
          v17 = (v7 - 1) >> 2;
          v61 = 0;
          v38 = v17;
          if ( Width )
          {
            while ( 1 )
            {
              v18 = v17;
              v19 = &v9[v17 >> 10];
              v7 = v50;
              *v48 = (v47 * ((v18 & 0x3FF) * *v19 + (1023 - (v18 & 0x3FF)) * v19[1])
                    + v46 * ((v18 & 0x3FF) * v19[v6] + (1023 - (v18 & 0x3FF)) * (unsigned int)v19[v6 + 1])) >> 20;
              Width = v4->Width;
              ++v48;
              v17 = v50 + v38;
              ++v61;
              v38 += v50;
              if ( v61 >= v4->Width )
                break;
              v9 = v52;
            }
          }
          break;
        default:
          break;
      }
      v49 += Pitch;
      v43 += v45;
      if ( ++v40 >= v4->Height )
        break;
      v8 = v43;
    }
  }
}
