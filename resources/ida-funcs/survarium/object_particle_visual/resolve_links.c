void __thiscall survarium::object_particle_visual::resolve_links(
        survarium::object_particle_visual *this,
        survarium::base_project *p,
        vostok::configs::binary_config_value config)
{
  const char *pointer; // edx
  survarium::base_game_object *v5; // eax
  survarium::base_game_object *v6; // eax

  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)this,
         (int)&config,
         (unsigned int)"path") )
  {
    pointer = (const char *)vostok::configs::binary_config_value::operator[](&config, "path")->data.pointer;
  }
  else
  {
    pointer = 0;
  }
  if ( pointer && strlen(pointer) )
  {
    v5 = p->get_object_by_name(p, pointer);
    if ( v5 )
      v6 = v5 - 336;
    else
      v6 = 0;
    *((_DWORD *)&this->vostok::resources::resource_flags + 3) = v6;
  }
}
