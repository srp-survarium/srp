void __cdecl stlp_std::priv::__insertion_sort<float *,float,stlp_std::less<float>>(float *__first, float *__last)
{
  float *v3; // esi
  int v4; // edi
  float v5; // xmm1_4
  float *v6; // ecx
  float *i; // eax
  float *__lasta; // [esp+10h] [ebp+8h]

  if ( __first != __last )
  {
    v3 = __first + 1;
    if ( __first + 1 != __last )
    {
      v4 = 4;
      do
      {
        v5 = *v3;
        __lasta = *(float **)v3;
        if ( *__first <= *v3 )
        {
          v6 = v3;
          for ( i = &__first[v4 / 4u - 1]; *i > v5; --i )
          {
            *v6 = *i;
            v6 = i;
          }
          *v6 = v5;
        }
        else
        {
          if ( v4 > 0 )
          {
            memmove((unsigned __int8 *)&v3[v4 / 0xFFFFFFFC + 1], (unsigned __int8 *)__first, v4);
            v5 = *(float *)&__lasta;
          }
          *__first = v5;
        }
        ++v3;
        v4 += 4;
      }
      while ( v3 != __last );
    }
  }
}
