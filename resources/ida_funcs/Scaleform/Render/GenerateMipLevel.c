void __stdcall Scaleform::Render::GenerateMipLevel(
        Scaleform::Render::ImagePlane *dplane,
        Scaleform::Render::ImagePlane *splane,
        unsigned int format,
        unsigned int formatPlaneIndex)
{
  Scaleform::Render::ImagePlane *v4; // ebp
  unsigned int Width; // edi
  unsigned int Pitch; // esi
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
  unsigned int rx; // [esp+10h] [ebp-38h]
  unsigned int rxa; // [esp+10h] [ebp-38h]
  unsigned int rxb; // [esp+10h] [ebp-38h]
  unsigned int j; // [esp+14h] [ebp-34h]
  unsigned int ja; // [esp+14h] [ebp-34h]
  unsigned int jb; // [esp+14h] [ebp-34h]
  unsigned int ry; // [esp+18h] [ebp-30h]
  unsigned int rya; // [esp+18h] [ebp-30h]
  unsigned int dy; // [esp+1Ch] [ebp-2Ch]
  unsigned int yreminv; // [esp+20h] [ebp-28h]
  unsigned int yrem; // [esp+24h] [ebp-24h]
  unsigned __int8 *out; // [esp+28h] [ebp-20h]
  int v49; // [esp+2Ch] [ebp-1Ch]
  unsigned int v50; // [esp+30h] [ebp-18h]
  unsigned int dpitch; // [esp+34h] [ebp-14h]
  unsigned __int8 *in0; // [esp+38h] [ebp-10h]
  unsigned __int32 v53; // [esp+3Ch] [ebp-Ch]
  unsigned int a; // [esp+40h] [ebp-8h]
  unsigned int b; // [esp+44h] [ebp-4h]
  unsigned int xrema; // [esp+4Ch] [ebp+4h]
  unsigned __int8 *xrem; // [esp+4Ch] [ebp+4h]
  unsigned __int8 *splanea; // [esp+50h] [ebp+8h]
  Scaleform::Render::ImagePlane *splaneb; // [esp+50h] [ebp+8h]
  unsigned int g; // [esp+54h] [ebp+Ch]
  unsigned int ga; // [esp+54h] [ebp+Ch]
  unsigned int gb; // [esp+54h] [ebp+Ch]
  unsigned int gc; // [esp+54h] [ebp+Ch]

  v4 = dplane;
  dpitch = dplane->Pitch;
  Width = dplane->Width;
  Pitch = splane->Pitch;
  v7 = (splane->Width << 10) / dplane->Width;
  v50 = v7;
  dy = (splane->Height << 10) / dplane->Height;
  if ( splane->Width == 1 )
  {
    if ( splane->Height != 1 )
    {
      pData = dplane->pData;
      xrem = splane->pData;
      splaneb = (Scaleform::Render::ImagePlane *)pData;
      switch ( format & 0xFFEFFFFF )
      {
        case 1u:
        case 2u:
          v29 = (dy - 1) >> 2;
          ja = 0;
          rya = v29;
          do
          {
            v30 = &xrem[Pitch * (v29 >> 10)];
            v31 = v29 & 0x3FF;
            b = v31 * v30[2] + (1023 - v31) * v30[Pitch + 2];
            v32 = v31 * v30[3] + (1023 - v31) * v30[Pitch + 3];
            v33 = v31 * *v30 + (1023 - v31) * v30[Pitch];
            BYTE1(splaneb->Width) = (v31 * v30[1] + (1023 - v31) * (unsigned int)v30[Pitch + 1]) >> 10;
            BYTE2(splaneb->Width) = b >> 10;
            v29 = dy + rya;
            HIBYTE(splaneb->Width) = v32 >> 10;
            LOBYTE(splaneb->Width) = v33 >> 10;
            splaneb = (Scaleform::Render::ImagePlane *)((char *)splaneb + dpitch);
            ++ja;
            rya += dy;
          }
          while ( ja < v4->Height );
          break;
        case 9u:
        case 0xC8u:
        case 0xC9u:
          v34 = (dy - 1) >> 2;
          jb = 0;
          do
          {
            v35 = &xrem[Pitch * (v34 >> 10)];
            v36 = v34;
            v34 += dy;
            LOBYTE(splaneb->Width) = ((v36 & 0x3FF) * *v35 + (1023 - (v36 & 0x3FF)) * (unsigned int)v35[Pitch]) >> 10;
            splaneb = (Scaleform::Render::ImagePlane *)((char *)splaneb + dpitch);
            ++jb;
          }
          while ( jb < v4->Height );
          break;
        default:
          return;
      }
    }
  }
  else if ( splane->Height == 1 )
  {
    v20 = dplane->pData;
    splanea = splane->pData;
    switch ( format & 0xFFEFFFFF )
    {
      case 1u:
      case 2u:
        v21 = (v7 - 1) >> 2;
        gb = 0;
        rxb = v21;
        if ( Width )
        {
          do
          {
            v22 = &splanea[4 * (v21 >> 10)];
            v23 = v21 & 0x3FF;
            xrema = v23 * v22[1] + (1023 - v23) * v22[5];
            v24 = v23 * v22[3] + (1023 - v23) * v22[7];
            v25 = v23 * *v22 + (1023 - v23) * v22[4];
            v26 = v23 * v22[2] + (1023 - v23) * v22[6];
            v20[1] = xrema >> 10;
            *v20 = v25 >> 10;
            v21 = v50 + rxb;
            v20[2] = v26 >> 10;
            v20[3] = v24 >> 10;
            v20 += 4;
            ++gb;
            rxb += v50;
          }
          while ( gb < v4->Width );
        }
        break;
      case 9u:
      case 0xC8u:
      case 0xC9u:
        v27 = (v7 - 1) >> 2;
        gc = 0;
        if ( Width )
        {
          do
          {
            *v20++ = ((v27 & 0x3FF) * splanea[v27 >> 10] + (1023 - (v27 & 0x3FF)) * splanea[(v27 >> 10) + 1]) >> 10;
            v27 += v7;
            ++gc;
          }
          while ( gc < dplane->Width );
        }
        break;
      default:
        return;
    }
  }
  else
  {
    v8 = (dy - 1) >> 2;
    j = 0;
    ry = v8;
    v53 = (format & 0xFFEFFFFF) - 1;
    v49 = 0;
    while ( 1 )
    {
      out = &v4->pData[v49];
      v9 = &splane->pData[Pitch * (v8 >> 10)];
      yrem = v8 & 0x3FF;
      in0 = v9;
      yreminv = 1023 - yrem;
      switch ( v53 )
      {
        case 0u:
        case 1u:
          v10 = (v7 - 1) >> 2;
          g = 0;
          rx = v10;
          if ( Width )
          {
            while ( 1 )
            {
              v11 = &v9[4 * (v10 >> 10)];
              v12 = v10 & 0x3FF;
              v13 = yrem * (v12 * v11[1] + (1023 - v12) * v11[5])
                  + yreminv * ((1023 - v12) * v11[Pitch + 5] + v12 * v11[Pitch + 1]);
              a = yrem * (v12 * v11[3] + (1023 - v12) * v11[7])
                + yreminv * ((1023 - v12) * v11[Pitch + 7] + v12 * v11[Pitch + 3]);
              v14 = v12 * v11[Pitch] + (1023 - v12) * v11[Pitch + 4];
              v15 = yrem * (v12 * *v11 + (1023 - v12) * v11[4]);
              v16 = yrem * (v12 * v11[2] + (1023 - v12) * v11[6])
                  + yreminv * ((1023 - v12) * v11[Pitch + 6] + v12 * v11[Pitch + 2]);
              out[1] = v13 >> 20;
              out[2] = v16 >> 20;
              *out = (v15 + yreminv * v14) >> 20;
              out[3] = a >> 20;
              out += 4;
              ++g;
              v4 = dplane;
              v7 = v50;
              Width = dplane->Width;
              v10 = v50 + rx;
              rx += v50;
              if ( g >= dplane->Width )
                break;
              v9 = in0;
            }
          }
          break;
        case 8u:
        case 0xC7u:
        case 0xC8u:
          v17 = (v7 - 1) >> 2;
          ga = 0;
          rxa = v17;
          if ( Width )
          {
            while ( 1 )
            {
              v18 = v17;
              v19 = &v9[v17 >> 10];
              v7 = v50;
              *out = (yrem * ((v18 & 0x3FF) * *v19 + (1023 - (v18 & 0x3FF)) * v19[1])
                    + yreminv * ((v18 & 0x3FF) * v19[Pitch] + (1023 - (v18 & 0x3FF)) * v19[Pitch + 1])) >> 20;
              Width = v4->Width;
              ++out;
              v17 = v50 + rxa;
              ++ga;
              rxa += v50;
              if ( ga >= v4->Width )
                break;
              v9 = in0;
            }
          }
          break;
        default:
          break;
      }
      v49 += dpitch;
      ry += dy;
      if ( ++j >= v4->Height )
        break;
      v8 = ry;
    }
  }
}
