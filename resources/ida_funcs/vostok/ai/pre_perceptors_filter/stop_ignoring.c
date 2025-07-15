void __thiscall vostok::ai::pre_perceptors_filter::stop_ignoring(
        vostok::ai::pre_perceptors_filter *this,
        const vostok::ai::game_object *const object)
{
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *end; // [esp+28h] [ebp-8h] BYREF
  stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum> *found_object; // [esp+2Ch] [ebp-4h] BYREF

  found_object = vostok::ai::pre_perceptors_filter::find_ignored_object(this, object);
  if ( found_object )
  {
    if ( found_object->second == ignorance_type_until_hit )
    {
      end = (stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *)&found_object[1];
      vostok::buffer_vector<stlp_std::pair<vostok::ai::game_object const *,enum vostok::ai::ignorance_types_enum>>::erase(
        (vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *)this,
        (stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> **)&found_object,
        &end);
    }
  }
}
