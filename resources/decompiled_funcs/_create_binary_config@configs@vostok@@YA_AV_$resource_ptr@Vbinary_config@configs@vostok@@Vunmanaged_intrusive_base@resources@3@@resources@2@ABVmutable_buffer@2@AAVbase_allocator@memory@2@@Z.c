vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *__cdecl vostok::configs::create_binary_config(
        vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *result,
        vostok::vfs::vfs_iterator *buffer)
{
  vostok::memory::base_allocator *f; // edi
  vostok::core::configs::binary_config *v4; // esi
  vostok::vfs::base_node<1> *v5; // eax
  int v6; // eax
  int v7; // esi
  vostok::resources::resources_manager *v8; // ecx
  vostok::resources::unmanaged_resource *binary_config_cook; // edi
  vostok::vfs::base_node<1> *v10; // eax
  unsigned int v12; // [esp+0h] [ebp-14h]
  unsigned __int8 *resulta; // [esp+18h] [ebp+4h]
  vostok::resources::cook_base *resultb; // [esp+18h] [ebp+4h]

  f = (vostok::memory::base_allocator *)survarium::g_allocator.f_.f_;
  v4 = (vostok::core::configs::binary_config *)(*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)LODWORD(survarium::g_allocator.f_.f_)
                                                                                  + 16))(
                                                 survarium::g_allocator.f_.f_,
                                                 280);
  if ( v4 )
  {
    resulta = (unsigned __int8 *)buffer->m_hashset;
    v5 = vostok::mutable_buffer::size(buffer);
    vostok::core::configs::binary_config::binary_config(v4, f, resulta, (unsigned int)v5);
    v7 = v6;
  }
  else
  {
    v7 = 0;
  }
  resultb = (vostok::resources::cook_base *)GetCurrentThreadId();
  binary_config_cook = (vostok::resources::unmanaged_resource *)vostok::resources::resources_manager::get_binary_config_cook(v8);
  vostok::resources::unmanaged_resource::set_deleter_object(binary_config_cook, (_DWORD *)v7, resultb, v12);
  *(_DWORD *)(v7 + 132) = binary_config_cook->vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
  v10 = vostok::mutable_buffer::size(buffer);
  *(_DWORD *)(v7 + 192) = 4;
  *(_DWORD *)(v7 + 88) = &vostok::resources::nocache_memory;
  *(_DWORD *)(v7 + 92) = v10;
  result->m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    result,
    (vostok::configs::binary_config *)v7);
  return result;
}
