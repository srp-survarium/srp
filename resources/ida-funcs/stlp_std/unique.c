unsigned int *__usercall stlp_std::unique<unsigned int *>@<eax>(
        unsigned int *__first@<eax>,
        unsigned int *__last@<esi>)
{
  unsigned int *v2; // ecx
  unsigned int *i; // eax

  v2 = __first;
  if ( __first == __last )
    return __last;
  while ( ++__first != __last )
  {
    if ( *v2 == *__first )
      goto LABEL_7;
    v2 = __first;
  }
  v2 = __last;
LABEL_7:
  if ( v2 == __last )
    return v2;
  for ( i = v2 + 1; i != __last; ++i )
  {
    if ( *v2 != *i )
      *++v2 = *i;
  }
  return v2 + 1;
}
