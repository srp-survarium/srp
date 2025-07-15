void __userpurge survarium::options_item_int::options_item_int(
        survarium::options_tab *parent_tab@<ecx>,
        unsigned __int8 option_item_id@<al>,
        survarium::options_item_int *this,
        const char *console_command,
        const char **values,
        unsigned __int8 values_count)
{
  survarium::options_item_base::options_item_base(this, console_command, parent_tab, option_item_id, string_selector);
  this->m_values_count = values_count;
  this->__vftable = (survarium::options_item_int_vtbl *)&survarium::options_item_int::`vftable';
  this->m_values = values;
}
