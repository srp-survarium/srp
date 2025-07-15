void __usercall vostok::render::culling::delete_tree(
        vostok::memory::base_allocator *allocator@<edi>,
        vostok::collision::space_partitioning_tree *tree@<esi>)
{
  if ( tree )
  {
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))tree->~vostok::collision::space_partitioning_tree)(
      tree,
      0);
    allocator->call_free(allocator, tree, "vostok::render::culling::delete_tree", ".\\portal_sector_structure.cpp", 38u);
  }
}
