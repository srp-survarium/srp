int __cdecl sub_536BF0(int a1, unsigned __int8 *a2, unsigned __int8 *a3, unsigned __int8 **a4)
{
  int v5; // [esp+4h] [ebp-48h]
  int v6; // [esp+Ch] [ebp-40h]
  int v7; // [esp+14h] [ebp-38h]
  int v8; // [esp+1Ch] [ebp-30h]
  int v9; // [esp+24h] [ebp-28h]
  int v10; // [esp+2Ch] [ebp-20h]
  int v11; // [esp+34h] [ebp-18h]
  int v12; // [esp+38h] [ebp-14h]
  int v13; // [esp+48h] [ebp-4h]

  v13 = 0;
  while ( a2 != a3 )
  {
    if ( a2[1] )
      v11 = sub_534A50(a2[1], *a2);
    else
      v11 = *(unsigned __int8 *)(a1 + *a2 + 76);
    switch ( v11 )
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
      case 9:
      case 10:
      case 21:
        goto LABEL_39;
      case 14:
        goto LABEL_50;
      case 22:
      case 24:
      case 25:
      case 26:
      case 27:
        goto LABEL_9;
      case 23:
        if ( v13 )
        {
          *a4 = a2;
          return 0;
        }
        v13 = 1;
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( a2[1] )
          v10 = sub_534A50(a2[1], *a2);
        else
          v10 = *(unsigned __int8 *)(a1 + *a2 + 76);
        switch ( v10 )
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
            goto LABEL_29;
          case 29:
            if ( (dword_88A300[8 * (unsigned __int8)byte_88A800[a2[1]] + ((int)*a2 >> 5)] & (1 << (*a2 & 0x1F))) == 0 )
            {
              *a4 = a2;
              return 0;
            }
LABEL_29:
            a2 += 2;
            break;
          default:
            *a4 = a2;
            return 0;
        }
        continue;
      case 29:
        if ( (dword_88A300[8 * (unsigned __int8)byte_88A900[a2[1]] + ((int)*a2 >> 5)] & (1 << (*a2 & 0x1F))) == 0 )
        {
          *a4 = a2;
          return 0;
        }
LABEL_9:
        a2 += 2;
        continue;
      default:
        *a4 = a2;
        return 0;
    }
    while ( 1 )
    {
LABEL_39:
      a2 += 2;
      if ( a2 == a3 )
        return -1;
      v9 = a2[1] ? sub_534A50(a2[1], *a2) : *(unsigned __int8 *)(a1 + *a2 + 76);
      if ( v9 == 14 )
        break;
      if ( v9 < 9 || v9 > 10 && v9 != 21 )
      {
        *a4 = a2;
        return 0;
      }
    }
LABEL_50:
    v13 = 0;
    while ( 1 )
    {
      a2 += 2;
      if ( a2 == a3 )
        return -1;
      v8 = a2[1] ? sub_534A50(a2[1], *a2) : *(unsigned __int8 *)(a1 + *a2 + 76);
      if ( v8 == 12 || v8 == 13 )
        break;
      if ( v8 < 9 || v8 > 10 && v8 != 21 )
      {
        *a4 = a2;
        return 0;
      }
    }
    a2 += 2;
    while ( 1 )
    {
      if ( a2 == a3 )
        return -1;
      v7 = a2[1] ? sub_534A50(a2[1], *a2) : *(unsigned __int8 *)(a1 + *a2 + 76);
      if ( v7 == v8 )
        break;
      switch ( v7 )
      {
        case 0:
        case 1:
        case 8:
          *a4 = a2;
          return 0;
        case 2:
          *a4 = a2;
          return 0;
        case 3:
          v12 = sub_534F70(a1, a2 + 2, a3, &a2);
          if ( v12 > 0 )
            continue;
          if ( !v12 )
            *a4 = a2;
          return v12;
        case 5:
          if ( a3 - a2 < 2 )
            return -2;
          a2 += 2;
          continue;
        case 6:
          if ( a3 - a2 < 3 )
            return -2;
          a2 += 3;
          continue;
        case 7:
          if ( a3 - a2 < 4 )
            return -2;
          a2 += 4;
          break;
        default:
          a2 += 2;
          continue;
      }
    }
    a2 += 2;
    if ( a2 == a3 )
      return -1;
    if ( a2[1] )
      v6 = sub_534A50(a2[1], *a2);
    else
      v6 = *(unsigned __int8 *)(a1 + *a2 + 76);
    switch ( v6 )
    {
      case 9:
      case 10:
      case 21:
LABEL_95:
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( a2[1] )
          v5 = sub_534A50(a2[1], *a2);
        else
          v5 = *(unsigned __int8 *)(a1 + *a2 + 76);
        break;
      case 11:
LABEL_113:
        *a4 = a2 + 2;
        return 1;
      case 17:
LABEL_114:
        a2 += 2;
        if ( a2 == a3 )
          return -1;
        if ( !a2[1] && *a2 == 62 )
        {
          *a4 = a2 + 2;
          return 3;
        }
        else
        {
          *a4 = a2;
          return 0;
        }
      default:
        *a4 = a2;
        return 0;
    }
    switch ( v5 )
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
      case 9:
      case 10:
      case 21:
        goto LABEL_95;
      case 11:
        goto LABEL_113;
      case 17:
        goto LABEL_114;
      case 22:
      case 24:
        goto LABEL_103;
      case 29:
        if ( (dword_88A300[8 * (unsigned __int8)byte_88A800[a2[1]] + ((int)*a2 >> 5)] & (1 << (*a2 & 0x1F))) == 0 )
        {
          *a4 = a2;
          return 0;
        }
LABEL_103:
        a2 += 2;
        break;
      default:
        *a4 = a2;
        return 0;
    }
  }
  return -1;
}
