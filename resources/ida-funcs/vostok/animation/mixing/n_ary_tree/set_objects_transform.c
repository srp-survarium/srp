void __userpurge vostok::animation::mixing::n_ary_tree::set_objects_transform(
        vostok::animation::mixing::n_ary_tree *this@<ecx>,
        float a2@<xmm4>,
        int a3)
{
  int v3; // eax
  int v4; // ebx
  int v5; // esi
  vostok::math::float4x4 *object_transform; // eax
  vostok::animation::mixing::n_ary_tree *v7; // ecx
  vostok::math::float4x4 v8; // [esp+10h] [ebp-40h] BYREF

  v3 = a3;
  v4 = *(_DWORD *)(a3 + 24);
  v5 = v4 + 136 * *(_DWORD *)(a3 + 36);
  if ( v4 != v5 )
  {
    while ( 1 )
    {
      object_transform = vostok::animation::mixing::n_ary_tree::get_object_transform(
                           (vostok::animation::mixing::n_ary_tree *)&v8,
                           v3,
                           a2,
                           &v8,
                           *(void **)(v4 + 128));
      vostok::animation::mixing::n_ary_tree::set_object_transform(v7, a3, *(const void **)(v4 + 128), object_transform);
      v4 += 136;
      if ( v4 == v5 )
        break;
      v3 = a3;
    }
  }
}
