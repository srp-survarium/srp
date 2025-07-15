void __thiscall survarium::weapon_user_animations_selector::set_animation_callback(
        survarium::weapon_user_animations_selector *this,
        const char *channel_id,
        const void *callback_uid,
        const boost::function<enum vostok::animation::callback_return_type_enum __cdecl(vostok::animation::animation_callback_params &)> *animation_callback)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> v5; // [esp+8h] [ebp-4h] BYREF

  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>(
    &v5,
    0);
  this->m_user->subscribe_animation_player(this->m_user, channel_id, animation_callback, callback_uid, &v5, 255u, 0);
  vostok::animation::mixing::animation_interval::~animation_interval(&v5);
}
