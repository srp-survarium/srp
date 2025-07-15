void __usercall stlp_std::iter_swap<survarium::animations_registry::animations_tuple *,survarium::animations_registry::animations_tuple *>(
        survarium::animations_registry::animations_tuple *__i1@<eax>,
        survarium::animations_registry::animations_tuple *a2@<ecx>,
        survarium::animations_registry::animations_tuple *__i2)
{
  survarium::animations_registry::animations_tuple *v4; // ecx
  survarium::animations_registry::animations_tuple *v5; // ecx
  survarium::animations_registry::animations_tuple v6; // [esp+8h] [ebp-Ch] BYREF

  survarium::animations_registry::animations_tuple::animations_tuple(a2, &v6, (int)__i1);
  survarium::animations_registry::animations_tuple::operator=(v4, &__i1->first_view, __i2);
  survarium::animations_registry::animations_tuple::operator=(v5, &__i2->first_view, &v6);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v6.third_view);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v6.first_view);
}
