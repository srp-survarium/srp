void __userpurge vostok::resources::resource_children::link_child_resource(
        vostok::resources::resource_children *this@<ecx>,
        int a3@<edi>,
        int a4@<esi>,
        vostok::resources::resource_base *child,
        vostok::threading::simple_lock *quality)
{
  char *v6; // eax
  vostok::resources::resource_link *v7; // eax
  unsigned int v8; // eax
  vostok::threading::simple_lock *v9; // ecx

  if ( quality != (vostok::threading::simple_lock *)-1 )
    _InterlockedOr(&child->m_flags.m_flags, 0x100u);
  v6 = type_info::raw_name(&vostok::resources::resource_link `RTTI Type Descriptor');
  v7 = (vostok::resources::resource_link *)((int (__thiscall *)(vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *, int, char *, const char *, const char *, int, int, int))vostok::memory::g_resources_links_allocator.call_malloc)(
                                             &vostok::memory::g_resources_links_allocator,
                                             12,
                                             v6,
                                             "vostok::resources::resource_children::link_child_resource",
                                             ".\\resources_resource_children.cpp",
                                             32,
                                             a3,
                                             a4);
  if ( v7 )
  {
    v7->quality_value = -1;
    v7->resource = 0;
    v7->next_link = 0;
  }
  else
  {
    v7 = 0;
  }
  if ( debug_macro_helper_ignore_always_10 || v7 )
  {
    v7->resource = child;
    v9 = quality;
    v7->quality_value = (unsigned int)quality;
    vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &this->m_children_resources,
      v7,
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
      HIBYTE(child) = 0;
      vostok::debug::on_error(
        (bool *)&child + 3,
        process_error_false,
        (bool *)"new_link",
        ".\\resources_resource_children.cpp",
        "vostok::resources::resource_children::link_child_resource",
        (const char *)0x21);
      if ( vostok::debug::is_debugger_present() || HIBYTE(child) )
        __debugbreak();
    }
  }
}
