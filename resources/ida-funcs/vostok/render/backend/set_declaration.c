void __usercall vostok::render::backend::set_declaration(
        vostok::render::backend *this@<eax>,
        vostok::render::res_declaration *decl@<edx>)
{
  if ( this->m_decl == decl )
  {
    this->m_dirty_objects.input_layout = 0;
  }
  else
  {
    this->m_input_layout = 0;
    this->m_decl = decl;
    this->m_dirty_objects.input_declaration = 1;
    this->m_dirty_objects.input_layout = 1;
  }
}
