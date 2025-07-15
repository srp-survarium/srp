void __thiscall vostok::ai::brain_unit::create_selectors(
        vostok::ai::brain_unit *this,
        vostok::configs::binary_config_value *options)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v2; // ecx
  int v4; // [esp+34h] [ebp-3Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+38h] [ebp-38h] BYREF
  vostok::ai::selectors::target_selector_base *selector; // [esp+58h] [ebp-18h]
  const vostok::configs::binary_config_value *selector_type_value; // [esp+5Ch] [ebp-14h]
  const char *selector_type; // [esp+60h] [ebp-10h]
  const vostok::configs::binary_config_value *selectors_value; // [esp+64h] [ebp-Ch]
  const vostok::configs::binary_config_value *it_end; // [esp+68h] [ebp-8h]
  const vostok::configs::binary_config_value *it; // [esp+6Ch] [ebp-4h]

  v4 = 0;
  selectors_value = vostok::configs::binary_config_value::operator[](options, "target_selectors");
  it = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)selectors_value);
  it_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)selectors_value);
  while ( it != it_end )
  {
    selector_type_value = it;
    selector_type = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                    (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)it,
                                    (int)it);
    selector = vostok::ai::create_selector_by_type(
                 this->m_world,
                 selector_type,
                 &this->m_working_memory,
                 &this->m_blackboard,
                 this);
    if ( selector )
    {
      vostok::intrusive_list<vostok::ai::sound_item_wrapper,vostok::ai::sound_item_wrapper *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
        (vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)&this->m_target_selectors,
        (vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *>,vostok::ai::planning::intrusive_list_item<vostok::intrusive_list<vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *>,vostok::ai::planning::intrusive_list_item<vostok::ai::planning::base_filter *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *,4,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy> *> *)selector,
        0);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", error) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v2);
        v4 |= 1u;
        vostok::logging::append(
          &log_callback,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\brain_unit_selectors.cpp",
          0x51u,
          "void __thiscall vostok::ai::brain_unit::create_selectors(const class vostok::configs::binary_config_value &)",
          "ai:",
          error,
          "Unknown target selector type was declared - %s",
          selector_type);
      }
      if ( (v4 & 1) != 0 )
      {
        v4 &= ~1u;
        boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
          (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v2,
          (int *)&log_callback);
      }
    }
    ++it;
  }
}
