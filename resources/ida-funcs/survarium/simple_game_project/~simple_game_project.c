void __usercall survarium::simple_game_project::~simple_game_project(
        survarium::simple_game_project *this@<ecx>,
        const char *a2@<edi>)
{
  survarium::simple_game_project *v2; // ebx
  bool v3; // zf
  survarium::render_visual *m_render_visuals; // eax
  char *v5; // esi
  vostok::memory::doug_lea_allocator *m_object; // ecx
  survarium::render_visual *v7; // edi
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base> > > *v8; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v9; // ecx
  survarium::vector<vostok::resources::request> *v10; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v11; // ecx
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v12; // ecx
  survarium::vector<vostok::resources::request> *v13; // ecx
  survarium::vector<vostok::resources::request> *v14; // ecx
  survarium::server_game_project *v15; // ecx
  const char *v17; // [esp+0h] [ebp-14h]
  unsigned int v18; // [esp+4h] [ebp-10h]
  vostok::memory::doug_lea_allocator *v19; // [esp+8h] [ebp-Ch]
  vostok::memory::doug_lea_allocator *v20; // [esp+Ch] [ebp-8h]
  survarium::render_visual *v21; // [esp+10h] [ebp-4h]

  v2 = this;
  v3 = this->m_render_visuals == 0;
  this->survarium::server_game_project::survarium::base_project::__vftable = (survarium::simple_game_project_vtbl *)&survarium::simple_game_project::`vftable'{for `survarium::base_project'};
  this->survarium::server_game_project::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (vostok::resources::unmanaged_resource_vtbl *)&survarium::simple_game_project::`vftable'{for `vostok::resources::unmanaged_resource'};
  if ( !v3 )
  {
    m_render_visuals = this->m_render_visuals;
    this = (survarium::simple_game_project *)survarium::g_allocator;
    v19 = survarium::g_allocator;
    if ( m_render_visuals )
    {
      v5 = (char *)&m_render_visuals[-1].matrix.lines[3].elements[3];
      m_object = (vostok::memory::doug_lea_allocator *)m_render_visuals[-1].model.m_object;
      v20 = m_object;
      v7 = (survarium::render_visual *)((char *)m_render_visuals
                                      + (_DWORD)m_object * LODWORD(m_render_visuals[-1].matrix.c.w));
      while ( 1 )
      {
        v21 = m_render_visuals;
        if ( m_render_visuals == v7 )
          break;
        vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_render_visuals->model);
        m_render_visuals = (survarium::render_visual *)((char *)v21 + (_DWORD)v20);
      }
      vostok::memory::doug_lea_allocator::free_impl(m_object, (int)v19, v5, a2, v17, v18);
    }
  }
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>(
    (stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *)this,
    (void **)&v2->m_game_effects._M_impl._M_start);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::generic_anomaly_core,vostok::resources::unmanaged_intrusive_base>>>(
    v8,
    (void **)&v2->m_anomalies._M_impl._M_start);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>(
    v9,
    (void **)&v2->m_ladders._M_impl._M_start);
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::~vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>(v10);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>(
    v11,
    (void **)&v2->m_effect_zones._M_impl._M_start);
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>(
    v12,
    (void **)&v2->m_damage_zones._M_impl._M_start);
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::~vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>(v13);
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>::~vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *>>(v14);
  survarium::server_game_project::~server_game_project(v15, (int)v2);
}
