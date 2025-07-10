void __thiscall stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::_M_put_nowiden(
        stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *this,
        const char *__s)
{
  char *v2; // ecx
  bool v3; // [esp+0h] [ebp-D4h]
  bool v4; // [esp+18h] [ebp-BCh]
  __int64 v5; // [esp+3Ch] [ebp-98h]
  __int64 __n; // [esp+B4h] [ebp-20h]
  bool __failed; // [esp+C3h] [ebp-11h]

  if ( stlp_std::priv::__init_bostr<char,stlp_std::char_traits<char>>(this) )
  {
    __n = stlp_std::char_traits<char>::length(__s);
    if ( *(_QWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40] <= (__int64)(unsigned int)__n )
      v5 = 0;
    else
      v5 = *(_QWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 40] - __n;
    if ( v5 )
    {
      if ( (*(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 8] & 7) == 1 )
      {
        v4 = ((__int64 (__thiscall *)(_DWORD, const char *, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]
                                                                                      + 40))(
               *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88],
               __s,
               __n,
               HIDWORD(__n)) != __n
          || ((__int64 (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]
                                                                                + 44))(
               *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88],
               (unsigned __int8)this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 84],
               v5,
               HIDWORD(v5)) != v5;
        __failed = v4;
      }
      else
      {
        v3 = ((__int64 (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]
                                                                                + 44))(
               *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88],
               (unsigned __int8)this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 84],
               v5,
               HIDWORD(v5)) != v5
          || ((__int64 (__thiscall *)(_DWORD, const char *, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]
                                                                                      + 40))(
               *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88],
               __s,
               __n,
               HIDWORD(__n)) != __n;
        __failed = v3;
      }
    }
    else
    {
      __failed = ((__int64 (__thiscall *)(_DWORD, const char *, _DWORD, _DWORD))*(_DWORD *)(**(_DWORD **)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88]
                                                                                          + 40))(
                   *(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 88],
                   __s,
                   __n,
                   HIDWORD(__n)) != __n;
    }
    v2 = &this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)];
    *((_DWORD *)v2 + 10) = 0;
    *((_DWORD *)v2 + 11) = 0;
    if ( __failed )
      stlp_std::basic_ios<char,stlp_std::char_traits<char>>::setstate(
        (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4)],
        4);
  }
  if ( (*(_DWORD *)&this->gap0[*(_DWORD *)(*(_DWORD *)this->gap0 + 4) + 8] & 0x2000) != 0 )
    stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush(this);
}
