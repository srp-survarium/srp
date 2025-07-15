void __thiscall vostok::render::grass_world::remove_patches(vostok::render::grass_world *this, _DWORD *a2)
{
  vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *i; // edi

  for ( i = (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2[82];
        i != (vostok::intrusive_ptr<vostok::render::render_target,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)a2[83];
        i += 4142 )
  {
    vostok::render::grass_patch::~grass_patch((vostok::render::grass_patch *)this, i);
  }
  a2[83] = a2[82];
  a2[86] = a2[85];
}
