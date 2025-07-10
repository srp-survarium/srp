vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *__thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::`scalar deleting destructor'(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        char a2)
{
  this->__vftable = (vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>_vtbl *)&vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::`vftable';
  this->m_allocator.m_initialized = 0;
  this->__vftable = (vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>_vtbl *)&vostok::memory::base_allocator::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
