void __cdecl _freeptd(_tiddata *ptd)
{
  int (__stdcall *Value)(unsigned int); // eax
  void (__stdcall *v2)(unsigned int, _DWORD); // eax
  unsigned int v3; // [esp-8h] [ebp-8h]
  unsigned int v4; // [esp-8h] [ebp-8h]

  if ( __flsindex != -1 )
  {
    if ( !ptd && TlsGetValue(__getvalueindex) )
    {
      v3 = __flsindex;
      Value = (int (__stdcall *)(unsigned int))TlsGetValue(__getvalueindex);
      ptd = (_tiddata *)Value(v3);
    }
    v4 = __flsindex;
    v2 = (void (__stdcall *)(unsigned int, _DWORD))_decode_pointer(gpFlsSetValue);
    v2(v4, 0);
    _freefls(ptd);
  }
  if ( __getvalueindex != -1 )
    TlsSetValue(__getvalueindex, 0);
}
