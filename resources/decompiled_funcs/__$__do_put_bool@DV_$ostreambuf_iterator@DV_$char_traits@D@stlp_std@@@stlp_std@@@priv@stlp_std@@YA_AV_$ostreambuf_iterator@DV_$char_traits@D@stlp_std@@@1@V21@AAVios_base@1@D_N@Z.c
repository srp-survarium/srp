stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__do_put_bool<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        char __fill,
        bool __x)
{
  stlp_std::locale *v5; // eax
  stlp_std::moneypunct<wchar_t,0> *v6; // edi
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *v7; // eax
  int v8; // ebx
  char *M_finish; // ebx
  char *M_data; // edi
  unsigned int M_width; // eax
  unsigned int M_width_high; // ecx
  unsigned int v13; // edx
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v14; // esi
  unsigned int v15; // ebp
  unsigned int v16; // edi
  unsigned __int64 v17; // kr00_8
  char *v18; // eax
  unsigned int v19; // ecx
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v20; // eax
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > v22; // [esp+20h] [ebp-60h] BYREF
  stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > v23; // [esp+28h] [ebp-58h] BYREF
  _STLP_atomic_freelist::item *v24; // [esp+54h] [ebp-2Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > v25; // [esp+58h] [ebp-28h] BYREF
  int v26; // [esp+7Ch] [ebp-4h]

  v5 = stlp_std::ios_base::getloc(__f, (stlp_std::locale *)&v22);
  v26 = 0;
  v6 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(v5, &stlp_std::numpunct<char>::id);
  v26 = -1;
  stlp_std::locale::~locale((stlp_std::locale *)&v22);
  if ( __x )
  {
    v7 = stlp_std::moneypunct<char,0>::curr_symbol(
           v6,
           (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v23._M_buffers._M_static_buf[12]);
    v8 = 1;
  }
  else
  {
    v7 = stlp_std::moneypunct<wchar_t,1>::positive_sign(
           v6,
           (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)&v23);
    v8 = 2;
  }
  v26 = v8;
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char>>(
    &v25,
    v7);
  v26 = 4;
  if ( (v8 & 2) != 0 )
  {
    LOBYTE(v8) = v8 & 0xFD;
    if ( *(stlp_std::basic_string<wchar_t,stlp_std::char_traits<wchar_t>,stlp_std::allocator<wchar_t> > **)&v23._M_buffers._M_static_buf[10] != &v23 )
    {
      if ( *(_DWORD *)&v23._M_buffers._M_static_buf[10] )
      {
        if ( (unsigned int)v23._M_buffers._M_end_of_storage - *(_DWORD *)&v23._M_buffers._M_static_buf[10] <= 0x80 )
          stlp_std::__node_alloc::_M_deallocate(
            *(_STLP_atomic_freelist::item **)&v23._M_buffers._M_static_buf[10],
            (unsigned int)v23._M_buffers._M_end_of_storage - *(_DWORD *)&v23._M_buffers._M_static_buf[10]);
        else
          operator delete(*(void **)&v23._M_buffers._M_static_buf[10]);
      }
    }
  }
  LOBYTE(v26) = 5;
  if ( (v8 & 1) != 0 && v24 != (_STLP_atomic_freelist::item *)&v23._M_buffers._M_static_buf[12] && v24 )
  {
    if ( (unsigned int)(*(_DWORD *)&v23._M_buffers._M_static_buf[12] - (_DWORD)v24) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(v24, *(_DWORD *)&v23._M_buffers._M_static_buf[12] - (_DWORD)v24);
    else
      operator delete(v24);
  }
  M_finish = v25._M_finish;
  M_data = v25._M_start_of_storage._M_data;
  M_width = __f->_M_width;
  M_width_high = HIDWORD(__f->_M_width);
  v13 = v25._M_finish - v25._M_start_of_storage._M_data;
  __f->_M_width = 0;
  if ( v13 < M_width )
  {
    v17 = __PAIR64__(M_width_high, M_width) - v13;
    v15 = HIDWORD(v17);
    v16 = v17;
    if ( (__f->_M_fmtflags & 7) == 1 )
    {
      stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
        &v22,
        v25._M_start_of_storage._M_data,
        M_finish,
        __s);
      v14 = result;
      stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
        result,
        v22,
        __SPAIR64__(v15, v16),
        &__fill);
      v18 = v25._M_start_of_storage._M_data;
      v26 = -1;
      if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v25._M_start_of_storage._M_data == &v25
        || !v25._M_start_of_storage._M_data )
      {
        return v14;
      }
      v19 = v25._M_buffers._M_end_of_storage - v25._M_start_of_storage._M_data;
      if ( (unsigned int)(v25._M_buffers._M_end_of_storage - v25._M_start_of_storage._M_data) > 0x80 )
        goto LABEL_29;
    }
    else
    {
      v20 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
              &v22,
              __s,
              __PAIR64__(M_width_high, M_width) - v13,
              &__fill);
      v14 = result;
      stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
        result,
        v25._M_start_of_storage._M_data,
        v25._M_finish,
        *v20);
      v18 = v25._M_start_of_storage._M_data;
      v26 = -1;
      if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v25._M_start_of_storage._M_data == &v25
        || !v25._M_start_of_storage._M_data )
      {
        return v14;
      }
      v19 = v25._M_buffers._M_end_of_storage - v25._M_start_of_storage._M_data;
      if ( (unsigned int)(v25._M_buffers._M_end_of_storage - v25._M_start_of_storage._M_data) > 0x80 )
        goto LABEL_29;
    }
    stlp_std::__node_alloc::_M_deallocate((_STLP_atomic_freelist::item *)v18, v19);
    return v14;
  }
  v14 = result;
  stlp_std::priv::__copy<char const *,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int>(
    result,
    M_data,
    M_finish,
    __s);
  v26 = -1;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)v25._M_start_of_storage._M_data != &v25
    && v25._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(v25._M_buffers._M_end_of_storage - v25._M_start_of_storage._M_data) <= 0x80 )
    {
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)v25._M_start_of_storage._M_data,
        v25._M_buffers._M_end_of_storage - v25._M_start_of_storage._M_data);
      return v14;
    }
LABEL_29:
    operator delete(v25._M_start_of_storage._M_data);
  }
  return v14;
}
