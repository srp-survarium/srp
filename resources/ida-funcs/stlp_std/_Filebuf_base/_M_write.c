char __thiscall stlp_std::_Filebuf_base::_M_write(stlp_std::_Filebuf_base *this, char *buf, int n)
{
  stlp_std::_Filebuf_base *v5; // ebp
  bool v6; // zf
  char *v7; // esi
  int v8; // edi
  DWORD *v9; // eax
  unsigned __int8 *v10; // edi
  char *v11; // ebx
  unsigned __int8 *v12; // esi
  signed int *v13; // eax
  signed int v14; // ebp
  int v15; // eax
  int v16; // ebp
  unsigned __int8 *v17; // esi
  int *v18; // eax
  unsigned __int8 *v19; // ebp
  int v20; // esi
  int *v21; // eax
  int v23; // [esp+10h] [ebp-1038h] BYREF
  int v24; // [esp+14h] [ebp-1034h] BYREF
  char *v25; // [esp+18h] [ebp-1030h] BYREF
  int v26; // [esp+1Ch] [ebp-102Ch] BYREF
  stlp_std::_Filebuf_base *v27; // [esp+20h] [ebp-1028h]
  int v28; // [esp+24h] [ebp-1024h] BYREF
  DWORD FileSize; // [esp+28h] [ebp-1020h]
  unsigned int FileSizeHigh; // [esp+2Ch] [ebp-101Ch] BYREF
  unsigned int NumberOfBytesWritten; // [esp+30h] [ebp-1018h] BYREF
  DWORD v32; // [esp+34h] [ebp-1014h]
  int DistanceToMoveHigh; // [esp+38h] [ebp-1010h] BYREF
  unsigned int v34; // [esp+3Ch] [ebp-100Ch] BYREF
  unsigned __int8 dst[4096]; // [esp+40h] [ebp-1008h] BYREF
  _BYTE v36[4]; // [esp+1040h] [ebp-8h] BYREF

  v5 = this;
  v27 = this;
  while ( 1 )
  {
    v6 = (v5->_M_openmode & 1) == 0;
    v24 = n;
    v25 = buf;
    if ( !v6 )
    {
      if ( (FileSize = GetFileSize(v5->_M_file_id, &FileSizeHigh), FileSize == -1) && GetLastError()
        || (FileSizeHigh & 0x80000000) == 0 )
      {
        v32 = 0;
        DistanceToMoveHigh = 0;
        v32 = SetFilePointer(v5->_M_file_id, 0, &DistanceToMoveHigh, 2u);
        if ( v32 == -1 )
          GetLastError();
      }
    }
    if ( (v5->_M_openmode & 4) != 0 )
      break;
    v10 = (unsigned __int8 *)buf;
    v11 = &buf[v24];
    v12 = dst;
    v23 = 4096;
    v13 = &v23;
    if ( v24 <= 4096 )
      v13 = &v24;
    v14 = *v13;
    if ( *v13 > 0 )
    {
      while ( 1 )
      {
        memchr(v10, 0xAu, v14);
        if ( !v15 )
          break;
        v16 = v15 - (_DWORD)v10;
        memcpy(v12, v10, v15 - (_DWORD)v10);
        v17 = &v12[v16];
        *v17++ = 13;
        *v17 = 10;
        v12 = v17 + 1;
        v10 += v16 + 1;
        v23 = v36 - v12;
        v28 = 0;
        v26 = v11 - (char *)v10;
        v18 = &v23;
        if ( v36 - v12 <= 0 )
          v18 = &v28;
        if ( *v18 >= v11 - (char *)v10 )
          v18 = &v26;
        v14 = *v18;
        if ( *v18 <= 0 )
          goto LABEL_28;
      }
      if ( v14 > 0 )
      {
        memcpy(v12, v10, v14);
        v12 += v14;
        v10 += v14;
      }
    }
LABEL_28:
    v19 = dst;
    v20 = v12 - dst;
    v23 = v20;
    if ( v20 )
    {
      v26 = -1;
      do
      {
        v21 = &v23;
        if ( v20 == -1 )
          v21 = &v26;
        WriteFile(v27->_M_file_id, v19, *v21, &v34, 0);
        if ( !v34 )
          return 0;
        v19 += v34;
        v20 -= v34;
        v23 = v20;
      }
      while ( v20 );
    }
    v8 = v10 - (unsigned __int8 *)v25;
    v5 = v27;
    buf = v25;
LABEL_35:
    if ( v24 == v8 )
      return 1;
    if ( v8 <= 0 || v8 >= v24 )
      return 0;
    n = v24 - v8;
    buf += v8;
  }
  v7 = (char *)v24;
  v8 = 0;
  v25 = (char *)v24;
  if ( !v24 )
    return 1;
  v23 = -1;
  while ( 1 )
  {
    v9 = (DWORD *)&v25;
    if ( v7 == (char *)-1 )
      v9 = (DWORD *)&v23;
    WriteFile(v5->_M_file_id, &buf[v8], *v9, &NumberOfBytesWritten, 0);
    if ( !NumberOfBytesWritten )
      return 0;
    v7 -= NumberOfBytesWritten;
    v8 += NumberOfBytesWritten;
    v25 = v7;
    if ( !v7 )
      goto LABEL_35;
  }
}
