void __thiscall vostok::ui::ui_image::draw(
        vostok::ui::ui_image *this,
        vostok::render::ui::renderer *renderer,
        vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *scene_view)
{
  int v4; // eax
  float v5; // xmm0_4
  vostok::ui::ui_image_vtbl *v6; // eax
  float *v7; // eax
  void **M_data; // xmm1_4
  float z; // xmm2_4
  float y; // xmm3_4
  float x; // xmm1_4
  vostok::render::ui::renderer *v12; // ecx
  unsigned int m_color; // [esp-4h] [ebp-94h]
  vostok::math::float2 v14; // [esp+10h] [ebp-80h] BYREF
  float v15; // [esp+18h] [ebp-78h]
  float v16; // [esp+1Ch] [ebp-74h]
  vostok::render::ui::vertex v17; // [esp+20h] [ebp-70h] BYREF
  vostok::math::float2 v18; // [esp+3Ch] [ebp-54h]
  int v19; // [esp+44h] [ebp-4Ch]
  int v20; // [esp+48h] [ebp-48h]
  unsigned int v21; // [esp+4Ch] [ebp-44h]
  void **v22; // [esp+50h] [ebp-40h]
  float v23; // [esp+54h] [ebp-3Ch]
  float v24; // [esp+58h] [ebp-38h]
  float v25; // [esp+5Ch] [ebp-34h]
  int v26; // [esp+60h] [ebp-30h]
  int v27; // [esp+64h] [ebp-2Ch]
  unsigned int v28; // [esp+68h] [ebp-28h]
  float v29; // [esp+6Ch] [ebp-24h]
  float v30; // [esp+70h] [ebp-20h]
  float v31; // [esp+74h] [ebp-1Ch]
  float v32; // [esp+78h] [ebp-18h]
  int v33; // [esp+7Ch] [ebp-14h]
  int v34; // [esp+80h] [ebp-10h]
  unsigned int v35; // [esp+84h] [ebp-Ch]
  float v36; // [esp+88h] [ebp-8h]
  float v37; // [esp+8Ch] [ebp-4h]
  char vars0; // [esp+90h] [ebp+0h] BYREF

  v4 = ((int (__thiscall *)(vostok::ui::ui_image *))this->set_color)(this);
  v14.x = *(float *)v4;
  v5 = *(float *)(v4 + 4);
  v6 = this->vostok::ui::image::__vftable;
  v14.y = v5;
  v7 = (float *)((int (__thiscall *)(vostok::ui::ui_image *))v6->~vostok::ui::ui_image)(this);
  v15 = *v7;
  v16 = v7[1];
  vostok::ui::client_to_screen(this != (vostok::ui::ui_image *)4 ? (const vostok::ui::ui_window *)this : 0, &v14);
  m_color = this->m_color;
  M_data = this->m_children._M_impl._M_end_of_storage._M_data;
  z = this->m_tex_coords.z;
  v17.m_color = LODWORD(this->m_tex_coords.w);
  v21 = v17.m_color;
  v28 = v17.m_color;
  v35 = v17.m_color;
  v17.m_position.x = v14.x;
  v18 = v14;
  y = this->m_tex_coords.y;
  v17.m_uv = (vostok::math::float2)__PAIR64__(LODWORD(z), (unsigned int)M_data);
  v22 = M_data;
  x = this->m_tex_coords.x;
  v17.m_position.y = v16 + v14.y;
  *(_QWORD *)&v17.m_position.elements[2] = 0;
  v19 = 0;
  v20 = 0;
  v23 = x;
  v24 = v15 + v14.x;
  v25 = v16 + v14.y;
  v26 = 0;
  v27 = 0;
  v29 = y;
  v30 = z;
  v31 = v15 + v14.x;
  v32 = v14.y;
  v33 = 0;
  v34 = 0;
  v36 = y;
  v37 = x;
  vostok::render::ui::renderer::draw_vertices(
    v12,
    (int)renderer,
    scene_view,
    &v17,
    (const vostok::render::ui::vertex *)&vars0,
    0,
    m_color);
  vostok::ui::ui_window::draw((vostok::ui::ui_window *)this, renderer, scene_view);
}
