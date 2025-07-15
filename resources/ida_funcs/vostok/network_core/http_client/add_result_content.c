bool __thiscall vostok::network_core::http_client::add_result_content(vostok::network_core::http_client *this)
{
  survarium::game_options *v1; // eax
  bool v4; // [esp+3Fh] [ebp-91h]
  stlp_std::basic_istream<char,stlp_std::char_traits<char> > *v5; // [esp+40h] [ebp-90h]
  survarium::game_camera v6; // [esp+47h] [ebp-89h] BYREF

  *(_DWORD *)((char *)&v6.m_inverted_view_matrix.j.elements[1] + 1) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbtable';
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::basic_ios<char,stlp_std::char_traits<char>>((stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[2].elements[1] + 1));
  *(_DWORD *)((char *)&v6.m_inverted_view_matrix.j.elements[1] + unk_815C28 + 1) = &stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vftable';
  *(_QWORD *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[3] + 1) = 0;
  stlp_std::basic_ios<char,stlp_std::char_traits<char>>::init(
    (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[1]
                                                             + *(_DWORD *)(*(_DWORD *)((char *)&v6.m_inverted_view_matrix.j.elements[1]
                                                                                     + 1)
                                                                         + 4)
                                                             + 1),
    &this->m_response_buff);
  v1 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v6);
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable + 1),
    (const stlp_std::allocator<char> *)v1);
  survarium::weapon_user_dead_state::finalize(&v6);
  while ( 1 )
  {
    v5 = stlp_std::getline<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
           (stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[1]
                                                                        + 1),
           (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable
                                                                                                 + 1),
           10);
    if ( ((*(_DWORD *)&v5->gap0[*(_DWORD *)(*(_DWORD *)v5->gap0 + 4) + 12] & 5) == 0
        ? (unsigned int)&v5->gap0[*(_DWORD *)(*(_DWORD *)v5->gap0 + 4)]
        : 0) == 0
      || stlp_std::operator==<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
           (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable + 1),
           "\r") )
    {
      break;
    }
    stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
      &this->m_result_content,
      *(char **)((char *)v6.m_inverted_view_matrix.j.elements + 1),
      *(char **)((char *)&v6.m_inverted_view_matrix.i.elements[3] + 1));
  }
  v4 = (unsigned int)(this->m_result_content._M_finish - this->m_result_content._M_start_of_storage._M_data) < 0x400;
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v6.__vftable + 1));
  stlp_std::basic_istream<char,stlp_std::char_traits<char>>::`vbase destructor'((stlp_std::basic_istream<char,stlp_std::char_traits<char> > *)((char *)&v6.m_inverted_view_matrix.lines[1].elements[1] + 1));
  return v4;
}
