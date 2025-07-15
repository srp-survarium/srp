int __thiscall vostok::render::_dynamic_initializer_for__request_helper__(vostok::variant<32> *this)
{
  _DWORD v2[2]; // [esp+0h] [ebp-10h] BYREF
  char v3; // [esp+8h] [ebp-8h]
  char v4; // [esp+9h] [ebp-7h]
  char v5; // [esp+Ah] [ebp-6h]
  char v6; // [esp+Bh] [ebp-5h]
  char v7; // [esp+Ch] [ebp-4h]

  v2[1] = -1;
  v2[0] = 0;
  v3 = 0;
  v4 = 0;
  v6 = 0;
  v7 = 0;
  v5 = 1;
  vostok::variant<32>::set<vostok::render::render_texture_cook_parameters>(
    this,
    (const vostok::render::render_texture_cook_parameters *)&vostok::render::request_helper,
    v2);
  return atexit(vostok::render::_dynamic_atexit_destructor_for__request_helper__);
}
