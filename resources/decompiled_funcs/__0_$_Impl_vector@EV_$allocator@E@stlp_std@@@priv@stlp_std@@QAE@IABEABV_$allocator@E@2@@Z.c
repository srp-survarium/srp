void __thiscall stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>(
        stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char> > *this,
        unsigned int __n,
        const unsigned __int8 *__val,
        const stlp_std::allocator<unsigned char> *__a)
{
  const stlp_std::allocator<unsigned char> *v4; // [esp+0h] [ebp-2Ch]
  int i; // [esp+10h] [ebp-1Ch]
  unsigned __int8 *M_start; // [esp+14h] [ebp-18h]
  unsigned __int8 *v8; // [esp+1Ch] [ebp-10h]

  stlp_std::priv::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>::_Vector_base<unsigned char,stlp_std::allocator<unsigned char>>(
    this,
    __n,
    v4);
  v8 = &this->_M_start[__n];
  M_start = this->_M_start;
  for ( i = __n; i > 0; --i )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *M_start++ = *__val;
  }
  this->_M_finish = v8;
}
