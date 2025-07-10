void __thiscall vostok::collision::colliders::cuboid_object::add_objects_by_callback(
        vostok::collision::colliders::cuboid_object *this,
        const vostok::collision::oct_node *const node)
{
  const vostok::collision::oct_node *v3; // esi
  vostok::collision::object *i; // esi
  boost::function<void __cdecl(vostok::collision::object const &)> *m_callback; // edi
  survarium::game_camera *v6; // eax
  boost::bad_function_call v7; // [esp+10h] [ebp-110h] BYREF

  v3 = node;
  do
  {
    if ( v3->octants[0] )
      vostok::collision::colliders::cuboid_object::add_objects_by_callback(this, v3->octants[0]);
    v3 = (const vostok::collision::oct_node *)((char *)v3 + 4);
  }
  while ( v3 != (const vostok::collision::oct_node *)&node->parent );
  for ( i = node->objects; i; i = i->m_next )
  {
    if ( (i->m_type & this->m_query_type) != 0 )
    {
      m_callback = this->m_callback;
      if ( !m_callback->vtable )
      {
        boost::bad_function_call::bad_function_call(&v7);
        boost::throw_exception(v6);
        stlp_std::__Named_exception::~__Named_exception((stlp_std::out_of_range *)&v7);
      }
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, vostok::collision::object *))(((int)m_callback->vtable & 0xFFFFFFFE) + 4))(
        &m_callback->functor,
        i);
    }
  }
}
