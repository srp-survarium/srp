int __usercall sub_484DC0@<eax>(int a1@<esi>)
{
  _DWORD *v1; // ebx
  _DWORD *v2; // edi
  int v3; // ebp
  int result; // eax
  int *v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  v1 = *(_DWORD **)(a1 + 424);
  if ( !(*(unsigned __int8 (**)(void))(*(_DWORD *)(a1 + 420) + 8))() )
  {
    *(_DWORD *)(*(_DWORD *)a1 + 20) = 25;
    (**(void (__cdecl ***)(int))a1)(a1);
  }
  v6 = 0;
  if ( *(int *)(a1 + 296) > 0 )
  {
    v2 = v1 + 9;
    v5 = (int *)(a1 + 300);
    while ( 1 )
    {
      v3 = *v5;
      if ( !*(_BYTE *)(a1 + 201) || !*(_DWORD *)(a1 + 368) && !*(_DWORD *)(a1 + 376) )
      {
        memset(v1[*(_DWORD *)(v3 + 20) + 14], 0, 64);
        *(v2 - 4) = 0;
        *v2 = 0;
      }
      if ( !*(_BYTE *)(a1 + 201) )
        break;
      if ( *(_DWORD *)(a1 + 368) )
        goto LABEL_13;
LABEL_14:
      ++v5;
      ++v2;
      if ( ++v6 >= *(_DWORD *)(a1 + 296) )
        goto LABEL_15;
    }
    if ( !*(_DWORD *)(a1 + 392) )
      goto LABEL_14;
LABEL_13:
    memset(v1[*(_DWORD *)(v3 + 24) + 30], 0, 256);
    goto LABEL_14;
  }
LABEL_15:
  result = 0;
  v1[2] = 0;
  v1[3] = 0;
  v1[4] = -16;
  v1[13] = *(_DWORD *)(a1 + 252);
  return result;
}
