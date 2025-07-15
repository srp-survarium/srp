void __thiscall vostok::detail::concrete_type_helper<vostok::collision::animated_object_cook_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::collision::animated_object_cook_data> *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *buffer)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer + 1);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::animation::animation_collection_cook_user_data> *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *buffer)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer + 1);
}


void __thiscall vostok::detail::concrete_type_helper<survarium::grenade_cook_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *buffer)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer);
}


void __thiscall vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::render::static_model_instance_user_data> *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *buffer)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer + 2);
}
