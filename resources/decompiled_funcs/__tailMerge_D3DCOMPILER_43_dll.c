int __usercall _tailMerge_D3DCOMPILER_43_dll@<eax>(int (__stdcall **a1)()@<eax>, int a2@<edx>, int a3@<ecx>)
{
  int (__stdcall *Helper2)(); // eax

  Helper2 = __delayLoadHelper2(&_DELAY_IMPORT_DESCRIPTOR_D3DCOMPILER_43_dll, a1);
  return ((int (__fastcall *)(int, int))Helper2)(a3, a2);
}
