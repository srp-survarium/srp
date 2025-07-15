void __cdecl vostok::vfs::find_async_across_link(vostok::vfs::find_environment *env)
{
  unsigned int v1; // esi
  survarium::game_camera *v2; // ecx
  vostok::memory::base_allocator *v3; // eax
  const char *v4; // esi
  int v5; // eax
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> v6; // [esp-34h] [ebp-310h] BYREF
  vostok::vfs::find_enum find_flags; // [esp-14h] [ebp-2F0h]
  vostok::vfs::virtual_file_system *file_system; // [esp-10h] [ebp-2ECh]
  vostok::memory::base_allocator *v9; // [esp-Ch] [ebp-2E8h]
  unsigned int v10; // [esp-8h] [ebp-2E4h]
  unsigned int v11; // [esp-4h] [ebp-2E0h]
  vostok::vfs::async_link_helper *v12; // [esp+4h] [ebp-2D8h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > *v13; // [esp+8h] [ebp-2D4h]
  boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > > f; // [esp+Ch] [ebp-2D0h]
  boost::function<void __cdecl(vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum)> *v15; // [esp+14h] [ebp-2C8h]
  char *v16; // [esp+38h] [ebp-2A4h]
  vostok::memory::base_allocator *allocator; // [esp+44h] [ebp-298h]
  boost::detail::function::vtable_base *mount_operation_id; // [esp+48h] [ebp-294h]
  vostok::vfs::base_node<1> *node; // [esp+4Ch] [ebp-290h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > __that; // [esp+50h] [ebp-28Ch] BYREF
  boost::function1<void,enum vostok::handshaking_error_types_enum> *p_that; // [esp+70h] [ebp-26Ch]
  boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *m_flags; // [esp+74h] [ebp-268h]
  vostok::vfs::vfs_hashset *p_hashset; // [esp+78h] [ebp-264h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+190h] [ebp-14Ch] BYREF
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > *v25; // [esp+1A0h] [ebp-13Ch]
  vostok::vfs::vfs_locked_iterator v26; // [esp+1A4h] [ebp-138h] BYREF
  char *c_string; // [esp+1B8h] [ebp-124h]
  vostok::vfs::async_link_helper *helper; // [esp+1BCh] [ebp-120h]
  void *params_buffer; // [esp+1C0h] [ebp-11Ch]
  vostok::fs_new::virtual_path_string path_across_link; // [esp+1C4h] [ebp-118h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&path_across_link);
  vostok::vfs::find_link_target_path<1>(env->node, (vostok::fs_new::native_path_string *)&path_across_link);
  c_string = (char *)&env->path_to_find[vostok::strings::length(env->partial_path)];
  vostok::buffer_string::append(&path_across_link.m_string, c_string);
  v1 = vostok::fs_new::path_string_impl::length(&path_across_link) + 65;
  survarium::weapon_user_dead_state::finalize(v2);
  params_buffer = vostok::memory::malloc_helper<vostok::memory::base_allocator>(v3, v1);
  if ( params_buffer )
  {
    v25 = (boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > *)operator new(0x40u, params_buffer);
    if ( v25 )
    {
      p_hashset = &env->file_system->hashset;
      m_flags = (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)env->find_flags.m_flags;
      p_that = (boost::function1<void,enum vostok::handshaking_error_types_enum> *)&__that;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(m_flags, &__that);
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
        p_that,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&env->callback);
      allocator = env->allocator;
      mount_operation_id = (boost::detail::function::vtable_base *)env->mount_operation_id;
      node = env->node;
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        v25,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that);
      v25[1].t_.vtable = (boost::detail::function::vtable_base *)node;
      (&v25[1].t_.vtable)[1] = mount_operation_id;
      v25[1].t_.functor.obj_ptr = allocator;
      v25[1].t_.functor.vostok_pointer_size_alignment[3] = m_flags;
      v25[1].t_.functor.bound_memfunc_ptr.obj_ptr = p_hashset;
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&__that);
      v13 = v25;
      v12 = (vostok::vfs::async_link_helper *)v25;
    }
    else
    {
      v12 = 0;
    }
    helper = v12;
    v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&path_across_link);
    v5 = vostok::fs_new::path_string_impl::length(&path_across_link);
    vostok::strings::copy(helper->path_across_link, v5 + 1, v4);
    v11 = -1;
    v10 = 0;
    v9 = env->allocator;
    file_system = env->file_system;
    find_flags = helper->find_flags;
    v6.functor.vostok_pointer_size_alignment[5] = (void *)(unsigned __int8)2_7;
    v6.functor.bound_memfunc_ptr.obj_ptr = (void *)(unsigned __int8)1_29;
    f = (boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::jump_logic_state_landing,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::jump_logic_state_landing *>,boost::arg<1> > >)*boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>((boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result, (void (__thiscall *)(vostok::sound::sound_debug_stats *))vostok::vfs::async_link_helper::on_link_received, (vostok::sound::sound_debug_stats *)helper);
    v15 = &v6;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
      (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)f.f_.f_,
      &v6);
    if ( boost::detail::function::basic_vtable1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<enum vostok::animation::callback_return_type_enum,vostok::animation::animation_callback_params &> *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_link_helper,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_link_helper *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable,
           f,
           &v15->functor) )
    {
      v16 = (char *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_link_helper,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_link_helper *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
          + 1;
      v15->vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function2<void,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::vfs::async_link_helper,vostok::vfs::vfs_locked_iterator const &,enum vostok::vfs::result_enum>,boost::_bi::list3<boost::_bi::value<vostok::vfs::async_link_helper *>,boost::arg<1>,boost::arg<2>>>>'::`2'::stored_vtable.base.manager
                                                           + 1);
    }
    else
    {
      v15->vtable = 0;
    }
    vostok::vfs::try_find_async(helper->path_across_link, v6, find_flags, file_system, v9, v10, v11);
  }
  else
  {
    vostok::vfs::unlock_and_decref_branch(env->node, lock_type_read, env->mount_operation_id);
    vostok::vfs::vfs_iterator::vfs_iterator(&v26);
    v26.mount_operation_id = 0;
    boost::function2<void,vostok::ai::brain_unit const *,vostok::ai::animation_item const *>::operator()(
      (boost::function2<void,char const *,vostok::network_core::udp_match_packet const *> *)&env->callback,
      (const char *)&v26,
      (const vostok::network_core::udp_match_packet *)3);
    vostok::vfs::vfs_locked_iterator::~vfs_locked_iterator(&v26);
  }
}
