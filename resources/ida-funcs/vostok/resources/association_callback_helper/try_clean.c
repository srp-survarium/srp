void __thiscall vostok::resources::association_callback_helper::try_clean(
        vostok::resources::association_callback_helper *this,
        vostok::resources::resource_flags **association)
{
  vostok::resources::base_of_intrusive_base *v2; // eax
  int v3; // edx

  v2 = vostok::resources::resource_flags::cast_base_of_intrusive_base(*association);
  if ( v2->m_reference_count <= *(_DWORD *)(v3 + 16) )
  {
    *association = 0;
    *(_BYTE *)(v3 + 20) = 1;
  }
}
