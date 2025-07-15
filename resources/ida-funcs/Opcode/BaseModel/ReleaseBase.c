void __thiscall Opcode::BaseModel::ReleaseBase(Opcode::BaseModel *this, int a2)
{
  int v2; // edi
  int v3; // esi
  Opcode::AABBOptimizedTree **v4; // esi

  if ( *(_DWORD *)(a2 + 12) )
  {
    v2 = *(_DWORD *)(a2 + 12);
    v3 = *(_DWORD *)(a2 + 20);
    if ( v2 )
    {
      Opcode::AABBTree::Release((Opcode::AABBTree *)this, v2);
      (*(void (__thiscall **)(int, int, const char *, const char *, int))(*(_DWORD *)v3 + 24))(
        v3,
        v2,
        "Opcode::BaseModel::ReleaseBase",
        ".\\OPC_BaseModel.cpp",
        80);
      *(_DWORD *)(a2 + 12) = 0;
    }
    *(_DWORD *)(a2 + 12) = 0;
  }
  v4 = (Opcode::AABBOptimizedTree **)(a2 + 16);
  if ( *(_DWORD *)(a2 + 16) )
  {
    vostok::memory::delete_helper<vostok::memory::base_allocator,Opcode::AABBOptimizedTree>(
      *(vostok::memory::base_allocator **)(a2 + 20),
      v4,
      "Opcode::BaseModel::ReleaseBase",
      (const char *const)0x51);
    *v4 = 0;
  }
}
