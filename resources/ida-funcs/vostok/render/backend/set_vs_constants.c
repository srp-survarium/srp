void __usercall vostok::render::backend::set_vs_constants(
        vostok::render::backend *this@<esi>,
        vostok::render::shader_constant_table *ctable@<eax>)
{
  unsigned int m_constant_update_counter; // eax

  if ( this->m_vs_constants_handler.m_current.m_object != ctable )
  {
    ++this->num_vsc_changes;
    vostok::render::constants_handler<0>::assign(&this->m_vs_constants_handler, ctable);
    m_constant_update_counter = this->m_constant_update_counter;
    this->m_dirty_objects.vertex_constants = 1;
    this->m_constant_update_markers[0] = m_constant_update_counter;
  }
}
