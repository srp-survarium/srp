int __cdecl __CxxSetUnhandledExceptionFilter()
{
  SetUnhandledExceptionFilter(__CxxUnhandledExceptionFilter);
  return 0;
}
