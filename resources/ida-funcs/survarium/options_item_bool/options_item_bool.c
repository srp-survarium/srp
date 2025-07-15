void __userpurge survarium::options_item_bool::options_item_bool(
        survarium::options_item_bool *this@<ecx>,
        _DWORD *a2@<eax>,
        survarium::options_tab *parent_tab,
        char *console_command,
        unsigned __int8 option_item_id)
{
  survarium::options_item_base::options_item_base(
    this,
    (int)a2,
    parent_tab,
    console_command,
    option_item_id,
    bool_selector);
  *a2 = &survarium::options_item_bool::`vftable';
}
