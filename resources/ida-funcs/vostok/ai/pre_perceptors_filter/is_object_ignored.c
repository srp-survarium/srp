BOOL __thiscall vostok::ai::pre_perceptors_filter::is_object_ignored(
        vostok::ai::pre_perceptors_filter *this,
        const vostok::ai::game_object *const object)
{
  return vostok::ai::pre_perceptors_filter::find_ignored_object(this, object) != 0;
}
