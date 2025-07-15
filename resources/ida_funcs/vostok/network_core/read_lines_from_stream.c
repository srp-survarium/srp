void __cdecl vostok::network_core::read_lines_from_stream(
        survarium::game_camera *prefix,
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *buff)
{
  survarium::game_camera *v2; // ecx
  _BYTE *v3; // eax
  survarium::game_options *v4; // eax
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > *v5; // [esp+24h] [ebp-90h]
  survarium::game_camera v6; // [esp+2Ah] [ebp-8Ah] BYREF

  BYTE1(v6.__vftable) = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  if ( *v3 )
    survarium::weapon_user_dead_state::finalize(prefix);
  *(_DWORD *)((char *)&v6.m_inverted_view_matrix.j.elements[1] + 2) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbtable';
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::basic_ios<char,stlp_std::char_traits<char>>((stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[2].elements[1] + 2));
  *(_DWORD *)((char *)&v6.m_inverted_view_matrix.j.elements[1] + unk_815C28 + 2) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vftable';
  *(_QWORD *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[3] + 2) = 0;
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::init(
    (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[1]
                                                             + *(_DWORD *)(*(_DWORD *)((char *)&v6.m_inverted_view_matrix.j.elements[1]
                                                                                     + 2)
                                                                         + 4)
                                                             + 2),
    buff);
  v4 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable + 2),
    (const stlp_std::allocator<char> *)v4);
  survarium::weapon_user_dead_state::finalize(&v6);
  do
    v5 = stlp_std::getline<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
           (stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[1]
                                                                        + 2),
           (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable
                                                                                                 + 2),
           10);
  while ( ((*(_DWORD *)&v5->gap0[*(_DWORD *)(*(_DWORD *)v5->gap0 + 4) + 12] & 5) == 0
         ? (unsigned int)&v5->gap0[*(_DWORD *)(*(_DWORD *)v5->gap0 + 4)]
         : 0) != 0
       && !stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
             (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable + 2),
             "\r") );
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable + 2));
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[1] + 2));
}
