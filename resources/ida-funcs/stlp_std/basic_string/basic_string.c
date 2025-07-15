void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__f,
        char *__l,
        const stlp_std::allocator<char> *__a)
{
  char *v4; // [esp-8h] [ebp-Ch]

  v4 = __l;
  this->_M_finish = (char *)this;
  this->_M_start_of_storage._M_data = (char *)this;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize<char const *>(
    this,
    __f,
    v4,
    (const stlp_std::forward_iterator_tag *)&__l + 3);
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__f,
        wchar_t *__l,
        const stlp_std::allocator<wchar_t> *__a)
{
  this->_M_finish = (wchar_t *)this;
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize<wchar_t const *>(
    this,
    __f,
    __l,
    (const stlp_std::forward_iterator_tag *)&__l);
}


void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        const stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *__s)
{
  this->_M_finish = (char *)this;
  this->_M_start_of_storage._M_data = (char *)this;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize(
    this,
    __s->_M_start_of_storage._M_data,
    __s->_M_finish);
}


void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        unsigned int __n,
        char __c,
        const stlp_std::allocator<char> *__a)
{
  unsigned int v5; // ebx
  unsigned int v6; // eax
  stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::allocator<char> > *p_M_start_of_storage; // edi
  char *v8; // eax
  unsigned int v9; // edx
  char *M_data; // eax
  char *v11; // edi

  v5 = __n;
  v6 = __n + 1;
  p_M_start_of_storage = &this->_M_start_of_storage;
  this->_M_finish = (char *)this;
  this->_M_start_of_storage._M_data = (char *)this;
  __n = v6;
  if ( !v6 )
    stlp_std::__stl_throw_length_error("basic_string");
  if ( v6 > 0x10 )
  {
    v8 = (char *)stlp_std::allocator<char>::_M_allocate(&this->_M_start_of_storage, v6, &__n);
    v9 = __n;
    p_M_start_of_storage->_M_data = v8;
    this->_M_finish = v8;
    this->_M_buffers._M_end_of_storage = &v8[v9];
  }
  M_data = p_M_start_of_storage->_M_data;
  v11 = &p_M_start_of_storage->_M_data[v5];
  stlp_std::priv::__ufill<char *,char,int>(M_data, &M_data[v5], &__c);
  this->_M_finish = v11;
  *v11 = 0;
}


void __thiscall stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
        stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *this,
        char *__s,
        const stlp_std::allocator<char> *__a)
{
  this->_M_finish = (char *)this;
  this->_M_start_of_storage._M_data = (char *)this;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::_M_range_initialize(
    this,
    __s,
    &__s[strlen(__s)]);
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        const stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *__s)
{
  this->_M_finish = (wchar_t *)this;
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize(
    this,
    __s->_M_start_of_storage._M_data,
    __s->_M_finish);
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        unsigned int __n,
        int __c,
        const stlp_std::allocator<wchar_t> *__a)
{
  wchar_t *v5; // edi

  stlp_std::priv::_String_base<wchar_t,stlp_std::allocator<wchar_t>>::_String_base<wchar_t,stlp_std::allocator<wchar_t>>(
    this,
    __a,
    __n + 1);
  v5 = &this->_M_start_of_storage._M_data[__n];
  stlp_std::priv::__ufill<wchar_t *,wchar_t,int>(this->_M_start_of_storage._M_data, v5, (wchar_t *)&__c);
  this->_M_finish = v5;
  *v5 = 0;
}


void __thiscall stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>(
        stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > *this,
        wchar_t *__s,
        const stlp_std::allocator<wchar_t> *__a)
{
  this->_M_finish = (wchar_t *)this;
  this->_M_start_of_storage._M_data = (wchar_t *)this;
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t>>::_M_range_initialize(
    this,
    __s,
    &__s[wcslen(__s)]);
}
