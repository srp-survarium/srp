void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  HMODULE ModuleHandleW; // eax
  HINSTANCE__ *hKernel32; // [esp+10h] [ebp-1Ch]
  int savedregs; // [esp+2Ch] [ebp+0h]

  ModuleHandleW = GetModuleHandleW(L"KERNEL32.DLL");
  if ( !ModuleHandleW )
    ModuleHandleW = _crt_waiting_on_module_handle(L"KERNEL32.DLL");
  hKernel32 = ModuleHandleW;
  ptd->_pxcptacttab = (void *)_XcptActTab;
  ptd->_holdrand = 1;
  if ( ModuleHandleW )
  {
    ptd->_encode_ptr = GetProcAddress(ModuleHandleW, "EncodePointer");
    ptd->_decode_ptr = GetProcAddress(hKernel32, "DecodePointer");
  }
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  _lock(13);
  InterlockedIncrement(&ptd->ptmbcinfo->refcount);
  _unlock(13);
  _lock(12);
  ptd->ptlocinfo = ptloci;
  if ( !ptloci )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptd->ptlocinfo);
  savedregs = 1656415;
  _unlock(12);
}
