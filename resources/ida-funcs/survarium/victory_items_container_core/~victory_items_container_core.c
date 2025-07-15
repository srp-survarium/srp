void __usercall survarium::victory_items_container_core::~victory_items_container_core(
        survarium::victory_items_container_core *this@<ecx>,
        int a2@<esi>)
{
  stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *>>::~_Vector_base<void *,vostok::vectora_allocator<void *>>(
    (stlp_std::priv::_Vector_base<void *,vostok::vectora_allocator<void *> > *)this,
    a2 + 336);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 72));
  survarium::usable_object::~usable_object((survarium::usable_object *)a2);
}
