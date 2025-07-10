void __cdecl stlp_std::priv::__insertion_sort<unsigned int *,unsigned int,vostok::render::culling::portal_id_closer_to_point>(
        unsigned int *__first,
        unsigned int *__last,
        unsigned int *__formal)
{
  unsigned __int8 *v3; // ebx
  unsigned int *v4; // esi
  unsigned int *v5; // ebp
  signed int v6; // edi
  unsigned int v7; // eax
  unsigned int *v8; // edx
  unsigned __int8 *i; // eax
  unsigned int v10; // [esp+4h] [ebp-4h]

  v3 = (unsigned __int8 *)__first;
  if ( __first != __last )
  {
    v4 = __first + 1;
    if ( __first + 1 != __last )
    {
      v5 = __formal;
      v6 = 4;
      do
      {
        v7 = *v4;
        v10 = *v4;
        if ( *(float *)&v5[*(_DWORD *)v3] <= *(float *)&v5[*v4] )
        {
          v8 = v4;
          for ( i = &v3[v6 - 4]; *(float *)&v5[*(_DWORD *)i] > *(float *)&v5[v10]; i -= 4 )
          {
            *v8 = *(_DWORD *)i;
            v8 = (unsigned int *)i;
          }
          *v8 = v10;
          v3 = (unsigned __int8 *)__first;
        }
        else
        {
          if ( v6 > 0 )
          {
            memmove((unsigned __int8 *)&v4[v6 / 0xFFFFFFFC + 1], v3, v6);
            v5 = __formal;
            v7 = v10;
          }
          *(_DWORD *)v3 = v7;
        }
        ++v4;
        v6 += 4;
      }
      while ( v4 != __last );
    }
  }
}
