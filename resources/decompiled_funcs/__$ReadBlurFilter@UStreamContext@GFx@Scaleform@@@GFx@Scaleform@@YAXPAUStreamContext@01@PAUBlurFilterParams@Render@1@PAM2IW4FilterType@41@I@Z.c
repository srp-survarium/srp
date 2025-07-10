void __cdecl Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::StreamContext>(
        Scaleform::GFx::StreamContext *ps,
        Scaleform::Render::BlurFilterParams *params,
        float *angle,
        float *distance,
        char readConstants,
        Scaleform::Render::FilterType type,
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
  Scaleform::Render::BlurFilterParams *paramsa; // [esp+18h] [ebp+8h]
  float paramsb; // [esp+18h] [ebp+8h]
  Scaleform::Render::BlurFilterParams *paramsc; // [esp+18h] [ebp+8h]
  float paramsd; // [esp+18h] [ebp+8h]
  Scaleform::Render::BlurFilterParams *paramse; // [esp+18h] [ebp+8h]
  Scaleform::Render::BlurFilterParams *paramsf; // [esp+18h] [ebp+8h]

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
  paramsa = (Scaleform::Render::BlurFilterParams *)(*v26 | ((v26[1] | (*((unsigned __int16 *)v26 + 1) << 8)) << 8));
  ps->CurByteIndex = v25 + 4;
  paramsb = (double)(unsigned int)paramsa * 0.0000152587890625;
  params->BlurX = paramsb * 20.0;
  if ( ps->CurBitIndex )
    ++ps->CurByteIndex;
  v27 = ps->CurByteIndex;
  v28 = &ps->pData[v27];
  ps->CurBitIndex = 0;
  paramsc = (Scaleform::Render::BlurFilterParams *)(*v28 | ((v28[1] | (*((unsigned __int16 *)v28 + 1) << 8)) << 8));
  ps->CurByteIndex = v27 + 4;
  paramsd = (double)(unsigned int)paramsc * 0.0000152587890625;
  params->BlurY = 20.0 * paramsd;
  if ( (readConstants & 4) != 0 )
  {
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v29 = ps->CurByteIndex;
    v30 = &ps->pData[v29];
    ps->CurBitIndex = 0;
    paramse = (Scaleform::Render::BlurFilterParams *)(*v30 | ((v30[1] | (*((unsigned __int16 *)v30 + 1) << 8)) << 8));
    ps->CurByteIndex = v29 + 4;
    *angle = (double)(unsigned int)paramse * 0.0000152587890625;
    if ( ps->CurBitIndex )
      ++ps->CurByteIndex;
    v31 = ps->CurByteIndex;
    v32 = &ps->pData[v31];
    ps->CurBitIndex = 0;
    paramsf = (Scaleform::Render::BlurFilterParams *)(*v32 | ((v32[1] | (*((unsigned __int16 *)v32 + 1) << 8)) << 8));
    ps->CurByteIndex = v31 + 4;
    *distance = 0.0000152587890625 * (double)(unsigned int)paramsf;
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
