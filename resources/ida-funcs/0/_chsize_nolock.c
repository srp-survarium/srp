int __usercall _chsize_nolock@<eax>(int a1@<edi>, int filedes, __int64 size)
{
  __int64 v3; // rax
  int v4; // edi
  unsigned int v5; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v8; // eax
  int v9; // eax
  bool v10; // of
  unsigned int v11; // kr08_4
  int v12; // esi
  HANDLE v13; // eax
  __int64 v14; // rax
  void *osfhandle; // eax
  unsigned int *v16; // esi
  __int64 v17; // rax
  __int64 v18; // [esp+Ch] [ebp-18h]
  __int64 v19; // [esp+14h] [ebp-10h]
  unsigned __int8 *mode; // [esp+1Ch] [ebp-8h]
  char *lpMem; // [esp+20h] [ebp-4h]

  HIDWORD(v19) = 0;
  v18 = _lseeki64_nolock(0, a1, filedes, 0, 1u);
  if ( (HIDWORD(v18) & (unsigned int)v18) == 0xFFFFFFFF )
    return *_errno();
  v3 = _lseeki64_nolock(0, a1, filedes, 0, 2u);
  if ( (HIDWORD(v3) & (unsigned int)v3) == 0xFFFFFFFF )
    return *_errno();
  v4 = (unsigned __int64)(size - v3) >> 32;
  v5 = size - v3;
  if ( v4 >= 0 && (size >= v3 && (unsigned __int64)(size - v3) >> 32 != 0 || v5) )
  {
    ProcessHeap = GetProcessHeap();
    lpMem = (char *)HeapAlloc(ProcessHeap, 8u, 0x1000u);
    if ( !lpMem )
    {
      *_errno() = 12;
      return *_errno();
    }
    mode = (unsigned __int8 *)_setmode_nolock(filedes, (unsigned __int8 *)0x8000);
    while ( 1 )
    {
      v8 = v4 < 0 || v4 <= 0 && v5 < 0x1000 ? v5 : 4096;
      v9 = _write_nolock(0, v4, filedes, lpMem, v8);
      if ( v9 == -1 )
        break;
      v10 = __OFSUB__(__PAIR64__(v4, v5), v9);
      v11 = v5 - v9;
      v4 = (__PAIR64__(v4, v5) - v9) >> 32;
      v5 -= v9;
      if ( v4 < 0 || (v4 < 0) ^ v10 | (v4 == 0) && !v11 )
      {
        v12 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v12 = -1;
    HIDWORD(v19) = -1;
LABEL_20:
    _setmode_nolock(filedes, mode);
    v13 = GetProcessHeap();
    HeapFree(v13, 0, lpMem);
    goto LABEL_28;
  }
  if ( v4 < 0 )
  {
    v14 = _lseeki64_nolock(0, v4, filedes, size, 0);
    if ( (HIDWORD(v14) & (unsigned int)v14) == 0xFFFFFFFF )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(0, v4, filedes);
    v19 = SetEndOfFile(osfhandle) - 1;
    if ( (HIDWORD(v19) & (unsigned int)v19) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v16 = __doserrno();
      *v16 = GetLastError();
      v12 = v19;
LABEL_28:
      if ( (HIDWORD(v19) & v12) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v17 = _lseeki64_nolock(0, v4, filedes, v18, 0);
  if ( (HIDWORD(v17) & (unsigned int)v17) == 0xFFFFFFFF )
    return *_errno();
  return 0;
}
