vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *__userpurge vostok::resources::query_result::pin_raw_file@<eax>(
        vostok::resources::query_result *this@<ecx>,
        vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *a2@<edi>,
        vostok::resources::query_result *result)
{
  const char *m_offset_to_file; // ebp
  vostok::mutable_buffer *v4; // eax
  vostok::sound::encoded_sound_interface *m_size; // edx
  vostok::vfs::base_node<1> *file_size; // eax
  char *m_data; // eax
  vostok::vfs::base_node<1> *v8; // esi
  vostok::sound::encoded_sound_interface *v9; // eax
  vostok::mutable_buffer v11; // [esp+10h] [ebp-8h] BYREF

  m_offset_to_file = (const char *)result->m_offset_to_file;
  v4 = vostok::resources::query_result::pin_raw_buffer(this, (int)result, &v11);
  a2->m_object = (vostok::sound::encoded_sound_interface *)v4->m_data;
  m_size = (vostok::sound::encoded_sound_interface *)v4->m_size;
  a2->m_object = (vostok::sound::encoded_sound_interface *)((char *)a2->m_object + (unsigned int)m_offset_to_file);
  a2[1].m_object = m_size;
  a2[1].m_object = (vostok::sound::encoded_sound_interface *)((char *)a2[1].m_object - m_offset_to_file);
  if ( result->m_fat_it.m_node )
  {
    file_size = (vostok::vfs::base_node<1> *)vostok::vfs::vfs_iterator::get_file_size(&result->m_fat_it);
  }
  else
  {
    m_data = (char *)result->m_creation_data_from_user.m_data;
    v11.m_size = result->m_creation_data_from_user.m_size;
    v11.m_data = m_data;
    file_size = vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)&v11);
  }
  v8 = file_size;
  v9 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr(a2);
  a2[1].m_object = (vostok::sound::encoded_sound_interface *)v8;
  a2->m_object = v9;
  return a2;
}
