const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *__thiscall vostok::sound::composite_sound::get_sound_rms(
        vostok::sound::composite_sound *this)
{
  int v1; // eax

  v1 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)this->type + 32))(*(_DWORD *)this->type);
  return (const vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v1 + 24))(v1, v1);
}
