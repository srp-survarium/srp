char __thiscall survarium::lobby_client::read_player_skills_tree(
        survarium::lobby_client *this,
        survarium::lobby_client *reader)
{
  int v2; // edx
  int v3; // eax
  char *v4; // ecx
  const vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  vostok::memory::base_allocator *v7; // [esp+0h] [ebp-10h]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> result; // [esp+4h] [ebp-Ch] BYREF
  vostok::mutable_buffer buffer; // [esp+8h] [ebp-8h] BYREF

  v2 = *(_DWORD *)(*(_DWORD *)this->account_nickname_ + 4);
  v3 = **(_DWORD **)this->account_nickname_;
  v4 = *(char **)&this->account_nickname_[4];
  buffer.m_size = v2 + v3 - (_DWORD)v4;
  buffer.m_data = v4;
  v5 = vostok::configs::create_binary_config(&result, &buffer, v7);
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    &reader->m_skills_tree_config,
    v5);
  if ( result.m_object && !_InterlockedExchangeAdd(&result.m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &result.m_object->vostok::resources::unmanaged_intrusive_base,
      result.m_object);
  return 1;
}
