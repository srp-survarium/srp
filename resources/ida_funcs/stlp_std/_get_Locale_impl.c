stlp_std::_Locale_impl *__cdecl stlp_std::_get_Locale_impl(stlp_std::_Locale_impl *loc)
{
  InterlockedIncrement(&loc->_M_ref_count);
  return loc;
}
