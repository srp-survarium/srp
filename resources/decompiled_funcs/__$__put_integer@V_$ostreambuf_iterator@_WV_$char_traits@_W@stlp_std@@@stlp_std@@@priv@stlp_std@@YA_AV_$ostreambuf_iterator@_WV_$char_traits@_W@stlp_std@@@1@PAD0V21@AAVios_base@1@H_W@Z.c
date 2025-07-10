// local variable allocation has failed, the output may be wrong!
stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__put_integer<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        char *__buf,
        char *__iend,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __s,
        stlp_std::ios_base *__f,
        __int16 __flags,
        wchar_t __fill)
{
  stlp_std::locale::facet *v7; // esi
  int v8; // ecx
  void (__thiscall *v9)(stlp_std::locale::facet *); // eax
  unsigned __int16 v10; // ax
  void (__thiscall *v11)(stlp_std::locale::facet *); // edx
  int inserted; // edi
  stlp_std::moneypunct<wchar_t,0> *v13; // esi
  int v14; // edi
  wchar_t v15; // ax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v16; // edi
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v18; // [esp-2Ch] [ebp-F8h]
  int v19; // [esp-24h] [ebp-F0h]
  __int64 M_width; // [esp-14h] [ebp-E0h]
  wchar_t v21; // [esp-8h] [ebp-D4h]
  wchar_t v22; // [esp-4h] [ebp-D0h]
  stlp_std::locale __loc; // [esp+14h] [ebp-B8h] BYREF
  int __xplus; // [esp+18h] [ebp-B4h] OVERLAPPED
  int __xminus; // [esp+1Ch] [ebp-B0h] OVERLAPPED
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v26; // [esp+20h] [ebp-ACh]
  stlp_std::basic_string<char,stlp_std::char_traits<char>,stlp_std::allocator<char> > grouping; // [esp+24h] [ebp-A8h] BYREF
  wchar_t __wbuf[64]; // [esp+3Ch] [ebp-90h] BYREF
  int v29; // [esp+C8h] [ebp-4h]

  v26 = result;
  stlp_std::ios_base::getloc(__f, &__loc);
  v29 = 0;
  v7 = stlp_std::locale::_M_use_facet(&__loc, &stlp_std::ctype<wchar_t>::id);
  v8 = ((unsigned __int16 (__thiscall *)(stlp_std::locale::facet *, int))v7->__vftable[10].~stlp_std::locale::facet)(
         v7,
         43);
  v9 = v7->__vftable[10].~stlp_std::locale::facet;
  __xplus = v8;
  v10 = ((int (__thiscall *)(stlp_std::locale::facet *, int))v9)(v7, 45);
  v11 = v7->__vftable[9].~stlp_std::locale::facet;
  __xminus = v10;
  ((void (__thiscall *)(stlp_std::locale::facet *, char *, char *, wchar_t *))v11)(v7, __buf, __iend, __wbuf);
  inserted = __iend - __buf;
  v13 = (stlp_std::moneypunct<wchar_t,0> *)stlp_std::locale::_M_use_facet(&__loc, &stlp_std::numpunct<wchar_t>::id);
  stlp_std::moneypunct<wchar_t,1>::grouping(v13, &grouping);
  LOBYTE(v29) = 1;
  if ( grouping._M_start_of_storage._M_data != grouping._M_finish )
  {
    if ( (__flags & 0x200) != 0 )
    {
      if ( (__flags & 0x38) == 0x10 )
        v14 = 2;
      else
        v14 = (__flags & 0x38) == 32;
    }
    else
    {
      v14 = 0;
    }
    v15 = v13->do_thousands_sep(v13);
    inserted = stlp_std::priv::__insert_grouping(
                 __wbuf,
                 &__wbuf[__iend - __buf],
                 &grouping,
                 v15,
                 __xplus,
                 __xminus,
                 v14);
  }
  v22 = __xminus;
  v21 = __xplus;
  M_width = __f->_M_width;
  v19 = inserted;
  v16 = v26;
  v18 = v26;
  __f->_M_width = 0;
  stlp_std::priv::__copy_integer_and_fill<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
    v18,
    __wbuf,
    v19,
    *(_QWORD *)&__s,
    __flags,
    (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)M_width,
    __fill,
    v21,
    v22);
  LOBYTE(v29) = 0;
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
  stlp_std::locale::~locale(&__loc);
  return v16;
}
