void __cdecl stlp_std::priv::__partial_sort<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__middle,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  float second; // edx
  stlp_std::pair<vostok::ai::npc const *,float> *v6; // eax
  int v7; // [esp-Ch] [ebp-30h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *v8; // [esp+0h] [ebp-24h]
  stlp_std::pair<vostok::ai::npc const *,float> *i; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::npc const *,float> v10; // [esp+8h] [ebp-1Ch] BYREF
  int *v11; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::npc const *,float> *v12; // [esp+18h] [ebp-Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
    __first,
    __middle,
    __comp);
  for ( __i = __middle; __i < __last; ++__i )
  {
    if ( __comp(__i, __first) )
    {
      v12 = &v10;
      v10 = *__i;
      second = __first->second;
      v6 = __i;
      __i->first = __first->first;
      v6->second = second;
      v11 = &v7;
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::npc const *,float> *,int,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        __first,
        0,
        __middle - __first,
        v10,
        __comp);
    }
  }
  for ( i = __middle; i - __first > 1; --i )
  {
    v8 = i;
    stlp_std::pop_heap<stlp_std::pair<vostok::ai::npc const *,float> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      __first,
      i,
      __comp);
  }
}
