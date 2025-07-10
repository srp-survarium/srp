void __usercall stlp_std::__make_heap<vostok::animation::mixing::animation_state * *,event_iterator_predicate,vostok::animation::mixing::animation_state *,int>(
        vostok::animation::mixing::animation_state **__first@<edi>,
        vostok::animation::mixing::animation_state **__last,
        event_iterator_predicate *a3)
{
  int v3; // ebx
  int v4; // esi
  vostok::animation::mixing::animation_state *v5; // eax

  v3 = __last - __first;
  v4 = (v3 - 2) / 2;
  stlp_std::__adjust_heap<vostok::animation::mixing::animation_state * *,int,vostok::animation::mixing::animation_state *,event_iterator_predicate>(
    __first,
    v4,
    v3,
    __first[v4],
    *a3);
  while ( v4 )
  {
    v5 = __first[--v4];
    stlp_std::__adjust_heap<vostok::animation::mixing::animation_state * *,int,vostok::animation::mixing::animation_state *,event_iterator_predicate>(
      __first,
      v4,
      v3,
      v5,
      *a3);
  }
}
