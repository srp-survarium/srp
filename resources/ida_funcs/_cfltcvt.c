int __usercall _cfltcvt@<eax>(
        unsigned int a1@<ebx>,
        _CRT_DOUBLE *arg,
        char *buffer,
        unsigned int sizeInBytes,
        int format,
        int precision,
        int caps)
{
  return _cfltcvt_l(a1, arg, buffer, sizeInBytes, format, precision, caps, 0);
}
