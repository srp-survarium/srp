stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *__usercall stlp_std::basic_ostream<char,stlp_std::char_traits<char>>::flush@<eax>(
        stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *this@<ecx>,
        int a2@<esi>)
{
  int v2; // ecx

  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + a2 + 88);
  if ( v2 && (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 16))(v2) == -1 )
    stlp_std::basic_ios<char,stlp_std::char_traits<char>>::clear(
      (stlp_std::basic_ios<char,stlp_std::char_traits<char> > *)(a2 + *(_DWORD *)(*(_DWORD *)a2 + 4)),
      *(_DWORD *)(a2 + *(_DWORD *)(*(_DWORD *)a2 + 4) + 12) | 1);
  return (stlp_std::basic_ostream<char,stlp_std::char_traits<char> > *)a2;
}
