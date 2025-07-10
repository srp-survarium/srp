void __usercall vostok::render::world::tick(vostok::render::world *this@<ecx>, int a2@<esi>)
{
  if ( !*(_DWORD *)(a2 + 388) )
    vostok::render::one_way_render_channel::render_process_commands(&this->m_logic_channel, 1);
  if ( !*(_BYTE *)(a2 + 392) )
    vostok::render::one_way_render_channel::render_process_commands(&this->m_logic_channel, 1);
}
