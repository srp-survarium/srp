bool __usercall vostok::resources::cook_base::does_create_resource@<al>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return (*(_BYTE *)(a2 + 24) & 8) != 8;
}


bool __fastcall vostok::resources::cook_base::does_create_resource(
        int a1,
        vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  return cook && (cook->m_flags.m_flags & 8) != 8;
}
