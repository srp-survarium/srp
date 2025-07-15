int __usercall _get_timezone@<eax>(int a1@<ebx>, int a2@<edi>, int *_Timezone)
{
  if ( _Timezone )
  {
    *_Timezone = _timezone;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter(a1, a2, 0);
    return 22;
  }
}
