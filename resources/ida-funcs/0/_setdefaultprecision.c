int __usercall _setdefaultprecision@<eax>(int a1@<ebx>, int a2@<edi>)
{
  int result; // eax

  result = _controlfp_s(a1, 0, (unsigned int)&_sbh_sizeHeaderList, (unsigned int)&loc_30000);
  if ( result )
    _invoke_watson(a1, a2, 0);
  return result;
}
