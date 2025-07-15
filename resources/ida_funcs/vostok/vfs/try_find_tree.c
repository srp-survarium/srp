void __cdecl vostok::vfs::try_find_tree(vostok::vfs::find_environment *env)
{
  unsigned int v1; // esi
  unsigned int v2; // esi
  survarium::game_camera *v3; // ecx
  vostok::memory::base_allocator *v4; // eax
  vostok::vfs::async_callbacks_data *v5; // [esp+Ch] [ebp-Ch]
  vostok::vfs::async_callbacks_data *async_data; // [esp+10h] [ebp-8h]

  v1 = vostok::strings::length(env->path_to_find);
  v2 = v1 + vostok::strings::length(env->path_to_find) + 138;
  survarium::weapon_user_dead_state::finalize(v3);
  async_data = (vostok::vfs::async_callbacks_data *)vostok::memory::malloc_helper<vostok::memory::base_allocator>(
                                                      v4,
                                                      v2);
  if ( async_data )
  {
    v5 = (vostok::vfs::async_callbacks_data *)operator new(0x88u, async_data);
    if ( v5 )
      vostok::vfs::async_callbacks_data::async_callbacks_data(v5, type_tree, env);
    if ( vostok::vfs::fill_expand_nodes_and_incref(
           async_data->env.node,
           async_data->env.node_parent,
           async_data->env.node,
           &async_data->nodes_to_expand,
           async_data,
           1u) == result_success )
      vostok::vfs::async_callbacks_data::finish_with_out_of_memory(async_data);
    else
      vostok::vfs::query_expand_nodes(&async_data->nodes_to_expand, async_data);
  }
  else
  {
    vostok::vfs::async_callbacks_data::finish_with_out_of_memory(0);
  }
}
