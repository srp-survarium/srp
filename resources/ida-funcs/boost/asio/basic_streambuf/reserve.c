void __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::reserve(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        unsigned int n)
{
  unsigned int *v2; // eax
  survarium::game_options *v3; // eax
  char *v5; // [esp+4h] [ebp-188h]
  char *v6; // [esp+8h] [ebp-184h]
  char *M_start; // [esp+1Ch] [ebp-170h]
  survarium::game_camera v8[3]; // [esp+4Bh] [ebp-141h] BYREF
  unsigned int pnext; // [esp+180h] [ebp-Ch]
  unsigned int pend; // [esp+184h] [ebp-8h] BYREF
  unsigned int gnext; // [esp+188h] [ebp-4h]

  gnext = this->_M_gnext - this->buffer_._M_impl._M_start;
  pnext = this->_M_pnext - this->buffer_._M_impl._M_start;
  pend = this->_M_pend - this->buffer_._M_impl._M_start;
  if ( n > pend - pnext )
  {
    if ( gnext )
    {
      pnext -= gnext;
      memmove(
        (unsigned __int8 *)this->buffer_._M_impl._M_start,
        (unsigned __int8 *)&this->buffer_._M_impl._M_start[gnext],
        pnext);
    }
    if ( n > pend - pnext )
    {
      if ( n > this->max_size_ || pnext > this->max_size_ - n )
      {
        v3 = survarium::weapon_core::cast_weapon_core((survarium::game_options *)v8);
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
          (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8[0].__vftable
                                                                                                + 1),
          "boost::asio::streambuf too long",
          (const stlp_std::allocator<char> *)v3);
        stlp_std::__Named_exception::__Named_exception(
          (stlp_std::__Named_exception *)((char *)&v8[0].m_inverted_view_matrix.lines[1].elements[3] + 1),
          (const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8[0].__vftable + 1));
        *(_DWORD *)((char *)&v8[0].m_inverted_view_matrix.j.elements[3] + 1) = &stlp_std::length_error::`vftable';
        stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block((stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)((char *)&v8[0].__vftable + 1));
        survarium::weapon_user_dead_state::finalize(v8);
        boost::throw_exception((const std::exception *)((char *)&v8[0].m_inverted_view_matrix.lines[1].elements[3] + 1));
        stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)((char *)&v8[0].m_inverted_view_matrix.lines[1].elements[3]
                                                                                 + 1));
      }
      else
      {
        pend = n + pnext;
        LOBYTE(v8[0].m_inverted_view_matrix.lines[1].elements[3]) = 0;
        *(_DWORD *)((char *)&v8[0].m_inverted_view_matrix.j.elements[1] + 1) = 1;
        v2 = (unsigned int *)stlp_std::max<unsigned int>(
                               &pend,
                               (const unsigned int *)((char *)&v8[0].m_inverted_view_matrix.j.elements[1] + 1));
        stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::resize(
          &this->buffer_._M_impl,
          *v2,
          (const char *)&v8[0].m_inverted_view_matrix.lines[1].elements[3]);
      }
    }
    M_start = this->buffer_._M_impl._M_start;
    this->_M_gbegin = M_start;
    this->_M_gnext = M_start;
    this->_M_gend = &M_start[pnext];
    v5 = &this->buffer_._M_impl._M_start[pend];
    v6 = &this->buffer_._M_impl._M_start[pnext];
    this->_M_pbegin = v6;
    this->_M_pnext = v6;
    this->_M_pend = v5;
  }
}
