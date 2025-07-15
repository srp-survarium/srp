int __stdcall __fls_setvalue(unsigned int dwFlsIndex, void *lpFlsData)
{
  int (__stdcall *v2)(unsigned int, void *); // eax

  v2 = (int (__stdcall *)(unsigned int, void *))_decode_pointer(gpFlsSetValue);
  return v2(dwFlsIndex, lpFlsData);
}
