void __thiscall vostok::render::custom_config_value::call_data_destructor(vostok::render::custom_config_value *this)
{
  void (__stdcall **destroyer)(void *); // eax
  void (__stdcall *v3)(void *); // eax
  void *p_data; // edx
  unsigned __int16 type; // ax
  vostok::render::custom_config_value *i; // edi

  destroyer = (void (__stdcall **)(void *))this->destroyer;
  if ( destroyer )
  {
    v3 = *destroyer;
    p_data = &this->data;
    if ( this->count > 4u )
      p_data = (void *)this->data;
    v3(p_data);
  }
  type = this->type;
  if ( type == 3 || type == 4 )
  {
    for ( i = (vostok::render::custom_config_value *)this->data;
          i != (vostok::render::custom_config_value *)this->data + this->count;
          ++i )
    {
      vostok::render::custom_config_value::call_data_destructor(i);
    }
  }
}
