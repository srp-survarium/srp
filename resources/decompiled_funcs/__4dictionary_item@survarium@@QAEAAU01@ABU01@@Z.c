survarium::dictionary_item *__thiscall survarium::dictionary_item::operator=(
        survarium::dictionary_item *this,
        const survarium::dictionary_item *__that)
{
  this->item_id = __that->item_id;
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>::operator=(
    &this->item_cfg,
    &__that->item_cfg);
  if ( &this->item_cfg_name != &__that->item_cfg_name )
    vostok::buffer_string::operator=(
      (vostok::fixed_string<32> *)&__that->item_cfg_name,
      (vostok::fixed_string<32> *)&this->item_cfg_name);
  this->item_category = __that->item_category;
  this->combat_log_icon = __that->combat_log_icon;
  this->is_premium = __that->is_premium;
  this->is_stack = __that->is_stack;
  this->weight = __that->weight;
  return this;
}
