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


stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *__thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_append(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        const char *__first,
        const char *__last)
{
  char *M_finish; // ecx
  unsigned int v5; // edi
  char *v6; // eax
  unsigned int size; // eax
  unsigned int v8; // ebp
  char *M_static_buf; // edi
  char *v10; // eax
  char *v11; // ebx

  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  v5 = __last - __first;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *)this->_M_start_of_storage._M_data == this )
    v6 = (char *)((char *)this - M_finish + 16);
  else
    v6 = (char *)(this->_M_buffers._M_end_of_storage - M_finish);
  if ( v5 < (unsigned int)v6 )
  {
    stlp_std::priv::__ucopy<char *,char *,int>(__first + 1, __last, M_finish + 1);
    this->_M_finish[v5] = 0;
    *this->_M_finish = *__first;
    this->_M_finish += v5;
    return this;
  }
  else
  {
    size = stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_compute_next_size(
             this,
             __last - __first);
    v8 = size;
    if ( size <= 0x101 )
      M_static_buf = this->_M_start_of_storage._M_static_buf;
    else
      M_static_buf = (char *)stlp_std::allocator<char>::allocate(&this->_M_start_of_storage, size, 0);
    v10 = stlp_std::priv::__ucopy<char *,char *,int>(this->_M_start_of_storage._M_data, this->_M_finish, M_static_buf);
    v11 = stlp_std::priv::__ucopy<char *,char *,int>(__first, __last, v10);
    *v11 = 0;
    stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_M_deallocate_block((stlp_std::priv::__basic_iostring<char> *)this);
    this->_M_start_of_storage._M_data = M_static_buf;
    this->_M_buffers._M_end_of_storage = &M_static_buf[v8];
    this->_M_finish = v11;
    return this;
  }
}


stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_append(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__first,
        wchar_t *__last)
{
  const wchar_t *v3; // edx
  wchar_t *v4; // ebp
  wchar_t *M_finish; // ecx
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  wchar_t *v10; // ebx
  wchar_t *v11; // eax
  wchar_t *v12; // ebp
  wchar_t *M_data; // eax
  wchar_t *v14; // ecx
  wchar_t *v16; // ecx
  unsigned int v17; // ebx

  v3 = __last;
  v4 = __first;
  if ( __first == __last )
    return this;
  M_finish = this->_M_finish;
  p_M_start_of_storage = &this->_M_start_of_storage;
  v8 = __last - __first;
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)this->_M_start_of_storage._M_data == this )
  {
    v9 = 16 - (((char *)M_finish - (char *)this) >> 1);
    v3 = __last;
  }
  else
  {
    v9 = this->_M_buffers._M_end_of_storage - M_finish;
  }
  if ( v8 < v9 )
  {
    stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(__first + 1, v3, M_finish + 1);
    v17 = v8;
    this->_M_finish[v17] = 0;
    *this->_M_finish = *v4;
    this->_M_finish = (wchar_t *)((char *)this->_M_finish + v17 * 2);
    return this;
  }
  __first = (wchar_t *)stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_compute_next_size(
                         this,
                         v8);
  v10 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(
                     &this->_M_start_of_storage,
                     (unsigned int)__first,
                     (unsigned int *)&__first);
  v11 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(p_M_start_of_storage->_M_data, this->_M_finish, v10);
  v12 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(v4, __last, v11);
  *v12 = 0;
  M_data = p_M_start_of_storage->_M_data;
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)p_M_start_of_storage->_M_data != this
    && M_data )
  {
    if ( (unsigned int)(2 * (this->_M_buffers._M_end_of_storage - M_data)) > 0x80 )
    {
      operator delete(p_M_start_of_storage->_M_data);
      v14 = __first;
      p_M_start_of_storage->_M_data = v10;
      this->_M_finish = v12;
      this->_M_buffers._M_end_of_storage = &v10[(_DWORD)v14];
      return this;
    }
    stlp_std::__node_alloc::_M_deallocate(
      (_STLP_atomic_freelist::item *)M_data,
      2 * (this->_M_buffers._M_end_of_storage - M_data));
  }
  v16 = __first;
  p_M_start_of_storage->_M_data = v10;
  this->_M_finish = v12;
  this->_M_buffers._M_end_of_storage = &v10[(_DWORD)v16];
  return this;
}
