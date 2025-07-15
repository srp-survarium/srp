bool __usercall vostok::resources::cook_base::cooks_inplace@<al>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 24) & 0x10) == 16;
}


bool __fastcall vostok::resources::cook_base::cooks_inplace(int a1, vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return !cook || (cook->m_flags.m_flags & 0x10) == 16;
}
