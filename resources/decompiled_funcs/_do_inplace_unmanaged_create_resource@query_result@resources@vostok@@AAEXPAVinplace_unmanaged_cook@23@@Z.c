void __usercall vostok::resources::query_result::do_inplace_unmanaged_create_resource(
        vostok::resources::query_result *this@<ecx>,
        vostok::resources::inplace_unmanaged_cook *cook@<eax>)
{
  bool resource_inplace_in_creation_or_inline_data; // bl
  vostok::vfs::base_node<1> *v5; // eax
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> *v6; // eax
  vostok::resources::query_result *v7; // ecx
  vostok::resources::cook_base::result_enum m_create_resource_result; // eax
  unsigned int v9; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_m_unmanaged_resource; // ebx
  vostok::vfs::vfs_iterator *v12; // ebp
  vostok::resources::unmanaged_resource *v13; // ecx
  vostok::resources::query_result *v14; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v15; // [esp-4h] [ebp-48h] BYREF
  bool do_debug_break; // [esp+17h] [ebp-2Dh] BYREF
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> delegate; // [esp+18h] [ebp-2Ch] BYREF
  _BYTE v18[4]; // [esp+20h] [ebp-24h] BYREF
  __int64 v19; // [esp+24h] [ebp-20h] BYREF
  vostok::vfs::vfs_iterator v20; // [esp+30h] [ebp-14h] BYREF

  resource_inplace_in_creation_or_inline_data = vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(
                                                  this,
                                                  (int)this);
  if ( resource_inplace_in_creation_or_inline_data )
  {
    if ( this->m_fat_it.m_node
      && (v5 = vostok::vfs::vfs_iterator::data_node(&this->m_fat_it), vostok::vfs::base_node<1>::is_inlined(v5))
      && !vostok::vfs::vfs_iterator::is_compressed(&this->m_fat_it) )
    {
      v6 = cook->get_create_resource_inplace_in_inline_fat_delegate(cook, v18);
    }
    else
    {
      v6 = cook->get_create_resource_inplace_in_creation_data_delegate(cook, (char *)&v19 + 4);
    }
    ((void (__thiscall *)(fastdelegate::detail::GenericClass *, vostok::resources::query_result *, char *, unsigned int))v6->m_Closure.m_pFunction)(
      v6->m_Closure.m_pthis,
      this,
      this->m_raw_unmanaged_buffer.m_data,
      this->m_raw_unmanaged_buffer.m_size);
  }
  else if ( this->m_fat_it.m_node
         || this->m_creation_data_from_user.m_data
         || this->m_creation_data_from_user.m_size
         || (this->m_flags & 0x2000) != 0 )
  {
    ((void (__thiscall *)(vostok::resources::inplace_unmanaged_cook *, vostok::resources::query_result *, char *, unsigned int))cook->create_resource)(
      cook,
      this,
      this->m_raw_unmanaged_buffer.m_data,
      this->m_raw_unmanaged_buffer.m_size);
  }
  else
  {
    cook->get_create_resource_if_no_file_delegate(cook, &delegate);
    ((void (__thiscall *)(fastdelegate::detail::GenericClass *, vostok::resources::query_result *, char *, unsigned int))delegate.m_Closure.m_pFunction)(
      delegate.m_Closure.m_pthis,
      this,
      this->m_raw_unmanaged_buffer.m_data,
      this->m_raw_unmanaged_buffer.m_size);
  }
  m_create_resource_result = this->m_create_resource_result;
  if ( m_create_resource_result != result_postponed
    && m_create_resource_result != result_requery
    && (this->m_flags & 0x8000) == 0 )
  {
    if ( debug_macro_helper_ignore_always_19 || this->m_unmanaged_resource.m_object )
    {
      if ( resource_inplace_in_creation_or_inline_data
        && vostok::resources::query_result::has_uncompressed_inline_data(v7, (vostok::vfs::vfs_iterator *)this) )
      {
        m_object = this->m_unmanaged_resource.m_object;
        p_m_unmanaged_resource = &this->m_unmanaged_resource;
        m_object->m_inlined_in_fat = 1;
        v7 = (vostok::resources::query_result *)_InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      else
      {
        p_m_unmanaged_resource = &this->m_unmanaged_resource;
        if ( !this->m_unmanaged_resource.m_object->m_deleter )
          vostok::resources::query_result::set_deleter_object(v7, this->m_unmanaged_resource.m_object);
      }
      v12 = (vostok::vfs::vfs_iterator *)p_m_unmanaged_resource->m_object;
      if ( p_m_unmanaged_resource->m_object->m_creation_source == creation_source_unset )
      {
        vostok::resources::query_result::get_fat_it_zero_if_physical_path_it(
          v7,
          (const vostok::vfs::vfs_iterator *)this,
          &v20);
        v15.m_object = v13;
        v12[10] = v20;
        boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
          &v15,
          p_m_unmanaged_resource);
        vostok::resources::query_result::set_creation_source_for_resource(v14, (int)this, v15);
      }
    }
    else
    {
      v9 = occurances_left_19;
      if ( occurances_left_19 == -1 )
        v9 = 10;
      occurances_left_19 = v9 - 1;
      if ( v9 )
      {
        do_debug_break = 0;
        vostok::debug::on_error(
          resource_inplace_in_creation_or_inline_data,
          &do_debug_break,
          process_error_false,
          &debug_macro_helper_ignore_always_19,
          assert_untyped,
          "assertion_failed",
          "m_unmanaged_resource",
          ".\\resources_query_result_cook.cpp",
          "vostok::resources::query_result::do_inplace_unmanaged_create_resource",
          0xA2u,
          "cook::create_resource should have called query.set_unmanaged_resource or query.set_zero_unmanaged_resource");
        if ( vostok::debug::is_debugger_present() || do_debug_break )
          __debugbreak();
      }
    }
  }
}
