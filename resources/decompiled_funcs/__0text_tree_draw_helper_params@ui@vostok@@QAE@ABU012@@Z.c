void __thiscall vostok::ui::text_tree_draw_helper_params::text_tree_draw_helper_params(
        vostok::ui::text_tree_draw_helper_params *this,
        const vostok::ui::text_tree_draw_helper_params *__that)
{
  this->color1 = __that->color1;
  this->color2 = __that->color2;
  this->fnt = __that->fnt;
  this->is_multipaged = __that->is_multipaged;
  this->row_height = __that->row_height;
  this->space_between_pages = __that->space_between_pages;
  this->start_pos = __that->start_pos;
}
