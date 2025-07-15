void __thiscall vostok::render::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128>>>::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128>>>(
        vostok::render::map<vostok::fixed_string<128>,vostok::render::effect_descriptor *,stlp_std::less<vostok::fixed_string<128> > > *this)
{
  char v1; // [esp+1Bh] [ebp-1h]

  *(_DWORD *)&this->_M_t._M_header._M_data._M_color = 0;
  this->_M_t._M_header._M_data._M_parent = 0;
  this->_M_t._M_header._M_data._M_left = 0;
  this->_M_t._M_header._M_data._M_right = 0;
  this->_M_t._M_header._M_data._M_color = 0;
  this->_M_t._M_header._M_data._M_parent = 0;
  this->_M_t._M_node_count = 0;
  this->_M_t._M_key_compare.gap0 = v1;
  this->_M_t._M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)this;
  this->_M_t._M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)this;
}
