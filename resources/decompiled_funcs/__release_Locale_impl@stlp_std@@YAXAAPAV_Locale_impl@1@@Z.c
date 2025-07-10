void __cdecl stlp_std::_release_Locale_impl(stlp_std::_Locale_impl **loc)
{
  stlp_std::_Locale_impl *v1; // esi

  if ( !InterlockedDecrement(&(*loc)->_M_ref_count) )
  {
    v1 = *loc;
    if ( Stl_classic_locale->_M_impl == *loc )
    {
      stlp_std::_Locale_impl::~_Locale_impl(*loc);
    }
    else if ( v1 )
    {
      stlp_std::_Locale_impl::~_Locale_impl(*loc);
      operator delete(v1);
      *loc = 0;
      return;
    }
    *loc = 0;
  }
}
