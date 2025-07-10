void __thiscall survarium::weapon_core_cook::on_weapon_states_ready(
        survarium::weapon_core_cook *this,
        vostok::resources::queries_result *data,
        const survarium::weapon_state_creation_params *params,
        survarium::weapon_core *object_to_cook)
{
  survarium::game_camera *v4; // ecx
  vostok::memory::doug_lea_allocator *v5; // eax
  vostok::resources::query_result_for_user *v6; // ecx
  vostok::resources::query_result_for_user *v7; // ecx
  vostok::resources::query_result_for_user *v8; // ecx
  vostok::resources::query_result_for_user *v9; // ecx
  vostok::resources::query_result_for_user *v10; // ecx
  unsigned int v11; // eax
  vostok::resources::query_result_for_user *v12; // ecx
  unsigned int v13; // eax
  vostok::resources::query_result_for_user *v14; // ecx
  vostok::network_core::packet_reader *v15; // eax
  vostok::resources::memory_usage_type *v16; // eax
  vostok::resources::unmanaged_resource *v17; // ecx
  vostok::resources::queries_result *v18; // ecx
  vostok::resources::query_result_for_cook *parent_query; // eax
  vostok::resources::queries_result *v20; // ecx
  vostok::resources::query_result_for_cook *v21; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v22[2]; // [esp-4h] [ebp-168h] BYREF
  vostok::resources::memory_usage_type *memory_usage; // [esp+4h] [ebp-160h]
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *v24; // [esp+8h] [ebp-15Ch]
  survarium::weapon_core_base_state *v25; // [esp+Ch] [ebp-158h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v26; // [esp+10h] [ebp-154h]
  unsigned int v27; // [esp+14h] [ebp-150h]
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *v28; // [esp+18h] [ebp-14Ch]
  survarium::weapon_core_base_state *v29; // [esp+1Ch] [ebp-148h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v30; // [esp+20h] [ebp-144h]
  unsigned int v31; // [esp+24h] [ebp-140h]
  survarium::weapon_core_base_state *v32; // [esp+28h] [ebp-13Ch]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v33; // [esp+2Ch] [ebp-138h]
  unsigned int v34; // [esp+30h] [ebp-134h]
  survarium::weapon_core_base_state *v35; // [esp+34h] [ebp-130h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v36; // [esp+38h] [ebp-12Ch]
  unsigned int v37; // [esp+3Ch] [ebp-128h]
  survarium::weapon_core_base_state *v38; // [esp+40h] [ebp-124h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v39; // [esp+44h] [ebp-120h]
  unsigned int v40; // [esp+48h] [ebp-11Ch]
  survarium::weapon_core_base_state *v41; // [esp+4Ch] [ebp-118h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v42; // [esp+50h] [ebp-114h]
  unsigned int v43; // [esp+54h] [ebp-110h]
  survarium::weapon_core_base_state *v44; // [esp+58h] [ebp-10Ch]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v45; // [esp+5Ch] [ebp-108h]
  unsigned int v46; // [esp+60h] [ebp-104h]
  survarium::weapon_core_base_state *v47; // [esp+64h] [ebp-100h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v48; // [esp+68h] [ebp-FCh]
  unsigned int v49; // [esp+6Ch] [ebp-F8h]
  survarium::weapon_core_base_state *p_m_prev_in_global_delay_delete_list; // [esp+70h] [ebp-F4h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v51; // [esp+74h] [ebp-F0h]
  unsigned int v52; // [esp+78h] [ebp-ECh]
  survarium::weapon_core_base_state *object; // [esp+7Ch] [ebp-E8h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v54; // [esp+80h] [ebp-E4h]
  unsigned int index; // [esp+84h] [ebp-E0h]
  survarium::weapon_core_cook *thisa; // [esp+88h] [ebp-DCh]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v57; // [esp+8Ch] [ebp-D8h]
  vostok::render::skeleton_model_instance *v58; // [esp+90h] [ebp-D4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v59; // [esp+94h] [ebp-D0h]
  vostok::render::skeleton_model_instance *v60; // [esp+98h] [ebp-CCh]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v61; // [esp+9Ch] [ebp-C8h]
  vostok::render::skeleton_model_instance *v62; // [esp+A0h] [ebp-C4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v63; // [esp+A4h] [ebp-C0h]
  vostok::render::skeleton_model_instance *v64; // [esp+A8h] [ebp-BCh]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v65; // [esp+ACh] [ebp-B8h]
  vostok::render::skeleton_model_instance *v66; // [esp+B0h] [ebp-B4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v67; // [esp+B4h] [ebp-B0h]
  vostok::render::skeleton_model_instance *v68; // [esp+B8h] [ebp-ACh]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v69; // [esp+BCh] [ebp-A8h]
  vostok::render::skeleton_model_instance *v70; // [esp+C0h] [ebp-A4h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v71; // [esp+C4h] [ebp-A0h]
  vostok::render::skeleton_model_instance *v72; // [esp+C8h] [ebp-9Ch]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v73; // [esp+CCh] [ebp-98h]
  vostok::render::skeleton_model_instance *v74; // [esp+D0h] [ebp-94h]
  vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *unmanaged_resource; // [esp+D4h] [ebp-90h]
  vostok::render::skeleton_model_instance *v76; // [esp+D8h] [ebp-8Ch]
  vostok::memory::doug_lea_allocator *allocator; // [esp+DCh] [ebp-88h]
  vostok::memory::detail::call_destructor_predicate call_destructor_predicate; // [esp+E3h] [ebp-81h] BYREF
  int v79; // [esp+E4h] [ebp-80h]
  boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *v80; // [esp+ECh] [ebp-78h] BYREF
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v81; // [esp+F4h] [ebp-70h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> v82; // [esp+F8h] [ebp-6Ch] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v83; // [esp+FCh] [ebp-68h] BYREF
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v84; // [esp+100h] [ebp-64h]
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v85; // [esp+104h] [ebp-60h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> v86; // [esp+108h] [ebp-5Ch] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v87; // [esp+10Ch] [ebp-58h] BYREF
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v88; // [esp+110h] [ebp-54h]
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v89; // [esp+114h] [ebp-50h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v90; // [esp+118h] [ebp-4Ch] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v91; // [esp+11Ch] [ebp-48h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v92; // [esp+120h] [ebp-44h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v93; // [esp+124h] [ebp-40h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v94; // [esp+128h] [ebp-3Ch] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v95; // [esp+12Ch] [ebp-38h] BYREF
  vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> v96; // [esp+130h] [ebp-34h] BYREF
  char v97; // [esp+137h] [ebp-2Dh]
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> reload_state; // [esp+138h] [ebp-2Ch] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> inactive_state; // [esp+13Ch] [ebp-28h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> idle_state; // [esp+140h] [ebp-24h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> fire_state; // [esp+144h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> chamber_a_round_state; // [esp+148h] [ebp-1Ch] BYREF
  unsigned int resource_index; // [esp+14Ch] [ebp-18h]
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> show_state; // [esp+150h] [ebp-14h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> chamber_a_round_aimed_state; // [esp+154h] [ebp-10h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> hide_state; // [esp+158h] [ebp-Ch] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> aim_state; // [esp+15Ch] [ebp-8h] BYREF
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> aim_fire_state; // [esp+160h] [ebp-4h] BYREF

  thisa = this;
  v79 = 0;
  v97 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v4);
  allocator = v5;
  call_destructor_predicate = 0;
  vostok::memory::detail::delete_helper_impl<vostok::memory::doug_lea_allocator,survarium::weapon_state_creation_params,vostok::memory::detail::call_destructor_predicate>(
    v5,
    (survarium::weapon_state_creation_params **)&params,
    &call_destructor_predicate);
  resource_index = 0;
  index = 0;
  v54 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, 0);
  unmanaged_resource = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource((vostok::resources::query_result_for_user *)++resource_index, v54, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v96);
  v76 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(unmanaged_resource);
  if ( v76 )
    object = (survarium::weapon_core_base_state *)&v76[-1].m_prev_in_global_delay_delete_list;
  else
    object = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &inactive_state,
    object);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v96);
  v52 = resource_index;
  v51 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v73 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v6, v51, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v95);
  v74 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v73);
  if ( v74 )
    p_m_prev_in_global_delay_delete_list = (survarium::weapon_core_base_state *)&v74[-1].m_prev_in_global_delay_delete_list;
  else
    p_m_prev_in_global_delay_delete_list = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &show_state,
    p_m_prev_in_global_delay_delete_list);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v95);
  v49 = resource_index;
  v48 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v71 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v7, v48, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v94);
  v72 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v71);
  if ( v72 )
    v47 = (survarium::weapon_core_base_state *)&v72[-1].m_prev_in_global_delay_delete_list;
  else
    v47 = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &hide_state,
    v47);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v94);
  v46 = resource_index;
  v45 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v69 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource((vostok::resources::query_result_for_user *)resource_index, v45, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v93);
  v70 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v69);
  if ( v70 )
    v44 = (survarium::weapon_core_base_state *)&v70[-1].m_prev_in_global_delay_delete_list;
  else
    v44 = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &idle_state,
    v44);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v93);
  v43 = resource_index;
  v42 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v67 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v8, v42, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v92);
  v68 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v67);
  if ( v68 )
    v41 = (survarium::weapon_core_base_state *)&v68[-1].m_prev_in_global_delay_delete_list;
  else
    v41 = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &reload_state,
    v41);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v92);
  v40 = resource_index;
  v39 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v65 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v9, v39, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v91);
  v66 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v65);
  if ( v66 )
    v38 = (survarium::weapon_core_base_state *)&v66[-1].m_prev_in_global_delay_delete_list;
  else
    v38 = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &fire_state,
    v38);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v91);
  v37 = resource_index;
  v36 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v63 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource((vostok::resources::query_result_for_user *)resource_index, v36, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v90);
  v64 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v63);
  if ( v64 )
    v35 = (survarium::weapon_core_base_state *)&v64[-1].m_prev_in_global_delay_delete_list;
  else
    v35 = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &aim_state,
    v35);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v90);
  v34 = resource_index;
  v33 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
  v61 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v10, v33, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v89);
  v62 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v61);
  if ( v62 )
    v32 = (survarium::weapon_core_base_state *)&v62[-1].m_prev_in_global_delay_delete_list;
  else
    v32 = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    &aim_fire_state,
    v32);
  vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v89);
  v11 = vostok::resources::queries_result::size(data);
  if ( resource_index >= v11 )
  {
    v79 |= 4u;
    v85.m_object = 0;
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v85,
      0);
    v28 = (vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *)&v85;
  }
  else
  {
    v31 = resource_index;
    v30 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
    v79 |= 1u;
    v79 |= 2u;
    v59 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v12, v30, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v87);
    v60 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v59);
    if ( v60 )
      v29 = (survarium::weapon_core_base_state *)&v60[-1].m_prev_in_global_delay_delete_list;
    else
      v29 = 0;
    vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
      &v86,
      v29);
    v28 = &v86;
  }
  v88 = v28;
  chamber_a_round_state.m_object = 0;
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &chamber_a_round_state,
    v28);
  if ( (v79 & 4) != 0 )
  {
    v79 &= ~4u;
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v85);
  }
  if ( (v79 & 2) != 0 )
  {
    v79 &= ~2u;
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v86);
  }
  if ( (v79 & 1) != 0 )
  {
    v79 &= ~1u;
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v87);
  }
  v13 = vostok::resources::queries_result::size(data);
  if ( resource_index >= v13 )
  {
    v79 |= 0x20u;
    v81.m_object = 0;
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v81,
      0);
    v24 = (vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *)&v81;
  }
  else
  {
    v27 = resource_index;
    v26 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, resource_index++);
    v79 |= 8u;
    v79 |= 0x10u;
    v57 = (vostok::intrusive_ptr<vostok::render::skeleton_model_instance,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::query_result_for_user::get_unmanaged_resource(v14, v26, (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&v83);
    v58 = vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr(v57);
    if ( v58 )
      v25 = (survarium::weapon_core_base_state *)&v58[-1].m_prev_in_global_delay_delete_list;
    else
      v25 = 0;
    vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
      &v82,
      v25);
    v24 = &v82;
  }
  v84 = v24;
  chamber_a_round_aimed_state.m_object = 0;
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &chamber_a_round_aimed_state,
    v24);
  if ( (v79 & 0x20) != 0 )
  {
    v79 &= ~0x20u;
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v81);
  }
  if ( (v79 & 0x10) != 0 )
  {
    v79 &= ~0x10u;
    vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v82);
  }
  if ( (v79 & 8) != 0 )
  {
    v79 &= ~8u;
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v83);
  }
  survarium::weapon_core::initialize_weapon_logic(
    object_to_cook,
    &inactive_state,
    &show_state,
    &hide_state,
    &idle_state,
    &reload_state,
    &fire_state,
    &aim_state,
    &aim_fire_state,
    &chamber_a_round_state,
    &chamber_a_round_aimed_state);
  v15 = (vostok::network_core::packet_reader *)thisa->cooked_object_size(thisa, object_to_cook);
  vostok::resources::memory_usage_type::memory_usage_type(
    (boost::_bi::list2<unsigned char &,vostok::network_core::packet_reader &> *)&vostok::resources::nocache_memory,
    &v80,
    v15,
    (vostok::network_core::packet_reader *)v22[1].m_object);
  memory_usage = v16;
  v22[0].m_object = v17;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    v22,
    (vostok::configs::binary_config *)object_to_cook);
  parent_query = vostok::resources::queries_result::get_parent_query(v18, (int)data);
  vostok::resources::query_result_for_cook::set_unmanaged_resource(parent_query, v22[0], memory_usage);
  v22[0].m_object = (vostok::resources::unmanaged_resource *)1;
  v21 = vostok::resources::queries_result::get_parent_query(v20, (int)data);
  vostok::resources::query_result_for_cook::finish_query(v21, result_success, (assert_on_fail_bool)v22[0].m_object);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&chamber_a_round_aimed_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&chamber_a_round_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&aim_fire_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&aim_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&fire_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&reload_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&idle_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&hide_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&show_state);
  vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&inactive_state);
}
