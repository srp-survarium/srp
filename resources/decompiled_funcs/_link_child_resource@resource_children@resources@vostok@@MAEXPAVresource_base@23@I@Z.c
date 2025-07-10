void __userpurge vostok::resources::resource_children::link_child_resource(
        vostok::resources::resource_children *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::resources::resource_base *child,
        unsigned int quality)
{
  unsigned int v4; // edi
  vostok::resources::resource_link *v6; // eax
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  unsigned int v8; // eax
  bool *v9; // [esp+0h] [ebp-Ch]

  v4 = quality;
  if ( quality != -1 )
    vostok::threading::interlocked_or(&child->m_flags.m_flags, 0x100u);
  v6 = (vostok::resources::resource_link *)vostok::memory::g_resources_links_allocator.call_malloc(
                                             &vostok::memory::g_resources_links_allocator,
                                             12);
  if ( v6 )
  {
    v6->resource = 0;
    v6->next_link = 0;
    v6->quality_value = -1;
  }
  else
  {
    v6 = 0;
  }
  if ( debug_macro_helper_ignore_always_9 || v6 )
  {
    v6->resource = child;
    v6->quality_value = v4;
    vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      &this->m_children_resources.m_size,
      v6,
      v9);
  }
  else
  {
    v8 = occurances_left_9;
    if ( occurances_left_9 == -1 )
      v8 = 10;
    occurances_left_9 = v8 - 1;
    if ( v8 )
    {
      LOBYTE(quality) = 0;
      vostok::debug::on_error(
        a2,
        (bool *)&quality,
        process_error_false,
        &debug_macro_helper_ignore_always_9,
        assert_untyped,
        "assertion_failed",
        "new_link",
        ".\\resources_resource_children.cpp",
        "vostok::resources::resource_children::link_child_resource",
        0x21u);
      if ( vostok::debug::is_debugger_present() || (_BYTE)quality )
        __debugbreak();
    }
  }
}
