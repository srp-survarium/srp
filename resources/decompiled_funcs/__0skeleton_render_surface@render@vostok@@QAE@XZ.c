void __usercall vostok::render::skeleton_render_surface::skeleton_render_surface(
        vostok::render::skeleton_render_surface *this@<ecx>,
        _DWORD *a2@<esi>)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  *a2 = &vostok::render::skeleton_render_surface::`vftable';
  a2[1] = 3;
}
