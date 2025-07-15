void __cdecl stlp_std::pop_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  vostok::network_core::udp_match_packet *__val; // [esp+0h] [ebp-4h]

  __val = *(__last - 1);
  *(__last - 1) = *__first;
  stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
    __first,
    0,
    __last - 1 - __first,
    __val,
    __comp);
}


void __cdecl stlp_std::pop_heap<vostok::ai::animation_item const * *,bool (__cdecl *)(vostok::ai::animation_item const *,vostok::ai::animation_item const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  const vostok::ai::sound_item *__val; // [esp+0h] [ebp-4h]

  __val = *(__last - 1);
  *(__last - 1) = *__first;
  stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
    __first,
    0,
    __last - 1 - __first,
    __val,
    __comp);
}


void __cdecl stlp_std::pop_heap<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  const vostok::ai::movement_target *__val; // [esp+0h] [ebp-4h]

  __val = *(__last - 1);
  *(__last - 1) = *__first;
  stlp_std::__adjust_heap<vostok::ai::movement_target const * *,int,vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
    __first,
    0,
    __last - 1 - __first,
    __val,
    __comp);
}


void __cdecl stlp_std::pop_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  vostok::sound::propagator_info v3; // [esp+0h] [ebp-14h]

  v3 = __last[-1];
  __last[-1] = *__first;
  stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
    __first,
    0,
    &__last[-1] - __first,
    v3,
    __comp);
}


void __cdecl stlp_std::pop_heap<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  vostok::particle::curve_point<float> v3; // [esp+0h] [ebp-18h]

  v3 = __last[-1];
  __last[-1] = *__first;
  stlp_std::__adjust_heap<vostok::particle::curve_point<float> *,int,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
    __first,
    0,
    &__last[-1] - __first,
    v3,
    __comp);
}


void __cdecl stlp_std::pop_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__first,
        vostok::particle::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<vostok::math::float4_pod> *, const vostok::particle::curve_point<vostok::math::float4_pod> *))
{
  vostok::particle::curve_point<vostok::math::float4_pod> v3; // [esp-4Ch] [ebp-9Ch] BYREF
  _BYTE v4[72]; // [esp+8h] [ebp-48h] BYREF

  qmemcpy(v4, &__last[-1], sizeof(v4));
  qmemcpy(&__last[-1], __first, sizeof(vostok::particle::curve_point<vostok::math::float4_pod>));
  qmemcpy(&v3, v4, sizeof(v3));
  stlp_std::__adjust_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,int,vostok::particle::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
    __first,
    0,
    &__last[-1] - __first,
    v3,
    __comp);
}


void __cdecl stlp_std::pop_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  stlp_std::__pop_heap_aux<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
    __first,
    __last,
    0,
    __comp);
}


void __cdecl stlp_std::pop_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  stlp_std::__pop_heap_aux<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
    __first,
    __last,
    0,
    __comp);
}
