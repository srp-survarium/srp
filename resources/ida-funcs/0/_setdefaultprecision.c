int __usercall _setdefaultprecision@<eax>(unsigned int a1@<ebx>, unsigned int a2@<edi>)
{
  int result; // eax

  result = _controlfp_s(0, (unsigned int)&_sbh_sizeHeaderList, 0x30000u);
  if ( result )
    _invoke_watson(a1, a2, 0);
  return result;
}
