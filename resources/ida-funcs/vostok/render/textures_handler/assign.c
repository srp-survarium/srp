void __usercall vostok::render::textures_handler<0>::assign(
        vostok::render::textures_handler<0> *this@<ecx>,
        vostok::render::res_texture_list *list@<eax>)
{
  unsigned int v3; // ecx
  unsigned int v4; // edx
  unsigned __int64 v5; // kr00_8

  if ( this->m_current.m_object )
    v3 = this->m_current.m_object->m_container.m_end - this->m_current.m_object->m_container.m_begin;
  else
    v3 = 0;
  if ( list )
    v4 = list->m_container.m_end - list->m_container.m_begin;
  else
    v4 = 0;
  this->m_diff_range_start = 0;
  v5 = this->m_diff_range_end - (unsigned __int64)(v3 - (v3 < v4 ? v3 - v4 : 0));
  this->m_diff_range_end -= v5 & HIDWORD(v5);
  vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::operator=(
    (vostok::intrusive_ptr<vostok::render::res_texture_list,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)this,
    list);
}
