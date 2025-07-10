void __thiscall survarium::profile_character::character_model_ready(
        survarium::profile_character *this,
        vostok::resources::unmanaged_resource *data)
{
  vostok::render::skeleton_model_instance *m_object; // eax
  vostok::render::skeleton_model_instance *v4; // eax
  vostok::resources::unmanaged_resource *v5; // ebx
  vostok::resources::unmanaged_resource *v6; // esi
  vostok::render::skeleton_model_instance *v7; // eax
  vostok::render::skeleton_model_instance *v8; // ecx
  vostok::render::skeleton_model_instance *v9; // eax
  const vostok::animation::skeleton_bone *v10; // ebx
  int v11; // esi
  int v12; // ecx
  vostok::render::scene_renderer *m_scene_renderer; // eax
  const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *m_scene; // [esp-10h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *p_m_render_model; // [esp-Ch] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_children_resources; // [esp-8h] [ebp-14h]

  m_object = this->m_character_model.m_object;
  if ( m_object )
  {
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::scene_renderer::remove_model(
        (vostok::render::scene_renderer *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
        this->m_scene_renderer,
        this->m_scene,
        &m_object->m_render_model);
      v4 = this->m_character_model.m_object;
      this->m_character_model.m_object = 0;
      if ( v4 )
      {
        if ( !_InterlockedExchangeAdd(&v4->m_reference_count, 0xFFFFFFFF) )
          vostok::resources::unmanaged_intrusive_base::destroy(&v4->vostok::resources::unmanaged_intrusive_base, v4);
      }
    }
  }
  if ( data->m_parent_resources.m_lock == 1 )
  {
    p_m_children_resources = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)&data[1].m_children_resources;
    data = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&data,
      (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)p_m_children_resources);
    v5 = data;
    v6 = 0;
    if ( data )
    {
      v6 = data;
      _InterlockedExchangeAdd(&data->m_reference_count, 1u);
    }
    v7 = 0;
    if ( v6 )
    {
      v7 = (vostok::render::skeleton_model_instance *)v6;
      _InterlockedExchangeAdd(&v6->m_reference_count, 1u);
    }
    v8 = v7;
    v9 = this->m_character_model.m_object;
    this->m_character_model.m_object = v8;
    if ( v9 && !_InterlockedExchangeAdd(&v9->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v9->vostok::resources::unmanaged_intrusive_base, v9);
    if ( v6 && !_InterlockedExchangeAdd(&v6->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(&v6->vostok::resources::unmanaged_intrusive_base, v6);
    if ( v5 )
    {
      if ( !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&v5->vostok::resources::unmanaged_intrusive_base, v5);
    }
    vostok::resources::resource_ptr<vostok::render::res_effect,vostok::resources::unmanaged_intrusive_base>::operator=(
      &this->m_character_model.m_object->m_skeleton,
      &this->m_skeleton.m_object);
    v10 = (const vostok::animation::skeleton_bone *)&this->m_skeleton.m_object[1];
    v11 = stlp_std::priv::__find_if<vostok::animation::skeleton_bone const *,bone_id_predicate>(
            v10,
            (const vostok::animation::skeleton_bone *)&this->m_skeleton.m_object[1]
          + this->m_skeleton.m_object->m_bones_count,
            (bone_id_predicate)&stru_971D84.m_data.m_size)
        - v10;
    v12 = v10->m_children_begin - v10;
    p_m_render_model = &this->m_character_model.m_object->m_render_model;
    m_scene = this->m_scene;
    m_scene_renderer = this->m_scene_renderer;
    this->m_weapon_bone_index = v11 - v12;
    vostok::render::scene_renderer::add_model(
      (vostok::render::scene_renderer *)v12,
      (int)m_scene_renderer,
      m_scene,
      p_m_render_model,
      &this->m_initial_matrix);
  }
}
