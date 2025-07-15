int __usercall _vsnprintf@<eax>(int a1@<edi>, int a2@<esi>, char *string, unsigned int count, char *format, char *ap)
{
  return _vsnprintf_l(a1, a2, string, count, format, 0, ap);
}
