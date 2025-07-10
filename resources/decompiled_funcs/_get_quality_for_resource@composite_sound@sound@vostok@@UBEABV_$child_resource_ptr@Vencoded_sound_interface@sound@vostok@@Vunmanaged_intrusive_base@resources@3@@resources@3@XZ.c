const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::sound::composite_sound::get_quality_for_resource(
        vostok::sound::composite_sound *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)this->type + 32))(*(_DWORD *)this->type);
  return (const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v1 + 12))(v1, v1);
}
