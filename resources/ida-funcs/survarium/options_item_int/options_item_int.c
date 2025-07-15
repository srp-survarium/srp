void __userpurge survarium::options_item_int::options_item_int(
        survarium::options_item_int *this@<ecx>,
        int a2@<eax>,
        survarium::options_tab *parent_tab,
        char *console_command,
        unsigned __int8 option_item_id,
        const char **values,
        unsigned __int8 values_count)
{
  survarium::options_item_base::options_item_base(
    this,
    a2,
    parent_tab,
    console_command,
    option_item_id,
    string_selector);
  *(_DWORD *)(a2 + 24) = values;
  *(_BYTE *)(a2 + 28) = values_count;
  *(_DWORD *)a2 = &survarium::options_item_int::`vftable';
}
