const stlp_std::locale *__thiscall stlp_std::locale::operator=(stlp_std::locale *this, const stlp_std::locale *L)
{
  if ( this->_M_impl != L->_M_impl )
  {
    if ( this->_M_impl )
      stlp_std::_release_Locale_impl(&this->_M_impl);
    this->_M_impl = stlp_std::_get_Locale_impl(L->_M_impl);
  }
  return this;
}


char __thiscall stlp_std::locale::operator==(stlp_std::locale *this, stlp_std::locale *L)
{
  char v3; // bl
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v4; // esi
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v5; // eax
  char *M_finish; // edx
  char *v7; // ecx
  const char *M_data; // esi
  const char *v9; // edi
  const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v10; // eax
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v12; // [esp+18h] [ebp-54h] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v13; // [esp+30h] [ebp-3Ch] BYREF
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > result; // [esp+48h] [ebp-24h] BYREF
  int v15; // [esp+68h] [ebp-4h]
  char v16; // [esp+70h] [ebp+4h]

  v3 = 0;
  if ( this->_M_impl == L->_M_impl )
    goto LABEL_5;
  v4 = stlp_std::locale::name(L, &result);
  v15 = 0;
  v5 = stlp_std::locale::name(this, &v13);
  M_finish = v5->_M_finish;
  v7 = v4->_M_finish;
  M_data = v4->_M_start_of_storage._M_data;
  v15 = 1;
  v9 = v5->_M_start_of_storage._M_data;
  if ( M_finish - v9 != v7 - M_data || stlp_std::char_traits<char>::compare(v9, M_data, M_finish - v9) )
  {
    v3 = 3;
    goto LABEL_12;
  }
  v10 = stlp_std::locale::name(this, &v12);
  v3 = 7;
  if ( !stlp_std::operator!=<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(v10, &Nameless) )
  {
LABEL_12:
    v16 = 0;
    goto LABEL_6;
  }
LABEL_5:
  v16 = 1;
LABEL_6:
  if ( (v3 & 4) != 0 )
  {
    v3 &= ~4u;
    if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v12._M_start_of_storage._M_data != &v12 )
    {
      if ( v12._M_start_of_storage._M_data )
      {
        if ( (unsigned int)(v12._M_buffers._M_end_of_storage - v12._M_start_of_storage._M_data) <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            (_STLP_atomic_freelist::item *)v12._M_start_of_storage._M_data,
            v12._M_buffers._M_end_of_storage - v12._M_start_of_storage._M_data);
        else
          operator delete(v12._M_start_of_storage._M_data);
      }
    }
  }
  v15 = 0;
  if ( (v3 & 2) != 0 )
  {
    v3 &= ~2u;
    if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v13._M_start_of_storage._M_data != &v13 )
    {
      if ( v13._M_start_of_storage._M_data )
      {
        if ( (unsigned int)(v13._M_buffers._M_end_of_storage - v13._M_start_of_storage._M_data) <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            (_STLP_atomic_freelist::item *)v13._M_start_of_storage._M_data,
            v13._M_buffers._M_end_of_storage - v13._M_start_of_storage._M_data);
        else
          operator delete(v13._M_start_of_storage._M_data);
      }
    }
  }
  v15 = -1;
  if ( (v3 & 1) != 0
    && (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)result._M_start_of_storage._M_data != &result
    && result._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(result._M_buffers._M_end_of_storage - result._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)result._M_start_of_storage._M_data,
        result._M_buffers._M_end_of_storage - result._M_start_of_storage._M_data);
    else
      operator delete(result._M_start_of_storage._M_data);
  }
  return v16;
}


bool __thiscall stlp_std::locale::operator!=(stlp_std::locale *this, stlp_std::locale *L)
{
  return stlp_std::locale::operator==(this, L) == 0;
}
