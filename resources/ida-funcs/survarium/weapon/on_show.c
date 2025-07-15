void __thiscall survarium::weapon::on_show(survarium::weapon *this, const bool real_insert)
{
  vostok::render::scene_renderer *v3; // ecx
  survarium::rifle_scope *m_object; // edx
  int v5; // edx
  survarium::weapon *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp+Ch] [ebp-4h] BYREF

  if ( real_insert )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v7,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_game_scene->m_render_scene);
    m_object = this->m_rifle_scope.m_object;
    if ( m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      if ( this->m_is_scope_aimed && survarium::player::is_current((survarium::player *)v3, (int)this->m_user) )
      {
        vostok::render::scene_renderer::add_model(
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_aimed_scope.m_object->m_render_model,
          *(vostok::render::scene_renderer **)((char *)&dword_200060
                                             + (unsigned int)this->m_game_scene->m_game->m_renderer),
          &v7,
          &this->m_current_transform,
          &this->m_current_transform);
        if ( this->m_rifle_scope.m_object->m_hide_weapon_on_aim )
          vostok::render::scene_renderer::set_model_visible(
            v3,
            *(const vostok::resources::resource_ptr<vostok::render::render_model_instance,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
            (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)(this->m_user[1].m_target_quality_level + 264),
            1u,
            (volatile int *)2);
        this->m_aimed_scope_added = 1;
      }
      else
      {
        vostok::render::scene_renderer::add_model(
          (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->m_idle_scope.m_object->m_render_model,
          *(vostok::render::scene_renderer **)((char *)&dword_200060
                                             + (unsigned int)this->m_game_scene->m_game->m_renderer),
          &v7,
          &this->m_current_transform,
          &this->m_current_transform);
      }
    }
    if ( !this->m_aimed_scope_added )
      vostok::render::scene_renderer::add_model(
        (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model.m_object->m_render_model,
        *(vostok::render::scene_renderer **)((char *)&dword_200060 + (unsigned int)this->m_game_scene->m_game->m_renderer),
        &v7,
        &this->m_current_transform,
        &this->m_current_transform);
    if ( survarium::player::is_current((survarium::player *)v3, (int)this->m_user) )
      *(_DWORD *)(*(_DWORD *)((char *)&loc_11403 + v5 + 5) + 872) = 1;
    survarium::weapon::set_foreground(this, *((_BYTE *)&loc_11439 + (unsigned int)this->m_user) == 0);
    survarium::weapon::set_movable_static(v6);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v7);
  }
}
