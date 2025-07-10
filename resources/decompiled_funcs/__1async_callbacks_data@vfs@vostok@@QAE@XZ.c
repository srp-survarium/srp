void __thiscall vostok::vfs::async_callbacks_data::~async_callbacks_data(vostok::vfs::async_callbacks_data *this)
{
  survarium::game_camera *v1; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize(v1);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&this->env.callback);
}
