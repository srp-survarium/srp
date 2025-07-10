void __userpurge survarium::swf_input_translator::register_char_bind(
        survarium::swf_input_translator *this@<ecx>,
        stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *a2@<eax>,
        vostok::input::enum_keyboard key,
        int scan,
        bool translate)
{
  stlp_std::less<enum vostok::input::enum_keyboard> *v5; // eax
  int v6; // edx

  v5 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &key);
  *(_DWORD *)&v5->gap0 = key;
  *(_WORD *)&v5[4].gap0 = 0;
  v6 = scan;
  *(_WORD *)&v5[6].gap0 = 0;
  *(_DWORD *)&v5[8].gap0 = v6;
  v5[12].gap0 = 1;
  v5[13].gap0 = 1;
}
