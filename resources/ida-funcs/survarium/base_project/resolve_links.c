void __thiscall survarium::base_project::resolve_links(survarium::base_project *this)
{
  survarium::base_project::resolve_link_object *M_start; // ebx
  survarium::link_resolver *object; // eax
  survarium::link_resolver_vtbl *v4; // edx
  _DWORD v5[6]; // [esp-Ch] [ebp-2Ch] BYREF
  survarium::base_project::resolve_link_object *i; // [esp+1Ch] [ebp-4h]

  M_start = this->m_objects_to_resolve._M_impl._M_start;
  for ( i = this->m_objects_to_resolve._M_impl._M_finish; M_start != i; ++M_start )
  {
    object = M_start->object;
    v4 = object->__vftable;
    qmemcpy(v5, M_start, sizeof(v5));
    ((void (__thiscall *)(survarium::link_resolver *, survarium::base_project *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v4->resolve_links)(
      object,
      this,
      v5[0],
      v5[1],
      v5[2],
      v5[3],
      v5[4],
      v5[5]);
  }
}
