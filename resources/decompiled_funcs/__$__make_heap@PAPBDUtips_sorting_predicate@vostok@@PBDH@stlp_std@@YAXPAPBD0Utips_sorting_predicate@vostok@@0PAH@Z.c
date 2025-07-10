void __usercall stlp_std::__make_heap<char const * *,vostok::tips_sorting_predicate,char const *,int>(
        const char **__first@<eax>,
        const char **__last,
        vostok::tips_sorting_predicate *a3)
{
  int v4; // ebx
  int v5; // esi
  const char *v6; // eax

  v4 = __last - __first;
  v5 = (v4 - 2) / 2;
  stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
    __first,
    v5,
    v4,
    __first[v5],
    (vostok::tips_sorting_predicate)a3->editor_str);
  while ( v5 )
  {
    v6 = __first[--v5];
    stlp_std::__adjust_heap<char const * *,int,char const *,vostok::tips_sorting_predicate>(
      __first,
      v5,
      v4,
      v6,
      (vostok::tips_sorting_predicate)a3->editor_str);
  }
}
