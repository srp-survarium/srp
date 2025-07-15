vostok::collision::space_partitioning_tree *__cdecl vostok::render::culling::new_tree(
        unsigned int nodes_count,
        float a2)
{
  int v2; // ecx
  void *v3; // eax

  v3 = (void *)(*(int (__thiscall **)(int, unsigned int, const char *, const char *, const char *, int))(*(_DWORD *)v2 + 16))(
                 v2,
                 40 * nodes_count + 52,
                 "space partitionaing tree",
                 "vostok::render::culling::new_tree",
                 ".\\portal_sector_structure.cpp",
                 27);
  return vostok::collision::new_space_partitioning_tree(v3, nodes_count, a2, nodes_count);
}
