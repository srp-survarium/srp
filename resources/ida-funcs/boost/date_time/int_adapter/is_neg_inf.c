BOOL __cdecl boost::date_time::int_adapter<__int64>::is_neg_inf(__int64 v)
{
  BOOL result; // eax

  result = 0;
  if ( !(_DWORD)v )
    return HIDWORD(v) == 0x80000000;
  return result;
}
