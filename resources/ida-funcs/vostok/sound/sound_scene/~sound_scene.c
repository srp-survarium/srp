void __thiscall vostok::sound::sound_scene::~sound_scene(vostok::sound::sound_scene *this)
{
  vostok::resources::resource_ptr<vostok::render::culling::portal_sector_structure,vostok::resources::unmanaged_intrusive_base> *p_m_graph; // ebx
  vostok::particle::particle_system_instance_impl *m_object; // eax
  vostok::collision::space_partitioning_tree *m_spatial_tree; // ecx
  vostok::threading::mutex *v5; // ecx
  stlp_std::pair<vostok::fixed_string<64>,XAUDIO2FX_REVERB_I3DL2_PARAMETERS *> *M_start; // edx
  vostok::particle::particle_system_instance_impl *v7; // [esp-4h] [ebp-14h]
  const char *v8; // [esp+0h] [ebp-10h]
  const char *v9; // [esp+4h] [ebp-Ch]
  unsigned int v10; // [esp+8h] [ebp-8h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v11; // [esp+Ch] [ebp-4h] BYREF

  this->__vftable = (vostok::sound::sound_scene_vtbl *)&vostok::sound::sound_scene::`vftable';
  p_m_graph = &this->m_graph;
  m_object = (vostok::particle::particle_system_instance_impl *)this->m_graph.m_object;
  this->m_graph.m_object = 0;
  v11.m_object = m_object;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v11);
  m_spatial_tree = this->m_spatial_tree;
  if ( m_spatial_tree )
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))m_spatial_tree->~vostok::collision::space_partitioning_tree)(
      m_spatial_tree,
      0);
  if ( this->m_spatial_tree )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      (vostok::memory::doug_lea_allocator *)m_spatial_tree,
      (int)vostok::sound::g_allocator,
      this->m_spatial_tree,
      v8,
      v9,
      v10);
    this->m_spatial_tree = 0;
  }
  if ( this->m_receivers.m_first )
  {
    vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::for_each<vostok::sound::receiver_unconditional_erasing_predicate>(
      (vostok::intrusive_list<vostok::sound::receiver_collision,vostok::sound::receiver_collision *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)m_spatial_tree,
      (int)&this->m_receivers,
      (const char *)p_m_graph,
      (const char *)this);
    if ( this == (vostok::sound::sound_scene *)-616 )
      v11.m_object = 0;
    else
      v11.m_object = (vostok::particle::particle_system_instance_impl *)&this->m_receivers.vostok::threading::mutex;
    vostok::threading::mutex::lock(v5, (_RTL_CRITICAL_SECTION *)v11.m_object);
    v7 = v11.m_object;
    this->m_receivers.m_first = 0;
    this->m_receivers.m_last = 0;
    this->m_receivers.m_size = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)v7);
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_active_voices.vostok::threading::mutex);
  DeleteCriticalSection((LPCRITICAL_SECTION)&this->m_receivers.vostok::threading::mutex);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_graph);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_memory_arena_resources_ptr);
  M_start = this->m_environment_parameters._M_impl._M_start;
  if ( M_start )
    this->m_environment_parameters._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_environment_parameters._M_impl._M_end_of_storage.m_allocator,
      M_start,
      "vostok::detail::std_allocator<struct stlp_std::pair<class vostok::fixed_string<64>,struct XAUDIO2FX_REVERB_I3DL2_P"
      "ARAMETERS *> >::deallocate",
      "c:\\survarium.deploy\\sources\\vostok/std_allocator_inline.h",
      102u);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
