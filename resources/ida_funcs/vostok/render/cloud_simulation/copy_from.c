void __fastcall vostok::render::cloud_simulation::copy_from(
        vostok::render::cloud_simulation *this,
        const vostok::render::cloud_simulation *other)
{
  memcpy(
    (unsigned __int8 *)this->m_voxels,
    (unsigned __int8 *)other->m_voxels,
    4 * this->m_clouds_size_x * this->m_clouds_size_y * this->m_clouds_size_z);
}
