stlp_std::pair<vostok::ai::npc const *,float> *__cdecl stlp_std::priv::__unguarded_partition<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float>,bool (__cdecl *)(stlp_std::pair<vostok::ai::npc const *,float> const &,stlp_std::pair<vostok::ai::npc const *,float> const &)>(
        stlp_std::pair<vostok::ai::npc const *,float> *__first,
        stlp_std::pair<vostok::ai::npc const *,float> *__last,
        stlp_std::pair<vostok::ai::npc const *,float> __pivot,
        bool (__cdecl *__comp)(const stlp_std::pair<vostok::ai::npc const *,float> *, const stlp_std::pair<vostok::ai::npc const *,float> *))
{
  while ( 1 )
  {
    while ( __comp(__first, &__pivot) )
      ++__first;
    for ( --__last; __comp(&__pivot, __last); --__last )
      ;
    if ( __first >= __last )
      break;
    stlp_std::iter_swap<stlp_std::pair<vostok::ai::npc const *,float> *,stlp_std::pair<vostok::ai::npc const *,float> *>(
      __first++,
      __last);
  }
  return __first;
}
