unsigned __int8 __usercall survarium::lobby_client::read_price_items@<al>(
        survarium::lobby_client *this@<ecx>,
        vostok::network_core::packet_reader *reader@<esi>)
{
  const unsigned __int8 *m_pointer; // eax
  unsigned __int8 v3; // bl
  survarium::faction_price *v4; // ebp
  const unsigned __int8 *v5; // ecx
  unsigned __int16 v6; // ax
  unsigned int v7; // edi
  vostok::memory::doug_lea_allocator *v8; // eax
  unsigned __int8 *v9; // eax
  unsigned int v10; // edi

  m_pointer = reader->m_pointer;
  v3 = *m_pointer;
  reader->m_pointer = m_pointer + 1;
  v4 = &this->m_prices[v3];
  v4->faction_id = v3;
  v5 = reader->m_pointer;
  v6 = *(_WORD *)v5;
  reader->m_pointer = v5 + 2;
  v4->count = v6;
  if ( v6 )
  {
    v7 = 6 * v6;
    v8 = (vostok::memory::doug_lea_allocator *)boost::get_pointer<vostok::sound::sound_scene>((vostok::sound::sound_world *)survarium::g_allocator.f_.f_);
    v9 = (unsigned __int8 *)vostok::memory::doug_lea_allocator::malloc_impl(v8, v7);
    v10 = 3 * v4->count;
    v4->items = (survarium::price_item *)v9;
    v10 *= 2;
    memcpy(v9, (unsigned __int8 *)reader->m_pointer, v10);
    reader->m_pointer += v10;
  }
  return v3;
}
