stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__cdecl stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int>,bool (__cdecl *)(stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &,stlp_std::pair<vostok::ai::weapon const *,unsigned int> const &)>(
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__first,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> *__last,
        stlp_std::pair<vostok::ai::weapon const *,unsigned int> __pivot,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *, const stlp_std::pair<vostok::ai::weapon const *,unsigned int> *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<stlp_std::pair<vostok::ai::weapon const *,unsigned int> *,stlp_std::pair<vostok::ai::weapon const *,unsigned int> *>(
      __first++,
      __last);
  }
  return __first;
}
