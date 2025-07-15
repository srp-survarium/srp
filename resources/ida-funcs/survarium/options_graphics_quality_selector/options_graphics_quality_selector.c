void __usercall survarium::options_graphics_quality_selector::options_graphics_quality_selector(
        survarium::options_graphics_quality_selector *this@<ecx>,
        survarium::options_tab *parent_tab@<eax>)
{
  survarium::options_item_base::options_item_base(this, "r_graphics_quality", parent_tab, 8u, string_selector);
  this->m_values = graphics_quality_data;
  this->m_values_count = 6;
  this->__vftable = (survarium::options_graphics_quality_selector_vtbl *)&survarium::options_graphics_quality_selector::`vftable';
}
