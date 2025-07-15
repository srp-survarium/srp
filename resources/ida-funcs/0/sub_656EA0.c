int __cdecl sub_656EA0(int a1, unsigned __int8 *a2, unsigned __int8 *a3, _DWORD *a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-1Ch]
  int v6; // [esp+Ch] [ebp-14h]
  int v7; // [esp+14h] [ebp-Ch]
  int v9; // [esp+1Ch] [ebp-4h] BYREF
  char *v10; // [esp+2Ch] [ebp+Ch]
  unsigned __int8 *v11; // [esp+2Ch] [ebp+Ch]

  if ( a2 == a3 )
    return -1;
  if ( *a2 )
    v7 = sub_64FDE0(*a2, a2[1]);
  else
    v7 = *(unsigned __int8 *)(a1 + a2[1] + 76);
  switch ( v7 )
  {
    case 5:
      if ( a3 - a2 < 2 )
        return -2;
      *a4 = a2;
      return 0;
    case 6:
      if ( a3 - a2 < 3 )
        return -2;
      *a4 = a2;
      return 0;
    case 7:
      if ( a3 - a2 < 4 )
        return -2;
      *a4 = a2;
      return 0;
    case 22:
    case 24:
      goto LABEL_9;
    case 29:
      if ( (dword_72DD78[8 * (unsigned __int8)byte_72E278[*a2] + ((int)a2[1] >> 5)] & (1 << (a2[1] & 0x1F))) == 0 )
      {
        *a4 = a2;
        return 0;
      }
LABEL_9:
      v10 = (char *)(a2 + 2);
      break;
    default:
      *a4 = a2;
      return 0;
  }
  while ( 2 )
  {
    if ( v10 == (char *)a3 )
      return -1;
    if ( *v10 )
      v6 = sub_64FDE0(*v10, v10[1]);
    else
      v6 = *(unsigned __int8 *)(a1 + (unsigned __int8)v10[1] + 76);
    switch ( v6 )
    {
      case 5:
        if ( a3 - (unsigned __int8 *)v10 < 2 )
          return -2;
        *a4 = v10;
        return 0;
      case 6:
        if ( a3 - (unsigned __int8 *)v10 < 3 )
          return -2;
        *a4 = v10;
        return 0;
      case 7:
        if ( a3 - (unsigned __int8 *)v10 < 4 )
          return -2;
        *a4 = v10;
        return 0;
      case 9:
      case 10:
      case 21:
        if ( !sub_657450(a1, a2, v10, &v9) )
        {
          *a4 = v10;
          return 0;
        }
        v11 = (unsigned __int8 *)(v10 + 2);
        break;
      case 15:
        if ( sub_657450(a1, a2, v10, &v9) )
        {
          v10 += 2;
          if ( v10 == (char *)a3 )
          {
            return -1;
          }
          else if ( *v10 || v10[1] != 62 )
          {
LABEL_69:
            *a4 = v10;
            return 0;
          }
          else
          {
            *a4 = v10 + 2;
            return v9;
          }
        }
        else
        {
          *a4 = v10;
          return 0;
        }
      case 22:
      case 24:
      case 25:
      case 26:
      case 27:
        goto LABEL_26;
      case 29:
        if ( (dword_72DD78[8 * (unsigned __int8)byte_72E378[(unsigned __int8)*v10] + ((int)(unsigned __int8)v10[1] >> 5)]
            & (1 << (v10[1] & 0x1F))) == 0 )
        {
          *a4 = v10;
          return 0;
        }
LABEL_26:
        v10 += 2;
        continue;
      default:
        goto LABEL_69;
    }
    break;
  }
  while ( 2 )
  {
    if ( v11 == a3 )
      return -1;
    if ( *v11 )
      v5 = sub_64FDE0(*v11, v11[1]);
    else
      v5 = *(unsigned __int8 *)(a1 + v11[1] + 76);
    switch ( v5 )
    {
      case 0:
      case 1:
      case 8:
        *a4 = v11;
        return 0;
      case 5:
        if ( a3 - v11 < 2 )
          return -2;
        v11 += 2;
        continue;
      case 6:
        if ( a3 - v11 < 3 )
          return -2;
        v11 += 3;
        continue;
      case 7:
        if ( a3 - v11 < 4 )
          return -2;
        v11 += 4;
        continue;
      case 15:
        v11 += 2;
        if ( v11 == a3 )
          return -1;
        if ( *v11 || v11[1] != 62 )
          continue;
        *a4 = v11 + 2;
        result = v9;
        break;
      default:
        v11 += 2;
        continue;
    }
    break;
  }
  return result;
}
