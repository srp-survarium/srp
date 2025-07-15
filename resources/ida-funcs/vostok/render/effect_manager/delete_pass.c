void __userpurge vostok::render::effect_manager::delete_pass(
        vostok::render::effect_manager *this@<ecx>,
        int a2@<eax>,
        vostok::render::res_pass *pass)
{
  bool v3; // al
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // esi
  vostok::memory::doug_lea_allocator *v6; // ecx
  bool has_passed_filters; // al
  vostok::render::res_pass *v8; // [esp-4h] [ebp-34h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v9; // [esp-4h] [ebp-34h]
  const char *v10; // [esp+0h] [ebp-30h]
  const char *v11; // [esp+4h] [ebp-2Ch]
  unsigned int v12; // [esp+8h] [ebp-28h]
  char v13; // [esp+Ch] [ebp-24h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> v14; // [esp+10h] [ebp-20h] BYREF

  v13 = 0;
  if ( pass->m_registered )
  {
    v3 = vostok::render::reclaim<vostok::render::res_geometry,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>>(
           (vostok::render::set<vostok::render::res_pass *,vostok::render::effect_manager::compare_predicate<vostok::render::res_pass> > *)(a2 + 18196),
           pass);
    v4 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v8;
    if ( v3 )
    {
      v5 = vostok::render::g_allocator;
      vostok::render::res_pass::~res_pass(v8, (int)pass);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v5, (char *)pass, v10, v11, v12);
    }
    else
    {
      if ( !vostok::core::g_log_filter_tree
        || (has_passed_filters = vostok::logging::has_passed_filters(
                                   (vostok::logging::filter_tree *)&initiator_raw.initiator_tree,
                                   (const char *)2),
            v4 = v9,
            has_passed_filters) )
      {
        boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(
          v4,
          &v14);
        v13 = 1;
        vostok::logging::append(
          &v14,
          (void *const)vostok::core::g_log_flags,
          &vostok::core::g_log_format,
          ".\\effect_manager.cpp",
          0x59u,
          "void __thiscall vostok::render::effect_manager::delete_pass(const class vostok::render::res_pass *)",
          (char *)&initiator_raw.initiator_tree,
          error,
          "!ERROR: Failed to find compiled pass.");
      }
      if ( (v13 & 1) != 0 )
        boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
          (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)v4,
          (int *)&v14);
    }
  }
}
