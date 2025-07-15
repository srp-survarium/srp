void (__cdecl *__cdecl _set_invalid_parameter_handler(
        void (__cdecl *pNew)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int)))(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int)
{
  void *v1; // esi

  v1 = _decode_pointer(__pInvalidArgHandler);
  __pInvalidArgHandler = (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))_encode_pointer(pNew);
  return (void (__cdecl *)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int))v1;
}
