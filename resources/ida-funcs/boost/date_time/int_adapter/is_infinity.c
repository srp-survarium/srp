BOOL __usercall boost::date_time::int_adapter<__int64>::is_infinity@<eax>(
        boost::date_time::int_adapter<__int64> *this@<ecx>,
        int *a2@<eax>)
{
  int v2; // ecx
  int v3; // eax

  v2 = *a2;
  v3 = a2[1];
  return !v2 && v3 == 0x80000000 || v2 == -1 && v3 == 0x7FFFFFFF;
}
