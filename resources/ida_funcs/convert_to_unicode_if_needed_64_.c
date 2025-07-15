wchar_t *__cdecl convert_to_unicode_if_needed_64_(const char *message, wchar_t (*output)[64])
{
  return convert_to_unicode_if_needed(message, (wchar_t *const)output, 0x40u);
}
