void __thiscall vostok::ai::behaviour_cook::load_behaviour_data(
        vostok::ai::behaviour_cook *this,
        vostok::resources::query_result_for_cook *const parent,
        vostok::configs::binary_config_value *behaviour_value,
        vostok::ai::behaviour *const new_behaviour)
{
  survarium::game_camera *m_animations_count; // ecx
  void *v5; // esp
  vostok::buffer_vector<vostok::resources::request> *v6; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v7; // ecx
  const vostok::variant<32> **v8; // eax
  vostok::buffer_vector<vostok::resources::request> *v9; // ecx
  unsigned int v10; // [esp-18h] [ebp-98h]
  vostok::memory::doug_lea_allocator *v11; // [esp-10h] [ebp-90h]
  unsigned int v12; // [esp+0h] [ebp-80h] BYREF
  vostok::ai::behaviour_cook *thisa; // [esp+4h] [ebp-7Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::ai::behaviour_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &,vostok::ai::behaviour *>,boost::_bi::list4<boost::_bi::value<vostok::ai::behaviour_cook *>,boost::arg<1>,boost::reference_wrapper<vostok::configs::binary_config_value const >,boost::_bi::value<vostok::ai::behaviour *> > > v14; // [esp+Ch] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::ai::behaviour_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &,vostok::ai::behaviour *>,boost::_bi::list4<boost::_bi::value<vostok::ai::behaviour_cook *>,boost::arg<1>,boost::reference_wrapper<vostok::configs::binary_config_value const >,boost::_bi::value<vostok::ai::behaviour *> > > result; // [esp+28h] [ebp-58h] BYREF
  void (__thiscall *__ptr64 f)(vostok::ai::behaviour_cook *, vostok::resources::queries_result *, const vostok::configs::binary_config_value *, vostok::ai::behaviour *); // [esp+44h] [ebp-3Ch]
  boost::reference_wrapper<vostok::configs::binary_config_value const > a3; // [esp+4Ch] [ebp-34h]
  boost::function1<void,vostok::resources::queries_result &> v18; // [esp+50h] [ebp-30h] BYREF
  vostok::buffer_vector<vostok::resources::request> requests; // [esp+74h] [ebp-Ch] BYREF
  unsigned int animations_count; // [esp+7Ch] [ebp-4h]

  thisa = this;
  m_animations_count = (survarium::game_camera *)new_behaviour->m_animations_count;
  animations_count = (unsigned int)m_animations_count;
  if ( m_animations_count )
  {
    v5 = alloca(8 * animations_count);
    v12 = (unsigned int)&v12;
    survarium::weapon_user_dead_state::finalize(m_animations_count);
    vostok::buffer_vector<vostok::resources::request>::buffer_vector<vostok::resources::request>(
      v6,
      (vostok::buffer_vector<vostok::resources::request> **)&requests,
      0,
      v12,
      (unsigned int)thisa);
    vostok::ai::behaviour_cook::get_requests_for_subresources(
      thisa,
      behaviour_value,
      &requests,
      resource_type_animation);
    if ( requests.m_begin != requests.m_end )
    {
      LODWORD(f) = vostok::ai::behaviour_cook::on_animations_loaded;
      HIDWORD(f) = 0;
      a3.t_ = (const vostok::configs::binary_config_value *)boost::addressof<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::vfs::async_callbacks_data,vostok::vfs::mount_result>,boost::_bi::list2<boost::_bi::value<vostok::vfs::async_callbacks_data *>,boost::arg<1>>>>((boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)behaviour_value);
      v14 = *boost::bind<void,vostok::ai::behaviour_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &,vostok::ai::behaviour *,vostok::ai::behaviour_cook *,boost::arg<1>,boost::reference_wrapper<vostok::configs::binary_config_value const>,vostok::ai::behaviour *>(
               &result,
               f,
               thisa,
               1_252,
               a3,
               new_behaviour);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v14.l_.a4_.t_,
        &v18);
      boost::function1<void,vostok::resources::queries_result &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf3<void,vostok::ai::behaviour_cook,vostok::resources::queries_result &,vostok::configs::binary_config_value const &,vostok::ai::behaviour *>,boost::_bi::list4<boost::_bi::value<vostok::ai::behaviour_cook *>,boost::arg<1>,boost::reference_wrapper<vostok::configs::binary_config_value const>,boost::_bi::value<vostok::ai::behaviour *>>>>(
        &v18,
        v14);
      v11 = vostok::ai::g_allocator;
      v10 = vostok::vectora<vostok::resources::request>::size((survarium::vector<vostok::resources::request> *)&requests);
      v8 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v7, (int)&requests);
      vostok::resources::query_resources(
        (const vostok::resources::request *)v8,
        v10,
        (boost::function4<void,unsigned int,float,float,char const *> *)&v18,
        v11,
        0,
        parent,
        assert_on_fail_true);
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v18);
      vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(v9, &requests);
      return;
    }
    vostok::buffer_vector<unsigned int>::~buffer_vector<unsigned int>(
      (vostok::buffer_vector<vostok::resources::request> *)requests.m_begin,
      &requests);
  }
  vostok::ai::behaviour_cook::load_sounds(thisa, parent, behaviour_value, new_behaviour);
}
