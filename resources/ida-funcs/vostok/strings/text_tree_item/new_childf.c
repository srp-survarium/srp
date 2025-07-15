vostok::strings::text_tree_item *vostok::strings::text_tree_item::new_childf(
        vostok::strings::text_tree_item *this,
        char *name,
        char *format,
        ...)
{
  vostok::strings::text_tree_item *v3; // ecx
  vostok::strings::text_tree_item *v4; // esi
  vostok::buffer_string *v5; // ecx
  vostok::strings::text_tree_item *v6; // ecx
  char *v8[3]; // [esp+Ch] [ebp-210h] BYREF
  _BYTE v9[512]; // [esp+18h] [ebp-204h] BYREF
  char v10; // [esp+218h] [ebp-4h] BYREF
  va_list va; // [esp+230h] [ebp+14h] BYREF

  va_start(va, format);
  v4 = vostok::strings::text_tree_item::new_child(v3, (const char *)this, name);
  v8[0] = v9;
  v8[1] = v9;
  v8[2] = &v10;
  v9[0] = 0;
  vostok::buffer_string::appendf_va_list(v5, v8, format, va);
  vostok::strings::text_tree_item::add_column_impl(v6, (const char *)v4, v8[0]);
  return v4;
}
