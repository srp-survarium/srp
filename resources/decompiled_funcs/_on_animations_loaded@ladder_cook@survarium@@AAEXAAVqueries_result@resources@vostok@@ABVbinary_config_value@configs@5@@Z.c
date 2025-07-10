void __thiscall survarium::ladder_cook::on_animations_loaded(
        survarium::ladder_cook *this,
        vostok::resources::queries_result *data,
        vostok::configs::binary_config_value *config)
{
  survarium::game_camera *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **v6; // eax
  const vostok::configs::binary_config_value *v7; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v8; // ecx
  const vostok::variant<32> **v9; // eax
  const vostok::math::float4x4 *v10; // eax
  survarium::game_camera *v11; // ecx
  const vostok::math::float3 *v12; // eax
  const vostok::math::float3 *v13; // esi
  survarium::game_camera *v14; // ecx
  const vostok::math::float3 *v15; // eax
  survarium::game_camera *v16; // ecx
  vostok::memory::doug_lea_allocator *v17; // eax
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *managed_resource; // eax
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v19; // eax
  survarium::ladder *v20; // eax
  const vostok::configs::binary_config_value *v21; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v22; // ecx
  const vostok::variant<32> **v23; // eax
  const vostok::configs::binary_config_value *v24; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v25; // ecx
  const vostok::variant<32> **v26; // eax
  const vostok::math::float4x4 *v27; // eax
  const vostok::math::float4x4 *v28; // eax
  survarium::game_camera *v29; // ecx
  vostok::memory::doug_lea_allocator *v30; // eax
  vostok::math::float4x4 *v31; // ecx
  survarium::game_camera *v32; // ecx
  survarium::flash_external_handler *v33; // eax
  survarium::flash_external_handler *v34; // edx
  survarium::flash_external_handler *v35; // eax
  survarium::flash_movie_resource **v36; // eax
  vostok::resources::resource_ptr<survarium::flash_movie_resource,vostok::resources::unmanaged_intrusive_base> *p_m_options_ui; // ecx
  const vostok::configs::binary_config_value *v38; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v39; // ecx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v40; // eax
  const vostok::configs::binary_config_value *v41; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v42; // ecx
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v43; // eax
  BOOL v44; // ecx
  bool has_passed_filters; // al
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v46; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v47; // [esp-Ch] [ebp-4E0h] BYREF
  const vostok::math::float4x4 *v48; // [esp-8h] [ebp-4DCh]
  unsigned int v49; // [esp-4h] [ebp-4D8h]
  vostok::math::float3 *v50; // [esp+0h] [ebp-4D4h]
  vostok::resources::query_result_for_user *v51; // [esp+8h] [ebp-4CCh]
  unsigned int v52; // [esp+Ch] [ebp-4C8h]
  vostok::resources::query_result_for_user *v53; // [esp+10h] [ebp-4C4h]
  unsigned int v54; // [esp+14h] [ebp-4C0h]
  survarium::landing_point *v55; // [esp+18h] [ebp-4BCh]
  survarium::ladder *v56; // [esp+1Ch] [ebp-4B8h]
  vostok::resources::query_result_for_user *v57; // [esp+20h] [ebp-4B4h]
  unsigned int index; // [esp+24h] [ebp-4B0h]
  survarium::ladder_cook *thisa; // [esp+28h] [ebp-4ACh]
  survarium::landing_point *v60; // [esp+34h] [ebp-4A0h]
  survarium::landing_point *v61; // [esp+38h] [ebp-49Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v62; // [esp+3Ch] [ebp-498h]
  survarium::landing_point *v63; // [esp+40h] [ebp-494h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *object; // [esp+44h] [ebp-490h]
  survarium::landing_point *v65; // [esp+48h] [ebp-48Ch]
  survarium::flash_movie_resource **angles_xyz; // [esp+50h] [ebp-484h]
  survarium::flash_external_handler *v67; // [esp+54h] [ebp-480h]
  void *v68; // [esp+58h] [ebp-47Ch]
  vostok::memory::doug_lea_allocator *v69; // [esp+5Ch] [ebp-478h]
  void *_Where; // [esp+104h] [ebp-3D0h]
  vostok::memory::doug_lea_allocator *v71; // [esp+108h] [ebp-3CCh]
  int v72; // [esp+274h] [ebp-260h]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+27Ch] [ebp-258h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v74; // [esp+2A0h] [ebp-234h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v75; // [esp+2A4h] [ebp-230h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v76; // [esp+2A8h] [ebp-22Ch] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v77; // [esp+2ACh] [ebp-228h] BYREF
  survarium::game_options *v78; // [esp+2BCh] [ebp-218h]
  vostok::math::float4x4 v79; // [esp+2C0h] [ebp-214h] BYREF
  vostok::math::float4x4 v80; // [esp+300h] [ebp-1D4h] BYREF
  vostok::math::float4x4 v81; // [esp+340h] [ebp-194h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v82; // [esp+380h] [ebp-154h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v83; // [esp+384h] [ebp-150h] BYREF
  survarium::ladder *v84; // [esp+388h] [ebp-14Ch]
  vostok::math::float4x4 v85; // [esp+38Ch] [ebp-148h] BYREF
  vostok::math::float4x4 result; // [esp+3CCh] [ebp-108h] BYREF
  char v87; // [esp+40Eh] [ebp-C6h]
  char v88; // [esp+40Fh] [ebp-C5h]
  const char *end_animation; // [esp+410h] [ebp-C4h]
  vostok::math::float4x4 v90; // [esp+414h] [ebp-C0h] BYREF
  const vostok::math::float4x4 *point_tansform; // [esp+454h] [ebp-80h]
  const char *start_animation; // [esp+458h] [ebp-7Ch]
  survarium::landing_point *new_point; // [esp+45Ch] [ebp-78h]
  const vostok::configs::binary_config_value *point; // [esp+460h] [ebp-74h]
  vostok::math::float4x4 v95; // [esp+464h] [ebp-70h] BYREF
  const vostok::configs::binary_config_value *it_point_end; // [esp+4A4h] [ebp-30h]
  const vostok::math::float4x4 *ladder_transform; // [esp+4A8h] [ebp-2Ch]
  const vostok::configs::binary_config_value *points; // [esp+4ACh] [ebp-28h]
  const vostok::math::plane *ladder_plane; // [esp+4B0h] [ebp-24h]
  unsigned int resource_index; // [esp+4B4h] [ebp-20h]
  vostok::resources::query_result_for_cook *parent; // [esp+4B8h] [ebp-1Ch]
  const vostok::configs::binary_config_value *it_point; // [esp+4BCh] [ebp-18h]
  vostok::math::plane v103; // [esp+4C0h] [ebp-14h] BYREF
  survarium::ladder *new_ladder; // [esp+4D0h] [ebp-4h]

  thisa = this;
  v72 = 0;
  parent = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)this, (int)data);
  v88 = 0;
  survarium::weapon_user_dead_state::finalize(v3);
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    resource_index = 0;
    v4 = vostok::configs::binary_config_value::operator[](config, "position");
    v6 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v5, (int)v4);
    v49 = (unsigned int)vostok::math::create_translation(&result, (const vostok::math::float3 *)v6);
    v7 = vostok::configs::binary_config_value::operator[](config, "rotation");
    v9 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v8, (int)v7);
    v10 = vostok::math::create_rotation(&v85, (const vostok::math::float3 *)v9);
    vostok::math::operator*(&v95, v10, (const vostok::math::float4x4 *)v49);
    ladder_transform = &v95;
    survarium::weapon_user_dead_state::finalize(v11);
    v13 = v12;
    survarium::weapon_user_dead_state::finalize(v14);
    vostok::math::create_plane_normalized(v15, v13, &v103);
    ladder_plane = &v103;
    survarium::weapon_user_dead_state::finalize(v16);
    v71 = v17;
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v17, 0x150u);
    v84 = (survarium::ladder *)operator new(0x150u, _Where);
    if ( v84 )
    {
      index = resource_index;
      v57 = vostok::resources::queries_result::operator[](data, resource_index++);
      v72 |= 3u;
      v49 = (unsigned int)ladder_plane;
      managed_resource = vostok::resources::query_result_for_user::get_managed_resource(v57, &v83);
      v19 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
              managed_resource,
              &v82);
      survarium::ladder::ladder(v84, v19, (const vostok::math::plane *)v49);
      v56 = v20;
    }
    else
    {
      v56 = 0;
    }
    new_ladder = v56;
    if ( (v72 & 2) != 0 )
    {
      v72 &= ~2u;
      vostok::animation::mixing::animation_interval::~animation_interval(&v82);
    }
    if ( (v72 & 1) != 0 )
    {
      v72 &= ~1u;
      vostok::animation::mixing::animation_interval::~animation_interval(&v83);
    }
    new_ladder->load(&new_ladder->survarium::usable_object, config);
    points = vostok::configs::binary_config_value::operator[](config, "landing_points");
    it_point = (const vostok::configs::binary_config_value *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)points);
    it_point_end = vostok::configs::binary_config_value::end((vostok::configs::binary_config_value *)points);
    while ( it_point != it_point_end )
    {
      point = it_point;
      v49 = (unsigned int)ladder_transform;
      v21 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)it_point,
              "position");
      v23 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v22, (int)v21);
      v48 = vostok::math::create_translation(&v81, (const vostok::math::float3 *)v23);
      v24 = vostok::configs::binary_config_value::operator[]((vostok::configs::binary_config_value *)point, "rotation");
      v26 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v25, (int)v24);
      v27 = vostok::math::create_rotation(&v80, (const vostok::math::float3 *)v26);
      v28 = vostok::math::operator*(&v79, v27, v48);
      vostok::math::operator*(&v90, v28, (const vostok::math::float4x4 *)v49);
      point_tansform = &v90;
      survarium::weapon_user_dead_state::finalize(v29);
      v69 = v30;
      v68 = vostok::memory::doug_lea_allocator::malloc_impl(v30, 0x24u);
      v78 = (survarium::game_options *)operator new(0x24u, v68);
      if ( v78 )
      {
        angles_xyz = (survarium::flash_movie_resource **)vostok::math::float4x4::get_angles_xyz(v31, v50);
        survarium::weapon_user_dead_state::finalize(v32);
        v67 = v33;
        survarium::weapon_core::cast_weapon_core(v78);
        v78->vostok::input::handler::__vftable = 0;
        v34 = v67;
        v35 = &v78->survarium::flash_external_handler;
        v78->survarium::flash_external_handler = *v67;
        v35[1].__vftable = v34[1].__vftable;
        v36 = angles_xyz;
        p_m_options_ui = &v78->m_options_ui;
        v78->m_options_ui.m_object = *angles_xyz;
        p_m_options_ui[1].m_object = v36[1];
        p_m_options_ui[2].m_object = v36[2];
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
          (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v78->m_options[1],
          0);
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
          (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)&v78->m_options[2],
          0);
        v55 = (survarium::landing_point *)v78;
      }
      else
      {
        v55 = 0;
      }
      new_point = v55;
      v38 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)point,
              "start_animation");
      start_animation = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                        v39,
                                        (int)v38);
      if ( !vostok::strings::equal(start_animation, (const char *)&buf) )
      {
        v54 = resource_index;
        v53 = vostok::resources::queries_result::operator[](data, resource_index++);
        v40 = vostok::resources::query_result_for_user::get_managed_resource(v53, &v77);
        object = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
                   v40,
                   &v76);
        v65 = new_point;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
          &new_point->m_start_animation,
          object);
        vostok::animation::mixing::animation_interval::~animation_interval(&v76);
        vostok::animation::mixing::animation_interval::~animation_interval(&v77);
      }
      v41 = vostok::configs::binary_config_value::operator[](
              (vostok::configs::binary_config_value *)point,
              "end_animation");
      end_animation = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                      v42,
                                      (int)v41);
      if ( !vostok::strings::equal(end_animation, (const char *)&buf) )
      {
        v52 = resource_index;
        v51 = vostok::resources::queries_result::operator[](data, resource_index++);
        v43 = vostok::resources::query_result_for_user::get_managed_resource(v51, &v75);
        v62 = vostok::static_cast_resource_ptr<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
                v43,
                &v74);
        v63 = new_point;
        vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator=(
          &new_point->m_end_animation,
          v62);
        vostok::animation::mixing::animation_interval::~animation_interval(&v74);
        vostok::animation::mixing::animation_interval::~animation_interval(&v75);
      }
      v61 = new_point;
      if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&new_point->m_start_animation) )
      {
        v60 = new_point;
        if ( !vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&new_point->m_end_animation) )
        {
          if ( !vostok::core::g_log_filter_tree
            || (has_passed_filters = vostok::logging::has_passed_filters(
                                       vostok::core::g_log_filter_tree,
                                       "game_core:",
                                       warning),
                v44 = has_passed_filters) )
          {
            boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>((boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *)v44);
            v72 |= 4u;
            vostok::logging::append(
              &log_callback,
              (void *const)vostok::core::g_log_flags,
              &vostok::core::g_log_format,
              ".\\ladder_cook.cpp",
              0x75u,
              "void __thiscall survarium::ladder_cook::on_animations_loaded(class vostok::resources::queries_result &,con"
              "st class vostok::configs::binary_config_value &)",
              "game_core:",
              warning,
              "landing point has no start/end animation, it's useless, hence won't be created");
          }
          v46 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v72 & 4);
          if ( (v72 & 4) != 0 )
          {
            v72 &= ~4u;
            boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
              v46,
              (int *)&log_callback);
          }
          __debugbreak();
        }
      }
      survarium::ladder::add_landing_point(new_ladder, (survarium::game_camera *)new_point);
      ++it_point;
    }
    v49 = 336;
    v48 = (const vostok::math::float4x4 *)&vostok::resources::nocache_memory;
    v47.m_object = (vostok::resources::unmanaged_resource *)it_point;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v47,
      (vostok::configs::binary_config *)new_ladder);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      parent,
      v47,
      (const vostok::resources::memory_type *)v48,
      v49);
    vostok::resources::query_result_for_cook::finish_query(parent, result_success, assert_on_fail_true);
  }
  else
  {
    v87 = 0;
    survarium::weapon_user_dead_state::finalize(0);
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
