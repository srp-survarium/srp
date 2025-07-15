bool __usercall vostok::resources::cook_base::destroy_in_any_thread@<al>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_DWORD *)(a2 + 24) & 1) == 1;
}


bool __fastcall vostok::resources::cook_base::destroy_in_any_thread(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return !cook || (cook->m_flags.m_flags & 1) == 1;
}
