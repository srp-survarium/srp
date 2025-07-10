void __thiscall survarium::game_material_manager_cook::on_decals_loaded(
        survarium::game_material_manager_cook *this,
        vostok::resources::queries_result *data,
        survarium::vector<survarium::game_material_manager_cook::query_ext_data> *ext_data)
{
  unsigned int v3; // eax
  vostok::resources::query_result *v4; // eax
  vostok::resources::query_result_for_user *v5; // ecx
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> *v6; // ecx
  vostok::resources::query_result *v7; // eax
  vostok::resources::resource_base *v8; // ecx
  vostok::fs_new::virtual_path_string *v9; // eax
  const char *v10; // eax
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v11; // ecx
  vostok::resources::query_result *v12; // eax
  vostok::resources::query_result_for_user *v13; // ecx
  vostok::render::material_effects_instance_cook_data **v14; // esi
  survarium::game_camera *v15; // ecx
  vostok::memory::doug_lea_allocator *v16; // eax
  vostok::resources::query_result *v17; // eax
  vostok::resources::query_result_for_user *v18; // ecx
  vostok::render::material_effects_instance_cook_data **p_cd; // esi
  survarium::game_camera *v20; // ecx
  vostok::memory::doug_lea_allocator *v21; // eax
  vostok::resources::query_result *v22; // eax
  vostok::resources::query_result_for_user *v23; // ecx
  vostok::resources::query_result *v24; // eax
  vostok::resources::query_result_for_user *v25; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v27; // [esp-4h] [ebp-1A4h] BYREF
  survarium::game_material_manager_cook *thisa; // [esp+8h] [ebp-198h]
  survarium::material_pair *v29; // [esp+Ch] [ebp-194h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v30; // [esp+10h] [ebp-190h] BYREF
  survarium::material_pair *pair; // [esp+24h] [ebp-17Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v32; // [esp+28h] [ebp-178h] BYREF
  survarium::material_pair *v33; // [esp+34h] [ebp-16Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> object; // [esp+38h] [ebp-168h] BYREF
  survarium::game_material_manager_cook::query_ext_data *M_finish; // [esp+3Ch] [ebp-164h]
  survarium::game_material_manager_cook::query_ext_data *M_start; // [esp+40h] [ebp-160h]
  int v37; // [esp+44h] [ebp-15Ch]
  boost::function<void __cdecl(void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)> log_callback; // [esp+58h] [ebp-148h] BYREF
  vostok::fs_new::virtual_path_string result; // [esp+7Ch] [ebp-124h] BYREF
  unsigned int idx; // [esp+190h] [ebp-10h]
  unsigned int i; // [esp+194h] [ebp-Ch]
  survarium::game_material_manager_cook::query_ext_data *end; // [esp+198h] [ebp-8h]
  survarium::game_material_manager_cook::query_ext_data *it; // [esp+19Ch] [ebp-4h]

  thisa = this;
  v37 = 0;
  if ( !vostok::resources::queries_result::is_successful(data) )
  {
    for ( i = 0; ; ++i )
    {
      v3 = vostok::resources::queries_result::size(data);
      if ( i >= v3 )
        break;
      v4 = vostok::resources::queries_result::operator[](data, i);
      if ( !vostok::resources::query_result_for_user::is_successful(v5, (int)v4) )
      {
        if ( !vostok::core::g_log_filter_tree
          || vostok::logging::has_passed_filters(vostok::core::g_log_filter_tree, "game_core:", error) )
        {
          boost::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>::function<void __cdecl (void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag)>(v6);
          v37 |= 1u;
          v7 = vostok::resources::queries_result::operator[](data, i);
          v9 = vostok::resources::resource_base::reusable_request_name(v8, v7, &result);
          v10 = (const char *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr((vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v9);
          vostok::logging::append(
            &log_callback,
            (void *const)vostok::core::g_log_flags,
            &vostok::core::g_log_format,
            ".\\game_material_manager_cook.cpp",
            0xE8u,
            "void __thiscall survarium::game_material_manager_cook::on_decals_loaded(class vostok::resources::queries_res"
            "ult &,class survarium::vector<struct survarium::game_material_manager_cook::query_ext_data> *)",
            "game_core:",
            error,
            "resource cook failed: %s",
            v10);
        }
        v11 = (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)(v37 & 1);
        if ( (v37 & 1) != 0 )
        {
          v37 &= ~1u;
          boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
            v11,
            (int *)&log_callback);
        }
      }
    }
  }
  M_start = ext_data->_M_impl._M_start;
  it = M_start;
  M_finish = ext_data->_M_impl._M_finish;
  end = M_finish;
  idx = 0;
  while ( it != end )
  {
    if ( it->type )
    {
      if ( it->type == logic )
      {
        v17 = vostok::resources::queries_result::operator[](data, idx);
        vostok::resources::query_result_for_user::get_unmanaged_resource(
          v18,
          (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v17,
          (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v32);
        pair = it->pair;
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
          &pair->m_decal2,
          &v32);
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v32);
        p_cd = &it->cd;
        survarium::weapon_user_dead_state::finalize(v20);
        vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data>(
          v21,
          p_cd);
      }
      else if ( it->type == editor )
      {
        v22 = vostok::resources::queries_result::operator[](data, idx);
        vostok::resources::query_result_for_user::get_unmanaged_resource(
          v23,
          (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v22,
          (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v30);
        v29 = it->pair;
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
          &v29->m_sound_emitter,
          &v30);
        vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v30);
      }
      else
      {
        v27.m_object = (vostok::configs::binary_config *)it;
        v24 = vostok::resources::queries_result::operator[](data, idx);
        vostok::resources::query_result_for_user::get_unmanaged_resource(
          v25,
          (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v24,
          &v27);
        survarium::material_pair::add_particle(
          it->pair,
          (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v27.m_object);
      }
    }
    else
    {
      v12 = vostok::resources::queries_result::operator[](data, idx);
      vostok::resources::query_result_for_user::get_unmanaged_resource(
        v13,
        (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v12,
        (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&object);
      v33 = it->pair;
      vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
        &v33->m_decal1,
        &object);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&object);
      v14 = &it->cd;
      survarium::weapon_user_dead_state::finalize(v15);
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::material_effects_instance_cook_data>(
        v16,
        v14);
    }
    ++it;
    ++idx;
  }
  v27.m_object = (vostok::configs::binary_config *)1;
  parent_query = vostok::resources::queries_result::get_parent_query((vostok::resources::queries_result *)it, (int)data);
  vostok::resources::query_result_for_cook::finish_query(
    parent_query,
    result_success,
    (assert_on_fail_bool)v27.m_object);
}
