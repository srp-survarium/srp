char __usercall sub_47E040@<al>(int a1@<esi>)
{
  _BYTE *v1; // eax
  int v2; // ecx
  int v3; // eax

  *(_DWORD *)(*(_DWORD *)a1 + 20) = 104;
  (*(void (__cdecl **)(int, int))(*(_DWORD *)a1 + 4))(a1, 1);
  if ( *(_BYTE *)(*(_DWORD *)(a1 + 420) + 12) )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 63;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v1 = (_BYTE *)(a1 + 219);
  v2 = 16;
  do
  {
    *(v1 - 16) = 0;
    *v1 = 1;
    v1[16] = 5;
    ++v1;
    --v2;
  }
  while ( v2 );
  v3 = *(_DWORD *)(a1 + 420);
  *(_DWORD *)(a1 + 252) = 0;
  *(_DWORD *)(a1 + 40) = 0;
  *(_BYTE *)(a1 + 266) = 0;
  *(_BYTE *)(a1 + 256) = 0;
  *(_BYTE *)(a1 + 259) = 0;
  *(_BYTE *)(a1 + 264) = 0;
  *(_BYTE *)(a1 + 265) = 0;
  *(_BYTE *)(a1 + 257) = 1;
  *(_BYTE *)(a1 + 258) = 1;
  *(_WORD *)(a1 + 260) = 1;
  *(_WORD *)(a1 + 262) = 1;
  *(_BYTE *)(v3 + 12) = 1;
  return 1;
}
