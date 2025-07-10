void __cdecl __lc_lctostr(char *locale, unsigned int sizeInBytes, const tagLC_STRINGS *names)
{
  if ( strcpy_s(locale, sizeInBytes, names->szLanguage) )
    _invoke_watson(0, 0, 0, 0, 0);
  if ( names->szCountry[0] )
    _strcats(locale, sizeInBytes, 2, "_", names->szCountry);
  if ( names->szCodePage[0] )
    _strcats(
      locale,
      sizeInBytes,
      2,
      &stru_957BE0.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
      names->szCodePage);
}
