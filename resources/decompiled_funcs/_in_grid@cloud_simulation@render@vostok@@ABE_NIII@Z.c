BOOL __userpurge vostok::render::cloud_simulation::in_grid@<eax>(
        vostok::render::cloud_simulation *this@<ecx>,
        int a2@<eax>,
        unsigned int y,
        const unsigned int z,
        const unsigned int a5)
{
  return (unsigned int)this < *(_DWORD *)(a2 + 92) && y < *(_DWORD *)(a2 + 96);
}
