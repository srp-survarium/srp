int __usercall strcpy_s<64>@<eax>(char (*_Dest)[64]@<ecx>, const char *_Source@<eax>)
{
  return strcpy_s((char *)_Dest, 0x40u, _Source);
}
