void __thiscall survarium::animation_analysis_result_cook::animation_analysis_result_cook(
        survarium::animation_analysis_result_cook *this)
{
  vostok::enum_flags<enum vostok::resources::cook_base::flags_enum> v1; // [esp-4h] [ebp-Ch] BYREF
  survarium::animation_analysis_result_cook *thisa; // [esp+0h] [ebp-8h]

  thisa = this;
  v1.m_flags = (unsigned int)this;
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    0,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v1);
  vostok::resources::translate_query_cook::translate_query_cook(
    thisa,
    animation_analysis_result_class,
    reuse_false,
    0xFFFFFFFD,
    v1);
  thisa->__vftable = (survarium::animation_analysis_result_cook_vtbl *)&survarium::animation_analysis_result_cook::`vftable';
}
