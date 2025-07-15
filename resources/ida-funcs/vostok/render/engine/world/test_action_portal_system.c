void __thiscall vostok::render::engine::world::test_action_portal_system(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *scene)
{
  vostok::resources::class_id_enum m_class_id; // eax

  m_class_id = scene->m_object[3].m_class_id;
  if ( m_class_id )
    *(_BYTE *)(m_class_id + 280) = 1;
}
