void __cdecl Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
        Scaleform::GFx::StreamContext *ps,
        Scaleform::Render::BlurFilterParams *params,
        float *angle,
        float *distance,
        char readConstants,
        unsigned int type,
        unsigned int passesMask)
{
  int v8; // edi
  unsigned int CurByteIndex; // esi
  const unsigned __int8 *pData; // ecx
  unsigned int v11; // esi
  const unsigned __int8 *v12; // ecx
  unsigned int v13; // esi
  const unsigned __int8 *v14; // ecx
  unsigned int v15; // esi
  const unsigned __int8 *v16; // ecx
  unsigned int v17; // esi
  const unsigned __int8 *v18; // ecx
  unsigned int v19; // esi
  const unsigned __int8 *v20; // ecx
  unsigned int v21; // esi
  const unsigned __int8 *v22; // ecx
  unsigned int v23; // esi
  const unsigned __int8 *v24; // ecx
  unsigned int v25; // ebp
  const unsigned __int8 *v26; // esi
  unsigned int v27; // ebp
  const unsigned __int8 *v28; // esi
  unsigned int v29; // ebx
  const unsigned __int8 *v30; // esi
  unsigned int v31; // ebp
  const unsigned __int8 *v32; // esi
  unsigned int v33; // ecx
  const unsigned __int8 *v34; // esi
  unsigned int v35; // esi
  const unsigned __int8 *v36; // ecx
  unsigned __int8 v37; // cl
  int v38; // [esp+18h] [ebp+8h]
  float v39; // [esp+18h] [ebp+8h]
  int v40; // [esp+18h] [ebp+8h]
  float v41; // [esp+18h] [ebp+8h]
  int v42; // [esp+18h] [ebp+8h]
  int v43; // [esp+18h] [ebp+8h]

  v8 = 0;
  if ( (readConstants & 1) != 0 )
  {
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    CurByteIndex = ps->CurByteIndex;
    pData = ps->pData;
    ps->CurBitIndex = 0;
    LOBYTE(pData) = pData[CurByteIndex];
    ps->CurByteIndex = CurByteIndex + 1;
    params->Colors[0].Channels.Red = (unsigned __int8)pData;
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v11 = ps->CurByteIndex;
    v12 = ps->pData;
    ps->CurBitIndex = 0;
    LOBYTE(v12) = v12[v11];
    ps->CurByteIndex = v11 + 1;
    params->Colors[0].Channels.Green = (unsigned __int8)v12;
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v13 = ps->CurByteIndex;
    v14 = ps->pData;
    ps->CurBitIndex = 0;
    LOBYTE(v14) = v14[v13];
    ps->CurByteIndex = v13 + 1;
    params->Colors[0].Channels.Blue = (unsigned __int8)v14;
    params->Colors[0].Channels.Alpha = -1;
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v15 = ps->CurByteIndex;
    v16 = ps->pData;
    ps->CurBitIndex = 0;
    LOBYTE(v16) = v16[v15];
    ps->CurByteIndex = v15 + 1;
    params->Colors[0].Channels.Alpha = (unsigned __int8)v16;
    if ( (readConstants & 2) != 0 )
    {
      if ( ps->CurBitIndex )
        ++ps->CurByteIndex;
      v17 = ps->CurByteIndex;
      v18 = ps->pData;
      ps->CurBitIndex = 0;
      LOBYTE(v18) = v18[v17];
      ps->CurByteIndex = v17 + 1;
      params->Colors[1].Channels.Red = (unsigned __int8)v18;
      if ( ps->CurBitIndex )
        ++ps->CurByteIndex;
      v19 = ps->CurByteIndex;
      v20 = ps->pData;
      ps->CurBitIndex = 0;
      LOBYTE(v20) = v20[v19];
      ps->CurByteIndex = v19 + 1;
      params->Colors[1].Channels.Green = (unsigned __int8)v20;
      if ( ps->CurBitIndex )
        ++ps->CurByteIndex;
      v21 = ps->CurByteIndex;
      v22 = ps->pData;
      ps->CurBitIndex = 0;
      LOBYTE(v22) = v22[v21];
      ps->CurByteIndex = v21 + 1;
      params->Colors[1].Channels.Blue = (unsigned __int8)v22;
      params->Colors[1].Channels.Alpha = -1;
      if ( ps->CurBitIndex )
        ++ps->CurByteIndex;
      v23 = ps->CurByteIndex;
      v24 = ps->pData;
      ps->CurBitIndex = 0;
      LOBYTE(v24) = v24[v23];
      ps->CurByteIndex = v23 + 1;
      params->Colors[1].Channels.Alpha = (unsigned __int8)v24;
    }
  }
  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  v25 = ps->CurByteIndex;
  v26 = &ps->pData[v25];
  ps->CurBitIndex = 0;
  v38 = *v26 | ((v26[1] | (*((unsigned __int16 *)v26 + 1) << 8)) << 8);
  ps->CurByteIndex = v25 + 4;
  v39 = (double)(unsigned int)v38 * 0.0000152587890625;
  params->BlurX = v39 * 20.0;
  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  v27 = ps->CurByteIndex;
  v28 = &ps->pData[v27];
  ps->CurBitIndex = 0;
  v40 = *v28 | ((v28[1] | (*((unsigned __int16 *)v28 + 1) << 8)) << 8);
  ps->CurByteIndex = v27 + 4;
  v41 = (double)(unsigned int)v40 * 0.0000152587890625;
  params->BlurY = 20.0 * v41;
  if ( (readConstants & 4) != 0 )
  {
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v29 = ps->CurByteIndex;
    v30 = &ps->pData[v29];
    ps->CurBitIndex = 0;
    v42 = *v30 | ((v30[1] | (*((unsigned __int16 *)v30 + 1) << 8)) << 8);
    ps->CurByteIndex = v29 + 4;
    *angle = (double)(unsigned int)v42 * 0.0000152587890625;
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v31 = ps->CurByteIndex;
    v32 = &ps->pData[v31];
    ps->CurBitIndex = 0;
    v43 = *v32 | ((v32[1] | (*((unsigned __int16 *)v32 + 1) << 8)) << 8);
    ps->CurByteIndex = v31 + 4;
    *distance = 0.0000152587890625 * (double)(unsigned int)v43;
  }
  if ( (readConstants & 8) != 0 )
  {
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v33 = ps->CurByteIndex;
    v34 = &ps->pData[v33];
    ps->CurBitIndex = 0;
    LOWORD(v34) = *(_WORD *)v34;
    ps->CurByteIndex = v33 + 2;
    params->Strength = (double)(unsigned __int16)v34 * 0.00390625;
  }
  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  v35 = ps->CurByteIndex;
  v36 = ps->pData;
  ps->CurBitIndex = 0;
  v37 = v36[v35];
  ps->CurByteIndex = v35 + 1;
  if ( passesMask == 248 )
  {
    params->Passes = v37 >> 3;
    params->Mode = type;
  }
  else
  {
    if ( (v37 & 0x80u) != 0 )
      v8 = 32;
    if ( (v37 & 0x40) != 0 )
      v8 |= 0x10u;
    if ( (v37 & 0x20) == 0 )
      v8 |= 0x40u;
    if ( passesMask <= 0xF && (v37 & 0x10) != 0 )
      v8 |= 0x80u;
    params->Mode = type | v8;
    params->Passes = passesMask & v37;
  }
}


