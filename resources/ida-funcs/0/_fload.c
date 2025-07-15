double __cdecl _fload(double parm)
{
  double tmp; // [esp+6h] [ebp-Ah]

  if ( (HIWORD(parm) & 0x7FF0) != 0x7FF0 )
    return parm;
  HIDWORD(tmp) = *(_QWORD *)&parm >> 21;
  LODWORD(tmp) = LODWORD(parm);
  return tmp;
}
