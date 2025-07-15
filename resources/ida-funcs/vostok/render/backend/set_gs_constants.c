void __usercall vostok::render::backend::set_gs_constants(
        vostok::render::backend *this@<esi>,
        vostok::render::shader_constant_table *ctable@<eax>)
{
  unsigned int m_constant_update_counter; // eax

  if ( this->m_gs_constants_handler.m_current.m_object != ctable )
  {
    vostok::render::constants_handler<2>::assign(&this->m_gs_constants_handler, ctable);
    m_constant_update_counter = this->m_constant_update_counter;
    this->m_dirty_objects.geometry_constants = 1;
    this->m_constant_update_markers[2] = m_constant_update_counter;
  }
}
