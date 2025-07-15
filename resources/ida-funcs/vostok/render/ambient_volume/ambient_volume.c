void __userpurge vostok::render::ambient_volume::ambient_volume(
        vostok::render::ambient_volume *this@<esi>,
        unsigned int id@<edx>,
        vostok::math::aabb *properties)
{
  const vostok::math::float4x4 *v3; // xmm0_4
  const vostok::math::float4x4 *v4; // ecx
  __int64 v5; // [esp+4h] [ebp-Ch]

  this->m_reference_count = 0;
  *(_QWORD *)&this->m_aabb.min.x = 0xBF800000BF800000uLL;
  v3 = clear_value;
  v4 = clear_value;
  this->m_aabb.min.z = -1.0;
  LODWORD(v5) = v3;
  HIDWORD(v5) = v3;
  *(_QWORD *)&this->m_aabb.max.x = v5;
  LODWORD(this->m_aabb.max.z) = v4;
  this->m_id = id;
  this->m_occlusion_info_index = -1;
  this->m_occluded = 0;
  vostok::render::ambient_volume::set_properties(this, properties);
}
