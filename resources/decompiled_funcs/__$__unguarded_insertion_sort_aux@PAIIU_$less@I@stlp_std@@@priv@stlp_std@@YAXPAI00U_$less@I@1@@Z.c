void __usercall stlp_std::priv::__unguarded_insertion_sort_aux<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned int *__first@<eax>,
        unsigned int *__last)
{
  unsigned int *i; // edi
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int *v6; // edx

  for ( i = __first; i != __last; *v6 = v3 )
  {
    v3 = *i;
    v4 = *(i - 1);
    v5 = i - 1;
    v6 = i;
    if ( *i < v4 )
    {
      do
      {
        *v6 = v4;
        v4 = *(v5 - 1);
        v6 = v5--;
      }
      while ( v3 < v4 );
    }
    ++i;
  }
}
