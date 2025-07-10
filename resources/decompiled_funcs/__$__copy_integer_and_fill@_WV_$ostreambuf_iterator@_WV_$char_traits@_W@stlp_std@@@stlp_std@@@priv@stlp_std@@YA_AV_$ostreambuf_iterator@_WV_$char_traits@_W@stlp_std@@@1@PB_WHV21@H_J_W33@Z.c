stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *__cdecl stlp_std::priv::__copy_integer_and_fill<wchar_t,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *result,
        wchar_t *__buf,
        int __len,
        __int64 __oi,
        __int16 __flg,
        stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > __wid,
        wchar_t __fill,
        wchar_t __xplus,
        wchar_t __xminus)
{
  int *p_wid; // eax
  int v11; // edi
  int v12; // eax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v13; // eax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v14; // eax
  stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *v15; // eax
  _DWORD v16[2]; // [esp+8h] [ebp-8h] BYREF

  if ( __len >= *(__int64 *)&__wid )
  {
    stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
      result,
      __buf,
      &__buf[__len],
      (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi);
    return result;
  }
  *(_QWORD *)&__wid -= __len;
  v16[0] = 0x7FFFFFFF;
  v16[1] = 0;
  if ( *(__int64 *)&__wid >= 0x7FFFFFFF )
    p_wid = v16;
  else
    p_wid = (int *)&__wid;
  v11 = *p_wid;
  v12 = __flg & 7;
  if ( v12 == 1 )
  {
    stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
      &__wid,
      __buf,
      &__buf[__len],
      (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi);
    __oi = (__int64)__wid;
    stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
      result,
      __wid,
      v11,
      &__fill);
    return result;
  }
  if ( v12 != 4 )
    goto LABEL_17;
  if ( __len && (*__buf == __xplus || *__buf == __xminus) )
  {
    stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator=(
      (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *)&__oi,
      *__buf);
    v13 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
            &__wid,
            (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi,
            v11,
            &__fill);
    __oi = *(__int64 *)v13;
    stlp_std::copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
      result,
      __buf + 1,
      &__buf[__len],
      *v13);
    return result;
  }
  if ( __len >= 2 && (__flg & 0x200) != 0 && (__flg & 0x38) == 0x10 )
  {
    stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator=(
      (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *)&__oi,
      *__buf);
    stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>::operator=(
      (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> > *)&__oi,
      __buf[1]);
    v14 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
            &__wid,
            (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi,
            v11,
            &__fill);
    __oi = *(__int64 *)v14;
    stlp_std::copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>>(
      result,
      __buf + 2,
      &__buf[__len],
      *v14);
    return result;
  }
  else
  {
LABEL_17:
    v15 = stlp_std::priv::__fill_n<stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int,wchar_t>(
            &__wid,
            (stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t> >)__oi,
            v11,
            &__fill);
    __oi = *(__int64 *)v15;
    stlp_std::priv::__copy<wchar_t const *,stlp_std::ostreambuf_iterator<wchar_t,stlp_std::char_traits<wchar_t>>,int>(
      result,
      __buf,
      &__buf[__len],
      *v15);
    return result;
  }
}
