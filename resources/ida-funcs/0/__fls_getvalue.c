int __stdcall __fls_getvalue(unsigned int dwFlsIndex)
{
  int (__stdcall *Value)(unsigned int); // eax

  Value = (int (__stdcall *)(unsigned int))TlsGetValue(__getvalueindex);
  return Value(dwFlsIndex);
}
