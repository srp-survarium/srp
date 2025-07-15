void __cdecl stlp_std::iter_swap<char *,char *>(char *__i1, char *__i2)
{
  char v2; // [esp+Bh] [ebp-9h]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}


void __cdecl stlp_std::iter_swap<vostok::ai::sound_item const * *,vostok::ai::sound_item const * *>(
        const vostok::ai::movement_target **__i1,
        const vostok::ai::movement_target **__i2)
{
  const vostok::ai::movement_target *v2; // [esp+8h] [ebp-Ch]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}


void __cdecl stlp_std::iter_swap<vostok::sound::propagator_info *,vostok::sound::propagator_info *>(
        vostok::sound::propagator_info *__i1,
        vostok::sound::propagator_info *__i2)
{
  vostok::sound::propagator_info v2; // [esp+8h] [ebp-1Ch]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}


void __cdecl stlp_std::iter_swap<vostok::particle::curve_point<float> *,vostok::particle::curve_point<float> *>(
        vostok::particle::curve_point<float> *__i1,
        vostok::particle::curve_point<float> *__i2)
{
  vostok::particle::curve_point<float> v2; // [esp+8h] [ebp-20h]

  v2 = *__i1;
  *__i1 = *__i2;
  *__i2 = v2;
}


void __cdecl stlp_std::iter_swap<vostok::particle::curve_point<vostok::math::float4_pod> *,vostok::particle::curve_point<vostok::math::float4_pod> *>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__i1,
        vostok::particle::curve_point<vostok::math::float4_pod> *__i2)
{
  _BYTE v2[72]; // [esp+10h] [ebp-50h] BYREF

  qmemcpy(v2, __i1, sizeof(v2));
  qmemcpy(__i1, __i2, sizeof(vostok::particle::curve_point<vostok::math::float4_pod>));
  qmemcpy(__i2, v2, sizeof(vostok::particle::curve_point<vostok::math::float4_pod>));
}


void __cdecl stlp_std::iter_swap<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float> *>(
        stlp_std::pair<vostok::ai::npc const *,float> *__i1,
        stlp_std::pair<vostok::ai::npc const *,float> *__i2)
{
  float second; // eax
  stlp_std::pair<vostok::ai::npc const *,float> v3; // [esp+8h] [ebp-10h]

  v3 = *__i1;
  second = __i2->second;
  __i1->first = __i2->first;
  __i1->second = second;
  *__i2 = v3;
}


void __cdecl stlp_std::iter_swap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i1,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i2)
{
  unsigned int second; // ecx
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> v3; // [esp+8h] [ebp-10h]

  v3 = *__i1;
  second = __i2->second;
  __i1->first = __i2->first;
  __i1->second = second;
  *__i2 = v3;
}
