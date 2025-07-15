char __cdecl jpeg_resync_to_restart(_DWORD *a1, int a2)
{
  int v2; // ebx
  int v3; // edi
  int v4; // edi
  int v5; // edi

  v2 = a1[99];
  *(_DWORD *)(*a1 + 20) = 124;
  *(_DWORD *)(*a1 + 24) = v2;
  *(_DWORD *)(*a1 + 28) = a2;
  (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, -1);
  while ( 1 )
  {
    if ( v2 < 192 )
    {
LABEL_3:
      v3 = 2;
      goto LABEL_11;
    }
    if ( (unsigned int)(v2 - 208) > 7 || v2 == (((_BYTE)a2 + 1) & 7) + 208 || v2 == (((_BYTE)a2 + 2) & 7) + 208 )
    {
      v3 = 3;
    }
    else
    {
      if ( v2 == (((_BYTE)a2 - 1) & 7) + 208 || v2 == (((_BYTE)a2 - 2) & 7) + 208 )
        goto LABEL_3;
      v3 = 1;
    }
LABEL_11:
    *(_DWORD *)(*a1 + 20) = 99;
    *(_DWORD *)(*a1 + 24) = v2;
    *(_DWORD *)(*a1 + 28) = v3;
    (*(void (__cdecl **)(_DWORD *, int))(*a1 + 4))(a1, 4);
    v4 = v3 - 1;
    if ( !v4 )
      break;
    v5 = v4 - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
        return 1;
    }
    else
    {
      if ( !sub_47F580(a1) )
        return 0;
      v2 = a1[99];
    }
  }
  a1[99] = 0;
  return 1;
}
