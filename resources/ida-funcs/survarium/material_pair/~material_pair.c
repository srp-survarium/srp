void __thiscall survarium::material_pair::~material_pair(survarium::material_pair *this)
{
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_decal2);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_decal1);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&this->m_sound_emitter);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::vectora_allocator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>>(&this->m_particles._M_impl);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
