void __userpurge vostok::render::scene::modify_model(
        vostok::render::scene *this@<ecx>,
        int a2@<ebx>,
        vostok::render::scene *a3@<esi>,
        vostok::resources::resource_ptr<vostok::render::render_model_instance_impl,vostok::resources::unmanaged_intrusive_base> v)
{
  vostok::render::render_model_instance_impl *m_object; // ecx
  vostok::render::render_model_instance_impl *v5; // [esp-Ch] [ebp-10h]

  a3->m_models_tree->move(a3->m_models_tree, &v.m_object->m_collision_object, &v.m_object->m_transform);
  v5 = 0;
  m_object = v.m_object;
  if ( v.m_object )
  {
    v5 = v.m_object;
    m_object = (vostok::render::render_model_instance_impl *)_InterlockedExchangeAdd(&v.m_object->m_reference_count, 1u);
  }
  vostok::render::scene::gather_streamable_textures(
    (vostok::render::scene *)m_object,
    a2,
    (int)&v.m_object->m_transform,
    (int)a3,
    a3,
    v5,
    1);
  if ( v.m_object )
  {
    if ( !_InterlockedExchangeAdd(&v.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::resources::unmanaged_intrusive_base::destroy(
        &v.m_object->vostok::resources::unmanaged_intrusive_base,
        v.m_object);
  }
}
