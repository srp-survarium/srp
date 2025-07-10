stlp_std::fpos<int> *__thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::seekpos(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this,
        stlp_std::fpos<int> *result,
        stlp_std::fpos<int> __pos,
        int __formal)
{
  __int64 v5; // rax
  stlp_std::fpos<int> *v6; // eax

  if ( !this->_M_base._M_is_open
    || !stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_init(this, 1)
    || (HIDWORD(__pos._M_pos) & __pos._M_pos) == -1
    || (v5 = stlp_std::_Filebuf_base::_M_seek(&this->_M_base, __pos._M_pos, 1),
        (HIDWORD(v5) & (unsigned int)v5) == 0xFFFFFFFF) )
  {
    v6 = result;
    result->_M_st = 0;
    result->_M_pos = -1;
  }
  else
  {
    this->_M_state = __pos._M_st;
    stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_seek_return(this, result, __pos._M_pos, __pos._M_st);
    return result;
  }
  return v6;
}
