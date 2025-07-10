void __cdecl stlp_std::priv::__unguarded_insertion_sort_aux<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  _DWORD v4[5]; // [esp-Ch] [ebp-18h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *__i; // [esp+8h] [ebp-4h]

  for ( __i = __first; __i != __last; ++__i )
  {
    v4[2] = __comp;
    v4[3] = v4;
    stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
      (stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)__i,
      *(stlp_std::pair<vostok::ai::weapon const *,unsigned int> *)__i,
      (bool (__cdecl *)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))__comp);
  }
}
