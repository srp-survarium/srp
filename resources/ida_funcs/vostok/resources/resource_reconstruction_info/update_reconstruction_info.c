void __thiscall vostok::resources::resource_reconstruction_info::update_reconstruction_info(
        vostok::resources::resource_reconstruction_info *this,
        unsigned __int64 update_tick)
{
  vostok::resources::resource_reconstruction_info *v3; // edi
  const vostok::resources::resource_link *no_dying; // eax
  const vostok::resources::resource_link *v5; // esi
  const vostok::resources::resource_link *i; // eax
  vostok::resources::resource_reconstruction_info *update_ticka; // [esp+18h] [ebp+4h]

  v3 = this;
  if ( LODWORD(this->m_reconstruction_info_actuality_tick) != (_DWORD)update_tick
    || (this = (vostok::resources::resource_reconstruction_info *)HIDWORD(this->m_reconstruction_info_actuality_tick),
        this != (vostok::resources::resource_reconstruction_info *)HIDWORD(update_tick)) )
  {
    v3->m_reconstruction_size = *(&v3[4].m_reconstruction_size + 1);
    v3->m_reconstruction_info_actuality_tick = update_tick;
    if ( *(&v3[3].m_reconstruction_size + 1) )
    {
      update_ticka = v3 + 3;
      vostok::threading::simple_lock::lock(
        (vostok::threading::simple_lock *)this,
        (vostok::threading::simple_lock *)&v3[3]);
      no_dying = (const vostok::resources::resource_link *)*(&v3[3].m_reconstruction_size + 1);
      if ( no_dying && (no_dying->resource->m_flags.m_flags & 0x800) != 0 )
        no_dying = vostok::resources::resource_link_list_next_no_dying(no_dying);
      v5 = no_dying;
      if ( no_dying )
      {
        do
        {
          vostok::resources::resource_reconstruction_info::update_reconstruction_info(
            &v5->resource->vostok::resources::resource_reconstruction_info,
            update_tick);
          if ( v5->quality_value == -1 )
            v3->m_reconstruction_size += v5->resource->m_reconstruction_size;
          for ( i = v5->next_link; i; i = i->next_link )
          {
            if ( (i->resource->m_flags.m_flags & 0x800) == 0 )
              break;
          }
          v5 = i;
        }
        while ( i );
      }
      if ( LODWORD(update_ticka->m_reconstruction_info_actuality_tick)-- == 1 )
        _InterlockedExchange((volatile __int32 *)&v3[3].m_reconstruction_info_actuality_tick + 1, 0);
    }
  }
}
