void __userpurge vostok::render::cloud_simulation::set_voxel(
        vostok::render::cloud_simulation *this@<ecx>,
        _DWORD *a2@<eax>,
        const vostok::render::cloud_simulation::voxel *v,
        unsigned int x,
        unsigned int y,
        unsigned int z)
{
  *(vostok::render::cloud_simulation::voxel *)(a2[20] + 4 * (x + a2[22] * (y + z * a2[23]))) = *v;
}
