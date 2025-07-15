void __stdcall _CallSettingFrame(unsigned int funclet, unsigned int pRN, int dwInCode)
{
  void (*v6)(void); // eax
  int v7; // ecx

  _NLG_Notify1(dwInCode);
  v6();
  v7 = dwInCode;
  if ( dwInCode == 256 )
    v7 = 2;
  _NLG_Notify1(v7);
}
