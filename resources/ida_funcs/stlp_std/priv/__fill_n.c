unsigned int *__fastcall stlp_std::priv::__fill_n<unsigned int *,unsigned int,unsigned int>(
        unsigned int __n,
        unsigned int *__val,
        unsigned int *__first)
{
  unsigned int *result; // eax

  for ( result = __first; __n; ++result )
  {
    *result = *__val;
    --__n;
  }
  return result;
}


void **__cdecl stlp_std::priv::__fill_n<void * *,unsigned int,void *>(
        void **__first,
        unsigned int __n,
        void *const *__val)
{
  unsigned int v3; // ecx
  void **result; // eax

  v3 = __n;
  for ( result = __first; v3; ++result )
  {
    *result = *__val;
    --v3;
  }
  return result;
}


vostok::render::batched_vertex_source *__fastcall stlp_std::priv::__fill_n<vostok::render::batched_vertex_source *,unsigned int,vostok::render::batched_vertex_source>(
        const vostok::render::batched_vertex_source *__val,
        unsigned int __n,
        vostok::render::batched_vertex_source *__first)
{
  vostok::render::batched_vertex_source *result; // eax

  for ( result = __first; __n; ++result )
  {
    *result = *__val;
    --__n;
  }
  return result;
}


D3D11_INPUT_ELEMENT_DESC *__fastcall stlp_std::priv::__fill_n<vostok::render::ui::vertex *,unsigned int,vostok::render::ui::vertex>(
        const D3D11_INPUT_ELEMENT_DESC *__val,
        unsigned int __n,
        D3D11_INPUT_ELEMENT_DESC *__first)
{
  D3D11_INPUT_ELEMENT_DESC *result; // eax

  for ( result = __first; __n; ++result )
  {
    *result = *__val;
    --__n;
  }
  return result;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,int,char>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __first,
        int __n,
        const char *__val)
{
  int v4; // esi
  bool M_ok; // al
  char *M_pnext; // edx
  unsigned __int8 v7; // bl
  int v8; // eax
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // eax

  v4 = __n;
  if ( __n > 0 )
  {
    M_ok = __first._M_ok;
    do
    {
      M_ok = M_ok
          && ((M_pnext = __first._M_buf->_M_pnext, v7 = *__val, M_pnext >= __first._M_buf->_M_pend)
            ? (v8 = __first._M_buf->overflow(__first._M_buf, v7))
            : (*M_pnext = v7, ++__first._M_buf->_M_pnext, v8 = (unsigned __int8)*M_pnext),
              v8 != -1);
      --v4;
      __first._M_ok = M_ok;
    }
    while ( v4 > 0 );
  }
  v9 = result;
  *result = __first;
  return v9;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,unsigned int,char>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __first,
        unsigned int __n,
        const char *__val)
{
  unsigned int v4; // edi
  bool M_ok; // al
  char *M_pnext; // edx
  unsigned __int8 v7; // bl
  int v8; // eax
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // eax

  v4 = __n;
  if ( __n )
  {
    M_ok = __first._M_ok;
    do
    {
      M_ok = M_ok
          && ((M_pnext = __first._M_buf->_M_pnext, v7 = *__val, M_pnext >= __first._M_buf->_M_pend)
            ? (v8 = __first._M_buf->overflow(__first._M_buf, v7))
            : (*M_pnext = v7, ++__first._M_buf->_M_pnext, v8 = (unsigned __int8)*M_pnext),
              v8 != -1);
      --v4;
      __first._M_ok = M_ok;
    }
    while ( v4 );
  }
  v9 = result;
  *result = __first;
  return v9;
}


stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>,__int64,char>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __first,
        __int64 __n,
        const char *__val)
{
  __int64 v4; // rdi
  bool M_ok; // al
  char *M_pnext; // edx
  unsigned __int8 v7; // bl
  int v8; // eax
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v9; // eax

  HIDWORD(v4) = HIDWORD(__n);
  if ( __n >= 0 )
  {
    LODWORD(v4) = __n;
    if ( __n > 0 )
    {
      M_ok = __first._M_ok;
      do
      {
        M_ok = M_ok
            && ((M_pnext = __first._M_buf->_M_pnext, v7 = *__val, M_pnext >= __first._M_buf->_M_pend)
              ? (v8 = __first._M_buf->overflow(__first._M_buf, v7))
              : (*M_pnext = v7, ++__first._M_buf->_M_pnext, v8 = (unsigned __int8)*M_pnext),
                v8 != -1);
        --v4;
        __first._M_ok = M_ok;
      }
      while ( v4 > 0 );
    }
  }
  v9 = result;
  *result = __first;
  return v9;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __first,
        int __n,
        const wchar_t *__val)
{
  int v4; // ebx
  bool M_ok; // al
  wchar_t *M_pnext; // edx
  unsigned __int16 v7; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v8; // eax

  v4 = __n;
  if ( __n > 0 )
  {
    M_ok = __first._M_ok;
    do
    {
      M_ok = M_ok
          && ((M_pnext = __first._M_buf->_M_pnext, M_pnext >= __first._M_buf->_M_pend)
            ? (v7 = __first._M_buf->overflow(__first._M_buf, *__val))
            : (*M_pnext = *__val, ++__first._M_buf->_M_pnext, v7 = *M_pnext),
              v7 != 0xFFFF);
      --v4;
      __first._M_ok = M_ok;
    }
    while ( v4 > 0 );
  }
  v8 = result;
  *result = __first;
  return v8;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,unsigned int,wchar_t>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __first,
        unsigned int __n,
        const wchar_t *__val)
{
  unsigned int v4; // ebx
  bool M_ok; // al
  wchar_t *M_pnext; // edx
  unsigned __int16 v7; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v8; // eax

  v4 = __n;
  if ( __n )
  {
    M_ok = __first._M_ok;
    do
    {
      M_ok = M_ok
          && ((M_pnext = __first._M_buf->_M_pnext, M_pnext >= __first._M_buf->_M_pend)
            ? (v7 = __first._M_buf->overflow(__first._M_buf, *__val))
            : (*M_pnext = *__val, ++__first._M_buf->_M_pnext, v7 = *M_pnext),
              v7 != 0xFFFF);
      --v4;
      __first._M_ok = M_ok;
    }
    while ( v4 );
  }
  v8 = result;
  *result = __first;
  return v8;
}


stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,__int64,wchar_t>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __first,
        __int64 __n,
        const wchar_t *__val)
{
  unsigned int v4; // edi
  unsigned int v5; // ebx
  bool M_ok; // al
  wchar_t *M_pnext; // edx
  unsigned __int16 v8; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v9; // eax

  v4 = HIDWORD(__n);
  if ( __n >= 0 )
  {
    v5 = __n;
    if ( __n > 0 )
    {
      M_ok = __first._M_ok;
      do
      {
        M_ok = M_ok
            && ((M_pnext = __first._M_buf->_M_pnext, M_pnext >= __first._M_buf->_M_pend)
              ? (v8 = __first._M_buf->overflow(__first._M_buf, *__val))
              : (*M_pnext = *__val, ++__first._M_buf->_M_pnext, v8 = *M_pnext),
                v8 != 0xFFFF);
        v4 = (__PAIR64__(v4, v5--) - 1) >> 32;
        __first._M_ok = M_ok;
      }
      while ( __SPAIR64__(v4, v5) > 0 );
    }
  }
  v9 = result;
  *result = __first;
  return v9;
}
