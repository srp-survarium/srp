int __cdecl _get_errno(int *pValue)
{
  if ( pValue )
  {
    *pValue = *_errno();
    return 0;
  }
  else
  {
    _invalid_parameter(0, 0, 0, 0, 0);
    return 22;
  }
}
