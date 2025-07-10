void __fastcall vostok::console_commands::trim_float_str(int a1, char (*dest)[512])
{
  char *i; // eax

  for ( i = &(*dest)[strlen((const char *)dest) - 1]; *i == 48; *i-- = 0 )
  {
    if ( *(i - 1) != 48 )
      break;
  }
}
