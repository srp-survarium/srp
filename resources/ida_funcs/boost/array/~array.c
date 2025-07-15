void __usercall boost::array<survarium::player_desc,20>::~array<survarium::player_desc,20>(
        boost::array<survarium::player_desc,20> *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::unmanaged_resource **v2; // esi
  int i; // edi
  int v4; // eax

  v2 = (vostok::resources::unmanaged_resource **)(a2 + 160);
  for ( i = 19; i >= 0; --i )
  {
    v4 = (int)*(v2 - 2);
    v2 -= 2;
    if ( v4 )
    {
      if ( !_InterlockedExchangeAdd((volatile signed __int32 *)(v4 + 208), 0xFFFFFFFF) )
        vostok::resources::unmanaged_intrusive_base::destroy(&(*v2)->vostok::resources::unmanaged_intrusive_base, *v2);
    }
  }
}
