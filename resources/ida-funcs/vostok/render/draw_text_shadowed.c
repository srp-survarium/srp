void __usercall vostok::render::draw_text_shadowed(
        const char *str@<eax>,
        unsigned int pos_y@<esi>,
        const vostok::ui::font *in_font,
        unsigned int pos_x,
        unsigned int clr)
{
  int v6; // eax

  v6 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(0.0), 0.0, 1.0);
  vostok::render::draw_text(str, in_font, pos_x + 1, pos_y + 1, (vostok::math::color)v6);
  vostok::render::draw_text(str, in_font, pos_x, pos_y, (vostok::math::color)clr);
}
