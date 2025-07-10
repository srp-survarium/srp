void __usercall stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme>::~pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme>(
        stlp_std::pair<vostok::animation::mixing::expression,vostok::animation::mixing::animation_lexeme> *this@<ecx>,
        _DWORD *a2@<esi>)
{
  void (__thiscall ***v2)(_DWORD, _DWORD); // eax
  bool v3; // zf

  vostok::animation::mixing::animation_lexeme::~animation_lexeme(
    (vostok::animation::mixing::animation_lexeme *)this,
    (int)(a2 + 2));
  v2 = (void (__thiscall ***)(_DWORD, _DWORD))*a2;
  if ( *a2 )
  {
    v3 = v2[4] == (void (__thiscall **)(_DWORD, _DWORD))1;
    v2[4] = (void (__thiscall **)(_DWORD, _DWORD))((char *)v2[4] - 1);
    if ( v3 )
      (**(void (__thiscall ***)(_DWORD, _DWORD))*a2)(*a2, 0);
  }
}
