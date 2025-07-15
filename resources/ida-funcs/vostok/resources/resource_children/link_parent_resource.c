void __thiscall vostok::resources::resource_children::link_parent_resource(
        vostok::resources::resource_children *this,
        vostok::resources::resource_base *parent,
        vostok::resources::resource_base *quality,
        vostok::threading::simple_lock *a4)
{
  char *v4; // eax
  vostok::resources::resource_link *v5; // eax
  unsigned int v6; // eax
  vostok::threading::simple_lock *v7; // ecx

  v4 = type_info::raw_name(&vostok::resources::resource_link `RTTI Type Descriptor');
  v5 = (vostok::resources::resource_link *)vostok::memory::g_resources_links_allocator.call_malloc(
                                             &vostok::memory::g_resources_links_allocator,
                                             12,
                                             v4,
                                             "vostok::resources::resource_children::link_parent_resource",
                                             ".\\resources_resource_children.cpp",
                                             18);
  if ( v5 )
  {
    v5->quality_value = -1;
    v5->resource = 0;
    v5->next_link = 0;
  }
  else
  {
    v5 = 0;
  }
  if ( debug_macro_helper_ignore_always_9 || v5 )
  {
    v5->resource = quality;
    v7 = a4;
    v5->quality_value = (unsigned int)a4;
    vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &parent->m_parent_resources,
      v5,
      v7);
  }
  else
  {
    v6 = occurances_left_8;
    if ( occurances_left_8 == -1 )
      v6 = 10;
    occurances_left_8 = v6 - 1;
    if ( v6 )
    {
      HIBYTE(quality) = 0;
      vostok::debug::on_error(
        (bool *)&quality + 3,
        process_error_false,
        (bool *)"new_link",
        ".\\resources_resource_children.cpp",
        "vostok::resources::resource_children::link_parent_resource",
        (const char *)0x13);
      if ( vostok::debug::is_debugger_present() || HIBYTE(quality) )
        __debugbreak();
    }
  }
}
