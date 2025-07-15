void __usercall stlp_std::make_heap<vostok::console_commands::console_command * *,vostok::console_commands::starts_from_predicate>(
        vostok::console_commands::console_command **__first@<edi>,
        vostok::console_commands::console_command **__last,
        vostok::console_commands::starts_from_predicate __comp)
{
  int v3; // ebx
  int i; // esi

  v3 = __last - __first;
  if ( v3 >= 2 )
  {
    for ( i = (v3 - 2) / 2; ; --i )
    {
      stlp_std::__adjust_heap<vostok::console_commands::console_command * *,int,vostok::console_commands::console_command *,vostok::console_commands::starts_from_predicate>(
        __first,
        i,
        v3,
        __first[i],
        __comp);
      if ( !i )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<vostok::ai::planning::goal * *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        const vostok::ai::sound_item **__first,
        const vostok::ai::sound_item **__last,
        bool (__cdecl *__comp)(const vostok::ai::sound_item *, const vostok::ai::sound_item *))
{
  int __holeIndex; // [esp+0h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::ai::planning::goal * *,int,vostok::ai::planning::goal *,bool (__cdecl *)(vostok::ai::planning::goal const *,vostok::ai::planning::goal const *)>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<vostok::network_core::udp_match_packet * *,packets_predicate>(
        vostok::network_core::udp_match_packet **__first,
        vostok::network_core::udp_match_packet **__last,
        packets_predicate __comp)
{
  int __holeIndex; // [esp+0h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::network_core::udp_match_packet * *,int,vostok::network_core::udp_match_packet *,packets_predicate>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<vostok::ai::movement_target const * *,vostok::ai::selectors::sort_by_distance_predicate>(
        const vostok::ai::movement_target **__first,
        const vostok::ai::movement_target **__last,
        vostok::ai::selectors::sort_by_distance_predicate __comp)
{
  int __holeIndex; // [esp+0h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::ai::movement_target const * *,int,vostok::ai::movement_target const *,vostok::ai::selectors::sort_by_distance_predicate>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<vostok::sound::propagator_info *,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        vostok::sound::propagator_info *__first,
        vostok::sound::propagator_info *__last,
        bool (__cdecl *__comp)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))
{
  int __holeIndex; // [esp+14h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::sound::propagator_info *,int,vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<vostok::particle::curve_point<float> *,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        vostok::particle::curve_point<float> *__first,
        vostok::particle::curve_point<float> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<float> *, const vostok::particle::curve_point<float> *))
{
  int __holeIndex; // [esp+18h] [ebp-8h]

  if ( __last - __first >= 2 )
  {
    for ( __holeIndex = (__last - __first - 2) / 2; ; --__holeIndex )
    {
      stlp_std::__adjust_heap<vostok::particle::curve_point<float> *,int,vostok::particle::curve_point<float>,bool (__cdecl *)(vostok::particle::curve_point<float> const &,vostok::particle::curve_point<float> const &)>(
        __first,
        __holeIndex,
        __last - __first,
        __first[__holeIndex],
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        vostok::particle::curve_point<vostok::math::float4_pod> *__first,
        vostok::particle::curve_point<vostok::math::float4_pod> *__last,
        bool (__cdecl *__comp)(const vostok::particle::curve_point<vostok::math::float4_pod> *, const vostok::particle::curve_point<vostok::math::float4_pod> *))
{
  vostok::particle::curve_point<vostok::math::float4_pod> v3; // [esp-4Ch] [ebp-A4h] BYREF
  _BYTE v4[72]; // [esp+8h] [ebp-50h] BYREF
  int __holeIndex; // [esp+50h] [ebp-8h]
  int __len; // [esp+54h] [ebp-4h]

  if ( __last - __first >= 2 )
  {
    __len = __last - __first;
    for ( __holeIndex = (__len - 2) / 2; ; --__holeIndex )
    {
      qmemcpy(v4, &__first[__holeIndex], sizeof(v4));
      qmemcpy(&v3, v4, sizeof(v3));
      stlp_std::__adjust_heap<vostok::particle::curve_point<vostok::math::float4_pod> *,int,vostok::particle::curve_point<vostok::math::float4_pod>,bool (__cdecl *)(vostok::particle::curve_point<vostok::math::float4_pod> const &,vostok::particle::curve_point<vostok::math::float4_pod> const &)>(
        __first,
        __holeIndex,
        __len,
        v3,
        __comp);
      if ( !__holeIndex )
        break;
    }
  }
}


void __cdecl stlp_std::make_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  stlp_std::__make_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &),stlp_std::pair<vostok::ai::npc const *,float>,int>(
    __first,
    __last,
    __comp,
    0,
    0);
}


void __cdecl stlp_std::make_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  stlp_std::__make_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &),stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int>(
    __first,
    __last,
    __comp,
    0,
    0);
}
