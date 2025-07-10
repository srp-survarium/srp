void __thiscall vostok::ai::planning::predicate::predicate(
        vostok::ai::planning::predicate *this,
        unsigned int predicate_id,
        vostok::ai::planning::parameters_order_enum index1,
        vostok::ai::planning::parameters_order_enum index2,
        vostok::ai::planning::parameters_order_enum index3)
{
  vostok::ai::planning::expression_parameter v6; // [esp+10h] [ebp-2Ch] BYREF
  vostok::ai::planning::expression_parameter v7; // [esp+20h] [ebp-1Ch] BYREF
  vostok::ai::planning::expression_parameter value; // [esp+30h] [ebp-Ch] BYREF

  vostok::ai::planning::base_lexeme::base_lexeme(this, 0);
  this->__vftable = (vostok::ai::planning::predicate_vtbl *)&vostok::ai::planning::predicate::`vftable';
  vostok::fixed_vector<char const *,4>::fixed_vector<char const *,4>((vostok::fixed_vector<void const *,4> *)&this->m_parameters);
  this->m_predicate_id = predicate_id;
  value.instance = (const void *)index1;
  vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(&this->m_parameters, &value);
  v7.instance = (const void *)index2;
  vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(&this->m_parameters, &v7);
  v6.instance = (const void *)index3;
  vostok::buffer_vector<vostok::ai::planning::expression_parameter>::push_back(&this->m_parameters, &v6);
}
