void __thiscall vostok::resources::query_result::~query_result(vostok::resources::query_result *this)
{
  vostok::resources::class_id_enum m_class_id; // eax
  vostok::vfs::base_node<1> *v3; // eax
  vostok::resources::vfs_sub_fat_resource *m_object; // eax
  vostok::vfs::vfs_iterator result; // [esp+10h] [ebp-10h] BYREF

  m_class_id = this->m_class_id;
  this->__vftable = (vostok::resources::query_result_vtbl *)&vostok::resources::query_result::`vftable';
  if ( m_class_id == fs_iterator_class || m_class_id == fs_iterator_recursive_class )
    vostok::vfs::vfs_iterator::operator bool(&this->m_result_iterator);
  vostok::resources::query_result::clear_reference(this, (int)this);
  if ( (this->m_flags & 0x800) != 0 )
  {
    v3 = vostok::mutable_buffer::size(&this->m_fat_it);
    vostok::vfs::destroy_temp_physical_node(v3);
    this->m_fat_it = *vostok::vfs::vfs_iterator::end(&result);
    vostok::threading::interlocked_and(&this->m_flags, 0xFFFFF7FF);
  }
  if ( (this->m_flags & 0x400) != 0 )
  {
    if ( this->m_request_path )
    {
      this->m_user_allocator->call_free(this->m_user_allocator, this->m_request_path);
      this->m_request_path = 0;
    }
    vostok::threading::interlocked_and(&this->m_flags, 0xFFFFFBFF);
  }
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_raw_managed_resource);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&this->m_compressed_resource);
  m_object = this->m_sub_fat.m_object;
  if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      &this->m_sub_fat.m_object->vostok::resources::unmanaged_intrusive_base,
      this->m_sub_fat.m_object);
  vostok::resources::query_result_for_cook::~query_result_for_cook(this);
}
