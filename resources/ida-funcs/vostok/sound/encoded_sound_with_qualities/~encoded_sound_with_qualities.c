void __thiscall vostok::sound::encoded_sound_with_qualities::~encoded_sound_with_qualities(
        vostok::sound::encoded_sound_with_qualities *this)
{
  int v2; // [esp+4h] [ebp-40h]
  vostok::resources::query_result_for_cook **j; // [esp+8h] [ebp-3Ch]
  vostok::sound::encoded_sound_interface *(__thiscall *v4)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+3Ch] [ebp-8h]
  int i; // [esp+40h] [ebp-4h]

  this->__vftable = (vostok::sound::encoded_sound_with_qualities_vtbl *)&vostok::sound::encoded_sound_with_qualities::`vftable';
  for ( i = 1; i >= 0; --i )
  {
    if ( this->m_qualities[i].m_object )
      v4 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
    else
      v4 = 0;
    if ( v4 )
      vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base>::set_zero(&this->m_qualities[i]);
  }
  v2 = 2;
  for ( j = &this->m_parent_query;
        --v2 >= 0;
        vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::sound::panning_lut,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)j) )
  {
    j -= 2;
    vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_with_qualities,vostok::resources::unmanaged_intrusive_base>::unlink_with_parent_if_needed((vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *)j);
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
