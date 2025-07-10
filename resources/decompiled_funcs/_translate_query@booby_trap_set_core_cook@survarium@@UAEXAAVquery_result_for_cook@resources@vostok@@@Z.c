void __thiscall survarium::booby_trap_set_core_cook::translate_query(
        survarium::booby_trap_set_core_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::resources::query_result_for_cook *v3; // ecx
  vostok::variant<32> *v4; // eax
  survarium::game_camera *v5; // ecx
  const char *v6; // eax
  vostok::memory::base_allocator *v7; // [esp-10h] [ebp-1A0h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v9; // [esp+4h] [ebp-18Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_cook_data>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_cook_data> > > result; // [esp+38h] [ebp-158h] BYREF
  void (__userpurge *f)(survarium::booby_trap_set_core_cook *@<ecx>, unsigned int@<ebp>, int@<esi>, float@<xmm0>, vostok::resources::queries_result *, survarium::booby_trap_set_cook_data); // [esp+48h] [ebp-148h]
  int f_4; // [esp+4Ch] [ebp-144h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+50h] [ebp-140h] BYREF
  char v14; // [esp+73h] [ebp-11Dh]
  survarium::booby_trap_set_cook_data cook_data; // [esp+74h] [ebp-11Ch] BYREF
  vostok::fs_new::virtual_path_string config_name; // [esp+78h] [ebp-118h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&config_name);
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(&config_name, "resources/%s", requested_path);
  if ( vostok::resources::query_result_for_cook::user_data(v3, (int)parent) )
  {
    v4 = vostok::resources::query_result_for_cook::user_data(
           (vostok::resources::query_result_for_cook *)&cook_data,
           (int)parent);
    if ( !vostok::variant<32>::try_get<survarium::booby_trap_set_cook_data>(v4, &cook_data) )
    {
      v14 = 0;
      survarium::weapon_user_dead_state::finalize(v5);
      vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
      return;
    }
  }
  else
  {
    cook_data.is_local_player = 0;
    cook_data.stack_size = 1;
  }
  f = survarium::booby_trap_set_core_cook::on_config_ready;
  f_4 = 0;
  v9 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)boost::bind<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_cook_data,survarium::booby_trap_set_core_cook *,boost::arg<1>,survarium::booby_trap_set_cook_data>(&result, (void (__thiscall *__ptr64)(survarium::booby_trap_set_core_cook *, vostok::resources::queries_result *, survarium::booby_trap_set_cook_data))(unsigned int)survarium::booby_trap_set_core_cook::on_config_ready, this, 1_171, cook_data);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v9.l_.a1_.t_,
    &callback);
  if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_cook_data>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_cook_data>>>>'::`2'::stored_vtable,
         v9,
         &callback.functor) )
  {
    callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_set_core_cook,vostok::resources::queries_result &,survarium::booby_trap_set_cook_data>,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_set_core_cook *>,boost::arg<1>,boost::_bi::value<survarium::booby_trap_set_cook_data>>>>'::`2'::stored_vtable.base.manager
                                                             + 1);
  }
  else
  {
    callback.vtable = 0;
  }
  v7 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v6 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&config_name);
  vostok::resources::query_resource(
    v6,
    binary_config_class_impl,
    (boost::function4<void,unsigned int,float,float,char const *> *)&callback,
    v7,
    0,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
}
