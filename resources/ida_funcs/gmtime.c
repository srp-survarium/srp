tm *__usercall gmtime@<eax>(unsigned int a1@<ebx>, const __int64 *_Time)
{
  return _gmtime64(a1, _Time);
}
