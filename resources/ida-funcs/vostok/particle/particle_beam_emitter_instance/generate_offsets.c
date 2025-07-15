void __thiscall vostok::particle::particle_beam_emitter_instance::generate_offsets(
        vostok::particle::particle_beam_emitter_instance *this,
        int a2)
{
  int v3; // eax
  float *v4; // edi
  bool v5; // zf
  float v6; // [esp+14h] [ebp-14h]
  float v7; // [esp+18h] [ebp-10h]
  float v8; // [esp+1Ch] [ebp-Ch]
  int v9; // [esp+20h] [ebp-8h]
  unsigned int i; // [esp+24h] [ebp-4h]
  int v11; // [esp+30h] [ebp+8h]

  v3 = 0;
  for ( i = 0; i < *(_DWORD *)(*(_DWORD *)(a2 + 484) + 8); v3 = v11 )
  {
    v11 = v3;
    v9 = 15;
    do
    {
      v6 = vostok::particle::random_float(0.0, 1.0);
      v7 = vostok::particle::random_float(0.0, 1.0);
      v8 = vostok::particle::random_float(0.0, 1.0);
      v4 = (float *)(v11 + *(_DWORD *)(a2 + 624));
      v11 += 12;
      v5 = v9-- == 1;
      *v4++ = v6;
      *v4 = v7;
      v4[1] = v8;
    }
    while ( !v5 );
    ++i;
  }
}
