int __cdecl boost::date_time::int_adapter<__int64>::to_special(__int64 v)
{
  switch ( v )
  {
    case 0x7FFFFFFFFFFFFFFELL:
      return 0;
    case 0x8000000000000000LL:
      return 1;
    case 0x7FFFFFFFFFFFFFFFLL:
      return 2;
  }
  return 5;
}
