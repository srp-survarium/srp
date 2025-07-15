char __usercall convert_channels_ids@<al>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *from@<eax>,
        vostok::resources::managed_resource *a2@<ecx>,
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *to,
        unsigned __int8 channels_ids)
{
  vostok::resources::pinned_ptr_mutable<unsigned char> *v4; // ecx
  vostok::resources::managed_resource *v5; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v6; // ecx
  vostok::resources::pinned_ptr_const<unsigned char> *v7; // ecx
  int v8; // edi
  int v9; // esi
  vostok::animation::animation_event_channels *v10; // ebx
  int v11; // eax
  int channel_id; // eax
  vostok::resources::pinned_ptr_const<unsigned char> *v13; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v15[4]; // [esp-4h] [ebp-2Ch] BYREF
  _BYTE v16[4]; // [esp+Ch] [ebp-1Ch] BYREF
  int v17; // [esp+10h] [ebp-18h]
  _BYTE v18[4]; // [esp+18h] [ebp-10h] BYREF
  vostok::animation::animation_event_channels *v19; // [esp+1Ch] [ebp-Ch]
  char v20; // [esp+27h] [ebp-1h]
  unsigned __int8 v21; // [esp+37h] [ebp+Fh]

  v15[0].m_object = a2;
  v20 = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    v15,
    from);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v4,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v16,
    v15[0]);
  v15[0].m_object = v5;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    v15,
    to);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v6,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)v18,
    v15[0]);
  v21 = channels_ids;
  if ( channels_ids )
  {
    v8 = *(_DWORD *)(v17 + 12);
    v9 = v17 + 8;
    v10 = v19 + 1;
    do
    {
      v11 = v21 & ~(v21 - 1);
      channel_id = vostok::animation::animation_event_channels::get_channel_id(
                     v10,
                     (char *)(v9
                            + v8
                            + 44
                            * (((v11 & 0xAAAAAAAA) != 0)
                             | (unsigned __int8)(2
                                               * (((v11 & 0xCCCCCCCC) != 0)
                                                | (2
                                                 * (((v11 & 0xF0F0F0F0) != 0)
                                                  | (2 * (((v11 & 0xFF00FF00) != 0) | (2 * ((v11 & 0xFFFF0000) != 0)))))))))));
      if ( channel_id != -1 )
      {
        v7 = (vostok::resources::pinned_ptr_const<unsigned char> *)channel_id;
        v20 |= 1 << channel_id;
      }
      v21 &= v21 - 1;
    }
    while ( v21 );
  }
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v7,
    (int)v18);
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(
    v13,
    (int)v16);
  return v20;
}
