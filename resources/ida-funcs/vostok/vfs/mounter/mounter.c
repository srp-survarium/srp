void __thiscall vostok::vfs::mounter::mounter(
        vostok::vfs::mounter *this,
        vostok::vfs::query_mount_arguments *args,
        vostok::vfs::virtual_file_system *file_system)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->__vftable = (vostok::vfs::mounter_vtbl *)&vostok::vfs::mounter::`vftable';
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->m_referers,
    &this->m_referers.m_size);
  vostok::threading::mutex::mutex(&this->m_referers.vostok::threading::mutex);
  this->m_referers.m_first = 0;
  this->m_referers.m_last = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_mount_ptr);
  this->m_result = result_error;
  vostok::vfs::query_mount_arguments::query_mount_arguments(&this->m_args, args);
  this->m_mount_root_base = 0;
  this->m_file_system = file_system;
  this->m_mount_id = 0;
  vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy>::push_back(
    (vostok::intrusive_double_linked_list<vostok::vfs::mounter_base,vostok::vfs::mounter *,0,4,vostok::threading::mutex,vostok::no_size_policy,vostok::debug_policy> *)((char *)&loc_2011E + (unsigned int)this->m_file_system + 2),
    this,
    0);
}
