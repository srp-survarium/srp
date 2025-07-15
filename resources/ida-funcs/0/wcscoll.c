int __usercall wcscoll@<eax>(int a1@<ebx>, int a2@<edi>, const wchar_t *_string1, const wchar_t *_string2)
{
  if ( __locale_changed )
    return _wcscoll_l(a2, 0, _string1, _string2, 0);
  if ( _string1 && _string2 )
    return wcscmp(_string1, _string2);
  *_errno() = 22;
  _invalid_parameter(a1, a2, 0);
  return 0x7FFFFFFF;
}
