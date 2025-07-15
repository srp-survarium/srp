double __usercall survarium::computed_shooting_animation_time_scale@<st0>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *shooting_animation@<eax>,
        vostok::resources::managed_resource *a2@<ecx>,
        const float rounds_per_second)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v3; // ecx
  int v4; // ebx
  int v5; // esi
  int v6; // edi
  int v7; // ecx
  unsigned int v8; // ebx
  int v9; // edx
  _DWORD *v10; // eax
  int v11; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v12; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v14; // [esp-4h] [ebp-28h] BYREF
  _BYTE v15[4]; // [esp+Ch] [ebp-18h] BYREF
  int v16; // [esp+10h] [ebp-14h]
  float v17; // [esp+1Ch] [ebp-8h]
  float i; // [esp+20h] [ebp-4h]

  v14.m_object = a2;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v14,
    shooting_animation);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v3,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v15,
    v14);
  v17 = 0.0;
  v4 = *(_DWORD *)(v16 + 12);
  v5 = v16 + 8;
  for ( i = 0.0; ; LODWORD(i) += 44 )
  {
    v6 = v5 + LODWORD(i) + v4;
    if ( !vostok::strings::compare((const char *)v6, "shoot") )
      break;
    ++LODWORD(v17);
  }
  v7 = *(_DWORD *)(v6 + 32);
  v8 = 0;
  v9 = 0;
  if ( v7 )
  {
    do
    {
      if ( !*(_BYTE *)(v6 + 32 + *(_DWORD *)(v6 + 36) + v9) )
        ++v8;
      ++v9;
    }
    while ( v9 != v7 );
  }
  v10 = (_DWORD *)(*(_DWORD *)(v16 + 20) + v16);
  v11 = 16 * *v10;
  v17 = *(float *)((char *)&v10[5 * *v10 - 1] + v10[1]);
  v12 = (vostok::resources::pinned_ptr_const<unsigned char> *)(v10[1] + v11);
  i = *(float *)((char *)v10 + (_DWORD)v12);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v12,
    (int)v15);
  return rounds_per_second / ((double)v8 / ((v17 - i) * 0.033333335));
}
