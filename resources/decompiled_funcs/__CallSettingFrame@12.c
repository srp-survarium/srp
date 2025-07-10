void __stdcall _CallSettingFrame(unsigned int funclet, unsigned int pRN, unsigned int dwInCode)
{
  void (*v3)(void); // eax
  unsigned int v4; // ecx

  v3 = (void (*)(void))_NLG_Notify1(dwInCode);
  v3();
  v4 = dwInCode;
  if ( dwInCode == 256 )
    v4 = 2;
  _NLG_Notify1(v4);
}
