void __usercall _invalid_parameter(unsigned int a1@<ebx>, unsigned int a2@<edi>, unsigned int a3@<esi>)
{
  void (*v3)(void); // eax

  v3 = (void (*)(void))_decode_pointer(__pInvalidArgHandler);
  if ( !v3 )
  {
    _crt_debugger_hook(2);
    _invoke_watson(a1, a2, a3);
  }
  v3();
}
