void __usercall survarium::server_game_project::~server_game_project(
        survarium::server_game_project *this@<ecx>,
        int a2@<esi>)
{
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *v2; // ecx

  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(a2 + 364));
  stlp_std::priv::_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>::~_Impl_vector<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::effect_zone,vostok::resources::unmanaged_intrusive_base>>>(v2);
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)(a2 + 48));
  survarium::base_project::~base_project((survarium::base_project *)a2);
}
