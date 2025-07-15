void __thiscall stlp_std::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>::pair<unsigned int const,vostok::fixed_vector<vostok::ai::planning::object_instance,16>>(
        stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > *this,
        const stlp_std::pair<unsigned int const ,vostok::fixed_vector<vostok::ai::planning::object_instance,16> > *__o)
{
  vostok::ai::planning::object_instance *end; // [esp+3Ch] [ebp-8h] BYREF
  vostok::ai::planning::object_instance *m_buffer; // [esp+40h] [ebp-4h]

  this->first = __o->first;
  m_buffer = (vostok::ai::planning::object_instance *)this->second.m_buffer;
  this->second.m_begin = (vostok::ai::planning::object_instance *)this->second.m_buffer;
  this->second.m_end = m_buffer;
  end = __o->second.m_end;
  vostok::buffer_vector<vostok::ai::planning::object_instance>::assign<vostok::ai::planning::object_instance const *>(
    &this->second,
    __o->second.m_begin,
    (const vostok::ai::planning::object_instance *const *)&end);
}


void __thiscall stlp_std::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>::pair<vostok::fixed_string<16> const,survarium::body_part_parameters_modifyer>(
        stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer> *this,
        const stlp_std::pair<vostok::fixed_string<16> const ,survarium::body_part_parameters_modifyer> *__o)
{
  vostok::fixed_string<16>::fixed_string<16>(&this->first, &__o->first);
  this->second.health = __o->second.health;
  this->second.health_regeneration = __o->second.health_regeneration;
  stlp_std::priv::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>::_Rb_tree<vostok::fixed_string<16>,stlp_std::less<vostok::fixed_string<16>>,stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<16> const,survarium::hit_type_parameters_modifyer>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<16>,survarium::hit_type_parameters_modifyer>>>(
    &this->second.hit_type_modifyers._M_t,
    &__o->second.hit_type_modifyers._M_t);
}


void __userpurge stlp_std::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *>::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *>(
        stlp_std::pair<boost::intrusive::rbtree_node<void *> *,boost::intrusive::rbtree_node<void *> *> *this@<ecx>,
        int a2@<eax>,
        boost::intrusive::rbtree_node<void *> *const *__a,
        boost::intrusive::rbtree_node<void *> *const *__b)
{
  *(_DWORD *)a2 = this->first;
  *(boost::intrusive::rbtree_node<void *> **)(a2 + 4) = *__a;
}


void __userpurge stlp_std::pair<boost::intrusive::rbtree_node<void *> *,bool>::pair<boost::intrusive::rbtree_node<void *> *,bool>(
        stlp_std::pair<boost::intrusive::rbtree_node<void *> *,bool> *this@<ecx>,
        int a2@<eax>,
        boost::intrusive::rbtree_node<void *> *const *__a,
        const bool *__b)
{
  *(_DWORD *)a2 = this->first;
  *(_BYTE *)(a2 + 4) = *(_BYTE *)__a;
}
