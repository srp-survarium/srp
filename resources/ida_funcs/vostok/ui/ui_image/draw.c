void __thiscall vostok::ui::ui_image::draw(
        vostok::ui::ui_image *this,
        vostok::render::ui::renderer *renderer,
        const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  float *v4; // eax
  void (__thiscall *v5)(struct vostok::ui::ui_image *); // edx
  void **M_data; // xmm1_4
  float z; // xmm5_4
  float x; // xmm6_4
  float y; // xmm2_4
  unsigned int m_color; // [esp-4h] [ebp-94h]
  vostok::math::float2 pos; // [esp+10h] [ebp-80h] BYREF
  vostok::math::float2 size; // [esp+18h] [ebp-78h]
  vostok::render::ui::vertex vertices[4]; // [esp+20h] [ebp-70h] BYREF
  char vars0; // [esp+90h] [ebp+0h] BYREF

  v4 = (float *)((int (__thiscall *)(vostok::ui::ui_image *))this->set_color)(this);
  pos.x = *v4;
  v5 = this->~vostok::ui::ui_image;
  pos.y = v4[1];
  size = *(vostok::math::float2 *)((int (__thiscall *)(vostok::ui::ui_image *))v5)(this);
  vostok::ui::client_to_screen(this != (vostok::ui::ui_image *)4 ? (const vostok::ui::ui_window *)this : 0, &pos);
  M_data = this->m_children._M_impl._M_end_of_storage._M_data;
  z = this->m_tex_coords.z;
  x = this->m_tex_coords.x;
  vertices[0].m_color = LODWORD(this->m_tex_coords.w);
  vertices[1].m_color = vertices[0].m_color;
  vertices[2].m_color = vertices[0].m_color;
  vertices[3].m_color = vertices[0].m_color;
  m_color = this->m_color;
  vertices[0].m_uv = (vostok::math::float2)__PAIR64__(LODWORD(z), (unsigned int)M_data);
  vertices[1].m_uv = (vostok::math::float2)__PAIR64__(LODWORD(x), (unsigned int)M_data);
  vertices[0].m_position.x = pos.x;
  *(vostok::math::float2 *)&vertices[1].m_position.x = pos;
  y = this->m_tex_coords.y;
  *(_QWORD *)&vertices[0].m_position.elements[1] = COERCE_UNSIGNED_INT(size.y + pos.y);
  vertices[0].m_position.w = 0.0;
  *(_QWORD *)&vertices[1].m_position.elements[2] = 0;
  vertices[2].m_position.x = size.x + pos.x;
  *(_QWORD *)&vertices[2].m_position.elements[1] = *(_QWORD *)&vertices[0].m_position.elements[1];
  vertices[2].m_position.w = 0.0;
  vertices[2].m_uv = (vostok::math::float2)__PAIR64__(LODWORD(z), LODWORD(y));
  vertices[3].m_position.x = size.x + pos.x;
  *(_QWORD *)&vertices[3].m_position.elements[1] = LODWORD(pos.y);
  vertices[3].m_position.w = 0.0;
  vertices[3].m_uv = (vostok::math::float2)__PAIR64__(LODWORD(x), LODWORD(y));
  vostok::render::ui::renderer::draw_vertices(
    (vostok::render::ui::renderer *)&vars0,
    (int *)renderer,
    scene_view,
    vertices,
    (const vostok::render::ui::vertex *)&vars0,
    0,
    m_color);
  vostok::ui::ui_window::draw((vostok::ui::ui_window *)this, renderer, scene_view);
}
