void __usercall vostok::render::speedtree_cook::finish_model_creation(
        vostok::resources::unmanaged_resource **d@<eax>,
        vostok::resources::query_result_for_cook *a2@<ecx>,
        vostok::render::speedtree_cook *this)
{
  bool v4; // zf
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> **v5; // edi
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *v6; // ecx
  vostok::render::material *v7; // eax
  vostok::render::speedtree_tree_component *v8; // ecx
  vostok::render::material *v9; // eax
  vostok::render::speedtree_tree_component *v10; // ecx
  vostok::render::material *v11; // eax
  vostok::render::speedtree_tree_component *v12; // ecx
  vostok::render::material *v13; // eax
  vostok::render::speedtree_tree_component *v14; // ecx
  vostok::render::material *v15; // eax
  vostok::render::speedtree_tree_component *v16; // ecx
  vostok::configs::binary_config *v17; // eax
  vostok::render::grass_render_model *m_object; // edi
  vostok::render::speedtree_data *v19; // ecx
  char *v20; // eax
  malloc_state *m_reconstruction_info_actuality_tick_high; // esi
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v22; // [esp-Ch] [ebp-18h] BYREF
  vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> v23; // [esp-8h] [ebp-14h] BYREF
  unsigned int m_begin; // [esp-4h] [ebp-10h]
  int v25; // [esp+8h] [ebp-4h]

  v4 = *((_BYTE *)d + 1428) == 0;
  v25 = 0;
  if ( v4 )
  {
    v5 = (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> **)d[356];
    if ( v5[977] )
    {
      v6 = (vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *)(d + 6);
      if ( d[6]
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && (v7 = (vostok::render::material *)d[1]) != 0
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        m_begin = (unsigned int)v7->m_material_name.m_begin;
        v23.m_object = (vostok::render::material_effects_instance *)(d + 6);
        v22.m_object = (vostok::configs::binary_config *)(d + 6);
        vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
          (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)v6,
          (survarium::inventory **)&v23);
        vostok::render::speedtree_tree_component::set_material_effects(v8, v5[977], v23, (const char *)m_begin);
      }
      else
      {
        ((void (__thiscall *)(vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *))v5[977]->m_object->m_flags.m_flags)(v5[977]);
      }
    }
    if ( v5[978] )
    {
      if ( d[7]
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && (v9 = (vostok::render::material *)d[2]) != 0
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        m_begin = (unsigned int)v9->m_material_name.m_begin;
        v23.m_object = (vostok::render::material_effects_instance *)(d + 7);
        v22.m_object = (vostok::configs::binary_config *)(d + 7);
        vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
          (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)d
        + 7,
          (survarium::inventory **)&v23);
        vostok::render::speedtree_tree_component::set_material_effects(v10, v5[978], v23, (const char *)m_begin);
      }
      else
      {
        ((void (__thiscall *)(vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *))v5[978]->m_object->m_flags.m_flags)(v5[978]);
      }
    }
    if ( v5[979] )
    {
      if ( d[8]
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && (v11 = (vostok::render::material *)d[3]) != 0
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        m_begin = (unsigned int)v11->m_material_name.m_begin;
        v23.m_object = (vostok::render::material_effects_instance *)(d + 8);
        v22.m_object = (vostok::configs::binary_config *)(d + 8);
        vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
          (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)d
        + 8,
          (survarium::inventory **)&v23);
        vostok::render::speedtree_tree_component::set_material_effects(v12, v5[979], v23, (const char *)m_begin);
      }
      else
      {
        ((void (__thiscall *)(vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *))v5[979]->m_object->m_flags.m_flags)(v5[979]);
      }
    }
    if ( v5[980] )
    {
      if ( d[9]
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && (v13 = (vostok::render::material *)d[4]) != 0
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        m_begin = (unsigned int)v13->m_material_name.m_begin;
        v23.m_object = (vostok::render::material_effects_instance *)(d + 9);
        v22.m_object = (vostok::configs::binary_config *)(d + 9);
        vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
          (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)d
        + 9,
          (survarium::inventory **)&v23);
        vostok::render::speedtree_tree_component::set_material_effects(v14, v5[980], v23, (const char *)m_begin);
      }
      else
      {
        ((void (__thiscall *)(vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *))v5[980]->m_object->m_flags.m_flags)(v5[980]);
      }
    }
    if ( v5[981] )
    {
      if ( d[10]
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr
        && (v15 = (vostok::render::material *)d[5]) != 0
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        m_begin = (unsigned int)v15->m_material_name.m_begin;
        v23.m_object = (vostok::render::material_effects_instance *)(d + 10);
        v22.m_object = (vostok::configs::binary_config *)(d + 10);
        vostok::resources::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base>(
          (vostok::intrusive_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)d
        + 10,
          (survarium::inventory **)&v23);
        vostok::render::speedtree_tree_component::set_material_effects(v16, v5[981], v23, (const char *)m_begin);
      }
      else
      {
        ((void (__thiscall *)(vostok::resources::resource_ptr<vostok::render::material_effects_instance,vostok::resources::unmanaged_intrusive_base> *))v5[981]->m_object->m_flags.m_flags)(v5[981]);
      }
    }
    v17 = (vostok::configs::binary_config *)d[356];
    m_begin = 3976;
    v23.m_object = (vostok::render::material_effects_instance *)&vostok::resources::nocache_memory;
    v22.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v22,
      v17);
    vostok::resources::query_result_for_cook::set_unmanaged_resource(
      (vostok::resources::query_result_for_cook *)*d,
      (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v22.m_object,
      (const vostok::resources::memory_type *)v23.m_object,
      m_begin);
    m_begin = 0;
    v23.m_object = (vostok::render::material_effects_instance *)1;
    v22.m_object = (vostok::configs::binary_config *)3;
  }
  else
  {
    m_begin = 11;
    v23.m_object = (vostok::render::material_effects_instance *)1;
    v22.m_object = (vostok::configs::binary_config *)1;
  }
  vostok::resources::query_result_for_cook::finish_query_impl(
    a2,
    (int)*d,
    (vostok::resources::cook_base::result_enum)v22.m_object,
    (assert_on_fail_bool)v23.m_object,
    (vostok::resources::query_result_for_cook *)m_begin);
  m_object = vostok::render::g_allocator.m_object;
  vostok::render::speedtree_data::~speedtree_data(v19, d);
  v20 = (char *)d;
  m_reconstruction_info_actuality_tick_high = (malloc_state *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
  BYTE2(m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v20);
}
