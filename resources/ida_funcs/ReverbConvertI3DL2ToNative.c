void __cdecl ReverbConvertI3DL2ToNative(
        const XAUDIO2FX_REVERB_I3DL2_PARAMETERS *pI3DL2,
        XAUDIO2FX_REVERB_PARAMETERS *pNative)
{
  double v2; // xmm0_8
  double DecayHFRatio; // xmm0_8
  long double v4; // [esp+0h] [ebp-30h]
  unsigned __int8 v5; // [esp+10h] [ebp-20h]
  unsigned __int8 v6; // [esp+14h] [ebp-1Ch]
  int v7; // [esp+20h] [ebp-10h]
  int index; // [esp+24h] [ebp-Ch]
  float reflectionsDelay; // [esp+28h] [ebp-8h]
  float reverbDelay; // [esp+2Ch] [ebp-4h]

  pNative->RearDelay = 5;
  pNative->PositionLeft = 6;
  pNative->PositionRight = 6;
  pNative->PositionMatrixLeft = 27;
  pNative->PositionMatrixRight = 27;
  pNative->RoomSize = 100.0;
  pNative->LowEQCutoff = 4;
  pNative->HighEQCutoff = 6;
  pNative->RoomFilterMain = (float)pI3DL2->Room / 100.0;
  pNative->RoomFilterHF = (float)pI3DL2->RoomHF / 100.0;
  if ( pI3DL2->DecayHFRatio < 1.0 )
  {
    DecayHFRatio = pI3DL2->DecayHFRatio;
    __libm_sse2_log10(v4);
    *(float *)&DecayHFRatio = DecayHFRatio;
    v7 = (int)(*(float *)&DecayHFRatio * 4.0);
    if ( v7 < -8 )
      v7 = -8;
    pNative->LowEQGain = 8;
    if ( v7 >= 0 )
      v5 = 8;
    else
      v5 = v7 + 8;
    pNative->HighEQGain = v5;
    pNative->DecayTime = pI3DL2->DecayTime;
  }
  else
  {
    v2 = pI3DL2->DecayHFRatio;
    __libm_sse2_log10(v4);
    *(float *)&v2 = v2;
    index = (int)(*(float *)&v2 * -4.0);
    if ( index < -8 )
      index = -8;
    if ( index >= 0 )
      v6 = 8;
    else
      v6 = index + 8;
    pNative->LowEQGain = v6;
    pNative->HighEQGain = 8;
    pNative->DecayTime = pI3DL2->DecayTime * pI3DL2->DecayHFRatio;
  }
  reflectionsDelay = pI3DL2->ReflectionsDelay * 1000.0;
  if ( reflectionsDelay < 300.0 )
  {
    if ( reflectionsDelay <= 1.0 )
      reflectionsDelay = FLOAT_1_0;
  }
  else
  {
    reflectionsDelay = FLOAT_299_0;
  }
  pNative->ReflectionsDelay = (__int64)reflectionsDelay;
  reverbDelay = pI3DL2->ReverbDelay * 1000.0;
  if ( reverbDelay >= 85.0 )
    reverbDelay = FLOAT_84_0;
  pNative->ReverbDelay = (int)reverbDelay;
  pNative->ReflectionsGain = (float)pI3DL2->Reflections / 100.0;
  pNative->ReverbGain = (float)pI3DL2->Reverb / 100.0;
  pNative->EarlyDiffusion = (int)(float)((float)(15.0 * pI3DL2->Diffusion) / 100.0);
  pNative->LateDiffusion = pNative->EarlyDiffusion;
  pNative->Density = pI3DL2->Density;
  pNative->RoomFilterFreq = pI3DL2->HFReference;
  pNative->WetDryMix = pI3DL2->WetDryMix;
}
