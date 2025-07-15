void __userpurge vostok::render::lights_db::add_light(
        unsigned int id@<eax>,
        long double a2@<esi:edi>,
        vostok::render::lights_db *this,
        vostok::render::light_props *props)
{
  vostok::render::light_data *m_begin; // ecx
  int v5; // eax
  int v6; // eax
  int v7; // edx
  vostok::render::light *v8; // eax
  vostok::buffer_vector<vostok::render::light_data> *v10; // [esp-4h] [ebp-1Ch]
  unsigned int count; // [esp+Ch] [ebp-Ch] BYREF
  vostok::render::light_data value; // [esp+10h] [ebp-8h] BYREF

  LODWORD(a2) = id;
  if ( props->type == light_type_parallel )
  {
    this->m_sun_id = id;
  }
  else
  {
    m_begin = this->m_lights.m_begin;
    v5 = (char *)this->m_lights.m_end - (char *)this->m_lights.m_begin;
    value.id = LODWORD(a2);
    v6 = v5 >> 3;
    while ( v6 > 0 )
    {
      v7 = v6 >> 1;
      HIDWORD(a2) = &m_begin[v6 >> 1];
      if ( *(_DWORD *)(HIDWORD(a2) + 4) >= LODWORD(a2) )
      {
        v6 >>= 1;
      }
      else
      {
        m_begin = (vostok::render::light_data *)(HIDWORD(a2) + 8);
        HIDWORD(a2) = -1 - v7;
        v6 += -1 - v7;
      }
    }
    count = (unsigned int)m_begin;
    v8 = vostok::render::lights_db::create(
           (vostok::render::lights_db *)m_begin,
           (const vostok::render::lights_db::tree_operation_enum)this);
    LODWORD(a2) = 0;
    if ( v8 )
    {
      ++v8->m_reference_count;
      LODWORD(a2) = v8;
    }
    value.light.m_object = (vostok::render::light *)LODWORD(a2);
    vostok::render::fill_light(a2, (vostok::render::light *)LODWORD(a2), props);
    vostok::buffer_vector<vostok::render::light_data>::insert(
      v10,
      &this->m_lights.m_begin,
      (vostok::render::light ***)&count,
      &value);
    if ( LODWORD(a2) )
    {
      if ( (*(_DWORD *)LODWORD(a2))-- == 1 )
        vostok::render::resource_intrusive_base::destroy<vostok::render::light>((const vostok::render::light *const)LODWORD(a2));
    }
  }
}
