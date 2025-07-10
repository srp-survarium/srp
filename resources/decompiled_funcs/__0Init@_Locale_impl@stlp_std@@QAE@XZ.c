void __thiscall stlp_std::_Locale_impl::Init::Init(stlp_std::_Locale_impl::Init *this)
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    Addend = 0;
  }
  if ( InterlockedIncrement(&Addend) == 1 )
  {
    stlp_std::_Stl_loc_assign_ids();
    stlp_std::_Locale_impl::make_classic_locale();
  }
}
