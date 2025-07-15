void __thiscall survarium::network_client::load_replay(
        vostok::resources::vfs_sub_fat_cook *this,
        vostok::resources::vfs_sub_fat_cook *buffer)
{
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
  vostok::resources::vfs_sub_fat_cook::destroy_resource(buffer, (vostok::resources::unmanaged_resource *)buffer);
}
