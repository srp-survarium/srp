void __cdecl vostok::collision::delete_space_partitioning_tree(vostok::collision::space_partitioning_tree *tree)
{
  void (__thiscall *insert)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *); // edi
  _BYTE *v2; // ebx

  if ( tree )
  {
    insert = tree[4].insert;
    v2 = __RTCastToVoid((void **)&tree->__vftable);
    ((void (__thiscall *)(vostok::collision::space_partitioning_tree *, _DWORD))tree->~vostok::collision::space_partitioning_tree)(
      tree,
      0);
    (*(void (__thiscall **)(void (__thiscall *)(vostok::collision::space_partitioning_tree *, vostok::collision::object *, const vostok::math::float4x4 *), _BYTE *))(*(_DWORD *)insert + 24))(
      insert,
      v2);
  }
}
