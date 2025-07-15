BOOL __thiscall vostok::resources::resource_base::has_user_references(vostok::resources::resource_base *this)
{
  vostok::resources::resource_flags *v1; // ecx
  vostok::resources::base_of_intrusive_base *v2; // eax
  int v3; // edx
  int v4; // ecx

  if ( vostok::resources::resource_flags::cast_base_of_intrusive_base(this) )
    vostok::resources::resource_flags::cast_base_of_intrusive_base(v1);
  v2 = vostok::resources::resource_flags::cast_base_of_intrusive_base(v1);
  return *(_DWORD *)(v4 + 60) < (unsigned int)(v2->m_reference_count - v3);
}
