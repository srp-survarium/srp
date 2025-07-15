void __userpurge survarium::options_item_float::options_item_float(
        survarium::options_item_float *this@<ecx>,
        int a2@<eax>,
        survarium::options_tab *parent_tab,
        char *console_command,
        unsigned __int8 option_item_id,
        float step)
{
  survarium::options_item_base::options_item_base(
    this,
    a2,
    parent_tab,
    console_command,
    option_item_id,
    slider_selector);
  *(_DWORD *)a2 = &survarium::options_item_float::`vftable';
  *(float *)(a2 + 24) = step;
}
