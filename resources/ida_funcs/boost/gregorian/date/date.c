void __thiscall boost::gregorian::date::date(
        boost::gregorian::date *this,
        boost::gregorian::greg_year y,
        boost::gregorian::greg_month m,
        boost::gregorian::greg_day d)
{
  unsigned int v4; // eax
  survarium::game_options *v5; // eax
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v6; // eax
  survarium::game_camera v8[3]; // [esp+33h] [ebp-129h] BYREF

  boost::date_time::gregorian_calendar_base<boost::date_time::year_month_day_base<boost::gregorian::greg_year,boost::gregorian::greg_month,boost::gregorian::greg_day>,unsigned int>::day_number();
  this->days_ = v4;
  if ( (unsigned __int16)boost::date_time::gregorian_calendar_base<boost::date_time::year_month_day_base<boost::gregorian::greg_year,boost::gregorian::greg_month,boost::gregorian::greg_day>,unsigned int>::end_of_month_day(
                           y,
                           m) < (int)d.value_ )
  {
    v5 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)v8);
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
      (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8[0].__vftable
                                                                                            + 1),
      "Day of month is not valid for year",
      (const stlp_std::allocator<char> *)v5);
    stlp_std::__Named_exception::__Named_exception(
      (stlp_std::__Named_exception *)((char *)&v8[0].m_inverted_view_matrix.lines[1].elements[1] + 1),
      v6);
    *(_DWORD *)((char *)&v8[0].m_inverted_view_matrix.j.elements[1] + 1) = &boost::gregorian::bad_day_of_month::`vftable';
    boost::throw_exception((const std::exception *)((char *)&v8[0].m_inverted_view_matrix.lines[1].elements[1] + 1));
    stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)((char *)&v8[0].m_inverted_view_matrix.lines[1].elements[1]
                                                                             + 1));
    stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8[0].__vftable + 1));
    survarium::weapon_user_dead_state::finalize(v8);
  }
}


void __thiscall boost::gregorian::date::date(boost::gregorian::date *this, boost::date_time::special_values sv)
{
  int v2; // ecx
  __int16 v3; // ecx^2
  __int16 v4; // ecx^2
  unsigned int *v5; // eax
  __int16 v6; // ecx^2
  __int16 v7; // ecx^2
  unsigned int *v8; // eax
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year> > v9; // [esp-Ch] [ebp-720h] BYREF
  __int16 v10; // [esp-Ah] [ebp-71Eh]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month> > v11; // [esp-8h] [ebp-71Ch] BYREF
  __int16 v12; // [esp-6h] [ebp-71Ah]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > v13; // [esp-4h] [ebp-718h] BYREF
  __int16 v14; // [esp-2h] [ebp-716h]
  unsigned int *v15; // [esp+0h] [ebp-714h]
  unsigned int *v16; // [esp+4h] [ebp-710h]
  boost::date_time::special_values v17; // [esp+8h] [ebp-70Ch]
  boost::gregorian::date *thisa; // [esp+Ch] [ebp-708h]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year> > *v19; // [esp+148h] [ebp-5CCh]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month> > *v20; // [esp+374h] [ebp-3A0h]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > *v21; // [esp+48Ch] [ebp-288h]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year> > *v22; // [esp+6DCh] [ebp-38h]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month> > *v23; // [esp+6E0h] [ebp-34h]
  boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month> > *v24; // [esp+6E4h] [ebp-30h]
  unsigned int v25; // [esp+6E8h] [ebp-2Ch]
  int *v26; // [esp+6ECh] [ebp-28h]
  boost::gregorian::date v27; // [esp+6FCh] [ebp-18h] BYREF
  boost::gregorian::date v28; // [esp+70Ch] [ebp-8h] BYREF
  int v29; // [esp+710h] [ebp-4h] BYREF

  thisa = this;
  v17 = sv;
  switch ( sv )
  {
    case not_a_date_time:
      v29 = -2;
      v26 = &v29;
      break;
    case neg_infin:
      v29 = 0;
      v26 = &v29;
      break;
    case pos_infin:
      v29 = -1;
      v26 = &v29;
      break;
    case min_date_time:
      v29 = 1;
      v26 = &v29;
      break;
    case max_date_time:
      v29 = -3;
      v26 = &v29;
      break;
    default:
      v29 = -2;
      v26 = &v29;
      break;
  }
  v2 = *v26;
  v25 = *v26;
  thisa->days_ = v25;
  if ( sv == min_date_time )
  {
    v14 = HIWORD(v2);
    v24 = &v13;
    v13.value_ = 1;
    boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month>>::assign(
      &v13,
      1u);
    v12 = v3;
    v23 = &v11;
    v11.value_ = 1;
    boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month>>::assign(
      &v11,
      1u);
    v10 = v4;
    v22 = &v9;
    v9.value_ = 1400;
    boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year>>::assign(
      &v9,
      0x578u);
    boost::gregorian::date::date(
      &v28,
      (boost::gregorian::greg_year)v9.value_,
      (boost::gregorian::greg_month)v11.value_,
      (boost::gregorian::greg_day)v13.value_);
    v16 = v5;
    HIWORD(v2) = HIWORD(v5);
    thisa->days_ = *v5;
  }
  if ( sv == max_date_time )
  {
    v14 = HIWORD(v2);
    v21 = &v13;
    v13.value_ = 1;
    boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,31,boost::gregorian::bad_day_of_month>>::assign(
      &v13,
      0x1Fu);
    v12 = v6;
    v20 = &v11;
    v11.value_ = 1;
    boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1,12,boost::gregorian::bad_month>>::assign(
      &v11,
      0xCu);
    v10 = v7;
    v19 = &v9;
    v9.value_ = 1400;
    boost::CV::constrained_value<boost::CV::simple_exception_policy<unsigned short,1400,10000,boost::gregorian::bad_year>>::assign(
      &v9,
      0x270Fu);
    boost::gregorian::date::date(
      &v27,
      (boost::gregorian::greg_year)v9.value_,
      (boost::gregorian::greg_month)v11.value_,
      (boost::gregorian::greg_day)v13.value_);
    v15 = v8;
    thisa->days_ = *v8;
  }
}
