void __userpurge vostok::variant<32>::set<vostok::render::material_effects_instance_cook_data *>(
        vostok::variant<32> *this@<ecx>,
        int a2@<esi>,
        vostok::render::material_effects_instance_cook_data *const *value)
{
  int v3; // ecx

  v3 = *(_DWORD *)(a2 + 40);
  if ( v3 )
  {
    (*(void (__thiscall **)(int, int))(*(_DWORD *)v3 + 4))(v3, a2 + 8);
    *(_DWORD *)(a2 + 40) = 0;
  }
  *(_DWORD *)(a2 + 44) = vostok::detail::type_to_int<vostok::render::material_effects_instance_cook_data *>::get();
  if ( a2 != -8 )
    *(vostok::render::material_effects_instance_cook_data **)(a2 + 8) = *value;
  *(_DWORD *)(a2 + 40) = a2;
  *(_DWORD *)a2 = &vostok::detail::concrete_type_helper<vostok::render::material_effects_instance_cook_data *>::`vftable';
}
