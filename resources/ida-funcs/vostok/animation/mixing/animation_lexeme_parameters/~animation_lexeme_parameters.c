void __usercall vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(
        vostok::animation::mixing::animation_lexeme_parameters *this@<ecx>,
        int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v2; // edi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v3; // esi

  v2 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 20);
  v3 = &v2[5 * *(_DWORD *)(a2 + 40)];
  while ( v2 != v3 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v2 + 1);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(v2);
    v2 += 5;
  }
}
