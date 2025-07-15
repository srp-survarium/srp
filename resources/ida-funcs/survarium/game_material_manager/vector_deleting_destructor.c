survarium::game_material_manager *__userpurge survarium::game_material_manager::`vector deleting destructor'@<eax>(
        survarium::game_material_manager *this@<ecx>,
        const char *a2@<esi>,
        char a3)
{
  vostok::memory::doug_lea_allocator *v4; // ecx
  char **m_materials; // edi
  const char *v7; // [esp-4h] [ebp-10h]
  const char *v8; // [esp+0h] [ebp-Ch]
  unsigned int v9; // [esp+4h] [ebp-8h]
  int v10; // [esp+8h] [ebp-4h]

  this->__vftable = (survarium::game_material_manager_vtbl *)&survarium::game_material_manager::`vftable';
  survarium::game_material_manager::delete_pairs(this, (int)this);
  m_materials = (char **)this->m_materials;
  v10 = 128;
  v7 = a2;
  do
  {
    if ( *m_materials )
    {
      vostok::memory::doug_lea_allocator::free_impl(v4, (int)survarium::g_allocator, *m_materials, v7, v8, v9);
      *m_materials = 0;
      *m_materials = 0;
    }
    ++m_materials;
    --v10;
  }
  while ( v10 );
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a3 & 1) != 0 )
    operator delete(this);
  return this;
}
