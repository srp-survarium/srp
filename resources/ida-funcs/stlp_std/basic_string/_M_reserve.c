void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_reserve(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n)
{
  btBroadphasePair *Length; // [esp+Ch] [ebp-30h]
  btPersistentManifold **v4; // [esp+14h] [ebp-28h]
  int i; // [esp+1Ch] [ebp-20h]
  char *v6; // [esp+20h] [ebp-1Ch]
  char *__new_start; // [esp+38h] [ebp-4h]

  __new_start = stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char>>::allocate(
                  &this->_M_start_of_storage,
                  __n,
                  &__n);
  Length = Scaleform::MemoryFile::GetLength((btNullPairCache *)this);
  v4 = stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_Start((btCollisionDispatcher *)this);
  v6 = __new_start;
  for ( i = (char *)Length - (char *)v4; i > 0; --i )
  {
    survarium::generate_shaders_world::is_loading();
    survarium::generate_shaders_world::is_loading();
    *v6 = *(_BYTE *)v4;
    v4 = (btPersistentManifold **)((char *)v4 + 1);
    ++v6;
  }
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_construct_null(this, v6);
  stlp_std::priv::_String_base<char,stlp_std::allocator<char>>::_M_deallocate_block(this);
  this->_M_buffers._M_end_of_storage = &__new_start[__n];
  this->_M_finish = v6;
  this->_M_start_of_storage._M_data = __new_start;
}


void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char>>::_M_reserve(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::priv::__iostring_allocator<char> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *p_M_start_of_storage; // ebp
  char *M_static_buf; // edi
  char *v5; // ebx
  char *M_data; // eax

  p_M_start_of_storage = &this->_M_start_of_storage;
  if ( __n <= 0x101 )
    M_static_buf = this->_M_start_of_storage._M_static_buf;
  else
    M_static_buf = (char *)stlp_std::allocator<char>::allocate(&this->_M_start_of_storage, __n, 0);
  v5 = stlp_std::priv::__ucopy<char *,char *,int>(this->_M_start_of_storage._M_data, this->_M_finish, M_static_buf);
  *v5 = 0;
  M_data = this->_M_start_of_storage._M_data;
  if ( M_data != (char *)this && M_data && M_data != (char *)p_M_start_of_storage )
  {
    if ( (unsigned int)(this->_M_buffers._M_end_of_storage - M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        this->_M_buffers._M_end_of_storage - M_data);
    else
      operator delete(this->_M_start_of_storage._M_data);
  }
  this->_M_start_of_storage._M_data = M_static_buf;
  this->_M_finish = v5;
  this->_M_buffers._M_end_of_storage = &M_static_buf[__n];
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_reserve(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::allocator<wchar_t> > *p_M_start_of_storage; // edi
  wchar_t *v4; // ebx
  wchar_t *v5; // ebp
  wchar_t *M_data; // eax
  wchar_t *v7; // edx
  wchar_t *v8; // edx

  p_M_start_of_storage = &this->_M_start_of_storage;
  v4 = (wchar_t *)stlp_std::allocator<wchar_t>::_M_allocate(&this->_M_start_of_storage, __n, &__n);
  v5 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(p_M_start_of_storage->_M_data, this->_M_finish, v4);
  *v5 = 0;
  M_data = p_M_start_of_storage->_M_data;
  if ( (stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *)p_M_start_of_storage->_M_data != this
    && M_data )
  {
    if ( (unsigned int)(2 * (this->_M_buffers._M_end_of_storage - M_data)) > 0x80 )
    {
      operator delete(p_M_start_of_storage->_M_data);
      v7 = &v4[__n];
      p_M_start_of_storage->_M_data = v4;
      this->_M_finish = v5;
      this->_M_buffers._M_end_of_storage = v7;
      return;
    }
    stlp_std::__node_alloc::_M_deallocate(
      (_STLP_atomic_freelist::item *)M_data,
      2 * (this->_M_buffers._M_end_of_storage - M_data));
  }
  v8 = &v4[__n];
  p_M_start_of_storage->_M_data = v4;
  this->_M_finish = v5;
  this->_M_buffers._M_end_of_storage = v8;
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t>>::_M_reserve(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::priv::__iostring_allocator<wchar_t> > *this,
        unsigned int __n)
{
  stlp_std::priv::_STLP_alloc_proxy<wchar_t *,wchar_t,stlp_std::priv::__iostring_allocator<wchar_t> > *p_M_start_of_storage; // ebp
  wchar_t *M_static_buf; // edi
  wchar_t *v5; // ebx
  wchar_t *M_data; // eax

  p_M_start_of_storage = &this->_M_start_of_storage;
  if ( __n <= 0x101 )
    M_static_buf = this->_M_start_of_storage._M_static_buf;
  else
    M_static_buf = (wchar_t *)stlp_std::allocator<wchar_t>::allocate(&this->_M_start_of_storage, __n, 0);
  v5 = stlp_std::priv::__ucopy<wchar_t const *,wchar_t *,int>(
         this->_M_start_of_storage._M_data,
         this->_M_finish,
         M_static_buf);
  *v5 = 0;
  M_data = this->_M_start_of_storage._M_data;
  if ( M_data != (wchar_t *)this && M_data && M_data != (wchar_t *)p_M_start_of_storage )
  {
    if ( (unsigned int)(2 * (this->_M_buffers._M_end_of_storage - M_data)) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)M_data,
        2 * (this->_M_buffers._M_end_of_storage - M_data));
    else
      operator delete(this->_M_start_of_storage._M_data);
  }
  this->_M_start_of_storage._M_data = M_static_buf;
  this->_M_finish = v5;
  this->_M_buffers._M_end_of_storage = &M_static_buf[__n];
}
