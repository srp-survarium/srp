char __userpurge vostok::command_line::key::is_set_as_number@<al>(
        vostok::command_line::key *this@<ecx>,
        int a2@<edi>,
        float *out_value)
{
  int v3; // esi
  unsigned int v5; // eax
  const char *v6; // [esp-4h] [ebp-10h]

  if ( !*(_DWORD *)(a2 + 548) )
    vostok::command_line::key::initialize(this, a2);
  v3 = *(_DWORD *)(a2 + 548);
  if ( v3 == 1 )
    return 0;
  if ( !debug_macro_helper_ignore_always_8 && v3 != 3 )
  {
    v5 = occurances_left_7;
    if ( occurances_left_7 == -1 )
      v5 = 10;
    occurances_left_7 = v5 - 1;
    if ( v5 )
    {
      v6 = *(const char **)a2;
      HIBYTE(out_value) = 0;
      vostok::debug::on_error(
        (bool *)&out_value + 3,
        process_error_false,
        0,
        "assertion_failed",
        "m_type == type_number",
        ".\\command_line.cpp",
        "vostok::command_line::key::is_set_as_number",
        (const char *)0x86,
        "given value is not convertible to number: %s",
        v6);
      if ( vostok::debug::is_debugger_present() || HIBYTE(out_value) )
        __debugbreak();
    }
    return 0;
  }
  if ( out_value )
    *out_value = *(float *)(a2 + 524);
  return 1;
}


char __userpurge vostok::command_line::key::is_set_as_number<unsigned int>@<al>(
        vostok::command_line::key *this@<ecx>,
        int a2@<edi>,
        unsigned int *out_value)
{
  char result; // al
  float out_valuea; // [esp+0h] [ebp-4h] BYREF

  out_valuea = 0.0;
  result = vostok::command_line::key::is_set_as_number(this, a2, &out_valuea);
  if ( result )
  {
    *out_value = (unsigned __int64)out_valuea;
    return 1;
  }
  return result;
}


char __usercall vostok::command_line::key::is_set_as_number<unsigned __int64>@<al>(
        vostok::command_line::key *this@<edi>,
        unsigned __int64 *out_value@<esi>,
        vostok::command_line::key *a3@<ecx>)
{
  char result; // al
  float v4; // [esp+4h] [ebp-4h] BYREF

  v4 = 0.0;
  result = vostok::command_line::key::is_set_as_number(a3, (int)this, &v4);
  if ( result )
  {
    *out_value = (unsigned __int64)v4;
    return 1;
  }
  return result;
}
