void __usercall vostok::ui::text_tree_draw_helper_params::text_tree_draw_helper_params(
        vostok::ui::text_tree_draw_helper_params *this@<ecx>,
        int a2@<eax>)
{
  *(_DWORD *)a2 = this->color1;
  *(_DWORD *)(a2 + 4) = this->color2;
  *(_DWORD *)(a2 + 8) = this->fnt;
  *(_BYTE *)(a2 + 12) = this->is_multipaged;
  *(float *)(a2 + 16) = this->row_height;
  *(float *)(a2 + 20) = this->space_between_pages;
  *(vostok::math::float2 *)(a2 + 24) = this->start_pos;
}
