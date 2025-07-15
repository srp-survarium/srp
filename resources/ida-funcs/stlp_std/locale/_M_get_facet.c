stlp_std::locale::facet *__thiscall stlp_std::locale::_M_get_facet(
        stlp_std::locale *this,
        const stlp_std::locale::id *n)
{
  if ( n->_M_index >= this->_M_impl->facets_vec._M_impl._M_finish - this->_M_impl->facets_vec._M_impl._M_start )
    return 0;
  else
    return (stlp_std::locale::facet *)this->_M_impl->facets_vec._M_impl._M_start[n->_M_index];
}
