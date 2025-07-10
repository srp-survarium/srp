vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__thiscall survarium::weapon_user_animations_container::get_stand_animation(
        survarium::weapon_user_animations_container *this,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *result,
        bool aimed,
        unsigned int index,
        bool is_third_view)
{
  const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v6; // [esp+0h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v7; // [esp+4h] [ebp-18h]
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *v8; // [esp+8h] [ebp-14h]
  survarium::weapon_user_animations_container *thisa; // [esp+Ch] [ebp-10h]

  thisa = this;
  if ( aimed )
  {
    this = (survarium::weapon_user_animations_container *)((char *)this + 744);
    v8 = thisa->m_aimed_stand_hands_only_animations[0];
  }
  else
  {
    v8 = this->m_stand_hands_only_animations[0];
  }
  if ( aimed )
  {
    this = (survarium::weapon_user_animations_container *)thisa->m_aimed_stand_animations;
    v7 = thisa->m_aimed_stand_animations[0];
  }
  else
  {
    v7 = thisa->m_stand_animations[0];
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( index >= 0x1B )
    v6 = &v8[6 * is_third_view - 27 + index];
  else
    v6 = &v7[27 * is_third_view + index];
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    result,
    v6);
  return result;
}
