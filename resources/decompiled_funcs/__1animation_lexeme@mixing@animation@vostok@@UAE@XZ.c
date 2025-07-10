void __usercall vostok::animation::mixing::animation_lexeme::~animation_lexeme(
        vostok::animation::mixing::animation_lexeme *this@<ecx>,
        int a2@<eax>)
{
  bool v3; // zf
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v4; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *i; // ebx
  int v6; // eax
  int v7; // eax

  v3 = *(_BYTE *)(a2 + 124) == 0;
  *(_DWORD *)a2 = &vostok::animation::mixing::animation_lexeme::`vftable';
  if ( !v3 )
  {
    v4 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 32);
    for ( i = &v4[3 * *(_DWORD *)(a2 + 72)]; v4 != i; v4 += 3 )
      vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v4);
  }
  v6 = *(_DWORD *)(a2 + 128);
  if ( v6 )
  {
    v3 = (*(_DWORD *)(v6 + 16))-- == 1;
    if ( v3 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 128))(*(_DWORD *)(a2 + 128), 0);
  }
  v7 = *(_DWORD *)(a2 + 60);
  if ( v7 )
  {
    v3 = (*(_DWORD *)(v7 + 16))-- == 1;
    if ( v3 )
      (***(void (__thiscall ****)(_DWORD, _DWORD))(a2 + 60))(*(_DWORD *)(a2 + 60), 0);
  }
}
