void __usercall vostok::render::render_output_window::goto_fullscreen(
        vostok::render::render_output_window *this@<ecx>,
        int a2@<eax>)
{
  vostok::render::res_render_output::goto_fullscreen((vostok::render::res_render_output *)this, *(_DWORD *)(a2 + 11488));
}
