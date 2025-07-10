vostok::render::res_texture *__thiscall vostok::render::resource_manager::get_color_grading_base_lut(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *result,
        vostok::render::res_texture *a3)
{
  vostok::render::res_texture *v3; // ebp
  vostok::render::res_texture *m_object; // eax
  vostok::render::res_texture *v5; // ecx
  vostok::render::res_texture *v6; // esi
  bool v7; // zf
  vostok::render::res_texture *v8; // eax

  v3 = a3;
  if ( !result->m_color_grading_base_lut.m_object )
  {
    m_object = vostok::render::create_color_grading_base_lut(&a3)->m_object;
    v5 = 0;
    if ( m_object )
    {
      v5 = m_object;
      ++m_object->m_reference_count;
    }
    v6 = result->m_color_grading_base_lut.m_object;
    result->m_color_grading_base_lut.m_object = v5;
    if ( v6 )
    {
      v7 = v6->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::res_texture::destroy_impl(v5, v6);
    }
    if ( a3 )
    {
      v7 = a3->m_reference_count-- == 1;
      if ( v7 )
        vostok::render::res_texture::destroy_impl(v5, a3);
    }
  }
  v8 = result->m_color_grading_base_lut.m_object;
  v3->__vftable = 0;
  if ( v8 )
  {
    ++v8->m_reference_count;
    v3->__vftable = (vostok::render::res_texture_vtbl *)v8;
  }
  return v3;
}
