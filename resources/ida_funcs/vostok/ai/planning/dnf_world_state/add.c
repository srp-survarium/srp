void __thiscall vostok::ai::planning::dnf_world_state::add(
        vostok::ai::planning::dnf_world_state *this,
        const vostok::ai::planning::world_state_property *property,
        vostok::ai::planning::world_state_property *it_begin)
{
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  stlp_std::priv::__less_2<vostok::ai::planning::world_state_property,vostok::ai::planning::world_state_property> v5; // [esp+1Eh] [ebp-32h]
  stlp_std::priv::__less_2<vostok::ai::planning::world_state_property,vostok::ai::planning::world_state_property> v6; // [esp+1Fh] [ebp-31h]
  vostok::ai::planning::world_state_property *__last; // [esp+20h] [ebp-30h]
  char v8; // [esp+24h] [ebp-2Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-28h] BYREF
  vostok::ai::planning::world_state_property *iter; // [esp+4Ch] [ebp-4h]

  v8 = 0;
  __last = this->m_properties._M_impl._M_finish;
  v6 = (stlp_std::priv::__less_2<vostok::ai::planning::world_state_property,vostok::ai::planning::world_state_property>)stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  v5 = (stlp_std::priv::__less_2<vostok::ai::planning::world_state_property,vostok::ai::planning::world_state_property>)stlp_std::priv::__less2<unsigned int,vostok::ai::planning::operator_pair>();
  iter = stlp_std::priv::__lower_bound<vostok::ai::planning::world_state_property *,vostok::ai::planning::world_state_property,stlp_std::priv::__less_2<vostok::ai::planning::world_state_property,vostok::ai::planning::world_state_property>,stlp_std::priv::__less_2<vostok::ai::planning::world_state_property,vostok::ai::planning::world_state_property>,int>(
           it_begin,
           __last,
           property,
           v5,
           v6,
           0);
  if ( iter == this->m_properties._M_impl._M_finish
    || (v3 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)iter,
        iter->m_id != property->m_id) )
  {
    stlp_std::priv::_Impl_vector<vostok::ai::planning::world_state_property,vostok::ai::std_allocator<vostok::ai::planning::world_state_property>>::insert(
      &this->m_properties._M_impl,
      iter,
      property);
    this->m_hash ^= property->m_hash;
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "ai:", warning) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v3);
      v8 = 1;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        "C:\\survarium\\sources\\vostok/ai/search/dnf_world_state_inline.h",
        0x2Fu,
        "void __thiscall vostok::ai::planning::dnf_world_state::add(const class vostok::ai::planning::world_state_propert"
        "y &,class vostok::ai::planning::world_state_property *)",
        "ai:",
        warning,
        "you're trying to add the world state property which is already presented");
    }
    if ( (v8 & 1) != 0 )
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v3,
        (int *)&log_callback);
  }
}
