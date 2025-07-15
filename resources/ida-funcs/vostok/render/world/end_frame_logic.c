void __thiscall vostok::render::world::end_frame_logic(vostok::render::world *this)
{
  vostok::render::world *v2; // ecx
  bool v3; // zf

  vostok::render::one_way_render_channel::render_on_end_frame(
    &this->m_logic_channel,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)this);
  v3 = !this->m_is_editor_frame_ended;
  this->m_is_logic_frame_ended = 1;
  if ( !v3 )
    vostok::render::world::end_frame(v2, (int)this);
}
