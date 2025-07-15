int __cdecl sub_645FD0(_DWORD *a1, int a2, int *a3, int a4, _DWORD *a5, char a6)
{
  int result; // eax
  int v7; // [esp+4h] [ebp-14h] BYREF
  _DWORD *v8; // [esp+8h] [ebp-10h]
  _DWORD *v9; // [esp+Ch] [ebp-Ch]
  int v10; // [esp+10h] [ebp-8h]
  int v11; // [esp+14h] [ebp-4h]

  v10 = *a3;
  if ( a2 == a1[36] )
  {
    v8 = a1 + 72;
    a1[72] = v10;
    v9 = a1 + 73;
  }
  else
  {
    v8 = (_DWORD *)a1[75];
    v9 = (_DWORD *)(a1[75] + 4);
  }
  *v8 = v10;
  *a3 = 0;
  v11 = (*(int (__cdecl **)(int, int, int, int *))(a2 + 12))(a2, v10, a4, &v7);
  *v9 = v7;
  switch ( v11 )
  {
    case -4:
    case -1:
      if ( a6 )
      {
        *a5 = v10;
        result = 0;
      }
      else
      {
        result = 2;
      }
      break;
    case -2:
      if ( a6 )
      {
        *a5 = v10;
        result = 0;
      }
      else
      {
        result = 6;
      }
      break;
    case 0:
      *v8 = v7;
      result = 4;
      break;
    case 42:
      if ( a1[20] )
        sub_6475E0(a1, a2, v10, v7);
      *a3 = v7;
      *a5 = v7;
      if ( a1[120] == 2 )
        result = 35;
      else
        result = 0;
      break;
    default:
      *v8 = v7;
      result = 23;
      break;
  }
  return result;
}
