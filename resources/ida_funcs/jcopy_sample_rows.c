void __cdecl jcopy_sample_rows(int a1, int a2, int a3, int a4, int a5, unsigned int count)
{
  int v6; // ebx
  unsigned __int8 **v7; // esi
  unsigned __int8 **i; // edi
  unsigned __int8 *v9; // [esp-10h] [ebp-1Ch]
  unsigned __int8 *v10; // [esp-Ch] [ebp-18h]

  v6 = a5;
  v7 = (unsigned __int8 **)(a1 + 4 * a2);
  for ( i = (unsigned __int8 **)(a3 + 4 * a4); v6 > 0; --v6 )
  {
    v10 = *v7;
    v9 = *i;
    ++v7;
    ++i;
    memcpy(v9, v10, count);
  }
}
