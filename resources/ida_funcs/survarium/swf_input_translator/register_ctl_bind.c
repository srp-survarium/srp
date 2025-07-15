void __userpurge survarium::swf_input_translator::register_ctl_bind(
        survarium::swf_input_translator *this@<ecx>,
        stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *a2@<eax>,
        vostok::input::enum_keyboard key,
        int scan)
{
  stlp_std::less<enum vostok::input::enum_keyboard> *v4; // eax
  int v5; // edx

  v4 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &key);
  *(_DWORD *)&v4->gap0 = key;
  *(_WORD *)&v4[4].gap0 = 0;
  v5 = scan;
  *(_WORD *)&v4[6].gap0 = 0;
  *(_DWORD *)&v4[8].gap0 = v5;
  v4[12].gap0 = 0;
  v4[13].gap0 = 0;
}
