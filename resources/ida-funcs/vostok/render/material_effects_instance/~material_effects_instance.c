void __userpurge vostok::render::material_effects_instance::~material_effects_instance(
        vostok::render::material_effects_instance *this@<ecx>,
        unsigned int a2@<ebx>,
        const char *a3@<edi>,
        const char *a4@<esi>,
        vostok::resources::unmanaged_resource *a5)
{
  vostok::resources::unmanaged_resource *v5; // ecx
  bool v6; // zf
  int v7; // eax
  char *v8; // esi
  vostok::render::material_effects *v9; // ecx
  int v10; // ebx
  int v11; // edi
  vostok::memory::doug_lea_allocator *v15; // [esp+0h] [ebp-8h]
  vostok::render::material_effects *v16; // [esp+4h] [ebp-4h]

  v5 = a5;
  v6 = LODWORD(a5[2].m_reconstruction_info_actuality_tick) == 0;
  a5->__vftable = (vostok::resources::unmanaged_resource_vtbl *)&vostok::render::material_effects_instance::`vftable';
  if ( !v6 )
  {
    v15 = vostok::render::g_allocator;
    v7 = *((_DWORD *)&a5[2].vostok::resources::resource_flags + 3);
    if ( v7 )
    {
      v8 = (char *)(v7 - 8);
      v9 = *(vostok::render::material_effects **)(v7 - 8 + 4);
      v10 = *((_DWORD *)&a5[2].vostok::resources::resource_flags + 3);
      v16 = v9;
      v11 = v7 + (_DWORD)v9 * *(_DWORD *)(v7 - 8);
      while ( v10 != v11 )
      {
        vostok::render::material_effects::~material_effects(v9, v10);
        v10 += (int)v16;
      }
      vostok::memory::doug_lea_allocator::free_impl((vostok::memory::doug_lea_allocator *)v9, (int)v15, v8, a3, a4, a2);
      v5 = a5;
    }
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(v5);
}
