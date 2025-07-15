void __usercall vostok::animation::mixing::animation_lexeme::~animation_lexeme(
        vostok::animation::mixing::animation_lexeme *this@<ecx>,
        int a2@<edi>)
{
  bool v2; // zf
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v3; // ebx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // esi
  int v5; // ecx

  v2 = *(_BYTE *)(a2 + 124) == 0;
  *(_DWORD *)a2 = &vostok::animation::mixing::animation_lexeme::`vftable';
  if ( !v2 )
  {
    v3 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 32);
    v4 = &v3[5 * *(_DWORD *)(a2 + 72)];
    while ( v3 != v4 )
    {
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v3 + 1);
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v3);
      v3 += 5;
    }
  }
  v5 = *(_DWORD *)(a2 + 128);
  if ( v5 )
  {
    v2 = (*(_DWORD *)(v5 + 16))-- == 1;
    if ( v2 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 128))(*(_DWORD *)(a2 + 128), 0);
  }
  vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::~intrusive_ptr<vostok::animation::mixing::binary_tree_base_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_animation_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy> *)(a2 + 60));
}
