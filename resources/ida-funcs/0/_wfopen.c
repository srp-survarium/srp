_iobuf *__usercall _wfopen@<eax>(const wchar_t *a1@<edi>, _iobuf *file, const wchar_t *mode)
{
  return _wfsopen(a1, file, mode, 64);
}
