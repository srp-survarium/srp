void __thiscall vostok::memory::_dynamic_atexit_destructor_for__g_resources_links_allocator__(
        vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex> *this)
{
  vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::~fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>(
    this,
    &vostok::memory::g_resources_links_allocator);
}
