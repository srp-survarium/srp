void __thiscall survarium::medkit::remove_affects(survarium::medkit *this)
{
  int v1; // eax
  stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *v2; // ecx
  const vostok::variant<32> **v3; // eax
  survarium::hit_affects_type_enum type; // [esp-4h] [ebp-18h]
  survarium::inventory_holder *v5; // [esp+0h] [ebp-14h]
  const survarium::medkit::affect *affct; // [esp+Ch] [ebp-8h]
  unsigned int i; // [esp+10h] [ebp-4h]

  for ( i = 0; i < this->m_affects_count; ++i )
  {
    affct = &this->m_affects[i];
    v5 = survarium::inventory::holder((survarium::inventory *)this, (int)this->m_inventory);
    type = affct->type;
    v1 = (int)v5->damage_model(v5);
    v3 = stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(v2, v1);
    survarium::damage_model::cancel_affect((survarium::damage_model *)v3, affct->body_part_name, type);
  }
}
