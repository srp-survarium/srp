void __usercall vostok::animation::mixing::binary_tree_expression_simplifier::~binary_tree_expression_simplifier(
        vostok::animation::mixing::binary_tree_expression_simplifier *this@<ecx>,
        int a2@<esi>)
{
  int v2; // eax
  bool v3; // zf
  int v4; // eax

  v2 = *(_DWORD *)(a2 + 12);
  if ( v2 )
  {
    v3 = (*(_DWORD *)(v2 + 16))-- == 1;
    if ( v3 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 12))(*(_DWORD *)(a2 + 12), 0);
  }
  v4 = *(_DWORD *)(a2 + 8);
  if ( v4 )
  {
    v3 = (*(_DWORD *)(v4 + 16))-- == 1;
    if ( v3 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 8))(*(_DWORD *)(a2 + 8), 0);
  }
}
