vostok::math::sphere *__thiscall vostok::render::render_surface_texture_instance_proxy::bound_sphere(
        vostok::render::render_surface_texture_instance_proxy *this,
        vostok::math::sphere *result)
{
  vostok::render::render_surface_instance::get_bound_sphere(
    (vostok::render::render_surface_instance *)this,
    (vostok::math::sphere *)this->m_surface,
    result);
  return result;
}
