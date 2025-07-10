void __cdecl stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,stlp_std::less<unsigned int>>(
        unsigned int *__first,
        unsigned int *__last)
{
  unsigned int *i; // esi
  unsigned int v3; // edi
  unsigned int v4; // ecx
  unsigned int *v5; // eax
  unsigned int *j; // edx

  if ( __first != __last )
  {
    for ( i = __first + 1; i != __last; ++i )
    {
      v3 = *i;
      if ( *i >= *__first )
      {
        v4 = *(i - 1);
        v5 = i - 1;
        for ( j = i; v3 < v4; --v5 )
        {
          *j = v4;
          v4 = *(v5 - 1);
          j = v5;
        }
        *j = v3;
      }
      else
      {
        if ( (char *)i - (char *)__first > 0 )
          memmove((unsigned __int8 *)__first + 4, (unsigned __int8 *)__first, (char *)i - (char *)__first);
        *__first = v3;
      }
    }
  }
}
