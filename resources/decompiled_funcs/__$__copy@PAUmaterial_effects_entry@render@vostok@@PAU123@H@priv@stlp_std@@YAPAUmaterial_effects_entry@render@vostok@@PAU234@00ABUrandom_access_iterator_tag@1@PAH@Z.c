vostok::render::material_effects_entry *__usercall stlp_std::priv::__copy<vostok::render::material_effects_entry *,vostok::render::material_effects_entry *,int>@<eax>(
        vostok::render::material_effects_entry *__first@<ecx>,
        vostok::render::material_effects_entry *__last@<eax>,
        vostok::render::material_effects_entry *__result)
{
  vostok::render::material_effects_entry *v4; // edi
  int i; // esi

  v4 = __first;
  for ( i = __last - __first; i > 0; ++__result )
  {
    __result->m_material_effects_instance_ptr = v4->m_material_effects_instance_ptr;
    vostok::fs_new::virtual_path_string::operator=(&__result->m_material_name, &v4->m_material_name);
    --i;
    ++v4;
  }
  return __result;
}
