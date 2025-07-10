void __thiscall vostok::vfs::async_callbacks_data::async_callbacks_data(
        vostok::vfs::async_callbacks_data *this,
        vostok::vfs::async_callbacks_data::type_enum type,
        boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *in_env)
{
  survarium::game_camera *v3; // ecx
  survarium::game_camera *v4; // ecx
  unsigned int partial_path_length; // [esp+2Ch] [ebp-Ch]
  unsigned int path_to_find_length; // [esp+34h] [ebp-4h]

  this->callbacks_count = 0;
  this->callbacks_called_count = 0;
  this->all_queries_done = 0;
  vostok::vfs::find_environment::find_environment(&this->env, in_env);
  this->result = result_error;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this,
    &this->nodes_to_expand.m_size);
  survarium::weapon_user_dead_state::finalize(v3);
  this->nodes_to_expand.m_first = 0;
  this->nodes_to_expand.m_last = 0;
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
    (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)&this->nodes_to_expand,
    &this->previous_nodes_to_expand.m_size);
  survarium::weapon_user_dead_state::finalize(v4);
  this->previous_nodes_to_expand.m_first = 0;
  this->previous_nodes_to_expand.m_last = 0;
  this->type = type;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->previous_nodes_to_expand);
  path_to_find_length = vostok::strings::length((const char *)(&in_env->vtable)[1]);
  partial_path_length = vostok::strings::length((const char *)in_env->functor.obj_ptr);
  vostok::strings::copy(this->path_to_find, path_to_find_length + 1, this->env.path_to_find);
  this->env.path_to_find = this->path_to_find;
  vostok::strings::copy(&this->path_to_find[path_to_find_length + 1], partial_path_length + 1, this->env.partial_path);
  this->env.partial_path = &this->path_to_find[path_to_find_length + 1];
}
