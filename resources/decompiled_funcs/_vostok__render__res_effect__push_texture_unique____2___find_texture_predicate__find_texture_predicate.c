void __usercall vostok::render::res_effect::push_texture_unique_::_2_::find_texture_predicate::find_texture_predicate(
        vostok::render::res_effect::push_texture_unique::__l2::find_texture_predicate *this@<ecx>,
        vostok::render::res_texture **a2@<eax>)
{
  vostok::render::res_texture *m_object; // ecx

  *a2 = 0;
  m_object = this->m_texture.m_object;
  if ( m_object )
  {
    *a2 = m_object;
    ++m_object->m_reference_count;
  }
}
