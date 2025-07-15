void __usercall vostok::animation::mixing::addition_lexeme::~addition_lexeme(
        vostok::animation::mixing::addition_lexeme *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  bool v3; // zf
  int v4; // eax

  v2 = *(_DWORD *)(a2 + 24);
  if ( v2 )
  {
    v3 = (*(_DWORD *)(v2 + 16))-- == 1;
    if ( v3 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 24))(*(_DWORD *)(a2 + 24), 0);
  }
  v4 = *(_DWORD *)(a2 + 20);
  if ( v4 )
  {
    v3 = (*(_DWORD *)(v4 + 16))-- == 1;
    if ( v3 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 20))(*(_DWORD *)(a2 + 20), 0);
  }
}
