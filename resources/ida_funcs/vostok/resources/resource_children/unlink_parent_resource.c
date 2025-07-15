void __userpurge vostok::resources::resource_children::unlink_parent_resource(
        vostok::resources::resource_children *this@<ecx>,
        unsigned int a2@<ebx>,
        vostok::resources::resource_base *parent)
{
  unsigned int v3; // eax
  vostok::resources::find_resource_link_predicate erase_predicate; // [esp+8h] [ebp-8h] BYREF

  erase_predicate.resource_ = parent;
  erase_predicate.found_link_ = 0;
  if ( !debug_macro_helper_ignore_always_10 )
  {
    parent = (vostok::resources::resource_base *)&erase_predicate;
    if ( vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::remove_if<vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::resources::find_resource_link_predicate>>(
           (vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)this,
           (int)&this->m_parent_resources,
           (const vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy>::bool_predicate_ref<vostok::resources::find_resource_link_predicate> *)&parent) )
    {
      if ( erase_predicate.found_link_ )
        vostok::memory::g_resources_links_allocator.call_free(
          &vostok::memory::g_resources_links_allocator,
          erase_predicate.found_link_);
    }
    else
    {
      v3 = occurances_left_10;
      if ( occurances_left_10 == -1 )
        v3 = 10;
      occurances_left_10 = v3 - 1;
      if ( v3 )
      {
        if ( !debug_macro_helper_ignore_always_10 )
        {
          LOBYTE(parent) = 0;
          vostok::debug::on_error(
            a2,
            (bool *)&parent,
            process_error_false,
            &debug_macro_helper_ignore_always_10,
            assert_untyped,
            "assertion_failed",
            "m_parent_resources.remove_if(erase_predicate)",
            ".\\resources_resource_children.cpp",
            "vostok::resources::resource_children::unlink_parent_resource",
            0x42u);
          if ( vostok::debug::is_debugger_present() || (_BYTE)parent )
            __debugbreak();
        }
      }
    }
  }
}
