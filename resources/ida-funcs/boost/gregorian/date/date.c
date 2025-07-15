void __thiscall boost::gregorian::date::date(
        boost::gregorian::date *this,
        _DWORD *y,
        boost::gregorian::greg_month m,
        boost::gregorian::greg_day d,
        int a5)
{
  __int16 v5; // ax
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v6; // eax
  unsigned __int16 v7; // [esp-4h] [ebp-13Ch]
  stlp_std::out_of_range v8; // [esp+10h] [ebp-128h] BYREF
  stlp_std::priv::_String_base<char,stlp_std::allocator<char> > v9; // [esp+120h] [ebp-18h] BYREF

  v5 = (14 - d.value_) / 12;
  *y = ((unsigned __int16)(m.value_ - v5 + 4800) >> 2)
     + 365 * (unsigned __int16)(m.value_ - v5 + 4800)
     + (unsigned __int16)(m.value_ - v5 + 4800) / 400
     + (153 * (unsigned __int16)(12 * v5 + d.value_ - 3) + 2) / 5
     - (unsigned __int16)(m.value_ - v5 + 4800) / 100
     + (unsigned __int16)a5
     - 32045;
  if ( d.value_ == 2 )
  {
    if ( (m.value_ & 3) != 0 || !(m.value_ % 100) && m.value_ % 400 )
      v7 = 28;
    else
      v7 = 29;
  }
  else if ( d.value_ == 4 || d.value_ == 6 || d.value_ == 9 || d.value_ == 11 )
  {
    v7 = 30;
  }
  else
  {
    v7 = 31;
  }
  if ( v7 < (unsigned __int16)a5 )
  {
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v9,
      "Day of month is not valid for year",
      (const stlp_std::allocator<char> *)&a5 + 3);
    stlp_std::out_of_range::out_of_range(&v8, v6);
    v8.__vftable = (stlp_std::out_of_range_vtbl *)&boost::gregorian::bad_day_of_month::`vftable';
    boost::throw_exception(&v8);
    stlp_std::__Named_exception::~__Named_exception(&v8);
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(&v9);
  }
}


void __userpurge boost::gregorian::date::date(
        boost::gregorian::date *this@<ecx>,
        int *a2@<edi>,
        boost::date_time::special_values sv)
{
  int v3; // eax
  bool v4; // zf
  boost::gregorian::date *v5; // ecx
  int *v6; // eax
  boost::gregorian::date *v7; // ecx
  int *v8; // eax
  int v9; // [esp-Ch] [ebp-18h] BYREF
  int v10; // [esp-8h] [ebp-14h]
  int v11; // [esp-4h] [ebp-10h]
  int v12; // [esp+8h] [ebp-4h] BYREF

  switch ( sv )
  {
    case not_a_date_time:
      goto LABEL_10;
    case neg_infin:
      v3 = 0;
      goto LABEL_12;
    case pos_infin:
      v3 = -1;
      goto LABEL_12;
    case min_date_time:
      v3 = 1;
      goto LABEL_12;
    case max_date_time:
      v11 = -3;
      break;
    default:
LABEL_10:
      v11 = -2;
      break;
  }
  v3 = v11;
LABEL_12:
  v4 = sv == min_date_time;
  *a2 = v3;
  if ( v4 )
  {
    HIWORD(v11) = HIWORD(this);
    LOWORD(v11) = 1;
    v9 = 1;
    v10 = 1;
    boost::gregorian::greg_year::greg_year((boost::gregorian::greg_year *)&v9, 0x578u);
    boost::gregorian::date::date(v5, &v12, (boost::gregorian::greg_month)v9, (boost::gregorian::greg_day)v10, v11);
    *a2 = *v6;
  }
  if ( sv == max_date_time )
  {
    HIWORD(v11) = HIWORD(this);
    v10 = 12;
    LOWORD(v11) = 31;
    v9 = 12;
    boost::gregorian::greg_year::greg_year((boost::gregorian::greg_year *)&v9, 0x270Fu);
    boost::gregorian::date::date(v7, &sv, (boost::gregorian::greg_month)v9, (boost::gregorian::greg_day)v10, v11);
    *a2 = *v8;
  }
}
