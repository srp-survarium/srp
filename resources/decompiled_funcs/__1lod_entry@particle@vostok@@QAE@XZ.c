void __thiscall vostok::particle::lod_entry::~lod_entry(vostok::particle::lod_entry *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)this);
}
