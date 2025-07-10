_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[_XcptActTabCount] );
  if ( result >= &pxcptacttab[_XcptActTabCount] || result->SigNum != signum )
    return 0;
  return result;
}
