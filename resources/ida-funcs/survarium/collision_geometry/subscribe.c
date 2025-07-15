void __userpurge survarium::collision_geometry::subscribe(
        survarium::collision_geometry *this@<ecx>,
        int a2@<eax>,
        vostok::physics::world *world,
        survarium::collision_geometry_subscriber *subscriber)
{
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *v4; // edi
  int v5; // ecx
  int v6; // edx
  int v7; // esi
  int v8; // eax

  v4 = (stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *> > *)(a2 + 8);
  if ( *(_DWORD *)(a2 + 8) == *(_DWORD *)(a2 + 12) )
  {
    *(_DWORD *)(a2 + 4) = world;
    *(_DWORD *)(*(_DWORD *)(a2 + 20) + 12) = a2;
    v5 = *(unsigned __int16 *)(a2 + 30);
    v6 = *(unsigned __int16 *)(a2 + 28);
    v7 = *(_DWORD *)(a2 + 20);
    v8 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v7 + 20) = v8;
    (*(void (__thiscall **)(_DWORD, _DWORD, int, int))(**(_DWORD **)(v8 + 56) + 28))(
      *(_DWORD *)(v8 + 56),
      *(_DWORD *)(v7 + 24),
      v6,
      v5);
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(v7 + 20) + 32))(*(_DWORD *)(v7 + 20), *(_DWORD *)(v7 + 24));
  }
  stlp_std::priv::_Impl_vector<void *,stlp_std::allocator<void *>>::push_back(v4, (void **)&subscriber);
}
