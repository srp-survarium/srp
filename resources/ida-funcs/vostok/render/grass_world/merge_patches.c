void __usercall vostok::render::grass_world::merge_patches(vostok::render::grass_world *this@<ecx>, int a2@<eax>)
{
  vostok::render::grass_patch **v2; // ebx
  vostok::render::grass_patch **i; // esi
  vostok::render::grass_patch *v4; // edi
  vostok::render::grass_patch *v5; // ecx

  v2 = *(vostok::render::grass_patch ***)(a2 + 292);
  for ( i = *(vostok::render::grass_patch ***)(a2 + 288); i != v2; ++i )
  {
    v4 = *i;
    vostok::render::grass_patch::init_collision((vostok::render::grass_patch *)this, *i);
    vostok::render::grass_patch::merge_instances(v5, v4);
  }
}
