void __userpurge vostok::render::culling::portal_sector_structure::portal_sector_structure(
        vostok::render::culling::portal_sector_structure *this@<ecx>,
        _DWORD *a2@<esi>,
        unsigned int portals_count,
        unsigned int sectors_count,
        unsigned int a5)
{
  vostok::memory::doug_lea_allocator *v5; // edi
  int v6; // eax
  int v8; // ecx
  int v9; // eax
  vostok::collision::space_partitioning_tree *v10; // eax
  float v11; // [esp-4h] [ebp-Ch]
  float v12; // [esp+0h] [ebp-8h]
  unsigned int v13; // [esp+14h] [ebp+Ch]

  v5 = vostok::render::g_allocator;
  vostok::resources::unmanaged_resource::unmanaged_resource(this, a2, fs_iterator_class);
  *a2 = &vostok::render::culling::portal_sector_structure::`vftable';
  a2[66] = v5;
  v6 = (int)v5->call_malloc(
              v5,
              76 * portals_count,
              "buffer for portals in render",
              "vostok::render::culling::portal_sector_structure::portal_sector_structure",
              ".\\portal_sector_structure.cpp",
              43u);
  a2[67] = v6;
  a2[70] = v6 + 76 * portals_count;
  a2[68] = v6;
  a2[69] = v6;
  v8 = a2[66];
  a2[71] = 0;
  v13 = 32 * sectors_count;
  v9 = (*(int (__thiscall **)(int, unsigned int, const char *, const char *, const char *, int))(*(_DWORD *)v8 + 16))(
         v8,
         v13,
         "buffer for sectors in render",
         "vostok::render::culling::portal_sector_structure::portal_sector_structure",
         ".\\portal_sector_structure.cpp",
         46);
  a2[72] = v9;
  a2[73] = v9;
  a2[74] = v9;
  a2[75] = v9 + v13;
  a2[76] = vostok::render::culling::new_tree(100 * sectors_count, v12);
  v10 = vostok::render::culling::new_tree(portals_count, v11);
  a2[78] = 0;
  a2[77] = v10;
}
