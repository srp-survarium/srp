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
