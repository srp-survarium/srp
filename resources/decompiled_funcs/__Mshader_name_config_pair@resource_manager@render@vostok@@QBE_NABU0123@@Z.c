BOOL __usercall vostok::render::resource_manager::shader_name_config_pair::operator<@<eax>(
        vostok::render::resource_manager::shader_name_config_pair *this@<edi>,
        const vostok::render::resource_manager::shader_name_config_pair *other@<esi>)
{
  int v2; // eax

  v2 = strcmp(this->name, other->name);
  return v2 < 0 || !v2 && vostok::render::union_base::operator<(&this->config, &other->config);
}
