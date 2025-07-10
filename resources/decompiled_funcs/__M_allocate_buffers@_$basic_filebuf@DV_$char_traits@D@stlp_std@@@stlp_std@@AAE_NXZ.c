char __thiscall stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_allocate_buffers(
        stlp_std::basic_filebuf<char,stlp_std::char_traits<char> > *this)
{
  return stlp_std::basic_filebuf<char,stlp_std::char_traits<char>>::_M_allocate_buffers(
           this,
           0,
           stlp_std::_Filebuf_base::_M_page_size
         * ((stlp_std::_Filebuf_base::_M_page_size + 4095)
          / stlp_std::_Filebuf_base::_M_page_size));
}
