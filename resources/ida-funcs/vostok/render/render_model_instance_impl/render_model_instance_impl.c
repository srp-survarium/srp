void __thiscall vostok::render::render_model_instance_impl::render_model_instance_impl(
        vostok::render::render_model_instance_impl *this,
        int a2)
{
  vostok::collision::object *v2; // ecx
  vostok::math::float4x4 *v3; // ecx
  vostok::math::float4x4 v4; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float4x4 v5; // [esp+50h] [ebp-40h] BYREF

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)a2 = &vostok::render::render_model_instance::`vftable';
  *(_BYTE *)(a2 + 268) = -1;
  *(_BYTE *)(a2 + 269) = 0;
  *(_DWORD *)(a2 + 272) = -1;
  *(_BYTE *)(a2 + 276) = 0;
  *(_BYTE *)(a2 + 277) = 0;
  *(_BYTE *)(a2 + 278) = 1;
  *(_DWORD *)a2 = &vostok::render::render_model_instance_impl::`vftable';
  vostok::collision::object::object(v2, a2 + 280);
  *(_DWORD *)(a2 + 280) = &vostok::render::render_collision_object<vostok::render::render_model_instance_impl>::`vftable';
  *(_DWORD *)(a2 + 328) = a2;
  *(_DWORD *)(a2 + 320) = 1;
  qmemcpy((void *)(a2 + 332), vostok::math::float4x4::identity(v3, &v4), 0x40u);
  qmemcpy((void *)(a2 + 396), vostok::math::float4x4::identity(0, &v5), 0x40u);
  *(_DWORD *)(a2 + 460) = a2 + 472;
  *(_DWORD *)(a2 + 464) = a2 + 472;
  *(_DWORD *)(a2 + 468) = a2 + 600;
  *(_DWORD *)(a2 + 600) = 0;
  *(_BYTE *)(a2 + 604) = 0;
}
