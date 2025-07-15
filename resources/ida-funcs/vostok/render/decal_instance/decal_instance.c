void __userpurge vostok::render::decal_instance::decal_instance(
        vostok::render::decal_instance *this@<ecx>,
        int a2@<edi>,
        vostok::collision::space_partitioning_tree *tree,
        vostok::render::decal_properties *properties,
        const unsigned int id)
{
  vostok::render::decal_instance *v5; // ecx
  vostok::fixed_string<260> *v6; // ecx
  int v7; // eax
  vostok::buffer_string v8[23]; // [esp+4h] [ebp-114h] BYREF

  *(_DWORD *)a2 = 0;
  vostok::render::decal_properties::decal_properties((vostok::render::decal_properties *)this, a2 + 4);
  vostok::math::create_identity_aabb((vostok::math::aabb *)(a2 + 100));
  *(_DWORD *)(a2 + 132) = 0;
  *(_DWORD *)(a2 + 136) = 0;
  *(_DWORD *)(a2 + 140) = -1;
  *(_DWORD *)(a2 + 124) = id;
  *(_DWORD *)(a2 + 128) = tree;
  *(_DWORD *)(a2 + 144) = 0;
  *(_DWORD *)(a2 + 148) = 0;
  *(_BYTE *)(a2 + 152) = 0;
  vostok::render::decal_instance::set_properties(v5, (vostok::render::decal_properties *)a2, (char *)properties);
  v7 = *(_DWORD *)(a2 + 68);
  if ( v7 )
    vostok::fixed_string<260>::fixed_string<260>(v6, v8, *(char **)(v7 + 264));
}
