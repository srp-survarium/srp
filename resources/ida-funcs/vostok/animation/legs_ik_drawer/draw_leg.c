void __userpurge vostok::animation::legs_ik_drawer::draw_leg(
        vostok::animation::legs_ik_drawer *this@<ecx>,
        int a2@<esi>,
        vostok::math::aabb *up_leg,
        vostok::math::aabb *knee,
        vostok::math::aabb *leg,
        vostok::math::aabb *foot,
        const vostok::math::color *up_leg_color,
        const vostok::math::color *knee_color,
        const vostok::math::color *leg_color,
        const vostok::math::color *foot_color,
        float cross_half_size)
{
  vostok::render::debug::renderer *v11; // ecx
  vostok::render::debug::renderer *v12; // ecx
  vostok::render::debug::renderer *v13; // ecx
  vostok::render::debug::renderer *v14; // ecx
  vostok::render::debug::renderer *v15; // ecx
  vostok::render::debug::renderer *v16; // ecx
  vostok::render::debug::renderer *v17; // ecx
  vostok::render::vertex_colored v18; // [esp-8h] [ebp-14h]
  vostok::render::vertex_colored v19; // [esp-8h] [ebp-14h]
  vostok::render::vertex_colored v20; // [esp-8h] [ebp-14h]
  vostok::render::vertex_colored v21; // [esp-8h] [ebp-14h]

  vostok::render::debug::renderer::draw_origin(
    (vostok::render::debug::renderer *)this,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    up_leg,
    0.0);
  vostok::render::debug::renderer::draw_origin(
    v11,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    knee,
    0.0);
  vostok::render::debug::renderer::draw_origin(
    v12,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    leg,
    0.0);
  vostok::render::debug::renderer::draw_origin(
    v13,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    foot,
    0.0);
  LODWORD(v18.position.z) = up_leg_color;
  LODWORD(v18.position.y) = &knee[2];
  LODWORD(v18.position.x) = &up_leg[2];
  vostok::render::debug::renderer::draw_line(
    v14,
    a2 + 4,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    v18);
  LODWORD(v19.position.z) = knee_color;
  LODWORD(v19.position.y) = &leg[2];
  LODWORD(v19.position.x) = &knee[2];
  vostok::render::debug::renderer::draw_line(
    v15,
    a2 + 4,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    v19);
  LODWORD(v20.position.z) = leg_color;
  LODWORD(v20.position.y) = &foot[2];
  LODWORD(v20.position.x) = &leg[2];
  vostok::render::debug::renderer::draw_line(
    v16,
    a2 + 4,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    v20);
  LODWORD(v21.position.z) = foot_color;
  LODWORD(v21.position.y) = &foot[2];
  LODWORD(v21.position.x) = &up_leg[2];
  vostok::render::debug::renderer::draw_line(
    v17,
    a2 + 4,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)a2,
    (vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *)(a2 + 4),
    v21);
}
