void __thiscall survarium::booby_trap_core_cook::translate_query(
        survarium::booby_trap_core_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::query_result_for_cook *v2; // ecx
  vostok::variant<32> *v3; // eax
  vostok::variant<32> *v4; // ecx
  unsigned __int8 v5; // al
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v6; // ecx
  const vostok::variant<32> **v7; // eax
  vostok::configs::binary_config *v8; // ecx
  vostok::configs::binary_config_value *root; // eax
  vostok::configs::binary_config_value *v10; // eax
  const vostok::configs::binary_config_value *v11; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v12; // ecx
  stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260> >,stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *v13; // ecx
  stlp_std::priv::_Rb_tree_node_base **v14; // eax
  vostok::configs::binary_config *v15; // ecx
  unsigned int DrawableImageFormat; // eax
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v17; // [esp-18h] [ebp-198h] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::booby_trap_core_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<survarium::booby_trap_core_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > v18; // [esp-14h] [ebp-194h] BYREF
  assert_on_fail_bool v19; // [esp-4h] [ebp-184h]
  vostok::network_core::packet_reader *v20; // [esp+0h] [ebp-180h]
  survarium::booby_trap_core_cook *thisa; // [esp+4h] [ebp-17Ch]
  void (__thiscall *__ptr64 f)(survarium::booby_trap_core_cook *, vostok::resources::queries_result *, vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>); // [esp+28h] [ebp-158h]
  boost::function<void __cdecl(vostok::resources::queries_result &)> callback; // [esp+38h] [ebp-148h] BYREF
  char v24; // [esp+5Eh] [ebp-122h]
  char v25; // [esp+5Fh] [ebp-121h]
  const char *model; // [esp+60h] [ebp-120h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config; // [esp+64h] [ebp-11Ch] BYREF
  vostok::resources::request requests[1]; // [esp+68h] [ebp-118h] BYREF
  vostok::fixed_string<260> aabb_path; // [esp+70h] [ebp-110h] BYREF

  thisa = this;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&config);
  v3 = vostok::resources::query_result_for_cook::user_data(v2, (int)parent);
  v5 = vostok::variant<32>::try_get<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
         v4,
         (const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *)v3,
         &config);
  if ( v5 )
  {
    v24 = 0;
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)v5);
    v7 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v6, (int)&config);
    root = (vostok::configs::binary_config_value *)vostok::configs::binary_config::get_root(v8, (int)v7);
    v10 = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](root, "data");
    v11 = vostok::configs::binary_config_value::operator[](v10, "model_armed");
    model = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                            v12,
                            (int)v11);
    vostok::fixed_string<260>::fixed_string<260>(&aabb_path);
    vostok::buffer_string::assignf(&aabb_path, "resources/models/%s.model/render/export_properties", model);
    v14 = stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::dictionary_item>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::dictionary_item>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::dictionary_item>>>::_S_right(
            v13,
            (int)&aabb_path);
    vostok::resources::memory_usage_type::memory_usage_type(
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)v14,
      (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> **)requests,
      (vostok::network_core::packet_reader *)0x22,
      v20);
    LODWORD(f) = survarium::booby_trap_core_cook::on_subresources_loaded;
    HIDWORD(f) = 0;
    v19 = assert_on_fail_false;
    v17.m_object = v15;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      &v17,
      &config);
    boost::bind<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>,vostok::ai::brain_unit_cook *,boost::arg<1>,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
      (boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::ai::brain_unit_cook,vostok::resources::queries_result &,vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list3<boost::_bi::value<vostok::ai::brain_unit_cook *>,boost::arg<1>,boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> > > > *)&v18,
      f,
      thisa,
      1_175,
      v17);
    boost::function<void __cdecl (vostok::resources::queries_result &)>::function<void __cdecl (vostok::resources::queries_result &)>(
      &callback,
      v18,
      v19);
    v19 = assert_on_fail_true;
    v18.l_.a3_.t_.m_object = (vostok::configs::binary_config *)parent;
    v18.l_.a1_.t_ = 0;
    HIDWORD(v18.f_.f_) = survarium::g_allocator.f_.f_;
    LODWORD(v18.f_.f_) = &callback;
    DrawableImageFormat = Scaleform::Render::TextureManager::GetDrawableImageFormat((btTriangleShape *)&callback);
    vostok::resources::query_resources(
      requests,
      DrawableImageFormat,
      (boost::function4<void,unsigned int,float,float,char const *> *)v18.f_.f_,
      (vostok::memory::base_allocator *)HIDWORD(v18.f_.f_),
      (const vostok::variant<32> **)v18.l_.a1_.t_,
      (vostok::resources::query_result_for_cook *)v18.l_.a3_.t_.m_object,
      v19);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&callback);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
  }
  else
  {
    v25 = 0;
    survarium::weapon_user_dead_state::finalize(0);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
    vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&config);
  }
}
