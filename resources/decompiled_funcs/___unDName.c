char *__cdecl __unDName(
        char *outputString,
        const char *name,
        int maxStringLength,
        void *(__cdecl *pAlloc)(unsigned int),
        void (__cdecl *pFree)(void *),
        unsigned __int16 disableFlags)
{
  UnDecorator unDecorate; // [esp+10h] [ebp-74h] BYREF
  char *unDecoratedName; // [esp+68h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+6Ch] [ebp-18h]

  if ( !pAlloc || !_mtinitlocknum(5) )
    return 0;
  _lock(5);
  ms_exc.registration.TryLevel = 0;
  heap.pOpNew = pAlloc;
  heap.pOpDelete = pFree;
  heap.blockLeft = 0;
  heap.head = 0;
  heap.tail = 0;
  UnDecorator::UnDecorator(&unDecorate, outputString, name, maxStringLength, 0, disableFlags);
  unDecoratedName = UnDecorator::operator char *(&unDecorate);
  HeapManager::Destructor(&heap);
  ms_exc.registration.TryLevel = -2;
  _unlock(5);
  return unDecoratedName;
}
