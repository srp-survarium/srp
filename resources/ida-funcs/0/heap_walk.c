int __cdecl heap_walk(void *heap_handle, _heapinfo *_entry)
{
  int *pentry; // eax
  DWORD LastError; // eax
  _PROCESS_HEAP_ENTRY Entry; // [esp+Ch] [ebp-3Ch] BYREF
  int retval; // [esp+28h] [ebp-20h]
  int errflag; // [esp+2Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+30h] [ebp-18h]

  retval = -2;
  Entry.wFlags = 0;
  Entry.iRegionIndex = 0;
  Entry.cbData = 0;
  pentry = _entry->_pentry;
  Entry.lpData = pentry;
  if ( pentry )
  {
    if ( _entry->_useflag != 1 )
      goto nextBlock;
    if ( HeapValidate(heap_handle, 0, pentry) )
    {
      Entry.wFlags = 4;
      goto nextBlock;
    }
    return -4;
  }
  if ( HeapWalk(heap_handle, &Entry) )
  {
    do
    {
      if ( (Entry.wFlags & 3) == 0 )
      {
        _entry->_pentry = (int *)Entry.lpData;
        _entry->_size = Entry.cbData;
        _entry->_useflag = (LOBYTE(Entry.wFlags) >> 2) & 1;
        return retval;
      }
nextBlock:
      ms_exc.registration.TryLevel = 0;
      errflag = !HeapWalk(heap_handle, &Entry);
      ms_exc.registration.TryLevel = -1;
    }
    while ( errflag != 1 );
    LastError = GetLastError();
    if ( LastError == 259 )
      return -5;
    if ( LastError == 120 )
      goto LABEL_4;
    return -4;
  }
  if ( GetLastError() == 120 )
  {
LABEL_4:
    *__doserrno() = 120;
    *_errno() = 40;
    return -5;
  }
  return -3;
}
