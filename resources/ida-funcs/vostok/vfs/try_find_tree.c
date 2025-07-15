void __usercall vostok::vfs::try_find_tree(vostok::vfs::find_environment *env@<eax>)
{
  vostok::vfs::async_callbacks_data *v2; // eax
  vostok::vfs::async_callbacks_data *v3; // ecx
  vostok::vfs::async_callbacks_data *v4; // esi

  v2 = (vostok::vfs::async_callbacks_data *)env->allocator->call_malloc(
                                              env->allocator,
                                              strlen(env->path_to_find) + strlen((const char *)env) + 138,
                                              "async_callbacks_data",
                                              "vostok::vfs::try_find_tree",
                                              ".\\find_async_tree.cpp",
                                              155);
  v4 = v2;
  if ( !v2 )
    goto LABEL_2;
  vostok::vfs::async_callbacks_data::async_callbacks_data(v2, env, type_tree);
  if ( vostok::vfs::fill_expand_nodes_and_incref(
         v4->env.node,
         v4->env.node_parent,
         v4->env.node,
         &v4->nodes_to_expand,
         v4,
         1u) == result_out_of_memory )
  {
    v2 = v4;
LABEL_2:
    vostok::vfs::async_callbacks_data::finish_with_out_of_memory(v3, (int)v2);
    return;
  }
  vostok::vfs::query_expand_nodes(&v4->nodes_to_expand, v4);
}
