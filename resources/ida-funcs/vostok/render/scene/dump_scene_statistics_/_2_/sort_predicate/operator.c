BOOL __usercall vostok::render::scene::dump_scene_statistics_::_2_::sort_predicate::operator()@<eax>(
        const vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *left@<eax>,
        const vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> *right@<ecx>,
        vostok::render::scene::dump_scene_statistics::__l2::sort_predicate *this)
{
  vostok::render::render_model_instance_impl *m_object; // esi
  unsigned int v4; // edi

  m_object = left->m_object;
  v4 = right->m_object->get_surfaces_count(right->m_object);
  return v4 < m_object->get_surfaces_count(m_object);
}
