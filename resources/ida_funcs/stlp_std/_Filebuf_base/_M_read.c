int __thiscall stlp_std::_Filebuf_base::_M_read(stlp_std::_Filebuf_base *this, char *buf, unsigned int n)
{
  int v4; // esi
  unsigned int *p_NumberOfBytesPeeked; // eax
  unsigned int v6; // ebx
  char *v7; // edi
  char *v8; // esi
  unsigned int v9; // ebx
  char v10; // al
  char v11; // al
  void *M_file_id; // [esp-18h] [ebp-34h]
  char peek; // [esp+Fh] [ebp-Dh] BYREF
  unsigned int NumberOfBytesPeeked; // [esp+10h] [ebp-Ch] BYREF
  unsigned int numberOfBytesRead; // [esp+14h] [ebp-8h] BYREF
  unsigned int chunkSize; // [esp+18h] [ebp-4h]

  v4 = 0;
  NumberOfBytesPeeked = n;
  numberOfBytesRead = -1;
  p_NumberOfBytesPeeked = &NumberOfBytesPeeked;
  if ( n == -1 )
    p_NumberOfBytesPeeked = &numberOfBytesRead;
  v6 = *p_NumberOfBytesPeeked;
  chunkSize = v6;
  if ( n >= v6 )
  {
    while ( 1 )
    {
      v7 = &buf[v4];
      ReadFile(this->_M_file_id, &buf[v4], v6, &numberOfBytesRead, 0);
      if ( !numberOfBytesRead )
        break;
      if ( (this->_M_openmode & 4) != 0 )
      {
        v4 += numberOfBytesRead;
      }
      else
      {
        v8 = &buf[v4];
        v9 = (unsigned int)&v7[numberOfBytesRead - 1];
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
              peek = 32;
              ReadFile(M_file_id, &peek, 1u, &NumberOfBytesPeeked, 0);
              if ( NumberOfBytesPeeked )
              {
                v11 = peek;
                if ( peek == 10 )
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
        v6 = chunkSize;
      }
      if ( n - v4 < v6 )
        return v4;
    }
  }
  return v4;
}
