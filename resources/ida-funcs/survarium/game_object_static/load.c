void __thiscall survarium::game_object_static::load(
        survarium::game_object_static *this,
        const vostok::configs::binary_config_value *t,
        const char *project_resources_path,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  survarium::load_transform(t, &this->m_transform);
}
