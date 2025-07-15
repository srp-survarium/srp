unsigned int *__usercall stlp_std::max_element<unsigned int *>@<eax>(unsigned int *__first@<eax>, unsigned int *__last)
{
  unsigned int *v2; // ecx

  if ( __first != __last )
  {
    v2 = __first;
    while ( ++__first != __last )
    {
      if ( *v2 < *__first )
        v2 = __first;
    }
    return v2;
  }
  return __first;
}
