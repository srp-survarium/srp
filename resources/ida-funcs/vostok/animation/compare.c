const vostok::animation::base_interpolator *__cdecl vostok::animation::compare(
        const vostok::animation::base_interpolator *right)
{
  int v1; // ecx
  int v3; // [esp+0h] [ebp-4h] BYREF

  v3 = v1;
  (*(void (__thiscall **)(int, int *, const vostok::animation::base_interpolator *))(*(_DWORD *)v1 + 20))(
    v1,
    &v3,
    right);
  return (const vostok::animation::base_interpolator *)v3;
}
