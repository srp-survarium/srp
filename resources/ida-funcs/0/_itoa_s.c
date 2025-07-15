int __usercall _itoa_s@<eax>(char *a1@<edi>, int val, char *buf, unsigned int sizeInTChars, unsigned int radix)
{
  if ( radix == 10 && val < 0 )
    return xtoa_s(val, buf, a1, sizeInTChars, 0xAu, 1);
  else
    return xtoa_s(val, buf, a1, sizeInTChars, radix, 0);
}
