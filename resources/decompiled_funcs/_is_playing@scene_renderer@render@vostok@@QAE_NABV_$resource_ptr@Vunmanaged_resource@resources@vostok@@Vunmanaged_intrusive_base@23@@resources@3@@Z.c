bool __usercall vostok::render::scene_renderer::is_playing@<al>(
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *instance@<eax>,
        vostok::render::scene_renderer *this)
{
  return vostok::particle::is_playing(instance);
}
