void __thiscall stlp_std::_Locale_impl::_Locale_impl(stlp_std::_Locale_impl *this, char *s)
{
  stlp_std::allocator<char> v3; // [esp+Bh] [ebp-15h] BYREF
  stlp_std::_Locale_impl *v4; // [esp+Ch] [ebp-14h]
  stlp_std::_Stl_aligned_buffer<stlp_std::_Locale_impl::Init> *v5; // [esp+10h] [ebp-10h]
  int v6; // [esp+1Ch] [ebp-4h]

  v4 = this;
  this->_M_ref_count = 0;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &this->name,
    s,
    &v3);
  this->facets_vec._M_impl._M_start = 0;
  this->facets_vec._M_impl._M_finish = 0;
  v6 = 0;
  this->facets_vec._M_impl._M_end_of_storage._M_data = 0;
  LOBYTE(v6) = 1;
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::reserve(
    &this->facets_vec._M_impl,
    stlp_std::locale::id::_S_max);
  v5 = &_Loc_init_buf;
  LOBYTE(v6) = 2;
  stlp_std::_Locale_impl::Init::Init((stlp_std::_Locale_impl::Init *)&_Loc_init_buf);
}
