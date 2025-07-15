void __userpurge vostok::resources::resource_children::link_parent_resource(
        vostok::resources::resource_children *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *parent,
        unsigned int quality)
{
  vostok::resources::resource_link *v5; // eax
  unsigned int v6; // eax
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *v7; // ecx
  unsigned int v8; // edx
  bool *v9; // [esp+0h] [ebp-4h]

  v5 = (vostok::resources::resource_link *)vostok::memory::g_resources_links_allocator.call_malloc(
                                             &vostok::memory::g_resources_links_allocator,
                                             12);
  if ( v5 )
  {
    v5->resource = 0;
    v5->next_link = 0;
    v5->quality_value = -1;
  }
  else
  {
    v5 = 0;
  }
  if ( debug_macro_helper_ignore_always_8 || v5 )
  {
    v7 = parent;
    v8 = quality;
    v5->resource = (vostok::resources::resource_base *)parent;
    v5->quality_value = v8;
    vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::push_back(
      v7,
      &this->m_parent_resources.m_size,
      v5,
      v9);
  }
  else
  {
    v6 = occurances_left_8;
    if ( occurances_left_8 == -1 )
      v6 = 10;
    occurances_left_8 = v6 - 1;
    if ( v6 )
    {
      LOBYTE(parent) = 0;
      vostok::debug::on_error(
        a2,
        (bool *)&parent,
        process_error_false,
        &debug_macro_helper_ignore_always_8,
        assert_untyped,
        "assertion_failed",
        "new_link",
        ".\\resources_resource_children.cpp",
        "vostok::resources::resource_children::link_parent_resource",
        0x13u);
      if ( vostok::debug::is_debugger_present() || (_BYTE)parent )
        __debugbreak();
    }
  }
}
