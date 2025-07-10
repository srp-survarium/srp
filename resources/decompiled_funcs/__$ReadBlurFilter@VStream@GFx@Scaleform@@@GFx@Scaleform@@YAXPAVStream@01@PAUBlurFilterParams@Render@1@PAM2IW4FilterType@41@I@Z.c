void __cdecl Scaleform::GFx::ReadBlurFilter<Scaleform::GFx::Stream>(
        Scaleform::GFx::Stream *ps,
        Scaleform::Render::BlurFilterParams *params,
        float *angle,
        float *distance,
        char readConstants,
        Scaleform::Render::FilterType type,
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
  float readConstantsa; // [esp+24h] [ebp+14h]
  float readConstantsb; // [esp+24h] [ebp+14h]
  unsigned int readConstantsc; // [esp+24h] [ebp+14h]
  unsigned int readConstantsd; // [esp+24h] [ebp+14h]
  signed int readConstantse; // [esp+24h] [ebp+14h]

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
  readConstantsa = (double)(unsigned int)v10 * 0.0000152587890625;
  params->BlurX = readConstantsa * 20.0;
  v11 = ps->DataSize - ps->Pos;
  ps->UnusedBits = 0;
  if ( v11 < 4 )
    Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
  v12 = ps->Pos;
  v13 = ps->pBuffer[v12] | ((ps->pBuffer[v12 + 1] | (*(unsigned __int16 *)&ps->pBuffer[v12 + 2] << 8)) << 8);
  ps->Pos = v12 + 4;
  readConstantsb = (double)(unsigned int)v13 * 0.0000152587890625;
  params->BlurY = readConstantsb * 20.0;
  if ( (readConstants & 4) != 0 )
  {
    v14 = ps->DataSize - ps->Pos;
    ps->UnusedBits = 0;
    if ( v14 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
    v15 = ps->Pos;
    readConstantsc = ps->pBuffer[v15]
                   | ((ps->pBuffer[v15 + 1] | (*(unsigned __int16 *)&ps->pBuffer[v15 + 2] << 8)) << 8);
    ps->Pos = v15 + 4;
    *angle = (double)readConstantsc * 0.0000152587890625;
    v16 = ps->DataSize - ps->Pos;
    ps->UnusedBits = 0;
    if ( v16 < 4 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 4);
    v17 = ps->Pos;
    readConstantsd = ps->pBuffer[v17]
                   | ((ps->pBuffer[v17 + 1] | ((ps->pBuffer[v17 + 2] | (ps->pBuffer[v17 + 3] << 8)) << 8)) << 8);
    ps->Pos = v17 + 4;
    *distance = (double)readConstantsd * 0.0000152587890625;
  }
  if ( (readConstants & 8) != 0 )
  {
    v18 = ps->DataSize - ps->Pos;
    ps->UnusedBits = 0;
    if ( v18 < 2 )
      Scaleform::GFx::Stream::PopulateBuffer(ps, 2);
    v19 = ps->Pos;
    readConstantse = *(unsigned __int16 *)&ps->pBuffer[v19];
    ps->Pos = v19 + 2;
    params->Strength = (double)readConstantse * 0.00390625;
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
