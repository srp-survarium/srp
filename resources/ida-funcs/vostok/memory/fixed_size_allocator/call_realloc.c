void __thiscall vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::call_realloc(
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *this,
        vostok::memory::fixed_size_allocator<vostok::particle::base_particle,vostok::threading::mutex> *pointer,
        const char *new_size,
        const char *description,
        const char *const function,
        const char *const file,
        const unsigned int line)
{
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
  vostok::memory::fixed_size_allocator<vostok::resources::resource_link,vostok::threading::mutex>::call_free(
    pointer,
    pointer,
    new_size,
    description,
    (const unsigned int)function);
}
