int __usercall vostok::animation::mixing::animation_lexeme_parameters::animation_intervals_count@<eax>(
        const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animation@<eax>)
{
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *v1; // ecx
  const unsigned __int8 *v2; // esi
  int channel_id; // eax
  int result; // eax
  int v5; // esi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v6; // [esp-4h] [ebp-18h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+4h] [ebp-10h] BYREF
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation> pinned_animation; // [esp+8h] [ebp-Ch] BYREF

  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    animation);
  v6.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v6,
    &object);
  vostok::resources::pinned_ptr_base<vostok::render::texture_data_resource const>::pinned_ptr_base<vostok::render::texture_data_resource const>(
    v1,
    &pinned_animation.m_resource,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)v6.m_object);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
  v2 = pinned_animation.m_data + 8;
  channel_id = vostok::animation::animation_event_channels::get_channel_id(
                 (vostok::animation::animation_event_channels *)pinned_animation.m_data + 1,
                 "anim_intervals");
  if ( channel_id == -1 )
  {
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
    return 1;
  }
  else
  {
    v5 = *(_DWORD *)&v2[44 * channel_id + 32 + *((_DWORD *)v2 + 1)];
    vostok::resources::pinned_ptr_base<unsigned char const>::~pinned_ptr_base<unsigned char const>((vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation> *)&pinned_animation);
    result = 1;
    if ( v5 )
      return v5;
  }
  return result;
}
