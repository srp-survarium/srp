void __userpurge vostok::render::backend::set_render_targets(
        vostok::render::backend *this@<ecx>,
        const vostok::render::render_target *rt0@<eax>,
        const vostok::render::render_target *rt1,
        const vostok::render::render_target *rt2,
        const vostok::render::render_target *rt3)
{
  int v6; // edx

  vostok::render::backend::set_render_target(this, enum_target_rt0, rt0);
  vostok::render::backend::set_render_target(this, (vostok::render::enum_render_target_enum)(v6 + 1), rt1);
  vostok::render::backend::set_render_target(this, enum_target_rt2, rt2);
  vostok::render::backend::set_render_target(this, enum_target_rt3, rt3);
}
