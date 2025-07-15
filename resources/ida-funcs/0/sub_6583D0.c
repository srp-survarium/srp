int __cdecl sub_6583D0(int a1, char *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int result; // eax
  int v5; // [esp+4h] [ebp-38h]
  int v6; // [esp+10h] [ebp-2Ch]
  int v7; // [esp+18h] [ebp-24h]
  int v8; // [esp+20h] [ebp-1Ch]
  int v9; // [esp+28h] [ebp-14h]
  int v10; // [esp+30h] [ebp-Ch]
  unsigned int v11; // [esp+34h] [ebp-8h]
  int v12; // [esp+38h] [ebp-4h]
  unsigned __int8 *v13; // [esp+48h] [ebp+Ch]
  unsigned __int8 *v14; // [esp+48h] [ebp+Ch]
  unsigned __int8 *v15; // [esp+48h] [ebp+Ch]
  unsigned __int8 *v16; // [esp+48h] [ebp+Ch]

  if ( a2 == (char *)a3 )
    return -4;
  if ( (((_BYTE)a3 - (_BYTE)a2) & 1) != 0 )
  {
    v11 = (a3 - (unsigned __int8 *)a2) & 0xFFFFFFFE;
    if ( !v11 )
      return -1;
    a3 = (unsigned __int8 *)&a2[v11];
  }
  if ( *a2 )
    v10 = sub_64FDE0(*a2, a2[1]);
  else
    v10 = *(unsigned __int8 *)(a1 + (unsigned __int8)a2[1] + 76);
  switch ( v10 )
  {
    case 2:
      v13 = (unsigned __int8 *)(a2 + 2);
      if ( v13 == a3 )
        return -1;
      if ( *v13 )
        v9 = sub_64FDE0(*v13, v13[1]);
      else
        v9 = *(unsigned __int8 *)(a1 + v13[1] + 76);
      switch ( v9 )
      {
        case 5:
        case 6:
        case 7:
        case 22:
        case 24:
        case 29:
          *a4 = v13 - 2;
          result = 29;
          break;
        case 15:
          result = sub_656EA0(a1, v13 + 2, a3, a4);
          break;
        case 16:
          result = sub_658F30(a1, v13 + 2, a3, a4);
          break;
        default:
          *a4 = v13;
          result = 0;
          break;
      }
      return result;
    case 4:
      v14 = (unsigned __int8 *)(a2 + 2);
      if ( v14 == a3 )
        return -26;
      if ( *v14 || v14[1] != 93 )
        goto LABEL_49;
      if ( v14 + 2 == a3 )
        return -1;
      if ( v14[2] || v14[3] != 62 )
      {
LABEL_49:
        *a4 = v14;
        return 26;
      }
      else
      {
        *a4 = v14 + 4;
        return 34;
      }
    case 5:
      if ( a3 - (unsigned __int8 *)a2 < 2 )
        return -2;
      *a4 = (unsigned __int8 *)a2;
      return 0;
    case 6:
      if ( a3 - (unsigned __int8 *)a2 < 3 )
        return -2;
      *a4 = (unsigned __int8 *)a2;
      return 0;
    case 7:
      if ( a3 - (unsigned __int8 *)a2 < 4 )
        return -2;
      *a4 = (unsigned __int8 *)a2;
      return 0;
    case 9:
      if ( a2 + 2 != (char *)a3 )
        goto LABEL_25;
      *a4 = a3;
      return -15;
    case 10:
    case 21:
LABEL_25:
      while ( 1 )
      {
        a2 += 2;
        if ( a2 == (char *)a3 )
          break;
        if ( *a2 )
          v8 = sub_64FDE0(*a2, a2[1]);
        else
          v8 = *(unsigned __int8 *)(a1 + (unsigned __int8)a2[1] + 76);
        if ( v8 == 9 )
        {
          if ( a2 + 2 == (char *)a3 )
            goto LABEL_34;
        }
        else if ( v8 != 10 && v8 != 21 )
        {
LABEL_34:
          *a4 = (unsigned __int8 *)a2;
          return 15;
        }
      }
      *a4 = (unsigned __int8 *)a2;
      return 15;
    case 11:
      *a4 = (unsigned __int8 *)(a2 + 2);
      return 17;
    case 12:
      return sub_659890(12, a1, a2 + 2, a3, a4);
    case 13:
      return sub_659890(13, a1, a2 + 2, a3, a4);
    case 19:
      return sub_659510(a1, a2 + 2, a3, a4);
    case 20:
      *a4 = (unsigned __int8 *)(a2 + 2);
      return 25;
    case 22:
    case 24:
      v12 = 18;
      v16 = (unsigned __int8 *)(a2 + 2);
      break;
    case 23:
    case 25:
    case 26:
    case 27:
      v12 = 19;
      v16 = (unsigned __int8 *)(a2 + 2);
      break;
    case 29:
      if ( (dword_72DD78[8 * (unsigned __int8)byte_72E278[(unsigned __int8)*a2] + ((int)(unsigned __int8)a2[1] >> 5)]
          & (1 << (a2[1] & 0x1F))) != 0 )
      {
        v16 = (unsigned __int8 *)(a2 + 2);
        v12 = 18;
        break;
      }
      if ( (dword_72DD78[8 * (unsigned __int8)byte_72E378[(unsigned __int8)*a2] + ((int)(unsigned __int8)a2[1] >> 5)]
          & (1 << (a2[1] & 0x1F))) == 0 )
      {
LABEL_79:
        *a4 = (unsigned __int8 *)a2;
        return 0;
      }
      v16 = (unsigned __int8 *)(a2 + 2);
      v12 = 19;
      break;
    case 30:
      return sub_659180(a1, a2 + 2, a3, a4);
    case 31:
      *a4 = (unsigned __int8 *)(a2 + 2);
      return 23;
    case 32:
      v15 = (unsigned __int8 *)(a2 + 2);
      if ( v15 == a3 )
        return -24;
      if ( *v15 )
        v7 = sub_64FDE0(*v15, v15[1]);
      else
        v7 = *(unsigned __int8 *)(a1 + v15[1] + 76);
      switch ( v7 )
      {
        case 9:
        case 10:
        case 11:
        case 21:
        case 32:
        case 35:
        case 36:
          *a4 = v15;
          result = 24;
          break;
        case 15:
          *a4 = v15 + 2;
          result = 35;
          break;
        case 33:
          *a4 = v15 + 2;
          result = 36;
          break;
        case 34:
          *a4 = v15 + 2;
          result = 37;
          break;
        default:
          *a4 = v15;
          result = 0;
          break;
      }
      return result;
    case 35:
      *a4 = (unsigned __int8 *)(a2 + 2);
      return 38;
    case 36:
      *a4 = (unsigned __int8 *)(a2 + 2);
      return 21;
    default:
      goto LABEL_79;
  }
  while ( v16 != a3 )
  {
    if ( *v16 )
      v6 = sub_64FDE0(*v16, v16[1]);
    else
      v6 = *(unsigned __int8 *)(a1 + v16[1] + 76);
    switch ( v6 )
    {
      case 5:
        if ( a3 - v16 < 2 )
          return -2;
        *a4 = v16;
        return 0;
      case 6:
        if ( a3 - v16 < 3 )
          return -2;
        *a4 = v16;
        return 0;
      case 7:
        if ( a3 - v16 < 4 )
          return -2;
        *a4 = v16;
        return 0;
      case 9:
      case 10:
      case 11:
      case 20:
      case 21:
      case 30:
      case 32:
      case 35:
      case 36:
        *a4 = v16;
        return v12;
      case 15:
        if ( v12 == 19 )
        {
          *a4 = v16;
          return 0;
        }
        else
        {
          *a4 = v16 + 2;
          return 30;
        }
      case 22:
      case 24:
      case 25:
      case 26:
      case 27:
        goto LABEL_87;
      case 23:
        v16 += 2;
        if ( v12 == 18 )
        {
          if ( v16 == a3 )
            return -1;
          v12 = 41;
          if ( *v16 )
            v5 = sub_64FDE0(*v16, v16[1]);
          else
            v5 = *(unsigned __int8 *)(a1 + v16[1] + 76);
          switch ( v5 )
          {
            case 5:
              if ( a3 - v16 < 2 )
                return -2;
              *a4 = v16;
              return 0;
            case 6:
              if ( a3 - v16 < 3 )
                return -2;
              *a4 = v16;
              return 0;
            case 7:
              if ( a3 - v16 < 4 )
                return -2;
              *a4 = v16;
              return 0;
            case 22:
            case 24:
            case 25:
            case 26:
            case 27:
              goto LABEL_109;
            case 29:
              if ( (dword_72DD78[8 * (unsigned __int8)byte_72E378[*v16] + ((int)v16[1] >> 5)] & (1 << (v16[1] & 0x1F))) == 0 )
              {
                *a4 = v16;
                return 0;
              }
LABEL_109:
              v16 += 2;
              break;
            default:
              v12 = 19;
              continue;
          }
        }
        else if ( v12 == 41 )
        {
          v12 = 19;
        }
        break;
      case 29:
        if ( (dword_72DD78[8 * (unsigned __int8)byte_72E378[*v16] + ((int)v16[1] >> 5)] & (1 << (v16[1] & 0x1F))) == 0 )
        {
          *a4 = v16;
          return 0;
        }
LABEL_87:
        v16 += 2;
        continue;
      case 33:
        if ( v12 == 19 )
        {
          *a4 = v16;
          return 0;
        }
        else
        {
          *a4 = v16 + 2;
          return 31;
        }
      case 34:
        if ( v12 == 19 )
        {
          *a4 = v16;
          return 0;
        }
        else
        {
          *a4 = v16 + 2;
          return 32;
        }
      default:
        *a4 = v16;
        return 0;
    }
  }
  return -v12;
}
