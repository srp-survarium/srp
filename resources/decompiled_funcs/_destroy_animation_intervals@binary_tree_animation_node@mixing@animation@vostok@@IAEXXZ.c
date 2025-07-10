void __usercall vostok::animation::mixing::binary_tree_animation_node::destroy_animation_intervals(
        vostok::animation::mixing::binary_tree_animation_node *this@<ecx>,
        int a2@<eax>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *v2; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *i; // edi

  v2 = *(vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **)(a2 + 32);
  for ( i = &v2[3 * *(_DWORD *)(a2 + 72)]; v2 != i; v2 += 3 )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(v2);
}
