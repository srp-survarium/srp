void __thiscall stlp_std::ios_base::Init::Init(stlp_std::ios_base::Init *this)
{
  if ( !stlp_std::ios_base::Init::_S_count++ )
  {
    _Locale_init();
    stlp_std::ios_base::_S_initialize();
    stlp_std::_Filebuf_base::_S_initialize();
  }
}
