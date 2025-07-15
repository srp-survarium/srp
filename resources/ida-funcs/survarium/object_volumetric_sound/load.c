void __thiscall survarium::object_volumetric_sound::load(
        survarium::object_volumetric_sound *this,
        const vostok::configs::binary_config_value *t,
        char *project_resources_path,
        boost::function<void __cdecl(survarium::game_object_ &)> *cb)
{
  const vostok::configs::binary_config_value *v5; // eax
  float pointer; // xmm0_4

  survarium::object_sound::load(
    this,
    t,
    project_resources_path,
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)cb);
  v5 = vostok::configs::binary_config_value::operator[](t, "radius");
  if ( v5->type == 2 )
    pointer = *(float *)&v5->data.pointer;
  else
    pointer = (float)(int)v5->data.pointer;
  this->m_radius = pointer;
}
