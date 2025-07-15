void __thiscall vostok::buffer_vector<vostok::apc::callback>::~buffer_vector<vostok::apc::callback>(
        vostok::buffer_vector<vostok::apc::callback> *this)
{
  vostok::apc::callback *m_begin; // eax
  int *v2; // esi

  m_begin = g_threads.m_begin;
  v2 = (int *)g_threads.m_begin;
  if ( g_threads.m_begin != g_threads.m_end )
  {
    do
    {
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
        v2);
      v2 += 12;
    }
    while ( v2 != (int *)g_threads.m_end );
    m_begin = g_threads.m_begin;
  }
  g_threads.m_end = m_begin;
}


void __usercall vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>::~buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct>(
        vostok::buffer_vector<vostok::render::effect_manager::effect_to_recompile_struct> *this@<ecx>,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // esi

  for ( i = *a2; i != a2[1]; i += 8 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i + 2);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::render::signature_layout_pair>::~buffer_vector<vostok::render::signature_layout_pair>(
        vostok::buffer_vector<vostok::render::signature_layout_pair> *this@<ecx>,
        int *a2@<edi>)
{
  int i; // esi

  for ( i = *a2; i != a2[1]; i += 8 )
  {
    vostok::intrusive_ptr<vostok::render::res_signature const,vostok::render::res_signature const,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_signature const ,vostok::render::res_signature const ,vostok::threading::single_threading_policy> *)(i + 4));
    vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::render::res_input_layout,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)i);
  }
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::animation::mixing::animation_interval>::~buffer_vector<vostok::animation::mixing::animation_interval>(
        vostok::buffer_vector<vostok::animation::mixing::animation_interval> *this@<ecx>,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *i; // esi

  for ( i = *a2; i != a2[1]; i += 5 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(i + 1);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>::~buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>>(
        vostok::buffer_vector<vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> > *this@<ecx>,
        int **a2@<edi>)
{
  int *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy>::dec(
      (vostok::physics::loose_ptr<vostok::physics::base_physics_object,vostok::physics::loose_ptr_data,vostok::threading::multi_threading_policy> *)this,
      i);
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>>(
        vostok::buffer_vector<vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base> > *this@<ecx>,
        vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **a2@<edi>)
{
  vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::intrusive_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base>>(
        vostok::buffer_vector<vostok::resources::resource_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base> > *this@<ecx>,
        vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **a2@<edi>)
{
  vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::intrusive_ptr<survarium::grenade_core,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>::~buffer_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>>(
        vostok::buffer_vector<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *this@<ecx>,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> **a2@<edi>)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *i; // esi

  for ( i = *a2; i != a2[1]; ++i )
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(i);
  a2[1] = *a2;
}


void __usercall vostok::buffer_vector<vostok::variant<32>>::~buffer_vector<vostok::variant<32>>(
        vostok::buffer_vector<vostok::variant<32> > *this@<ecx>,
        int *a2@<edi>)
{
  int i; // esi

  for ( i = *a2; i != a2[1]; i += 48 )
    vostok::variant<32>::destroy_previous_variable_if_needed((vostok::variant<32> *)this, i);
  a2[1] = *a2;
}
