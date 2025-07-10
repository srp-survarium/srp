void __usercall stlp_std::sort_heap<vostok::animation::mixing::animation_state * *,event_iterator_predicate>(
        vostok::animation::mixing::animation_state **__first@<esi>,
        vostok::animation::mixing::animation_state **__last@<eax>,
        event_iterator_predicate __comp)
{
  int v3; // eax
  vostok::animation::mixing::animation_state *v4; // ecx
  int v5; // edi

  v3 = (char *)__last - (char *)__first;
  if ( (int)(v3 & 0xFFFFFFFC) > 4 )
  {
    do
    {
      v4 = *(vostok::animation::mixing::animation_state **)((char *)__first + v3 - 4);
      v5 = v3 - 4;
      *(vostok::animation::mixing::animation_state **)((char *)__first + v3 - 4) = *__first;
      stlp_std::__adjust_heap<vostok::animation::mixing::animation_state * *,int,vostok::animation::mixing::animation_state *,event_iterator_predicate>(
        __first,
        0,
        (v3 - 4) >> 2,
        v4,
        __comp);
      v3 = v5;
    }
    while ( (int)(v5 & 0xFFFFFFFC) > 4 );
  }
}
