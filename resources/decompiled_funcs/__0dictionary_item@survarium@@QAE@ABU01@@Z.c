void __usercall survarium::dictionary_item::dictionary_item(
        survarium::dictionary_item *this@<esi>,
        const survarium::dictionary_item *__that@<edi>)
{
  char *m_begin; // edx
  char *v3; // ecx
  char *v4; // ebx

  this->item_id = __that->item_id;
  this->item_cfg.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
    &this->item_cfg,
    &__that->item_cfg);
  m_begin = __that->item_cfg_name.m_begin;
  v3 = (char *)(__that->item_cfg_name.m_end - m_begin);
  this->item_cfg_name.m_max_end = (char *)&this->item_category;
  v4 = v3;
  this->item_cfg_name.m_begin = this->item_cfg_name.m_buffer;
  this->item_cfg_name.m_end = this->item_cfg_name.m_buffer;
  memcpy((unsigned __int8 *)this->item_cfg_name.m_buffer, (unsigned __int8 *)m_begin, (unsigned int)v3);
  this->item_cfg_name.m_end += (unsigned int)v4;
  *this->item_cfg_name.m_end = 0;
  this->item_category = __that->item_category;
  this->combat_log_icon = __that->combat_log_icon;
  this->is_premium = __that->is_premium;
  this->is_stack = __that->is_stack;
  this->weight = __that->weight;
}
