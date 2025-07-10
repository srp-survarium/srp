void __cdecl stlp_std::priv::__insertion_sort<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__formal,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  _DWORD v4[10]; // [esp-Ch] [ebp-2Ch] BYREF
  stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__i; // [esp+1Ch] [ebp-4h]

  if ( __first != __last )
  {
    for ( __i = __first + 1; __i != __last; ++__i )
    {
      v4[2] = __comp;
      v4[8] = v4;
      stlp_std::priv::__linear_insert<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        __first,
        __i,
        *__i,
        __comp);
    }
  }
}
