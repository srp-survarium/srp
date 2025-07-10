void __thiscall vostok::ai::brain_unit::create_perceptors(
        vostok::ai::brain_unit *this,
        vostok::configs::binary_config_value *options)
{
  BOOL v2; // ecx
  bool has_passed_filters; // al
  int v5; // [esp+34h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-38h] BYREF
  vostok::ai::perceptors::perceptor_base *perceptor; // [esp+58h] [ebp-18h]
  const char *perceptor_type; // [esp+5Ch] [ebp-14h]
  const vostok::configs::binary_config_value *perceptor_type_value; // [esp+60h] [ebp-10h]
  const vostok::configs::binary_config_value *perceptors_value; // [esp+64h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+68h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+6Ch] [ebp-4h]

  v5 = 0;
  perceptors_value = vostok::configs::binary_config_value::operator[](options, "perceptors");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)perceptors_value);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)perceptors_value);
  while ( it != it_end )
  {
    perceptor_type_value = it;
    perceptor_type = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                     (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it,
                                     (int)it);
    perceptor = vostok::ai::create_perceptor_by_type(this->m_npc, perceptor_type, &this->m_working_memory, this);
    if ( perceptor )
    {
      vostok::intrusive_list<vostok::ai::sound_item_wrapper,vostok::ai::sound_item_wrapper *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_perceptors,
        (vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *)perceptor,
        0);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error),
            v2 = has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v2);
        v5 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\brain_unit_perceptors.cpp",
          0x38u,
          "void __thiscall vostok::ai::brain_unit::create_perceptors(const class vostok::configs::binary_config_value &)",
          "ai:",
          error,
          "Unknown perceptor type was declared - %s",
          perceptor_type);
      }
      if ( (v5 & 1) != 0 )
      {
        v5 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
          (int *)&log_callback);
      }
    }
    ++it;
  }
}
