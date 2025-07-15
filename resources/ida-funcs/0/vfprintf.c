int __usercall vfprintf@<eax>(int a1@<ebx>, _iobuf *str, char *format, char *ap)
{
  return vfprintf_helper(a1, _output_l, str, format, 0, ap);
}
