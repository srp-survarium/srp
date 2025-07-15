void __thiscall vostok::render::engine::world::set_slomo(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        unsigned int time_multiplier)
{
  scene->m_object[3].m_current_quality_level = time_multiplier;
}
