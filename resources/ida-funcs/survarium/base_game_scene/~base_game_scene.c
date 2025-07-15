void __thiscall survarium::base_game_scene::~base_game_scene(survarium::base_game_scene *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v3; // eax
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // [esp-4h] [ebp-10h]
  const char *v6; // [esp+0h] [ebp-Ch]
  const char *v7; // [esp+4h] [ebp-8h]
  unsigned int v8; // [esp+8h] [ebp-4h]

  v1 = survarium::g_allocator;
  this->__vftable = (survarium::base_game_scene_vtbl *)&survarium::base_game_scene::`vftable';
  if ( this->m_camera_director )
  {
    v3 = __RTCastToVoid((void **)&this->m_camera_director->__vftable);
    vostok::memory::doug_lea_allocator::free_impl(v5, (int)v1, v3, v6, v7, v8);
    this->m_camera_director = 0;
  }
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::~_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>(
    (stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record> > *)this,
    (stlp_std::reverse_iterator<survarium::scheduler::record *> *)&this->m_scheduler.m_active_objects);
  stlp_std::priv::_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>::~_Impl_vector<survarium::scheduler::record,vostok::vectora_allocator<survarium::scheduler::record>>(
    v4,
    (stlp_std::reverse_iterator<survarium::scheduler::record *> *)&this->m_scheduler);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sound_scene);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene_view);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_render_scene);
}
