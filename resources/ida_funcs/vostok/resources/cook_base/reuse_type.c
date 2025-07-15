vostok::resources::cook_base::reuse_enum __usercall vostok::resources::cook_base::reuse_type@<eax>(
        vostok::resources::cook_base *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 12);
}


int __fastcall vostok::resources::cook_base::reuse_type(int a1, vostok::resources::class_id_enum resource_class)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(resource_class);
  if ( cook )
    return cook->m_reuse_type;
  else
    return 1;
}
