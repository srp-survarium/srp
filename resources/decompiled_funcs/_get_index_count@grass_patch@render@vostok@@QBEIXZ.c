unsigned int __usercall vostok::render::grass_patch::get_index_count@<eax>(
        vostok::render::grass_patch *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 4 * *(_DWORD *)(a2 + 16448) + 16528);
}
