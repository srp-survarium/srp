bool __usercall vostok::render::engine::world::is_playing@<al>(
        const vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *instance@<eax>,
        vostok::render::engine::world *this)
{
  return vostok::particle::is_playing(instance);
}
