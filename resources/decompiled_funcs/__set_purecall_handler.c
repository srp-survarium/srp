void (__cdecl *__cdecl _set_purecall_handler(void (__cdecl *pNew)()))()
{
  void *v1; // esi

  v1 = _decode_pointer(__pPurecall);
  __pPurecall = (void (__cdecl *)())_encode_pointer(pNew);
  return (void (__cdecl *)())v1;
}
