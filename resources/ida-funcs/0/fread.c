unsigned int __usercall fread@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        unsigned __int8 *buffer,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  return fread_s(a1, a2, buffer, 0xFFFFFFFF, elementSize, count, stream);
}
