void __thiscall vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base>(
        vostok::resources::resource_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base> *this,
        vostok::ai::sound_player *object)
{
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    this,
    object);
}
