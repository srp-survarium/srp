int __cdecl vostok::sound::ogg_utils::ov_read_func(
        unsigned __int8 *ptr,
        unsigned int size,
        unsigned int nmemb,
        const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *datasource)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v4; // ecx
  vostok::resources::pinned_ptr_mutable<unsigned char> *v5; // ecx
  unsigned __int8 *v6; // esi
  signed int v7; // eax
  unsigned int v8; // eax
  int v9; // ebx
  vostok::resources::pinned_ptr_const<unsigned char> *v10; // ecx
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp+0h] [ebp-20h] BYREF
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> ptra; // [esp+10h] [ebp-10h] BYREF
  int v14; // [esp+14h] [ebp-Ch]
  int v15; // [esp+18h] [ebp-8h]
  unsigned int v16; // [esp+1Ch] [ebp-4h]

  v12.m_object = v4.m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(
    &v12,
    datasource);
  vostok::resources::pinned_ptr_const<unsigned char>::pinned_ptr_const<unsigned char>(
    v5,
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>)&ptra,
    v12);
  v6 = (unsigned __int8 *)datasource[1].m_object + v14;
  v16 = v15 - (unsigned int)datasource[1].m_object;
  *(float *)&v12.m_object = (double)v16 / (double)size;
  v7 = vostok::math::floor(*(float *)&v12.m_object);
  v8 = -(-v7 & -(v7 > 0));
  v9 = nmemb + (v8 < nmemb ? v8 - nmemb : 0);
  memcpy(ptr, v6, size * v9);
  datasource[1].m_object = (vostok::resources::managed_resource *)&v6[size * v9 - v14];
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>::~pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation>(v10);
  return v9;
}
