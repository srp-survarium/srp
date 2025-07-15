void __usercall vostok::render::buffers_handler<2>::assign(
        vostok::render::buffers_handler<0> *this@<ecx>,
        const vostok::render::res_buffer_list *list@<esi>)
{
  unsigned int v2; // eax
  unsigned int v3; // edx
  unsigned __int64 v4; // kr00_8
  const vostok::render::res_buffer_list *v5; // edx
  const vostok::render::res_buffer_list *m_object; // eax

  if ( this->m_current.m_object )
    v2 = this->m_current.m_object->m_container.m_end - this->m_current.m_object->m_container.m_begin;
  else
    v2 = 0;
  if ( list )
    v3 = list->m_container.m_end - list->m_container.m_begin;
  else
    v3 = 0;
  this->m_diff_range_start = 0;
  v4 = this->m_diff_range_end - (unsigned __int64)(v2 - (v2 < v3 ? v2 - v3 : 0));
  v5 = 0;
  this->m_diff_range_end -= v4 & HIDWORD(v4);
  if ( list )
  {
    ++list->m_reference_count;
    v5 = list;
  }
  m_object = this->m_current.m_object;
  this->m_current.m_object = v5;
  if ( m_object )
    --m_object->m_reference_count;
}
