void __usercall stlp_std::priv::__partial_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<eax>,
        unsigned int *__middle,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned int *v4; // ebx
  unsigned int v6; // eax
  unsigned int *v7; // [esp+0h] [ebp-10h]
  int *v8; // [esp+4h] [ebp-Ch]

  v4 = __middle;
  stlp_std::__make_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point,unsigned int,int>(
    __first,
    __middle,
    (vostok::render::culling::portal_id_closer_to_point)__formal,
    v7,
    v8);
  if ( __middle < __last )
  {
    do
    {
      v6 = *v4;
      if ( *(float *)&__formal[*__first] > *(float *)&__formal[*v4] )
      {
        *v4 = *__first;
        stlp_std::__adjust_heap<unsigned int *,int,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
          __first,
          0,
          __middle - __first,
          v6,
          (vostok::render::culling::portal_id_closer_to_point)__formal);
      }
      ++v4;
    }
    while ( v4 < __last );
  }
  stlp_std::sort_heap<unsigned int *,vostok::render::culling::portal_id_closer_to_point>(
    __first,
    __middle,
    (vostok::render::culling::portal_id_closer_to_point)__formal);
}
