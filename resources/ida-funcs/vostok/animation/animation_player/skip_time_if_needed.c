void __userpurge vostok::animation::animation_player::skip_time_if_needed(
        unsigned int current_time_in_ms@<eax>,
        vostok::animation::animation_player *a2@<ecx>,
        const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *this)
{
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v3; // ebx
  unsigned int v5; // eax
  const vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *v6; // ebx
  unsigned int m_reference_count; // edi
  int *v8; // eax
  vostok::animation::mixing::n_ary_tree *v9; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v10; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v12; // [esp-4h] [ebp-48h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v13; // [esp+10h] [ebp-34h] BYREF
  unsigned int v14; // [esp+34h] [ebp-10h]
  vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> v15; // [esp+38h] [ebp-Ch] BYREF
  int v16; // [esp+3Ch] [ebp-8h]

  v16 = 0;
  v3 = this;
  if ( LOWORD(this[16437].m_object)
    || !vostok::animation::animation_player::are_there_any_animations(a2, this)
    || (v16 = 1,
        v5 = vostok::animation::tree(v3 + 16432, &v15)->m_object[11].m_reference_count + 10000,
        HIBYTE(this) = 1,
        v5 > current_time_in_ms) )
  {
    HIBYTE(this) = 0;
  }
  if ( (v16 & 1) != 0 )
  {
    v16 &= ~1u;
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v15);
  }
  if ( HIBYTE(this) )
  {
    v6 = v3 + 16432;
    m_reference_count = vostok::animation::tree(
                          v6,
                          (vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this)->m_object[11].m_reference_count;
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec((vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy> *)&this);
    v14 = current_time_in_ms - m_reference_count;
    v8 = (int *)vostok::animation::tree(v6, &v15);
    vostok::animation::mixing::n_ary_tree::add_offset(v9, *v8, current_time_in_ms - m_reference_count);
    vostok::intrusive_ptr<vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::animation::mixing::n_ary_tree_intrusive_base,vostok::threading::single_threading_policy>::dec(&v15);
    if ( !vostok::core::g_log_filter_tree
      || (has_passed_filters = vostok::logging::has_passed_filters(
                                 (vostok::logging::filter_tree *)"animation",
                                 (const char *)3),
          v10 = v12,
          has_passed_filters) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
        v10,
        &v13);
      v16 |= 2u;
      vostok::logging::append(
        &v13,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\animation_player.cpp",
        0x112u,
        "void __thiscall vostok::animation::animation_player::skip_time_if_needed(const unsigned int)",
        "animation",
        warning,
        "big time lag (%d.%03d) => skipping animation events",
        v14 / 0x3E8,
        v14 % 0x3E8);
    }
    if ( (v16 & 2) != 0 )
      boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
        (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v10,
        (int *)&v13);
  }
}
