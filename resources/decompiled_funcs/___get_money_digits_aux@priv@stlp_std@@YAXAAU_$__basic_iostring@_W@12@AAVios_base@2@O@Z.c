void __cdecl stlp_std::priv::__get_money_digits_aux(
        stlp_std::priv::__basic_iostring<wchar_t> *__wbuf,
        stlp_std::ios_base *__f,
        long double __x)
{
  stlp_std::locale *v3; // eax
  const stlp_std::ctype<wchar_t> *v4; // edi
  stlp_std::locale result; // [esp+14h] [ebp-234h] BYREF
  stlp_std::priv::__iostring_allocator<char> __a; // [esp+1Bh] [ebp-22Dh] BYREF
  stlp_std::priv::__basic_iostring<char> __buf; // [esp+11Ch] [ebp-12Ch] BYREF
  int v8; // [esp+244h] [ebp-4h]

  stlp_std::priv::_String_base<char,stlp_std::priv::__iostring_allocator<char>>::_String_base<char,stlp_std::priv::__iostring_allocator<char>>(
    &__buf,
    &__a,
    0x101u);
  *__buf._M_finish = 0;
  v8 = 0;
  stlp_std::priv::__get_floor_digits(&__buf, __x);
  v3 = stlp_std::ios_base::getloc(__f, &result);
  LOBYTE(v8) = 1;
  v4 = (const stlp_std::ctype<wchar_t> *)stlp_std::locale::_M_use_facet(v3, &stlp_std::ctype<wchar_t>::id);
  LOBYTE(v8) = 0;
  stlp_std::locale::~locale(&result);
  stlp_std::priv::__convert_float_buffer(&__buf, __wbuf, v4, 0, 0);
  v8 = -1;
  if ( (stlp_std::priv::__basic_iostring<char> *)__buf._M_start_of_storage._M_data != &__buf
    && __buf._M_start_of_storage._M_data
    && (stlp_std::priv::_STLP_alloc_proxy<char *,char,stlp_std::priv::__iostring_allocator<char> > *)__buf._M_start_of_storage._M_data != &__buf._M_start_of_storage )
  {
    if ( (unsigned int)(__buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data) <= 0x80 )
      stlp_std::__node_alloc::_M_deallocate(
        (_STLP_atomic_freelist::item *)__buf._M_start_of_storage._M_data,
        __buf._M_buffers._M_end_of_storage - __buf._M_start_of_storage._M_data);
    else
      operator delete(__buf._M_start_of_storage._M_data);
  }
}
