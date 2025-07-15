BOOL __thiscall boost::date_time::int_adapter<__int64>::is_special(
        boost::date_time::int_adapter<__int64> *this,
        int a2)
{
  boost::date_time::int_adapter<__int64> *v2; // ecx

  return boost::date_time::int_adapter<__int64>::is_infinity(this) || boost::date_time::int_adapter<__int64>::is_nan(v2);
}
