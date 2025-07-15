const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *__thiscall vostok::sound::composite_sound::dbg_get_encoded_sound(
        vostok::sound::composite_sound *this,
        unsigned int quality)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)this->type + 32))(*(_DWORD *)this->type);
  return (const vostok::resources::child_resource_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base> *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 12))(v2, v2);
}
