void __userpurge vostok::render::static_render_surface::create_shadow_pass_geometry_::_2_::opt_static_vertex::set(
        const vostok::render::static_vertex_type *base@<eax>,
        vostok::math::half *a2@<ecx>,
        vostok::render::static_render_surface::create_shadow_pass_geometry::__l2::opt_static_vertex *this)
{
  vostok::render::static_render_surface::create_shadow_pass_geometry::__l2::opt_static_vertex *v3; // ebx
  vostok::math::half *v5; // ecx
  int v6; // eax
  int v7; // [esp+6h] [ebp-Eh]
  vostok::math::half3 v8; // [esp+Ah] [ebp-Ah] BYREF
  _WORD *v9; // [esp+10h] [ebp-4h]

  v3 = this;
  v9 = vostok::math::half::half(a2, (_WORD *)&this + 1, 0);
  vostok::math::half3::half3(&v8, &base->position, v5);
  LOWORD(v7) = *(_WORD *)(v6 + 4);
  HIWORD(v7) = *v9;
  *(_DWORD *)&v3->position.x.data = *(_DWORD *)v6;
  *(_DWORD *)&v3->position.z.data = v7;
  v3->uv = base->uv;
  v3->normal.m_value = base->normal.m_value;
}
