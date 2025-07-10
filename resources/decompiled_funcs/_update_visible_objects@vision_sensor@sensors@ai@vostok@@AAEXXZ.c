void __thiscall vostok::ai::sensors::vision_sensor::update_visible_objects(vostok::ai::sensors::vision_sensor *this)
{
  vostok::ai::sensors::vision_sensor::reset_frustum_status(this);
  vostok::ai::sensors::vision_sensor::check_frustum(this);
  vostok::ai::sensors::vision_sensor::delete_not_in_frustum(this);
  vostok::ai::sensors::vision_sensor::trace_objects_in_frustum(this);
  vostok::ai::sensors::vision_sensor::update_visibility_value(this);
  vostok::ai::sensors::vision_sensor::remove_invisible_objects(this);
}
