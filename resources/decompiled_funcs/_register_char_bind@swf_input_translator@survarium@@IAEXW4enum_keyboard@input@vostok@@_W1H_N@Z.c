void __userpurge survarium::swf_input_translator::register_char_bind(
        survarium::swf_input_translator *this@<ecx>,
        stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *a2@<eax>,
        vostok::input::enum_keyboard key,
        wchar_t c,
        wchar_t c_shift,
        int scan,
        bool translate)
{
  stlp_std::less<enum vostok::input::enum_keyboard> *v7; // eax
  wchar_t v8; // dx
  wchar_t v9; // cx
  int v10; // edx

  v7 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         a2,
         &key);
  v8 = c;
  *(_DWORD *)&v7->gap0 = key;
  v9 = c_shift;
  *(_WORD *)&v7[4].gap0 = v8;
  v10 = scan;
  *(_WORD *)&v7[6].gap0 = v9;
  LOBYTE(v9) = translate;
  *(_DWORD *)&v7[8].gap0 = v10;
  v7[12].gap0 = v9;
  v7[13].gap0 = 1;
}
