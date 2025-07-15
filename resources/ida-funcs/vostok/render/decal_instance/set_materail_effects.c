void __usercall vostok::render::decal_instance::set_materail_effects(
        vostok::render::decal_instance *this@<eax>,
        const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *in_ptr@<edi>)
{
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *p_material; // esi
  vostok::fixed_string<260> *v3; // ecx
  vostok::buffer_string v4[23]; // [esp+4h] [ebp-114h] BYREF

  p_material = &this->m_properties.material;
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>::operator=(
    in_ptr,
    &this->m_properties.material);
  vostok::fixed_string<260>::fixed_string<260>(v3, v4, (char *)p_material->m_object[1].__vftable);
}
