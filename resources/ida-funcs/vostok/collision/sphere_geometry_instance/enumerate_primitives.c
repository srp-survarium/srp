void __userpurge vostok::collision::sphere_geometry_instance::enumerate_primitives(
        vostok::collision::sphere_geometry_instance *this@<ecx>,
        int a2@<xmm0>,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::enumerate_primitives_callback_vtbl *v3; // edi
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 *v5; // eax
  vostok::math::float4x4 v6; // [esp+8h] [ebp-50h] BYREF
  _DWORD v7[4]; // [esp+48h] [ebp-10h] BYREF

  vostok::collision::sphere_geometry_instance::radius(this);
  v7[0] = 0;
  v3 = cb->__vftable;
  v7[1] = a2;
  v7[2] = 0;
  v7[3] = 0;
  v5 = vostok::math::float4x4::identity(v4, &v6);
  v3->enumerate(cb, v5, (const vostok::collision::primitive *)v7);
}


void __userpurge vostok::collision::sphere_geometry_instance::enumerate_primitives(
        vostok::collision::sphere_geometry_instance *this@<ecx>,
        int a2@<xmm0>,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::enumerate_primitives_callback_vtbl *v4; // eax
  _DWORD v5[4]; // [esp+0h] [ebp-10h] BYREF

  vostok::collision::sphere_geometry_instance::radius(this);
  v4 = cb->__vftable;
  v5[0] = 0;
  v5[1] = a2;
  v5[2] = 0;
  v5[3] = 0;
  v4->enumerate(cb, transform, (const vostok::collision::primitive *)v5);
}
