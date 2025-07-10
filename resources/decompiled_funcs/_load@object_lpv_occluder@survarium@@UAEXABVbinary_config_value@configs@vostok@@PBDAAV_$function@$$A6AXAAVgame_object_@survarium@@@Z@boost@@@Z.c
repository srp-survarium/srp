void __thiscall survarium::object_lpv_occluder::load(
        survarium::object_lpv_occluder *this,
        vostok::configs::binary_config_value *t,
        const char *__formal,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  boost::function1<void,char const *> *v5; // ecx

  survarium::load_transform(t, &this->m_transform);
  boost::function1<void,vostok::render::ambient_volume_properties const &>::operator()(v5, cb, (const char *)this);
}
