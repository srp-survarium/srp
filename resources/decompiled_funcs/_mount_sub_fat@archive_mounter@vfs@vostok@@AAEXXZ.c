void __thiscall vostok::vfs::archive_mounter::mount_sub_fat(vostok::vfs::archive_mounter *this)
{
  survarium::game_camera *v1; // ecx
  survarium::game_camera *v2; // ecx
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  vostok::memory::base_allocator *v5; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v7; // ecx
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > __that; // [esp+8h] [ebp-114h] BYREF
  boost::function1<void,bool> v10; // [esp+28h] [ebp-F4h] BYREF
  boost::function1<void,bool> *p_callback; // [esp+48h] [ebp-D4h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v12; // [esp+4Ch] [ebp-D0h]
  boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > *p_that; // [esp+5Ch] [ebp-C0h]
  char *v14; // [esp+60h] [ebp-BCh]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > v15; // [esp+64h] [ebp-B8h]
  boost::function1<void,bool> *v16; // [esp+74h] [ebp-A8h]
  char v17; // [esp+7Bh] [ebp-A1h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > v18; // [esp+7Ch] [ebp-A0h] BYREF
  void (__thiscall *__ptr64 v19)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *); // [esp+90h] [ebp-8Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1> > > result; // [esp+9Ch] [ebp-80h] BYREF
  void (__thiscall *f)(vostok::vfs::archive_mounter *, bool); // [esp+B0h] [ebp-6Ch]
  int f_4; // [esp+B4h] [ebp-68h]
  char v23; // [esp+BFh] [ebp-5Dh]
  char v24; // [esp+C0h] [ebp-5Ch]
  char v25; // [esp+C1h] [ebp-5Bh]
  char v26; // [esp+C2h] [ebp-5Ah]
  bool read_result; // [esp+C3h] [ebp-59h]
  vostok::fs_new::query_custom_operation_args args; // [esp+C4h] [ebp-58h] BYREF
  unsigned int sub_fat_size; // [esp+118h] [ebp-4h]

  v26 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  v25 = 0;
  survarium::weapon_user_dead_state::finalize(v1);
  v24 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  sub_fat_size = vostok::vfs::get_file_size<1>(this->m_args.submount_node);
  v23 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  survarium::weapon_user_dead_state::finalize(v4);
  this->m_nodes_buffer = (char *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(v5, sub_fat_size);
  if ( this->m_nodes_buffer )
  {
    if ( this->m_args.asynchronous_device )
    {
      f = vostok::vfs::archive_mounter::on_read_sub_fat;
      f_4 = 0;
      LODWORD(v19) = vostok::vfs::archive_mounter::read_sub_fat;
      HIDWORD(v19) = 0;
      v15 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&result, (void (__thiscall *__ptr64)(vostok::sound::sound_environment_cook *, vostok::resources::queries_result *))(unsigned int)vostok::vfs::archive_mounter::on_read_sub_fat, (survarium::weapon_core_animation_end_aware_state *)this);
      v16 = &v10;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v15.l_.a1_.t_,
        &v10);
      boost::function1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::archive_mounter,bool>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1>>>>(
        v16,
        v15);
      v12 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)boost::bind<void,vostok::sound::ogg_sound_cook,vostok::resources::queries_result &,vostok::sound::ogg_sound_cook *,boost::arg<1>>((boost::_bi::bind_t<enum vostok::animation::callback_return_type_enum,boost::_mfi::mf1<enum vostok::animation::callback_return_type_enum,survarium::weapon_core_animation_end_aware_state,vostok::animation::animation_callback_params &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_animation_end_aware_state *>,boost::arg<1> > > *)&v18, v19, (survarium::weapon_core_animation_end_aware_state *)this);
      p_that = &__that;
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v12.l_.a1_.t_,
        &__that);
      if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
             (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf1<bool,vostok::vfs::archive_mounter,vostok::fs_new::synchronous_device_interface &>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1>>>>'::`2'::stored_vtable,
             v12,
             &p_that->t_.functor) )
      {
        v14 = (char *)&`boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf1<bool,vostok::vfs::archive_mounter,vostok::fs_new::synchronous_device_interface &>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
            + 1;
        p_that->t_.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<bool,vostok::fs_new::synchronous_device_interface &>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf1<bool,vostok::vfs::archive_mounter,vostok::fs_new::synchronous_device_interface &>,boost::_bi::list2<boost::_bi::value<vostok::vfs::archive_mounter *>,boost::arg<1>>>>'::`2'::stored_vtable.base.manager
                                                                   + 1);
      }
      else
      {
        p_that->t_.vtable = 0;
      }
      boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>(
        (boost::_bi::value<boost::function<void __cdecl(enum vostok::handshaking_error_types_enum)> > *)&args,
        (vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&__that);
      args.result = 0;
      p_callback = &args.callback;
      boost::function1<void,bool>::function1<void,bool>(&args.callback, &v10);
      args.event_to_fire_after_execute = 0;
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&__that);
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v6,
        (int *)&v10);
      if ( !vostok::fs_new::asynchronous_device_interface::query_custom_operation(
              this->m_args.asynchronous_device,
              &args,
              this->m_args.allocator) )
        vostok::vfs::mounter::finish_with_out_of_memory(this);
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v7,
        (int *)&args.callback);
      boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&args);
    }
    else
    {
      v17 = 0;
      survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
      read_result = vostok::vfs::archive_mounter::read_sub_fat(this, this->m_args.synchronous_device);
      vostok::vfs::archive_mounter::on_read_sub_fat(this, read_result);
    }
  }
  else
  {
    vostok::vfs::mounter::finish_with_out_of_memory(this);
  }
}
