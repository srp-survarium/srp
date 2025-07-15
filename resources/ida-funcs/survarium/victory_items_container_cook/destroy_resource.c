void __thiscall survarium::victory_items_container_cook::destroy_resource(
        survarium::victory_items_container_cook *this,
        vostok::resources::unmanaged_resource *resource)
{
  char *p_m_creation_source; // ecx

  if ( resource )
    p_m_creation_source = (char *)&resource[-1].m_creation_source;
  else
    p_m_creation_source = 0;
  (**(void (__thiscall ***)(char *, _DWORD))p_m_creation_source)(p_m_creation_source, 0);
}
