vostok::journaling::keyboard *__thiscall vostok::journaling::keyboard::translate_text(
        vostok::journaling::keyboard *this,
        char dik,
        wchar_t *dest_text)
{
  vostok::journaling::keyboard *v4; // [esp-4h] [ebp-4h]

  v4 = (vostok::journaling::keyboard *)*dest_text;
  vostok::memory::process_allocator::finalize_impl((vostok::render::stage_screen_space_reflections *)this);
  return vostok::journaling::keyboard::`vector deleting destructor'(v4, dik);
}
