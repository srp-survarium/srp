void __cdecl stlp_std::_Stl_get_global_locale_::_2_::_dynamic_atexit_destructor_for__init__()
{
  if ( (_S1 & 1) == 0 )
  {
    _S1 |= 1u;
    Addend = 0;
  }
  InterlockedDecrement(&Addend);
}
