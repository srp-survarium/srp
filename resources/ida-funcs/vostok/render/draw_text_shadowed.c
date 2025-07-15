void __usercall vostok::render::draw_text_shadowed(
        unsigned int pos_x@<edi>,
        unsigned int pos_y@<esi>,
        vostok::ui::font *in_font,
        const char *str,
        int clr)
{
  int v5; // eax

  v5 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 1.0);
  vostok::render::draw_text(in_font, str, pos_x + 1, pos_y + 1, v5);
  vostok::render::draw_text(in_font, str, pos_x, pos_y, clr);
}
