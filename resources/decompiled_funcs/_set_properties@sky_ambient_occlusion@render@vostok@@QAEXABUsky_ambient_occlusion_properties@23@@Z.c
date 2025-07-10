void __userpurge vostok::render::sky_ambient_occlusion::set_properties(
        const vostok::render::sky_ambient_occlusion_properties *in_properties@<eax>,
        vostok::render::sky_ambient_occlusion *this)
{
  vostok::render::res_texture *v3; // ecx
  vostok::render::res_texture *m_object; // esi
  bool v5; // zf
  stlp_std::priv::_Rb_tree_node_base *texture; // eax
  vostok::render::res_texture *v7; // ecx
  vostok::render::res_texture *v8; // esi
  const vostok::math::float4x4 *v9; // ecx
  __int64 v10; // xmm0_8
  vostok::math::float3 scale; // [esp+Ch] [ebp-64h] BYREF
  __int128 v12; // [esp+20h] [ebp-50h]
  vostok::math::float4x4 new_transform; // [esp+30h] [ebp-40h] BYREF

  vostok::render::sky_ambient_occlusion_properties::operator=(&this->m_properties, in_properties);
  if ( in_properties->texture_invalidated )
  {
    m_object = this->m_texture.m_object;
    this->m_texture.m_object = 0;
    if ( m_object )
    {
      v5 = m_object->m_reference_count-- == 1;
      if ( v5 )
        vostok::render::res_texture::destroy_impl(v3, m_object);
    }
    texture = vostok::render::resource_manager::create_texture(
                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                this->m_properties.texture_name.m_buffer,
                0,
                0,
                0,
                1,
                1,
                0xFFFFFFFF);
    v7 = 0;
    if ( texture )
    {
      ++texture->_M_parent;
      v7 = (vostok::render::res_texture *)texture;
    }
    v8 = this->m_texture.m_object;
    this->m_texture.m_object = v7;
    if ( v8 )
    {
      v5 = v8->m_reference_count-- == 1;
      if ( v5 )
        vostok::render::res_texture::destroy_impl(v7, v8);
    }
  }
  vostok::math::create_translation(&new_transform, &in_properties->location);
  scale.x = in_properties->width;
  scale.y = in_properties->depth;
  scale.z = in_properties->height;
  vostok::math::float4x4::set_scale(&new_transform, &scale);
  LODWORD(scale.z) = clear_value;
  v9 = clear_value;
  LODWORD(scale.x) = clear_value;
  LODWORD(scale.y) = clear_value;
  LODWORD(v12) = -1082130432;
  *(_QWORD *)((char *)&v12 + 4) = *(_QWORD *)&scale.x;
  v10 = v12;
  *(_QWORD *)&this->m_aabb.min.x = 0xBF800000BF800000uLL;
  HIDWORD(v12) = v9;
  *(_QWORD *)&this->m_aabb.min.elements[2] = v10;
  *(_QWORD *)&this->m_aabb.max.elements[1] = *((_QWORD *)&v12 + 1);
  vostok::math::aabb::modify((vostok::math::aabb *)&new_transform, &this->m_aabb);
}
