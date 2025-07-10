stlp_std::locale::facet *__thiscall stlp_std::locale::_M_use_facet(
        stlp_std::locale *this,
        const stlp_std::locale::id *n)
{
  stlp_std::locale::facet *result; // eax

  if ( n->_M_index >= this->_M_impl->facets_vec._M_impl._M_finish - this->_M_impl->facets_vec._M_impl._M_start
    || (result = (stlp_std::locale::facet *)this->_M_impl->facets_vec._M_impl._M_start[n->_M_index]) == 0 )
  {
    stlp_std::_Locale_impl::_M_throw_bad_cast();
  }
  return result;
}
