void __thiscall survarium::artefact_lifebone_core::load_core(
        survarium::artefact_lifebone_core *this,
        vostok::configs::binary_config_value config)
{
  const vostok::configs::binary_config_value *v2; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v3; // ecx
  const vostok::configs::binary_config_value *v4; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v5; // ecx
  const vostok::variant<32> **amount; // [esp+24h] [ebp-4h]

  v2 = vostok::configs::binary_config_value::operator[](&config, "amount");
  amount = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v3, (int)v2);
  survarium::inventory_item::set_amount((survarium::inventory_item *)amount, (int)this);
  this->m_unlimited = (const vostok::variant<32> **)((char *)amount + 1) == 0;
  v4 = vostok::configs::binary_config_value::operator[](&config, "cooldown_ms");
  this->m_cooldown_ms = (unsigned int)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                                        v5,
                                        (int)v4);
}
