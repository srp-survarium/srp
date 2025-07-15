BOOL __usercall vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::ambient_light>::operator()@<eax>(
        const vostok::render::ambient_light *const obj@<eax>,
        vostok::render::ambient_light *a2@<ecx>)
{
  return !obj->m_properties.enabled || vostok::render::ambient_light::is_occluded(a2, (int)obj);
}


BOOL __thiscall vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe>::operator()(
        vostok::render::remove_if_disabled_or_occluded_predicate<vostok::render::environment_probe> *this)
{
  vostok::render::environment_probe *v1; // ecx

  return !*(_BYTE *)&this[545]
      || !vostok::render::environment_probe::is_valid_textures((vostok::render::environment_probe *)this)
      || vostok::render::environment_probe::is_occluded(v1, (int)v1);
}
