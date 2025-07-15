void __userpurge vostok::collision::loose_oct_tree::render(
        vostok::collision::loose_oct_tree *this@<ecx>,
        bool a2@<dil>,
        vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene,
        vostok::render::debug::renderer *renderer)
{
  if ( this->m_initialized )
    vostok::collision::loose_oct_tree::render_iterate(
      this,
      a2,
      scene,
      renderer,
      this->m_root,
      &this->m_aabb_center,
      this->m_aabb_extents);
}
