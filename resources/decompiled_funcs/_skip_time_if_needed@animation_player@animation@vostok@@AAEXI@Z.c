void __userpurge vostok::animation::animation_player::skip_time_if_needed(
        vostok::animation::animation_player *this@<ecx>,
        vostok::animation::animation_player *a2@<edi>,
        unsigned int current_time_in_ms)
{
  unsigned int m_tree_actual_time_in_ms; // eax
  unsigned int v5; // esi
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v6; // ecx
  void (__cdecl *v7)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // eax
  void *v8; // esp
  vostok::animation::mixing::n_ary_tree *v9; // ecx
  _DWORD v10[2]; // [esp-4000h] [ebp-402Ch] BYREF
  _DWORD *v11; // [esp-3FF8h] [ebp-4024h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+8h] [ebp-24h] BYREF
  char current_time_in_msa; // [esp+34h] [ebp+8h]
  void (__cdecl *current_time_in_msb)(void *, const char *, unsigned int, const char *, const char *, vostok::logging::verbosity, const char *, unsigned int, vostok::logging::callback_flag); // [esp+34h] [ebp+8h]

  current_time_in_msa = 0;
  if ( !a2->m_in_tick )
  {
    if ( a2->m_mixing_tree.m_animations_count )
    {
      m_tree_actual_time_in_ms = a2->m_mixing_tree.m_tree_actual_time_in_ms;
      if ( m_tree_actual_time_in_ms + 10000 <= current_time_in_ms )
      {
        v5 = current_time_in_ms - m_tree_actual_time_in_ms;
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "animation:", warning) )
        {
          v7 = vostok::core::g_log_callback;
          current_time_in_msb = vostok::core::g_log_callback;
          log_callback.vtable = 0;
          if ( `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager )
          {
            `boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager(
              &log_callback.functor,
              &log_callback.functor,
              destroy_functor_tag);
            v7 = current_time_in_msb;
          }
          if ( v7 )
          {
            log_callback.functor.obj_ptr = v7;
            log_callback.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag>::assign_to<void (__cdecl *)(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>'::`2'::stored_vtable.base.manager
                                                                         + 1);
          }
          else
          {
            log_callback.vtable = 0;
          }
          current_time_in_msa = 1;
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\animation_player.cpp",
            0x14Bu,
            "void __thiscall vostok::animation::animation_player::skip_time_if_needed(const unsigned int)",
            "animation:",
            warning,
            "big time lag (%d.%03d) => skipping animation events",
            v5 / 0x3E8,
            v5 % 0x3E8);
        }
        if ( (current_time_in_msa & 1) != 0 )
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v6,
            (int *)&log_callback);
        v8 = alloca(0x4000);
        vostok::animation::animation_player::serialize_state((char *)v10, 0x4000u, a2);
        vostok::animation::animation_player::deserialize_state(a2, (char *)v10, current_time_in_ms);
        v10[0] = -4334115;
        vostok::animation::mixing::n_ary_tree::destroy(v9);
        if ( v11 )
          --*v11;
      }
    }
  }
}
