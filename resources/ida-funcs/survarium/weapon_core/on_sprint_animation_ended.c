vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core::on_sprint_animation_ended(
        survarium::weapon_core *this,
        vostok::animation::animation_callback_params *params)
{
  char v3; // bl
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *sprint_animation; // eax
  vostok::resources::managed_resource *m_object; // ecx
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v6; // eax
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *v7; // eax
  char v9; // [esp+Fh] [ebp-19h]
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v10; // [esp+10h] [ebp-18h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v11; // [esp+18h] [ebp-10h] BYREF
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > v12; // [esp+20h] [ebp-8h] BYREF

  v10.first.m_object = 0;
  v3 = 1;
  sprint_animation = survarium::weapon_user_animations_container::get_sprint_animation(
                       (survarium::weapon_user_animations_container *)&v12,
                       (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)this->m_portable_interactive_object->m_user_animations_selector.m_animations.m_object,
                       &v12,
                       0);
  m_object = params->animation->m_object;
  if ( m_object == sprint_animation->first.m_object
    || (v3 = 3,
        v6 = survarium::weapon_user_animations_container::get_sprint_animation(
               (survarium::weapon_user_animations_container *)&v11,
               (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)this->m_portable_interactive_object->m_user_animations_selector.m_animations.m_object,
               &v11,
               2),
        m_object = params->animation->m_object,
        m_object == v6->first.m_object)
    || (v3 = 7,
        v7 = survarium::weapon_user_animations_container::get_sprint_animation(
               (survarium::weapon_user_animations_container *)&v10,
               (stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *)this->m_portable_interactive_object->m_user_animations_selector.m_animations.m_object,
               &v10,
               4),
        m_object = params->animation->m_object,
        v9 = 0,
        m_object == v7->first.m_object) )
  {
    v9 = 1;
  }
  if ( (v3 & 4) != 0 )
  {
    v3 &= ~4u;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v10.second);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v10.first);
  }
  if ( (v3 & 2) != 0 )
  {
    v3 &= ~2u;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v11.second);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v11.first);
  }
  if ( (v3 & 1) != 0 )
  {
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v12.second);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&v12.first);
  }
  if ( v9 )
  {
    params->interrupt_animation_player_tick = 1;
    survarium::base_player::unsubscribe_animation_player(
      (survarium::base_player *)m_object,
      (vostok::animation::reserved_channel_ids_enum)this->m_user,
      (const void *)3,
      (int)this);
    this->m_is_in_sprint_transition = 0;
  }
  return 0;
}
