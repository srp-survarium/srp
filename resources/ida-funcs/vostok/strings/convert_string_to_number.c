bool __usercall vostok::strings::convert_string_to_number@<al>(
        char *string@<edi>,
        float *const out_result@<esi>,
        int a3@<ecx>,
        unsigned int a4@<ebx>)
{
  unsigned int v4; // eax
  unsigned int v6; // eax
  long double v7; // st7
  bool do_debug_break; // [esp+1h] [ebp-1h] BYREF

  do_debug_break = HIBYTE(a3);
  if ( BYTE4(vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[1]) || string )
  {
    if ( BYTE5(vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[1])
      || out_result )
    {
      v7 = atof(string);
      *out_result = v7;
      return v7 != 0.0
          || !strcmp(string, (const char *)&stru_95AF78.m_key_bindings[6].m_keyboard[1])
          || !strcmp(string, "0.")
          || vostok::strings::equal(string, "0.0");
    }
    else
    {
      v6 = occurances_left_15;
      if ( occurances_left_15 == -1 )
        v6 = 10;
      occurances_left_15 = v6 - 1;
      if ( v6 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          a4,
          &do_debug_break,
          process_error_false,
          (bool *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[1] + 5,
          assert_untyped,
          "assertion_failed",
          "out_result",
          ".\\strings_functions.cpp",
          "vostok::strings::convert_string_to_number",
          0x10u,
          "2nd argument is null pointer");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
      return 0;
    }
  }
  else
  {
    v4 = occurances_left_14;
    if ( occurances_left_14 == -1 )
      v4 = 10;
    occurances_left_14 = v4 - 1;
    if ( v4 )
    {
      do_debug_break = 0;
      vostok::debug::on_error(
        a4,
        &do_debug_break,
        process_error_false,
        (bool *)&vostok::testing::suite_base<vostok::core_test_suite>::s_suite_creation_flag.m_tests.m_mutex[1] + 4,
        assert_untyped,
        "assertion_failed",
        "string",
        ".\\strings_functions.cpp",
        "vostok::strings::convert_string_to_number",
        0xFu,
        "1st argument is null pointer");
      if ( vostok::debug::is_debugger_present() || do_debug_break )
        __debugbreak();
    }
    return 0;
  }
}
