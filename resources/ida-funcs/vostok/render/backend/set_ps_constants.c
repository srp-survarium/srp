void __usercall vostok::render::backend::set_ps_constants(
        vostok::render::backend *this@<esi>,
        vostok::render::shader_constant_table *ctable@<eax>)
{
  unsigned int m_constant_update_counter; // eax

  if ( this->m_ps_constants_handler.m_current.m_object != ctable )
  {
    ++this->num_psc_changes;
    vostok::render::constants_handler<1>::assign(&this->m_ps_constants_handler, ctable);
    m_constant_update_counter = this->m_constant_update_counter;
    this->m_dirty_objects.pixel_constants = 1;
    this->m_constant_update_markers[1] = m_constant_update_counter;
  }
}
