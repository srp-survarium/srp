void __thiscall survarium::object_ambient_volume::load(
        survarium::object_ambient_volume *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const vostok::configs::binary_config_value *v5; // eax
  boost::function1<void,char const *> *v6; // ecx
  float pointer; // xmm0_4
  bool v8; // zf

  survarium::load_transform(t, &this->m_transform);
  this->m_enabled = vostok::configs::binary_config_value::operator[](t, "enabled")->data.pointer != 0;
  v5 = vostok::configs::binary_config_value::operator[](t, "ambient_multiplier");
  if ( v5->type == 2 )
    pointer = *(float *)&v5->data.pointer;
  else
    pointer = (float)(int)v5->data.pointer;
  v8 = !this->m_enabled;
  this->m_ambient_multiplier = pointer;
  if ( v8 || pointer == *(float *)&clear_value )
    this->m_valid = 0;
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(v6, cb, (const char *)this);
}
