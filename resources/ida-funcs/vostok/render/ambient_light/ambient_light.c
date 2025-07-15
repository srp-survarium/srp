void __userpurge vostok::render::ambient_light::ambient_light(
        vostok::render::ambient_light *this@<ecx>,
        int a2@<esi>,
        vostok::collision::space_partitioning_tree *tree,
        const vostok::render::ambient_light_properties *properties,
        const unsigned int id)
{
  vostok::collision::space_partitioning_tree *v5; // eax
  double v6; // st7
  vostok::render::ambient_light *v7; // ecx
  const vostok::render::ambient_light_properties *v8; // [esp+0h] [ebp-4h]

  *(_DWORD *)a2 = 0;
  vostok::math::create_identity_aabb((vostok::math::aabb *)(a2 + 116));
  v5 = tree;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_DWORD *)(a2 + 156) = -1;
  *(_DWORD *)(a2 + 140) = v5;
  *(_DWORD *)(a2 + 152) = id;
  *(_BYTE *)(a2 + 164) = 0;
  tree = (vostok::collision::space_partitioning_tree *)a2;
  v6 = vostok::math::random32::random_f((vostok::math::random32 *)&tree, 1.0);
  v8 = properties;
  *(float *)(a2 + 160) = v6 * 0.1;
  vostok::render::ambient_light::set_properties(v7, (vostok::collision::geometry_instance *)a2, (int)v8);
}
