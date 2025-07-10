void __usercall vostok::render::user_render_model_instance::assign_surface(
        vostok::render::user_render_model_instance *this@<ecx>,
        _DWORD *a2@<eax>)
{
  a2[98] = this;
  a2[99] = this;
  a2[100] = a2 + 81;
  a2[101] = a2;
  a2[104] = 3;
}
