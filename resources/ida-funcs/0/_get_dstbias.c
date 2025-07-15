int __usercall _get_dstbias@<eax>(int a1@<ebx>, int a2@<edi>, int *_Daylight_savings_bias)
{
  if ( _Daylight_savings_bias )
  {
    *_Daylight_savings_bias = _dstbias;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return 22;
  }
}
