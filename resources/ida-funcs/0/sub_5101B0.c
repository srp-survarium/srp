int __cdecl sub_5101B0(int a1, char *first, unsigned int count, int a4, int a5)
{
  int v7; // [esp+0h] [ebp-Ch] BYREF
  int v8; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h]

  v7 = *(_DWORD *)(a1 + 24);
  v8 = 0;
  do
  {
    v9 = sub_510220((int)&v7, a1, first, count, a4, a5, (int)&v8);
    if ( v9 > 0 )
      break;
  }
  while ( *(unsigned __int8 *)v7++ );
  return v9;
}
