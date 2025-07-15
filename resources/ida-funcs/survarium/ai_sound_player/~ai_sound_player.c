void __thiscall survarium::ai_sound_player::~ai_sound_player(survarium::ai_sound_player *this)
{
  vostok::sound::sound_instance_proxy *m_object; // ecx
  bool v3; // zf
  survarium::ai_sound_player *v4; // ebx
  vostok::resources::unmanaged_intrusive_base **p_type; // esi
  vostok::resources::unmanaged_intrusive_base *v6; // ecx
  vostok::sound::sound_instance_proxy *v7; // eax

  this->__vftable = (survarium::ai_sound_player_vtbl *)&survarium::ai_sound_player::`vftable';
  m_object = this->m_active_sound.m_object;
  this->m_active_sound.m_object = 0;
  if ( m_object )
  {
    v3 = m_object->m_reference_count-- == 1;
    if ( v3 )
      m_object->free_object(m_object);
  }
  v4 = (survarium::ai_sound_player *)((char *)this + 16 * this->m_sounds_count + 424);
  if ( &this[1] != v4 )
  {
    p_type = (vostok::resources::unmanaged_intrusive_base **)&this[1].type;
    do
    {
      v6 = p_type[1];
      if ( v6 )
      {
        (*(void (__thiscall **)(vostok::resources::unmanaged_intrusive_base *, vostok::resources::unmanaged_intrusive_base *))(v6->m_reference_count + 12))(
          v6,
          *p_type);
        vostok::resources::resource_children::unlink_parent_resource(
          (vostok::resources::resource_children *)*p_type,
          (vostok::resources::resource_base *)p_type[1]);
        p_type[1] = 0;
      }
      if ( *p_type && !_InterlockedExchangeAdd(&(*p_type)[26].m_reference_count, 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(
          *p_type + 26,
          (vostok::resources::unmanaged_resource *)*p_type);
      p_type += 4;
    }
    while ( p_type - 1 != (vostok::resources::unmanaged_intrusive_base **)v4 );
  }
  v7 = this->m_active_sound.m_object;
  if ( v7 )
  {
    v3 = v7->m_reference_count-- == 1;
    if ( v3 )
      this->m_active_sound.m_object->free_object(this->m_active_sound.m_object);
  }
  this->__vftable = (survarium::ai_sound_player_vtbl *)&vostok::ai::sound_player::`vftable';
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
