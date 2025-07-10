bool __usercall vostok::resources::query_result::is_translate_query@<al>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::cook_base *cook; // eax

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  return cook && ((cook->m_flags.m_flags & 8) != 8 ? 0 : (unsigned int)cook) != 0;
}
