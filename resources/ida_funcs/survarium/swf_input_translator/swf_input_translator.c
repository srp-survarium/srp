void __usercall survarium::swf_input_translator::swf_input_translator(
        survarium::swf_input_translator *this@<ecx>,
        int a2@<eax>)
{
  char v2; // [esp+Bh] [ebp-1h]

  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  *(_BYTE *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 8) = a2;
  *(_DWORD *)(a2 + 12) = a2;
  *(_BYTE *)(a2 + 20) = v2;
  survarium::swf_input_translator::initialize(
    this,
    (stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *)a2);
}
