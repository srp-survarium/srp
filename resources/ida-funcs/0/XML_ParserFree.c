int __cdecl XML_ParserFree(int a1)
{
  int result; // eax
  int v2; // [esp+0h] [ebp-10h]
  _DWORD *v3; // [esp+4h] [ebp-Ch]
  int v4; // [esp+8h] [ebp-8h]
  _DWORD *v5; // [esp+Ch] [ebp-4h]

  if ( !a1 )
    return result;
  v5 = *(_DWORD **)(a1 + 364);
  while ( 1 )
  {
    if ( v5 )
      goto LABEL_6;
    if ( !*(_DWORD *)(a1 + 368) )
      break;
    v5 = *(_DWORD **)(a1 + 368);
    *(_DWORD *)(a1 + 368) = 0;
LABEL_6:
    v3 = v5;
    v5 = (_DWORD *)*v5;
    (*(void (__cdecl **)(_DWORD))(a1 + 20))(v3[9]);
    sub_6403F0(v3[11], a1);
    (*(void (__cdecl **)(_DWORD *))(a1 + 20))(v3);
  }
  v4 = *(_DWORD *)(a1 + 300);
  while ( 1 )
  {
    if ( v4 )
      goto LABEL_11;
    if ( !*(_DWORD *)(a1 + 304) )
      break;
    v4 = *(_DWORD *)(a1 + 304);
    *(_DWORD *)(a1 + 304) = 0;
LABEL_11:
    v2 = v4;
    v4 = *(_DWORD *)(v4 + 8);
    (*(void (__cdecl **)(int))(a1 + 20))(v2);
  }
  sub_6403F0(*(_DWORD *)(a1 + 376), a1);
  sub_6403F0(*(_DWORD *)(a1 + 372), a1);
  sub_648FA0(a1 + 416);
  sub_648FA0(a1 + 440);
  if ( !*(_BYTE *)(a1 + 488) && *(_DWORD *)(a1 + 356) )
    sub_648850(*(_DWORD *)(a1 + 356), *(_DWORD *)(a1 + 476) == 0, a1 + 12);
  (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 392));
  (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 464));
  (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 8));
  (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 44));
  (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 396));
  (*(void (__cdecl **)(_DWORD))(a1 + 20))(*(_DWORD *)(a1 + 240));
  if ( *(_DWORD *)(a1 + 252) )
    (*(void (__cdecl **)(_DWORD))(a1 + 252))(*(_DWORD *)(a1 + 244));
  return (*(int (__cdecl **)(int))(a1 + 20))(a1);
}
