int (__cdecl *__cdecl _set_new_handler(int (__cdecl *pnh)(unsigned int)))(unsigned int)
{
  void *v1; // esi

  _lock(4);
  v1 = _decode_pointer(_pnhHeap);
  _pnhHeap = (int (__cdecl *)(unsigned int))_encode_pointer(pnh);
  _unlock(4);
  return (int (__cdecl *)(unsigned int))v1;
}
