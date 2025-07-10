void __thiscall vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data>::destroy(
        vostok::detail::concrete_type_helper<vostok::sound::sound_collection_cook_user_data> *this,
        vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *buffer)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(buffer + 1);
}
