void __usercall vostok::render::engine::world::draw_text(
        unsigned int start_selection@<ecx>,
        unsigned int end_selection@<eax>,
        vostok::vectora<vostok::render::ui::vertex> *output,
        const char **text,
        const vostok::ui::font *font,
        const vostok::math::float2 *position,
        const vostok::math::color *text_color,
        const vostok::math::color *selection_color,
        unsigned int max_line_width,
        bool is_multiline)
{
  vostok::render::make_ui_vertices(
    position,
    output,
    *text,
    font,
    text_color,
    selection_color,
    max_line_width,
    is_multiline,
    start_selection,
    end_selection);
}
