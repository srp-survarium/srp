char __usercall try_to_allocate_arenas@<al>(
        vostok::memory::platform::region *managed_arena@<eax>,
        vostok::buffer_vector<vostok::memory::platform::region> *a2@<ecx>,
        vostok::buffer_vector<vostok::memory::platform::region> *arenas,
        vostok::memory::platform::region *unmanaged_arena,
        vostok::memory::platform::region *only_resources)
{
  void *v6; // esp
  _BYTE *v7; // ebx
  vostok::buffer_vector<vostok::memory::platform::region> *v8; // ecx
  char *v9; // eax
  char result; // al
  _BYTE *v11; // esi
  _DWORD *v12; // edi
  _DWORD *v13; // esi
  _DWORD *v14; // esi
  _DWORD *v15; // edi
  void **v16; // esi
  _BYTE v17[32]; // [esp-20h] [ebp-3Ch] BYREF
  int v18; // [esp+0h] [ebp-1Ch] BYREF
  _BYTE *v19; // [esp+10h] [ebp-Ch] BYREF
  _BYTE *v20; // [esp+14h] [ebp-8h]
  int *v21; // [esp+18h] [ebp-4h]

  v6 = alloca(32);
  v7 = v17;
  v19 = v17;
  v20 = v17;
  v21 = &v18;
  if ( vostok::memory::g_use_resources_manager )
  {
    vostok::buffer_vector<vostok::memory::platform::region>::push_back(
      a2,
      (const vostok::memory::platform::region *)&v19,
      managed_arena);
    vostok::buffer_vector<vostok::memory::platform::region>::push_back(
      v8,
      (const vostok::memory::platform::region *)&v19,
      unmanaged_arena);
    v7 = v20;
  }
  if ( !(_BYTE)only_resources
    && try_to_allocate_arenas_as_a_single_block(arenas, (vostok::buffer_vector<vostok::memory::platform::region> *)&v19)
    || (v9 = (char *)allocation_granularity(),
        (result = allocate_arenas(
                    (vostok::memory::platform::region *)arenas,
                    (vostok::buffer_vector<vostok::memory::platform::region> *)&v19,
                    v9,
                    only_resources)) != 0) )
  {
    if ( vostok::memory::g_use_resources_manager )
    {
      v11 = v19;
      if ( *((vostok::memory::platform::region **)v19 + 3) == managed_arena )
      {
        LODWORD(managed_arena->size) = *(_DWORD *)v19;
        v13 = v11 + 4;
        v12 = (_DWORD *)&managed_arena->size + 1;
        *v12 = *v13++;
        *++v12 = *v13;
        v12[1] = v13[1];
        v14 = v7 - 16;
      }
      else
      {
        LODWORD(managed_arena->size) = *((_DWORD *)v7 - 4);
        v15 = (_DWORD *)&managed_arena->size + 1;
        *v15++ = *((_DWORD *)v7 - 3);
        *v15 = *((_DWORD *)v7 - 2);
        v15[1] = *((_DWORD *)v7 - 1);
        v14 = v19;
      }
      LODWORD(unmanaged_arena->size) = *v14;
      v16 = (void **)(v14 + 1);
      HIDWORD(unmanaged_arena->size) = *v16++;
      unmanaged_arena->address = *v16;
      unmanaged_arena->data = v16[1];
    }
    return 1;
  }
  return result;
}
