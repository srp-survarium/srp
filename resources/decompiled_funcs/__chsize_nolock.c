int __cdecl _chsize_nolock(int filedes, __int64 size)
{
  doubleint v2; // rax
  signed int v3; // edi
  unsigned int v4; // esi
  HANDLE ProcessHeap; // eax
  unsigned int v7; // eax
  int v8; // eax
  bool v9; // of
  unsigned int v10; // kr08_4
  int v11; // esi
  HANDLE v12; // eax
  doubleint v13; // rax
  void *osfhandle; // eax
  unsigned int *v15; // esi
  doubleint v16; // rax
  __int64 place; // [esp+Ch] [ebp-18h]
  __int64 retval; // [esp+14h] [ebp-10h]
  int oldmode; // [esp+1Ch] [ebp-8h]
  char *v20; // [esp+20h] [ebp-4h]

  HIDWORD(retval) = 0;
  place = _lseeki64_nolock(filedes, 0, 1u).bigint;
  if ( (HIDWORD(place) & (unsigned int)place) == 0xFFFFFFFF )
    return *_errno();
  v2.bigint = _lseeki64_nolock(filedes, 0, 2u).bigint;
  if ( (v2.twoints.upperhalf & v2.twoints.lowerhalf) == -1 )
    return *_errno();
  v3 = (unsigned __int64)(size - v2.bigint) >> 32;
  v4 = size - v2.twoints.lowerhalf;
  if ( v3 >= 0 && (size >= v2.bigint && (unsigned __int64)(size - v2.bigint) >> 32 != 0 || v4) )
  {
    ProcessHeap = GetProcessHeap();
    v20 = (char *)HeapAlloc(ProcessHeap, 8u, 0x1000u);
    if ( !v20 )
    {
      *_errno() = 12;
      return *_errno();
    }
    oldmode = _setmode_nolock(filedes, 0x8000);
    while ( 1 )
    {
      v7 = v3 < 0 || v3 <= 0 && v4 < 0x1000 ? v4 : 4096;
      v8 = _write_nolock(0, v3, filedes, v20, v7);
      if ( v8 == -1 )
        break;
      v9 = __OFSUB__(__PAIR64__(v3, v4), v8);
      v10 = v4 - v8;
      v3 = (__PAIR64__(v3, v4) - v8) >> 32;
      v4 -= v8;
      if ( v3 < 0 || (v3 < 0) ^ v9 | (v3 == 0) && !v10 )
      {
        v11 = 0;
        goto LABEL_20;
      }
    }
    if ( *__doserrno() == 5 )
      *_errno() = 13;
    v11 = -1;
    HIDWORD(retval) = -1;
LABEL_20:
    _setmode_nolock(filedes, oldmode);
    v12 = GetProcessHeap();
    HeapFree(v12, 0, v20);
    goto LABEL_28;
  }
  if ( v3 < 0 )
  {
    v13.bigint = _lseeki64_nolock(filedes, size, 0).bigint;
    if ( (v13.twoints.upperhalf & v13.twoints.lowerhalf) == -1 )
      return *_errno();
    osfhandle = (void *)_get_osfhandle(filedes);
    retval = SetEndOfFile(osfhandle) - 1;
    if ( (HIDWORD(retval) & (unsigned int)retval) == 0xFFFFFFFF )
    {
      *_errno() = 13;
      v15 = __doserrno();
      *v15 = GetLastError();
      v11 = retval;
LABEL_28:
      if ( (HIDWORD(retval) & v11) == 0xFFFFFFFF )
        return *_errno();
    }
  }
  v16.bigint = _lseeki64_nolock(filedes, place, 0).bigint;
  if ( (v16.twoints.upperhalf & v16.twoints.lowerhalf) == -1 )
    return *_errno();
  return 0;
}
