void __thiscall vostok::sound::encoded_sound_with_qualities::encoded_sound_with_qualities(
        vostok::sound::encoded_sound_with_qualities *this)
{
  int v2; // [esp+4h] [ebp-14h]
  vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *i; // [esp+8h] [ebp-10h]

  vostok::resources::unmanaged_resource::unmanaged_resource(this, 2u);
  this->__vftable = (vostok::sound::encoded_sound_with_qualities_vtbl *)&vostok::sound::encoded_sound_with_qualities::`vftable';
  vostok::fixed_string<260>::fixed_string<260>(&this->m_req_path, (const char *)&buf);
  v2 = 2;
  for ( i = this->m_qualities; --v2 >= 0; ++i )
  {
    i->m_object = 0;
    i->m_parent = 0;
  }
  this->m_parent_query = 0;
  this->m_sound_interface_type = unknown_data_class;
  this->m_current_quality = 0;
  this->m_increasing_quality = 0;
}
