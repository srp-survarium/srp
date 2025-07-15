_iobuf *__usercall fopen@<eax>(const char *a1@<esi>, char *file, char *mode)
{
  return _fsopen(a1, file, mode, 64);
}
