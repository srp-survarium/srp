void __thiscall survarium::animation_analysis_result_cook::translate_query(
        survarium::animation_analysis_result_cook *this,
        vostok::resources::query_result_for_cook *parent)
{
  vostok::resources::query_result_for_cook *v2; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v3; // ecx
  vostok::variant<32> *v4; // eax
  unsigned __int8 v5; // al
  survarium::game_camera *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // eax
  vostok::resources::unmanaged_resource *v8; // ecx
  vostok::configs::binary_config *v9; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v10; // [esp-Ch] [ebp-7Ch] BYREF
  const vostok::resources::memory_type *v11; // [esp-8h] [ebp-78h]
  unsigned int v12; // [esp-4h] [ebp-74h]
  survarium::animation_analysis_result *v13; // [esp+4h] [ebp-6Ch]
  survarium::animation_analysis_result_cook *thisa; // [esp+8h] [ebp-68h]
  void *_Where; // [esp+10h] [ebp-60h]
  vostok::memory::doug_lea_allocator *v16; // [esp+14h] [ebp-5Ch]
  int v17; // [esp+1Ch] [ebp-54h]
  survarium::animation_analysis_result *v18; // [esp+24h] [ebp-4Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+28h] [ebp-48h] BYREF
  survarium::animation_analysis_result *result; // [esp+4Ch] [ebp-24h]
  survarium::animation_analysis_result_cook_user_data ud; // [esp+50h] [ebp-20h] BYREF
  survarium::animation_analyzer analyzer; // [esp+60h] [ebp-10h] BYREF

  thisa = this;
  v17 = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&ud.animation);
  if ( vostok::resources::query_result_for_cook::user_data(v2, (int)parent)
    && (v4 = vostok::resources::query_result_for_cook::user_data(
               (vostok::resources::query_result_for_cook *)v3,
               (int)parent),
        v5 = vostok::variant<32>::try_get<survarium::animation_analysis_result_cook_user_data>(v4, &ud),
        (v3 = (boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v5) != 0) )
  {
    survarium::animation_analyzer::animation_analyzer(&analyzer, ud.legs, ud.legs_count, ud.skeleton);
    survarium::weapon_user_dead_state::finalize(v6);
    v16 = v7;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v7, 0x118u);
    v18 = (survarium::animation_analysis_result *)operator new(0x118u, _Where);
    if ( v18 )
    {
      survarium::animation_analysis_result::animation_analysis_result(v18, ud.legs_count);
      v13 = (survarium::animation_analysis_result *)v9;
    }
    else
    {
      v13 = 0;
    }
    result = v13;
    v12 = 280;
    v11 = &vostok::resources::nocache_memory;
    v10.m_object = v8;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v10,
      (vostok::configs::binary_config *)v13);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(parent, v10, v11, v12);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
    survarium::animation_analyzer::~animation_analyzer(&analyzer);
    vostok::animation::mixing::animation_interval::~animation_interval(&ud.animation);
  }
  else
  {
    if ( !vostok::core::g_log_filter_tree
      || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", error) )
    {
      boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v3);
      v17 |= 1u;
      vostok::logging::append(
        &log_callback,
        (void *const)vostok::core::g_log_flags,
        &vostok::core::g_log_format,
        ".\\animation_analysis_result_cook.cpp",
        0x1Bu,
        "void __thiscall survarium::animation_analysis_result_cook::translate_query(class vostok::resources::query_result_for_cook &)",
        "game_core:",
        error,
        "Failed to get user data for animation_analysis_result_cook");
    }
    if ( (v17 & 1) != 0 )
    {
      v17 &= ~1u;
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v3,
        (int *)&log_callback);
    }
    vostok::animation::mixing::animation_interval::~animation_interval(&ud.animation);
  }
}
