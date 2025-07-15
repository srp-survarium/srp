bool __usercall vostok::strings::convert_string_to_number@<al>(char *string@<edi>, float *const out_result@<esi>)
{
  unsigned int v2; // eax
  unsigned int v4; // eax
  long double v5; // st7
  const char *v6; // [esp-14h] [ebp-1Ch]
  int v7; // [esp-8h] [ebp-10h]
  char *v8; // [esp-4h] [ebp-Ch]
  const char *v9; // [esp+0h] [ebp-8h]
  bool do_debug_break; // [esp+7h] [ebp-1h] BYREF

  if ( !debug_macro_helper_ignore_always_21 && !string )
  {
    v2 = occurances_left_14;
    if ( occurances_left_14 == -1 )
      v2 = 10;
    occurances_left_14 = v2 - 1;
    if ( !v2 )
      return 0;
    v8 = "1st argument is null pointer";
    v7 = 15;
    v6 = "string";
LABEL_7:
    do_debug_break = 0;
    vostok::debug::on_error(
      &do_debug_break,
      process_error_false,
      0,
      "assertion_failed",
      v6,
      ".\\strings_functions.cpp",
      "vostok::strings::convert_string_to_number",
      (const char *)v7,
      v8,
      v9);
    if ( vostok::debug::is_debugger_present() || do_debug_break )
      __debugbreak();
    return 0;
  }
  if ( !debug_macro_helper_ignore_always_22 && !out_result )
  {
    v4 = occurances_left_15;
    if ( occurances_left_15 == -1 )
      v4 = 10;
    occurances_left_15 = v4 - 1;
    if ( !v4 )
      return 0;
    v8 = "2nd argument is null pointer";
    v7 = 16;
    v6 = "out_result";
    goto LABEL_7;
  }
  v5 = atof(string);
  *out_result = v5;
  return v5 != 0.0
      || !vostok::strings::compare(string, "0")
      || !vostok::strings::compare(string, "0.")
      || !vostok::strings::compare(string, "0.0");
}
