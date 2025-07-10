vostok::debug::detail::string_helper *__usercall vostok::debug::detail::make_fail_message<unsigned int,unsigned int>@<eax>(
        unsigned __int8 *a1@<esi>,
        vostok::debug::detail::string_helper *result,
        const unsigned int *value1)
{
  __int64 v4; // [esp-8h] [ebp-400Ch]
  __int64 v5; // [esp-8h] [ebp-400Ch]
  vostok::debug::detail::string_helper v6; // [esp+0h] [ebp-4004h] BYREF
  vostok::debug::detail::string_helper v7; // [esp+1000h] [ebp-3004h] BYREF
  vostok::debug::detail::string_helper dst; // [esp+2000h] [ebp-2004h] BYREF
  vostok::debug::detail::string_helper v9; // [esp+3000h] [ebp-1004h] BYREF

  v4 = *(unsigned int *)result->m_buffer;
  v7.m_buffer[0] = 0;
  v6.m_buffer[0] = 0;
  vostok::debug::detail::string_helper::appendf(&v6, "%I64i", v4);
  memcpy((unsigned __int8 *)&dst, (unsigned __int8 *)&v6, sizeof(dst));
  if ( vostok::debug::detail::string_helper::size(&dst) )
    vostok::debug::detail::string_helper::appendf(&v7, "(left = %s", dst.m_buffer);
  v5 = *value1;
  v6.m_buffer[0] = 0;
  vostok::debug::detail::string_helper::appendf(&v6, "%I64i", v5);
  memcpy((unsigned __int8 *)&v9, (unsigned __int8 *)&v6, sizeof(v9));
  if ( vostok::debug::detail::string_helper::size(&v9) )
    vostok::debug::detail::string_helper::appendf(&v7, ", right = %s)", v9.m_buffer);
  if ( vostok::debug::detail::string_helper::size(&v7) )
    vostok::debug::detail::string_helper::appendf(&v7, "%s", (const char *)&stru_95AF78);
  memcpy(a1, (unsigned __int8 *)&v7, 0x1000u);
  return (vostok::debug::detail::string_helper *)a1;
}
