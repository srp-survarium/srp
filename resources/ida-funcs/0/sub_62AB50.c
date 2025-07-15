int __cdecl sub_62AB50(int a1, _DWORD *a2, int a3, int a4, int a5)
{
  int v5; // edx
  int v6; // ecx
  int v8; // [esp+8h] [ebp-38h]
  int v9; // [esp+Ch] [ebp-34h]
  unsigned __int8 *v10; // [esp+10h] [ebp-30h]
  int v11; // [esp+14h] [ebp-2Ch]
  int v12; // [esp+18h] [ebp-28h]
  _BYTE *i; // [esp+1Ch] [ebp-24h]
  int v14; // [esp+20h] [ebp-20h]
  int v15; // [esp+24h] [ebp-1Ch]
  int v16; // [esp+28h] [ebp-18h]
  unsigned __int8 *v17; // [esp+2Ch] [ebp-14h]
  int m; // [esp+34h] [ebp-Ch]
  _BYTE *v19; // [esp+38h] [ebp-8h]
  unsigned __int8 *v20; // [esp+38h] [ebp-8h]
  int v21; // [esp+3Ch] [ebp-4h]
  int j; // [esp+3Ch] [ebp-4h]
  int k; // [esp+3Ch] [ebp-4h]

  m = *(unsigned __int8 *)(*(_DWORD *)a1 + 1);
  v19 = (_BYTE *)(*(_DWORD *)a1 + 2);
  if ( (a4 & 0x800) != 0 && *(unsigned __int8 *)(*(_DWORD *)a1 + 1) >= 0xC0u )
  {
    if ( (m & 0x20) != 0 )
    {
      if ( (m & 0x10) != 0 )
      {
        if ( (m & 8) != 0 )
        {
          if ( (m & 4) != 0 )
          {
            m = *(_BYTE *)(*(_DWORD *)a1 + 6) & 0x3F
              | ((v19[3] & 0x3F) << 6)
              | ((v19[2] & 0x3F) << 12)
              | ((v19[1] & 0x3F) << 18)
              | ((*v19 & 0x3F) << 24)
              | ((m & 1) << 30);
            v19 = (_BYTE *)(*(_DWORD *)a1 + 7);
          }
          else
          {
            m = v19[3] & 0x3F
              | ((v19[2] & 0x3F) << 6)
              | ((v19[1] & 0x3F) << 12)
              | ((*v19 & 0x3F) << 18)
              | ((m & 3) << 24);
            v19 = (_BYTE *)(*(_DWORD *)a1 + 6);
          }
        }
        else
        {
          m = *(_BYTE *)(*(_DWORD *)a1 + 4) & 0x3F
            | ((*(_BYTE *)(*(_DWORD *)a1 + 3) & 0x3F) << 6)
            | ((*(_BYTE *)(*(_DWORD *)a1 + 2) & 0x3F) << 12)
            | ((m & 7) << 18);
          v19 = (_BYTE *)(*(_DWORD *)a1 + 5);
        }
      }
      else
      {
        m = *(_BYTE *)(*(_DWORD *)a1 + 3) & 0x3F | ((*(_BYTE *)(*(_DWORD *)a1 + 2) & 0x3F) << 6) | ((m & 0xF) << 12);
        v19 = (_BYTE *)(*(_DWORD *)a1 + 4);
      }
    }
    else
    {
      m = *v19 & 0x3F | ((m & 0x1F) << 6);
      v19 = (_BYTE *)(*(_DWORD *)a1 + 3);
    }
  }
  v20 = v19 - 1;
  if ( m )
  {
    if ( m >= 48 && m <= 122 )
    {
      v21 = *(__int16 *)&aInstancesFlVec_3[2 * m + 24];
      if ( *(_WORD *)&aInstancesFlVec_3[2 * m + 24] )
      {
        m = *(__int16 *)&aInstancesFlVec_3[2 * m + 24];
      }
      else
      {
        switch ( m )
        {
          case '0':
            goto LABEL_82;
          case '1':
          case '2':
          case '3':
          case '4':
          case '5':
          case '6':
          case '7':
          case '8':
          case '9':
            if ( a5 )
              goto LABEL_80;
            v17 = v20;
            m -= 48;
            while ( (byte_72C7A8[v20[1]] & 4) != 0 )
              m = 10 * m + *++v20 - 48;
            if ( m >= 0 )
            {
              if ( m >= 10 && m > a3 )
              {
                v20 = v17;
LABEL_80:
                m = *v20;
                if ( (unsigned int)m < 0x38 )
                {
LABEL_82:
                  for ( m -= 48; ; m = *v20 + 8 * m - 48 )
                  {
                    v5 = v21++;
                    if ( v5 >= 2 || v20[1] < 0x30u || v20[1] > 0x37u )
                      break;
                    ++v20;
                  }
                  if ( (a4 & 0x800) == 0 && m > 255 )
                    *a2 = 51;
                }
                else
                {
                  --v20;
                  m = 0;
                }
              }
              else
              {
                m = -(m + 35);
              }
            }
            else
            {
              *a2 = 61;
            }
            break;
          case 'L':
          case 'l':
            *a2 = 37;
            break;
          case 'U':
            if ( (a4 & 0x2000000) == 0 )
              *a2 = 37;
            break;
          case 'c':
            m = *++v20;
            if ( *v20 )
            {
              if ( *v20 <= 0x7Fu )
              {
                if ( *v20 >= 0x61u && *v20 <= 0x7Au )
                  m -= 32;
                m ^= 0x40u;
              }
              else
              {
                *a2 = 68;
              }
            }
            else
            {
              *a2 = 2;
            }
            break;
          case 'g':
            if ( a5 )
              break;
            if ( v20[1] == 60 || v20[1] == 39 )
            {
              m = -27;
              break;
            }
            if ( v20[1] == 123 )
            {
              for ( i = v20 + 2; *i && *i != 125 && (*i == 45 || (byte_72C7A8[(unsigned __int8)*i] & 4) != 0); ++i )
                ;
              if ( *i && *i != 125 )
              {
                m = -28;
                break;
              }
              v15 = 1;
              ++v20;
            }
            else
            {
              v15 = 0;
            }
            if ( v20[1] == 45 )
            {
              v16 = 1;
              ++v20;
            }
            else
            {
              v16 = 0;
            }
            m = 0;
            while ( (byte_72C7A8[v20[1]] & 4) != 0 )
              m = 10 * m + *++v20 - 48;
            if ( m < 0 )
            {
              *a2 = 61;
              break;
            }
            if ( v15 )
            {
              if ( *++v20 != 125 )
              {
                *a2 = 57;
                break;
              }
            }
            if ( !m )
            {
              *a2 = 58;
              break;
            }
            if ( !v16 )
              goto LABEL_69;
            if ( m <= a3 )
            {
              m = a3 - (m - 1);
LABEL_69:
              m = -(m + 35);
            }
            else
            {
              *a2 = 15;
            }
            break;
          case 'u':
            if ( (a4 & 0x2000000) != 0 )
            {
              if ( (byte_72C7A8[v20[1]] & 8) != 0
                && (byte_72C7A8[v20[2]] & 8) != 0
                && (byte_72C7A8[v20[3]] & 8) != 0
                && (byte_72C7A8[v20[4]] & 8) != 0 )
              {
                m = 0;
                for ( j = 0; j < 4; ++j )
                {
                  v14 = *++v20;
                  if ( (unsigned int)v14 >= 0x61 )
                    v14 -= 32;
                  m = v14 + 16 * m - (v14 >= 65 ? 55 : 48);
                }
              }
            }
            else
            {
              *a2 = 37;
            }
            break;
          case 'x':
            if ( (a4 & 0x2000000) != 0 )
            {
              if ( (byte_72C7A8[v20[1]] & 8) != 0 && (byte_72C7A8[v20[2]] & 8) != 0 )
              {
                m = 0;
                for ( k = 0; k < 2; ++k )
                {
                  v12 = *++v20;
                  if ( (unsigned int)v12 >= 0x61 )
                    v12 -= 32;
                  m = v12 + 16 * m - (v12 >= 65 ? 55 : 48);
                }
              }
            }
            else
            {
              if ( v20[1] != 123 )
                goto LABEL_113;
              v10 = v20 + 2;
              v11 = 0;
              m = 0;
              while ( (byte_72C7A8[*v10] & 8) != 0 )
              {
                v9 = *v10++;
                if ( m || v9 != 48 )
                {
                  ++v11;
                  if ( v9 >= 97 )
                    v9 -= 32;
                  m = v9 + 16 * m - (v9 >= 65 ? 55 : 48);
                }
              }
              if ( *v10 == 125 )
              {
                if ( m < 0 || v11 > ((a4 & 0x800) != 0 ? 8 : 2) )
                  *a2 = 34;
                v20 = v10;
              }
              else
              {
LABEL_113:
                for ( m = 0; ; m = v8 + 16 * m - (v8 >= 65 ? 55 : 48) )
                {
                  v6 = v21++;
                  if ( v6 >= 2 || (byte_72C7A8[v20[1]] & 8) == 0 )
                    break;
                  v8 = *++v20;
                  if ( (unsigned int)v8 >= 0x61 )
                    v8 -= 32;
                }
              }
            }
            break;
          default:
            if ( (a4 & 0x40) != 0 )
              *a2 = 3;
            break;
        }
      }
    }
  }
  else
  {
    *a2 = 1;
  }
  if ( m == -12 && v20[1] == 123 && !sub_62AA80(v20 + 2) )
    *a2 = 37;
  if ( (a4 & 0x20000000) != 0 && m <= -6 && m >= -11 )
    m -= 23;
  *(_DWORD *)a1 = v20;
  return m;
}
