__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime((LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL)
         / (unsigned int)&stru_984D24.m_working_macro_list.m_buffer[33].m_store[300];
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr )
    *timeptr = result;
  return result;
}
