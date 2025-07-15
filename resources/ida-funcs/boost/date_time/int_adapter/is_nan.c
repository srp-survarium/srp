BOOL __usercall boost::date_time::int_adapter<__int64>::is_nan@<eax>(
        boost::date_time::int_adapter<__int64> *this@<ecx>,
        _DWORD *a2@<eax>)
{
  return *a2 == -2 && a2[1] == 0x7FFFFFFF;
}
