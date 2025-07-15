stlp_std::locale *__cdecl stlp_std::_Stl_get_global_locale()
{
  if ( (_S3 & 1) == 0 )
  {
    _S3 |= 1u;
    if ( (_S1 & 1) == 0 )
    {
      _S1 |= 1u;
      dword_8E3FF4 = 0;
    }
    if ( InterlockedIncrement(&dword_8E3FF4) == 1 )
    {
      stlp_std::_Stl_loc_assign_ids();
      stlp_std::_Locale_impl::make_classic_locale();
    }
    atexit((int (__cdecl *)())stlp_std::_Stl_get_global_locale_::_2_::_dynamic_atexit_destructor_for__init__);
  }
  return Stl_global_locale;
}
