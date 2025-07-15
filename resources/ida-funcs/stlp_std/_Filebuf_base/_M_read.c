int __thiscall stlp_std::_Filebuf_base::_M_read(stlp_std::_Filebuf_base *this, char *buf, DWORD n)
{
  int v4; // esi
  unsigned int *p_NumberOfBytesRead; // eax
  DWORD v6; // ebx
  char *v7; // edi
  char *v8; // esi
  unsigned int v9; // ebx
  char v10; // al
  char v11; // al
  void *M_file_id; // [esp-18h] [ebp-34h]
  char Buffer; // [esp+Fh] [ebp-Dh] BYREF
  unsigned int v15; // [esp+10h] [ebp-Ch] BYREF
  unsigned int NumberOfBytesRead; // [esp+14h] [ebp-8h] BYREF
  DWORD v17; // [esp+18h] [ebp-4h]

  v4 = 0;
  v15 = n;
  NumberOfBytesRead = -1;
  p_NumberOfBytesRead = &v15;
  if ( n == -1 )
    p_NumberOfBytesRead = &NumberOfBytesRead;
  v6 = *p_NumberOfBytesRead;
  v17 = v6;
  if ( n >= v6 )
  {
    while ( 1 )
    {
      v7 = &buf[v4];
      ReadFile(this->_M_file_id, &buf[v4], v6, &NumberOfBytesRead, 0);
      if ( !NumberOfBytesRead )
        break;
      if ( (this->_M_openmode & 4) != 0 )
      {
        v4 += NumberOfBytesRead;
      }
      else
      {
        v8 = &buf[v4];
        v9 = (unsigned int)&v7[NumberOfBytesRead - 1];
        if ( (unsigned int)v7 <= v9 )
        {
          while ( 1 )
          {
            v10 = *v7;
            if ( *v7 == 26 )
              goto LABEL_15;
            if ( v10 != 13 )
              break;
            if ( (unsigned int)v7 >= v9 )
            {
              M_file_id = this->_M_file_id;
              Buffer = 32;
              ReadFile(M_file_id, &Buffer, 1u, &v15, 0);
              if ( v15 )
              {
                v11 = Buffer;
                if ( Buffer == 10 )
                {
                  *v8 = 10;
                }
                else
                {
                  *v8++ = 13;
                  if ( v8 >= &buf[n] || v11 == 13 )
                  {
                    SetFilePointer(this->_M_file_id, -1, 0, 1u);
                    goto LABEL_14;
                  }
                  *v8 = v11;
                }
              }
              else
              {
LABEL_12:
                *v8 = 13;
              }
LABEL_13:
              ++v8;
              goto LABEL_14;
            }
            if ( v7[1] != 10 )
              goto LABEL_12;
LABEL_14:
            if ( (unsigned int)++v7 > v9 )
              goto LABEL_15;
          }
          *v8 = v10;
          goto LABEL_13;
        }
LABEL_15:
        v4 = v8 - buf;
        if ( (unsigned int)v7 <= v9 )
        {
          SetFilePointer(this->_M_file_id, (LONG)&v7[-v9 - 1], 0, 1u);
          return v4;
        }
        v6 = v17;
      }
      if ( n - v4 < v6 )
        return v4;
    }
  }
  return v4;
}
