void __usercall survarium::human_npc::get_available_weapons(survarium::human_npc *this@<ecx>, int a2@<eax>)
{
  unsigned int i; // edi
  vostok::sound::sound_producer_vtbl *v4; // eax
  const stlp_std::__true_type *v5; // [esp+0h] [ebp-Ch]
  unsigned int v6; // [esp+4h] [ebp-8h]
  unsigned int __x; // [esp+8h] [ebp-4h] BYREF

  for ( i = *(_DWORD *)(a2 + 396); i; i = *(_DWORD *)(i + 12) )
  {
    v4 = (vostok::sound::sound_producer_vtbl *)this->vostok::ai::game_object::__vftable;
    __x = i;
    if ( v4 == this->vostok::sound::sound_producer::__vftable )
    {
      stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int>>::_M_insert_overflow(
        (stlp_std::priv::_Impl_vector<unsigned int,vostok::vectora_allocator<unsigned int> > *)&__x,
        (unsigned __int8 **)this,
        (int)v4,
        &__x,
        v5,
        v6,
        __x);
    }
    else
    {
      v4->get_description = (const char *(__thiscall *)(vostok::sound::sound_producer *))i;
      this->vostok::ai::game_object::__vftable = (vostok::ai::game_object_vtbl *)((char *)this->vostok::ai::game_object::__vftable
                                                                                + 4);
    }
  }
}
