void __thiscall stlp_std::ios_base::Init::~Init(stlp_std::ios_base::Init *this)
{
  if ( !--stlp_std::ios_base::Init::_S_count )
  {
    stlp_std::ios_base::_S_uninitialize();
    _Locale_final();
  }
}
