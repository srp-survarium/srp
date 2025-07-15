vostok::render::ui::draw_vertices_command *__thiscall vostok::render::ui::draw_vertices_command::`scalar deleting destructor'(
        vostok::render::ui::draw_vertices_command *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_scene_view);
  this->m_vertices.m_end = this->m_vertices.m_begin;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
