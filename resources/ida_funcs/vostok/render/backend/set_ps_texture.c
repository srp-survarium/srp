void __usercall vostok::render::backend::set_ps_texture(
        vostok::render::backend *this@<esi>,
        vostok::render::textures_handler<0> *name@<ecx>)
{
  this->m_dirty_objects.pixel_textures = vostok::render::textures_handler<0>::set_overwrite(
                                           name,
                                           (const char *)&this->m_ps_textures_handler,
                                           (vostok::render::res_texture *)name);
}
