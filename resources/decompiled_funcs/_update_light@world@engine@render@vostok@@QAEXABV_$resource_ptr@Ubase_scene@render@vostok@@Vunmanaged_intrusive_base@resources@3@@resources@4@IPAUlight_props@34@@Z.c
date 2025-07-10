void __thiscall vostok::render::engine::world::update_light(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        unsigned int id,
        vostok::render::light_props *props)
{
  vostok::render::light_data **m_next_in_increase_quality_queue; // eax
  vostok::render::light_data *v5; // eax
  unsigned int __val; // [esp+4h] [ebp-4h] BYREF

  m_next_in_increase_quality_queue = (vostok::render::light_data **)in_scene->m_object[3].m_next_in_increase_quality_queue;
  __val = id;
  v5 = stlp_std::priv::__lower_bound<vostok::render::light_data *,unsigned int,stlp_std::priv::__less_2<vostok::render::light_data,unsigned int>,stlp_std::priv::__less_2<unsigned int,vostok::render::light_data>,int>(
         m_next_in_increase_quality_queue[1],
         &__val,
         *m_next_in_increase_quality_queue);
  vostok::render::fill_light(v5->light.m_object, props);
}
