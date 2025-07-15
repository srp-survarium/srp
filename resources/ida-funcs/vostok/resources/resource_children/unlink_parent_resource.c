void __usercall vostok::resources::resource_children::unlink_parent_resource(
        vostok::resources::resource_children *this@<ecx>,
        vostok::resources::resource_base *parent@<eax>)
{
  unsigned int v2; // eax
  bool do_debug_break; // [esp+Bh] [ebp-Dh] BYREF
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::resources::find_resource_link_predicate> predicate; // [esp+Ch] [ebp-Ch] BYREF
  vostok::resources::resource_base *v5; // [esp+10h] [ebp-8h] BYREF
  void *v6; // [esp+14h] [ebp-4h]

  v5 = parent;
  v6 = 0;
  if ( !debug_macro_helper_ignore_always_11 )
  {
    predicate.m_predicate_ref = (vostok::resources::find_resource_link_predicate *)&v5;
    if ( vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::remove_if<vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::resources::find_resource_link_predicate>>(
           (vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)this,
           (int)&this->m_parent_resources,
           &predicate) )
    {
      if ( v6 )
        vostok::memory::g_resources_links_allocator.call_free(
          &vostok::memory::g_resources_links_allocator,
          v6,
          "vostok::resources::resource_children::unlink_parent_resource",
          ".\\resources_resource_children.cpp",
          69u);
    }
    else
    {
      v2 = occurances_left_10;
      if ( occurances_left_10 == -1 )
        v2 = 10;
      occurances_left_10 = v2 - 1;
      if ( v2 )
      {
        if ( !debug_macro_helper_ignore_always_11 )
        {
          do_debug_break = 0;
          vostok::debug::on_error(
            &do_debug_break,
            process_error_false,
            (bool *)"m_parent_resources.remove_if(erase_predicate)",
            ".\\resources_resource_children.cpp",
            "vostok::resources::resource_children::unlink_parent_resource",
            (const char *)0x42);
          if ( vostok::debug::is_debugger_present() || do_debug_break )
            __debugbreak();
        }
      }
    }
  }
}
