void __usercall vostok::animation::mixing::animation_lexeme_parameters::~animation_lexeme_parameters(
        vostok::animation::mixing::animation_lexeme_parameters *this@<ecx>,
        int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v2; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *i; // edi

  v2 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 20);
  for ( i = &v2[3 * *(_DWORD *)(a2 + 40)]; v2 != i; v2 += 3 )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v2);
}
