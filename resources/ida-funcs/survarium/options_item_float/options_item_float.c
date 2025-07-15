void __userpurge survarium::options_item_float::options_item_float(
        survarium::options_tab *parent_tab@<ecx>,
        unsigned __int8 option_item_id@<al>,
        survarium::options_item_float *this,
        const char *console_command,
        float step)
{
  survarium::options_item_base::options_item_base(this, console_command, parent_tab, option_item_id, slider_selector);
  this->__vftable = (survarium::options_item_float_vtbl *)&survarium::options_item_float::`vftable';
  this->m_step = step;
}
