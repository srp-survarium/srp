void __thiscall survarium::items_cook::translate_query(
        survarium::items_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  const char *requested_path; // eax
  vostok::resources::query_result_for_cook *v3; // ecx
  const char *v4; // eax
  vostok::memory::base_allocator *v5; // [esp-10h] [ebp-188h]
  vostok::variant<32> *v6; // [esp-Ch] [ebp-184h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::items_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::items_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > v8; // [esp+4h] [ebp-174h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::inventory_cook,vostok::resources::queries_result &,survarium::inventory_cooker_data *>,boost::_bi::list3<boost::_bi::value<survarium::inventory_cook *>,boost::arg<1>,boost::_bi::value<survarium::inventory_cooker_data *> > > result; // [esp+28h] [ebp-150h] BYREF
  void (__userpurge *f)(survarium::items_cook *@<ecx>, float@<xmm0>, vostok::resources::queries_result *, vostok::resources::query_result_for_cook *); // [esp+38h] [ebp-140h]
  int f_4; // [esp+3Ch] [ebp-13Ch]
  boost::function1<void,vostok::resources::queries_result &> v12; // [esp+40h] [ebp-138h] BYREF
  vostok::fs_new::virtual_path_string config_name; // [esp+60h] [ebp-118h] BYREF

  vostok::fs_new::virtual_path_string::virtual_path_string(&config_name);
  requested_path = vostok::resources::query_result_for_user::get_requested_path(parent);
  vostok::fs_new::path_string_impl::assignf(&config_name, "resources/%s", requested_path);
  f = survarium::items_cook::on_config_ready;
  f_4 = 0;
  v8 = *boost::bind<void,survarium::inventory_cook,vostok::resources::queries_result &,survarium::inventory_cooker_data *,survarium::inventory_cook *,boost::arg<1>,survarium::inventory_cooker_data *>(
          (boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::items_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::items_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *> > > *)&result,
          (void (__thiscall *__ptr64)(survarium::inventory_cook *, vostok::resources::queries_result *, survarium::inventory_cooker_data *))(unsigned int)survarium::items_cook::on_config_ready,
          (survarium::inventory_cook *)this,
          1_213,
          (survarium::inventory_cooker_data *)parent);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v8.l_.a1_.t_,
    &v12);
  boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::items_cook,vostok::resources::queries_result &,vostok::resources::query_result_for_cook *>,boost::_bi::list3<boost::_bi::value<survarium::items_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::query_result_for_cook *>>>>(
    &v12,
    v8);
  v6 = vostok::resources::query_result_for_cook::user_data(v3, (int)parent);
  v5 = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v4 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&config_name);
  vostok::resources::query_resource(
    v4,
    binary_config_class_impl,
    (boost::function4<void,unsigned int,float,float,char const *> *)&v12,
    v5,
    v6,
    parent,
    assert_on_fail_true);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v12);
}
