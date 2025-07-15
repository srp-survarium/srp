bool __usercall stlp_std::_M_init_noskip<char,stlp_std::char_traits<char>>@<al>(
        stlp_std::basic_istream<char,stlp_std::char_traits<char> > *__istr@<edi>)
{
  stlp_std::basic_ios<char,stlp_std::char_traits<char> > *v1; // ecx
  stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *M_tied_ostream; // ecx
  int v3; // eax

  v1 = (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&__istr->gap0[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4)];
  if ( v1->_M_iostate )
  {
    v3 = v1->_M_iostate | 4;
    goto LABEL_7;
  }
  M_tied_ostream = v1->_M_tied_ostream;
  if ( M_tied_ostream )
    stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(M_tied_ostream, (int)M_tied_ostream);
  v1 = (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&__istr->gap0[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4)];
  if ( !v1->_M_streambuf )
  {
    v3 = v1->_M_iostate | 1;
LABEL_7:
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::clear(v1, v3);
  }
  return *(_DWORD *)&__istr->gap0[*(_DWORD *)(*(_DWORD *)__istr->gap0 + 4) + 12] == 0;
}
