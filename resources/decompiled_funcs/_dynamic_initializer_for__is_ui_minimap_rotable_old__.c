bool dynamic_initializer_for__is_ui_minimap_rotable_old__()
{
  bool result; // al

  result = is_ui_minimap_rotable;
  LOBYTE(is_ui_minimap_rotable_old) = is_ui_minimap_rotable;
  return result;
}
