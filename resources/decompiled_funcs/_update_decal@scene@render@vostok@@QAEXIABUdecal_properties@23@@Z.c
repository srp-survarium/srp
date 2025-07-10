void __userpurge vostok::render::scene::update_decal(
        const vostok::render::decal_properties *properties@<edi>,
        vostok::render::decal_instance *a2@<ecx>,
        vostok::render::scene *this,
        const vostok::render::decal_properties *id)
{
  vostok::render::scene::decal_instance_node *m_first; // esi

  m_first = this->m_decals.m_first;
  LOBYTE(a2) = 0;
  if ( !m_first )
    goto LABEL_6;
  do
  {
    if ( (const vostok::render::decal_properties *)m_first->decal.m_object->m_id == id )
    {
      vostok::render::decal_instance::set_properties(
        a2,
        (const vostok::render::decal_properties *)m_first->decal.m_object);
      LOBYTE(a2) = 1;
    }
    m_first = m_first->next;
  }
  while ( m_first );
  if ( !(_BYTE)a2 )
LABEL_6:
    vostok::render::scene::add_decal(this, this, id, properties);
}
