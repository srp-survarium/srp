stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_append(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__first,
        char *__last)
{
  unsigned int v4; // [esp+0h] [ebp-84h]
  const char *v6; // [esp+14h] [ebp-70h]
  int i; // [esp+1Ch] [ebp-68h]
  char *v8; // [esp+20h] [ebp-64h]
  char *v9; // [esp+30h] [ebp-54h]
  int k; // [esp+34h] [ebp-50h]
  char *v11; // [esp+38h] [ebp-4Ch]
  btBroadphasePair *Length; // [esp+40h] [ebp-44h]
  char *__val; // [esp+48h] [ebp-3Ch]
  int j; // [esp+4Ch] [ebp-38h]
  char *__p; // [esp+50h] [ebp-34h]
  char *__new_start; // [esp+78h] [ebp-Ch]
  unsigned int __len; // [esp+7Ch] [ebp-8h] BYREF
  unsigned int __n; // [esp+80h] [ebp-4h]

  if ( __first != __last )
  {
    __n = __last - __first;
    if ( stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_using_static_buf(this) )
      v4 = 16 - (this->_M_finish - (char *)this);
    else
      v4 = this->_M_buffers._M_end_of_storage - this->_M_finish;
    if ( __n < v4 )
    {
      v6 = __first + 1;
      v8 = this->_M_finish + 1;
      for ( i = __last - (__first + 1); i > 0; --i )
      {
        survarium::generate_shaders_world::is_loading();
        survarium::generate_shaders_world::is_loading();
        *v8++ = *v6++;
      }
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_construct_null(
        this,
        &this->_M_finish[__n]);
      LOBYTE(Scaleform::MemoryFile::GetLength((btNullPairCache *)this)->m_pProxy0) = *__first;
      this->_M_finish += __n;
    }
    else
    {
      __len = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_compute_next_size(
                this,
                __n);
      __new_start = stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
                      &this->_M_start_of_storage,
                      __len,
                      &__len);
      Length = Scaleform::MemoryFile::GetLength((btNullPairCache *)this);
      __val = (char *)stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
      __p = __new_start;
      for ( j = (char *)Length - __val; j > 0; --j )
        stlp_std::_Param_Construct<char,char>(__p++, __val++);
      v9 = __first;
      v11 = __p;
      for ( k = __last - __first; k > 0; --k )
        stlp_std::_Param_Construct<char,char>(v11++, v9++);
      stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_construct_null(this, v11);
      stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(this);
      this->_M_buffers._M_end_of_storage = &__new_start[__len];
      this->_M_finish = v11;
      this->_M_start_of_storage._M_data = __new_start;
    }
  }
  return this;
}
