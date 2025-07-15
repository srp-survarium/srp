bool __thiscall Opcode::BaseModel::CreateTree(Opcode::BaseModel *this, int no_leaf, bool quantized, char a4)
{
  Opcode::AABBOptimizedTree **v5; // eax
  Opcode::AABBOptimizedTree **v6; // esi
  int v7; // eax
  int v8; // edi
  char *v9; // eax
  Opcode::AABBOptimizedTree *v10; // eax
  vostok::memory::base_allocator *v11; // ebx
  char *v12; // eax
  char *v13; // eax
  char *v14; // eax
  Opcode::AABBOptimizedTree **v16; // [esp+14h] [ebp+8h]

  v5 = (Opcode::AABBOptimizedTree **)(no_leaf + 16);
  v16 = v5;
  if ( *v5 )
  {
    v6 = v5;
    vostok::memory::delete_helper<vostok::memory::base_allocator,Opcode::AABBOptimizedTree>(
      *(vostok::memory::base_allocator **)(no_leaf + 20),
      v5,
      "Opcode::BaseModel::CreateTree",
      (const char *const)0x5E);
    *v6 = 0;
  }
  if ( quantized )
    *(_DWORD *)(no_leaf + 8) |= 2u;
  else
    *(_DWORD *)(no_leaf + 8) &= ~2u;
  if ( a4 )
    *(_DWORD *)(no_leaf + 8) |= 1u;
  else
    *(_DWORD *)(no_leaf + 8) &= ~1u;
  v7 = *(_DWORD *)(no_leaf + 8);
  v8 = *(_DWORD *)(no_leaf + 20);
  if ( (v7 & 2) == 0 )
  {
    if ( (v7 & 1) != 0 )
    {
      v13 = type_info::raw_name(&Opcode::AABBQuantizedTree `RTTI Type Descriptor');
      v10 = (Opcode::AABBOptimizedTree *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v8 + 16))(
                                           v8,
                                           40,
                                           v13,
                                           "Opcode::BaseModel::CreateTree",
                                           ".\\OPC_BaseModel.cpp",
                                           111);
      if ( v10 )
      {
        v11 = *(vostok::memory::base_allocator **)(no_leaf + 20);
        v10->__vftable = (Opcode::AABBOptimizedTree_vtbl *)&Opcode::AABBQuantizedTree::`vftable';
        goto LABEL_20;
      }
    }
    else
    {
      v14 = type_info::raw_name(&Opcode::AABBCollisionTree `RTTI Type Descriptor');
      v10 = (Opcode::AABBOptimizedTree *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v8 + 16))(
                                           v8,
                                           16,
                                           v14,
                                           "Opcode::BaseModel::CreateTree",
                                           ".\\OPC_BaseModel.cpp",
                                           112);
      if ( v10 )
      {
        v11 = *(vostok::memory::base_allocator **)(no_leaf + 20);
        v10->__vftable = (Opcode::AABBOptimizedTree_vtbl *)&Opcode::AABBCollisionTree::`vftable';
        goto LABEL_20;
      }
    }
    goto LABEL_21;
  }
  if ( (v7 & 1) == 0 )
  {
    v12 = type_info::raw_name(&Opcode::AABBNoLeafTree `RTTI Type Descriptor');
    v10 = (Opcode::AABBOptimizedTree *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v8 + 16))(
                                         v8,
                                         16,
                                         v12,
                                         "Opcode::BaseModel::CreateTree",
                                         ".\\OPC_BaseModel.cpp",
                                         107);
    if ( v10 )
    {
      v11 = *(vostok::memory::base_allocator **)(no_leaf + 20);
      v10->__vftable = (Opcode::AABBOptimizedTree_vtbl *)&Opcode::AABBNoLeafTree::`vftable';
      goto LABEL_20;
    }
LABEL_21:
    v10 = 0;
    goto LABEL_22;
  }
  v9 = type_info::raw_name(&Opcode::AABBQuantizedNoLeafTree `RTTI Type Descriptor');
  v10 = (Opcode::AABBOptimizedTree *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v8 + 16))(
                                       v8,
                                       40,
                                       v9,
                                       "Opcode::BaseModel::CreateTree",
                                       ".\\OPC_BaseModel.cpp",
                                       106);
  if ( !v10 )
    goto LABEL_21;
  v11 = *(vostok::memory::base_allocator **)(no_leaf + 20);
  v10->__vftable = (Opcode::AABBOptimizedTree_vtbl *)&Opcode::AABBQuantizedNoLeafTree::`vftable';
LABEL_20:
  v10->m_allocator = v11;
  v10->mNbNodes = 0;
  v10[1].__vftable = 0;
LABEL_22:
  *v16 = v10;
  return *v16 != 0;
}
