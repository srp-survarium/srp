BOOL __usercall vostok::strings::mbstowcs@<eax>(unsigned int dest_size_bytes@<eax>, char *src@<ecx>, wchar_t *dest)
{
  int v3; // eax
  unsigned int converted_chars; // [esp+0h] [ebp-4h] BYREF

  converted_chars = 0;
  v3 = mbstowcs_s(&converted_chars, dest, dest_size_bytes >> 1, src, 0xFFFFFFFF);
  return !v3 || v3 == 80;
}
