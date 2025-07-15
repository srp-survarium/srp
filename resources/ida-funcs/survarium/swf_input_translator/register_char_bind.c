void __thiscall survarium::swf_input_translator::register_char_bind(
        survarium::swf_input_translator *this,
        stlp_std::priv::_Rb_tree_node_base *key,
        stlp_std::priv::_Rb_tree_node_base *scan)
{
  stlp_std::priv::_Rb_tree_node_base **v3; // eax

  v3 = stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
         &this->char_map,
         (const vostok::input::enum_keyboard *)&key);
  *v3 = key;
  v3[1] = scan;
  *((_BYTE *)v3 + 8) = 1;
}
