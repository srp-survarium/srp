void __userpurge vostok::resources::unmanaged_cook::unmanaged_cook(
        vostok::resources::class_id_enum resource_class@<ecx>,
        DWORD creation_thread_id@<eax>,
        vostok::resources::unmanaged_cook *this,
        vostok::resources::cook_base::reuse_enum reuse_type,
        DWORD allocate_thread_id,
        vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> flags)
{
  vostok::resources::cook_base::cook_base(
    this,
    resource_class,
    creation_thread_id,
    reuse_type,
    flags,
    allocate_thread_id);
  this->__vftable = (vostok::resources::unmanaged_cook_vtbl *)&vostok::resources::unmanaged_cook::`vftable';
}
