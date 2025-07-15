void __thiscall vostok::resources::resource_reconstruction_info::update_reconstruction_info(
        vostok::resources::resource_reconstruction_info *this,
        unsigned __int64 update_tick)
{
  vostok::threading::simple_lock *v3; // ecx
  vostok::resources::resource_link *i; // eax
  vostok::resources::resource_link *v5; // edi
  vostok::threading::simple_lock::mutex_raii v6; // [esp+10h] [ebp-8h] BYREF

  if ( this->m_reconstruction_info_actuality_tick != update_tick )
  {
    v3 = (vostok::threading::simple_lock *)*(&this[4].m_reconstruction_size + 1);
    this->m_reconstruction_size = (unsigned int)v3;
    this->m_reconstruction_info_actuality_tick = update_tick;
    if ( *(&this[3].m_reconstruction_size + 1) )
    {
      v6.lock = (const vostok::threading::simple_lock *)&this[3];
      vostok::threading::simple_lock::lock(v3, (int)&this[3]);
      v6.locked = 1;
      for ( i = vostok::resources::resource_link_list_front_no_dying((const vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)(&this[2].m_reconstruction_size + 1));
            ;
            i = vostok::resources::resource_link_list_next_no_dying(v5) )
      {
        v5 = i;
        if ( !i )
          break;
        vostok::resources::resource_reconstruction_info::update_reconstruction_info(
          &i->resource->vostok::resources::resource_reconstruction_info,
          update_tick);
        if ( v5->quality_value == -1 )
          this->m_reconstruction_size += v5->resource->m_reconstruction_size;
      }
      vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v6);
    }
  }
}
