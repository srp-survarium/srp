void _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v1; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v1 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))_decode_pointer(gpFlsFree);
    v0(v1);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(__getvalueindex);
    __getvalueindex = -1;
  }
  _mtdeletelocks();
}
