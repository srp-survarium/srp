void __usercall survarium::game_world::initialize_ai(survarium::game_world *this@<ecx>, vostok::ai::engine *a2@<esi>)
{
  if ( a2 )
    a2[146].__vftable = (vostok::ai::engine_vtbl *)vostok::ai::create_world(a2 + 47);
  else
    MEMORY[0x248] = vostok::ai::create_world(0);
}
