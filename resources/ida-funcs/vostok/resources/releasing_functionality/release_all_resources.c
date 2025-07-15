char __thiscall vostok::resources::releasing_functionality::release_all_resources(
        vostok::resources::releasing_functionality *this,
        vostok::resources::resource_base *a2)
{
  void (__thiscall *decrease_quality)(struct vostok::resources::resource_base *, unsigned int); // edi
  _DWORD *v3; // esi
  _DWORD *v4; // ebx
  char v6; // [esp+13h] [ebp-1h]

  decrease_quality = a2->__vftable[1].decrease_quality;
  v6 = 1;
  while ( decrease_quality )
  {
    v3 = (_DWORD *)*((_DWORD *)decrease_quality + 4);
    if ( v3 )
    {
      do
      {
        v4 = (_DWORD *)v3[38];
        if ( v3[27] == 1 || !(*(unsigned __int8 (__thiscall **)(_DWORD *))(*v3 + 24))(v3) )
          vostok::resources::releasing_functionality::release_resource(
            this,
            a2,
            (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v3);
        v3 = v4;
      }
      while ( v4 );
    }
    if ( *((_DWORD *)decrease_quality + 4) )
      v6 = 0;
    decrease_quality = *(void (__thiscall **)(struct vostok::resources::resource_base *, unsigned int))decrease_quality;
  }
  return v6;
}
