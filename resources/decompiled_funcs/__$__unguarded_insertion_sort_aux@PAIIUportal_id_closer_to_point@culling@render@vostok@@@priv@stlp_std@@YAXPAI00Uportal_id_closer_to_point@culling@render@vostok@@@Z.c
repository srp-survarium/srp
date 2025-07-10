void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first@<eax>,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned int *i; // esi
  unsigned int v4; // edi
  unsigned int *v5; // edx
  unsigned int *j; // eax

  for ( i = __first; i != __last; *v5 = v4 )
  {
    v4 = *i;
    v5 = i;
    for ( j = i - 1; *(float *)&__formal[*j] > *(float *)&__formal[v4]; --j )
    {
      *v5 = *j;
      v5 = j;
    }
    ++i;
  }
}
