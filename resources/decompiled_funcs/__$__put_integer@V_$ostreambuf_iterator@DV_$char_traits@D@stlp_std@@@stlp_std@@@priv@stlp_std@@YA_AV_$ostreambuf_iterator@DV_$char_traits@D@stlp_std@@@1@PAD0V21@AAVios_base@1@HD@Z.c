stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *__cdecl stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *result,
        char *__buf,
        char *__iend,
        stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > __s,
        stlp_std::ios_base *__f,
        __int16 __flags,
        char __fill)
{
  char *v7; // edi
  unsigned int v8; // ebx
  stlp_std::locale *v9; // eax
  stlp_std::moneypunct<wchar_t,0> *v10; // ebp
  char *v11; // ebx
  int inserted; // eax
  unsigned int M_width; // ecx
  unsigned int M_width_high; // edx
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v15; // esi
  stlp_std::locale v17; // [esp+14h] [ebp-78h] BYREF
  int __basechars; // [esp+18h] [ebp-74h]
  int __len; // [esp+1Ch] [ebp-70h]
  stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> > *v20; // [esp+20h] [ebp-6Ch]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > grouping; // [esp+24h] [ebp-68h] BYREF
  char __grpbuf[64]; // [esp+3Ch] [ebp-50h] BYREF
  int v23; // [esp+88h] [ebp-4h]

  v7 = __buf;
  v8 = __iend - __buf;
  v20 = result;
  __len = __iend - __buf;
  v9 = stlp_std::ios_base::getloc(__f, &v17);
  v23 = 0;
  v10 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(v9, &stlp_std::numpunct<char>::id);
  v23 = -1;
  stlp_std::locale::~locale(&v17);
  stlp_std::moneypunct<wchar_t,1>::grouping(v10, &grouping);
  v23 = 1;
  if ( grouping._M_start_of_storage._M_data == grouping._M_finish )
  {
    inserted = __len;
  }
  else
  {
    if ( (__flags & 0x200) != 0 )
    {
      if ( (__flags & 0x38) == 0x10 )
        __basechars = 2;
      else
        __basechars = (__flags & 0x38) == 32;
    }
    else
    {
      __basechars = 0;
    }
    if ( v8 )
      memmove((unsigned __int8 *)__grpbuf, (unsigned __int8 *)__buf, v8);
    v7 = __grpbuf;
    v11 = &__grpbuf[__len];
    LOBYTE(v17._M_impl) = v10->do_thousands_sep(v10);
    inserted = stlp_std::priv::__insert_grouping(__grpbuf, v11, &grouping, (char)v17._M_impl, 43, 45, __basechars);
  }
  M_width = __f->_M_width;
  M_width_high = HIDWORD(__f->_M_width);
  __f->_M_width = 0;
  v15 = v20;
  stlp_std::priv::__copy_integer_and_fill<char,stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char>>>(
    v20,
    v7,
    inserted,
    *(_QWORD *)&__s,
    __flags,
    (stlp_std::ostreambuf_iterator<char,stlp_std::char_traits<char> >)__PAIR64__(M_width_high, M_width),
    __fill,
    43,
    45);
  v23 = -1;
  if ( (stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > *)grouping._M_start_of_storage._M_data != &grouping
    && grouping._M_start_of_storage._M_data )
  {
    if ( (unsigned int)(grouping._M_buffers._M_end_of_storage - grouping._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)grouping._M_start_of_storage._M_data,
        grouping._M_buffers._M_end_of_storage - grouping._M_start_of_storage._M_data);
    else
      operator delete(grouping._M_start_of_storage._M_data);
  }
  return v15;
}
