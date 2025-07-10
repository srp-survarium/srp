BOOL __userpurge vostok::render::cloud_simulation::is_empty@<eax>(
        vostok::render::cloud_simulation *this@<ecx>,
        _DWORD *a2@<eax>,
        unsigned int x,
        unsigned int y,
        unsigned int z)
{
  return *(_BYTE *)(a2[20] + 4 * (x + a2[22] * (y + z * a2[23]))) == 0;
}
