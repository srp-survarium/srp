vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *__thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::`scalar deleting destructor'(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this,
        char a2)
{
  vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::~fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>(
    this,
    this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
