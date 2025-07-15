int __usercall _get_daylight@<eax>(int a1@<ebx>, int a2@<edi>, int *_Daylight)
{
  if ( _Daylight )
  {
    *_Daylight = _daylight;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return 22;
  }
}
