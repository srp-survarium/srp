void __userpurge vostok::vfs::async_callbacks_data::async_callbacks_data(
        vostok::vfs::async_callbacks_data *this@<esi>,
        const vostok::vfs::find_environment *in_env@<eax>,
        vostok::vfs::async_callbacks_data::type_enum type)
{
  unsigned int v4; // edi
  char *partial_path; // [esp-10h] [ebp-18h]
  unsigned int v6; // [esp+10h] [ebp+8h]

  this->callbacks_count = 0;
  this->callbacks_called_count = 0;
  this->all_queries_done = 0;
  this->env.find_results = in_env->find_results;
  this->env.path_to_find = in_env->path_to_find;
  this->env.partial_path = in_env->partial_path;
  this->env.path_part_index = in_env->path_part_index;
  this->env.out_iterator = in_env->out_iterator;
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&in_env->callback,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)&this->env.callback);
  this->env.node = in_env->node;
  this->env.node_parent = in_env->node_parent;
  this->env.find_flags.m_flags = in_env->find_flags.m_flags;
  this->env.file_system = in_env->file_system;
  this->env.allocator = in_env->allocator;
  this->env.mount_operation_id = in_env->mount_operation_id;
  this->result = result_success;
  this->nodes_to_expand.m_size = 0;
  this->nodes_to_expand.m_first = 0;
  this->nodes_to_expand.m_last = 0;
  this->previous_nodes_to_expand.m_size = 0;
  this->previous_nodes_to_expand.m_first = 0;
  this->previous_nodes_to_expand.m_last = 0;
  this->type = type;
  v6 = strlen(in_env->path_to_find);
  v4 = strlen(in_env->partial_path);
  vostok::strings::copy(this->path_to_find, v6 + 1, (char *)this->env.path_to_find);
  partial_path = (char *)this->env.partial_path;
  this->env.path_to_find = this->path_to_find;
  vostok::strings::copy(&this->path_to_find[v6 + 1], v4 + 1, partial_path);
  this->env.partial_path = &this->path_to_find[v6 + 1];
}
