void __fastcall vostok::debug::detail::make_fail_message<unsigned int,unsigned int>(
        vostok::debug::detail::string_helper *operands_and_result,
        bool *comparison_result,
        vostok::debug::detail::string_helper *out_helper)
{
  bool v3; // al
  const unsigned int *v4; // [esp+0h] [ebp-1008h]
  unsigned __int8 src[4096]; // [esp+8h] [ebp-1000h] BYREF

  if ( operands_and_result->m_buffer[8] )
  {
    *comparison_result = 1;
  }
  else
  {
    v3 = operands_and_result->m_buffer[8];
    *comparison_result = v3;
    if ( v3 )
      src[0] = 0;
    else
      vostok::debug::detail::make_fail_message<unsigned int,unsigned int>(
        operands_and_result,
        (const unsigned int *)&operands_and_result->m_buffer[4],
        v4);
    memcpy((unsigned __int8 *)out_helper, src, sizeof(vostok::debug::detail::string_helper));
  }
}
