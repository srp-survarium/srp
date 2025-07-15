void __thiscall vostok::render::unregister_cooks(vostok::render *this)
{
  vostok::render *v1; // [esp-4h] [ebp-4h]

  vostok::particle::finalize(this);
  vostok::render::unregister_texture_cook(v1);
}
