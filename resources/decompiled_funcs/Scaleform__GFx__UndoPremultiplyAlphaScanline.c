void __cdecl Scaleform::GFx::UndoPremultiplyAlphaScanline(Scaleform::GFx::Params *params)
{
  unsigned __int8 *pReadScanline; // ebx
  unsigned __int8 *v2; // ebp
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edx
  unsigned __int8 *v5; // ebx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // ecx
  char v12; // cl
  unsigned __int8 v13; // cl
  unsigned __int8 v14; // cl
  unsigned int x; // [esp+10h] [ebp-20h]
  unsigned __int8 *imgSl; // [esp+14h] [ebp-1Ch]
  const unsigned __int8 *line0; // [esp+18h] [ebp-18h]
  const unsigned __int8 *line0a; // [esp+18h] [ebp-18h]
  unsigned int g; // [esp+1Ch] [ebp-14h]
  unsigned int ga; // [esp+1Ch] [ebp-14h]
  unsigned __int16 gb; // [esp+1Ch] [ebp-14h]
  unsigned __int8 *v22; // [esp+20h] [ebp-10h]
  int v23; // [esp+24h] [ebp-Ch]
  int v24; // [esp+28h] [ebp-8h]
  int v25; // [esp+2Ch] [ebp-4h]

  pReadScanline = params->ScanlineWithAlphas[0]->pReadScanline;
  v2 = params->ScanlineWithAlphas[1]->pReadScanline;
  v3 = params->ScanlineWithAlphas[2]->pReadScanline;
  imgSl = params->FinalScanline.pReadScanline;
  line0 = pReadScanline;
  g = (unsigned int)v3;
  memcpy(imgSl, v2 + 4, params->FinalScanline.ReadScanlineSize);
  x = 0;
  if ( params->Width )
  {
    v4 = imgSl;
    v24 = v2 - v3;
    v23 = pReadScanline - v3;
    v5 = pReadScanline + 11;
    v25 = v2 - line0;
    v6 = v3 + 3;
    v7 = v2 + 1;
    v22 = &imgSl[-g];
    line0a = (const unsigned __int8 *)(imgSl - v2);
    do
    {
      v8 = v22[(_DWORD)v6];
      if ( v8 >= 0x10u )
      {
        v13 = v4[4 * x];
        gb = GFx_UndoPremultiplyTable[v8];
        if ( v13 > v8 )
          v13 = v22[(_DWORD)v6];
        v4[4 * x] = (unsigned __int16)(GFx_UndoPremultiplyTable[v8] * v13) >> 8;
        v14 = v7[(_DWORD)line0a];
        if ( v14 > v8 )
          v14 = v8;
        line0a[(_DWORD)v7] = (unsigned __int16)(gb * v14) >> 8;
        if ( v4[4 * x + 2] <= v8 )
          v8 = v4[4 * x + 2];
        v4[4 * x + 2] = (unsigned __int16)(gb * v8) >> 8;
      }
      else
      {
        v9 = *v5 + *v6 + v7[6] + *(v5 - 4) + v6[4] + v6[8] + v5[v25] + v6[v24] + v6[v23];
        if ( v9 )
        {
          ga = ((*v7 + v7[4] + v7[8] + *(v5 - 2) + *(v5 - 6) + *(v5 - 10) + v6[2] + *(v6 - 2) + (unsigned int)v6[6]) << 8)
             / v9;
          v10 = ((v7[1] + v7[5] + v7[9] + *(v5 - 1) + *(v5 - 5) + *(v5 - 9) + *(v6 - 1) + v6[3] + (unsigned int)v6[7]) << 8)
              / v9;
          v11 = ((*(v7 - 1)
                + v7[3]
                + v7[7]
                + *(v5 - 3)
                + *(v5 - 7)
                + *(v5 - 11)
                + v6[1]
                + *(v6 - 3)
                + (unsigned int)v6[5]) << 8)
              / v9;
          if ( v11 > 0xFF )
            LOBYTE(v11) = -1;
          imgSl[4 * x] = v11;
          v12 = ga;
          if ( ga > 0xFF )
            v12 = -1;
          line0a[(_DWORD)v7] = v12;
          if ( v10 > 0xFF )
            LOBYTE(v10) = -1;
          imgSl[4 * x + 2] = v10;
          v4 = imgSl;
        }
      }
      v7 += 4;
      v5 += 4;
      v6 += 4;
      ++x;
    }
    while ( x < params->Width );
  }
}
