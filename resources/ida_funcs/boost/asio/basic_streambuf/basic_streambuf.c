void __thiscall boost::asio::basic_streambuf<stlp_std::allocator<char>>::basic_streambuf<stlp_std::allocator<char>>(
        boost::asio::basic_streambuf<stlp_std::allocator<char> > *this,
        unsigned int maximum_size,
        const stlp_std::allocator<char> *allocator)
{
  unsigned int *v3; // eax
  char *v5; // [esp+4h] [ebp-4Ch]
  char *v6; // [esp+8h] [ebp-48h]
  char *M_start; // [esp+1Ch] [ebp-34h]
  unsigned int v8; // [esp+40h] [ebp-10h] BYREF
  char __x; // [esp+47h] [ebp-9h] BYREF
  unsigned int __b; // [esp+48h] [ebp-8h] BYREF
  unsigned int pend; // [esp+4Ch] [ebp-4h] BYREF

  stlp_std::basic_streambuf<char,stlp_std::char_traits<char>>::basic_streambuf<char,stlp_std::char_traits<char>>(this);
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->max_size_);
  this->__vftable = (boost::asio::basic_streambuf<stlp_std::allocator<char> >_vtbl *)&boost::asio::basic_streambuf<stlp_std::allocator<char>>::`vftable';
  this->max_size_ = maximum_size;
  stlp_std::priv::_Vector_base<char,stlp_std::allocator<char>>::_Vector_base<char,stlp_std::allocator<char>>(
    &this->buffer_._M_impl,
    allocator);
  __b = 128;
  pend = *stlp_std::min<unsigned int>(&this->max_size_, &__b);
  __x = 0;
  v8 = 1;
  v3 = (unsigned int *)stlp_std::max<unsigned int>(&pend, &v8);
  stlp_std::priv::_Impl_vector<char,stlp_std::allocator<char>>::resize(&this->buffer_._M_impl, *v3, &__x);
  M_start = this->buffer_._M_impl._M_start;
  this->_M_gbegin = M_start;
  this->_M_gnext = M_start;
  this->_M_gend = M_start;
  v5 = &this->buffer_._M_impl._M_start[pend];
  v6 = this->buffer_._M_impl._M_start;
  this->_M_pbegin = v6;
  this->_M_pnext = v6;
  this->_M_pend = v5;
}
