void __thiscall survarium::weapon::on_skeleton_matrices_changed(
        survarium::weapon *this,
        unsigned int current_time_in_ms,
        const vostok::math::float4x4 *weapon_transform,
        const vostok::math::float4x4 *const weapon_matrices_begin,
        const vostok::math::float4x4 *const weapon_matrices_end,
        const vostok::math::float4x4 *user_transform,
        vostok::math::float4x4 *const user_matrices_begin,
        vostok::math::float4x4 *const user_matrices_end,
        const vostok::math::float4x4 *__formal)
{
  unsigned int v10; // eax
  bool v11; // zf
  unsigned int m_current_fire_light_anim_time; // ecx
  unsigned int m_fire_light_anim_length; // eax
  survarium::base_game_scene *m_game_scene; // eax
  const vostok::math::float4x4 *v15; // eax
  vostok::render::base_scene *m_object; // eax
  vostok::render::game::renderer *m_renderer; // edi
  survarium::rifle_scope *v18; // eax
  float v19; // xmm0_4
  survarium::player *v20; // esi
  survarium::base_game_scene *v21; // ecx
  survarium::rifle_scope *v22; // eax
  float v23; // xmm0_4
  survarium::player *m_user; // esi
  survarium::rifle_scope *v25; // eax
  const vostok::math::float4x4 *v26; // edx
  vostok::render::game::renderer *v27; // ecx
  vostok::render::skeleton_model_instance *v28; // edx
  survarium::rifle_scope *v29; // eax
  survarium::rifle_scope *v30; // eax
  vostok::render::base_scene *v31; // eax
  vostok::resources::unmanaged_intrusive_base *v32; // ecx
  vostok::render::scene_renderer *m_scene; // [esp-10h] [ebp-70h]
  vostok::render::scene_renderer *v34; // [esp-Ch] [ebp-6Ch]
  unsigned int v35; // [esp+0h] [ebp-60h]
  unsigned int v36; // [esp+0h] [ebp-60h]
  vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> scene; // [esp+Ch] [ebp-54h] BYREF
  const vostok::math::float4x4 *transform; // [esp+10h] [ebp-50h]
  float m_fov_factor; // [esp+14h] [ebp-4Ch]
  vostok::render::game::renderer *renderer; // [esp+18h] [ebp-48h]
  unsigned int weapon_matrices_count; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 result; // [esp+20h] [ebp-40h] BYREF

  v10 = current_time_in_ms - this->m_last_tick_time_in_ms;
  v11 = !this->m_firing_light_added;
  this->m_last_tick_time_in_ms = current_time_in_ms;
  if ( !v11 )
  {
    this->m_current_fire_light_anim_time += v10;
    m_current_fire_light_anim_time = this->m_current_fire_light_anim_time;
    m_fire_light_anim_length = this->m_fire_light_anim_length;
    if ( m_current_fire_light_anim_time < m_fire_light_anim_length )
    {
      weapon_matrices_count = this->m_fire_light_anim_length;
      this->m_weapon_fire_light_props.range = (double)(m_fire_light_anim_length - m_current_fire_light_anim_time)
                                            * 5.0
                                            / (double)m_fire_light_anim_length;
    }
    else
    {
      this->m_weapon_fire_light_props.range = 0.0;
      this->m_current_fire_light_anim_time = 0;
    }
    m_game_scene = this->m_game_scene;
    m_scene = m_game_scene->m_game->m_renderer->m_scene;
    vostok::render::scene_renderer::update_light(
      m_scene,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)m_scene,
      (unsigned int)&m_game_scene->m_render_scene,
      (vostok::render::light_props *)this->m_weapon_fire_light_id);
  }
  weapon_matrices_count = weapon_matrices_end - weapon_matrices_begin;
  vostok::math::mul4x3(&result, &user_matrices_begin[this->m_left_toe_bone_index], user_transform);
  v15 = &user_matrices_begin[this->m_right_toe_bone_index];
  qmemcpy((void *)&this->m_left_toe_transform, &result, sizeof(this->m_left_toe_transform));
  vostok::math::mul4x3(&result, v15, user_transform);
  qmemcpy((void *)&this->m_right_toe_transform, &result, sizeof(this->m_right_toe_transform));
  qmemcpy(
    (void *)&this->m_barrel_transform,
    survarium::weapon::calculate_locator(
      (survarium::weapon *)&result,
      (int)this,
      &result,
      &this->m_barrel_locator,
      weapon_matrices_begin,
      v35),
    sizeof(this->m_barrel_transform));
  transform = &this->m_scope_transform;
  qmemcpy(
    (void *)&this->m_scope_transform,
    survarium::weapon::calculate_locator(
      (survarium::weapon *)&result,
      (int)this,
      &result,
      &this->m_scope_locator,
      weapon_matrices_begin,
      v36),
    sizeof(this->m_scope_transform));
  survarium::weapon::update_pfx_transform(0, this);
  m_object = this->m_game_scene->m_render_scene.m_object;
  scene.m_object = 0;
  if ( m_object )
  {
    scene.m_object = m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  m_renderer = this->m_game_scene->m_game->m_renderer;
  renderer = m_renderer;
  if ( s_draw_fire_point )
    vostok::render::debug::renderer::draw_origin(&scene, 0);
  if ( this->m_is_third_view )
  {
    if ( this->m_user->m_is_alive )
      goto LABEL_27;
    goto LABEL_20;
  }
  if ( !this->m_aimed )
  {
LABEL_20:
    if ( !this->m_is_scope_aimed )
      goto LABEL_30;
    v22 = this->m_rifle_scope.m_object;
    if ( v22 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        m_user = (survarium::player *)this->m_user;
        m_fov_factor = v22->m_fov_factor;
        v23 = m_fov_factor;
        survarium::player::fov_factor(m_user, current_time_in_ms);
        v25 = this->m_rifle_scope.m_object;
        if ( v25->m_change_scope_factor > (float)((float)(*(float *)&clear_value - v23)
                                                / (float)(*(float *)&clear_value - m_fov_factor))
          || !this->m_user->m_is_alive )
        {
          v26 = transform;
          this->m_is_scope_aimed = 0;
          vostok::render::scene_renderer::add_model(
            (vostok::render::scene_renderer *)this->m_game_scene->m_game->m_renderer,
            &scene,
            &v25->m_idle_scope.m_object->m_render_model,
            v26);
          v27 = this->m_game_scene->m_game->m_renderer;
          vostok::render::scene_renderer::remove_model(
            (vostok::render::scene_renderer *)v27,
            (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v27->m_scene,
            (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
          if ( this->m_rifle_scope.m_object->m_hide_weapon_on_aim )
          {
            v28 = this->model.m_object;
            qmemcpy((void *)&result, &this->survarium::weapon_core::m_transform, sizeof(result));
            vostok::render::scene_renderer::add_model(
              (vostok::render::scene_renderer *)this->m_game_scene,
              &scene,
              &v28->m_render_model,
              &result);
            vostok::render::scene_renderer::set_model_visible(
              (vostok::render::scene_renderer *)this->m_game_scene->m_game,
              (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
              LODWORD(this->m_user[122].m_recoil_params.stand_multiplier) + 264,
              1u);
            m_renderer = renderer;
          }
        }
      }
    }
LABEL_27:
    if ( this->m_is_scope_aimed )
      goto LABEL_28;
LABEL_30:
    vostok::render::scene_renderer::update_model(
      m_renderer->m_scene,
      (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)m_renderer->m_scene,
      (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene,
      (const vostok::math::float4x4 *)&this->model.m_object->m_render_model);
    vostok::render::scene_renderer::update_skeleton(
      (vostok::render::scene_renderer *)&this->model.m_object->m_render_model,
      &this->model.m_object->m_render_model,
      weapon_matrices_begin,
      weapon_matrices_count);
    goto LABEL_31;
  }
  if ( !this->m_is_scope_aimed )
  {
    v18 = this->m_rifle_scope.m_object;
    if ( v18 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v20 = (survarium::player *)this->m_user;
        m_fov_factor = v18->m_fov_factor;
        v19 = m_fov_factor;
        survarium::player::fov_factor(v20, current_time_in_ms);
        if ( (float)((float)(*(float *)&clear_value - v19) / (float)(*(float *)&clear_value - m_fov_factor)) >= this->m_rifle_scope.m_object->m_change_scope_factor )
        {
          v21 = this->m_game_scene;
          this->m_is_scope_aimed = 1;
          v34 = v21->m_game->m_renderer->m_scene;
          vostok::render::scene_renderer::remove_model(
            v34,
            (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)v34,
            (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
          vostok::render::scene_renderer::add_model(
            (vostok::render::scene_renderer *)this->m_game_scene->m_game,
            &scene,
            &this->m_rifle_scope.m_object->m_aimed_scope.m_object->m_render_model,
            transform);
          if ( this->m_rifle_scope.m_object->m_hide_weapon_on_aim )
          {
            vostok::render::scene_renderer::remove_model(
              (vostok::render::scene_renderer *)this->m_game_scene->m_game,
              (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
              (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene);
            vostok::render::scene_renderer::set_model_visible(
              (vostok::render::scene_renderer *)this->m_game_scene->m_game,
              (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)this->m_game_scene->m_game->m_renderer->m_scene,
              LODWORD(this->m_user[122].m_recoil_params.stand_multiplier) + 264,
              1u);
          }
        }
      }
    }
    goto LABEL_27;
  }
LABEL_28:
  v29 = this->m_rifle_scope.m_object;
  if ( !v29 || !v29->m_hide_weapon_on_aim )
    goto LABEL_30;
LABEL_31:
  v30 = this->m_rifle_scope.m_object;
  if ( v30
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    if ( this->m_is_scope_aimed )
      vostok::render::scene_renderer::update_model(
        m_renderer->m_scene,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)m_renderer->m_scene,
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene,
        (const vostok::math::float4x4 *)&v30->m_aimed_scope.m_object->m_render_model);
    else
      vostok::render::scene_renderer::update_model(
        (vostok::render::scene_renderer *)&scene,
        (const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)m_renderer->m_scene,
        (const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> *)&scene,
        (const vostok::math::float4x4 *)&v30->m_idle_scope.m_object->m_render_model);
  }
  v31 = scene.m_object;
  if ( scene.m_object )
  {
    v32 = &scene.m_object->vostok::resources::unmanaged_intrusive_base;
    if ( !_InterlockedExchangeAdd(&scene.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(v32, v31);
  }
}
