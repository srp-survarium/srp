int __cdecl boost::date_time::int_adapter<__int64>::to_special(__int64 v)
{
  if ( v == 0x7FFFFFFFFFFFFFFELL )
    return 0;
  if ( boost::date_time::int_adapter<__int64>::is_neg_inf(v) )
    return 1;
  return boost::date_time::int_adapter<__int64>::is_pos_inf(v) ? 2 : 5;
}
