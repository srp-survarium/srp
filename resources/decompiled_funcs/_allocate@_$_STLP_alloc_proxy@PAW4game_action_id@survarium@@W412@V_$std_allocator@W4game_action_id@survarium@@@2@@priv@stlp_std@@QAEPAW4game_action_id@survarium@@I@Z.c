vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *__usercall stlp_std::priv::_STLP_alloc_proxy<enum survarium::game_action_id *,enum survarium::game_action_id,survarium::std_allocator<enum survarium::game_action_id>>::allocate@<eax>(
        unsigned int __n@<eax>,
        stlp_std::priv::_STLP_alloc_proxy<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *,vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base>,survarium::std_allocator<vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> > > *this)
{
  char v2; // dl
  bool v3; // cf
  unsigned int *v4; // eax
  unsigned int v5; // ecx
  int f; // eax
  unsigned int v7; // ecx
  int v9; // [esp+0h] [ebp-8h] BYREF
  unsigned int v10; // [esp+4h] [ebp-4h] BYREF

  v2 = 1;
  v10 = __n;
  v3 = __n == 0;
  v9 = 1;
  v4 = (unsigned int *)&v9;
  if ( !v3 )
    v4 = &v10;
  v5 = *v4;
  f = (int)survarium::g_allocator.f_.f_;
  v7 = 4 * v5;
  if ( !*(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) || !v7 )
    v2 = 0;
  *(_BYTE *)(LODWORD(survarium::g_allocator.f_.f_) + 42) = v2;
  if ( v7 )
    return (vostok::resources::resource_ptr<survarium::damage_zone,vostok::resources::unmanaged_intrusive_base> *)vostok_mspace_malloc(*(void **)(f + 20), v7);
  else
    return 0;
}