void __cdecl Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(
        Scaleform::GFx::Stream *ps,
        Scaleform::Render::BlurFilterParams *params,
        float *angle,
        float *distance,
        char readConstants,
        unsigned int type,
        unsigned int passesMask)
{
  signed int v8; // edx
  unsigned int Pos; // edx
  int v10; // eax
  signed int v11; // edx
  unsigned int v12; // edx
  int v13; // eax
  signed int v14; // edx
  unsigned int v15; // edx
  signed int v16; // eax
  unsigned int v17; // edx
  signed int v18; // eax
  unsigned int v19; // eax
  signed int v20; // eax
  unsigned int v21; // eax
  unsigned __int8 v22; // cl
  unsigned int v23; // eax
  int v24; // ecx
  float v25; // [esp+24h] [ebp+14h]
  float v26; // [esp+24h] [ebp+14h]
  int v27; // [esp+24h] [ebp+14h]
  int v28; // [esp+24h] [ebp+14h]
  int v29; // [esp+24h] [ebp+14h]

  if ( (readConstants & 1) != 0 )
  {
    Scaleform::GFx::Stream::ReadRgba(ps, params->Colors);
    if ( (readConstants & 2) != 0 )
      Scaleform::GFx::Stream::ReadRgba(ps, &params->Colors[1]);
  }
  v8 = ps->DataSize - ps->Pos;
  ps->UnusedBits = 0;
  if ( v8 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
  Pos = ps->Pos;
  v10 = ps->pBuffer[Pos] | ((ps->pBuffer[Pos + 1] | (*(unsigned __int16 *)&ps->pBuffer[Pos + 2] << 8)) << 8);
  ps->Pos = Pos + 4;
  v25 = (double)(unsigned int)v10 * 0.0000152587890625;
  params->BlurX = v25 * 20.0;
  v11 = ps->DataSize - ps->Pos;
  ps->UnusedBits = 0;
  if ( v11 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
  v12 = ps->Pos;
  v13 = ps->pBuffer[v12] | ((ps->pBuffer[v12 + 1] | (*(unsigned __int16 *)&ps->pBuffer[v12 + 2] << 8)) << 8);
  ps->Pos = v12 + 4;
  v26 = (double)(unsigned int)v13 * 0.0000152587890625;
  params->BlurY = v26 * 20.0;
  if ( (readConstants & 4) != 0 )
  {
    v14 = ps->DataSize - ps->Pos;
    ps->UnusedBits = 0;
    if ( v14 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
    v15 = ps->Pos;
    v27 = ps->pBuffer[v15] | ((ps->pBuffer[v15 + 1] | (*(unsigned __int16 *)&ps->pBuffer[v15 + 2] << 8)) << 8);
    ps->Pos = v15 + 4;
    *angle = (double)(unsigned int)v27 * 0.0000152587890625;
    v16 = ps->DataSize - ps->Pos;
    ps->UnusedBits = 0;
    if ( v16 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
    v17 = ps->Pos;
    v28 = ps->pBuffer[v17] | ((ps->pBuffer[v17 + 1] | ((ps->pBuffer[v17 + 2] | (ps->pBuffer[v17 + 3] << 8)) << 8)) << 8);
    ps->Pos = v17 + 4;
    *distance = (double)(unsigned int)v28 * 0.0000152587890625;
  }
  if ( (readConstants & 8) != 0 )
  {
    v18 = ps->DataSize - ps->Pos;
    ps->UnusedBits = 0;
    if ( v18 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 2);
    v19 = ps->Pos;
    v29 = *(unsigned __int16 *)&ps->pBuffer[v19];
    ps->Pos = v19 + 2;
    params->Strength = (double)v29 * 0.00390625;
  }
  v20 = ps->DataSize - ps->Pos;
  ps->UnusedBits = 0;
  if ( v20 < 1 )
    Scaleform::GFx::Stream::PopulateBuffer1(ps);
  v21 = ps->Pos;
  v22 = ps->pBuffer[v21];
  ps->Pos = v21 + 1;
  v23 = v22;
  v24 = 0;
  if ( passesMask == 248 )
  {
    params->Passes = v23 >> 3;
    params->Mode = type;
  }
  else
  {
    if ( (v23 & 0x80u) != 0 )
      v24 = 32;
    if ( (v23 & 0x40) != 0 )
      v24 |= 0x10u;
    if ( (v23 & 0x20) == 0 )
      v24 |= 0x40u;
    if ( passesMask <= 0xF && (v23 & 0x10) != 0 )
      v24 |= 0x80u;
    params->Passes = passesMask & v23;
    params->Mode = type | v24;
  }
}
