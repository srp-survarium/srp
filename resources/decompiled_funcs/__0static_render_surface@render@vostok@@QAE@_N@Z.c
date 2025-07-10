void __userpurge vostok::render::static_render_surface::static_render_surface(
        vostok::render::static_render_surface *this@<ecx>,
        _DWORD *a2@<esi>,
        bool colored)
{
  vostok::render::render_surface::render_surface(this, (int)a2);
  *a2 = &vostok::render::static_render_surface::`vftable';
  a2[1] = colored + 1;
}
