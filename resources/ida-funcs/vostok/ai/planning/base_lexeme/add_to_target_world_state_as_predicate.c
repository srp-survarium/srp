void __thiscall vostok::ai::planning::base_lexeme::add_to_target_world_state_as_predicate(
        survarium::network_client *this,
        char *map_name,
        Scaleform::SysAllocMalloc *director,
        unsigned int a4,
        Scaleform::DefaultAcquireInterface *a5)
{
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
  Scaleform::SysAllocMalloc::Realloc(director, (unsigned int)map_name, (unsigned int)director, a4, a5);
}
