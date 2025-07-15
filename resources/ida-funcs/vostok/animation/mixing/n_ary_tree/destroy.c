void __usercall vostok::animation::mixing::n_ary_tree::destroy(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        _DWORD *a2@<eax>)
{
  _DWORD *v3; // edi
  vostok::resources::pinned_ptr_const<unsigned char> *v4; // ecx
  _DWORD *v5; // edi
  _DWORD *v6; // ebx
  int v7; // ebx
  int v8; // edi
  void **v9; // [esp+8h] [ebp-4h] BYREF

  v3 = (_DWORD *)a2[1];
  if ( v3 )
  {
    v9 = &vostok::animation::mixing::n_ary_tree_destroyer::`vftable';
    do
    {
      (*(void (__thiscall **)(_DWORD *, void ***))(*v3 + 8))(v3, &v9);
      v3 = (_DWORD *)v3[10];
    }
    while ( v3 );
    a2[1] = 0;
    a2[2] = 0;
    v5 = (_DWORD *)a2[3];
    v6 = &v5[a2[10]];
    while ( v5 != v6 )
    {
      (*(void (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*v5 + 40))(*v5, 0);
      ++v5;
    }
    v7 = a2[4];
    v8 = v7 + 176 * a2[8];
    while ( v7 != v8 )
    {
      vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
        v4,
        v7 + 80);
      v7 += 176;
    }
  }
}
