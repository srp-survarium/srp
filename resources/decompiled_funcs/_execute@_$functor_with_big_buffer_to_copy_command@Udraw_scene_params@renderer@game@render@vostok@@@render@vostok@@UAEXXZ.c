void __thiscall vostok::render::functor_with_big_buffer_to_copy_command<vostok::render::game::renderer::draw_scene_params>::execute(
        vostok::render::functor_with_big_buffer_to_copy_command<vostok::math::float4x4> *this)
{
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(
    (boost::function1<void,char const *> *)this,
    &this->m_on_execute.vtable,
    (const char *)&this->m_data);
}
