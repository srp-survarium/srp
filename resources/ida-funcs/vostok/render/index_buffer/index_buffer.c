void __usercall vostok::render::index_buffer::index_buffer(
        vostok::render::index_buffer *this@<esi>,
        unsigned int size@<eax>)
{
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v2; // eax
  vostok::render::resource_manager *v3; // [esp-18h] [ebp-1Ch]

  v3 = vostok::quasi_singleton<vostok::render::resource_manager>::pinst;
  this->m_buffer.m_object = 0;
  this->m_size = size;
  this->m_position = 0;
  this->m_discard_id = 0;
  this->m_lock_size = 0;
  vostok::render::resource_manager::create_buffer(size, v3, (void *)1, enum_buffer_type_vertex, 1, 1, 0);
  vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    v2,
    (vostok::intrusive_ptr<vostok::render::untyped_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)this,
    (vostok::render::hw_buffer_pool *)this);
}
