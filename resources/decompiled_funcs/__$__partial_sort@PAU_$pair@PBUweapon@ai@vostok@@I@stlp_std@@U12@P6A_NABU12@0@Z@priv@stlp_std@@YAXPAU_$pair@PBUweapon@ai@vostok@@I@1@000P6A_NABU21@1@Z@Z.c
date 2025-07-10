void __cdecl stlp_std::priv::__partial_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__middle,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  unsigned int second; // eax
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v6; // ecx
  int v7; // [esp-Ch] [ebp-30h] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v8; // [esp+0h] [ebp-24h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *i; // [esp+4h] [ebp-20h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> v10; // [esp+8h] [ebp-1Ch] BYREF
  int *v11; // [esp+10h] [ebp-14h]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *v12; // [esp+18h] [ebp-Ch]
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i; // [esp+20h] [ebp-4h]

  stlp_std::make_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
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
      stlp_std::__adjust_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,int,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
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
    stlp_std::pop_heap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
      __first,
      i,
      __comp);
  }
}
