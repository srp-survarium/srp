void __thiscall vostok::vfs::fixup_node::fixup_inlined_node(vostok::vfs::fixup_node *this)
{
  char *v2; // [esp+10h] [ebp-20h] BYREF
  unsigned int m_size; // [esp+14h] [ebp-1Ch]
  vostok::const_buffer buffer; // [esp+18h] [ebp-18h] BYREF
  char v5; // [esp+23h] [ebp-Dh]
  unsigned int data_offs; // [esp+24h] [ebp-Ch]
  vostok::const_buffer inline_data; // [esp+28h] [ebp-8h] BYREF

  inline_data.m_data = 0;
  inline_data.m_size = 0;
  vostok::vfs::get_inline_data<1>(this->node, &inline_data);
  data_offs = (unsigned int)inline_data.m_data;
  v5 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)inline_data.m_data);
  v2 = &this->buffer_origin[data_offs];
  m_size = inline_data.m_size;
  buffer.m_data = (const char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                  (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)inline_data.m_size,
                                  (int)&v2);
  buffer.m_size = m_size;
  vostok::vfs::set_inline_data<1>(this->node, &buffer);
}
