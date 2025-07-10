vostok::render::environment_probe_properties *__thiscall vostok::render::environment_probe_properties::operator=(
        vostok::render::environment_probe_properties *this,
        const vostok::render::environment_probe_properties *__that,
        vostok::render::environment_probe_properties *__thata)
{
  vostok::fixed_string<260>::operator=(&__that->texture_name, &__thata->texture_name);
  qmemcpy((void *)&__that->transform, &__thata->transform, 0x68u);
  return (vostok::render::environment_probe_properties *)__that;
}
