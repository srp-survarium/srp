void __thiscall survarium::game::load_cc_script(
        survarium::game *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> cfg,
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> create_renderer,
        char command_types_to_execute,
        unsigned int __formal)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v5; // ecx
  vostok::vfs::vfs_iterator::type_enum m_type; // eax
  int v7; // edi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v8; // ecx
  vostok::variant<32> *v9; // ecx
  vostok::const_buffer v10; // [esp-18h] [ebp-88h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > v11; // [esp-14h] [ebp-84h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp-4h] [ebp-74h] BYREF
  _DWORD v13[10]; // [esp+10h] [ebp-60h] BYREF
  _DWORD *v14; // [esp+38h] [ebp-38h]
  int v15; // [esp+3Ch] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::game *>,boost::arg<1> > > f; // [esp+40h] [ebp-30h] BYREF
  void (__thiscall *v17)(vostok::particle::particle_action *, vostok::mutable_buffer *); // [esp+50h] [ebp-20h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptr; // [esp+54h] [ebp-1Ch] BYREF
  vostok::resources::managed_resource *m_object; // [esp+58h] [ebp-18h]
  unsigned int v20; // [esp+5Ch] [ebp-14h]
  vostok::memory::reader v21; // [esp+64h] [ebp-Ch] BYREF

  if ( create_renderer.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v12.m_object = (vostok::resources::managed_resource *)this;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
      &v12,
      &create_renderer);
    vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
      v5,
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptr,
      v12);
    v21.m_data = (const unsigned __int8 *)m_object;
    v21.m_pointer = (const unsigned __int8 *)m_object;
    v21.m_size = v20;
    vostok::console_commands::load(&v21, execution_filter_general, __formal);
    vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>((vostok::resources::pinned_ptr_const<unsigned char> *)v12.m_object);
  }
  if ( command_types_to_execute )
  {
    m_type = cfg.m_object->m_fat_it.m_type;
    v14 = 0;
    v15 = 0;
    v7 = *(int *)((char *)&dword_200054 + m_type);
    vostok::variant<32>::destroy_previous_variable_if_needed((vostok::variant<32> *)this, (int)v13);
    v15 = vostok::detail::type_to_int<vostok::render::engine::world *>::get();
    v13[2] = v7;
    v14 = v13;
    m_object = cfg.m_object;
    v17 = survarium::empty_hands::tick;
    ptr.m_object = 0;
    HIDWORD(v11.f_.f_) = survarium::empty_hands::tick;
    *(_QWORD *)&v11.l_.a1_.t_ = __PAIR64__((unsigned int)cfg.m_object, 0);
    LODWORD(v11.f_.f_) = &f;
    v13[0] = &vostok::detail::concrete_type_helper<vostok::render::engine::world *>::`vftable';
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      0,
      v11,
      v20);
    v10.m_size = (unsigned int)survarium::g_allocator;
    v10.m_data = (const char *)103;
    vostok::resources::query_create_resource(
      "renderer",
      v10,
      (const char *)v13,
      0,
      (const vostok::variant<32> *)" ",
      (vostok::resources::query_result_for_cook *)1);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v8,
      (int *)&f);
    vostok::variant<32>::destroy_previous_variable_if_needed(v9, (int)v13);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&create_renderer);
}
