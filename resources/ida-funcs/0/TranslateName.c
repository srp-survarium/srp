BOOL __cdecl TranslateName(const tagLOCALETAB *lpTable, int high, char **ppchName)
{
  int v3; // ebx
  signed int v4; // eax
  int v5; // esi
  const tagLOCALETAB *v6; // edi

  v3 = 0;
  v4 = 1;
  while ( v3 <= high )
  {
    if ( !v4 )
      break;
    v5 = (v3 + high) / 2;
    v6 = &lpTable[v5];
    v4 = _stricmp(v3, (int)v6, *ppchName, v6->szName);
    if ( v4 )
    {
      if ( v4 >= 0 )
        v3 = v5 + 1;
      else
        high = v5 - 1;
    }
    else
    {
      *ppchName = v6->chAbbrev;
    }
  }
  return v4 == 0;
}
