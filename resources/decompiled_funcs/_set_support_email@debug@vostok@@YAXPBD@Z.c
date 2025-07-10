void __cdecl vostok::debug::set_support_email(const char *support_email)
{
  wchar_t *v1; // eax
  wchar_t unicode_message[64]; // [esp+0h] [ebp-80h] BYREF

  strcpy_s<64>((char (*)[64])s_support_email, support_email);
  if ( s_BT_SetSupportEMail )
  {
    v1 = convert_to_unicode_if_needed_64_(s_support_email, (wchar_t (*)[64])unicode_message);
    s_BT_SetSupportEMail((const char *)v1);
  }
}
