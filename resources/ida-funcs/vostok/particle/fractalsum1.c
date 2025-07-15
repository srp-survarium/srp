float __cdecl vostok::particle::fractalsum1(float x, float freq, unsigned int octaves, unsigned int seed)
{
  void *v4; // ecx
  int v5; // edi
  int v6; // eax
  double v7; // st7
  unsigned int v8; // esi
  unsigned int v9; // eax
  int v10; // edx
  float v11; // xmm3_4
  float v12; // xmm0_4
  int v13; // edx
  float v15; // [esp+Ch] [ebp-4h]
  float v16; // [esp+18h] [ebp+8h]

  if ( (_S5_2 & 1) == 0 )
  {
    _S5_2 |= 1u;
    ignore_133 = vostok::particle::initNoise(v4);
  }
  v15 = 0.0;
  v5 = 0;
  v16 = x * freq;
  if ( octaves )
  {
    v6 = 0;
    do
    {
      v7 = v16;
      v8 = v6 + seed;
      v9 = vostok::math::floor(v16);
      v11 = vostok::particle::noise1(v8, LODWORD(v16), v9).m128_f32[0];
      v12 = vostok::particle::noise1(v8, LODWORD(v16), v10 + 1).m128_f32[0];
      v15 = (float)((float)((float)((float)(v12 - v11) * (float)(v16 - (float)v13)) + v11) / freq) + v15;
      v6 = (unsigned __int16)++v5;
      freq = freq * 2.375;
      v16 = v16 * freq;
    }
    while ( (unsigned __int16)v5 < octaves );
  }
  return v7;
}
