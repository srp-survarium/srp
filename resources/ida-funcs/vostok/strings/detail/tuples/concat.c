void __userpurge vostok::strings::detail::tuples::concat(
        vostok::strings::detail::tuples *this@<ecx>,
        int a2@<esi>,
        char *result)
{
  unsigned __int8 *v3; // edi
  unsigned int *v4; // ebx
  unsigned int dst; // [esp+Ch] [ebp+8h]

  memcpy((unsigned __int8 *)result, *(unsigned __int8 **)a2, *(_DWORD *)(a2 + 4));
  v3 = (unsigned __int8 *)&result[*(_DWORD *)(a2 + 4)];
  dst = 1;
  if ( *(_DWORD *)(a2 + 48) > 1u )
  {
    v4 = (unsigned int *)(a2 + 12);
    do
    {
      memcpy(v3, (unsigned __int8 *)*(v4 - 1), *v4);
      v3 += *v4;
      ++dst;
      v4 += 2;
    }
    while ( dst < *(_DWORD *)(a2 + 48) );
  }
  *v3 = 0;
}
