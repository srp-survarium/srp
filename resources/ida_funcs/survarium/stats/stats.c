void __usercall survarium::stats::stats(survarium::stats *this@<ecx>, vostok::ui::world *ui_world@<eax>)
{
  this->m_ui_world = ui_world;
  this->m_crosshair_dist = 0.0;
  this->m_odd_row_color = -8323073;
  this->m_even_row_color = -128;
  survarium::stats::create(this, this);
}
