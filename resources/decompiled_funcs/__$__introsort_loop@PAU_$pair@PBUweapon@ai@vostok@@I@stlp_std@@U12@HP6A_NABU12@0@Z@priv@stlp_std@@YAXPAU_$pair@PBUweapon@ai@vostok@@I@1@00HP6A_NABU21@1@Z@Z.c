void __cdecl stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        int __depth_limit,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  int v5; // [esp-Ch] [ebp-20h] BYREF
  bool (__cdecl *v6)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *); // [esp-4h] [ebp-18h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v7; // [esp+0h] [ebp-14h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v8; // [esp+4h] [ebp-10h]
  int *v9; // [esp+8h] [ebp-Ch]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__cut; // [esp+10h] [ebp-4h]

  while ( __last - __first > 16 )
  {
    if ( !__depth_limit )
    {
      stlp_std::partial_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        __first,
        __last,
        __last,
        __comp);
      return;
    }
    --__depth_limit;
    v6 = __comp;
    v8 = (stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)stlp_std::priv::__median<vostok::sound::propagator_info,bool (__cdecl *)(vostok::sound::propagator_info const &,vostok::sound::propagator_info const &)>(
                                                                      (const vostok::sound::propagator_info *)__first,
                                                                      (const vostok::sound::propagator_info *)&__first[(__last - __first) / 2],
                                                                      (const vostok::sound::propagator_info *)&__last[-1],
                                                                      (bool (__cdecl *)(const vostok::sound::propagator_info *, const vostok::sound::propagator_info *))__comp);
    v9 = &v5;
    v7 = stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
           __first,
           __last,
           *v8,
           v6);
    __cut = v7;
    stlp_std::priv::__introsort_loop<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,int,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      v7,
      __last,
      0,
      __depth_limit,
      __comp);
    __last = __cut;
  }
}
