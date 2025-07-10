void __usercall vostok::physics::bullet_character_controller::jump(
        vostok::physics::bullet_character_controller *this@<ecx>,
        int a2@<eax>)
{
  _STLP_atomic_freelist::item *v2; // edi
  _STLP_atomic_freelist::item *v3; // esi
  _STLP_atomic_freelist::item *v4; // eax

  if ( !*(_BYTE *)(a2 + 224) && COERCE_FLOAT(*(_DWORD *)(a2 + 232) & 0x7FFFFFFF) < 0.001 && !*(_BYTE *)(a2 + 260) )
  {
    v2 = (_STLP_atomic_freelist::item *)(a2 + 264);
    *(_BYTE *)(a2 + 257) = 1;
    v3 = *(_STLP_atomic_freelist::item **)(a2 + 264);
    if ( v3 != (_STLP_atomic_freelist::item *)(a2 + 264) )
    {
      do
      {
        v4 = v3;
        v3 = v3->_M_next;
        stlp_std::__node_alloc::_M_deallocate(v4, 0x20u);
      }
      while ( v3 != v2 );
    }
    v2->_M_next = v2;
    v2[1]._M_next = v2;
  }
}
