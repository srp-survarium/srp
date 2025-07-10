const vostok::render::cloud_simulation::voxel *__userpurge vostok::render::cloud_simulation::get_voxel@<eax>(
        vostok::render::cloud_simulation *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int x,
        unsigned int y,
        unsigned int z)
{
  return (const vostok::render::cloud_simulation::voxel *)(a2[20] + 4 * (x + a2[22] * (y + z * a2[23])));
}
