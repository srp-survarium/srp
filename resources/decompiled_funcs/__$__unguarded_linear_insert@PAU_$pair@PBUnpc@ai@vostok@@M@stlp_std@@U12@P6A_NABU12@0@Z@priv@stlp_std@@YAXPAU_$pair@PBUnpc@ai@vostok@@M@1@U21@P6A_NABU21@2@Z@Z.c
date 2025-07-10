void __cdecl stlp_std::priv::__unguarded_linear_insert<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> __val,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  unsigned int second; // ecx
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__next; // [esp+0h] [ebp-4h]

  for ( __next = __last - 1; __comp(&__val, __next); --__next )
  {
    second = __next->second;
    __last->first = __next->first;
    __last->second = second;
    __last = __next;
  }
  *__last = __val;
}
