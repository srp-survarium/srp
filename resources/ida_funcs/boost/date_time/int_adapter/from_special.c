boost::date_time::int_adapter<__int64> *__cdecl boost::date_time::int_adapter<__int64>::from_special(
        boost::date_time::int_adapter<__int64> *result,
        boost::date_time::special_values sv)
{
  boost::date_time::int_adapter<__int64> *v2; // eax

  switch ( sv )
  {
    case not_a_date_time:
      result->value_ = 0x7FFFFFFFFFFFFFFELL;
      v2 = result;
      break;
    case neg_infin:
      result->value_ = 0x8000000000000000uLL;
      v2 = result;
      break;
    case pos_infin:
      result->value_ = 0x7FFFFFFFFFFFFFFFLL;
      v2 = result;
      break;
    case min_date_time:
      result->value_ = 0x8000000000000001uLL;
      v2 = result;
      break;
    case max_date_time:
      result->value_ = 0x7FFFFFFFFFFFFFFDLL;
      v2 = result;
      break;
    default:
      result->value_ = 0x7FFFFFFFFFFFFFFELL;
      v2 = result;
      break;
  }
  return v2;
}
