void __userpurge survarium::options_item_bool::options_item_bool(
        survarium::options_tab *parent_tab@<ecx>,
        unsigned __int8 option_item_id@<al>,
        survarium::options_item_bool *this,
        const char *console_command)
{
  survarium::options_item_base::options_item_base(this, console_command, parent_tab, option_item_id, bool_selector);
  this->__vftable = (survarium::options_item_bool_vtbl *)&survarium::options_item_bool::`vftable';
}
