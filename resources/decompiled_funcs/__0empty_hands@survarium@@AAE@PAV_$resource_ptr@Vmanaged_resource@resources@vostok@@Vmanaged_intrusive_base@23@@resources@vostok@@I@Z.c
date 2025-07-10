void __userpurge survarium::empty_hands::empty_hands(
        survarium::empty_hands *this@<ecx>,
        int a2@<esi>,
        vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *animations,
        unsigned int animations_count)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)(a2 + 332) = animations;
  *(_DWORD *)a2 = &survarium::empty_hands::`vftable';
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 336) = animations_count;
  *(_DWORD *)(a2 + 340) = 0;
  vostok::math::float4x4::identity((vostok::math::float4x4 *)(a2 + 264));
}
