void __thiscall vostok::collision::box_geometry_instance::enumerate_primitives(
        vostok::collision::box_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::box_geometry_instance_vtbl *v3; // edx
  const vostok::math::float4x4 *(__thiscall *get_matrix)(vostok::collision::geometry_instance *); // eax
  const vostok::math::float4x4 *v5; // eax
  __int64 v6; // [esp+4h] [ebp-5Ch]
  const vostok::math::float4x4 *v7; // [esp+Ch] [ebp-54h]
  int v8; // [esp+10h] [ebp-50h] BYREF
  __int64 v9; // [esp+14h] [ebp-4Ch]
  const vostok::math::float4x4 *v10; // [esp+1Ch] [ebp-44h]
  vostok::math::float4x4 result; // [esp+20h] [ebp-40h] BYREF

  v3 = this->__vftable;
  v7 = clear_value;
  LODWORD(v6) = clear_value;
  HIDWORD(v6) = clear_value;
  v10 = clear_value;
  get_matrix = v3->get_matrix;
  v8 = 1;
  v9 = v6;
  v5 = get_matrix(&this->vostok::collision::geometry_instance);
  vostok::math::mul4x3(&result, v5, transform);
  cb->enumerate(cb, &result, (const vostok::collision::primitive *)&v8);
}
