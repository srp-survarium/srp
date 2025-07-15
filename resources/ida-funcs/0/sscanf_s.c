int __usercall sscanf_s@<eax>(int a1@<ebx>, const char *string, const char *format, ...)
{
  va_list va; // [esp+14h] [ebp+10h] BYREF

  va_start(va, format);
  return vscan_fn(
           string,
           a1,
           (int (__cdecl *)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *))_input_s_l,
           format,
           0,
           va);
}
