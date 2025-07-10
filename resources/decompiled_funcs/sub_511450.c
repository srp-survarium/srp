BOOL __cdecl sub_511450(unsigned __int8 *a1, int a2, char *first, int a4, int a5)
{
  BOOL v26; // [esp+6Ch] [ebp-30h]
  BOOL v27; // [esp+70h] [ebp-2Ch]
  BOOL v28; // [esp+74h] [ebp-28h]
  BOOL v29; // [esp+78h] [ebp-24h]
  BOOL v30; // [esp+7Ch] [ebp-20h]
  BOOL v31; // [esp+80h] [ebp-1Ch]
  int v32; // [esp+84h] [ebp-18h]
  int v33; // [esp+88h] [ebp-14h]
  int v34; // [esp+8Ch] [ebp-10h] BYREF
  int v35; // [esp+90h] [ebp-Ch]
  int v36; // [esp+94h] [ebp-8h]
  int v37; // [esp+98h] [ebp-4h]
  unsigned __int8 *v38; // [esp+A4h] [ebp+8h]

  v36 = *a1;
  v38 = a1 + 1;
  if ( (a4 & 8) != 0 )
  {
    while ( 1 )
    {
LABEL_2:
      while ( (*(_BYTE *)(*(_DWORD *)(a5 + 12) + (unsigned __int8)*first) & 1) != 0 )
        ++first;
      if ( *first != 35 )
        break;
      ++first;
      while ( *first )
      {
        if ( *(_DWORD *)(a5 + 96) )
        {
          v31 = (unsigned int)first < *(_DWORD *)(a5 + 28)
             && _pcre_is_newline(first, *(_DWORD *)(a5 + 96), *(_DWORD *)(a5 + 28), a5 + 100, a2);
          v30 = v31;
        }
        else
        {
          v29 = (unsigned int)first <= *(_DWORD *)(a5 + 28) - *(_DWORD *)(a5 + 100)
             && *first == *(_BYTE *)(a5 + 104)
             && (*(_DWORD *)(a5 + 100) == 1 || first[1] == *(_BYTE *)(a5 + 105));
          v30 = v29;
        }
        if ( v30 )
        {
          first += *(_DWORD *)(a5 + 100);
          goto LABEL_2;
        }
        ++first;
        if ( a2 )
        {
          while ( (*first & 0xC0) == 0x80 )
            ++first;
        }
      }
    }
  }
  if ( *first == 92 )
  {
    v34 = 0;
    v37 = sub_50F7B0((int)&first, &v34, *(_DWORD *)(a5 + 56), a4, 0);
    if ( v34 )
      return 0;
    ++first;
  }
  else
  {
    if ( (*(_BYTE *)(*(_DWORD *)(a5 + 12) + (unsigned __int8)*first) & 0x80) != 0 )
      return 0;
    if ( a2 )
    {
      v37 = (unsigned __int8)*first++;
      if ( v37 >= 192 )
      {
        if ( (v37 & 0x20) != 0 )
        {
          if ( (v37 & 0x10) != 0 )
          {
            if ( (v37 & 8) != 0 )
            {
              if ( (v37 & 4) != 0 )
              {
                v37 = first[4] & 0x3F
                    | ((first[3] & 0x3F) << 6)
                    | ((first[2] & 0x3F) << 12)
                    | ((first[1] & 0x3F) << 18)
                    | ((*first & 0x3F) << 24)
                    | ((v37 & 1) << 30);
                first += 5;
              }
              else
              {
                v37 = first[3] & 0x3F
                    | ((first[2] & 0x3F) << 6)
                    | ((first[1] & 0x3F) << 12)
                    | ((*first & 0x3F) << 18)
                    | ((v37 & 3) << 24);
                first += 4;
              }
            }
            else
            {
              v37 = first[2] & 0x3F | ((first[1] & 0x3F) << 6) | ((*first & 0x3F) << 12) | ((v37 & 7) << 18);
              first += 3;
            }
          }
          else
          {
            v37 = first[1] & 0x3F | ((*first & 0x3F) << 6) | ((v37 & 0xF) << 12);
            first += 2;
          }
        }
        else
        {
          v37 = *first++ & 0x3F | ((v37 & 0x1F) << 6);
        }
      }
    }
    else
    {
      v37 = (unsigned __int8)*first++;
    }
  }
  if ( (a4 & 8) != 0 )
  {
    while ( 1 )
    {
LABEL_47:
      while ( (*(_BYTE *)(*(_DWORD *)(a5 + 12) + (unsigned __int8)*first) & 1) != 0 )
        ++first;
      if ( *first != 35 )
        break;
      ++first;
      while ( *first )
      {
        if ( *(_DWORD *)(a5 + 96) )
        {
          v28 = (unsigned int)first < *(_DWORD *)(a5 + 28)
             && _pcre_is_newline(first, *(_DWORD *)(a5 + 96), *(_DWORD *)(a5 + 28), a5 + 100, a2);
          v27 = v28;
        }
        else
        {
          v26 = (unsigned int)first <= *(_DWORD *)(a5 + 28) - *(_DWORD *)(a5 + 100)
             && *first == *(_BYTE *)(a5 + 104)
             && (*(_DWORD *)(a5 + 100) == 1 || first[1] == *(_BYTE *)(a5 + 105));
          v27 = v26;
        }
        if ( v27 )
        {
          first += *(_DWORD *)(a5 + 100);
          goto LABEL_47;
        }
        ++first;
        if ( a2 )
        {
          while ( (*first & 0xC0) == 0x80 )
            ++first;
        }
      }
    }
  }
  if ( *first == 42 || *first == 63 || !strncmp(first, "{0,", 3u) )
    return 0;
  if ( v37 >= 0 )
  {
    switch ( v36 )
    {
      case 6:
        return v37 <= 127 && (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v37) & 4) != 0;
      case 7:
        return v37 > 127 || (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v37) & 4) == 0;
      case 8:
        return v37 <= 127 && (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v37) & 1) != 0;
      case 9:
        return v37 > 127 || (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v37) & 1) == 0;
      case 10:
        return v37 <= 127 && (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v37) & 0x10) != 0;
      case 11:
        return v37 > 127 || (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v37) & 0x10) == 0;
      case 17:
      case 20:
      case 21:
        if ( v37 > 133 )
        {
          if ( v37 < 8232 || v37 > 8233 )
            return v36 != 20;
        }
        else if ( v37 != 133 && (v37 < 10 || v37 > 13) )
        {
          return v36 != 20;
        }
        return v36 == 20;
      case 18:
      case 19:
        if ( v37 > 6158 )
        {
          if ( v37 <= 8287 )
          {
            if ( v37 != 8287 && (v37 < 0x2000 || v37 > 8202 && v37 != 8239) )
              return v36 != 18;
            return v36 == 18;
          }
          if ( v37 == 12288 )
            return v36 == 18;
        }
        else
        {
          if ( v37 == 6158 )
            return v36 == 18;
          if ( v37 <= 160 )
          {
            if ( v37 != 160 && v37 != 9 && v37 != 32 )
              return v36 != 18;
            return v36 == 18;
          }
          if ( v37 == 5760 )
            return v36 == 18;
        }
        return v36 != 18;
      case 29:
        v35 = *v38;
        if ( a2 && v35 >= 192 )
        {
          if ( (v35 & 0x20) != 0 )
          {
            if ( (v35 & 0x10) != 0 )
            {
              if ( (v35 & 8) != 0 )
              {
                if ( (v35 & 4) != 0 )
                  v35 = v38[5] & 0x3F
                      | ((v38[4] & 0x3F) << 6)
                      | ((v38[3] & 0x3F) << 12)
                      | ((v38[2] & 0x3F) << 18)
                      | ((v38[1] & 0x3F) << 24)
                      | ((v35 & 1) << 30);
                else
                  v35 = v38[4] & 0x3F
                      | ((v38[3] & 0x3F) << 6)
                      | ((v38[2] & 0x3F) << 12)
                      | ((v38[1] & 0x3F) << 18)
                      | ((v35 & 3) << 24);
              }
              else
              {
                v35 = v38[3] & 0x3F | ((v38[2] & 0x3F) << 6) | ((v38[1] & 0x3F) << 12) | ((v35 & 7) << 18);
              }
            }
            else
            {
              v35 = v38[2] & 0x3F | ((v38[1] & 0x3F) << 6) | ((v35 & 0xF) << 12);
            }
          }
          else
          {
            v35 = v38[1] & 0x3F | ((v35 & 0x1F) << 6);
          }
        }
        return v35 != v37;
      case 30:
        v35 = *v38;
        if ( a2 && v35 >= 192 )
        {
          if ( (v35 & 0x20) != 0 )
          {
            if ( (v35 & 0x10) != 0 )
            {
              if ( (v35 & 8) != 0 )
              {
                if ( (v35 & 4) != 0 )
                  v35 = v38[5] & 0x3F
                      | ((v38[4] & 0x3F) << 6)
                      | ((v38[3] & 0x3F) << 12)
                      | ((v38[2] & 0x3F) << 18)
                      | ((v38[1] & 0x3F) << 24)
                      | ((v35 & 1) << 30);
                else
                  v35 = v38[4] & 0x3F
                      | ((v38[3] & 0x3F) << 6)
                      | ((v38[2] & 0x3F) << 12)
                      | ((v38[1] & 0x3F) << 18)
                      | ((v35 & 3) << 24);
              }
              else
              {
                v35 = v38[3] & 0x3F | ((v38[2] & 0x3F) << 6) | ((v38[1] & 0x3F) << 12) | ((v35 & 7) << 18);
              }
            }
            else
            {
              v35 = v38[2] & 0x3F | ((v38[1] & 0x3F) << 6) | ((v35 & 0xF) << 12);
            }
          }
          else
          {
            v35 = v38[1] & 0x3F | ((v35 & 0x1F) << 6);
          }
        }
        if ( v35 == v37 )
          return 0;
        if ( !a2 )
          return v35 != *(unsigned __int8 *)(*(_DWORD *)(a5 + 4) + v37);
        if ( v37 >= 128 )
          v33 = -1;
        else
          v33 = *(unsigned __int8 *)(*(_DWORD *)(a5 + 4) + v37);
        return v35 != v33;
      case 31:
        v35 = *v38;
        return v35 == v37;
      case 32:
        v35 = *v38;
        if ( v35 == v37 )
          return 1;
        if ( !a2 )
          return v35 == *(unsigned __int8 *)(*(_DWORD *)(a5 + 4) + v37);
        if ( v37 >= 128 )
          v32 = -1;
        else
          v32 = *(unsigned __int8 *)(*(_DWORD *)(a5 + 4) + v37);
        return v35 == v32;
      default:
        return 0;
    }
  }
  switch ( v36 )
  {
    case 6:
      return v37 == -7;
    case 7:
      return v37 == -6 || v37 == -9 || v37 == -10 || v37 == -19 || v37 == -21 || v37 == -17;
    case 8:
      return v37 == -9 || v37 == -19 || v37 == -21;
    case 9:
      return v37 == -8 || v37 == -7 || v37 == -11 || v37 == -17;
    case 10:
      return v37 == -11 || v37 == -7;
    case 11:
      return v37 == -10 || v37 == -9 || v37 == -19 || v37 == -21 || v37 == -17;
    case 17:
    case 21:
      return v37 == -20 || v37 == -7 || v37 == -11;
    case 18:
      return v37 == -19;
    case 19:
      return v37 == -8 || v37 == -18 || v37 == -7 || v37 == -11 || v37 == -21 || v37 == -17;
    case 20:
      return v37 == -21 || v37 == -17;
    case 29:
    case 30:
      v35 = *v38;
      if ( a2 && v35 >= 192 )
      {
        if ( (v35 & 0x20) != 0 )
        {
          if ( (v35 & 0x10) != 0 )
          {
            if ( (v35 & 8) != 0 )
            {
              if ( (v35 & 4) != 0 )
                v35 = v38[5] & 0x3F
                    | ((v38[4] & 0x3F) << 6)
                    | ((v38[3] & 0x3F) << 12)
                    | ((v38[2] & 0x3F) << 18)
                    | ((v38[1] & 0x3F) << 24)
                    | ((v35 & 1) << 30);
              else
                v35 = v38[4] & 0x3F
                    | ((v38[3] & 0x3F) << 6)
                    | ((v38[2] & 0x3F) << 12)
                    | ((v38[1] & 0x3F) << 18)
                    | ((v35 & 3) << 24);
            }
            else
            {
              v35 = v38[3] & 0x3F | ((v38[2] & 0x3F) << 6) | ((v38[1] & 0x3F) << 12) | ((v35 & 7) << 18);
            }
          }
          else
          {
            v35 = v38[2] & 0x3F | ((v38[1] & 0x3F) << 6) | ((v35 & 0xF) << 12);
          }
        }
        else
        {
          v35 = v38[1] & 0x3F | ((v35 & 0x1F) << 6);
        }
      }
      break;
    default:
      return 0;
  }
  switch ( -v37 )
  {
    case 6:
      return v35 <= 127 && (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v35) & 4) != 0;
    case 7:
      return v35 > 127 || (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v35) & 4) == 0;
    case 8:
      return v35 <= 127 && (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v35) & 1) != 0;
    case 9:
      return v35 > 127 || (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v35) & 1) == 0;
    case 10:
      return v35 <= 127 && (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v35) & 0x10) != 0;
    case 11:
      return v35 > 127 || (*(_BYTE *)(*(_DWORD *)(a5 + 12) + v35) & 0x10) == 0;
    case 18:
    case 19:
      if ( v35 > 6158 )
      {
        if ( v35 <= 8287 )
        {
          if ( v35 != 8287 && (v35 < 0x2000 || v35 > 8202 && v35 != 8239) )
            return -v37 == 19;
          return -v37 != 19;
        }
        if ( v35 == 12288 )
          return -v37 != 19;
      }
      else
      {
        if ( v35 == 6158 )
          return -v37 != 19;
        if ( v35 <= 160 )
        {
          if ( v35 != 160 && v35 != 9 && v35 != 32 )
            return -v37 == 19;
          return -v37 != 19;
        }
        if ( v35 == 5760 )
          return -v37 != 19;
      }
      return -v37 == 19;
    case 20:
    case 21:
      if ( v35 > 133 )
      {
        if ( v35 < 8232 || v35 > 8233 )
          return -v37 == 21;
        return -v37 != 21;
      }
      if ( v35 == 133 || v35 >= 10 && v35 <= 13 )
        return -v37 != 21;
      return -v37 == 21;
    default:
      return 0;
  }
}
