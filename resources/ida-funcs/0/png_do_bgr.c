int __cdecl png_do_bgr(unsigned int *a1, char *a2)
{
  int result; // eax
  char v3; // [esp+3h] [ebp-31h]
  char v4; // [esp+3h] [ebp-31h]
  char *v5; // [esp+4h] [ebp-30h]
  unsigned int v6; // [esp+8h] [ebp-2Ch]
  char v7; // [esp+Fh] [ebp-25h]
  char v8; // [esp+Fh] [ebp-25h]
  char *j; // [esp+10h] [ebp-24h]
  unsigned int v10; // [esp+14h] [ebp-20h]
  char v11; // [esp+1Bh] [ebp-19h]
  char *i; // [esp+1Ch] [ebp-18h]
  unsigned int v13; // [esp+20h] [ebp-14h]
  char v14; // [esp+27h] [ebp-Dh]
  char *v15; // [esp+28h] [ebp-Ch]
  unsigned int v16; // [esp+2Ch] [ebp-8h]
  unsigned int v17; // [esp+30h] [ebp-4h]

  result = (int)a1;
  if ( (a1[2] & 2) != 0 )
  {
    v17 = *a1;
    if ( *((_BYTE *)a1 + 9) == 8 )
    {
      result = (int)a1;
      if ( *((_BYTE *)a1 + 8) == 2 )
      {
        v16 = 0;
        v15 = a2;
        while ( v16 < v17 )
        {
          v14 = *v15;
          *v15 = v15[2];
          v15[2] = v14;
          result = ++v16;
          v15 += 3;
        }
      }
      else if ( *((_BYTE *)a1 + 8) == 6 )
      {
        v13 = 0;
        for ( i = a2; ; i += 4 )
        {
          result = v13;
          if ( v13 >= v17 )
            break;
          v11 = *i;
          *i = i[2];
          i[2] = v11;
          ++v13;
        }
      }
    }
    else
    {
      result = *((unsigned __int8 *)a1 + 9);
      if ( result == 16 )
      {
        if ( *((_BYTE *)a1 + 8) == 2 )
        {
          v10 = 0;
          for ( j = a2; ; j += 6 )
          {
            result = v10;
            if ( v10 >= v17 )
              break;
            v7 = *j;
            *j = j[4];
            j[4] = v7;
            v8 = j[1];
            j[1] = j[5];
            j[5] = v8;
            ++v10;
          }
        }
        else
        {
          result = (int)a1;
          if ( *((_BYTE *)a1 + 8) == 6 )
          {
            v6 = 0;
            v5 = a2;
            while ( v6 < v17 )
            {
              v3 = *v5;
              *v5 = v5[4];
              v5[4] = v3;
              v4 = v5[1];
              v5[1] = v5[5];
              v5[5] = v4;
              result = ++v6;
              v5 += 8;
            }
          }
        }
      }
    }
  }
  return result;
}
